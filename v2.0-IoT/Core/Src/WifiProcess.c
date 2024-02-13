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
	bool validInput = false;

	int loc = 0;
	int writeLoc = 5;

	memset(machineID, 0, sizeof(machineID));

	while(!validInput) {
		lcd_clear();

		saveCharacter(loc, writeLoc, idStartPos, 'M');

		if(checkMachineID(&huart1, machineID) == 1) {
			validInput = true; // Doğru uzunlukta veri girildi
			setupCompleted = 1;
		} else {
			lcd_clear();
			HAL_Delay(50);
			if(dilSecim == 0) {
				lcd_print(1, 1, "BU ID FARKLI BIR");
				lcd_print(2, 1, " MAKINEDE AKTIF ");
			} else {
				lcd_print(1, 1, "THIS  ID CAN NOT");
				lcd_print(2, 1, "    BE  USED    ");
			}
			HAL_Delay(2000);

			loc = 0;
			writeLoc = 5;
			memset(machineID, 0, sizeof(machineID));
		}
	}

	//EEPROM'a kaydetme işini burada gerçekleştir
	HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
	HAL_Delay(1200);
}

void takeWifiSSID() {
    bool validInput = false;

    int loc = 0;
    int writeLoc = 7;

    memset(wifiSSID, 0, sizeof(wifiSSID));

    while(!validInput) {
        lcd_clear();

        saveCharacter(loc, writeLoc, ssidStartPos, 'S');

        if (strlen(wifiSSID) <= 20) {
            validInput = true; // Uygun uzunlukta veri girildi
        } else {
            lcd_clear();
            if(dilSecim == 0) {
            	lcd_print(1, 1, " 20 KARAKTERDEN ");
            	lcd_print(2, 1, "FAZLA SSID OLMAZ");
            } else {
            	lcd_print(1, 1, "SSID CANT EXCEED");
            	lcd_print(2, 1, " 20 CHARACTERS ");
            }
            HAL_Delay(2000); // Kullanıcıya mesajı göster
            // Uzunluğu sıfırla ve yeniden dene
            loc = 0;
            writeLoc = 7;
            memset(wifiSSID, 0, sizeof(wifiSSID));
        }
    }

    // EEPROM'a kaydetme işini burada gerçekleştir
	HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
	HAL_Delay(1200);
}

void takeWifiPass() {
    bool validInput = false;

    int loc = 0;
    int writeLoc = 7;

    memset(wifiPass, 0, sizeof(wifiPass));

    while(!validInput) {
        lcd_clear();

        saveCharacter(loc, writeLoc, passStartPos, 'P');

        if (strlen(wifiPass) <= 20) {
            validInput = true; // Uygun uzunlukta veri girildi
        } else {
            lcd_clear();
            if(dilSecim == 0) {
            	lcd_print(1, 1, " 20 KARAKTERDEN ");
            	lcd_print(2, 1, "FAZLA PASS OLMAZ");
            } else {
            	lcd_print(1, 1, "PASS CANT EXCEED");
            	lcd_print(2, 1, " 20 CHARACTERS ");
            }
            HAL_Delay(2000); // Kullanıcıya mesajı göster
            // Uzunluğu sıfırla ve yeniden dene
            loc = 0;
            writeLoc = 7;
            memset(wifiPass, 0, sizeof(wifiPass));
        }
    }

    // EEPROM'a kaydetme işini burada gerçekleştir
	HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
	HAL_Delay(1200);
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
		/*if(machineID[machineIDCharacterLimit-1] == '\0') {
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
		HAL_Delay(500);*/

		takeMachineID();
		HAL_Delay(10);
		takeWifiSSID();
		HAL_Delay(10);
		takeWifiPass();
	}

	ESP8266_Init(&huart1, wifiSSID, wifiPass);
	HAL_Delay(500);
	convertAndSendData();
}

void saveCharacter(int arrayPos, int lcdPos, int eepromStartPos, char type) {
	int loc = arrayPos;
	int writeLoc = lcdPos;
	int startPos = eepromStartPos;
    int characterPos = 0; // Kullanıcının LCD üzerinde seçtiği karakterin pozisyonu
    char selectedChar;

    int cursorLoc = 1;

    int page = 1; // SSID ve password için sayfa kontrolü

    lcd_clear();
    HAL_Delay(50);
    lcd_cursor(1);
    if (type == 'M') {
    	printTemplate(1, 0);
    	cursorLoc = 3;
    } else {
    	printTemplate(type == 'S' ? 2 : 3, page);
    }

    lcd_gotoxy(2, cursorLoc); //Seçim işleminden önce işaretçiyi geçerli konuma gönder

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
            // Kaydetme işlemini bitir
        	if(type == 'M') {
        		if (strlen(machineID) == 12) {

        		} else {
        			lcd_clear();
        			if(dilSecim == 0) {
        				lcd_print(1, 1, " ID 12 KARAKTER ");
        				lcd_print(2, 1, " OLMAK ZORUNDA! ");
        			} else {
        				lcd_print(1, 1, "MACHINE ID MUST");
        				lcd_print(2, 1, "BE 12 CHARACTERS");
        			}
        			HAL_Delay(2000); // Kullanıcıya mesajı göster

        			loc = 0;
        			writeLoc = 5;
        			memset(machineID, 0, sizeof(machineID));
        		}
        	} else {
        		break;
        	}
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
        	if(type == 'M') {
        		if(cursorLoc == 7) {
        			cursorLoc = 10;
        		} else if(cursorLoc == 14) {
        			cursorLoc = 3;
        		} else {
        			cursorLoc++;
        		}
        	} else {
        		if(cursorLoc == 16) {
        			page++;
        			cursorLoc++;
        		} else if(cursorLoc == 32) {
        			page++;
        			cursorLoc++;
        		} else if(cursorLoc == 48) {
        			page++;
        			cursorLoc++;
        		} else if(cursorLoc == 64) {
        			page++;
        			cursorLoc++;
        		} else if(cursorLoc == 80) {
        			page = 1;
        			cursorLoc = 1;
        		}

        		printTemplate(type == 'S' ? 2 : 3, page);
        	}

        	lcd_gotoxy(2, cursorLoc);
        	HAL_Delay(200);
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
        	if(type == 'M') {
        		if(cursorLoc == 10) {
        			cursorLoc = 7;
        		} else if(cursorLoc == 3) {
        			cursorLoc = 14;
        		} else {
        			cursorLoc--;
        		}
        	} else {
        		if(cursorLoc == 17) {
        			page--;
        			cursorLoc--;
        		} else if(cursorLoc == 33) {
        			page--;
        			cursorLoc--;
        		} else if(cursorLoc == 49) {
        			page--;
        			cursorLoc--;
        		} else if(cursorLoc == 65) {
        			page--;
        			cursorLoc--;
        		} else if(cursorLoc == 1) {
        			page = 5;
        			cursorLoc = 80;
        		}

        		printTemplate(type == 'S' ? 2 : 3, page);
        	}

        	lcd_gotoxy(2, cursorLoc);

        	HAL_Delay(200); //Debouncing
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
        	if(type == 'M') {
        		if(cursorLoc == 3) {
        			characterPos = 0;
        		} else if(cursorLoc == 4) {
        			characterPos = 1;
        		} else if(cursorLoc == 5) {
        			characterPos = 2;
        		} else if(cursorLoc == 6) {
        			characterPos = 3;
        		} else if(cursorLoc == 7) {
        			characterPos = 4;
        		} else if(cursorLoc == 10) {
        			characterPos = 5;
        		} else if(cursorLoc == 11) {
        			characterPos = 6;
        		} else if(cursorLoc == 12) {
        			characterPos = 7;
        		} else if(cursorLoc == 13) {
        			characterPos = 8;
        		} else if(cursorLoc == 14) {
        			characterPos = 9;
        		}

        		selectedChar = idCharactersArray[characterPos];
        		machineID[loc] = selectedChar; //seçilen karakteri machineID dizisine aktar

        		eepromData[startPos] = characterPos; //makine idsini eeproma kaydet

        		lcd_print_char(1, writeLoc, selectedChar); //seçilen karakteri lcd'nin ilk satırına yaz

        		loc++;
        		writeLoc++;
        		startPos++;
        	} else {
        		characterPos = (cursorLoc*page) - 1;

        		selectedChar = charactersArray[characterPos];

        		if(type == 'S') {
        			wifiSSID[loc] = selectedChar;

        			eepromData[startPos] = characterPos;

        			lcd_gotoxy(1, writeLoc); //imleci karakterin yazılacağı konuma gönder
        			lcd_print_char(1, writeLoc, selectedChar); //ekrana wifiSSID'yi yazdır
        		} else {
        			wifiPass[loc] = selectedChar;

        			eepromData[startPos] = characterPos;

        			lcd_gotoxy(1, writeLoc); //imleci karakterin yazılacağı konuma gönders
        			lcd_print_char(1, writeLoc, selectedChar); //ekrana wifiPASS'i yazdır
        		}

        		lcd_gotoxy(2, cursorLoc); //karakter seçim sırasında ki konumuna imleci geri gönder

        		loc++;
        		writeLoc++;
        		startPos++;
        	}

        	HAL_Delay(200); //Debouncing
        }

        if (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
        	if(type == 'M') {
        		loc--;
        		writeLoc--;
        		startPos--;

        		machineID[loc] = '\0';
        		eepromData[startPos] = '\0';
        		lcd_delete_char(1, writeLoc);
        	} else {
        		loc--;
        		writeLoc--;
        		startPos--;

        		if(type == 'S') {
        			wifiSSID[loc] = '\0';
        			eepromData[startPos] = '\0';

        			lcd_delete_char(1, writeLoc);
        		} else {
        			wifiPass[loc] = '\0';
        			eepromData[startPos] = '\0';

        			lcd_delete_char(1, writeLoc);
        		}

        		lcd_gotoxy(2, cursorLoc);
        	}

        	HAL_Delay(200); //Debouncing
        }
    }
}
