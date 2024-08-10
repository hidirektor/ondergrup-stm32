/*
 * WifiProcess.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "WifiProcess.h"
#include "main.h"
#include "GlobalVariables.h"
#include "WifiCommands.h"
#include "i2c-lcd.h"
#include "IoTMenu.h"
#include "EEPROMProcess.h"
#include "TextVariables.h"


void takeMachineIDWithConfirmation() {
	HAL_Delay(500);
	int confirmationVal = 0;
	while(confirmationVal == 0) {
		lcd_print(1, 1, idConfirmationText);
		lcd_print(2, 1, idConfirmationSubText);

		if((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin)) == 1) {
			confirmationVal = 1;
		}
	}

	takeMachineID();

	convertArrays(1);
	HAL_Delay(50);

	printCredentials(1); //Ekrana makine id'si yazdır.
}

void takeMachineID() {
	mainSection:

	lcd_cursor(1);
    memset(machineID, 0, machineIDCharacterLimit*sizeof(*machineID));

	int writeLoc = 5; //kullanıcının seçtiği karkaterin yazılırken başlayacağı karakter değişkeni

    int cursorPosition = 3; //kullanıcının seçim yaptığı işaretçinin konumu
    int arrayPos = 0; //kullanıcının seçtiği karakteri diziye aktarırken kullanılacak olan değişken
    int eepromVal = idStartPos; //kullanıcının seçtiği karakteri eeproma aktarmak için kullanılacak olan değişken

    printTemplate(1, 0);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
        	lcd_cursor(0);

        	if(checkEEPROM4ID() != 1) {
        		lcd_print(1, 1, mustBe12Text);
        		lcd_print(2, 1, mustBe122Text);
        		HAL_Delay(1250);

        		goto mainSection;
        	}

        	//int machineIDControl = 0;
        	//for(int i=0; i<2; i++) {
        		//machineIDControl = checkMachineID(&huart1, machineID);
        	//}

        	int adminPassword = az5();

        	if(adminPassword == 1) {
        		saveEEPROM(1);
        	} else {
        		//Özel mesaj ayarlanacak
        		lcd_print(1, 1, mustBeUniqueText);
        		lcd_print(2, 1, mustBeUnique2Text);

        		HAL_Delay(500);

        		goto mainSection;
        	}
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
        	if(cursorPosition == 7) {
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
            } else if(cursorPosition == 10) {
            	cursorPosition = 7;
            } else {
            	cursorPosition--;
            }

            HAL_Delay(250);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
        	if(cursorPosition == 3) {
        		machineID[arrayPos] = '0';
        		eepromData[eepromVal] = 0;
        	} else if(cursorPosition == 4) {
        		machineID[arrayPos] = '1';
        		eepromData[eepromVal] = 1;
        	} else if(cursorPosition == 5) {
        		machineID[arrayPos] = '2';
        		eepromData[eepromVal] = 2;
        	} else if(cursorPosition == 6) {
        		machineID[arrayPos] = '3';
        		eepromData[eepromVal] = 3;
        	} else if(cursorPosition == 7) {
        		machineID[arrayPos] = '4';
        		eepromData[eepromVal] = 4;
        	} else if(cursorPosition == 10) {
        		machineID[arrayPos] = '5';
        		eepromData[eepromVal] = 5;
        	} else if(cursorPosition == 11) {
        		machineID[arrayPos] = '6';
        		eepromData[eepromVal] = 6;
        	} else if(cursorPosition == 12) {
        		machineID[arrayPos] = '7';
        		eepromData[eepromVal] = 7;
        	} else if(cursorPosition == 13) {
        		machineID[arrayPos] = '8';
        		eepromData[eepromVal] = 8;
        	} else if(cursorPosition == 14) {
        		machineID[arrayPos] = '9';
        		eepromData[eepromVal] = 9;
        	}

        	lcd_print_char(1, writeLoc, machineID[arrayPos]);

        	writeLoc++;
        	arrayPos++;
        	eepromVal++;

        	HAL_Delay(150);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
            if(strlen(machineID) >= 1) {
                machineID[arrayPos] = '\0';
                eepromData[eepromVal] = '\0';

                if(writeLoc > 5) {
                	writeLoc--;
                } else if(writeLoc < 5) {
                	writeLoc = 5;
                }

                if(arrayPos > 0) {
                	arrayPos--;
                	eepromVal--;
                } else if(arrayPos < 0) {
                	arrayPos = 0;
                	eepromVal = idStartPos;
                }

                lcd_delete_char(1, 4+arrayPos+1);
                HAL_Delay(50);
            }

            HAL_Delay(150);
        }

        lcd_gotoxy(2, cursorPosition);
    }
}

uint8_t ssidConfirmation() {
	int loopVal = 1;
	lcd_print(1, 1, "                ");

	while(loopVal == 1) {
		lcd_print(2, 1, wifiConfirmationText);
		if(HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
			loopVal = 0;
		}

		lcd_print(1, 1, wifiSSID);
	}

    lcd_cursor(0);

    if(strlen(wifiSSID) > 20) {
    	lcd_print(1, 1, ssidExceedErrorText);
    	lcd_print(2, 1, ssidExceedError2Text);
        HAL_Delay(1250);

        return 0;
    } else {
    	saveEEPROM(1);

    	return 1;
    }
}

void takeWifiSSID() {
	mainSSIDSection:

    lcd_cursor(1);
    memset(wifiSSID, 0, wifiCharacterLimit*sizeof(*wifiSSID));

    int page = 1; //wifi karakterleri için sayfa değişkeni
    int writeLoc = 7; //seçilen karakterleri yazdırmaya başlanılacak karakter

    int cursorPosition = 1; //kullanıcının gezindiği işaretçinin değişkeni
    int arrayPosition = 0; //kullanıcının seçtiği karakteri diziye aktarırken kullanılacak değişken
    int eepromVal = ssidStartPos; //kullanıcının seçtiği karakteri eeproma yazarken kullanılacak değişken

    printTemplate(2, 1);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
        	if(ssidConfirmation() == 0) {
        		goto mainSSIDSection;
        	} else {
        		break;
        	}
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
        	if(cursorPosition > 80) {
        		cursorPosition = 1;
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
        	if(cursorPosition < 1) {
        		cursorPosition = 80;
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
            eepromData[eepromVal] = cursorPosition;
            wifiSSID[arrayPosition] = charactersArray[cursorPosition];

            lcd_print_char(1, writeLoc, charactersArray[cursorPosition]);

            writeLoc++;
            arrayPosition++;
            eepromVal++;

            eepromData[eepromVal] = '\0';
            wifiSSID[arrayPosition] = '\0';

            HAL_Delay(150);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
        	if(strlen(wifiSSID) >= 1) {
        		eepromData[eepromVal] = '\0';
        		wifiSSID[arrayPosition] = '\0';

        		if(writeLoc > 7) {
        			writeLoc--;
        		} else if(writeLoc < 7) {
        			writeLoc = 7;
        		}

        		if(arrayPosition > 0) {
        			arrayPosition--;
        			eepromVal--;
        		} else if(arrayPosition < 0) {
        			arrayPosition = 0;
        			eepromVal = ssidStartPos;
        		}

        		lcd_delete_char(1, 6+arrayPosition+1);
        		HAL_Delay(50);
        	}

        	HAL_Delay(150);
        }

        lcd_gotoxy(2, cursorPosition);
    }
}

uint8_t passConfirmation() {
	int loopVal = 1;
	lcd_print(1, 1, "                ");

	while(loopVal == 1) {
		lcd_print(2, 1, wifiConfirmationText);
		if(HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
			loopVal = 0;
		}

		lcd_print(1, 1, wifiPass);
	}

    lcd_cursor(0);

    if(strlen(wifiPass) > 20) {
    	lcd_print(1, 1, passExceedErrorText);
    	lcd_print(2, 1, passExceedError2Text);
        HAL_Delay(1250);

        return 0;
    } else {
    	saveEEPROM(1);

    	return 1;
    }
}

void takeWifiPass() {
	mainPassSection:

    lcd_cursor(1);
    memset(wifiPass, 0, wifiCharacterLimit*sizeof(*wifiPass));

    int page = 1; //wifi karakterleri için sayfa değişkeni
    int writeLoc = 7; //seçilen karakterleri yazdırmaya başlanılacak karakter

    int cursorPosition = 1; //kullanıcının gezindiği işaretçinin değişkeni
    int arrayPosition = 0; //kullanıcının seçtiği karakteri diziye aktarırken kullanılacak değişken
    int eepromVal = passStartPos; //kullanıcının seçtiği karakteri eeproma yazarken kullanılacak değişken

    printTemplate(3, 1);

    while (1) {
    	if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
    	    if(passConfirmation() == 0) {
    	        goto mainPassSection;
    	    } else {
    	        break;
    	    }
    	}

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
        	if(cursorPosition > 80) {
        		cursorPosition = 1;
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
        	if(cursorPosition < 1) {
        		cursorPosition = 80;
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
            eepromData[eepromVal] = cursorPosition;
            wifiPass[arrayPosition] = charactersArray[cursorPosition];

            lcd_print_char(1, writeLoc, charactersArray[cursorPosition]);

            writeLoc++;
            arrayPosition++;
            eepromVal++;

            eepromData[eepromVal] = '\0';
            wifiPass[arrayPosition] = '\0';

            HAL_Delay(150);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
        	if(strlen(wifiPass) >= 1) {
        		eepromData[eepromVal] = '\0';
        		wifiPass[arrayPosition] = '\0';

        		if(writeLoc > 7) {
        			writeLoc--;
        		} else if(writeLoc < 7) {
        			writeLoc = 7;
        		}

        		if(arrayPosition > 0) {
        			arrayPosition--;
        			eepromVal--;
        		} else if(arrayPosition < 0) {
        			arrayPosition = 0;
        			eepromVal = passStartPos;
        		}

        		lcd_delete_char(1, 6+arrayPosition+1);
        		HAL_Delay(50);
        	}

        	HAL_Delay(150);
        }

        lcd_gotoxy(2, cursorPosition);
    }
}

char* mergeData() {
	char combinedString[45] = "";
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
			calismaSayisi,
			calismaSayisiDemo,
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

char* getCredentials(int type) {
	if(type == 1) {
		char combinedString[12] = "";
		char temp[10];

		int startPos = idStartPos;

		uint8_t uintVariables[] = {
				eepromData[startPos + 0],
				eepromData[startPos + 1],
				eepromData[startPos + 2],
				eepromData[startPos + 3],
				eepromData[startPos + 4],
				eepromData[startPos + 5],
				eepromData[startPos + 6],
				eepromData[startPos + 7],
				eepromData[startPos + 8],
				eepromData[startPos + 9],
				eepromData[startPos + 10],
				eepromData[startPos + 11]
		};

		for (int i = 0; i < sizeof(uintVariables) / sizeof(uintVariables[0]); ++i) {
			sprintf(temp, "%u", uintVariables[i]);
			strcat(combinedString, temp);
		}

		char* result = malloc(strlen(combinedString) + 1);
		strcpy(result, combinedString);
		return result;
	} else if(type == 2) {
		char combinedString[20] = "";
		char temp[10];

		int startPos = ssidStartPos;

		uint8_t uintVariables[] = {
				eepromData[startPos + 0],
				eepromData[startPos + 1],
				eepromData[startPos + 2],
				eepromData[startPos + 3],
				eepromData[startPos + 4],
				eepromData[startPos + 5],
				eepromData[startPos + 6],
				eepromData[startPos + 7],
				eepromData[startPos + 8],
				eepromData[startPos + 9],
				eepromData[startPos + 10],
				eepromData[startPos + 11],
				eepromData[startPos + 12],
				eepromData[startPos + 13],
				eepromData[startPos + 14],
				eepromData[startPos + 15],
				eepromData[startPos + 16],
				eepromData[startPos + 17],
				eepromData[startPos + 18],
				eepromData[startPos + 19]
		};

		for (int i = 0; i < sizeof(uintVariables) / sizeof(uintVariables[0]); ++i) {
			sprintf(temp, "%u", uintVariables[i]);
			strcat(combinedString, temp);
		}

		char* result = malloc(strlen(combinedString) + 1);
		strcpy(result, combinedString);
		return result;
	} else {
		char combinedString[20] = "";
		char temp[10];

		int startPos = passStartPos;

		uint8_t uintVariables[] = {
				eepromData[startPos + 0],
				eepromData[startPos + 1],
				eepromData[startPos + 2],
				eepromData[startPos + 3],
				eepromData[startPos + 4],
				eepromData[startPos + 5],
				eepromData[startPos + 6],
				eepromData[startPos + 7],
				eepromData[startPos + 8],
				eepromData[startPos + 9],
				eepromData[startPos + 10],
				eepromData[startPos + 11],
				eepromData[startPos + 12],
				eepromData[startPos + 13],
				eepromData[startPos + 14],
				eepromData[startPos + 15],
				eepromData[startPos + 16],
				eepromData[startPos + 17],
				eepromData[startPos + 18],
				eepromData[startPos + 19]
		};

		for (int i = 0; i < sizeof(uintVariables) / sizeof(uintVariables[0]); ++i) {
			sprintf(temp, "%u", uintVariables[i]);
			strcat(combinedString, temp);
		}

		char* result = malloc(strlen(combinedString) + 1);
		strcpy(result, combinedString);
		return result;
	}
}

void convertAndSendData() {
	lcd_print(1, 1, dataSynchText);
	lcd_print(2, 1, dataSynch2Text);

	for(int i=0; i<2; i++) {
		sendMachineData(&huart1, machineID, wifiSSID, wifiPass, mergeData());
	}

	HAL_Delay(500);
	lcd_clear();
}

void iotSetup() {
	if(iotMode != 0) {
		if(checkEEPROM4ID() != 1) {
			takeMachineID();
		}

		if(!(strlen(wifiSSID) >= 2)) {
			takeWifiSSID();
		}

		if(!(strlen(wifiPass) >= 2)) {
			takeWifiPass();
		}

		ESP8266_Init(&huart1, demoWifiSSIDEv, demoWifiPassEv);
		HAL_Delay(500);
		convertAndSendData();
	}
}

int checkEEPROM4ID() {
	int eepromVal = idStartPos;
	int returnVal = 1;

	for(int i=0; i<machineIDCharacterLimit; i++) {
		if(eepromData[eepromVal] == '\0') {
			returnVal = 0;
		}
		eepromVal++;
	}

	return returnVal;
}

int az5() {
	//Özel şifre iste
	return 0;
}
