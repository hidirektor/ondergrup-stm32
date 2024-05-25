/*
 * Util.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#include "Util.h"
#include "ESP8266.h"
#include "SystemDefaults.h"
#include <string>

void checkAndUpdateFirmware(UART_HandleTypeDef *huart1) {
    ESP8266& esp = ESP8266::getInstance();
    std::string currentVersion = "1.0.0";
    std::string newVersion;
    int fileSize;
    std::string crc;

    if (esp.checkForUpdate(huart1, currentVersion, newVersion, fileSize, crc)) {
        uint8_t* firmwareBuffer = new uint8_t[fileSize];

        if (esp.downloadNewVersion(huart1, newVersion, firmwareBuffer, fileSize)) {
            if (esp.verifyCRC(firmwareBuffer, fileSize, crc)) {
                // Update flags
                HAL_FLASH_Unlock();
                HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, UPDATE_FLAG_ADDRESS, 0xDEADBEEF);
                HAL_FLASH_Lock();

                // New firmware
                uint32_t new_firmware_address = 0x08008000;
                HAL_FLASH_Unlock();
                for (int i = 0; i < fileSize; i += 2) {
                    uint16_t data16 = firmwareBuffer[i] | (firmwareBuffer[i + 1] << 8);
                    HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, new_firmware_address + i, data16);
                }
                HAL_FLASH_Lock();

                // Reset system
                NVIC_SystemReset();
            } else {
                // CRC error
                delete[] firmwareBuffer;
                return;
            }
        } else {
            // Download error
            delete[] firmwareBuffer;
            return;
        }

        delete[] firmwareBuffer;
    }
}



