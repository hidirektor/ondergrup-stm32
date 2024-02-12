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
	int writeLoc = 1;

	memset(machineID, 0, sizeof(machineID));

	while(!validInput) {
		lcd_clear();

		saveCharacter(&loc, &writeLoc, machineID, idStartPos, 'M');

		if (strlen(machineID) == 12) {
		    validInput = true; // Doğru uzunlukta veri girildi
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
		    writeLoc = 1;
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
    int writeLoc = 1;

    memset(wifiSSID, 0, sizeof(wifiSSID));

    while(!validInput) {
        lcd_clear();

        saveCharacter(&loc, &writeLoc, wifiSSID, ssidStartPos, 'S');

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
            writeLoc = 1;
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
    int writeLoc = 1;

    memset(wifiPass, 0, sizeof(wifiPass));

    while(!validInput) {
        lcd_clear();

        saveCharacter(&loc, &writeLoc, wifiPass, passStartPos, 'S');

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
            writeLoc = 1;
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

void saveCharacter(int *loc, int *writeLoc, char *data, int startPos, char type) {
    int characterPos = 0; // Kullanıcının LCD üzerinde seçtiği karakterin pozisyonu
    char selectedChar;

    int charactersArrayLength = 0;
    int page = 1; // SSID ve password için sayfa kontrolü

    lcd_clear();
    if (type == 'M') {
    	charactersArrayLength = strlen(idCharactersArray);

    	printTemplate(1, 0);
    } else {
    	charactersArrayLength = strlen(charactersArray);

    	printTemplate(type == 'S' ? 2 : 3, page);
    }

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
            // Kaydetme işlemini bitir
            break;
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {

            characterPos = (characterPos + 1) % charactersArrayLength;
            // SSID ve Password için sayfa kontrolü
            if (type != 'M' && *writeLoc >= 16) {
                *writeLoc = 0; // İmleci sıfırla
                page++; // Sonraki sayfaya geç
                printTemplate(type == 'S' ? 2 : 3, page);
            }
            lcd_gotoxy(2, *writeLoc % 16);
            if(type == 'M') {
            	lcd_send_char(idCharactersArray[characterPos]);
            } else {
            	lcd_send_char(charactersArray[characterPos]);
            }
            HAL_Delay(200); // Debouncing için gecikme
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
            characterPos = (characterPos - 1 + charactersArrayLength) % charactersArrayLength;
            // SSID ve Password için sayfa kontrolü
            if (type != 'M' && *writeLoc <= 1) {
                *writeLoc = 16; // İmleci sayfanın sonuna taşı
                page = page > 1 ? page - 1 : 1; // Önceki sayfaya geç, 1'den küçük olmamalı
                printTemplate(type == 'S' ? 2 : 3, page);
            }
            lcd_gotoxy(2, (*writeLoc - 1) % 16);
            if(type == 'M') {
            	lcd_send_char(idCharactersArray[characterPos]);
            } else {
            	lcd_send_char(charactersArray[characterPos]);
            }
            HAL_Delay(200); // Debouncing için gecikme
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
            // Karakteri seç ve kaydet
        	if(type == 'M') {
        		selectedChar = idCharactersArray[characterPos];
        	} else {
        		selectedChar = charactersArray[characterPos];
        	}
            data[*loc] = selectedChar;
            eepromData[startPos + *loc] = characterPos;
            (*loc)++;
            (*writeLoc)++;
            lcd_print_char(2, *writeLoc, selectedChar);
            HAL_Delay(200); // Debouncing için gecikme
        }

        if (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
            // Son karakteri sil
            if (*loc > 0) {
                (*loc)--;
                (*writeLoc)--;
                lcd_delete_char(2, *writeLoc + 1);
                data[*loc] = '\0';
                eepromData[startPos + *loc] = '\0';
            }
            HAL_Delay(200); // Debouncing için gecikme
        }
    }
}
