/*
 * WifiProcess.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


#include "WifiProcess.h"

#include "Instance.h"
#include "main.h"

#include <cstring>
#include <cstdio>

WifiProcess& WifiProcess::getInstance() {
    static WifiProcess instance;
    return instance;
}

WifiProcess::WifiProcess() {}

void WifiProcess::takeMachineIDWithConfirmation() {
    HAL_Delay(500);
    int confirmationVal = 0;
    while (confirmationVal == 0) {
        lcd.print(1, 1, textVars.idConfirmationText.c_str());
        lcd.print(2, 1, textVars.idConfirmationSubText.c_str());

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
            confirmationVal = 1;
        }
    }

    takeMachineID();

    EEPROMProcess::getInstance().convertArrays(1);
    HAL_Delay(50);

    iotMenu.printCredentials(1); // Ekrana makine id'si yazdır.
}

void WifiProcess::takeMachineID() {
    mainSection:

    lcd.setCursor(1);
    memset(globalVariables.machineID.data(), 0, systemDefaults.machineIDCharacterLimit);

    int writeLoc = 5; // kullanıcının seçtiği karkaterin yazılırken başlayacağı karakter değişkeni
    int cursorPosition = 3; // kullanıcının seçim yaptığı işaretçinin konumu
    int arrayPos = 0; // kullanıcının seçtiği karakteri diziye aktarırken kullanılacak olan değişken
    int eepromVal = systemDefaults.idStartPos; // kullanıcının seçtiği karakteri eeproma aktarmak için kullanılacak olan değişken

    iotMenu.printTemplate(1, 0);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
            lcd.setCursor(0);

            if (checkEEPROM4ID() != 1) {
                lcd.print(1, 1, textVars.mustBe12Text.c_str());
                lcd.print(2, 1, textVars.mustBe122Text.c_str());
                HAL_Delay(1250);

                goto mainSection;
            } else {
                HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, globalVariables.eepromData.data(), 110, 3000);
                HAL_Delay(1000);

                break;
            }
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
            if (cursorPosition == 7) {
                cursorPosition = 10;
            } else if (cursorPosition == 14) {
                cursorPosition = 3;
            } else {
                cursorPosition++;
            }

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
            if (cursorPosition == 3) {
                cursorPosition = 14;
            } else if (cursorPosition == 10) {
                cursorPosition = 7;
            } else {
                cursorPosition--;
            }

            HAL_Delay(250);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
            switch (cursorPosition) {
                case 3: globalVariables.machineID[arrayPos] = '0'; globalVariables.eepromData[eepromVal] = 0; break;
                case 4: globalVariables.machineID[arrayPos] = '1'; globalVariables.eepromData[eepromVal] = 1; break;
                case 5: globalVariables.machineID[arrayPos] = '2'; globalVariables.eepromData[eepromVal] = 2; break;
                case 6: globalVariables.machineID[arrayPos] = '3'; globalVariables.eepromData[eepromVal] = 3; break;
                case 7: globalVariables.machineID[arrayPos] = '4'; globalVariables.eepromData[eepromVal] = 4; break;
                case 10: globalVariables.machineID[arrayPos] = '5'; globalVariables.eepromData[eepromVal] = 5; break;
                case 11: globalVariables.machineID[arrayPos] = '6'; globalVariables.eepromData[eepromVal] = 6; break;
                case 12: globalVariables.machineID[arrayPos] = '7'; globalVariables.eepromData[eepromVal] = 7; break;
                case 13: globalVariables.machineID[arrayPos] = '8'; globalVariables.eepromData[eepromVal] = 8; break;
                case 14: globalVariables.machineID[arrayPos] = '9'; globalVariables.eepromData[eepromVal] = 9; break;
            }

            lcd.printChar(1, writeLoc, globalVariables.machineID[arrayPos]);

            writeLoc++;
            arrayPos++;
            eepromVal++;

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
            if (strlen(globalVariables.machineID) >= 1) {
                globalVariables.machineID[arrayPos] = '\0';
                globalVariables.eepromData[eepromVal] = '\0';

                if (writeLoc > 5) {
                    writeLoc--;
                } else if (writeLoc < 5) {
                    writeLoc = 5;
                }

                if (arrayPos > 0) {
                    arrayPos--;
                    eepromVal--;
                } else if (arrayPos < 0) {
                    arrayPos = 0;
                    eepromVal = systemDefaults.idStartPos;
                }

                lcd.deleteChar(1, 4 + arrayPos + 1);
                HAL_Delay(50);
            }

            HAL_Delay(150);
        }

        lcd.setCursorPosition(2, cursorPosition);
    }
}

uint8_t WifiProcess::ssidConfirmation() {
    int loopVal = 1;
    lcd.print(1, 1, "                ");

    while (loopVal == 1) {
        lcd.print(2, 1, textVars.wifiConfirmationText.c_str());
        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
            loopVal = 0;
        }

        if (strlen(globalVariables.wifiSSID.data()) > 16) {
            slideText(globalVariables.wifiSSID.c_str(), 1, 1, 1);
        } else {
            lcd.print(1, 1, globalVariables.wifiSSID);
        }
    }

    lcd.setCursor(0);

    if (strlen(globalVariables.wifiSSID) > 20) {
        lcd.print(1, 1, textVars.ssidExceedErrorText.c_str());
        lcd.print(2, 1, textVars.ssidExceedError2Text.c_str());
        HAL_Delay(1250);

        return 0;
    } else {
        HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, globalVariables.eepromData, 110, 3000);
        HAL_Delay(1000);

        return 1;
    }
}

void WifiProcess::takeWifiSSID() {
    mainSSIDSection:

    lcd.setCursor(1);
    memset(globalVariables.wifiSSID.data(), 0, wifiCharacterLimit * sizeof(char));

    int page = 1; // wifi karakterleri için sayfa değişkeni
    int writeLoc = 7; // seçilen karakterleri yazdırmaya başlanılacak karakter

    int cursorPosition = 1; // kullanıcının gezindiği işaretçinin değişkeni
    int arrayPosition = 0; // kullanıcının seçtiği karakteri diziye aktarırken kullanılacak değişken
    int eepromVal = systemDefaults.ssidStartPos; // kullanıcının seçtiği karakteri eeproma yazarken kullanılacak değişken

    iotMenu.printTemplate(2, 1);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
            if (ssidConfirmation() == 0) {
                goto mainSSIDSection;
            } else {
                break;
            }
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
            if (cursorPosition > 80) {
                cursorPosition = 1;
            }

            if (cursorPosition == 16) {
                if (page == 1) {
                    cursorPosition = 1;
                    page++;
                    iotMenu.printTemplate(2, 2);
                } else if (page == 2) {
                    cursorPosition = 1;
                    page++;
                    iotMenu.printTemplate(2, 3);
                } else if (page == 3) {
                    cursorPosition = 1;
                    page++;
                    iotMenu.printTemplate(2, 4);
                } else if (page == 4) {
                    cursorPosition = 1;
                    page++;
                    iotMenu.printTemplate(2, 5);
                } else if (page == 5) {
                    cursorPosition = 1;
                    page = 1;
                    iotMenu.printTemplate(2, 1);
                }
            } else {
                cursorPosition++;
            }

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
            if (cursorPosition < 1) {
                cursorPosition = 80;
            }

            if (cursorPosition == 1) {
                if (page == 1) {
                    cursorPosition = 16;
                    page = 5;
                    iotMenu.printTemplate(2, 5);
                } else if (page == 2) {
                    cursorPosition = 16;
                    page = 1;
                    iotMenu.printTemplate(2, 1);
                } else if (page == 3) {
                    cursorPosition = 16;
                    page = 2;
                    iotMenu.printTemplate(2, 2);
                } else if (page == 4) {
                    cursorPosition = 16;
                    page = 3;
                    iotMenu.printTemplate(2, 3);
                } else if (page == 5) {
                    cursorPosition = 16;
                    page = 4;
                    iotMenu.printTemplate(2, 4);
                }
            } else {
                cursorPosition--;
            }

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
            globalVariables.eepromData[eepromVal] = cursorPosition;
            globalVariables.wifiSSID[arrayPosition] = systemDefaults.charactersArray[cursorPosition];

            lcd.printChar(1, writeLoc, systemDefaults.charactersArray[cursorPosition]);

            writeLoc++;
            arrayPosition++;
            eepromVal++;

            globalVariables.eepromData[eepromVal] = '\0';
            globalVariables.wifiSSID[arrayPosition] = '\0';

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
            if (strlen(globalVariables.wifiSSID) >= 1) {
                globalVariables.eepromData[eepromVal] = '\0';
                globalVariables.wifiSSID[arrayPosition] = '\0';

                if (writeLoc > 7) {
                    writeLoc--;
                } else if (writeLoc < 7) {
                    writeLoc = 7;
                }

                if (arrayPosition > 0) {
                    arrayPosition--;
                    eepromVal--;
                } else if (arrayPosition < 0) {
                    arrayPosition = 0;
                    eepromVal = systemDefaults.ssidStartPos;
                }

                lcd.deleteChar(1, 6 + arrayPosition + 1);
                HAL_Delay(50);
            }

            HAL_Delay(150);
        }

        lcd.setCursorPosition(2, cursorPosition);
    }
}

uint8_t WifiProcess::passConfirmation() {
    int loopVal = 1;
    lcd.print(1, 1, "                ");

    while (loopVal == 1) {
        lcd.print(2, 1, textVars.wifiConfirmationText.c_str());
        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
            loopVal = 0;
        }

        if (strlen(globalVariables.wifiPass) > 16) {
            slideText(globalVariables.wifiPass, 1, 1, 1);
        } else {
            lcd.print(1, 1, globalVariables.wifiPass);
        }
    }

    lcd.setCursor(0);

    if (strlen(globalVariables.wifiPass) > 20) {
        lcd.print(1, 1, textVars.passExceedErrorText.c_str());
        lcd.print(2, 1, textVars.passExceedError2Text.c_str());
        HAL_Delay(1250);

        return 0;
    } else {
        HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, globalVariables.eepromData, 110, 3000);
        HAL_Delay(1000);

        return 1;
    }
}

void WifiProcess::takeWifiPass() {
    mainPassSection:

    lcd.setCursor(1);
    memset(globalVariables.wifiPass.data(), 0, wifiCharacterLimit * sizeof(char));

    int page = 1; // wifi karakterleri için sayfa değişkeni
    int writeLoc = 7; // seçilen karakterleri yazdırmaya başlanılacak karakter

    int cursorPosition = 1; // kullanıcının gezindiği işaretçinin değişkeni
    int arrayPosition = 0; // kullanıcının seçtiği karakteri diziye aktarırken kullanılacak değişken
    int eepromVal = systemDefaults.passStartPos; // kullanıcının seçtiği karakteri eeproma yazarken kullanılacak değişken

    iotMenu.printTemplate(3, 1);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
            if (passConfirmation() == 0) {
                goto mainPassSection;
            } else {
                break;
            }
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
            if (cursorPosition > 80) {
                cursorPosition = 1;
            }

            if (cursorPosition == 16) {
                if (page == 1) {
                    cursorPosition = 1;
                    page++;
                    iotMenu.printTemplate(3, 2);
                } else if (page == 2) {
                    cursorPosition = 1;
                    page++;
                    iotMenu.printTemplate(3, 3);
                } else if (page == 3) {
                    cursorPosition = 1;
                    page++;
                    iotMenu.printTemplate(3, 4);
                } else if (page == 4) {
                    cursorPosition = 1;
                    page++;
                    iotMenu.printTemplate(3, 5);
                } else if (page == 5) {
                    cursorPosition = 1;
                    page = 1;
                    iotMenu.printTemplate(3, 1);
                }
            } else {
                cursorPosition++;
            }

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
            if (cursorPosition < 1) {
                cursorPosition = 80;
            }

            if (cursorPosition == 1) {
                if (page == 1) {
                    cursorPosition = 16;
                    page = 5;
                    iotMenu.printTemplate(3, 5);
                } else if (page == 2) {
                    cursorPosition = 16;
                    page = 1;
                    iotMenu.printTemplate(3, 1);
                } else if (page == 3) {
                    cursorPosition = 16;
                    page = 2;
                    iotMenu.printTemplate(3, 2);
                } else if (page == 4) {
                    cursorPosition = 16;
                    page = 3;
                    iotMenu.printTemplate(3, 3);
                } else if (page == 5) {
                    cursorPosition = 16;
                    page = 4;
                    iotMenu.printTemplate(3, 4);
                }
            } else {
                cursorPosition--;
            }

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
            globalVariables.eepromData[eepromVal] = cursorPosition;
            globalVariables.wifiPass[arrayPosition] = systemDefaults.charactersArray[cursorPosition];

            lcd.printChar(1, writeLoc, systemDefaults.charactersArray[cursorPosition]);

            writeLoc++;
            arrayPosition++;
            eepromVal++;

            globalVariables.eepromData[eepromVal] = '\0';
            globalVariables.wifiPass[arrayPosition] = '\0';

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
            if (strlen(globalVariables.wifiPass) >= 1) {
                globalVariables.eepromData[eepromVal] = '\0';
                globalVariables.wifiPass[arrayPosition] = '\0';

                if (writeLoc > 7) {
                    writeLoc--;
                } else if (writeLoc < 7) {
                    writeLoc = 7;
                }

                if (arrayPosition > 0) {
                    arrayPosition--;
                    eepromVal--;
                } else if (arrayPosition < 0) {
                    arrayPosition = 0;
                    eepromVal = systemDefaults.passStartPos;
                }

                lcd.deleteChar(1, 6 + arrayPosition + 1);
                HAL_Delay(50);
            }

            HAL_Delay(150);
        }

        lcd.setCursorPosition(2, cursorPosition);
    }
}

std::string WifiProcess::mergeData() {
    std::string combinedString;
    char temp[10];

    uint8_t uintVariables[] = {
    	globalVariables.devirmeYuruyusSecim,
		globalVariables.calismaSekli,
		globalVariables.emniyetCercevesi,
		globalVariables.yavaslamaLimit,
		globalVariables.altLimit,
		globalVariables.kapiTablaAcKonum,
		globalVariables.basincSalteri,
		globalVariables.kapiSecimleri,
		globalVariables.kapiAcTipi,
		globalVariables.kapi1Tip,
		globalVariables.kapi1AcSure,
		globalVariables.kapi2Tip,
		globalVariables.kapi2AcSure,
		globalVariables.kapitablaTip,
		globalVariables.kapiTablaAcSure,
		globalVariables.yukariYavasLimit,
		globalVariables.devirmeYukariIleriLimit,
		globalVariables.devirmeAsagiGeriLimit,
		globalVariables.devirmeSilindirTipi,
		globalVariables.platformSilindirTipi,
		globalVariables.yukariValfTmr,
		globalVariables.asagiValfTmr,
		globalVariables.devirmeYukariIleriTmr,
		globalVariables.devirmeAsagiGeriTmr,
		globalVariables.makineCalismaTmr,
		globalVariables.buzzer,
		globalVariables.demoMode,
		globalVariables.calismaSayisi1,
		globalVariables.calismaSayisi10,
		globalVariables.calismaSayisi100,
		globalVariables.calismaSayisi1000,
		globalVariables.calismaSayisi10000,
		globalVariables.dilSecim,
        globalVariables.eepromData[38],
        globalVariables.eepromData[39],
        globalVariables.eepromData[40],
        globalVariables.eepromData[41],
        globalVariables.eepromData[42],
        globalVariables.eepromData[43],
        globalVariables.eepromData[44],
        globalVariables.eepromData[45],
        globalVariables.eepromData[46],
        globalVariables.eepromData[47],
		globalVariables.lcdBacklightSure
    };

    for (int i = 0; i < sizeof(uintVariables) / sizeof(uintVariables[0]); ++i) {
        sprintf(temp, "%u", uintVariables[i]);
        combinedString += temp;
    }

    return combinedString;
}

std::string WifiProcess::getCredentials(int type) {
    std::string combinedString;
    char temp[10];

    int startPos = (type == 1) ? systemDefaults.idStartPos : (type == 2) ? systemDefaults.ssidStartPos : systemDefaults.passStartPos;

    int length = (type == 1) ? 12 : 20;
    uint8_t* data = globalVariables.eepromData + startPos;

    for (int i = 0; i < length; ++i) {
        sprintf(temp, "%u", data[i]);
        combinedString += temp;
    }

    return combinedString;
}

void WifiProcess::convertAndSendData() {
    lcd.print(1, 1, textVars.dataSynchText.c_str());
    lcd.print(2, 1, textVars.dataSynch2Text.c_str());

    for (int i = 0; i < 2; i++) {
        wifiProcess.sendMachineData(&huart1, globalVariables.machineID, globalVariables.wifiSSID, globalVariables.wifiPass, mergeData().c_str());
    }

    HAL_Delay(500);
    lcd.clear();
}

void WifiProcess::iotSetup() {
    if (globalVariables.iotMode != 0) {
        if (checkEEPROM4ID() != 1) {
            takeMachineID();
        }

        if (!(strlen(globalVariables.wifiSSID) >= 2)) {
            takeWifiSSID();
        }

        if (!(strlen(globalVariables.wifiPass) >= 2)) {
            takeWifiPass();
        }
    }

    esp.init(&huart1, systemDefaults.demoWifiSSIDEv, systemDefaults.demoWifiPassEv);
    HAL_Delay(500);
    convertAndSendData();
}

int WifiProcess::checkEEPROM4ID() {
    int eepromVal = systemDefaults.idStartPos;
    int returnVal = 1;

    for (int i = 0; i < systemDefaults.machineIDCharacterLimit; i++) {
        if (globalVariables.eepromData[eepromVal] == '\0') {
            returnVal = 0;
        }
        eepromVal++;
    }

    return returnVal;
}
