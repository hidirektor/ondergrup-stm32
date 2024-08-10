/*
 * Flash.h
 *
 *  Created on: Aug 10, 2024
 *      Author: hidir
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include <stdint.h>

#define FLASH_PAGE_SIZE         1024
#define FLASH_BASE_ADDR         0x08000000

#define FLASH_USER_START_ADDR   (FLASH_BASE_ADDR + FLASH_PAGE_SIZE * 60)
#define FLASH_USER_END_ADDR     (FLASH_BASE_ADDR + FLASH_PAGE_SIZE * 63 + FLASH_PAGE_SIZE - 1)

void writeFlash(uint32_t* data, uint32_t dataSize);

#endif /* INC_FLASH_H_ */
