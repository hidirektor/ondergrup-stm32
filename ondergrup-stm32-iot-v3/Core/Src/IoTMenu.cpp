/*
 * IoTMenu.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


#include "IoTMenu.h"
#include "Instance.h"
#include "main.h"

IoTMenu& IoTMenu::getInstance() {
    static IoTMenu instance;
    return instance;
}

void IoTMenu::printTemplate(int type, int page) {
    HAL_Delay(200);
    lcd.clear();
    if (type == 1 && page == 0) {
        lcd.print(1, 1, "ID: ");
        lcd.print(2, 3, "0");
        lcd.print(2, 4, "1");
        lcd.print(2, 5, "2");
        lcd.print(2, 6, "3");
        lcd.print(2, 7, "4");
        lcd.print(2, 10, "5");
        lcd.print(2, 11, "6");
        lcd.print(2, 12, "7");
        lcd.print(2, 13, "8");
        lcd.print(2, 14, "9");
        lcd.setCursorPosition(2, 3);
    } else if (type == 2) {
        if (page == 1) {
            lcd.clear();
            HAL_Delay(100);
            lcd.print(1, 1, "SSID:           ");
            lcd.print(1, 7, globalVars.wifiSSID.data());
            lcd.print(2, 1, "abcdefghijklmnop");
        } else if (page == 2) {
            lcd.clear();
            HAL_Delay(100);
            lcd.print(1, 1, "SSID: ");
            lcd.print(1, 7, globalVars.wifiSSID.data());
            lcd.print(2, 1, "qrstuvwxyzABCDEF");
        } else if (page == 3) {
            lcd.clear();
            HAL_Delay(100);
            lcd.print(1, 1, "SSID:           ");
            lcd.print(1, 7, globalVars.wifiSSID.data());
            lcd.print(2, 1, "GHIİJKLMNOPQRSTU");
        } else if (page == 4) {
            lcd.clear();
            HAL_Delay(100);
            lcd.print(1, 1, "SSID:           ");
            lcd.print(1, 7, globalVars.wifiSSID.data());
            lcd.print(2, 1, "VWXYZ0123456789!");
        } else if (page == 5) {
            lcd.clear();
            HAL_Delay(100);
            lcd.print(1, 1, "SSID:           ");
            lcd.print(1, 7, globalVars.wifiSSID.data());
            lcd.print(2, 1, "@#$%^&*()-_+=<>?");
        }
    } else if (type == 3) {
        if (page == 1) {
            lcd.clear();
            HAL_Delay(100);
            lcd.print(1, 1, "PASS:           ");
            lcd.print(1, 7, globalVars.wifiPass.data());
            lcd.print(2, 1, "abcdefghijklmnop");
        } else if (page == 2) {
            lcd.clear();
            HAL_Delay(100);
            lcd.print(1, 1, "PASS:           ");
            lcd.print(1, 7, globalVars.wifiPass.data());
            lcd.print(2, 1, "qrstuvwxyzABCDEF");
        } else if (page == 3) {
            lcd.clear();
            HAL_Delay(100);
            lcd.print(1, 1, "PASS:           ");
            lcd.print(1, 7, globalVars.wifiPass.data());
            lcd.print(2, 1, "GHIİJKLMNOPQRSTU");
        } else if (page == 4) {
            lcd.clear();
            HAL_Delay(100);
            lcd.print(1, 1, "PASS:           ");
            lcd.print(1, 7, globalVars.wifiPass.data());
            lcd.print(2, 1, "VWXYZ0123456789!");
        } else if (page == 5) {
            lcd.clear();
            HAL_Delay(100);
            lcd.print(1, 1, "PASS:           ");
            lcd.print(1, 7, globalVars.wifiPass.data());
            lcd.print(2, 1, "@#$%^&*()-_+=<>?");
        }
    }
}

int IoTMenu::checkSlideVal(int state) {
    if (state == 0) { // ssid (33)
        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
            return 34;
        }
        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
            return 32;
        }
    } else { // pass (34)
        if (HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port, butonIleriIn_Pin) == 1) {
            return 35;
        }
        if (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port, butonGeriIn_Pin) == 1) {
            return 33;
        }
    }
    return 0;
}

void IoTMenu::slideText(const char* text, int startPos, int startLine, int state) {
    uint8_t uzunluk = strlen(text);
    int mainLoopVal = 1;

    while (mainLoopVal == 1) {
        if (checkSlideVal(state) > 0) {
            globalVars.menuSayac = checkSlideVal(state);
            break;
        }

        for (int z = 0; z < uzunluk; z++) {
            if (checkSlideVal(state) > 0) {
                globalVars.menuSayac = checkSlideVal(state);
                mainLoopVal = 0;
                break;
            }

            for (int i = startPos + z; i < uzunluk + startPos; i++) {
                if (checkSlideVal(state) > 0) {
                    globalVars.menuSayac = checkSlideVal(state);
                    z = uzunluk;
                    mainLoopVal = 0;
                    break;
                }
                lcd.printChar(startLine, i - z, text[i - startPos]);
                HAL_Delay(30);
            }

            for (int j = uzunluk - 1; j >= uzunluk - z; j--) {
                if (checkSlideVal(state) > 0) {
                    globalVars.menuSayac = checkSlideVal(state);
                    z = uzunluk;
                    mainLoopVal = 0;
                    break;
                }
                if (j >= startPos) {
                    lcd.printChar(startLine, j, ' ');
                    HAL_Delay(30);
                }
            }
        }
    }
}

void IoTMenu::printCredentials(int type) {
    if (type == 1) {
        // machine id yazdır
        lcd.print(1, 1, textVars.machineIDText.data());
        lcd.print(2, 1, globalVars.machineID.data());
        lcd.print(2, 13, "    ");
    } else if (type == 2) {
        // wifi ssid yazdır
        int ssidLength = strlen(globalVars.wifiSSID.data());

        lcd.print(1, 1, "WIFI SSID       ");
        if (ssidLength == 16 || ssidLength < 16) {
            lcd.print(2, 1, globalVars.wifiSSID.data());
        } else if (ssidLength > 16) {
            // Eğer ssid 16'dan büyükse kayarak yazdır
            slideText(globalVars.wifiSSID.data(), 1, 2, 0);
        } else {
            lcd.print(2, 1, "                ");
        }
    } else {
        // wifi pass yazdır
        int passLength = strlen(globalVars.wifiPass.data());

        lcd.print(1, 1, "WIFI PASS       ");
        if (passLength == 16 || passLength < 16) {
            lcd.print(2, 1, globalVars.wifiPass.data());
        } else if (passLength > 16) {
            // Eğer pass 16'dan büyükse kayarak yazdır
            slideText(globalVars.wifiPass.data(), 1, 2, 1);
        } else {
            lcd.print(2, 1, "                ");
        }
    }
}
