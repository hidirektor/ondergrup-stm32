/*
 * ErrorProcess.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#include "ErrorProcess.h"
#include "main.h"

ErrorProcess& ErrorProcess::getInstance() {
    static ErrorProcess instance;
    return instance;
}

void ErrorProcess::hata2EEPROM(uint8_t errorCode) {
    updateEEPROMData(systemDefaults.eepromHataBaslangic + errorCode, errorCode);
}

void ErrorProcess::hataKoduLcdGoster(uint8_t errorCode) {
    switch (errorCode) {
        case 1:
            lcd.print(1, 1, textVars.errorCodeText.c_str());
            lcd.print(2, 1, "1");
            lcd.print(2, 7, "          ");
            break;
        case 2:
            lcd.print(1, 1, textVars.errorCodeText.c_str());
            lcd.print(2, 2, "2");
            lcd.print(2, 7, "          ");
            break;
        case 3:
            lcd.print(1, 1, textVars.errorCodeText.c_str());
            lcd.print(2, 3, "3");
            lcd.print(2, 7, "          ");
            break;
        case 4:
            lcd.print(1, 1, textVars.errorCodeText.c_str());
            lcd.print(2, 4, "4");
            lcd.print(2, 7, "          ");
            break;
        case 5:
            lcd.print(1, 1, textVars.errorCodeText.c_str());
            lcd.print(2, 5, "5");
            lcd.print(2, 7, "          ");
            break;
        case 6:
            lcd.print(1, 1, textVars.errorCodeText.c_str());
            lcd.print(2, 6, "6");
            lcd.print(2, 7, "          ");
            break;
        default:
            lcd.print(1, 1, "Unknown Error");
            lcd.print(2, 1, "Code");
            lcd.print(2, 7, "          ");
            break;
    }
    HAL_Delay(2000);
    lcd.clear();
}

void ErrorProcess::eepromDataFillWithEmpty() {
    for (size_t i = 0; i < systemDefaults.eepromVal.size(); ++i) {
        updateEEPROMData(systemDefaults.eepromVal[i], 0xFF);  // Fill with 0xFF as default empty value
    }
}

void ErrorProcess::updateEEPROMData(uint8_t index, uint8_t value) {
    // Implement EEPROM writing logic here
    HAL_StatusTypeDef status = HAL_I2C_Mem_Write(&hi2c1, 0xA0, index, I2C_MEMADD_SIZE_8BIT, &value, 1, 100);
    if (status != HAL_OK) {
        // Handle error, possibly by showing an error on the LCD
        showErrorOnLCD("EEPROM Write Error");
    }
}

void ErrorProcess::showErrorOnLCD(const std::string& errorMessage) {
    lcd.print(1, 1, errorMessage.c_str());
    HAL_Delay(2000);  // Delay for 2 seconds for the message to be visible
    lcd.clear();
}
