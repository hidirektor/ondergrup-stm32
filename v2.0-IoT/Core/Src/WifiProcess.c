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
#include "IoTMenu.h"
#include "EEPROMProcess.h"

void takeMachineID() {
	uint8_t inputMachineID[machineIDCharacterLimit];
	mainSection:
	lcd_cursor(1);

	int writeLoc = 5; //kullanıcının seçtiği karkaterin yazılırken başlayacağı karakter değişkeni

    int cursorPosition = 3; //kullanıcının seçim yaptığı işaretçinin konumu
    int arrayPos = 0; //kullanıcının seçtiği karakteri diziye aktarırken kullanılacak olan değişken
    int eepromVal = idStartPos; //kullanıcının seçtiği karakteri eeproma aktarmak için kullanılacak olan değişken

    resetEEPROM4Wifi(1);
    HAL_Delay(100);

    printTemplate(1, 0);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
        	lcd_cursor(0);

        	if(strlen(machineID) != machineIDCharacterLimit) {
        		lcd_clear();
        		lcd_print(1, 1, " ID 12 KARAKTER ");
        		lcd_print(2, 1, " OLMAK ZORUNDA! ");
        		HAL_Delay(1200);
        		goto mainSection;
        	} else {
        		memcpy(inputMachineID, &eepromData[idStartPos], machineIDCharacterLimit);

            	HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
            	HAL_Delay(1000);

            	break;
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

            HAL_Delay(150);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
        	if(cursorPosition == 3) {
        		//machineID[arrayPos] = '0';
        		inputMachineID[arrayPos] = 0;
        		eepromData[eepromVal] = 0;
        	} else if(cursorPosition == 4) {
        		//machineID[arrayPos] = '1';
        		inputMachineID[arrayPos] = 1;
        		eepromData[eepromVal] = 1;
        	} else if(cursorPosition == 5) {
        		//machineID[arrayPos] = '2';
        		inputMachineID[arrayPos] = 2;
        		eepromData[eepromVal] = 2;
        	} else if(cursorPosition == 6) {
        		//machineID[arrayPos] = '3';
        		inputMachineID[arrayPos] = 3;
        		eepromData[eepromVal] = 3;
        	} else if(cursorPosition == 7) {
        		//machineID[arrayPos] = '4';
        		inputMachineID[arrayPos] = 4;
        		eepromData[eepromVal] = 4;
        	} else if(cursorPosition == 10) {
        		//machineID[arrayPos] = '5';
        		inputMachineID[arrayPos] = 5;
        		eepromData[eepromVal] = 5;
        	} else if(cursorPosition == 11) {
        		//machineID[arrayPos] = '6';
        		inputMachineID[arrayPos] = 6;
        		eepromData[eepromVal] = 6;
        	} else if(cursorPosition == 12) {
        		//machineID[arrayPos] = '7';
        		inputMachineID[arrayPos] = 7;
        		eepromData[eepromVal] = 7;
        	} else if(cursorPosition == 13) {
        		//machineID[arrayPos] = '8';
        		inputMachineID[arrayPos] = 8;
        		eepromData[eepromVal] = 8;
        	} else if(cursorPosition == 14) {
        		//machineID[arrayPos] = '9';
        		inputMachineID[arrayPos] = 9;
        		eepromData[eepromVal] = 9;
        	}

        	lcd_print_char(1, writeLoc, machineID[arrayPos]);

        	writeLoc++;
        	arrayPos++;
        	eepromVal++;

        	//machineID[machineIDCharacterLimit] = '\0';
        	inputMachineID[arrayPos] = '\0';
        	eepromData[eepromVal] = '\0';

        	HAL_Delay(150);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
            if(strlen(machineID) >= 1) {
                //machineID[arrayPos] = '\0';
            	inputMachineID[arrayPos] = '\0';
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

                lcd_delete_char(1, 4+arrayPos);
                HAL_Delay(50);
            }

            HAL_Delay(150);
        }

        lcd_gotoxy(2, cursorPosition);
    }
}

void takeWifiSSID() {
	mainSSIDSection:
    lcd_cursor(1);

    resetEEPROM4Wifi(2);
    HAL_Delay(100);

    int page = 1; //wifi karakterleri için sayfa değişkeni
    int writeLoc = 7; //seçilen karakterleri yazdırmaya başlanılacak karakter

    int cursorPosition = 1; //kullanıcının gezindiği işaretçinin değişkeni
    int arrayPosition = 0; //kullanıcının seçtiği karakteri diziye aktarırken kullanılacak değişken
    int eepromVal = ssidStartPos; //kullanıcının seçtiği karakteri eeproma yazarken kullanılacak değişken

    printTemplate(2, 1);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
            lcd_cursor(0);

            if(strlen(wifiSSID) > 20) {
                lcd_clear();
                lcd_print(1, 1, " 20 KARAKTERDEN ");
                lcd_print(2, 1, "FAZLA SSID OLMAZ");
                HAL_Delay(1250);
                goto mainSSIDSection;
            } else {
            	HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
            	HAL_Delay(1000);

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
        	//wifiSSID[arrayPosition] = charactersArray[cursorPosition - 1];
            //wifiSSIDInt[arrayPosition] = cursorPosition - 1;
            eepromData[eepromVal] = cursorPosition - 1;

            lcd_print_char(1, writeLoc, wifiSSID[arrayPosition]);

            writeLoc++;
            arrayPosition++;
            eepromVal++;

            //wifiSSID[arrayPosition] = '\0';
            //wifiSSIDInt[arrayPosition] = '\0';
            eepromData[eepromVal] = '\0';

            HAL_Delay(150);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
        	if(strlen(wifiSSID) >= 1) {
        		//wifiSSID[arrayPosition] = '\0';
        		//wifiSSIDInt[arrayPosition] = '\0';
        		eepromData[eepromVal] = '\0';

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

        		lcd_delete_char(1, 6+arrayPosition);
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

    resetEEPROM4Wifi(3);
    HAL_Delay(100);

    int page = 1; //wifi karakterleri için sayfa değişkeni
    int writeLoc = 7; //seçilen karakterlerin yazılacağı başlangıç karakteri

    int cursorPosition = 1; //kullanıcının seçim yaparken kullandığı işaretçi değişkeni
    int arrayPos = 0; //kullanıcının seçtiği karakteri diziye aktarmak için kullanılacak olan değişken
    int eepromVal = passStartPos; //kullanıcının seçtiği karakteri eeproma aktarırken kullanılacak olan değişken

    printTemplate(3, 1);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
            lcd_cursor(0);

            if(strlen(wifiPass) > 20) {
                lcd_clear();
                lcd_print(1, 1, " 20 KARAKTERDEN ");
                lcd_print(2, 1, "FAZLA PASS OLMAZ");
                HAL_Delay(1200);
                goto mainPASSSection;
            } else {
            	HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
            	HAL_Delay(1000);

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
        	//wifiPass[arrayPos] = charactersArray[cursorPosition - 1];
        	//wifiPassInt[arrayPos] = cursorPosition - 1;
        	eepromData[eepromVal] = cursorPosition - 1;

            lcd_print_char(1, writeLoc, wifiPass[arrayPos]);

            writeLoc++;
            arrayPos++;
            eepromVal++;

            //wifiPass[arrayPos] = '\0';
            //wifiPassInt[arrayPos] = '\0';
            eepromData[eepromVal] = '\0';

            HAL_Delay(150);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
            if(strlen(wifiPass) >= 1) {
            	//wifiPass[arrayPos] = '\0';
            	//wifiPassInt[arrayPos] = '\0';
            	eepromData[eepromVal] = '\0';

            	writeLoc--;
            	arrayPos--;
            	eepromVal--;

            	lcd_delete_char(1, 6+arrayPos);
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

	sendMachineData(&huart1, machineID, wifiSSID, wifiPass, mergeData());

	HAL_Delay(500);
	lcd_clear();
}

void iotSetup() {
	if(iotMode != 0) {
		if(strlen(machineID) != machineIDCharacterLimit) {
			takeMachineID();
		}

		if(!(strlen(wifiSSID) >= 2)) {
			takeWifiSSID();
		}

		if(!(strlen(wifiPass) >= 2)) {
			takeWifiPass();
		}
	}

	if(setupCompleted != 1) {
		takeIDSection:
		if(checkMachineID(&huart1, machineID) == 1) {
			setupCompleted = 1;
			//EEPROMA yazma işlemini başlat
        	HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
        	HAL_Delay(1000);
		} else {
			if(dilSecim == 1) {
				//türkçe hata mesajı
				lcd_print(1, 1, " BU ID MAKINEDE ");
				lcd_print(2, 1, "  KULLANILAMAZ  ");
			} else {
				//ingilizce hata mesajı
				lcd_print(1, 1, "ID NOT AVAILABLE");
				lcd_print(2, 1, "FOR THIS MACHINE");
			}

			HAL_Delay(1250);
			//Tekrar id alma işlemi
			takeMachineID();
			HAL_Delay(200);
			goto takeIDSection;
		}
	}

	ESP8266_Init(&huart1, wifiSSID, wifiPass);
	HAL_Delay(500);
	convertAndSendData();
}
