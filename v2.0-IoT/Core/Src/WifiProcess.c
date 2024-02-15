/*
 * WifiProcess.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "WifiProcess.h"
#include "main.h"
#include "GlobalVariables.h"
#include "ESP8266.h"
#include "i2c-lcd.h"
#include "EEPROMProcess.h"
#include "IoTMenu.h"

void takeMachineID() {
	mainSection:
	lcd_cursor(1);

	int writeLoc = 5; //lcdnin ilk satırındaki başlangıç karakteri

    int cursorPos = 3; //işaretçi konumu

    int idStart = idStartPos; //eepromKonumu

    memset(machineID, 0, sizeof(machineID));
    HAL_Delay(100);

    printTemplate(1, 0);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
        	lcd_cursor(0);

        	if(machineID[11] == '\0' || machineID[12] != '\0') {
        		lcd_clear();
        		lcd_print(1, 1, " ID 12 KARAKTER ");
        		lcd_print(2, 1, " OLMAK ZORUNDA! ");
        		HAL_Delay(1200);
        		goto mainSection;
        	}

        	HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
        	HAL_Delay(1000);

        	readFromEEPROM(3);

            break;
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
        	HAL_Delay(50);
        	if(cursorPos == 7) {
        		cursorPos = 10;
        	} else if (cursorPos == 14) {
                cursorPos = 3;
            } else {
            	cursorPos++;
            }

        	HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
        	HAL_Delay(50);
            if (cursorPos == 3) {
                cursorPos = 14;
            } else if(cursorPos == 10) {
            	cursorPos = 7;
            } else {
            	cursorPos--;
            }

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
        	HAL_Delay(50);
        	if(cursorPos == 3) {
        		eepromData[idStart] = 0;
        	} else if(cursorPos == 4) {
        		eepromData[idStart] = 1;
        	} else if(cursorPos == 5) {
        		eepromData[idStart] = 2;
        	} else if(cursorPos == 6) {
        		eepromData[idStart] = 3;
        	} else if(cursorPos == 7) {
        		eepromData[idStart] = 4;
        	} else if(cursorPos == 10) {
        		eepromData[idStart] = 5;
        	} else if(cursorPos == 11) {
        		eepromData[idStart] = 6;
        	} else if(cursorPos == 12) {
        		eepromData[idStart] = 7;
        	} else if(cursorPos == 13) {
        		eepromData[idStart] = 8;
        	} else if(cursorPos == 14) {
        		eepromData[idStart] = 9;
        	}

        	lcd_print_char(1, writeLoc, getIDCharFromCursorPosition(eepromData[idStart]));

        	writeLoc++;
        	idStart++;

        	HAL_Delay(150);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
        	HAL_Delay(50);
            if(strlen(machineID) >= 1) {

            	if(writeLoc > 5) {
            	    writeLoc--;
            	} else if(writeLoc < 5) {
            	    writeLoc = 5;
            	}

            	idStart--;

            	eepromData[idStart] = '\0';

                lcd_delete_char(1, 4+writeLoc);
                HAL_Delay(50);
            }

            HAL_Delay(150);
        }

        lcd_gotoxy(2, cursorPos);
    }
}

void takeWifiSSID() {
	mainSSIDSection:
    lcd_cursor(1);

    memset(wifiSSID, 0, sizeof(wifiSSID));
    HAL_Delay(100);

    int realCharPos = 1;
    int cursorPosition = 1;
    int page = 1;
    int wifiNameLoc = 0;
    int writeLoc = 7;

    int idStart = ssidStartPos;

    printTemplate(2, 1);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
        	HAL_Delay(50);
            lcd_cursor(0);

            if(strlen(wifiSSID) > 20) {
                lcd_clear();
                lcd_print(1, 1, " 20 KARAKTERDEN ");
                lcd_print(2, 1, "FAZLA SSID OLMAZ");
                HAL_Delay(1200);
                goto mainSSIDSection;
            }

            HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
            HAL_Delay(1000);

            break;
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
        	HAL_Delay(50);

        	realCharPos++;
        	if(realCharPos > 80) {
        		realCharPos = 1;
        	}
            if (cursorPosition == 16) {
            	if(page == 1) {
            		cursorPosition = 1;
            		page++;
            		printTemplate(2, 2);
            	} else if(page == 2) {
            		cursorPosition = 1;
            		page++;
            		printTemplate(2, 3);
            	} else if(page == 3) {
            		cursorPosition = 1;
            		page++;
            		printTemplate(2, 4);
            	} else if(page == 4) {
            		cursorPosition = 1;
            		page++;
            		printTemplate(2, 5);
            	} else if(page == 5) {
            		cursorPosition = 1;
            		page = 1;
            		printTemplate(2, 1);
            	}
            } else {
            	cursorPosition++;
            }

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
        	HAL_Delay(50);

        	realCharPos--;
        	if(realCharPos < 1) {
        		realCharPos = 80;
        	}
            if(cursorPosition == 1) {
            	if(page == 1) {
            		cursorPosition = 16;
            		page = 5;
            		printTemplate(2, 5);
            	} else if(page == 2) {
            		cursorPosition = 16;
            		page = 1;
            		printTemplate(2, 1);
            	} else if(page == 3) {
            		cursorPosition = 16;
            		page = 2;
            		printTemplate(2, 2);
            	} else if(page == 4) {
            		cursorPosition = 16;
            		page = 3;
            		printTemplate(2, 3);
            	} else if(page == 5) {
            		cursorPosition = 16;
            		page = 4;
            		printTemplate(2, 4);
            	}
            } else {
            	cursorPosition--;
            }

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
        	HAL_Delay(50);
            wifiSSID[wifiNameLoc] = getCharFromCursorPosition(realCharPos - 1);
            eepromData[idStart] = realCharPos - 1;
            wifiSSIDInt[wifiNameLoc] = realCharPos - 1;

            lcd_print_char(1, writeLoc, wifiSSID[wifiNameLoc]);

            writeLoc++;
            wifiNameLoc++;
            idStart++;

            HAL_Delay(150);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
        	HAL_Delay(50);

        	if(strlen(wifiSSID) >= 1) {
        		if(writeLoc > 7) {
        			writeLoc--;
        		} else if(writeLoc < 7) {
        			writeLoc = 7;
        		}

        		if(wifiNameLoc > 0) {
        			wifiNameLoc--;
        			idStart--;
        		} else if(wifiNameLoc < 0) {
        			wifiNameLoc = 0;
        		}

        		wifiSSID[wifiNameLoc] = '\0';
        		eepromData[idStart] = '\0';
        		wifiSSIDInt[wifiNameLoc] = '\0';

        		lcd_delete_char(1, 6+wifiNameLoc);
        		HAL_Delay(50);
        	}

        	HAL_Delay(150);
        }

        lcd_gotoxy(2, cursorPosition);
    }
}

void takeWifiPass() {
	mainPASSSection:
    lcd_cursor(1);

    memset(wifiPass, 0, sizeof(wifiPass));
    HAL_Delay(100);

    int realCharPos = 1;
    int cursorPosition = 1;
    int page = 1;
    int wifiPassLoc = 0;
    int writeLoc = 7;

    int passStart = passStartPos;

    printTemplate(3, 1);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
        	HAL_Delay(50);
            lcd_cursor(0);

            if(strlen(wifiPass) > 20) {
                lcd_clear();
                lcd_print(1, 1, " 20 KARAKTERDEN ");
                lcd_print(2, 1, "FAZLA PASS OLMAZ");
                HAL_Delay(1200);
                goto mainPASSSection;
            }

            HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
            HAL_Delay(1000);

            break;
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
        	HAL_Delay(50);

        	realCharPos++;
        	if(realCharPos > 80) {
        	    realCharPos = 1;
        	}
            if (cursorPosition == 16) {
            	if(page == 1) {
            		cursorPosition = 1;
            		page++;
            		printTemplate(3, 2);
            	} else if(page == 2) {
            		cursorPosition = 1;
            		page++;
            		printTemplate(3, 3);
            	} else if(page == 3) {
            		cursorPosition = 1;
            		page++;
            		printTemplate(3, 4);
            	} else if(page == 4) {
            		cursorPosition = 1;
            		page++;
            		printTemplate(3, 5);
            	} else if(page == 5) {
            		cursorPosition = 1;
            		page = 1;
            		printTemplate(3, 1);
            	}
            } else {
            	cursorPosition++;
            }

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
        	HAL_Delay(50);

        	realCharPos--;
        	if(realCharPos < 1) {
        	    realCharPos = 80;
        	}
            if(cursorPosition == 1) {
            	if(page == 1) {
            		cursorPosition = 16;
            		page = 5;
            		printTemplate(3, 5);
            	} else if(page == 2) {
            		cursorPosition = 16;
            		page = 1;
            		printTemplate(3, 1);
            	} else if(page == 3) {
            		cursorPosition = 16;
            		page = 2;
            		printTemplate(3, 2);
            	} else if(page == 4) {
            		cursorPosition = 16;
            		page = 3;
            		printTemplate(3, 3);
            	} else if(page == 5) {
            		cursorPosition = 16;
            		page = 4;
            		printTemplate(3, 4);
            	}
            } else {
            	cursorPosition--;
            }

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
        	wifiPass[wifiPassLoc] = getCharFromCursorPosition(realCharPos - 1);
        	eepromData[passStart] = realCharPos - 1;
        	wifiPassInt[wifiPassLoc] = realCharPos - 1;

            lcd_print_char(1, writeLoc, wifiPass[wifiPassLoc]);

            writeLoc++;
            wifiPassLoc++;
            passStart++;

            HAL_Delay(150);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
            if(strlen(wifiPass) >= 1) {
            	if(writeLoc > 7) {
            		writeLoc--;
            	} else if(writeLoc < 7) {
            		writeLoc = 7;
            	}

            	if(wifiPassLoc > 0) {
            		wifiPassLoc--;
            		passStartPos--;
            	} else if(wifiPassLoc < 0) {
            		wifiPassLoc = 0;
            	}

            	wifiPass[wifiPassLoc] = '\0';
            	eepromData[passStartPos] = '\0';
            	wifiPassInt[wifiPassLoc] = '\0';

            	lcd_delete_char(1, 6+wifiPassLoc);
            	HAL_Delay(50);
            }

            HAL_Delay(150);
        }

        lcd_gotoxy(2, cursorPosition);
    }
}

char* mergeData() {
	char combinedString[44] = "";
	char temp[10];

	uint8_t uintVariables[] = {
			devirmeYuruyusSecim,
			calismaSekli,
			emniyetCercevesi,
			yavaslamaLimit,
			altLimit,
			kapiTablaAcKonum,
			basincSalteri,
			kapiSecimleri,
			kapiAcTipi,
			kapi1Tip,
			kapi1AcSure,
			kapi2Tip,
			kapi2AcSure,
			kapitablaTip,
			kapiTablaAcSure,
			yukariYavasLimit,
			devirmeYukariIleriLimit,
			devirmeAsagiGeriLimit,
			devirmeSilindirTipi,
			platformSilindirTipi,
			yukariValfTmr,
			asagiValfTmr,
			devirmeYukariIleriTmr,
			devirmeAsagiGeriTmr,
			makineCalismaTmr,
			buzzer,
			demoMode,
			calismaSayisi1,
			calismaSayisi10,
			calismaSayisi100,
			calismaSayisi1000,
			calismaSayisi10000,
			dilSecim,
			eepromData[38],
			eepromData[39],
			eepromData[40],
			eepromData[41],
			eepromData[42],
			eepromData[43],
			eepromData[44],
			eepromData[45],
			eepromData[46],
			eepromData[47],
			lcdBacklightSure
	};

	for (int i = 0; i < sizeof(uintVariables) / sizeof(uintVariables[0]); ++i) {
	    sprintf(temp, "%u", uintVariables[i]);
	    strcat(combinedString, temp);
	}

	char* result = malloc(strlen(combinedString) + 1);
	strcpy(result, combinedString);
	return result;
}

void convertAndSendData() {
	if(dilSecim == 0) {
		lcd_print(1, 1, "  Veri  Esleme  ");
		lcd_print(2, 1, " Baslatildi ... ");
	} else {
		lcd_print(1, 1, " Syncronization ");
		lcd_print(2, 1, "   Started...   ");
	}
	for(int i=0; i<2; i++) {
		sendMachineData(&huart1, machineID, mergeData());
	}
	HAL_Delay(500);
	lcd_clear();
}

void iotSetup() {
	if(iotMode != 0) {
		if(machineID[machineIDCharacterLimit-1] == '\0') {
			takeMachineID();
		}
		HAL_Delay(500);

		if(wifiSSID[0] == '\0') {
			takeWifiSSID();
		}
		HAL_Delay(500);

		if(wifiPass[0] == '\0') {
			takeWifiPass();
		}
		HAL_Delay(500);
	}

	ESP8266_Init(&huart1, wifiSSID, wifiPass);
	HAL_Delay(500);
	convertAndSendData();
}

