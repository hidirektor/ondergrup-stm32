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
#include "TextVariables.h"
#include "Translation.h"

void menu() {
	if ((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin) == 1) && (butonKontrol == 0)) {
		menuSayac = menuSayac+1;
		if (menuSayac == 32) {    //MENÜ BÜYÜDÜKÇE DUZENLE
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
			menuSayac = 31;     //MENÜ BÜYÜDÜKÇE DUZENLE
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
		lcd_print(1, 1, menuyeGirildiText);
		lcd_print(2, 1, ayarlarText);
	}

	if (menuSayac == 1) {
		lcd_print(1, 1, hataKayitListText);

		if(hataGostermeSirasi == 0) {
			lcd_print(2, 1, birHataKoduText);
			lcd_print(2, 15, "   ");
			itoa(hataKayit1, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 1) {
			lcd_print(2, 1, ikiHataKoduText);
			lcd_print(2, 15, "  ");
			itoa(hataKayit2, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 2) {
			lcd_print(2, 1, ucHataKoduText);
			lcd_print(2, 15, "  ");
			itoa(hataKayit3, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 3) {
			lcd_print(2, 1, dortHataKoduText);
			lcd_print(2, 15, "  ");
			itoa(hataKayit4, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 4) {
			lcd_print(2, 1, besHataKoduText);
			lcd_print(2, 15, "  ");
			itoa(hataKayit5, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 5) {
			lcd_print(2, 1, altiHataKoduText);
			lcd_print(2, 15, "  ");
			itoa(hataKayit6, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 6) {
			lcd_print(2, 1, yediHataKoduText);
			lcd_print(2, 15, "  ");
			itoa(hataKayit7, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 7) {
			lcd_print(2, 1, sekizHataKoduText);
			lcd_print(2, 15, "  ");
			itoa(hataKayit8, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 8) {
			lcd_print(2, 1, dokuzHataKoduText);
			lcd_print(2, 15, "  ");
			itoa(hataKayit9, snum, 10);
			lcd_print(2, 14, snum);
		}

		if(hataGostermeSirasi == 9) {
			lcd_print(2, 1, onHataKoduText);
			lcd_print(2, 16, " ");
			itoa(hataKayit10, snum, 10);
			lcd_print(2, 15, snum);
		}

		if(hataGostermeSirasi == 10) {
			lcd_print(2, 1, silmekIcinText);
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
		lcd_print(1, 1, calismaSekliText);

		if((devirmeYuruyusSecim == 1) || (devirmeYuruyusSecim == 2)) {
			lcd_print(2, 1, devirmeYuruyusText);
		}

		if((calismaSekli == 0) && (devirmeYuruyusSecim == 0)) {
			lcd_print(2, 1, bastikcaCalisanText);
		}

		if((calismaSekli == 1) && (devirmeYuruyusSecim == 0)) {
			lcd_print(2, 1, basGonderText);
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
		lcd_print(1, 1, emniyetCercevesiText);

		if(emniyetCercevesi == 0) {
			lcd_print(2, 1, pasifText);
		} else if(emniyetCercevesi == 1) {
			lcd_print(2, 1, ondSafetyTextGN);
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
		lcd_print(1, 1, yavaslamaLimitText);

		if(yavaslamaLimit == 0) {
			lcd_print(2, 1, pasifText);
		} else if(yavaslamaLimit == 1) {
			lcd_print(2, 1, aktifText);
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
		lcd_print(1, 1, altLimitText);

		if(altLimit == 0) {
			lcd_print(2, 1, pasifText);
		} else if(altLimit == 1) {
			lcd_print(2, 1, aktifText);
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
		lcd_print(1, 1, basincSalteriText);

		if(basincSalteri == 0) {
			lcd_print(2, 1, pasifText);
		} else if(basincSalteri == 1) {
			lcd_print(2, 1, aktifText);
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
		lcd_print(1, 1, kapiSecimleriText);

		if(kapiSecimleri == 0) {
			lcd_print(2, 1, pasifText);
		} else if(kapiSecimleri == 1) {
			lcd_print(2, 1, katKapisiAktifText);
		} else if(kapiSecimleri == 2) {
			lcd_print(2, 1, tablaKapiAktifText);
		} else if(kapiSecimleri == 3) {
			lcd_print(2, 1, katArtiTablaAktifText);
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
		lcd_print(1, 1, kapiAcmaTipiText);

		if(kapiAcTipi == 0) {
			lcd_print(2, 1, kapiButonuESPText);
		} else if(kapiAcTipi == 1){
			lcd_print(2, 1, katButonuEXTText);
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
		lcd_print(1, 1, birKatKapiTipiText);

		if(kapi1Tip == 0) {
			lcd_print(2, 1, prudhomeTextGN);
		} else if(kapi1Tip == 1) {
			lcd_print(2, 1, butonKontrolluText);
		} else if(kapi1Tip == 2) {
			lcd_print(2, 1, pizzattoTextGN);
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
		lcd_print(1, 1, birinciKapiAcSuresiText);
		lcd_print(2, 1, kacSaniyeText);

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
		lcd_print(1, 1, ikinciKatKapiTipiText);

		if(kapi2Tip == 0) {
			lcd_print(2, 1, prudhomeTextGN);
		} else if(kapi2Tip == 1) {
			lcd_print(2, 1, butonKontrolluText);
		} else if(kapi2Tip == 2) {
			lcd_print(2, 1, pizzattoTextGN);
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
		lcd_print(1, 1, ikinciKapiAcSuresiText);
		lcd_print(2, 1, kacSaniyeText);

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
		lcd_print(1, 1, tablaKapiTipiText);

		if(kapitablaTip == 0) {
			lcd_print(2, 1, prudhomeTextGN);
		} else if(kapitablaTip == 1) {
			lcd_print(2, 1, butonKontrolluText);
		} else if(kapitablaTip == 2) {
			lcd_print(2, 1, pizzattoTextGN);
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
		lcd_print(1, 1, tablaKapiAcKonumText);

		if(kapiTablaAcKonum == 0) {
			lcd_print(2, 1, birinciKattaAcText);
		} else if(kapiTablaAcKonum == 1) {
			lcd_print(2, 1, ikinciKattaAcText);
		} else if(kapiTablaAcKonum == 2) {
			lcd_print(2, 1, birVeIkinciKattaAcText);
		} else if(kapiTablaAcKonum == 3) {
			lcd_print(2, 1, pasifText);
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
		lcd_print(1, 1, tablaKapiAcSureText);
		lcd_print(2, 1, kacSaniyeText);

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
		lcd_print(1, 1, yukariYavaslamaLimitiText);

		if(yukariYavasLimit == 0) {
			lcd_print(2, 1, pasifText);
		} else if(yukariYavasLimit == 1) {
			lcd_print(2, 1, aktifText);
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
		lcd_print(1, 1, devirmeYuruyusMenuText);

		if(devirmeYuruyusSecim == 2) {
			lcd_print(2, 1, devirmeAktifText);
		} else if(devirmeYuruyusSecim == 1) {
			lcd_print(2, 1, yuruyusAktifText);
		} else if(devirmeYuruyusSecim == 0) {
			lcd_print(2, 1, pasifText);
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
			lcd_print(1, 1, devirmeYukariText);
		} else if(devirmeYuruyusSecim == 1) {
			lcd_print(1, 1, yuruyusIleriText);
		}

		if(devirmeYukariIleriLimit == 0) {
			lcd_print(2, 1, pasifText);
		} else if(devirmeYukariIleriLimit == 1){
			lcd_print(2, 1, aktifText);
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
			lcd_print(1, 1, devirmeAsagiSivicText);
		} else if(devirmeYuruyusSecim == 1) {
			lcd_print(1, 1, yuruyusGeriSivicText);
		}

		if(devirmeAsagiGeriLimit == 0) {
			lcd_print(2, 1, pasifText);
		} else if(devirmeAsagiGeriLimit == 1) {
			lcd_print(2, 1, aktifText);
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
			lcd_print(1, 1, yuruyusSecildiText);
		} else if(devirmeYuruyusSecim == 2) {
			lcd_print(1, 1, devirmeSilindirTipiText);
		}

		if(devirmeSilindirTipi == 0) {
			lcd_print(2, 1, tekTesirText);
		} else if(devirmeSilindirTipi == 1) {
			lcd_print(2, 1, ciftTesirText);
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
		lcd_print(1, 1, platformSilindirTipiText);

		if(platformSilindirTipi == 0) {
			lcd_print(2, 1, tekTesirText);
		} else if(platformSilindirTipi == 1) {
			lcd_print(2, 1, ciftTesirText);
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
		lcd_print(1, 1, yukariValfSureText);

		if(yukariValfTmr >= 0) {
			lcd_print(2, 1, kacSaniyeText);
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
		lcd_print(1, 1, asagiValfSureText);

		if(asagiValfTmr >= 0) {
			lcd_print(2, 1, kacSaniyeText);
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
			lcd_print(1, 1, devirmeYukariValfSureText);
		} else if(devirmeYuruyusSecim == 1) {
			lcd_print(1, 1, ileriValfSureText);
		}

		if(devirmeYukariIleriTmr >= 0) {
			lcd_print(2, 1, kacSaniyeText);
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
			lcd_print(1, 1, devirmeAsagiValfSureText);
		} else if(devirmeYuruyusSecim == 1) {
			lcd_print(1, 1, geriValfSureText);
		}

		if(devirmeAsagiGeriTmr >= 0) {
			lcd_print(2, 1, kacSaniyeText);
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
		lcd_print(1, 1, calismaSuresiText);

		if(makineCalismaTmr > 99) {
			lcd_print(2, 1, kacSaniyeText);

			itoa(makineCalismaTmr, snum, 10);
			lcd_print(2,14,snum);

		} else if((makineCalismaTmr >= 10) && (makineCalismaTmr <=  99)) {
			lcd_print(2, 1, kacSaniyeText);

			itoa(makineCalismaTmr, snum, 10);
			lcd_print(2, 15, snum);
		} else if(makineCalismaTmr <=  9) {
			lcd_print(2, 1, kacSaniyeText);

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
		lcd_print(1, 1, buzzerTextGN);

		if(buzzer == 0) {
			lcd_print(2, 1, pasifText);
		} else if(buzzer == 1) {
			lcd_print(2, 1, aktifText);
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
		lcd_print(1, 1, demoModTextGN);

		if(demoMode == 0) {
			lcd_print(2, 1, pasifText);
		} else if(demoMode == 1) {
			lcd_print(2, 1, aktifText);
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
		if(calismaSayModu == 0) {
			lcd_print(1, 1, calismaSayisiText);
			int finalCount = 0;

			if(demoMode == 1) {
				finalCount += calismaCountDemo * 255; //sıfır durumu da dahil ediliyor
				finalCount += calismaSayisiDemo;
			} else {
				finalCount += calismaCount * 255; //sıfır durumu da dahil ediliyor
				finalCount += calismaSayisi;
			}

			itoa(finalCount, snum, 10);
			lcd_print(2, 16, snum);

			lcd_print(2, 1, "           ");
		} else if(calismaSayModu == 1) {
			lcd_print(1, 1, calismaSayisiText);
			lcd_print(2, 1, enterlaSifirlaText);
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
			if(demoMode == 1) {
				calismaSayisiDemo = 0;
				eepromData[28] = 0;
			} else {
				calismaSayisi = 0;
				eepromData[27] = 0;
			}
			calismaSayModu = 0;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 30) {
		calismaSayModu = 0;

		lcd_print(1, 1, dilSecimText);
		lcd_print(2, 1, secilenDilText);

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (butonKontrol == 0)) {
			dilSecim = dilSecim + 1;

			if(dilSecim > 1) {
				dilSecim = 0;
			}
			loadMenuTexts(dilSecim);

			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (butonKontrol == 0)) {
			dilSecim = dilSecim - 1;

		   	if(dilSecim > 0) {
		   		dilSecim = 1;
		   	}
		   	loadMenuTexts(dilSecim);

			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (butonKontrol == 0)) {
			eepromData[33] = dilSecim;
			hafizaYaz = 1;
		}
	}

	if (menuSayac == 31) {
		lcd_print(1, 1, menudenCikisText);
		lcd_print(2, 1, enteraBasinizText);

		if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) {
			menuGiris = 0;

			uint32_t startTick = HAL_GetTick();
			while (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF) {
			    if (HAL_GetTick() - startTick > 1000) {  // 1 saniye zaman aşımı
			        break;
			    }
			}

			startTick = HAL_GetTick();
			while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY) {
			    if (HAL_GetTick() - startTick > 1000) {  // 1 saniye zaman aşımı
			        break;
			    }
			}

			HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
			HAL_Delay(1200);

			lcd_clear();
			HAL_Delay(500);
			NVIC_SystemReset();
		}
	}
}
