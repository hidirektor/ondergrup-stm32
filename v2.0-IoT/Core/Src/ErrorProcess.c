/*
 * ErrorProcess.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "ErrorProcess.h"
#include "main.h"
#include "GlobalVariables.h"
#include "i2c-lcd.h"
#include "EEPROMProcess.h"
#include "TextVariables.h"

void hata2EEPROM(uint8_t hataKodu) {
	if(eepromData[eepromHataBaslangic+(indeksSayisi-1)] != 0) {
		eepromDataFillWithEmpty();
		goto veriEkleme;
	} else {
		veriEkleme:
			for(int i=0; i<indeksSayisi; i++) {
				if(eepromData[eepromHataBaslangic+i] == 0) {
					eepromData[eepromHataBaslangic+i] = hataKodu;
					break;
				}
			}
	}

	HAL_I2C_Mem_Write(&hi2c1, 0xA0, eepromHataBaslangic, indeksSayisi, &eepromData[eepromHataBaslangic], indeksSayisi, 3000);
	HAL_Delay(500);
	eepromKontrol();
}

void hataKoduLcdGoster(uint8_t x) {
	if(x==1) {
		lcd_print(1, 1, errorCodeText);
		lcd_print(2, 1, "1");
		lcd_print(2, 7, "          ");
	} else if(x==2){
		lcd_print(1, 1, errorCodeText);
		lcd_print(2, 2, "2");
		lcd_print(2, 7, "          ");
	} else if(x==3) {
		lcd_print(1, 1, errorCodeText);
		lcd_print(2, 3, "3");
		lcd_print(2, 7, "          ");
	} else if(x==4){
		lcd_print(1, 1, errorCodeText);
		lcd_print(2, 4, "4");
		lcd_print(2, 7, "          ");
	} else if(x==5) {
		lcd_print(1, 1, errorCodeText);
		lcd_print(2, 5, "5");
		lcd_print(2, 7, "          ");
	} else if(x==6) {
		lcd_print(1, 1, errorCodeText);
		lcd_print(2, 6, "6");
		lcd_print(2, 7, "          ");
	}
}

void eepromDataFillWithEmpty(void) {
	for(int i=0; i<indeksSayisi; i++) {
		eepromData[eepromVal[i]] = 0;
	}
}
