/*
 * Process.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "main.h"
#include "Process.h"
#include "GlobalVariables.h"
#include "i2c-lcd.h"
#include "ErrorProcess.h"
#include "EEPROMProcess.h"
#include "WifiProcess.h"
#include "Menu.h"
#include "Translation.h"
#include "TextVariables.h"

void lcdUpdate(uint8_t y) {
	if(y==1) {
		lcd_print(2, 1, " ");
	} else if(y==2) {
		lcd_print(2, 2, " ");
	} else if(y==3) {
		lcd_print(2, 3, " ");
	} else if(y==4) {
		lcd_print(2, 4, " ");
	} else if(y==5) {
		lcd_print(2, 5, " ");
	} else if(y==6) {
		lcd_print(2, 6, " ");
	} else if (y==7) {
		lcd_clear();
		lcd_print(1, 1, mainTextGN);
		lcd_print(2, 1, mainText2GN);
	}
}

void checkLCDBacklight() {
	if(millis - backLightTimer >= lcdBacklightSure*10) {
		lcd_backlight(0);
	} else {
		lcd_backlight(1);
	}
}

void bekle() {
	timer1=millis;
    while((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin) == 1) && (millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port,butonGeriIn_Pin) == 1) && (millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port,kapi1AcButonIn_Pin) == 0) && (millis-timer1<1)){
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port,kapi2AcButonIn_Pin) == 0) && (millis-timer1<1)){
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port,kapiTablaAcButonIn_Pin) == 0) && (millis-timer1<1)){
    	butonKontrol = 1;
    }

}

uint8_t buttonCheck(void) {
	if((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin) == 1)
			|| (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port,butonGeriIn_Pin) == 1)
			|| (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1)
			|| (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1)
			|| (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1)) {
		backLightTimer = 0;
		return 1;
	}
	return 0;
}

void checkBasincSalteri() {
	if(basincSalteri==0) {
		basincVar=1;
	}

	if(basincSalteri==1) {
		if(HAL_GPIO_ReadPin(basincSalteriIn_GPIO_Port, basincSalteriIn_Pin)==0) {
			if(millis-timer5>=3) {
				basincVar=1;
			}
		} else {
			timer5=millis;
			basincVar=0;
		}
	}
}

void checkBasGonder() {
	if((calismaSekli==1)&&(yukarimotorcalisiyor==1)&&(devirmeYuruyusSecim==0)) {
		basgondercalisyukari=1;
	} else if(yukarimotorcalisiyor==0) {
		basgondercalisyukari=0;
	}

	if((calismaSekli==1)&&(asagivalfcalisiyor==1)&&(devirmeYuruyusSecim==0)) {
		basgondercalisasagi=1;
	} else if(asagivalfcalisiyor==0) {
		basgondercalisasagi=0;
	}
}

void checkKapiSecimleri() {
	if(kapiSecimleri==0) {
		kapiSivicVar=1;
	}

	if(kapiSecimleri==1) {
		if(HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==0) {
			kapiSivicVar=1;
		} else {
			kapiSivicVar=0;
		}
	}

	if(kapiSecimleri==2){
		if(HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==0) {
			kapiSivicVar=1;
		} else {
			kapiSivicVar=0;
		}
	}

	if(kapiSecimleri==3) {
		if((HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==0)&&(HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==0)) {
			kapiSivicVar=1;
		} else {
			kapiSivicVar=0;
		}
	}
}

void checkAktifCalisma() {
	if(demoMode==0 && menuGiris==0) {
		if(((yukarimotorcalisiyor)||(devmotoryukaricalisiyor)||((asagivalfcalisiyor)&&(butonKontrol2==0)&&(platformSilindirTipi==1))||((devmotorasagicalisiyor)&&(devirmeSilindirTipi)==1))&&(stopVar)&&(kapiSivicVar)) {
			HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_SET);
			motorcalisiyor=1;
			CalismaSayisiYukari=1;
		} else {
			HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
			motorcalisiyor=0;
		}

		/*YUKARI ÇALISMA*/

		if((menuGiris==0) && (stopVar) && (kapiSivicVar)																		/********* motor calısması ***********/
				&& ((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0)||(basgondercalisyukari))
				&& (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
				&& (basincVar)
				&& (((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==1))||(yukarimotorcalisiyor))
				&& (asagivalfcalisiyor==0)
				&& (devmotoryukaricalisiyor==0)
				&& (devmotorasagicalisiyor==0)
				&&(devyukarivalfcalisiyor==0)
				&&(devasagivalfcalisiyor==0)) {
			yukarimotorcalisiyor=1;
		} else {
			yukarimotorcalisiyor=0;
		}

		if((yukarimotorcalisiyor==1)&&(((HAL_GPIO_ReadPin(yukariYavaslamaLimitIn_GPIO_Port, yukariYavaslamaLimitIn_Pin)==1))&&(yukariYavasLimit))) {	/* ikinci hız */
			HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
		}

		if(yukarimotorcalisiyor && (devirmeYuruyusSecim==1 || devirmeYuruyusSecim==2 || platformSilindirTipi==1)) {
			HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_SET);
			yukarivalfcalisiyor=1;
		}

		// yukari valf timer calisması

		if((yukarivalfcalisiyor==1)&&(((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1)&&(basgondercalisyukari==0))||(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1))&&(stopVar)&&(kapiSivicVar)&&(basincVar)&&(butonKontrol3==0)) {
			timer2=millis;
			butonKontrol3=1;
		}

		if((((millis-timer2 >= yukariValfTmr)&&(butonKontrol3==1))||((stopVar==0)||(kapiSivicVar==0)||(basincVar==0)))) {
			HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
			yukarivalfcalisiyor=0;
			butonKontrol3=0;
		}

		//Ond safety

		if(emniyetCercevesi==0) {
			cerceveVar=1;
		}

		if((emniyetCercevesi==1)&&(calismaSekli==0)&&(HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin)==0)&&(HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0)) {
			cerceveVar=1;
		} else if((emniyetCercevesi==1)&&(HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin)==1)&&(calismaSekli==0)) {
			cerceveVar=0;
		}

		if (emniyetCercevesi==1 && calismaSekli==1) {
			if(HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin)==0) {
				cerceveVar=1;
			} else {
				cerceveVar=0;
			}
		}

		//Asagi calisma
		if((menuGiris==0)&& (stopVar)&& (kapiSivicVar)
				&& ((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0)||(basgondercalisasagi))
				&& (cerceveVar)&&(emniyetCercevesihatasi==0)
				&& ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)||!(altLimit))
				&& (((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==1))||(asagivalfcalisiyor))
				&& (yukarimotorcalisiyor==0)
				&& (yukarivalfcalisiyor==0)
		  	  	&& (devmotoryukaricalisiyor==0)
				&& (devmotorasagicalisiyor==0)
				&& (devyukarivalfcalisiyor==0)
				&& (devasagivalfcalisiyor==0)) {
			HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_SET);
			asagivalfcalisiyor=1;
			CalismaSayisiAsagi=1;
			cercevesasagicalisma=1;
		}

		// asagi valf timer calisması

		if((asagivalfcalisiyor==1)&&(((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==1)&&(basgondercalisasagi==0))||((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)&&(altLimit)))&&(stopVar)&&(kapiSivicVar)&&(cerceveVar)&&(butonKontrol2==0)) {
			timer2=millis;
			butonKontrol2=1;
		}

		if((((millis-timer2 >= asagiValfTmr)&&(butonKontrol2==1))||((stopVar==0)||(kapiSivicVar==0)||(cerceveVar==0)))) {
			HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
			asagivalfcalisiyor=0;
			butonKontrol2=0;
		}

		//yavaslama valf

		if((asagivalfcalisiyor==1)&&(((HAL_GPIO_ReadPin(yavaslamaLimitIn_GPIO_Port, yavaslamaLimitIn_Pin)==0))&&(yavaslamaLimit))) {	/* ikinci hız */
			HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
		}

		/*DEVIRME veya YURUYUS Baslangic*/

		// Devirme Yukari veya yuruyus ileri calisma
		if((menuGiris==0)
				&& ((devirmeYuruyusSecim==1)||(devirmeYuruyusSecim==2))
				&& (stopVar) && (kapiSivicVar)
				&& (HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==0)
				&& ((HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==0)||!(devirmeYukariIleriLimit))
				&& (((HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==1))||(devmotoryukaricalisiyor))
				&& (yukarimotorcalisiyor==0)
				&& (yukarivalfcalisiyor==0)
				&& (asagivalfcalisiyor==0)
				&& (devmotorasagicalisiyor==0)
				&&(devasagivalfcalisiyor==0)) {
			devmotoryukaricalisiyor=1;
		} else {
			devmotoryukaricalisiyor=0;
		}

		if(devmotoryukaricalisiyor==1) {
			HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_SET);
			devyukarivalfcalisiyor=1;
		}
		// devirme yukari + yuruyus ileri valf timer calismasi

		if((devyukarivalfcalisiyor==1)&&((HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==1)||(HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==1))&&(stopVar)&&(kapiSivicVar)&&(butonKontrol4==0)) {
			timer2=millis;
			butonKontrol4=1;
		}

		if((((millis-timer2 >= devirmeYukariIleriTmr)&&(butonKontrol4==1))||((stopVar==0)||(kapiSivicVar==0)))) {
			HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
			devyukarivalfcalisiyor=0;
			butonKontrol4=0;
		}

		// Devirme Asagi veya yuruyus geri calisma

		if((menuGiris==0)
				&& ((devirmeYuruyusSecim==1)||(devirmeYuruyusSecim==2))
				&& (stopVar) && (kapiSivicVar)
				&& (HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==0)
				&& ((HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin)==0)||!(devirmeAsagiGeriLimit))
				&& (((HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==1))||(devmotorasagicalisiyor))
				&& (yukarimotorcalisiyor==0)
				&& (yukarivalfcalisiyor==0)
				&& (asagivalfcalisiyor==0)
				&& (devyukarivalfcalisiyor==0)
				&& (devmotoryukaricalisiyor==0)) {
			devmotorasagicalisiyor=1;
		} else {
			devmotorasagicalisiyor=0;
		}

		if(devmotorasagicalisiyor==1) {
			HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_SET);
			devasagivalfcalisiyor=1;
		}

		//devirme asagi + geri valf timer calismasi

		if((devasagivalfcalisiyor==1)&&((HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==1)||(HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin)==1))&&(stopVar)&&(kapiSivicVar)&&(butonKontrol5==0)) {
			timer2=millis;
			butonKontrol5=1;
		}

		if((((millis-timer2 >= devirmeYukariIleriTmr)&&(butonKontrol5==1))||((stopVar==0)||(kapiSivicVar==0)))) {
			HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
			devasagivalfcalisiyor=0;
			butonKontrol5=0;
		}

		// makine durum kontrolü

		if(HAL_GPIO_ReadPin(motorOut_GPIO_Port, motorOut_Pin)==0
				&&(HAL_GPIO_ReadPin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin)==0)
				&&(HAL_GPIO_ReadPin(yukariValfOut_GPIO_Port, yukariValfOut_Pin)==0)
				&&(HAL_GPIO_ReadPin(asagiValfOut_GPIO_Port, asagiValfOut_Pin)==0)
				&&(HAL_GPIO_ReadPin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin)==0)) {
			makineStop=1;
		} else {
			makineStop=0;
		}

		//kapi 1 kontrol

		// kapi 1 prudhome
		if((kapi1Tip==0)&&((kapiSecimleri==1)||(kapiSecimleri==3))
				&&((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0 && (kapiAcTipi==1)))
				&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
				&&(butonKontrol==0)
				&&(makineStop==1)) {
			kapi1prudhome=1;
			timer = millis;
			bekle();
		}

		if((millis-timer >= kapi1AcSure)||((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)||!(altLimit))||(makineStop==0)) {
			kapi1prudhome=0;
		}

		// kapi 1 buton kontrol

		if((kapi1Tip==1)&&((kapiSecimleri==1)||(kapiSecimleri==3))

				&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
				&&((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0 && (kapiAcTipi==1)))
				&&(makineStop==1)) {
			kapi1butonkontrol=1;
		} else {
			kapi1butonkontrol=0;
		}

		// kapi 1 pizzato

		if((kapi1Tip==2)&&((kapiSecimleri==1)||(kapiSecimleri==3))

				&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
				&&(makineStop==1)) {
			kapi1pizzato=1;
		} else {
			kapi1pizzato=0;
		}

		// kapi 1 çıkış

		if(kapi1butonkontrol==1 || kapi1pizzato==1 || kapi1prudhome==1) {
			HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
		}

		//kapi2 kontrol

		// kapi 2 prudhome

		if((kapi2Tip==0)&&((kapiSecimleri==1)||(kapiSecimleri==3))
				&&((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0 && (kapiAcTipi==1)))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
				&&(makineStop==1)
				&&(butonKontrol==0)) {
			kapi2prudhome=1;
			timer = millis;
			bekle();
		}

		if((millis-timer >= kapi2AcSure) || (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)||(makineStop==0)) {
			kapi2prudhome=0;
		}

		// kapi 2 buton kontrol

		if((kapi2Tip==1)&&((kapiSecimleri==1)||(kapiSecimleri==3))

				&&((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0 && (kapiAcTipi==1)))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
				&&(makineStop==1)) {
			kapi2butonkontrol=1;
		} else {
			kapi2butonkontrol=0;
		}

		// kapi 2 pizzato

		if((kapi2Tip==2)&&((kapiSecimleri==1)||(kapiSecimleri==3))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
				&&(makineStop==1)) {
			kapi2pizzato=1;
		} else {
			kapi2pizzato=0;
		}

		// kapi 2 çıkış

		if(kapi2butonkontrol==1 || kapi2pizzato==1 || kapi2prudhome==1) {
			HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
		}

		//   kapi tabla kontrol ***

		if((kapiTablaAcKonum==0 || kapiTablaAcKonum==2)
				&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)) {
			kapiTablaAcKonumKat1=1;
		} else {
			kapiTablaAcKonumKat1=0;
		}

		if((kapiTablaAcKonum==1 || kapiTablaAcKonum==2)
				&& (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)) {
			kapiTablaAcKonumKat2=1;
		} else {
			kapiTablaAcKonumKat2=0;
		}

		if(kapiTablaAcKonumKat1==1
				&& kapiAcTipi==1
				&& HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0) {
			kapiactablaesp1=1;
		} else {
			kapiactablaesp1=0;
		}

		if(kapiTablaAcKonumKat2==1
				&& kapiAcTipi==1
				&& HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0) {
			kapiactablaesp2=1;
		} else {
			kapiactablaesp2=0;
		}

		// tabla kapısı prudhome

		if((kapitablaTip==0)&&((kapiSecimleri==2)||(kapiSecimleri==3))
				&&((kapiTablaAcKonumKat1==1)||(kapiTablaAcKonumKat2==1))
				&&(((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin)==0)&&(kapiAcTipi==0))
				||(kapiactablaesp1)==1 || (kapiactablaesp2)==1)
				&&(makineStop==1)
				&&(butonKontrol==0)) {

			kapiTablaprudhome=1;
			timer = millis;
			bekle();
		}

		if((millis-timer >= kapiTablaAcSure)||((kapiTablaAcKonumKat1==0)&&(kapiTablaAcKonumKat2==0))||(makineStop==0)) {
			kapiTablaprudhome=0;
		}

		// tabla kapı buton kontrol

		if((kapitablaTip==1)&&((kapiSecimleri==2)||(kapiSecimleri==3))

				&&((kapiTablaAcKonumKat1==1)||(kapiTablaAcKonumKat2==1))
				&&(((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin)==0)&&(kapiAcTipi==0))
				||(kapiactablaesp1)==1 || (kapiactablaesp2)==1)
				&&(makineStop==1)) {
			kapiTablabutonkontrol=1;
		} else {
			kapiTablabutonkontrol=0;
		}

		// tabla kapı pizzato

		if((kapitablaTip==2)&&((kapiSecimleri==2)||(kapiSecimleri==3))
				&&((kapiTablaAcKonumKat1==1)||(kapiTablaAcKonumKat2==1))
				&&(makineStop==1)) {
			kapiTablapizzato=1;
		} else { /* if((kapitablaTip==1)&&((kapiSecimleri==2)||(kapiSecimleri==3))) */
			kapiTablapizzato=0;
		}

		// kapi Tabla çıkış

		if(kapiTablabutonkontrol==1 || kapiTablaprudhome==1 || kapiTablapizzato==1) {
			HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
		}

		/********************************* CALİSMA SAYISI KAYIT YERİ *************************************/

		if(((CalismaSayisiYukari==1)&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)&&(altLimit==0)&&(makineStop==1))
				||((CalismaSayisiAsagi==1)&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)&&(altLimit))&&(makineStop==1))) {
			calismaSayisi++;
			eepromData[27]=calismaSayisi;

			hafizaYaz=1;

			CalismaSayisiYukari=0;
			CalismaSayisiAsagi=0;

		}

		/******************************************* HATA BASLIYOR *******************************************/

		/************************************ ACİL STOP HATA BASLANGICI **************************************************/
		if((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0
			  	||HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0
			  	||HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==0
			  	||HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==0)) {
			startBasili=1;
		} else {
			startBasili=0;
		}


		if(startBasili && HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin)==1) {
			hataVar=1;
			hataKoduLcdGoster(1);
			hata2EEPROM(1);
			convertAndSendData();
			acilstophatasi=1;
		} else if(acilstophatasi && HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin)==0 && startBasili==0) {
			acilstophatasi=0;
			lcdUpdate(1);
		}

		/************************************ Emniyet Çerçevesi Hatasi ***************************************************/

		if(cerceveVar==0 && (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0 || cercevesasagicalisma)&& (emniyetCercevesi==1)) {
			hataVar=1;
			hataKoduLcdGoster(2);
			hata2EEPROM(2);
			convertAndSendData();
			emniyetCercevesihatasi=1;
		} else if(emniyetCercevesihatasi && cerceveVar==1 && asagivalfcalisiyor==0) {
			emniyetCercevesihatasi=0;
			cercevesasagicalisma=0;
			lcdUpdate(2);
		}

		/************************************ BASINC ASIRI YUK HATASI **************************************************/

		if(basincVar==0 && basincSalteri==1 && motorcalisiyor==1 && HAL_GPIO_ReadPin(basincSalteriIn_GPIO_Port, basincSalteriIn_Pin)==1) {
			hataVar=1;
			hataKoduLcdGoster(3);
			hata2EEPROM(3);
			convertAndSendData();
			basinchatasi=1;
		} else if(basinchatasi && basincVar==1 && HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1) {
			basinchatasi=0;
			lcdUpdate(3);
		}

		/************************************ KAPI SİVİÇ HATASI **************************************************/
		if((startBasili || HataMakineCalisiyorkapi) && HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==1 && (kapiSecimleri==1 || kapiSecimleri==3)) {
			hataVar=1;
			hataKoduLcdGoster(4);
			hata2EEPROM(4);
			convertAndSendData();
			katkapisivicihatasi=1;
		} else if (katkapisivicihatasi && makineStop && startBasili==0 && HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==0) {
			katkapisivicihatasi=0;
			HataMakineCalisiyorkapi=0;
			lcdUpdate(4);
		}

		/************************************ TABLA KAPI SİVİÇ HATASI **************************************************/

		if((startBasili || HataMakineCalisiyortabla)&& HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==1 && (kapiSecimleri==1 || kapiSecimleri==3)) {
			hataVar=1;
			hataKoduLcdGoster(5);
			hata2EEPROM(5);
			convertAndSendData();
			tablakapisivicihatasi=1;
		} else if (tablakapisivicihatasi && makineStop && startBasili==0 && HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==0 && makineStop==1) {
			tablakapisivicihatasi=0;
			HataMakineCalisiyortabla=0;
			lcdUpdate(5);
		}

		/************************************ MAX CALİSMA HATASI BASLANGIC ******************************************/

		if((motorcalisiyor)||(asagivalfcalisiyor)||(devmotorasagicalisiyor)) {
		    if(millis-timer4>=makineCalismaTmr) {
			  	hataVar=1;
			  	hataKoduLcdGoster(6);
			  	hata2EEPROM(6);
			  	convertAndSendData();
			  	maksimumcalismahatasi=1;
			  }
		}

		if(maksimumcalismahatasi && HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) && startBasili==0) {
			maksimumcalismahatasi=0;
			lcdUpdate(6);
		}

		if((yukarimotorcalisiyor==1)||(asagivalfcalisiyor==1)||(devmotoryukaricalisiyor==1)||(devmotorasagicalisiyor==1)) {
			makineCalisiyor=0;
			HataMakineCalisiyorkapi=1;
			HataMakineCalisiyortabla=1;
		} else {
			makineCalisiyor=1;
			timer4=millis;
		}

		/*********************************** HATA YOKSA HATA VAR SIFIRLA **************************************************/
		if(hataVar==1 && acilstophatasi==0 && emniyetCercevesihatasi==0 && basinchatasi==0
				&& katkapisivicihatasi==0 && tablakapisivicihatasi==0 && maksimumcalismahatasi==0) {
			hataVar=0;
			lcdUpdate(7);
		}


		/************************************ HATA LCD GÖSTERME ************************************************************/
	} 		// aktif calisma son parantez.
}

void checkDemoModCalisma() {
	if((demoMode==1)&&(stopVar)&&(menuGiris==0)) {

		if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
				&& (demoAsagiCalis==0)
				&& (demoDevYukari==0)
				&& (demoDevAsagi==0)) {

			HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_SET);
			demoYukariCalis=1;
		} else if(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1) {

			HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
			demoYukariCalis=0;
		}

		// DEMO MOTOR CALISMASI

		if((demoYukariCalis)||(demoDevYukari)||(demoDevAsagi)||(demoAsagiCalis)) {
			HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
		}

		if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==0)
				&& (demoYukariCalis==0)
				&& (demoAsagiCalis==0)) {
			//bos burası
		}

		//DEVİRME YUKARI CALIS
		if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==0)
				&&(demoYukariCalis==0)
				&&(demoAsagiCalis==0)
				&& (demoDevAsagi==0)) {

			HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_SET);
			demoDevYukari=1;
		} else {
			HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
			demoDevYukari=0;
		}

		// DEVIRME ASAGI CALIS

		if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin)==0)
				&&(demoYukariCalis==0)
				&&(demoDevYukari==0)
				&& (demoAsagiCalis==0)) {

			HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_SET);
			demoDevAsagi=1;
		} else {
			HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
			demoDevAsagi=0;
		}

		// DEMO ASAGI CALISMA

		if((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
				&& (demoYukariCalis==0)
				&& (demoDevAsagi==0)
				&& (demoDevYukari==0)) {

			HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_SET);
			demoAsagiCalis=1;
			demoCalismaSayisiYar=1;
		} else if ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)) {
			HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
			demoAsagiCalis=0;
		}

		if(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1) {
			HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
			timer3 = millis;
		}

		if(millis-timer3 >= 5) {
			HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
		}

		if(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1) {
			HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
			timer3 = millis;
		}

		if(millis-timer3 >= 5) {
			HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
		}

		if((demoYukariCalis==1) && (demoCalismaSayisiYar==1)) {
			//mesajYazildi=0;
			calismaSayisiDemo++;

			eepromData[28]=calismaSayisiDemo;
			hafizaYaz=1;
		 		//mesajYazildi=0;
			demoCalismaSayisiYar=0;
		}

		if (menuGiris==0) {
			lcd_print(1, 1, demoModTextGN);
			lcd_print(2, 1, cycleTextGN);
			itoa(calismaSayisiDemo, snum, 10);
			lcd_print(2,16,snum);
			mesajYazildi=1;
		}
	} else if(demoMode==1 || menuGiris==1) {
		HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
		//HAL_GPIO_WritePin(buzzerOut_GPIO_Port, buzzerOut_Pin, GPIO_PIN_RESET);
	}
}

void mainLoop() {
	while(1) {
		checkLCDBacklight();

		if((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port,butonGeriIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==0)&&(HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin)==1)&&(HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin)==1)&&(HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin)==1)) {
			butonKontrol=0;
		} else {
			backLightTimer = millis;
		}

		if(buttonCheck() == 1) {
			backLightTimer = millis;
		}

		if(hafizaYaz==1) {
		  while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
		  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);

		  HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
		  HAL_Delay(500);

		  hafizaYaz=0;
		  lcd_print(2, 1, dataYazildiText);

		  HAL_Delay(1000);
		  lcd_clear();
		}

		if((hafizaOku==0)&&(HAL_I2C_GetState(&hi2c1) == HAL_I2C_STATE_READY)) {
		  if(ilkOkuma==0) {
			  lcd_print(1, 1, eepromTextGN);
			  lcd_print(2, 1, dataOkunuyorText);
			  HAL_Delay(1000);

			  while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
			  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY) {
				  HAL_Delay(1000);
			  }

			  lcd_print(2, 1, dataOkunduText);

			  ilkOkuma=1;
		  } else {
			  lcd_print(2, 1, degerKaydedildiText);
			  lcd_clear();
		  }

		  lcd_clear();

		  eepromKontrol();
		  hafizaOku=1;
		}

		if((menuGiris==0)&&(mesajYazildi==0)&&(demoMode==0)) {
			lcd_clear();
			HAL_Delay(10);
			lcd_print(1, 1, mainTextGN);
			lcd_print(2, 1, mainText2GN);
			mesajYazildi=1;
		}

		if ((menuGiris==0) && (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)) {
			menuGiris=1;
			lcd_clear();
		}

		if(menuGiris==1) {
			menu();
		}

		HAL_GPIO_TogglePin(cycleLed_GPIO_Port, cycleLed_Pin);

		/* GİRİLEN PARAMETRELERE GÖRE AYARLARIN YAPILMASI*/

		if(HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin)==0 && hataVar==0) {
			stopVar=1;
		} else {
			stopVar=0;
		}

		/****************************************  BASINC SALTERI ********************************************/
		checkBasincSalteri();

		/******** Bas gönder ***********/
		checkBasGonder();

		/******** Kapı Secimleri ***********/
		checkKapiSecimleri();

		/* PARAMETRELERE GÖRE ÇIKISLARIN AYARLANMASI*/
		/*MOTOR CALISIYOR*/
		checkAktifCalisma();

		// DEMO MOD BASLIYOR
		// DEMO YUKARI CALISMA
		checkDemoModCalisma();
	}
}
