/*
 * Menu.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#include "Menu.h"

#include "Instance.h"
#include "main.h"

namespace {
    void handleMenuIncrease();
    void handleMenuDecrease();
    void displayMenuContent();

    // Helper functions for specific menu cases
    void displayErrorLog();
    void displayOperatingMode();
    void displaySafetyFrame();
    void displaySlowdownLimit();
    void displayLowerLimit();
    void displayPressureSwitch();
    void displayDoorSelections();
    void displayDoorOpeningType();
    void displayFirstFloorDoorType();
    void displayFirstFloorDoorOpenTime();
    void displaySecondFloorDoorType();
    void displaySecondFloorDoorOpenTime();
    void displayPlatformDoorType();
    void displayPlatformDoorOpenPosition();
    void displayPlatformDoorOpenTime();
    void displayUpperSlowdownLimit();
    void displayTippingWalkingMenu();
    void displayTippingWalkingSwitch();
    void displayTippingWalkingReturnSwitch();
    void displayCylinderType();
    void displayPlatformCylinderType();
    void displayUpperValveTime();
    void displayLowerValveTime();
    void displayForwardValveTime();
    void displayBackwardValveTime();
    void displayOperatingTime();
    void displayBuzzer();
    void displayDemoMode();
    void displayOperatingCount();
    void displayLanguageSelection();
    void displayIoTMode();
    void displayMachineID();
    void displayWifiSSID();
    void displayWifiPassword();
    void displayExitMenu();

    void clearEEPROMData(int start, int length);
}

void menu() {
    if ((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        handleMenuIncrease();
    }

    if ((HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        handleMenuDecrease();
    }

    displayMenuContent();
}

namespace {
    void handleMenuIncrease() {
        globalVars.menuSayac++;
        if (globalVars.menuSayac == 36) {
            globalVars.menuSayac = 1;
        }

        if ((globalVars.menuSayac == 18) && (globalVars.devirmeYuruyusSecim == 0)) {
            globalVars.menuSayac = 21;
        }

        if ((globalVars.menuSayac == 8) && (globalVars.kapiSecimleri == 0)) {
            globalVars.menuSayac = 16;
        }

        if ((globalVars.menuSayac == 13) && (globalVars.kapiSecimleri == 1)) {
            globalVars.menuSayac = 16;
        }

        if ((globalVars.menuSayac == 9) && (globalVars.kapiSecimleri == 2)) {
            globalVars.menuSayac = 13;
        }

        if ((globalVars.menuSayac == 10) && ((globalVars.kapi1Tip == 1) || (globalVars.kapi1Tip == 2))) {
            globalVars.menuSayac = 11;
        }

        if ((globalVars.menuSayac == 12) && ((globalVars.kapi2Tip == 1) || (globalVars.kapi2Tip == 2)) && (globalVars.kapiSecimleri == 1)) {
            globalVars.menuSayac = 16;
        }

        if ((globalVars.menuSayac == 12) && ((globalVars.kapi2Tip == 1) || (globalVars.kapi2Tip == 2)) && (globalVars.kapiSecimleri == 3)) {
            globalVars.menuSayac = 13;
        }

        if ((globalVars.menuSayac == 15) && (globalVars.kapitablaTip == 1)) {
            globalVars.menuSayac = 16;
        }

        if ((globalVars.menuSayac == 24) && (globalVars.devirmeYuruyusSecim == 0)) {
            globalVars.menuSayac = 26;
        }

        if (globalVars.menuSayac == 33 && globalVars.iotMode == 0) {
            globalVars.menuSayac = 35;
        }

        process.bekle();
    }

    void handleMenuDecrease() {
        if (globalVars.menuSayac <= 1) {
            globalVars.menuSayac = 36;
        }

        globalVars.menuSayac--;

        if ((globalVars.menuSayac == 20) && (globalVars.devirmeYuruyusSecim == 0)) {
            globalVars.menuSayac = 17;
        }

        if ((globalVars.menuSayac == 15) && (globalVars.kapiSecimleri == 0)) {
            globalVars.menuSayac = 7;
        }

        if ((globalVars.menuSayac == 15) && (globalVars.kapiSecimleri == 1)) {
            globalVars.menuSayac = 12;
        }

        if ((globalVars.menuSayac == 12) && (globalVars.kapiSecimleri == 2)) {
            globalVars.menuSayac = 8;
        }

        if ((globalVars.menuSayac == 10) && ((globalVars.kapi1Tip == 1) || (globalVars.kapi1Tip == 2))) {
            globalVars.menuSayac = 9;
        }

        if ((globalVars.menuSayac == 12) && ((globalVars.kapi2Tip == 1) || (globalVars.kapi2Tip == 2))) {
            globalVars.menuSayac = 11;
        }

        if ((globalVars.menuSayac == 15) && (globalVars.kapitablaTip == 1)) {
            globalVars.menuSayac = 14;
        }

        if ((globalVars.menuSayac == 25) && (globalVars.devirmeYuruyusSecim == 0)) {
            globalVars.menuSayac = 23;
        }

        if (globalVars.menuSayac == 34 && globalVars.iotMode == 0) {
            globalVars.menuSayac = 32;
        }

        process.bekle();
    }

    void displayMenuContent() {
        switch (globalVars.menuSayac) {
            case 0:
                lcd.print(1, 1, textVars.menuyeGirildiText.data());
                lcd.print(2, 1, textVars.ayarlarText.data());
                break;
            case 1:
                displayErrorLog();
                break;
            case 2:
                displayOperatingMode();
                break;
            case 3:
                displaySafetyFrame();
                break;
            case 4:
                displaySlowdownLimit();
                break;
            case 5:
                displayLowerLimit();
                break;
            case 6:
                displayPressureSwitch();
                break;
            case 7:
                displayDoorSelections();
                break;
            case 8:
                displayDoorOpeningType();
                break;
            case 9:
                displayFirstFloorDoorType();
                break;
            case 10:
                displayFirstFloorDoorOpenTime();
                break;
            case 11:
                displaySecondFloorDoorType();
                break;
            case 12:
                displaySecondFloorDoorOpenTime();
                break;
            case 13:
                displayPlatformDoorType();
                break;
            case 14:
                displayPlatformDoorOpenPosition();
                break;
            case 15:
                displayPlatformDoorOpenTime();
                break;
            case 16:
                displayUpperSlowdownLimit();
                break;
            case 17:
                displayTippingWalkingMenu();
                break;
            case 18:
                displayTippingWalkingSwitch();
                break;
            case 19:
                displayTippingWalkingReturnSwitch();
                break;
            case 20:
                displayCylinderType();
                break;
            case 21:
                displayPlatformCylinderType();
                break;
            case 22:
                displayUpperValveTime();
                break;
            case 23:
                displayLowerValveTime();
                break;
            case 24:
                displayForwardValveTime();
                break;
            case 25:
                displayBackwardValveTime();
                break;
            case 26:
                displayOperatingTime();
                break;
            case 27:
                displayBuzzer();
                break;
            case 28:
                displayDemoMode();
                break;
            case 29:
                displayOperatingCount();
                break;
            case 30:
                displayLanguageSelection();
                break;
            case 31:
                displayIoTMode();
                break;
            case 32:
                displayMachineID();
                break;
            case 33:
                displayWifiSSID();
                break;
            case 34:
                displayWifiPassword();
                break;
            case 35:
                displayExitMenu();
                break;
            default:
                break;
        }
    }

    void displayErrorLog() {
        lcd.print(1, 1, textVars.hataKayitListText.data());

        if (globalVars.hataGostermeSirasi == 0) {
            lcd.print(2, 1, textVars.birHataKoduText.data());
            lcd.print(2, 15, "   ");
            itoa(globalVars.hataKayit1, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
        }

        if (globalVars.hataGostermeSirasi == 1) {
            lcd.print(2, 1, textVars.ikiHataKoduText.data());
            lcd.print(2, 15, "  ");
            itoa(globalVars.hataKayit2, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
        }

        if (globalVars.hataGostermeSirasi == 2) {
            lcd.print(2, 1, textVars.ucHataKoduText.data());
            lcd.print(2, 15, "  ");
            itoa(globalVars.hataKayit3, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
        }

        if (globalVars.hataGostermeSirasi == 3) {
            lcd.print(2, 1, textVars.dortHataKoduText.data());
            lcd.print(2, 15, "  ");
            itoa(globalVars.hataKayit4, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
        }

        if (globalVars.hataGostermeSirasi == 4) {
            lcd.print(2, 1, textVars.besHataKoduText.data());
            lcd.print(2, 15, "  ");
            itoa(globalVars.hataKayit5, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
        }

        if (globalVars.hataGostermeSirasi == 5) {
            lcd.print(2, 1, textVars.altiHataKoduText.data());
            lcd.print(2, 15, "  ");
            itoa(globalVars.hataKayit6, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
        }

        if (globalVars.hataGostermeSirasi == 6) {
            lcd.print(2, 1, textVars.yediHataKoduText.data());
            lcd.print(2, 15, "  ");
            itoa(globalVars.hataKayit7, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
        }

        if (globalVars.hataGostermeSirasi == 7) {
            lcd.print(2, 1, textVars.sekizHataKoduText.data());
            lcd.print(2, 15, "  ");
            itoa(globalVars.hataKayit8, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
        }

        if (globalVars.hataGostermeSirasi == 8) {
            lcd.print(2, 1, textVars.dokuzHataKoduText.data());
            lcd.print(2, 15, "  ");
            itoa(globalVars.hataKayit9, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
        }

        if (globalVars.hataGostermeSirasi == 9) {
            lcd.print(2, 1, textVars.onHataKoduText.data());
            lcd.print(2, 16, " ");
            itoa(globalVars.hataKayit10, globalVars.snum.data(), 10);
            lcd.print(2, 15, globalVars.snum.data());
        }

        if (globalVars.hataGostermeSirasi == 10) {
            lcd.print(2, 1, textVars.silmekIcinText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.devirmeYuruyusSecim == 0)) {
        	globalVars.hataGostermeSirasi++;

            if (globalVars.hataGostermeSirasi > 10) {
            	globalVars.hataGostermeSirasi = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.devirmeYuruyusSecim == 0)) {
        	globalVars.hataGostermeSirasi--;

            if (globalVars.hataGostermeSirasi > 11) {
            	globalVars.hataGostermeSirasi = 10;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0) && globalVars.hataGostermeSirasi == 10) {
            clearEEPROMData(37, 10);
            globalVars.hafizaYaz = 1;
        }
    }

    void displayOperatingMode() {
        lcd.print(1, 1, textVars.calismaSekliText.data());

        if ((globalVars.devirmeYuruyusSecim == 1) || (globalVars.devirmeYuruyusSecim == 2)) {
            lcd.print(2, 1, textVars.devirmeYuruyusText.data());
        }

        if ((globalVars.calismaSekli == 0) && (globalVars.devirmeYuruyusSecim == 0)) {
            lcd.print(2, 1, textVars.bastikcaCalisanText.data());
        }

        if ((globalVars.calismaSekli == 1) && (globalVars.devirmeYuruyusSecim == 0)) {
            lcd.print(2, 1, textVars.basGonderText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.devirmeYuruyusSecim == 0)) {
        	globalVars.calismaSekli++;

            if (globalVars.calismaSekli > 1) {
            	globalVars.calismaSekli = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.devirmeYuruyusSecim == 0)) {
        	globalVars.calismaSekli--;

            if (globalVars.calismaSekli > 0) {
            	globalVars.calismaSekli = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[1] = globalVars.calismaSekli;

            if (globalVars.calismaSekli == 1) {
            	globalVars.altLimit = 1;
            	globalVars.eepromData[5] = globalVars.altLimit;
            }
            globalVars.hafizaYaz = 1;
        }
    }

    void displaySafetyFrame() {
        lcd.print(1, 1, textVars.emniyetCercevesiText.data());

        if (globalVars.emniyetCercevesi == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.emniyetCercevesi == 1) {
            lcd.print(2, 1, translation.ondSafetyTextGN.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.emniyetCercevesi++;

            if (globalVars.emniyetCercevesi > 1) {
            	globalVars.emniyetCercevesi = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.emniyetCercevesi--;

            if (globalVars.emniyetCercevesi > 0) {
            	globalVars.emniyetCercevesi = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[2] = globalVars.emniyetCercevesi;
            globalVars.hafizaYaz = 1;
        }
    }

    void displaySlowdownLimit() {
        lcd.print(1, 1, textVars.yavaslamaLimitText.data());

        if (globalVars.yavaslamaLimit == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.yavaslamaLimit == 1) {
            lcd.print(2, 1, textVars.aktifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.yavaslamaLimit++;

            if (globalVars.yavaslamaLimit > 1) {
            	globalVars.yavaslamaLimit = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.yavaslamaLimit--;

            if (globalVars.yavaslamaLimit > 0) {
            	globalVars.yavaslamaLimit = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[4] = globalVars.yavaslamaLimit;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayLowerLimit() {
        lcd.print(1, 1, textVars.altLimitText.data());

        if (globalVars.altLimit == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.altLimit == 1) {
            lcd.print(2, 1, textVars.aktifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.calismaSekli == 0)) {
        	globalVars.altLimit++;

            if (globalVars.altLimit > 1) {
            	globalVars.altLimit = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0) && globalVars.calismaSekli == 0) {
        	globalVars.altLimit--;

            if (globalVars.altLimit > 0) {
            	globalVars.altLimit = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[5] = globalVars.altLimit;

            if (globalVars.altLimit == 0 && (globalVars.kapiTablaAcKonum == 0 || globalVars.kapiTablaAcKonum == 2)) {
            	globalVars.kapiTablaAcKonum = 3;
            	globalVars.eepromData[34] = globalVars.kapiTablaAcKonum;
            } else if (globalVars.altLimit == 0) {
            	globalVars.platformSilindirTipi = 0;
            	globalVars.eepromData[19] = globalVars.platformSilindirTipi;
            }

            globalVars.hafizaYaz = 1;
        }
    }

    void displayPressureSwitch() {
        lcd.print(1, 1, textVars.basincSalteriText.data());

        if (globalVars.basincSalteri == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.basincSalteri == 1) {
            lcd.print(2, 1, textVars.aktifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.basincSalteri++;

            if (globalVars.basincSalteri > 1) {
            	globalVars.basincSalteri = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.basincSalteri--;

            if (globalVars.basincSalteri > 0) {
            	globalVars.basincSalteri = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[6] = globalVars.basincSalteri;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayDoorSelections() {
        lcd.print(1, 1, textVars.kapiSecimleriText.data());

        if (globalVars.kapiSecimleri == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.kapiSecimleri == 1) {
            lcd.print(2, 1, textVars.katKapisiAktifText.data());
        } else if (globalVars.kapiSecimleri == 2) {
            lcd.print(2, 1, textVars.tablaKapiAktifText.data());
        } else if (globalVars.kapiSecimleri == 3) {
            lcd.print(2, 1, textVars.katArtiTablaAktifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapiSecimleri++;

            if (globalVars.kapiSecimleri > 3) {
            	globalVars.kapiSecimleri = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapiSecimleri--;

            if (globalVars.kapiSecimleri > 4) {
            	globalVars.kapiSecimleri = 3;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[7] = globalVars.kapiSecimleri;

            if (globalVars.kapiSecimleri >= 1) {
            	globalVars.altLimit = 1;
            	globalVars.eepromData[5] = globalVars.altLimit;
            }
            globalVars.hafizaYaz = 1;
        }
    }

    void displayDoorOpeningType() {
        lcd.print(1, 1, textVars.kapiAcmaTipiText.data());

        if (globalVars.kapiAcTipi == 0) {
            lcd.print(2, 1, textVars.kapiButonuESPText.data());
        } else if (globalVars.kapiAcTipi == 1) {
            lcd.print(2, 1, textVars.katButonuEXTText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapiAcTipi++;

            if (globalVars.kapiAcTipi > 1) {
            	globalVars.kapiAcTipi = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapiAcTipi--;

            if (globalVars.kapiAcTipi > 0) {
            	globalVars.kapiAcTipi = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[36] = globalVars.kapiAcTipi;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayFirstFloorDoorType() {
        lcd.print(1, 1, textVars.birKatKapiTipiText.data());

        if (globalVars.kapi1Tip == 0) {
            lcd.print(2, 1, translation.prudhomeTextGN.data());
        } else if (globalVars.kapi1Tip == 1) {
            lcd.print(2, 1, textVars.butonKontrolluText.data());
        } else if (globalVars.kapi1Tip == 2) {
            lcd.print(2, 1, translation.pizzattoTextGN.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapi1Tip++;

            if (globalVars.kapi1Tip > 2) {
            	globalVars.kapi1Tip = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapi1Tip--;

            if (globalVars.kapi1Tip > 3) {
            	globalVars.kapi1Tip = 2;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[8] = globalVars.kapi1Tip;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayFirstFloorDoorOpenTime() {
        lcd.print(1, 1, textVars.birinciKapiAcSuresiText.data());
        lcd.print(2, 1, textVars.kacSaniyeText.data());

        itoa(globalVars.kapi1AcSure, globalVars.snum.data(), 10);
        lcd.print(2, 16, globalVars.snum.data());

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.kapi1Tip == 0)) {
        	globalVars.kapi1AcSure++;

            if (globalVars.kapi1AcSure > 5) {
            	globalVars.kapi1AcSure = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.kapi1Tip == 0)) {
        	globalVars.kapi1AcSure--;

            if (globalVars.kapi1AcSure > 6) {
            	globalVars.kapi1AcSure = 5;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[9] = globalVars.kapi1AcSure;
            globalVars.hafizaYaz = 1;
        }
    }

    void displaySecondFloorDoorType() {
        lcd.print(1, 1, textVars.ikinciKatKapiTipiText.data());

        if (globalVars.kapi2Tip == 0) {
            lcd.print(2, 1, translation.prudhomeTextGN.data());
        } else if (globalVars.kapi2Tip == 1) {
            lcd.print(2, 1, textVars.butonKontrolluText.data());
        } else if (globalVars.kapi2Tip == 2) {
            lcd.print(2, 1, translation.pizzattoTextGN.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapi2Tip++;

            if (globalVars.kapi2Tip > 2) {
            	globalVars.kapi2Tip = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapi2Tip--;

            if (globalVars.kapi2Tip > 3) {
            	globalVars.kapi2Tip = 2;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[10] = globalVars.kapi2Tip;
            globalVars.hafizaYaz = 1;
        }
    }

    void displaySecondFloorDoorOpenTime() {
        lcd.print(1, 1, textVars.ikinciKapiAcSuresiText.data());
        lcd.print(2, 1, textVars.kacSaniyeText.data());

        itoa(globalVars.kapi2AcSure, globalVars.snum.data(), 10);
        lcd.print(2, 16, globalVars.snum.data());

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.kapi2Tip == 0)) {
        	globalVars.kapi2AcSure++;

            if (globalVars.kapi2AcSure > 5) {
            	globalVars.kapi2AcSure = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.kapi2Tip == 0)) {
        	globalVars.kapi2AcSure--;

            if (globalVars.kapi2AcSure > 6) {
            	globalVars.kapi2AcSure = 5;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[11] = globalVars.kapi2AcSure;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayPlatformDoorType() {
        lcd.print(1, 1, textVars.tablaKapiTipiText.data());

        if (globalVars.kapitablaTip == 0) {
            lcd.print(2, 1, translation.prudhomeTextGN.data());
        } else if (globalVars.kapitablaTip == 1) {
            lcd.print(2, 1, textVars.butonKontrolluText.data());
        } else if (globalVars.kapitablaTip == 2) {
            lcd.print(2, 1, translation.pizzattoTextGN.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapitablaTip++;

            if (globalVars.kapitablaTip > 2) {
            	globalVars.kapitablaTip = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapitablaTip--;

            if (globalVars.kapitablaTip > 3) {
            	globalVars.kapitablaTip = 2;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[12] = globalVars.kapitablaTip;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayPlatformDoorOpenPosition() {
        lcd.print(1, 1, textVars.tablaKapiAcKonumText.data());

        if (globalVars.kapiTablaAcKonum == 0) {
            lcd.print(2, 1, textVars.birinciKattaAcText.data());
        } else if (globalVars.kapiTablaAcKonum == 1) {
            lcd.print(2, 1, textVars.ikinciKattaAcText.data());
        } else if (globalVars.kapiTablaAcKonum == 2) {
            lcd.print(2, 1, textVars.birVeIkinciKattaAcText.data());
        } else if (globalVars.kapiTablaAcKonum == 3) {
            lcd.print(2, 1, textVars.pasifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapiTablaAcKonum++;

            if (globalVars.kapiTablaAcKonum > 2) {
            	globalVars.kapiTablaAcKonum = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.kapiTablaAcKonum--;

            if (globalVars.kapiTablaAcKonum > 3) {
            	globalVars.kapiTablaAcKonum = 2;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[34] = globalVars.kapiTablaAcKonum;

            if (globalVars.kapiTablaAcKonum == 0 || globalVars.kapiTablaAcKonum == 2) {
            	globalVars.altLimit = 1;
            	globalVars.eepromData[5] = globalVars.altLimit;
            }

            globalVars.hafizaYaz = 1;
        }
    }

    void displayPlatformDoorOpenTime() {
        lcd.print(1, 1, textVars.tablaKapiAcSureText.data());
        lcd.print(2, 1, textVars.kacSaniyeText.data());

        itoa(globalVars.kapiTablaAcSure, globalVars.snum.data(), 10);
        lcd.print(2, 16, globalVars.snum.data());

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.kapitablaTip == 0)) {
        	globalVars.kapiTablaAcSure++;

            if (globalVars.kapiTablaAcSure > 5) {
            	globalVars.kapiTablaAcSure = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.kapitablaTip == 0)) {
        	globalVars.kapiTablaAcSure--;

            if (globalVars.kapiTablaAcSure > 6) {
            	globalVars.kapiTablaAcSure = 5;
            }

            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[13] = globalVars.kapiTablaAcSure;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayUpperSlowdownLimit() {
        lcd.print(1, 1, textVars.yukariYavaslamaLimitiText.data());

        if (globalVars.yukariYavasLimit == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.yukariYavasLimit == 1) {
            lcd.print(2, 1, textVars.aktifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.yukariYavasLimit++;

            if (globalVars.yukariYavasLimit > 1) {
            	globalVars.yukariYavasLimit = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.yukariYavasLimit--;

            if (globalVars.yukariYavasLimit > 0) {
            	globalVars.yukariYavasLimit = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[14] = globalVars.yukariYavasLimit;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayTippingWalkingMenu() {
        lcd.print(1, 1, textVars.devirmeYuruyusMenuText.data());

        if (globalVars.devirmeYuruyusSecim == 2) {
            lcd.print(2, 1, textVars.devirmeAktifText.data());
        } else if (globalVars.devirmeYuruyusSecim == 1) {
            lcd.print(2, 1, textVars.yuruyusAktifText.data());
        } else if (globalVars.devirmeYuruyusSecim == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.devirmeYuruyusSecim++;

            if (globalVars.devirmeYuruyusSecim > 2) {
            	globalVars.devirmeYuruyusSecim = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.devirmeYuruyusSecim--;

            if (globalVars.devirmeYuruyusSecim > 3) {
            	globalVars.devirmeYuruyusSecim = 2;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[15] = globalVars.devirmeYuruyusSecim;

            if (globalVars.devirmeYuruyusSecim == 2 || globalVars.devirmeYuruyusSecim == 1) {
            	globalVars.calismaSekli = 0;
            	globalVars.eepromData[1] = globalVars.calismaSekli;
            }

            if (globalVars.devirmeYuruyusSecim == 1) {
            	globalVars.devirmeSilindirTipi = 1;
            	globalVars.eepromData[18] = globalVars.devirmeSilindirTipi;
            }
            globalVars.hafizaYaz = 1;
        }
    }

    void displayTippingWalkingSwitch() {
        if (globalVars.devirmeYuruyusSecim == 2) {
            lcd.print(1, 1, textVars.devirmeYukariText.data());
        } else if (globalVars.devirmeYuruyusSecim == 1) {
            lcd.print(1, 1, textVars.yuruyusIleriText.data());
        }

        if (globalVars.devirmeYukariIleriLimit == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.devirmeYukariIleriLimit == 1) {
            lcd.print(2, 1, textVars.aktifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.devirmeYukariIleriLimit++;

            if (globalVars.devirmeYukariIleriLimit > 1) {
            	globalVars.devirmeYukariIleriLimit = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.devirmeYukariIleriLimit--;

            if (globalVars.devirmeYukariIleriLimit > 0) {
            	globalVars.devirmeYukariIleriLimit = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[16] = globalVars.devirmeYukariIleriLimit;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayTippingWalkingReturnSwitch() {
        if (globalVars.devirmeYuruyusSecim == 2) {
            lcd.print(1, 1, textVars.devirmeAsagiSivicText.data());
        } else if (globalVars.devirmeYuruyusSecim == 1) {
            lcd.print(1, 1, textVars.yuruyusGeriSivicText.data());
        }

        if (globalVars.devirmeAsagiGeriLimit == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.devirmeAsagiGeriLimit == 1) {
            lcd.print(2, 1, textVars.aktifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.devirmeAsagiGeriLimit++;

            if (globalVars.devirmeAsagiGeriLimit > 1) {
            	globalVars.devirmeAsagiGeriLimit = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.devirmeAsagiGeriLimit--;

            if (globalVars.devirmeAsagiGeriLimit > 0) {
            	globalVars.devirmeAsagiGeriLimit = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[17] = globalVars.devirmeAsagiGeriLimit;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayCylinderType() {
        if (globalVars.devirmeYuruyusSecim == 1) {
            lcd.print(1, 1, textVars.yuruyusSecildiText.data());
        } else if (globalVars.devirmeYuruyusSecim == 2) {
            lcd.print(1, 1, textVars.devirmeSilindirTipiText.data());
        }

        if (globalVars.devirmeSilindirTipi == 0) {
            lcd.print(2, 1, textVars.tekTesirText.data());
        } else if (globalVars.devirmeSilindirTipi == 1) {
            lcd.print(2, 1, textVars.ciftTesirText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.devirmeYuruyusSecim == 2)) {
        	globalVars.devirmeSilindirTipi++;

            if (globalVars.devirmeSilindirTipi > 1) {
            	globalVars.devirmeSilindirTipi = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.devirmeYuruyusSecim == 2)) {
        	globalVars.devirmeSilindirTipi--;

            if (globalVars.devirmeSilindirTipi > 0) {
            	globalVars.devirmeSilindirTipi = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[18] = globalVars.devirmeSilindirTipi;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayPlatformCylinderType() {
        lcd.print(1, 1, textVars.platformSilindirTipiText.data());

        if (globalVars.platformSilindirTipi == 0) {
            lcd.print(2, 1, textVars.tekTesirText.data());
        } else if (globalVars.platformSilindirTipi == 1) {
            lcd.print(2, 1, textVars.ciftTesirText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.platformSilindirTipi++;

            if (globalVars.platformSilindirTipi > 1) {
            	globalVars.platformSilindirTipi = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.platformSilindirTipi--;

            if (globalVars.platformSilindirTipi > 0) {
            	globalVars.platformSilindirTipi = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[19] = globalVars.platformSilindirTipi;

            if (globalVars.platformSilindirTipi == 1) {
            	globalVars.altLimit = 1;
            	globalVars.eepromData[5] = globalVars.altLimit;
            }
            globalVars.hafizaYaz = 1;
        }
    }

    void displayUpperValveTime() {
        lcd.print(1, 1, textVars.yukariValfSureText.data());

        if (globalVars.yukariValfTmr >= 0) {
            lcd.print(2, 1, textVars.kacSaniyeText.data());
        }

        itoa(globalVars.yukariValfTmr, globalVars.snum.data(), 10);
        lcd.print(2, 16, globalVars.snum.data());

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.yukariValfTmr++;

            if (globalVars.yukariValfTmr > 5) {
            	globalVars.yukariValfTmr = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.yukariValfTmr--;

            if (globalVars.yukariValfTmr > 6) {
            	globalVars.yukariValfTmr = 5;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[20] = globalVars.yukariValfTmr;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayLowerValveTime() {
        lcd.print(1, 1, textVars.asagiValfSureText.data());

        if (globalVars.asagiValfTmr >= 0) {
            lcd.print(2, 1, textVars.kacSaniyeText.data());
        }

        itoa(globalVars.asagiValfTmr, globalVars.snum.data(), 10);
        lcd.print(2, 16, globalVars.snum.data());

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.asagiValfTmr++;

            if (globalVars.asagiValfTmr > 5) {
            	globalVars.asagiValfTmr = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.asagiValfTmr--;

            if (globalVars.asagiValfTmr > 6) {
            	globalVars.asagiValfTmr = 5;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[21] = globalVars.asagiValfTmr;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayForwardValveTime() {
        if (globalVars.devirmeYuruyusSecim == 2) {
            lcd.print(1, 1, textVars.devirmeYukariValfSureText.data());
        } else if (globalVars.devirmeYuruyusSecim == 1) {
            lcd.print(1, 1, textVars.ileriValfSureText.data());
        }

        if (globalVars.devirmeYukariIleriTmr >= 0) {
            lcd.print(2, 1, textVars.kacSaniyeText.data());
        }

        itoa(globalVars.devirmeYukariIleriTmr, globalVars.snum.data(), 10);
        lcd.print(2, 16, globalVars.snum.data());

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.devirmeYukariIleriTmr++;

            if (globalVars.devirmeYukariIleriTmr > 5) {
            	globalVars.devirmeYukariIleriTmr = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.devirmeYukariIleriTmr--;

            if (globalVars.devirmeYukariIleriTmr > 6) {
            	globalVars.devirmeYukariIleriTmr = 5;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[22] = globalVars.devirmeYukariIleriTmr;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayBackwardValveTime() {
        if (globalVars.devirmeYuruyusSecim == 2) {
            lcd.print(1, 1, textVars.devirmeAsagiValfSureText.data());
        } else if (globalVars.devirmeYuruyusSecim == 1) {
            lcd.print(1, 1, textVars.geriValfSureText.data());
        }

        if (globalVars.devirmeAsagiGeriTmr >= 0) {
            lcd.print(2, 1, textVars.kacSaniyeText.data());
        }

        itoa(globalVars.devirmeAsagiGeriTmr, globalVars.snum.data(), 10);
        lcd.print(2, 16, globalVars.snum.data());

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.devirmeAsagiGeriTmr++;

            if (globalVars.devirmeAsagiGeriTmr > 5) {
            	globalVars.devirmeAsagiGeriTmr = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.devirmeAsagiGeriTmr--;

            if (globalVars.devirmeAsagiGeriTmr > 6) {
            	globalVars.devirmeAsagiGeriTmr = 5;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[23] = globalVars.devirmeAsagiGeriTmr;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayOperatingTime() {
        lcd.print(1, 1, textVars.calismaSuresiText.data());

        if (globalVars.makineCalismaTmr > 99) {
            lcd.print(2, 1, textVars.kacSaniyeText.data());

            itoa(globalVars.makineCalismaTmr, globalVars.snum.data(), 10);
            lcd.print(2, 14, globalVars.snum.data());
        } else if ((globalVars.makineCalismaTmr >= 10) && (globalVars.makineCalismaTmr <= 99)) {
            lcd.print(2, 1, textVars.kacSaniyeText.data());

            itoa(globalVars.makineCalismaTmr, globalVars.snum.data(), 10);
            lcd.print(2, 15, globalVars.snum.data());
        } else if (globalVars.makineCalismaTmr <= 9) {
            lcd.print(2, 1, textVars.kacSaniyeText.data());

            itoa(globalVars.makineCalismaTmr, globalVars.snum.data(), 10);
            lcd.print(2, 16, globalVars.snum.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.makineCalismaTmr++;

            if (globalVars.makineCalismaTmr > 180) {
            	globalVars.makineCalismaTmr = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.makineCalismaTmr--;

            if (globalVars.makineCalismaTmr > 181) {
            	globalVars.makineCalismaTmr = 180;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[24] = globalVars.makineCalismaTmr;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayBuzzer() {
        lcd.print(1, 1, translation.buzzerTextGN.data());

        if (globalVars.buzzer == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.buzzer == 1) {
            lcd.print(2, 1, textVars.aktifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.buzzer++;
            if (globalVars.buzzer > 1) {
            	globalVars.buzzer = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.buzzer--;

            if (globalVars.buzzer > 0) {
            	globalVars.buzzer = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[25] = globalVars.buzzer;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayDemoMode() {
        globalVars.calismaSayModu = 0;
        lcd.print(1, 1, translation.demoModTextGN.data());

        if (globalVars.demoMode == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.demoMode == 1) {
            lcd.print(2, 1, textVars.aktifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.demoMode++;

            if (globalVars.demoMode > 1) {
            	globalVars.demoMode = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.demoMode--;

            if (globalVars.demoMode > 0) {
            	globalVars.demoMode = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[26] = globalVars.demoMode;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayOperatingCount() {
        if (globalVars.calismaSayisi1 == 0 && globalVars.calismaSayisi10 == 0 && globalVars.calismaSayisi100 == 0 && globalVars.calismaSayisi1000 == 0 && globalVars.calismaSayisi10000 == 0) {
        	globalVars.calismaSayisiYar = 0;
        } else {
        	globalVars.calismaSayisiYar = 1;
        }

        if (globalVars.calismaSayModu == 0) {
            lcd.print(1, 1, textVars.calismaSayisiText.data());

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

            lcd.print(2, 1, "           ");
        } else if (globalVars.calismaSayModu == 1) {
            lcd.print(1, 1, textVars.calismaSayisiText.data());
            lcd.print(2, 1, textVars.enterlaSifirlaText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.calismaSayisiYar == 1)) {
            globalVars.calismaSayModu++;

            if (globalVars.calismaSayModu > 1) {
                globalVars.calismaSayModu = 0;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0) && (globalVars.calismaSayisiYar == 1)) {
            globalVars.calismaSayModu--;

            if (globalVars.calismaSayModu > 0) {
                globalVars.calismaSayModu = 1;
            }
            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
            clearEEPROMData(28, 5);
            globalVars.calismaSayisi10000 = 0;
            globalVars.calismaSayisi1000 = 0;
            globalVars.calismaSayisi100 = 0;
            globalVars.calismaSayisi10 = 0;
            globalVars.calismaSayisi1 = 0;
            globalVars.calismaSayModu = 0;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayLanguageSelection() {
        globalVars.calismaSayModu = 0;

        lcd.print(1, 1, textVars.dilSecimText.data());
        lcd.print(2, 1, textVars.secilenDilText.data());

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.dilSecim++;

            if (globalVars.dilSecim > 1) {
            	globalVars.dilSecim = 0;
            }
            textVars.loadMenuTexts(globalVars.dilSecim);

            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.dilSecim--;

            if (globalVars.dilSecim > 0) {
            	globalVars.dilSecim = 1;
            }
            textVars.loadMenuTexts(globalVars.dilSecim);

            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[33] = globalVars.dilSecim;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayIoTMode() {
        globalVars.calismaSayModu = 0;
        lcd.print(1, 1, translation.iotModTextGN.data());

        if (globalVars.iotMode == 0) {
            lcd.print(2, 1, textVars.pasifText.data());
        } else if (globalVars.iotMode == 1) {
            lcd.print(2, 1, textVars.aktifText.data());
        }

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.iotMode++;

            if (globalVars.iotMode > 1) {
            	globalVars.iotMode = 0;
            }

            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.iotMode--;

            if (globalVars.iotMode > 0) {
            	globalVars.iotMode = 1;
            }

            process.bekle();
        }

        if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	globalVars.eepromData[48] = globalVars.iotMode;
            globalVars.hafizaYaz = 1;
        }
    }

    void displayMachineID() {
        globalVars.calismaSayModu = 0;

        eepromProcess.convertArrays(1);
        HAL_Delay(50);

        iotMenu.printCredentials(1); //ekrana machine id yazdır

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
            wifiProcess.takeMachineIDWithConfirmation();
        }
    }

    void displayWifiSSID() {
        globalVars.calismaSayModu = 0;

        eepromProcess.convertArrays(2);
        HAL_Delay(50);

        iotMenu.printCredentials(2); //ekrana wifi ssid yazdır

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
        	wifiProcess.takeWifiSSID();

        	eepromProcess.convertArrays(2);
            HAL_Delay(50);

            iotMenu.printCredentials(2); //ekrana wifi ssid yazdır
        }
    }

    void displayWifiPassword() {
        globalVars.calismaSayModu = 0;

        eepromProcess.convertArrays(3);
        HAL_Delay(50);

        iotMenu.printCredentials(3); //ekrana wifi pass yazdır

        if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port, butonYukariIn_Pin) == 1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port, butonAsagiIn_Pin) == 1) && (globalVars.butonKontrol == 0)) {
            wifiProcess.takeWifiPass();

            eepromProcess.convertArrays(3);
            HAL_Delay(50);

            iotMenu.printCredentials(3); //ekrana wifi pass yazdır
        }
    }

    void displayExitMenu() {
        lcd.print(1, 1, textVars.menudenCikisText.data());
        lcd.print(2, 1, textVars.enteraBasinizText.data());

        if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) == 1) {
            globalVars.menuGiris = 0;

            while (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
            while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);

            HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, globalVars.eepromData.data(), 110, 3000);
            HAL_Delay(1200);

            lcd.clear();
            HAL_Delay(500);
            NVIC_SystemReset();
        }
    }

    void clearEEPROMData(int start, int length) {
        for (int i = start; i < start + length; ++i) {
        	globalVars.eepromData[i] = 0;
        }
    }
}


