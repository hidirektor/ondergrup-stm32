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
