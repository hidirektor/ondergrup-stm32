/*
 * Flash.c
 *
 *  Created on: Aug 10, 2024
 *      Author: hidir
 */

#include "Flash.h"

#include "stm32f1xx_hal.h"


void writeFlash(uint32_t* data, uint32_t dataSize) {
    HAL_StatusTypeDef status;
    uint32_t address = FLASH_USER_START_ADDR;
    uint32_t endAddress = FLASH_USER_END_ADDR;
    uint32_t dataIndex = 0;

    HAL_FLASH_Unlock();

    FLASH_EraseInitTypeDef eraseInitStruct;
    uint32_t pageError = 0;
    eraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    eraseInitStruct.PageAddress = FLASH_USER_START_ADDR;
    eraseInitStruct.NbPages = (endAddress - address + 1) / FLASH_PAGE_SIZE;

    status = HAL_FLASHEx_Erase(&eraseInitStruct, &pageError);

    if (status != HAL_OK) {
        lcd_print(1, 1, "Erase Error");
        HAL_FLASH_Lock();
        return;
    }

    while (address < endAddress && dataIndex < dataSize) {
        status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, data[dataIndex]);

        if (status == HAL_OK) {
            address += 4;
            dataIndex++;
        } else {
            lcd_print(1, 1, "Write Error");
            HAL_FLASH_Lock();
            return;
        }
    }

    HAL_FLASH_Lock();

    for (uint32_t i = 0; i < dataSize; i++) {
        if (*(uint32_t*)(FLASH_USER_START_ADDR + (i * 4)) != data[i]) {
            lcd_print(1, 1, "Verify Error");
            return;
        }
    }

    lcd_print(1, 1, "Update Success");
}

// .hex verisini buffer'a parse eden fonksiyon
void parseHexDataToBuffer(char *bufferRX, uint32_t *receivedData, int *dataSize) {
    char *line = strtok(bufferRX, "\r\n");
    *dataSize = 0;

    while (line != NULL) {
        if (line[0] == ':') {
            int byteCount = strtol(&line[1], NULL, 16);
            int address = strtol(&line[3], NULL, 16);
            int recordType = strtol(&line[7], NULL, 16);

            if (recordType == 0) {
                for (int i = 0; i < byteCount; i++) {
                    char byteStr[3];
                    byteStr[0] = line[9 + i * 2];
                    byteStr[1] = line[9 + i * 2 + 1];
                    byteStr[2] = '\0';

                    uint32_t dataByte = strtol(byteStr, NULL, 16);

                    if (i % 4 == 0) {
                        receivedData[*dataSize] = 0;
                    }

                    receivedData[*dataSize] |= dataByte << ((i % 4) * 8);

                    if (i % 4 == 3) {
                        (*dataSize)++;
                    }
                }
            }
        }
        line = strtok(NULL, "\r\n");
    }
}
