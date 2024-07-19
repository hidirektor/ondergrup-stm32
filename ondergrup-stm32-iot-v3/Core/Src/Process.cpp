/*
 * Process.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


/*
 * Process.cpp
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "Process.h"

#include "Instance.h"
#include "Menu.h"
#include "main.h"

void Process::lcdUpdate(uint8_t y) {
    if (y == 1) {
        lcd.print(2, 1, " ");
    } else if (y == 2) {
        lcd.print(2, 2, " ");
    } else if (y == 3) {
        lcd.print(2, 3, " ");
    } else if (y == 4) {
        lcd.print(2, 4, " ");
    } else if (y == 5) {
        lcd.print(2, 5, " ");
    } else if (y == 6) {
        lcd.print(2, 6, " ");
    } else if (y == 7) {
        lcd.clear();
        lcd.print(1, 1, translation.mainTextGN.data());
        lcd.print(2, 1, translation.mainText2GN.data());
    }
}

void Process::checkLCDBacklight() {
    if (globalVars.millis - globalVars.backLightTimer >= systemDefaults.lcdBacklightSure * 10) {
        lcd.backlight(0);
    } else {
        lcd.backlight(1);
    }
}

void Process::bekle() {
	globalVars.timer1 = globalVars.millis;
    while ((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) && (globalVars.millis - globalVars.timer1 < 1)) { /* Butona basili olduğu surece bekle */
        globalVars.butonKontrol = 1;
    }

    while ((HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) && (globalVars.millis - globalVars.timer1 < 1)) { /* Butona basili olduğu surece bekle */
        globalVars.butonKontrol = 1;
    }

    while ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.millis - globalVars.timer1 < 1)) { /* Butona basili olduğu surece bekle */
        globalVars.butonKontrol = 1;
    }

    while ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.millis - globalVars.timer1 < 1)) { /* Butona basili olduğu surece bekle */
        globalVars.butonKontrol = 1;
    }

    while ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.millis - globalVars.timer1 < 1)) { /* Butona basili olduğu surece bekle */
        globalVars.butonKontrol = 1;
    }

    while ((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin) == 0) && (globalVars.millis - globalVars.timer1 < 1)) {
        globalVars.butonKontrol = 1;
    }

    while ((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin) == 0) && (globalVars.millis - globalVars.timer1 < 1)) {
        globalVars.butonKontrol = 1;
    }

    while ((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin) == 0) && (globalVars.millis - globalVars.timer1 < 1)) {
        globalVars.butonKontrol = 1;
    }
}

uint8_t Process::buttonCheck() {
    if ((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1)
        || (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1)
        || (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1)
        || (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1)
        || (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1)) {
    	globalVars.backLightTimer = 0;
        return 1;
    }
    return 0;
}

void Process::checkBasincSalteri() {
    if (globalVars.basincSalteri == 0) {
    	globalVars.basincVar = 1;
    }

    if (globalVars.basincSalteri == 1) {
        if (HAL_GPIO_ReadPin(basincSalteriIn_GPIO_Port, basincSalteriIn_Pin) == 0) {
            if (globalVars.millis - globalVars.timer5 >= 3) {
            	globalVars.basincVar = 1;
            }
        } else {
        	globalVars.timer5 = globalVars.millis;
            globalVars.basincVar = 0;
        }
    }
}

void Process::checkBasGonder() {
    if ((globalVars.calismaSekli == 1) && (globalVars.yukarimotorcalisiyor == 1) && (globalVars.devirmeYuruyusSecim == 0)) {
    	globalVars.basgondercalisyukari = 1;
    } else if (globalVars.yukarimotorcalisiyor == 0) {
    	globalVars.basgondercalisyukari = 0;
    }

    if ((globalVars.calismaSekli == 1) && (globalVars.asagivalfcalisiyor == 1) && (globalVars.devirmeYuruyusSecim == 0)) {
    	globalVars.basgondercalisasagi = 1;
    } else if (globalVars.asagivalfcalisiyor == 0) {
    	globalVars.basgondercalisasagi = 0;
    }
}

void Process::checkKapiSecimleri() {
    if (globalVars.kapiSecimleri == 0) {
    	globalVars.kapiSivicVar = 1;
    }

    if (globalVars.kapiSecimleri == 1) {
        if (HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin) == 0) {
        	globalVars.kapiSivicVar = 1;
        } else {
        	globalVars.kapiSivicVar = 0;
        }
    }

    if (globalVars.kapiSecimleri == 2) {
        if (HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin) == 0) {
        	globalVars.kapiSivicVar = 1;
        } else {
        	globalVars.kapiSivicVar = 0;
        }
    }

    if (globalVars.kapiSecimleri == 3) {
        if ((HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin) == 0) && (HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin) == 0)) {
        	globalVars.kapiSivicVar = 1;
        } else {
        	globalVars.kapiSivicVar = 0;
        }
    }
}

void Process::checkAktifCalisma() {
    if (globalVars.demoMode == 0 && globalVars.menuGiris == 0) {
        if (((globalVars.yukarimotorcalisiyor) || (globalVars.devmotoryukaricalisiyor) || ((globalVars.asagivalfcalisiyor) && (globalVars.butonKontrol2 == 0) && (globalVars.platformSilindirTipi == 1)) || ((globalVars.devmotorasagicalisiyor) && (globalVars.devirmeSilindirTipi) == 1)) && (globalVars.stopVar) && (globalVars.kapiSivicVar)) {
            HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_SET);
            globalVars.motorcalisiyor = 1;
            globalVars.CalismaSayisiYukari = 1;
        } else {
            HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
            globalVars.motorcalisiyor = 0;
        }

        /* YUKARI ÇALISMA */

        if ((globalVars.menuGiris == 0) && (globalVars.stopVar) && (globalVars.kapiSivicVar)
            && ((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 0) || (globalVars.basgondercalisyukari))
            && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 0)
            && (globalVars.basincVar)
            && (((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin) == 1)) || (globalVars.yukarimotorcalisiyor))
            && (globalVars.asagivalfcalisiyor == 0)
            && (globalVars.devmotoryukaricalisiyor == 0)
            && (globalVars.devmotorasagicalisiyor == 0)
            && (globalVars.devyukarivalfcalisiyor == 0)
            && (globalVars.devasagivalfcalisiyor == 0)) {
        	globalVars.yukarimotorcalisiyor = 1;
        } else {
        	globalVars.yukarimotorcalisiyor = 0;
        }

        if ((globalVars.yukarimotorcalisiyor == 1) && (((HAL_GPIO_ReadPin(yukariYavaslamaLimitIn_GPIO_Port, yukariYavaslamaLimitIn_Pin) == 1)) && (globalVars.yukariYavasLimit))) { /* ikinci hız */
            HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
        }

        if (globalVars.yukarimotorcalisiyor && (globalVars.devirmeYuruyusSecim == 1 || globalVars.devirmeYuruyusSecim == 2 || globalVars.platformSilindirTipi == 1)) {
            HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_SET);
            globalVars.yukarivalfcalisiyor = 1;
        }

        // yukari valf timer calisması

        if ((globalVars.yukarivalfcalisiyor == 1) && (((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 1) && (globalVars.basgondercalisyukari == 0)) || (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1)) && (globalVars.stopVar) && (globalVars.kapiSivicVar) && (globalVars.basincVar) && (globalVars.butonKontrol3 == 0)) {
        	globalVars.timer2 = globalVars.millis;
            globalVars.butonKontrol3 = 1;
        }

        if (((globalVars.millis - globalVars.timer2 >= globalVars.yukariValfTmr) && (globalVars.butonKontrol3 == 1)) || ((globalVars.stopVar == 0) || (globalVars.kapiSivicVar == 0) || (globalVars.basincVar == 0))) {
            HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
            globalVars.yukarivalfcalisiyor = 0;
            globalVars.butonKontrol3 = 0;
        }

        // Ond safety

        if (globalVars.emniyetCercevesi == 0) {
        	globalVars.cerceveVar = 1;
        }

        if ((globalVars.emniyetCercevesi == 1) && (globalVars.calismaSekli == 0) && (HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin) == 0) && (HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 0)) {
        	globalVars.cerceveVar = 1;
        } else if ((globalVars.emniyetCercevesi == 1) && (HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin) == 1) && (globalVars.calismaSekli == 0)) {
        	globalVars.cerceveVar = 0;
        }

        if (globalVars.emniyetCercevesi == 1 && globalVars.calismaSekli == 1) {
            if (HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin) == 0) {
            	globalVars.cerceveVar = 1;
            } else {
            	globalVars.cerceveVar = 0;
            }
        }

        // Asagi calisma
        if ((globalVars.menuGiris == 0) && (globalVars.stopVar) && (globalVars.kapiSivicVar)
            && ((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin) == 0) || (globalVars.basgondercalisasagi))
            && (globalVars.cerceveVar) && (globalVars.emniyetCercevesihatasi == 0)
            && ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 0) || !(globalVars.altLimit))
            && (((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin) == 1)) || (globalVars.asagivalfcalisiyor))
            && (globalVars.yukarimotorcalisiyor == 0)
            && (globalVars.yukarivalfcalisiyor == 0)
            && (globalVars.devmotoryukaricalisiyor == 0)
            && (globalVars.devmotorasagicalisiyor == 0)
            && (globalVars.devyukarivalfcalisiyor == 0)
            && (globalVars.devasagivalfcalisiyor == 0)) {
            HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_SET);
            globalVars.asagivalfcalisiyor = 1;
            globalVars.CalismaSayisiAsagi = 1;
            globalVars.cercevesasagicalisma = 1;
        }

        // asagi valf timer calisması

        if ((globalVars.asagivalfcalisiyor == 1) && (((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin) == 1) && (globalVars.basgondercalisasagi == 0)) || ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 1) && (globalVars.altLimit))) && (globalVars.stopVar) && (globalVars.kapiSivicVar) && (globalVars.cerceveVar) && (globalVars.butonKontrol2 == 0)) {
        	globalVars.timer2 = globalVars.millis;
            globalVars.butonKontrol2 = 1;
        }

        if (((globalVars.millis - globalVars.timer2 >= globalVars.asagiValfTmr) && (globalVars.butonKontrol2 == 1)) || ((globalVars.stopVar == 0) || (globalVars.kapiSivicVar == 0) || (globalVars.cerceveVar == 0))) {
            HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
            globalVars.asagivalfcalisiyor = 0;
            globalVars.butonKontrol2 = 0;
        }

        // yavaslama valf

        if ((globalVars.asagivalfcalisiyor == 1) && (((HAL_GPIO_ReadPin(yavaslamaLimitIn_GPIO_Port, yavaslamaLimitIn_Pin) == 0)) && (globalVars.yavaslamaLimit))) { /* ikinci hız */
            HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
        }

        /* DEVIRME veya YURUYUS Baslangic */

        // Devirme Yukari veya yuruyus ileri calisma
        if ((globalVars.menuGiris == 0)
            && ((globalVars.devirmeYuruyusSecim == 1) || (globalVars.devirmeYuruyusSecim == 2))
            && (globalVars.stopVar) && (globalVars.kapiSivicVar)
            && (HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin) == 0)
            && ((HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin) == 0) || !(globalVars.devirmeYukariIleriLimit))
            && (((HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin) == 1)) || (globalVars.devmotoryukaricalisiyor))
            && (globalVars.yukarimotorcalisiyor == 0)
            && (globalVars.yukarivalfcalisiyor == 0)
            && (globalVars.asagivalfcalisiyor == 0)
            && (globalVars.devmotorasagicalisiyor == 0)
            && (globalVars.devasagivalfcalisiyor == 0)) {
        	globalVars.devmotoryukaricalisiyor = 1;
        } else {
        	globalVars.devmotoryukaricalisiyor = 0;
        }

        if (globalVars.devmotoryukaricalisiyor == 1) {
            HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_SET);
            globalVars.devyukarivalfcalisiyor = 1;
        }
        // devirme yukari + yuruyus ileri valf timer calismasi

        if ((globalVars.devyukarivalfcalisiyor == 1) && ((HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin) == 1) || (HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin) == 1)) && (globalVars.stopVar) && (globalVars.kapiSivicVar) && (globalVars.butonKontrol4 == 0)) {
        	globalVars.timer2 = globalVars.millis;
            globalVars.butonKontrol4 = 1;
        }

        if (((globalVars.millis - globalVars.timer2 >= globalVars.devirmeYukariIleriTmr) && (globalVars.butonKontrol4 == 1)) || ((globalVars.stopVar == 0) || (globalVars.kapiSivicVar == 0))) {
            HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
            globalVars.devyukarivalfcalisiyor = 0;
            globalVars.butonKontrol4 = 0;
        }

        // Devirme Asagi veya yuruyus geri calisma

        if ((globalVars.menuGiris == 0)
            && ((globalVars.devirmeYuruyusSecim == 1) || (globalVars.devirmeYuruyusSecim == 2))
            && (globalVars.stopVar) && (globalVars.kapiSivicVar)
            && (HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin) == 0)
            && ((HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin) == 0) || !(globalVars.devirmeAsagiGeriLimit))
            && (((HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin) == 1)) || (globalVars.devmotorasagicalisiyor))
            && (globalVars.yukarimotorcalisiyor == 0)
            && (globalVars.yukarivalfcalisiyor == 0)
            && (globalVars.asagivalfcalisiyor == 0)
            && (globalVars.devyukarivalfcalisiyor == 0)
            && (globalVars.devmotoryukaricalisiyor == 0)) {
        	globalVars.devmotorasagicalisiyor = 1;
        } else {
        	globalVars.devmotorasagicalisiyor = 0;
        }

        if (globalVars.devmotorasagicalisiyor == 1) {
            HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_SET);
            globalVars.devasagivalfcalisiyor = 1;
        }

        // devirme asagi + geri valf timer calismasi

        if ((globalVars.devasagivalfcalisiyor == 1) && ((HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin) == 1) || (HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin) == 1)) && (globalVars.stopVar) && (globalVars.kapiSivicVar) && (globalVars.butonKontrol5 == 0)) {
        	globalVars.timer2 = globalVars.millis;
            globalVars.butonKontrol5 = 1;
        }

        if (((globalVars.millis - globalVars.timer2 >= globalVars.devirmeYukariIleriTmr) && (globalVars.butonKontrol5 == 1)) || ((globalVars.stopVar == 0) || (globalVars.kapiSivicVar == 0))) {
            HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
            globalVars.devasagivalfcalisiyor = 0;
            globalVars.butonKontrol5 = 0;
        }

        // makine durum kontrolü

        if (HAL_GPIO_ReadPin(motorOut_GPIO_Port, motorOut_Pin) == 0
            && (HAL_GPIO_ReadPin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin) == 0)
            && (HAL_GPIO_ReadPin(yukariValfOut_GPIO_Port, yukariValfOut_Pin) == 0)
            && (HAL_GPIO_ReadPin(asagiValfOut_GPIO_Port, asagiValfOut_Pin) == 0)
            && (HAL_GPIO_ReadPin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin) == 0)) {
        	globalVars.makineStop = 1;
        } else {
        	globalVars.makineStop = 0;
        }

        // kapi 1 kontrol

        // kapi 1 prudhome
        if ((globalVars.kapi1Tip == 0) && ((globalVars.kapiSecimleri == 1) || (globalVars.kapiSecimleri == 3))
            && ((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin) == 0 && (globalVars.kapiAcTipi == 0)) || (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin) == 0 && (globalVars.kapiAcTipi == 1)))
            && ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 1) || !(globalVars.altLimit))
            && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 0)
            && (globalVars.butonKontrol == 0)
            && (globalVars.makineStop == 1)) {
        	globalVars.kapi1prudhome = 1;
        	globalVars.timer = globalVars.millis;
            bekle();
        }

        if ((globalVars.millis - globalVars.timer >= globalVars.kapi1AcSure) || ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 0) || !(globalVars.altLimit)) || (globalVars.makineStop == 0)) {
        	globalVars.kapi1prudhome = 0;
        }

        // kapi 1 buton kontrol

        if ((globalVars.kapi1Tip == 1) && ((globalVars.kapiSecimleri == 1) || (globalVars.kapiSecimleri == 3))

            && ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 1) || !(globalVars.altLimit))
            && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 0)
            && ((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin) == 0 && (globalVars.kapiAcTipi == 0)) || (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin) == 0 && (globalVars.kapiAcTipi == 1)))
            && (globalVars.makineStop == 1)) {
        	globalVars.kapi1butonkontrol = 1;
        } else {
        	globalVars.kapi1butonkontrol = 0;
        }

        // kapi 1 pizzato

        if ((globalVars.kapi1Tip == 2) && ((globalVars.kapiSecimleri == 1) || (globalVars.kapiSecimleri == 3))

            && ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 1) || !(globalVars.altLimit))
            && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 0)
            && (globalVars.makineStop == 1)) {
        	globalVars.kapi1pizzato = 1;
        } else {
        	globalVars.kapi1pizzato = 0;
        }

        // kapi 1 çıkış

        if (globalVars.kapi1butonkontrol == 1 || globalVars.kapi1pizzato == 1 || globalVars.kapi1prudhome == 1) {
            HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
        }

        // kapi2 kontrol

        // kapi 2 prudhome

        if ((globalVars.kapi2Tip == 0) && ((globalVars.kapiSecimleri == 1) || (globalVars.kapiSecimleri == 3))
            && ((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin) == 0 && (globalVars.kapiAcTipi == 0)) || (HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 0 && (globalVars.kapiAcTipi == 1)))
            && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 0)
            && (globalVars.makineStop == 1)
            && (globalVars.butonKontrol == 0)) {
        	globalVars.kapi2prudhome = 1;
        	globalVars.timer = globalVars.millis;
            bekle();
        }

        if ((globalVars.millis - globalVars.timer >= globalVars.kapi2AcSure) || (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 0) || (globalVars.makineStop == 0)) {
        	globalVars.kapi2prudhome = 0;
        }

        // kapi 2 buton kontrol

        if ((globalVars.kapi2Tip == 1) && ((globalVars.kapiSecimleri == 1) || (globalVars.kapiSecimleri == 3))

            && ((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin) == 0 && (globalVars.kapiAcTipi == 0)) || (HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 0 && (globalVars.kapiAcTipi == 1)))
            && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 0)
            && (globalVars.makineStop == 1)) {
        	globalVars.kapi2butonkontrol = 1;
        } else {
        	globalVars.kapi2butonkontrol = 0;
        }

        // kapi 2 pizzato

        if ((globalVars.kapi2Tip == 2) && ((globalVars.kapiSecimleri == 1) || (globalVars.kapiSecimleri == 3))
            && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 0)
            && (globalVars.makineStop == 1)) {
        	globalVars.kapi2pizzato = 1;
        } else {
        	globalVars.kapi2pizzato = 0;
        }

        // kapi 2 çıkış

        if (globalVars.kapi2butonkontrol == 1 || globalVars.kapi2pizzato == 1 || globalVars.kapi2prudhome == 1) {
            HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
        }

        // kapi tabla kontrol ***

        if ((globalVars.kapiTablaAcKonum == 0 || globalVars.kapiTablaAcKonum == 2)
            && ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 1) || !(globalVars.altLimit))
            && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 0)) {
        	globalVars.kapiTablaAcKonumKat1 = 1;
        } else {
        	globalVars.kapiTablaAcKonumKat1 = 0;
        }

        if ((globalVars.kapiTablaAcKonum == 1 || globalVars.kapiTablaAcKonum == 2)
            && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 0)) {
        	globalVars.kapiTablaAcKonumKat2 = 1;
        } else {
        	globalVars.kapiTablaAcKonumKat2 = 0;
        }

        if (globalVars.kapiTablaAcKonumKat1 == 1
            && globalVars.kapiAcTipi == 1
            && HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin) == 0) {
        	globalVars.kapiactablaesp1 = 1;
        } else {
        	globalVars.kapiactablaesp1 = 0;
        }

        if (globalVars.kapiTablaAcKonumKat2 == 1
            && globalVars.kapiAcTipi == 1
            && HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 0) {
        	globalVars.kapiactablaesp2 = 1;
        } else {
        	globalVars.kapiactablaesp2 = 0;
        }

        // tabla kapısı prudhome

        if ((globalVars.kapitablaTip == 0) && ((globalVars.kapiSecimleri == 2) || (globalVars.kapiSecimleri == 3))
            && ((globalVars.kapiTablaAcKonumKat1 == 1) || (globalVars.kapiTablaAcKonumKat2 == 1))
            && (((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin) == 0) && (globalVars.kapiAcTipi == 0))
            || (globalVars.kapiactablaesp1) == 1 || (globalVars.kapiactablaesp2) == 1)
            && (globalVars.makineStop == 1)
            && (globalVars.butonKontrol == 0)) {

        	globalVars.kapiTablaprudhome = 1;
        	globalVars.timer = globalVars.millis;
            bekle();
        }

        if ((globalVars.millis - globalVars.timer >= globalVars.kapiTablaAcSure) || ((globalVars.kapiTablaAcKonumKat1 == 0) && (globalVars.kapiTablaAcKonumKat2 == 0)) || (globalVars.makineStop == 0)) {
        	globalVars.kapiTablaprudhome = 0;
        }

        // tabla kapı buton kontrol

        if ((globalVars.kapitablaTip == 1) && ((globalVars.kapiSecimleri == 2) || (globalVars.kapiSecimleri == 3))

            && ((globalVars.kapiTablaAcKonumKat1 == 1) || (globalVars.kapiTablaAcKonumKat2 == 1))
            && (((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin) == 0) && (globalVars.kapiAcTipi == 0))
            || (globalVars.kapiactablaesp1) == 1 || (globalVars.kapiactablaesp2) == 1)
            && (globalVars.makineStop == 1)) {
        	globalVars.kapiTablabutonkontrol = 1;
        } else {
        	globalVars.kapiTablabutonkontrol = 0;
        }

        // tabla kapı pizzato

        if ((globalVars.kapitablaTip == 2) && ((globalVars.kapiSecimleri == 2) || (globalVars.kapiSecimleri == 3))
            && ((globalVars.kapiTablaAcKonumKat1 == 1) || (globalVars.kapiTablaAcKonumKat2 == 1))
            && (globalVars.makineStop == 1)) {
        	globalVars.kapiTablapizzato = 1;
        } else { /* if ((kapitablaTip == 1) && ((kapiSecimleri == 2) || (kapiSecimleri == 3))) */
        	globalVars.kapiTablapizzato = 0;
        }

        // kapi Tabla çıkış

        if (globalVars.kapiTablabutonkontrol == 1 || globalVars.kapiTablaprudhome == 1 || globalVars.kapiTablapizzato == 1) {
            HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
        }

        /********************************* CALİSMA SAYISI KAYIT YERİ *************************************/

        if (((globalVars.CalismaSayisiYukari == 1) && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1) && (globalVars.altLimit == 0) && (globalVars.makineStop == 1))
            || ((globalVars.CalismaSayisiAsagi == 1) && ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 1) && (globalVars.altLimit)) && (globalVars.makineStop == 1))) {
            globalVars.calismaSayisi1 = globalVars.calismaSayisi1 + 1;
            if (globalVars.calismaSayisi1 > 9) {
                globalVars.calismaSayisi1 = 0;
                globalVars.calismaSayisi10 = globalVars.calismaSayisi10 + 1;
            }
            if (globalVars.calismaSayisi10 > 9) {
                globalVars.calismaSayisi10 = 0;
                globalVars.calismaSayisi100 = globalVars.calismaSayisi100 + 1;
            }
            if (globalVars.calismaSayisi100 > 9) {
                globalVars.calismaSayisi100 = 0;
                globalVars.calismaSayisi1000 = globalVars.calismaSayisi1000 + 1;
            }
            if (globalVars.calismaSayisi1000 > 9) {
                globalVars.calismaSayisi1000 = 0;
                globalVars.calismaSayisi10000 = globalVars.calismaSayisi10000 + 1;
            }
            globalVars.eepromData[32] = globalVars.calismaSayisi10000;
            globalVars.eepromData[31] = globalVars.calismaSayisi1000;
            globalVars.eepromData[30] = globalVars.calismaSayisi100;
            globalVars.eepromData[29] = globalVars.calismaSayisi10;
            globalVars.eepromData[28] = globalVars.calismaSayisi1;

            globalVars.hafizaYaz = 1;

            globalVars.CalismaSayisiYukari = 0;
            globalVars.CalismaSayisiAsagi = 0;
        }

        /******************************************* HATA BASLIYOR *******************************************/

        /************************************ ACİL STOP HATA BASLANGICI **************************************************/
        if ((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 0
            || HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin) == 0
            || HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin) == 0
            || HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin) == 0)) {
        	globalVars.startBasili = 1;
        } else {
        	globalVars.startBasili = 0;
        }


        if (globalVars.startBasili && HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin) == 1) {
        	globalVars.hataVar = 1;
        	errorProcess.hataKoduLcdGoster(1);
        	errorProcess.hata2EEPROM(1);
            wifiProcess.convertAndSendData();
            globalVars.acilstophatasi = 1;
        } else if (globalVars.acilstophatasi && HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin) == 0 && globalVars.startBasili == 0) {
        	globalVars.acilstophatasi = 0;
            lcdUpdate(1);
        }

        /************************************ Emniyet Çerçevesi Hatasi ***************************************************/

        if (globalVars.cerceveVar == 0 && (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin) == 0 || globalVars.cercevesasagicalisma) && (globalVars.emniyetCercevesi == 1)) {
        	globalVars.hataVar = 1;
        	errorProcess.hataKoduLcdGoster(2);
        	errorProcess.hata2EEPROM(2);
            wifiProcess.convertAndSendData();
            globalVars.emniyetCercevesihatasi = 1;
        } else if (globalVars.emniyetCercevesihatasi && globalVars.cerceveVar == 1 && globalVars.asagivalfcalisiyor == 0) {
        	globalVars.emniyetCercevesihatasi = 0;
        	globalVars.cercevesasagicalisma = 0;
            lcdUpdate(2);
        }

        /************************************ BASINC ASIRI YUK HATASI **************************************************/

        if (globalVars.basincVar == 0 && globalVars.basincSalteri == 1 && globalVars.motorcalisiyor == 1 && HAL_GPIO_ReadPin(basincSalteriIn_GPIO_Port, basincSalteriIn_Pin) == 1) {
        	globalVars.hataVar = 1;
        	errorProcess.hataKoduLcdGoster(3);
            errorProcess.hata2EEPROM(3);
            wifiProcess.convertAndSendData();
            globalVars.basinchatasi = 1;
        } else if (globalVars.basinchatasi && globalVars.basincVar == 1 && HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin) == 1) {
        	globalVars.basinchatasi = 0;
            lcdUpdate(3);
        }

        /************************************ KAPI SİVİÇ HATASI **************************************************/
        if ((globalVars.startBasili || globalVars.HataMakineCalisiyorkapi) && HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin) == 1 && (globalVars.kapiSecimleri == 1 || globalVars.kapiSecimleri == 3)) {
        	globalVars.hataVar = 1;
        	errorProcess.hataKoduLcdGoster(4);
            errorProcess.hata2EEPROM(4);
            wifiProcess.convertAndSendData();
            globalVars.katkapisivicihatasi = 1;
        } else if (globalVars.katkapisivicihatasi && globalVars.makineStop && globalVars.startBasili == 0 && HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin) == 0) {
        	globalVars.katkapisivicihatasi = 0;
        	globalVars.HataMakineCalisiyorkapi = 0;
            lcdUpdate(4);
        }

        /************************************ TABLA KAPI SİVİÇ HATASI **************************************************/

        if ((globalVars.startBasili || globalVars.HataMakineCalisiyortabla) && HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin) == 1 && (globalVars.kapiSecimleri == 1 || globalVars.kapiSecimleri == 3)) {
        	globalVars.hataVar = 1;
        	errorProcess.hataKoduLcdGoster(5);
        	errorProcess.hata2EEPROM(5);
            wifiProcess.convertAndSendData();
            globalVars.tablakapisivicihatasi = 1;
        } else if (globalVars.tablakapisivicihatasi && globalVars.makineStop && globalVars.startBasili == 0 && HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin) == 0 && globalVars.makineStop == 1) {
        	globalVars.tablakapisivicihatasi = 0;
        	globalVars.HataMakineCalisiyortabla = 0;
            lcdUpdate(5);
        }

        /************************************ MAX CALİSMA HATASI BASLANGIC ******************************************/

        if ((globalVars.motorcalisiyor) || (globalVars.asagivalfcalisiyor) || (globalVars.devmotorasagicalisiyor)) {
            if (globalVars.millis - globalVars.timer4 >= globalVars.makineCalismaTmr) {
            	globalVars.hataVar = 1;
            	errorProcess.hataKoduLcdGoster(6);
            	errorProcess.hata2EEPROM(6);
                wifiProcess.convertAndSendData();
                globalVars.maksimumcalismahatasi = 1;
            }
        }

        if (globalVars.maksimumcalismahatasi && HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) && globalVars.startBasili == 0) {
        	globalVars.maksimumcalismahatasi = 0;
            lcdUpdate(6);
        }

        if ((globalVars.yukarimotorcalisiyor == 1) || (globalVars.asagivalfcalisiyor == 1) || (globalVars.devmotoryukaricalisiyor == 1) || (globalVars.devmotorasagicalisiyor == 1)) {
        	globalVars.makineCalisiyor = 0;
        	globalVars.HataMakineCalisiyorkapi = 1;
        	globalVars.HataMakineCalisiyortabla = 1;
        } else {
        	globalVars.makineCalisiyor = 1;
        	globalVars.timer4 = globalVars.millis;
        }

        /*********************************** HATA YOKSA HATA VAR SIFIRLA **************************************************/
        if (globalVars.hataVar == 1 && globalVars.acilstophatasi == 0 && globalVars.emniyetCercevesihatasi == 0 && globalVars.basinchatasi == 0
            && globalVars.katkapisivicihatasi == 0 && globalVars.tablakapisivicihatasi == 0 && globalVars.maksimumcalismahatasi == 0) {
        	globalVars.hataVar = 0;
            lcdUpdate(7);
        }

        /************************************ HATA LCD GÖSTERME ************************************************************/
    } // aktif calisma son parantez.
}

void Process::checkDemoModCalisma() {
    if ((globalVars.demoMode == 1) && (globalVars.stopVar) && (globalVars.menuGiris == 0)) {

        if ((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 0)
            && (globalVars.demoAsagiCalis == 0)
            && (globalVars.demoDevYukari == 0)
            && (globalVars.demoDevAsagi == 0)) {

            HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_SET);
            globalVars.demoYukariCalis = 1;
        } else if (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1) {

            HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
            globalVars.demoYukariCalis = 0;
        }

        // DEMO MOTOR CALISMASI

        if ((globalVars.demoYukariCalis) || (globalVars.demoDevYukari) || (globalVars.demoDevAsagi) || (globalVars.demoAsagiCalis)) {
            HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
        }

        if ((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin) == 0)
            && (globalVars.demoYukariCalis == 0)
            && (globalVars.demoAsagiCalis == 0)) {
            // bos burası
        }

        // DEVİRME YUKARI CALIS
        if ((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin) == 0)
            && (globalVars.demoYukariCalis == 0)
            && (globalVars.demoAsagiCalis == 0)
            && (globalVars.demoDevAsagi == 0)) {

            HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_SET);
            globalVars.demoDevYukari = 1;
        } else {
            HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
            globalVars.demoDevYukari = 0;
        }

        // DEVIRME ASAGI CALIS

        if ((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1)
            && (HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin) == 0)
            && (globalVars.demoYukariCalis == 0)
            && (globalVars.demoDevYukari == 0)
            && (globalVars.demoAsagiCalis == 0)) {

            HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_SET);
            globalVars.demoDevAsagi = 1;
        } else {
            HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
            globalVars.demoDevAsagi = 0;
        }

        // DEMO ASAGI CALISMA

        if ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 0)
            && (globalVars.demoYukariCalis == 0)
            && (globalVars.demoDevAsagi == 0)
            && (globalVars.demoDevYukari == 0)) {

            HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_SET);
            globalVars.demoAsagiCalis = 1;
            globalVars.demoCalismaSayisiYar = 1;
        } else if ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 1)) {
            HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
            globalVars.demoAsagiCalis = 0;
        }

        if (HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin) == 1) {
            HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
            globalVars.timer3 = globalVars.millis;
        }

        if (globalVars.millis - globalVars.timer3 >= 5) {
            HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
        }

        if (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin) == 1) {
            HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
            globalVars.timer3 = globalVars.millis;
        }

        if (globalVars.millis - globalVars.timer3 >= 5) {
            HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
        }

        if ((globalVars.demoYukariCalis == 1) && (globalVars.demoCalismaSayisiYar == 1)) {
            // mesajYazildi = 0;
            globalVars.calismaSayisi1 = globalVars.calismaSayisi1 + 1;

            if (globalVars.calismaSayisi1 > 9) {
                globalVars.calismaSayisi1 = 0;
                globalVars.calismaSayisi10 = globalVars.calismaSayisi10 + 1;
            }

            if (globalVars.calismaSayisi10 > 9) {
                globalVars.calismaSayisi10 = 0;
                globalVars.calismaSayisi100 = globalVars.calismaSayisi100 + 1;
            }

            if (globalVars.calismaSayisi100 > 9) {
                globalVars.calismaSayisi100 = 0;
                globalVars.calismaSayisi1000 = globalVars.calismaSayisi1000 + 1;
            }

            if (globalVars.calismaSayisi1000 > 9) {
                globalVars.calismaSayisi1000 = 0;
                globalVars.calismaSayisi10000 = globalVars.calismaSayisi10000 + 1;
            }
            globalVars.eepromData[32] = globalVars.calismaSayisi10000;
            globalVars.eepromData[31] = globalVars.calismaSayisi1000;
            globalVars.eepromData[30] = globalVars.calismaSayisi100;
            globalVars.eepromData[29] = globalVars.calismaSayisi10;
            globalVars.eepromData[28] = globalVars.calismaSayisi1;
            globalVars.hafizaYaz = 1;
            // mesajYazildi = 0;
            globalVars.demoCalismaSayisiYar = 0;
        }

        if (globalVars.menuGiris == 0) {
            lcd.print(1, 1, translation.demoModTextGN.data());
            lcd.print(2, 1, translation.cycleTextGN.data());
            itoa(globalVars.calismaSayisi10000, globalVars.snum.data(), 10);
            lcd.print(2, 12, globalVars.snum.data());
            itoa(globalVars.calismaSayisi1000, globalVars.snum.data(), 10);
            lcd.print(2, 13, globalVars.snum.data());
            itoa(globalVars.calismaSayisi100, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
            itoa(globalVars.calismaSayisi10, globalVars.snum.data(), 10);
            lcd.print(2, 15, globalVars.snum.data());
            itoa(globalVars.calismaSayisi1, globalVars.snum.data(), 10);
            lcd.print(2, 16, globalVars.snum.data());
            globalVars.mesajYazildi = 1;
        }
    } else if (globalVars.demoMode == 1 || globalVars.menuGiris == 1) {
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
        // HAL_GPIO_WritePin(buzzerOut_GPIO_Port, buzzerOut_Pin, GPIO_PIN_RESET);
    }
}

void Process::mainLoop() {
    while (1) {
        checkLCDBacklight();

        if ((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 0) && (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 0) && (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 0) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 0) && (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 0) && (HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin) == 1) && (HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin) == 1) && (HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin) == 1)) {
            globalVars.butonKontrol = 0;
        } else {
        	globalVars.backLightTimer = globalVars.millis;
        }

        if (buttonCheck() == 1) {
        	globalVars.backLightTimer = globalVars.millis;
        }

        if (globalVars.hafizaYaz == 1) {
            while (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
            while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);

            HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, globalVars.eepromData.data(), 110, 3000);
            HAL_Delay(500);

            globalVars.hafizaYaz = 0;
            lcd.print(2, 1, textVars.dataYazildiText.data());

            HAL_Delay(1000);
            lcd.clear();
        }

        if ((globalVars.hafizaOku == 0) && (HAL_I2C_GetState(&hi2c1) == HAL_I2C_STATE_READY)) {
            if (globalVars.ilkOkuma == 0) {
                lcd.print(1, 1, translation.eepromTextGN.data());
                lcd.print(2, 1, textVars.dataOkunuyorText.data());
                HAL_Delay(1000);

                while (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
                while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY) {
                    HAL_Delay(1000);
                }

                lcd.print(2, 1, textVars.dataOkunduText.data());

                globalVars.ilkOkuma = 1;
            } else {
                lcd.print(2, 1, textVars.degerKaydedildiText.data());
                lcd.clear();
            }

            lcd.clear();

            eepromProcess.eepromKontrol();
            globalVars.hafizaOku = 1;
        }

        if ((globalVars.menuGiris == 0) && (globalVars.mesajYazildi == 0) && (globalVars.demoMode == 0)) {
            lcd.clear();
            HAL_Delay(10);
            lcd.print(1, 1, translation.mainTextGN.data());
            lcd.print(2, 1, translation.mainText2GN.data());
            globalVars.mesajYazildi = 1;
        }

        if ((globalVars.menuGiris == 0) && (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1)) {
        	globalVars.menuGiris = 1;
            lcd.clear();
        }

        if (globalVars.menuGiris == 1) {
            menu();
        }

        HAL_GPIO_TogglePin(cycleLed_GPIO_Port, cycleLed_Pin);

        /* GİRİLEN PARAMETRELERE GÖRE AYARLARIN YAPILMASI */

        if (HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin) == 0 && globalVars.hataVar == 0) {
            globalVars.stopVar = 1;
        } else {
        	globalVars.stopVar = 0;
        }

        /****************************************  BASINC SALTERI ********************************************/
        checkBasincSalteri();

        /******** Bas gönder ***********/
        checkBasGonder();

        /******** Kapı Secimleri ***********/
        checkKapiSecimleri();

        /* PARAMETRELERE GÖRE ÇIKISLARIN AYARLANMASI */
        /* MOTOR CALISIYOR */
        checkAktifCalisma();

        // DEMO MOD BASLIYOR
        // DEMO YUKARI CALISMA
        checkDemoModCalisma();
    }
}
