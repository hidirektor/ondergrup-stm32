/*
 * Menu.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "Menu.h"
#include "main.h"
#include "GlobalVariables.h"
#include "EEPROMProcess.h"
#include "i2c-lcd.h"
#include "WifiProcess.h"
#include "IoTMenu.h"

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
			if(dilSecim == 0) {
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

		if(dilSecim == 0) {
			lcd_print(1, 1, "MAKINE ID       ");
		} else {
			lcd_print(1, 1, "MACHINE ID      ");
		}
		lcd_print(2, 1, machineID);
		lcd_print(2, 13, "    ");

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			takeMachineID();

			HAL_I2C_Mem_Read(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
			HAL_Delay(1500);
			memcpy(machineIDInt, &eepromData[idStartPos], 12);
			convertArrays(1);

			HAL_Delay(250);
			lcd_print(2, 1, machineID);
			lcd_print(2, 13, "    ");
		}
	}

	if (menuSayac == 33) {
		calismaSayModu = 0;
		int ssidLength = strlen(wifiSSID);

		lcd_print(1, 1, "WIFI SSID       ");
		if(ssidLength == 16) {
			lcd_print(2, 1, wifiSSID);
		} else if(ssidLength < 16) {
			for(int i=0; i<16-ssidLength; i++) {
				lcd_delete_char(2, ssidLength);
				ssidLength++;
			}
		} else {
			int lcdVal = 1;

			//Eğer ssid 16'dan büyükse buraya ekle
			for(int i=0; i<16; i++) {
				lcd_print_char(2, lcdVal, wifiSSID[i]);
				lcdVal++;
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			takeWifiSSID();

			HAL_I2C_Mem_Read(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
			HAL_Delay(1500);
			memcpy(wifiSSIDInt, &eepromData[ssidStartPos], 20);
			convertArrays(2);

			ssidLength = strlen(wifiSSID);

			HAL_Delay(250);
			if(ssidLength == 16) {
				lcd_print(2, 1, wifiSSID);
			} else if(ssidLength < 16) {
				for(int i=0; i<16-ssidLength; i++) {
					lcd_delete_char(2, ssidLength);
					ssidLength++;
				}
			} else {
				int lcdVal = 1;

				//Eğer ssid 16'dan büyükse buraya ekle
				for(int i=0; i<16; i++) {
					lcd_print_char(2, lcdVal, wifiSSID[i]);
					lcdVal++;
				}
			}
		}
	}

	if (menuSayac == 34) {
		calismaSayModu = 0;
		int passLength = strlen(wifiPass);

		lcd_print(1, 1, "WIFI PASS       ");
		if(passLength == 16) {
			lcd_print(2, 1, wifiPass);
		} else if(passLength < 16) {
			for(int i=0; i<16-passLength; i++) {
				lcd_delete_char(2, passLength);
				passLength++;
			}
		} else {
			int lcdVal = 1;

			//Eğer pass 16'dan büyükse buraya ekle
			for(int i=0; i<16; i++) {
				lcd_print_char(2, lcdVal, wifiPass[i]);
				lcdVal++;
			}
		}

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			takeWifiPass();

			HAL_I2C_Mem_Read(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
			HAL_Delay(1500);
			memcpy(wifiPassInt, &eepromData[passStartPos], 20);
			convertArrays(3);

			passLength = strlen(wifiPass);

			HAL_Delay(250);
			if(passLength == 16) {
				lcd_print(2, 1, wifiPass);
			} else if(passLength < 16) {
				for(int i=0; i<16-passLength; i++) {
					lcd_delete_char(2, passLength);
					passLength++;
				}
			} else {
				int lcdVal = 1;

				//Eğer pass 16'dan büyükse buraya ekle
				for(int i=0; i<16; i++) {
					lcd_print_char(2, lcdVal, wifiPass[i]);
					lcdVal++;
				}
			}
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

			while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
			while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);

			HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
			HAL_Delay(1200);

			lcd_clear();
			HAL_Delay(500);
			NVIC_SystemReset();
		}
	}
}
