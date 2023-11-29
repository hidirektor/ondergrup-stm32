/*
 * Data.h
 *
 *  Created on: Jul 27, 2023
 *      Author: hidir
 */
#ifndef INC_DATA_H_
#define INC_DATA_H_

#include "Translate.h"
#include "i2c-lcd.h"
#include <stdint.h>
#include <stdbool.h>

CAN_HandleTypeDef hcan;

I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;

char* copyText(const char* text);
char* copyTextNormal(const char* text);
void printTemplate(int type, int page);

char getCharFromCursorPosition(int cursorPosition);
void writeToEEPROM(int state);
void readFromEEPROM(int state);

void takeMachineID(int state);
void takeWifiSSID(int state);
void takeWifiPass(int state);

int checkSlideVal(int state);
void slideText(const char* text, int startPos, int startLine, int state);

void menu();
void loadMenuTexts(uint8_t dilSecim);

uint8_t eepromData[110];
uint8_t kaydedilenDeger = 0;
char snum[5];
unsigned long millis = 0;
unsigned long timer = 0;
unsigned long timer1 = 0;
unsigned long timer2 = 0;
unsigned long timer3 = 0;
unsigned long timer4 = 0;				// maksimum calisma kayit suresi
unsigned long timer5 = 0;				// basinc kayit suresi
unsigned long timer6 = 0;				// lcd update suresi
unsigned long backLightTimer = 0;
int eepromVal[] = {38, 39, 40, 41, 42, 43, 44, 45, 46, 47};
int eepromFull[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int indeksSayisi = sizeof(eepromVal)/sizeof(eepromVal[0]);
int eepromHataBaslangic = 38;

uint8_t lcdBacklightSure = 6; //Buradaki değer 10 ile çarpılıyor. Maksimum 90 saniyeyi destekler.

char machineID[12];
char wifiSSID[20];
char wifiPass[20];

int cursorPosition = 1;
int page = 1;
char emptyArray[] = "                ";
char charactersArray[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=<>? ";

uint8_t idKontrol = 0;
uint8_t safeVal = 0;

uint8_t idStartPos = 50;
uint8_t ssidStartPos = 62;
uint8_t passStartPos = 82;

uint8_t x = 0;
uint8_t y = 0;
uint8_t calismaSayisi = 0; //
uint8_t calismaSayisi1 = 0; //
uint8_t calismaSayisi10 = 0; //
uint8_t calismaSayisi100 = 2; //
uint8_t calismaSayisi1000 = 1; //
uint8_t calismaSayisi10000 = 0; //
//Menü içi parametreler
uint8_t menuSayac = 0;
uint8_t durakSayisi = 0;
uint8_t calismaSekli = 0;
uint8_t hataGostermeSirasi = 0;
uint8_t basincVar = 0;
uint8_t basincVartmr = 0;
uint8_t emniyetCercevesi = 0;
uint8_t yavaslamaLimit = 0;
uint8_t altLimit = 0;
uint8_t basincSalteri = 0;
uint8_t kapiSecimleri = 0;
uint8_t kapi1Tip = 0;
uint8_t kapi2Tip = 0;
uint8_t kapitablaTip = 0;
uint8_t kapiAcTipi = 0;
uint8_t kapiTablaAcKonum = 0;
uint8_t yukariYavasLimit = 0;
uint8_t devirmeYuruyusSecim = 0;
uint8_t devirmeYukariIleriLimit = 0;
uint8_t devirmeAsagiGeriLimit = 0;
uint8_t devirmeSilindirTipi = 0;
uint8_t platformSilindirTipi = 0;
uint8_t yukariValfTmr = 0;
uint8_t asagiValfTmr = 0;
uint8_t devirmeYukariIleriTmr = 0;
uint8_t devirmeAsagiGeriTmr = 0;
uint8_t makineCalismaTmr = 0;
uint8_t kapi1AcSure = 0;
uint8_t kapi2AcSure = 0;
uint8_t kapiTablaAcSure = 0;
uint8_t buzzer = 0;
uint8_t menuGiris = 0;
uint8_t demoMode = 0;
uint8_t iotMode = 0;
uint8_t calismaSayModu = 0;
uint8_t dilSecim = 0;
uint8_t hataKayit1 = 0;
uint8_t hataKayit2 = 0;
uint8_t hataKayit3 = 0;
uint8_t hataKayit4 = 0;
uint8_t hataKayit5 = 0;
uint8_t hataKayit6 = 0;
uint8_t hataKayit7 = 0;
uint8_t hataKayit8 = 0;
uint8_t hataKayit9 = 0;
uint8_t hataKayit10 = 0;
bool hafizaYaz = 0;
bool hafizaOku = 0;
bool ilkOkuma = 0;
bool butonKontrol = 0;
bool butonKontrol2 = 0;
bool butonKontrol3 = 0;
bool butonKontrol4 = 0;
bool butonKontrol5 = 0;
bool mesajYazildi = 0;
bool yukarimotorcalisiyor = 0;
bool devmotoryukaricalisiyor = 0;
bool devmotorasagicalisiyor = 0;
bool asagivalfcalisiyor = 0;
bool yukarivalfcalisiyor = 0;
bool devyukarivalfcalisiyor = 0;
bool devasagivalfcalisiyor = 0;
bool basgondercalisyukari = 0;
bool basgondercalisasagi = 0;
bool demoCalismaSayisiYar = 0;
bool CalismaSayisiYukari = 0;
bool CalismaSayisiAsagi = 0;
bool calismaSayisiYar = 0;
bool makineStop = 0;
bool kapi1prudhome = 0; bool kapi1butonkontrol = 0; bool kapi1pizzato = 0;
bool kapi2prudhome = 0; bool kapi2butonkontrol = 0; bool kapi2pizzato = 0;
bool kapiTablaprudhome = 0; bool kapiTablabutonkontrol = 0; bool kapiTablapizzato = 0;
bool kapiTablaAcKonumKat1 = 0; bool kapiTablaAcKonumKat2 = 0;
bool startBasili = 0;
bool maksimumcalismahatasi = 0;
bool acilstophatasi = 0;
bool emniyetCercevesihatasi = 0;
bool stopVar = 0;
bool kapiSivicVar = 0;
bool motorcalisiyor = 0;
bool hataVar = 0;
bool makineCalisiyor = 0;
bool cerceveVar = 0;
bool demoYukariCalis = 0;
bool demoAsagiCalis = 0;
bool demoDevYukari = 0;
bool demoDevAsagi = 0;
bool kapiactablaesp1 = 0;
bool kapiactablaesp2 = 0;
bool basinchatasi = 0;
bool katkapisivicihatasi = 0;
bool tablakapisivicihatasi = 0;
bool cercevesasagicalisma = 0;
bool HataMakineCalisiyorkapi = 0;
bool HataMakineCalisiyortabla = 0;

//Menü için text değişkenleri
char *mainText;
char *mainText2;
char *menuyeGirildiText;
char *ayarlarText;
char *hataKayitListText;
char *birHataKoduText;
char *ikiHataKoduText;
char *ucHataKoduText;
char *dortHataKoduText;
char *besHataKoduText;
char *altiHataKoduText;
char *yediHataKoduText;
char *sekizHataKoduText;
char *dokuzHataKoduText;
char *onHataKoduText;
char *silmekIcinText;
char *calismaSekliText;
char *devirmeYuruyusText;
char *bastikcaCalisanText;
char *basGonderText;
char *emniyetCercevesiText;
char *pasifText;
char *aktifText;
char *ondSafetyText;
char *yavaslamaLimitText;
char *altLimitText;
char *basincSalteriText;
char *kapiSecimleriText;
char *katKapisiAktifText;
char *tablaKapiAktifText;
char *katArtiTablaAktifText;
char *kapiAcmaTipiText;
char *kapiButonuESPText;
char *katButonuEXTText;
char *birKatKapiTipiText;
char *prudhomeText;
char *butonKontrolluText;
char *pizzattoText;
char *birinciKapiAcSuresiText;
char *kacSaniyeText;
char *ikinciKatKapiTipiText;
char *ikinciKapiAcSuresiText;
char *tablaKapiTipiText;
char *tablaKapiAcKonumText;
char *birinciKattaAcText;
char *ikinciKattaAcText;
char *birVeIkinciKattaAcText;
char *tablaKapiAcSureText;
char *yukariYavaslamaLimitiText;
char *devirmeYuruyusMenuText;
char *devirmeAktifText;
char *yuruyusAktifText;
char *devirmeYukariText;
char *yuruyusIleriText;
char *devirmeAsagiSivicText;
char *yuruyusGeriSivicText;
char *yuruyusSecildiText;
char *devirmeSilindirTipiText;
char *tekTesirText;
char *ciftTesirText;
char *platformSilindirTipiText;
char *asagiValfSureText;
char *devirmeYukariValfSureText;
char *ileriValfSureText;
char *devirmeAsagiValfSureText;
char *geriValfSureText;
char *calismaSuresiText;
char *buzzerText;
char *demoModText;
char *calismaSayisiText;
char *enterlaSifirlaText;
char *dilSecimText;
char *secilenDilText;
char *menudenCikisText;
char *enteraBasinizText;
char *hataKoduText;

char* copyText(const char* text) {
    char* result = (char*)malloc(strlen(text) + 1);
    if (result != NULL) {
        strcpy(result, text);
    }
    return result;
}

char* copyTextNormal(const char* text) {
    size_t textLength = strlen(text);
    char* result = (char*)malloc(textLength + 17);
    if (result != NULL) {
        strcpy(result, text);
        if (textLength < 16) {
            for (size_t i = textLength; i < 16; i++) {
                result[i] = ' ';
            }
            result[16] = '\0';
        }
    }
    return result;
}

void printTemplate(int type, int page) {
	HAL_Delay(200);
	lcd_clear();
	if(type == 1 && page == 0) {
		lcd_print(1, 1, "ID: ");
		lcd_print(2, 3, "0");
		lcd_print(2, 4, "1");
		lcd_print(2, 5, "2");
		lcd_print(2, 6, "3");
		lcd_print(2, 7, "4");
		lcd_print(2, 10, "5");
		lcd_print(2, 11, "6");
		lcd_print(2, 12, "7");
		lcd_print(2, 13, "8");
		lcd_print(2, 14, "9");
		lcd_print(1, 5, machineID);
		lcd_gotoxy(2, 3);
	} else if(type == 2) {
		if(page == 1) {
			lcd_clear();
			HAL_Delay(100);
			lcd_print(1, 1, "SSID: ");
			lcd_print(1, 7, wifiSSID);
			lcd_print(2, 1, "abcdefghijklmnop");
		} else if(page == 2) {
			lcd_clear();
			HAL_Delay(100);
			lcd_print(1, 1, "SSID: ");
			lcd_print(1, 7, wifiSSID);
			lcd_print(2, 1, "qrstuvwxyzABCDEF");
		} else if(page == 3) {
			lcd_clear();
			HAL_Delay(100);
			lcd_print(1, 1, "SSID: ");
			lcd_print(1, 7, wifiSSID);
			lcd_print(2, 1, "GHIJKLMNOPQRSTUV");
		} else if(page == 4) {
			lcd_clear();
			HAL_Delay(100);
			lcd_print(1, 1, "SSID: ");
			lcd_print(1, 7, wifiSSID);
			lcd_print(2, 1, "WXYZ0123456789!@");
		} else if(page == 5) {
			lcd_clear();
			HAL_Delay(100);
			lcd_print(1, 1, "SSID: ");
			lcd_print(1, 7, wifiSSID);
			lcd_print(2, 1, "#$%^&*()-_+=<>? ");
		}
	} else if(type == 3) {
		if(page == 1) {
			lcd_clear();
			HAL_Delay(100);
			lcd_print(1, 1, "PASS: ");
			lcd_print(1, 7, wifiPass);
			lcd_print(2, 1, "abcdefghijklmnop");
		} else if(page == 2) {
			lcd_clear();
			HAL_Delay(100);
			lcd_print(1, 1, "PASS: ");
			lcd_print(1, 7, wifiPass);
			lcd_print(2, 1, "qrstuvwxyzABCDEF");
		} else if(page == 3) {
			lcd_clear();
			HAL_Delay(100);
			lcd_print(1, 1, "PASS: ");
			lcd_print(1, 7, wifiPass);
			lcd_print(2, 1, "GHIJKLMNOPQRSTUV");
		} else if(page == 4) {
			lcd_clear();
			HAL_Delay(100);
			lcd_print(1, 1, "PASS: ");
			lcd_print(1, 7, wifiPass);
			lcd_print(2, 1, "WXYZ0123456789!@");
		} else if(page == 5) {
			lcd_clear();
			HAL_Delay(100);
			lcd_print(1, 1, "PASS: ");
			lcd_print(1, 7, wifiPass);
			lcd_print(2, 1, "#$%^&*()-_+=<>? ");
		}
	}
}

char getCharFromCursorPosition(int cursorPosition) {
    return charactersArray[cursorPosition];
}

void writeToEEPROM(int state) {
	if(state == 0) {
		memset(&eepromData[ssidStartPos], 0, 20);
		strncpy((char *)&eepromData[ssidStartPos], wifiSSID, 20);
	} else {
		memset(&eepromData[passStartPos], 0, 20);
		strncpy((char *)&eepromData[passStartPos], wifiPass, 20);
	}
}

void readFromEEPROM(int state) {
	if(state == 0) {
		strncpy(wifiSSID, (char *)&eepromData[ssidStartPos], 20);
		wifiSSID[20] = '\0';
	} else {
		strncpy(wifiPass, (char *)&eepromData[passStartPos], 20);
		wifiPass[20] = '\0';
	}
}

void takeMachineID(int state) {
	mainSection:
	lcd_cursor(1);

    int cursorPosition = 3;
    int machineIDLoc = 0;
    int writeLoc = 5;

    if(state == 0) {
    	memset(machineID, 0, sizeof(machineID));
    }
    HAL_Delay(100);

    printTemplate(1, 0);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
        	lcd_cursor(0);

        	if(machineID[11] == '\0') {
        		lcd_clear();
        		lcd_print(1, 1, " ID 12 KARAKTER ");
        		lcd_print(2, 1, " OLMAK ZORUNDA! ");
        		HAL_Delay(1200);
        		goto mainSection;
        	}

        	/*if(checkMachineID(&huart1, machineID) != 1) {
        		lcd_clear();
        		lcd_print(1, 1, "BU ID ILE MAKINE");
        		lcd_print(2, 1, "OLUSTURAMAZSINIZ");
        		HAL_Delay(1200);
        		goto mainSection;
        	} else {
        		eepromData[49] = 1;
        	}*/

        	memcpy(&eepromData[idStartPos], machineID, 12);
        	HAL_Delay(200);

        	HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
        	HAL_Delay(500);

            break;
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
        	if(cursorPosition == 7) {
        		cursorPosition = 10;
        	} else if (cursorPosition == 14) {
                cursorPosition = 3;
            } else {
            	cursorPosition++;
            }

        	HAL_Delay(350);
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
            if (cursorPosition == 3) {
                cursorPosition = 14;
            } else if(cursorPosition == 10) {
            	cursorPosition = 7;
            } else {
            	cursorPosition--;
            }

            HAL_Delay(350);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
        	if(cursorPosition == 3) {
        		machineID[machineIDLoc] = '0';
        	} else if(cursorPosition == 4) {
        		machineID[machineIDLoc] = '1';
        	} else if(cursorPosition == 5) {
        		machineID[machineIDLoc] = '2';
        	} else if(cursorPosition == 6) {
        		machineID[machineIDLoc] = '3';
        	} else if(cursorPosition == 7) {
        		machineID[machineIDLoc] = '4';
        	} else if(cursorPosition == 10) {
        		machineID[machineIDLoc] = '5';
        	} else if(cursorPosition == 11) {
        		machineID[machineIDLoc] = '6';
        	} else if(cursorPosition == 12) {
        		machineID[machineIDLoc] = '7';
        	} else if(cursorPosition == 13) {
        		machineID[machineIDLoc] = '8';
        	} else if(cursorPosition == 14) {
        		machineID[machineIDLoc] = '9';
        	}

        	lcd_print_char(1, writeLoc, machineID[machineIDLoc]);

        	writeLoc++;
        	machineIDLoc++;

        	HAL_Delay(450);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
            if(strlen(machineID) >= 1) {

                machineID[machineIDLoc] = '\0';

                lcd_delete_char(1, 4+machineIDLoc);
                HAL_Delay(50);

                if(writeLoc > 5) {
                	writeLoc--;
                } else if(writeLoc < 5) {
                	writeLoc = 5;
                }

                if(machineIDLoc > 0) {
                	machineIDLoc--;
                } else if(machineIDLoc < 0) {
                	machineIDLoc = 0;
                }
            }

            HAL_Delay(350);
        }

        lcd_gotoxy(2, cursorPosition);
    }
}

void takeWifiSSID(int state) {
	mainSSIDSection:
    lcd_cursor(1);

    if(state == 0) {
    	memset(wifiSSID, 0, sizeof(wifiSSID));
    }

    int realCharPos = 1;
    cursorPosition = 1;
    page = 1;
    int wifiNameLoc = 0;
    int writeLoc = 7;

    printTemplate(2, 1);

    while (1) {
        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
            lcd_cursor(0);

            if(strlen(wifiSSID) > 20) {
                lcd_clear();
                lcd_print(1, 1, " 20 KARAKTERDEN ");
                lcd_print(2, 1, "FAZLA SSID OLMAZ");
                HAL_Delay(1200);
                goto mainSSIDSection;
            }

            memcpy(&eepromData[ssidStartPos], (uint8_t *)wifiSSID, strlen(wifiSSID));

            HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
            HAL_Delay(500);

            break;
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
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

            HAL_Delay(250);
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
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

            HAL_Delay(250);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
            wifiSSID[wifiNameLoc] = getCharFromCursorPosition(realCharPos - 1);

            lcd_print_char(1, writeLoc, wifiSSID[wifiNameLoc]);

            writeLoc++;
            wifiNameLoc++;

            HAL_Delay(250);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
        	if(strlen(wifiSSID) >= 1) {
        		wifiSSID[wifiNameLoc] = '\0';

        		lcd_delete_char(1, 6+wifiNameLoc);
        		HAL_Delay(50);
        		if(writeLoc > 7) {
        			writeLoc--;
        		} else if(writeLoc < 7) {
        			writeLoc = 7;
        		}

        		if(wifiNameLoc > 0) {
        			wifiNameLoc--;
        		} else if(wifiNameLoc < 0) {
        			wifiNameLoc = 0;
        		}
        	}

        	HAL_Delay(250);
        }

        lcd_gotoxy(2, cursorPosition);
    }
}

void takeWifiPass(int state) {
	mainPASSSection:
    lcd_cursor(1);

    if(state == 0) {
    	memset(wifiPass, 0, sizeof(wifiPass));
    }

    int realCharPos = 1;
    cursorPosition = 1;
    page = 1;
    int wifiPassLoc = 0;
    int writeLoc = 7;

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
            }

            memcpy(&eepromData[passStartPos], (uint8_t *)wifiPass, strlen(wifiPass));

            HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
            HAL_Delay(500);

            break;
        }

        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
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

            HAL_Delay(250);
        }

        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
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

            HAL_Delay(250);
        }

        if (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) {
        	wifiPass[wifiPassLoc] = getCharFromCursorPosition(realCharPos - 1);

            lcd_print_char(1, writeLoc, wifiPass[wifiPassLoc]);

            writeLoc++;
            wifiPassLoc++;

            HAL_Delay(250);
        }

        if(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) {
            if(strlen(wifiPass) >= 1) {
            	wifiPass[wifiPassLoc] = '\0';

            	lcd_delete_char(1, 6+wifiPassLoc);
            	HAL_Delay(50);

            	if(writeLoc > 7) {
            		writeLoc--;
            	} else if(writeLoc < 7) {
            		writeLoc = 7;
            	}

            	if(wifiPassLoc > 0) {
            		wifiPassLoc--;
            	} else if(wifiPassLoc < 0) {
            		wifiPassLoc = 0;
            	}
            }

            HAL_Delay(250);
        }

        lcd_gotoxy(2, cursorPosition);
    }
}

int checkSlideVal(int state) {
	if(state == 0) { //ssid (33)
		if(HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
			return 34;
		}

		if(HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
			return 32;
		}
	} else { //pass (34)
		if(HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
			return 35;
		}

		if(HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
			return 33;
		}
	}
	return 0;
}

void slideText(const char* text, int startPos, int startLine, int state) {
	uint8_t uzunluk = strlen(text);
	int mainLoopVal = 1;

	while(mainLoopVal == 1) {
		if(checkSlideVal(state) > 0) {
			menuSayac = checkSlideVal(state);
			break;
		}

		for(int z=0; z < uzunluk; z++) {
			if(checkSlideVal(state) > 0) {
				menuSayac = checkSlideVal(state);
				mainLoopVal = 0;
				break;
			}
			for(int i=startPos + z; i < uzunluk + startPos; i++) {
				if(checkSlideVal(state) > 0) {
					menuSayac = checkSlideVal(state);
					z = uzunluk;
					mainLoopVal = 0;
					break;
				}
				lcd_print_char(startLine, i-z, text[i-startPos]);
				HAL_Delay(30);
			}

			for (int j = uzunluk - 1; j >= uzunluk - z; j--) {
				if(checkSlideVal(state) > 0) {
					menuSayac = checkSlideVal(state);
					z = uzunluk;
					mainLoopVal = 0;
					break;
				}
			     if(j >= startPos) {
			    	 lcd_print_char(startLine, j, ' ');
			    	 HAL_Delay(30);
			     }
			}
		}
	}
}

void menu() {
	if ((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin) == 1) && (butonKontrol == 0)) {
		menuSayac = menuSayac+1;
		if (menuSayac == 36) {    //MENÜ BÜYÜDÜKÇE DUZENLE
			menuSayac = 1;
		}

		if((menuSayac == 18) && (devirmeYuruyusSecim == 0)) {
			menuSayac = 21;
		}

		if((menuSayac == 8) && (kapiSecimleri == 0)) {
			menuSayac = 16;
		}

		if ((menuSayac == 13) && (kapiSecimleri == 1)) {			// kapi kat sivici aktif ise tabla kapı hariç ayarlar gösterilir.
			menuSayac = 16;
		}

		if((menuSayac == 9) && (kapiSecimleri == 2)) {			// tabla aktif ise kat harici kapılar gösterilir.
			menuSayac = 13;
		}

		if((menuSayac == 10) && ((kapi1Tip == 1) || (kapi1Tip == 2))) {
			menuSayac = 11;
		}

		if((menuSayac == 12) && ((kapi2Tip == 1)  ||  (kapi2Tip == 2)) && (kapiSecimleri == 1)) {
			menuSayac = 16;
		}
		if((menuSayac == 12) && ((kapi2Tip == 1)  ||  (kapi2Tip == 2)) && (kapiSecimleri == 3)) {
			menuSayac = 13;
		}

		if((menuSayac == 15) && (kapitablaTip == 1)) {
			menuSayac = 16;
		}

		if((menuSayac == 24) && (devirmeYuruyusSecim == 0)) {
			menuSayac = 26;
		}

		bekle();
	}

	if ((HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port,butonGeriIn_Pin) == 1) && (butonKontrol == 0)) {
		if (menuSayac <= 1) {
			menuSayac = 36;     //MENÜ BÜYÜDÜKÇE DUZENLE
		}

		menuSayac = menuSayac - 1;

		if((menuSayac == 20) && (devirmeYuruyusSecim == 0)) {
			menuSayac = 17;
		}

		if((menuSayac == 15) && (kapiSecimleri == 0)) {
			menuSayac = 7;
		}

		if((menuSayac == 15) && (kapiSecimleri == 1)) {
			menuSayac = 12;
		}

		if((menuSayac == 12) && (kapiSecimleri == 2)) {
			menuSayac = 8;
		}

		if((menuSayac == 10) && ((kapi1Tip == 1) || (kapi1Tip == 2))) {
			menuSayac = 9;
		}

		if((menuSayac == 12) && ((kapi2Tip == 1) || (kapi2Tip == 2))) {
			menuSayac = 11;
		}

		if((menuSayac == 15) && (kapitablaTip == 1)) {
			menuSayac = 14;
		}

		if((menuSayac == 25) && (devirmeYuruyusSecim == 0)) {
			menuSayac = 23;
		}

		bekle();
	}

	if (menuSayac == 0) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "MENUYE  GiRDiNiZ");
			lcd_print(2, 1, "    AYARLAR     ");
		} else if(dilSecim  ==  1) {
			lcd_print(1, 1, "ENTERED THE MENU");
			lcd_print(2, 1, "    SETTINGS    ");
		}
	}

	if (menuSayac == 1) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "HATA KAYIT LiST.");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "ERROR SAVE LiST.");
		}

		if(hataGostermeSirasi == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "1.Hata Kodu: ");

			} else if(dilSecim == 1) {
				lcd_print(2, 1, "1.Error Code:");
			}
			lcd_print(2, 15, "   ");
			itoa(hataKayit1, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "2.Hata Kodu: ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "2.Error Code:");
			}
			lcd_print(2, 15, "  ");
			itoa(hataKayit2, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 2) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "3.Hata Kodu: ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "3.Error Code:");
			}
			lcd_print(2, 15, "  ");
			itoa(hataKayit3, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 3) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "4.Hata Kodu: ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "4.Error Code:");
			}
			lcd_print(2, 15, "  ");
			itoa(hataKayit4, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 4) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "5.Hata Kodu: ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "5.Error Code:");
			}
			lcd_print(2, 15, "  ");
			itoa(hataKayit5, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 5) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "6.Hata Kodu: ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "6.Error Code:");
			}
			lcd_print(2, 15, "  ");
			itoa(hataKayit6, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 6) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "7.Hata Kodu: ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "7.Error Code:");
			}
			lcd_print(2, 15, "  ");
			itoa(hataKayit7, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 7) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "8.Hata Kodu: ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "8.Error Code:");
			}
			lcd_print(2, 15, "  ");
			itoa(hataKayit8, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 8) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "9.Hata Kodu: ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "9.Error Code:");
			}
			lcd_print(2, 15, "  ");
			itoa(hataKayit9, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 9) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "10.Hata Kodu: ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "10.Error Code:");
			}
			lcd_print(2, 16, " ");
			itoa(hataKayit10, snum, 10);
			lcd_print(2, 15, snum);
		}

		if(hataGostermeSirasi == 10) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Silmek icin ent.");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Del. press enter");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0) && (devirmeYuruyusSecim == 0)) {
			hataGostermeSirasi = hataGostermeSirasi + 1;

			if(hataGostermeSirasi > 10) {
				hataGostermeSirasi = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0) && (devirmeYuruyusSecim == 0)) {
			hataGostermeSirasi = hataGostermeSirasi - 1;

	    	if(hataGostermeSirasi > 11) {
	    		hataGostermeSirasi = 10;
	    	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0) &&  hataGostermeSirasi == 10) {
			hataKayit1 = 0; eepromData[37] = 0;
			hataKayit2 = 0; eepromData[38] = 0;
			hataKayit3 = 0; eepromData[39] = 0;
			hataKayit4 = 0; eepromData[40] = 0;
			hataKayit5 = 0; eepromData[41] = 0;
			hataKayit6 = 0; eepromData[42] = 0;
			hataKayit7 = 0; eepromData[43] = 0;
			hataKayit8 = 0; eepromData[44] = 0;
			hataKayit9 = 0; eepromData[45] = 0;
			hataKayit10 = 0; eepromData[46] = 0;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 2) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "CALISMA SEKLi   ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "WORKNG PRINCIPLE");
		}

		if((devirmeYuruyusSecim == 1) || (devirmeYuruyusSecim == 2)) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Dvr Yrys secildi");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Tppng Mobil slct");
			}
		}

		if((calismaSekli == 0) && (devirmeYuruyusSecim == 0)) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Bastikca cal.  ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Deadman Control");
			}
		}

		if((calismaSekli == 1) && (devirmeYuruyusSecim == 0)) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Bas gonder     ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Call & Send    ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0) && (devirmeYuruyusSecim == 0)) {
			calismaSekli = calismaSekli + 1;

			if(calismaSekli > 1) {
				calismaSekli = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0) && (devirmeYuruyusSecim == 0)) {
			calismaSekli = calismaSekli - 1;

	    	if(calismaSekli > 0) {
	    		calismaSekli = 1;
	    	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[1] = calismaSekli;

			if(calismaSekli == 1) {
				altLimit = 1;
				eepromData[5] = altLimit;
			}
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 3) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "EMNIYET CER.    ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "SAFETY FRAME    ");
		}

		if(emniyetCercevesi == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Passive         ");
			}
		} else if(emniyetCercevesi == 1) {
			lcd_print(2, 1, "OND Safety     ");
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			emniyetCercevesi = emniyetCercevesi + 1;

			if(emniyetCercevesi > 1) {
				emniyetCercevesi = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			emniyetCercevesi = emniyetCercevesi - 1;
		   	if(emniyetCercevesi > 0) {
		   		emniyetCercevesi = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)){
			eepromData[2] = emniyetCercevesi;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 4) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "YAVASLAMA LIMIT ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "SLOW DOWN LIMIT ");
		}

		if(yavaslamaLimit == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Passive         ");
			}
		} else if(yavaslamaLimit == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Aktif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Active          ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			yavaslamaLimit = yavaslamaLimit + 1;

			if(yavaslamaLimit > 1){
				yavaslamaLimit = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			yavaslamaLimit = yavaslamaLimit - 1;

		   	if(yavaslamaLimit > 0){
		   		yavaslamaLimit = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[4] = yavaslamaLimit;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 5) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "ALT LIMIT       ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "DOWN LIMIT      ");
		}

		if(altLimit == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Passive         ");
			}
		} else if(altLimit == 1) {
			if(dilSecim == 0){
				lcd_print(2, 1, "Aktif           ");
			} else if(dilSecim == 1){
				lcd_print(2, 1, "Active          ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0) && (calismaSekli == 0)) {
			altLimit = altLimit + 1;

			if(altLimit > 1) {
				altLimit = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0) && calismaSekli == 0) {
			altLimit = altLimit - 1;

		   	if(altLimit > 0){
		   		altLimit = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[5] = altLimit;

			if(altLimit == 0 && (kapiTablaAcKonum == 0 || kapiTablaAcKonum == 2)) {
				kapiTablaAcKonum = 3;
				eepromData[34] = kapiTablaAcKonum;
			} else if(altLimit == 0) {
				platformSilindirTipi = 0;
				eepromData[19] = platformSilindirTipi;
			}

			hafizaYaz = 1;
		}
	}

	if (menuSayac == 6) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "BASINC SALTERI ");
		} else if(dilSecim == 1){
			lcd_print(1, 1, "PRESSURE SWITCH");
		}
		if(basincSalteri == 0){
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1){
				lcd_print(2, 1, "Passive         ");
			}
		} else if(basincSalteri == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Aktif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Active          ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			basincSalteri = basincSalteri + 1;

			if(basincSalteri > 1){
				basincSalteri = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			basincSalteri = basincSalteri - 1;

		   	if(basincSalteri > 0){
		   		basincSalteri = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[6] = basincSalteri;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 7) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "KAPI SECIMLERI     ");
		} else if(dilSecim == 1){
			lcd_print(1, 1, "DOOR SELECTION     ");
		}

		if(kapiSecimleri == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1){
				lcd_print(2, 1, "Passive         ");
			}
		} else if(kapiSecimleri == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Kat kapisi aktif");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Floor door act  ");
			}
		} else if(kapiSecimleri == 2){
			if(dilSecim == 0) {
				lcd_print(2, 1, "Tabla kapi aktif");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Pltfrm door act ");
			}
		} else if(kapiSecimleri == 3){
			if(dilSecim == 0) {
				lcd_print(2, 1, "Kat + Tabl aktif");
			} else if(dilSecim == 1){
				lcd_print(2, 1, "Flr + Plrfrm act");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			kapiSecimleri = kapiSecimleri + 1;

			if(kapiSecimleri > 3){
				kapiSecimleri = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			kapiSecimleri = kapiSecimleri - 1;

		   	if(kapiSecimleri > 4){
		   		kapiSecimleri = 3;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[7] = kapiSecimleri;

			if(kapiSecimleri >= 1) {
				altLimit = 1;
				eepromData[5] = altLimit;
			}
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 8) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "KAPI ACMA TIPI  ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "OPEN DOOR TYPE  ");
		}

		if(kapiAcTipi == 0){
			if(dilSecim == 0) {
				lcd_print(2, 1, "Kapi butonu ESP");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Door Button ESP");
			}
		} else if(kapiAcTipi == 1){
			if(dilSecim == 0){
				lcd_print(2, 1, "Kat butonu EXT  ");
			} else if(dilSecim == 1){
				lcd_print(2, 1, "Floor button EXT");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			kapiAcTipi = kapiAcTipi + 1;

			if(kapiAcTipi > 1){
				kapiAcTipi = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			kapiAcTipi = kapiAcTipi - 1;

		   	if(kapiAcTipi > 0){
		   		kapiAcTipi = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[36] = kapiAcTipi;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 9) {
		if(dilSecim == 0){
			lcd_print(1, 1, "1.KAT KAPI TiPi ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "1.FLOOR DOOR TYP");
		}

		if(kapi1Tip == 0) {
			lcd_print(2, 1, "Prudhome        ");
		} else if(kapi1Tip == 1) {
			if(dilSecim == 0){
				lcd_print(2, 1, "Buton kontrollu");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Button cntrolled");
			}
		} else if(kapi1Tip == 2) {
			lcd_print(2, 1, "Pizzato        ");
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			kapi1Tip = kapi1Tip + 1;

			if(kapi1Tip > 2){
				kapi1Tip = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			kapi1Tip = kapi1Tip - 1;

		   	if(kapi1Tip > 3){
		   		kapi1Tip = 2;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[8] = kapi1Tip;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 10) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "1.KAPI AC SURESi");
			lcd_print(2, 1, "Kac Saniye     ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "1.FLR DR OPN TMR");
			lcd_print(2, 1, "Seconds        ");
		}

		itoa(kapi1AcSure, snum, 10);
		lcd_print(2,16,snum);

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0) && (kapi1Tip == 0)) {
			kapi1AcSure = kapi1AcSure + 1;

			if(kapi1AcSure > 5){
				kapi1AcSure = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0) && (kapi1Tip == 0)) {
			kapi1AcSure = kapi1AcSure - 1;

		   	if(kapi1AcSure > 6){
		   		kapi1AcSure = 5;
		   	}
			bekle();
		}
		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[9] = kapi1AcSure;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 11) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "2.KAT KAPI TiPi ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "2.FLOOR DOOR TYP");
		}

		if(kapi2Tip == 0) {
			lcd_print(2, 1, "Prudhome        ");
		} else if(kapi2Tip == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Buton kontrollu");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Button cntrolled");
			}
		} else if(kapi2Tip == 2) {
			lcd_print(2, 1, "Pizzato        ");
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			kapi2Tip = kapi2Tip + 1;

			if(kapi2Tip > 2){
				kapi2Tip = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			kapi2Tip = kapi2Tip - 1;

		   	if(kapi2Tip > 3){
		   		kapi2Tip = 2;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[10] = kapi2Tip;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 12) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "2.KAPI AC SURESi");
			lcd_print(2, 1, "Kac Saniye     ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "2.FLR DR OPN TMR");
			lcd_print(2, 1, "Seconds        ");
		}

		itoa(kapi2AcSure, snum, 10);
		lcd_print(2,16,snum);

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0) && (kapi2Tip == 0)) {
			kapi2AcSure = kapi2AcSure + 1;

			if(kapi2AcSure > 5) {
				kapi2AcSure = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0) && (kapi2Tip == 0)) {
			kapi2AcSure = kapi2AcSure - 1;

		   	if(kapi2AcSure > 6) {
		   		kapi2AcSure = 5;
		   	}
			bekle();
		}
		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[11] = kapi2AcSure;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 13) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "TABLA KAPI TiPi ");
		} else if(dilSecim == 1){
			lcd_print(1, 1, "PLTFRM DOOR TYPE");
		}

		if(kapitablaTip == 0) {
			lcd_print(2, 1, "Prudhome        ");
		} else if(kapitablaTip == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Buton kontrollu");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Button cntrolled");
			}
		} else if(kapitablaTip == 2) {
			lcd_print(2, 1, "Pizzato        ");
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			kapitablaTip = kapitablaTip + 1;

			if(kapitablaTip > 2) {
				kapitablaTip = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			kapitablaTip = kapitablaTip - 1;

		   	if(kapitablaTip > 3) {
		   		kapitablaTip = 2;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[12] = kapitablaTip;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 14) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "TBL KPI AC KONUM");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "PLTFRM DR OP LOC");
		}

		if(kapiTablaAcKonum == 0) {
			if(dilSecim == 0){
				lcd_print(2, 1, "1. Katta ac    ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "1. Floor open  ");
			}
		} else if(kapiTablaAcKonum == 1) {
			if(dilSecim == 0){
				lcd_print(2, 1, "2. Katta ac    ");
			}
			if(dilSecim == 1){
				lcd_print(2, 1, "2. Floor open  ");
			}
		} else if(kapiTablaAcKonum == 2) {
			if(dilSecim == 0){
				lcd_print(2, 1, "1.+2. Katta ac  ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "1.+2. Floor open");
			}
		} else if(kapiTablaAcKonum == 3) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			}
			if(dilSecim == 1) {
				lcd_print(2, 1, "Passive         ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			kapiTablaAcKonum = kapiTablaAcKonum + 1;

			if(kapiTablaAcKonum > 2){
				kapiTablaAcKonum = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			kapiTablaAcKonum = kapiTablaAcKonum - 1;

		   	if(kapiTablaAcKonum > 3){
		   		kapiTablaAcKonum = 2;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[34] = kapiTablaAcKonum;

			if(kapiTablaAcKonum == 0 || kapiTablaAcKonum == 2){
				altLimit = 1;
				eepromData[5] = altLimit;
			}

			hafizaYaz = 1;
		}
	}

	if (menuSayac == 15) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "TABLA KP AC SURE");
			lcd_print(2, 1, "Kac Saniye     ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "PLTFM DR OPN TMR");
			lcd_print(2, 1, "Seconds        ");
		}

		itoa(kapiTablaAcSure, snum, 10);
		lcd_print(2,16,snum);

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0) && (kapitablaTip == 0)) {
			kapiTablaAcSure = kapiTablaAcSure + 1;

			if(kapiTablaAcSure > 5){
				kapiTablaAcSure = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0) && (kapitablaTip == 0)) {
			kapiTablaAcSure = kapiTablaAcSure - 1;

		   	if(kapiTablaAcSure > 6){
		   		kapiTablaAcSure = 5;
		   	}

			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[13] = kapiTablaAcSure;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 16) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "YUKARI YAVAS LMT");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "UPPR SLW DWN LMT");
		}

		if(yukariYavasLimit == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Passive         ");
			}
		} else if(yukariYavasLimit == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Aktif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Active          ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			yukariYavasLimit = yukariYavasLimit + 1;

			if(yukariYavasLimit > 1){
				yukariYavasLimit = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			yukariYavasLimit = yukariYavasLimit - 1;

		   	if(yukariYavasLimit > 0){
		   		yukariYavasLimit = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[14] = yukariYavasLimit;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 17) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "DEVIRME-YURUYUS ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "TPPNG-MOBIL PLT ");
		}

		if(devirmeYuruyusSecim == 2) {
			if(dilSecim == 0){
				lcd_print(2, 1, "Devirme aktif  ");
			} else if(dilSecim == 1){
				lcd_print(2, 1, "Tipping active ");
			}
		} else if(devirmeYuruyusSecim == 1) {
			if(dilSecim == 0){
				lcd_print(2, 1, "Yuruyus aktif  ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Drive active   ");
			}
		} else if(devirmeYuruyusSecim == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Passive         ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			devirmeYuruyusSecim = devirmeYuruyusSecim + 1;

			if(devirmeYuruyusSecim > 2){
				devirmeYuruyusSecim = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			devirmeYuruyusSecim = devirmeYuruyusSecim-1;

		   	if(devirmeYuruyusSecim>3){
		   		devirmeYuruyusSecim = 2;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[15] = devirmeYuruyusSecim;

			if(devirmeYuruyusSecim == 2 || devirmeYuruyusSecim == 1) {
				calismaSekli = 0;
				eepromData[1] = calismaSekli;
			}

			if(devirmeYuruyusSecim == 1) {
				devirmeSilindirTipi = 1;
				eepromData[18] = devirmeSilindirTipi;
			}
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 18) {
		if(devirmeYuruyusSecim == 2) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "DEVRM YUKARI SVC");
			} else if(dilSecim == 1) {
				lcd_print(1, 1, "TPPNG SWTCH/OPN");
			}
		} else if(devirmeYuruyusSecim == 1) {
			if(dilSecim == 0){
				lcd_print(1, 1, "YURUYUS ILER SVC");
			}
			if(dilSecim == 1){
				lcd_print(1, 1, "DRVE FRWRD SWTCH");
			}
		}

		if(devirmeYukariIleriLimit == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1){
				lcd_print(2, 1, "Passive         ");
			}
		} else if(devirmeYukariIleriLimit == 1){
			if(dilSecim == 0){
				lcd_print(2, 1, "Aktif           ");
			} else if(dilSecim == 1){
				lcd_print(2, 1, "Active          ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			devirmeYukariIleriLimit = devirmeYukariIleriLimit + 1;

			if(devirmeYukariIleriLimit > 1){
				devirmeYukariIleriLimit = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			devirmeYukariIleriLimit = devirmeYukariIleriLimit - 1;

		   	if(devirmeYukariIleriLimit > 0){
		   		devirmeYukariIleriLimit = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[16] = devirmeYukariIleriLimit;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 19) {
		if(devirmeYuruyusSecim == 2) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "DEVIRM ASAGI SVC");
			} else if(dilSecim == 1) {
				lcd_print(1, 1, "TPPNG SWTCH/CLSD");
			}
		} else if(devirmeYuruyusSecim == 1) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "YURUYUS GERI SVC");
			}
			if(dilSecim == 1) {
				lcd_print(1, 1, "DRIVE BACK SWTCH");
			}
		}

		if(devirmeAsagiGeriLimit == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Passive         ");
			}
		} else if(devirmeAsagiGeriLimit == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Aktif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Active          ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			devirmeAsagiGeriLimit = devirmeAsagiGeriLimit + 1;

			if(devirmeAsagiGeriLimit > 1) {
				devirmeAsagiGeriLimit = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			devirmeAsagiGeriLimit = devirmeAsagiGeriLimit - 1;

		   	if(devirmeAsagiGeriLimit > 0) {
		   		devirmeAsagiGeriLimit = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[17] = devirmeAsagiGeriLimit;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 20){
		if(devirmeYuruyusSecim == 1) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "YURUYUS SECiLDi ");
			} else if(dilSecim == 1) {
				lcd_print(1, 1, "DRIVE SELECTED  ");
			}
		} else if(devirmeYuruyusSecim == 2) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "DEVIRME SLN TIPI");
			} else if(dilSecim == 1) {
				lcd_print(1, 1, "CYLNDR TYP/TIPPD");
			}
		}

		if(devirmeSilindirTipi == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Tek tesir       ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Single acting  ");
			}
		} else if(devirmeSilindirTipi == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Cift tesir      ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Double acting  ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0) && (devirmeYuruyusSecim == 2)) {
			devirmeSilindirTipi = devirmeSilindirTipi + 1;

			if(devirmeSilindirTipi > 1) {
				devirmeSilindirTipi = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0) && (devirmeYuruyusSecim == 2)) {
			devirmeSilindirTipi = devirmeSilindirTipi - 1;

		   	if(devirmeSilindirTipi > 0) {
		   		devirmeSilindirTipi = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[18] = devirmeSilindirTipi;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 21) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "PLATFRM SLN TIPI");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "CYLNDR TYPE/PLT");
		}

		if(platformSilindirTipi == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Tek tesir       ");
			}
			if(dilSecim == 1) {
				lcd_print(2, 1, "Single acting  ");
			}
		} else if(platformSilindirTipi == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Cift tesir      ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Double acting  ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			platformSilindirTipi = platformSilindirTipi + 1;

			if(platformSilindirTipi > 1) {
				platformSilindirTipi = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			platformSilindirTipi = platformSilindirTipi - 1;

		   	if(platformSilindirTipi > 0) {
		   		platformSilindirTipi = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[19] = platformSilindirTipi;

			if(platformSilindirTipi == 1) {
				altLimit = 1;
				eepromData[5] = altLimit;
			}
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 22) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "YUKARI VALF SURE");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "UP VALVE TIMER  ");
		}

		if(yukariValfTmr >= 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Kac Saniye     ");
			} else if(dilSecim == 1){
				lcd_print(2, 1, "Second         ");
			}
		}

		itoa(yukariValfTmr, snum, 10);
		lcd_print(2,16,snum);

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			yukariValfTmr = yukariValfTmr + 1;

			if(yukariValfTmr > 5) {
				yukariValfTmr = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			yukariValfTmr = yukariValfTmr - 1;

		   	if(yukariValfTmr > 6) {
		   		yukariValfTmr = 5;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[20] = yukariValfTmr;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 23) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "ASAGI VALF SURE ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "DOWN VALVE TIMER");
		}

		if(asagiValfTmr >= 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Kac Saniye     ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Second         ");
			}
		}

		itoa(asagiValfTmr, snum, 10);
		lcd_print(2,16,snum);

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			asagiValfTmr = asagiValfTmr + 1;

			if(asagiValfTmr > 5) {
				asagiValfTmr = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			asagiValfTmr = asagiValfTmr - 1;

		   	if(asagiValfTmr > 6) {
		   		asagiValfTmr = 5;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[21] = asagiValfTmr;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 24) {
		if(devirmeYuruyusSecim == 2) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "DVRM YKR VLF SN ");
			} else if(dilSecim == 1) {
				lcd_print(1, 1, "TIPPD UP VLV TMR");
			}
		} else if(devirmeYuruyusSecim == 1) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "iLERi VALF SURE ");
			} else if(dilSecim == 1) {
				lcd_print(1, 1, "FRWD DRV VLV TMR");
			}
		}

		if(devirmeYukariIleriTmr >= 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Kac Saniye     ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Second         ");
			}
		}

		itoa(devirmeYukariIleriTmr, snum, 10);
		lcd_print(2, 16, snum);

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			devirmeYukariIleriTmr = devirmeYukariIleriTmr + 1;

			if(devirmeYukariIleriTmr > 5) {
				devirmeYukariIleriTmr = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			devirmeYukariIleriTmr = devirmeYukariIleriTmr - 1;

		   	if(devirmeYukariIleriTmr > 6) {
		   		devirmeYukariIleriTmr = 5;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[22] = devirmeYukariIleriTmr;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 25) {
		if(devirmeYuruyusSecim == 2) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "DVRM ASG VALF SN");
			} else if(dilSecim == 1) {
				lcd_print(1, 1, "TPPD DWN VLV TMR");
			}
		} else if(devirmeYuruyusSecim == 1) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "GERi VALF SURE  ");
			} else if(dilSecim == 1) {
				lcd_print(1, 1, "REVERSE VLV TMR ");
			}
		}

		if(devirmeAsagiGeriTmr >= 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Kac Saniye     ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Second         ");
			}
		}

		itoa(devirmeAsagiGeriTmr, snum, 10);
		lcd_print(2,16,snum);

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			devirmeAsagiGeriTmr = devirmeAsagiGeriTmr + 1;

			if(devirmeAsagiGeriTmr > 5) {
				devirmeAsagiGeriTmr = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			devirmeAsagiGeriTmr = devirmeAsagiGeriTmr - 1;

		   	if(devirmeAsagiGeriTmr > 6) {
		   		devirmeAsagiGeriTmr = 5;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[23] = devirmeAsagiGeriTmr;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 26) {
		if(dilSecim == 0) {
			lcd_print(1, 1, "CALiSMA SURESi  ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "WORKING TIME    ");
		}

		if(makineCalismaTmr > 99) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Kac Saniye     ");
			}
			if(dilSecim == 1) {
				lcd_print(2, 1, "Second         ");
			}

			itoa(makineCalismaTmr, snum, 10);
			lcd_print(2,14,snum);

		} else if((makineCalismaTmr >= 10) && (makineCalismaTmr <=  99)) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Kac Saniye     ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Second         ");
			}

			itoa(makineCalismaTmr, snum, 10);
			lcd_print(2, 15, snum);
		} else if(makineCalismaTmr <=  9) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Kac Saniye     ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Second         ");
			}

			itoa(makineCalismaTmr, snum, 10);
			lcd_print(2, 16, snum);
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			makineCalismaTmr = makineCalismaTmr + 1;

			if(makineCalismaTmr > 180) {
				makineCalismaTmr = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			makineCalismaTmr = makineCalismaTmr - 1;

		   	if(makineCalismaTmr > 181) {
		   		makineCalismaTmr = 180;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[24] = makineCalismaTmr;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 27) {
		lcd_print(1, 1, "BUZZER          ");

		if(buzzer == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Passive         ");
			}
		} else if(buzzer == 1) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Aktif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Active          ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			buzzer = buzzer + 1;
			if(buzzer > 1){
				buzzer = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			buzzer = buzzer - 1;

		   	if(buzzer > 0){
		   		buzzer = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[25] = buzzer;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 28) {
		calismaSayModu = 0;
		lcd_print(1, 1, "DEMO MODE      ");

		if(demoMode == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Passive         ");
			}
		} else if(demoMode == 1) {
			if(dilSecim == 0){
				lcd_print(2, 1, "Aktif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Active          ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			demoMode = demoMode + 1;

			if(demoMode > 1){
				demoMode = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			demoMode = demoMode - 1;

		   	if(demoMode > 0) {
		   		demoMode = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[26] = demoMode;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 29) {
		if(calismaSayisi1 == 0 && calismaSayisi10 == 0 && calismaSayisi100 == 0 && calismaSayisi1000 == 0 && calismaSayisi10000 == 0) {
			calismaSayisiYar = 0;
		} else {
			calismaSayisiYar = 1;
		}

		if(calismaSayModu == 0) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "Calisma Sayisi  ");
			} else if(dilSecim == 1) {
				lcd_print(1, 1, "Working Cycle   ");
			}

			itoa(calismaSayisi10000, snum, 10);
			lcd_print(2, 12, snum);

			itoa(calismaSayisi1000, snum, 10);
			lcd_print(2, 13, snum);

			itoa(calismaSayisi100, snum, 10);
			lcd_print(2, 14, snum);

			itoa(calismaSayisi10, snum, 10);
			lcd_print(2, 15, snum);

			itoa(calismaSayisi1, snum, 10);
			lcd_print(2, 16, snum);

			lcd_print(2, 1, "           ");
		} else if(calismaSayModu == 1) {
			if(dilSecim == 0) {
				lcd_print(1, 1, "Calisma Sayisi  ");
				lcd_print(2, 1, "Enter'la Sifirla");
			} else if(dilSecim == 1) {
				lcd_print(1, 1, "Working Cycle   ");
				lcd_print(2, 1, "Del. with Enter ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0) && (calismaSayisiYar == 1)) {
			calismaSayModu = calismaSayModu + 1;

			if(calismaSayModu > 1){
				calismaSayModu = 0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0) && (calismaSayisiYar == 1)) {
			calismaSayModu = calismaSayModu - 1;

		   	if(calismaSayModu > 0) {
		   		calismaSayModu = 1;
		   	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[32] = 0;
			eepromData[31] = 0;
			eepromData[30] = 0;
			eepromData[29] = 0;
			eepromData[28] = 0;
			calismaSayisi10000 = 0;
			calismaSayisi1000 = 0;
			calismaSayisi100 = 0;
			calismaSayisi10 = 0;
			calismaSayisi1 = 0;
			calismaSayModu = 0;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 30) {
		calismaSayModu = 0;

		if(dilSecim == 0) {
			lcd_print(1, 1, "DIL SECIMI      ");
			lcd_print(2, 1, "TURKCE          ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, "LANGUAGE SELECT ");
			lcd_print(2, 1, "ENGLISH         ");
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			dilSecim = dilSecim + 1;

			if(dilSecim > 1) {
				dilSecim = 0;
			}

			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			dilSecim = dilSecim - 1;

		   	if(dilSecim > 0) {
		   		dilSecim = 1;
		   	}

			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[33] = dilSecim;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 31) {
		calismaSayModu = 0;
		lcd_print(1, 1, "IoT MODE        ");

		if(iotMode == 0) {
			if(dilSecim == 0) {
				lcd_print(2, 1, "Pasif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Passive         ");
			}
		} else if(iotMode == 1) {
			if(dilSecim == 0){
				lcd_print(2, 1, "Aktif           ");
			} else if(dilSecim == 1) {
				lcd_print(2, 1, "Active          ");
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			iotMode = iotMode + 1;

			if(iotMode > 1) {
				iotMode = 0;
			}

			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			iotMode = iotMode - 1;

		   	if(iotMode > 0) {
		   		iotMode = 1;
		   	}

			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[48] = iotMode;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 32) {
		calismaSayModu = 0;

		lcd_print(1, 1, "MAKINE ID       ");

		lcd_print(2, 1, machineID);
		lcd_print(2, 13, "    ");

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			takeMachineID(0);

			HAL_Delay(50);

			lcd_print(2, 1, machineID);
			lcd_print(2, 13, "    ");

			bekle();
		}
	}

	if (menuSayac == 33) {
		calismaSayModu = 0;

		lcd_print(1, 1, "WIFI SSID       ");
		if(strlen(wifiSSID) <=16) {
			lcd_print(2, 1, wifiSSID);
			lcd_print(2, 1+strlen(wifiSSID), emptyArray);
		} else {
			slideText(wifiSSID, 1, 2, 0);
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			takeWifiSSID(0);

			HAL_Delay(100);

			lcd_print(2, 1, wifiSSID);
			lcd_print(2, 1+strlen(wifiSSID), emptyArray);

			bekle();
		}
	}

	if (menuSayac == 34) {
		calismaSayModu = 0;

		lcd_print(1, 1, "WIFI PASS       ");
		if(strlen(wifiPass) <= 16) {
			lcd_print(2, 1, wifiPass);
			lcd_print(2, 1+strlen(wifiPass), emptyArray);
		} else {
			slideText(wifiPass, 1, 2, 1);
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			takeWifiPass(0);

			HAL_Delay(50);

			lcd_print(2, 1, wifiPass);
			lcd_print(2, 1+strlen(wifiPass), emptyArray);

			bekle();
		}
	}

	if (menuSayac == 35) {
		if(dilSecim == 0) {
			lcd_print(1, 1, " MENUDEN CIKIS  ");
			lcd_print(2, 1, "ENTER'A BASINIZ ");
		} else if(dilSecim == 1) {
			lcd_print(1, 1, " EXIT THE MENU  ");
			lcd_print(2, 1, "PUSH ENTER BUTON");
		}

		if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) {
			menuGiris = 0;

			lcd_clear();
			HAL_Delay(500);
			NVIC_SystemReset();
		}
	}
}

void loadMenuTexts(uint8_t dilSecim) {
	mainText = copyText(mainTextGN);
	mainText2 = copyText(mainText2GN);
	ondSafetyText = copyText(ondSafetyTextGN);
	prudhomeText = copyText(prudhomeTextGN);
	pizzattoText = copyText(pizzattoTextGN);
	buzzerText = copyText(buzzerTextGN);
	demoModText = copyText(demoModTextGN);
	if(dilSecim == 0) {
		menuyeGirildiText = copyText(menuyeGirildiTextTR);
		ayarlarText = copyText(ayarlarTextTR);
		hataKayitListText = copyText(hataKayitListTextTR);
		birHataKoduText = copyText(birHataKoduTextTR);
		ikiHataKoduText = copyText(ikiHataKoduTextTR);
		ucHataKoduText = copyText(ucHataKoduTextTR);
		dortHataKoduText = copyText(dortHataKoduTextTR);
		besHataKoduText = copyText(besHataKoduTextTR);
		altiHataKoduText = copyText(altiHataKoduTextTR);
		yediHataKoduText = copyText(yediHataKoduTextTR);
		sekizHataKoduText = copyText(sekizHataKoduTextTR);
		dokuzHataKoduText = copyText(dokuzHataKoduTextTR);
		onHataKoduText = copyText(onHataKoduTextTR);
		silmekIcinText = copyText(silmekIcinTextTR);
		calismaSekliText = copyText(calismaSekliTextTR);
		devirmeYuruyusText = copyText(devirmeYuruyusTextTR);
		bastikcaCalisanText = copyText(bastikcaCalisanTextTR);
		basGonderText = copyText(basGonderTextTR);
		emniyetCercevesiText = copyText(emniyetCercevesiTextTR);
		pasifText = copyText(pasifTextTR);
		aktifText = copyText(aktifTextTR);
		yavaslamaLimitText = copyText(yavaslamaLimitTextTR);
		altLimitText = copyText(altLimitTextTR);
		basincSalteriText = copyText(basincSalteriTextTR);
		kapiSecimleriText = copyText(kapiSecimleriTextTR);
		katKapisiAktifText = copyText(katKapisiAktifTextTR);
		tablaKapiAktifText = copyText(tablaKapiAktifTextTR);
		katArtiTablaAktifText = copyText(katArtiTablaAktifTextTR);
		kapiAcmaTipiText = copyText(kapiAcmaTipiTextTR);
		kapiButonuESPText = copyText(kapiButonuESPTextTR);
		katButonuEXTText = copyText(katButonuEXTTextTR);
		birKatKapiTipiText = copyText(birKatKapiTipiTextTR);
		butonKontrolluText = copyText(butonKontrolluTextTR);
		birinciKapiAcSuresiText = copyText(birinciKapiAcSuresiTextTR);
		kacSaniyeText = copyText(kacSaniyeTextTR);
		ikinciKatKapiTipiText = copyText(ikinciKatKapiTipiTextTR);
		ikinciKapiAcSuresiText = copyText(ikinciKapiAcSuresiTextTR);
		tablaKapiTipiText = copyText(tablaKapiTipiTextTR);
		tablaKapiAcKonumText = copyText(tablaKapiAcKonumTextTR);
		birinciKattaAcText = copyText(birinciKattaAcTextTR);
		ikinciKattaAcText = copyText(ikinciKattaAcTextTR);
		birVeIkinciKattaAcText = copyText(birVeIkinciKattaAcTextTR);
		tablaKapiAcSureText = copyText(tablaKapiAcSureTextTR);
		yukariYavaslamaLimitiText = copyText(yukariYavaslamaLimitiTextTR);
		devirmeYuruyusMenuText = copyText(devirmeYuruyusMenuTextTR);
		devirmeAktifText = copyText(devirmeAktifTextTR);
		yuruyusAktifText = copyText(yuruyusAktifTextTR);
		devirmeYukariText = copyText(devirmeYukariTextTR);
		yuruyusIleriText = copyText(yuruyusIleriTextTR);
		devirmeAsagiSivicText = copyText(devirmeAsagiSivicTextTR);
		yuruyusGeriSivicText = copyText(yuruyusGeriSivicTextTR);
		yuruyusSecildiText = copyText(yuruyusSecildiTextTR);
		devirmeSilindirTipiText = copyText(devirmeSilindirTipiTextTR);
		tekTesirText = copyText(tekTesirTextTR);
		ciftTesirText = copyText(ciftTesirTextTR);
		platformSilindirTipiText = copyText(platformSilindirTipiTextTR);
		asagiValfSureText = copyText(asagiValfSureTextTR);
		devirmeYukariValfSureText = copyText(devirmeYukariValfSureTextTR);
		ileriValfSureText = copyText(ileriValfSureTextTR);
		devirmeAsagiValfSureText = copyText(devirmeAsagiValfSureTextTR);
		geriValfSureText = copyText(geriValfSureTextTR);
		calismaSuresiText = copyText(calismaSuresiTextTR);
		calismaSayisiText = copyText(calismaSayisiTextTR);
		enterlaSifirlaText = copyText(enterlaSifirlaTextTR);
		dilSecimText = copyText(dilSecimTextTR);
		secilenDilText = copyText(secilenDilTextTR);
		menudenCikisText = copyText(menudenCikisTextTR);
		enteraBasinizText = copyText(enteraBasinizTextTR);
		hataKoduText = copyText(hataKoduTextTR);
	} else {
		menuyeGirildiText = copyText(menuyeGirildiTextEN);
		ayarlarText = copyText(ayarlarTextEN);
		hataKayitListText = copyText(hataKayitListTextEN);
		birHataKoduText = copyText(birHataKoduTextEN);
		ikiHataKoduText = copyText(ikiHataKoduTextEN);
		ucHataKoduText = copyText(ucHataKoduTextEN);
		dortHataKoduText = copyText(dortHataKoduTextEN);
		besHataKoduText = copyText(besHataKoduTextEN);
		altiHataKoduText = copyText(altiHataKoduTextEN);
		yediHataKoduText = copyText(yediHataKoduTextEN);
		sekizHataKoduText = copyText(sekizHataKoduTextEN);
		dokuzHataKoduText = copyText(dokuzHataKoduTextEN);
		onHataKoduText = copyText(onHataKoduTextEN);
		silmekIcinText = copyText(silmekIcinTextEN);
		calismaSekliText = copyText(calismaSekliTextEN);
		devirmeYuruyusText = copyText(devirmeYuruyusTextEN);
		bastikcaCalisanText = copyText(bastikcaCalisanTextEN);
		basGonderText = copyText(basGonderTextEN);
		emniyetCercevesiText = copyText(emniyetCercevesiTextEN);
		pasifText = copyText(pasifTextEN);
		aktifText = copyText(aktifTextEN);
		yavaslamaLimitText = copyText(yavaslamaLimitTextEN);
		altLimitText = copyText(altLimitTextEN);
		basincSalteriText = copyText(basincSalteriTextEN);
		kapiSecimleriText = copyText(kapiSecimleriTextEN);
		katKapisiAktifText = copyText(katKapisiAktifTextEN);
		tablaKapiAktifText = copyText(tablaKapiAktifTextEN);
		katArtiTablaAktifText = copyText(katArtiTablaAktifTextEN);
		kapiAcmaTipiText = copyText(kapiAcmaTipiTextEN);
		kapiButonuESPText = copyText(kapiButonuESPTextEN);
		katButonuEXTText = copyText(katButonuEXTTextEN);
		birKatKapiTipiText = copyText(birKatKapiTipiTextEN);
		butonKontrolluText = copyText(butonKontrolluTextEN);
		birinciKapiAcSuresiText = copyText(birinciKapiAcSuresiTextEN);
		kacSaniyeText = copyText(kacSaniyeTextEN);
		ikinciKatKapiTipiText = copyText(ikinciKatKapiTipiTextEN);
		ikinciKapiAcSuresiText = copyText(ikinciKapiAcSuresiTextEN);
		tablaKapiTipiText = copyText(tablaKapiTipiTextEN);
		tablaKapiAcKonumText = copyText(tablaKapiAcKonumTextEN);
		birinciKattaAcText = copyText(birinciKattaAcTextEN);
		ikinciKattaAcText = copyText(ikinciKattaAcTextEN);
		birVeIkinciKattaAcText = copyText(birVeIkinciKattaAcTextEN);
		tablaKapiAcSureText = copyText(tablaKapiAcSureTextEN);
		yukariYavaslamaLimitiText = copyText(yukariYavaslamaLimitiTextEN);
		devirmeYuruyusMenuText = copyText(devirmeYuruyusMenuTextEN);
		devirmeAktifText = copyText(devirmeAktifTextEN);
		yuruyusAktifText = copyText(yuruyusAktifTextEN);
		devirmeYukariText = copyText(devirmeYukariTextEN);
		yuruyusIleriText = copyText(yuruyusIleriTextEN);
		devirmeAsagiSivicText = copyText(devirmeAsagiSivicTextEN);
		yuruyusGeriSivicText = copyText(yuruyusGeriSivicTextEN);
		yuruyusSecildiText = copyText(yuruyusSecildiTextEN);
		devirmeSilindirTipiText = copyText(devirmeSilindirTipiTextEN);
		tekTesirText = copyText(tekTesirTextEN);
		ciftTesirText = copyText(ciftTesirTextEN);
		platformSilindirTipiText = copyText(platformSilindirTipiTextEN);
		asagiValfSureText = copyText(asagiValfSureTextEN);
		devirmeYukariValfSureText = copyText(devirmeYukariValfSureTextEN);
		ileriValfSureText = copyText(ileriValfSureTextEN);
		devirmeAsagiValfSureText = copyText(devirmeAsagiValfSureTextEN);
		geriValfSureText = copyText(geriValfSureTextEN);
		calismaSuresiText = copyText(calismaSuresiTextEN);
		calismaSayisiText = copyText(calismaSayisiTextEN);
		enterlaSifirlaText = copyText(enterlaSifirlaTextEN);
		dilSecimText = copyText(dilSecimTextEN);
		secilenDilText = copyText(secilenDilTextEN);
		menudenCikisText = copyText(menudenCikisTextEN);
		enteraBasinizText = copyText(enteraBasinizTextEN);
		hataKoduText = copyText(hataKoduTextEN);
	}
}

#endif /* INC_DATA_H_ */
