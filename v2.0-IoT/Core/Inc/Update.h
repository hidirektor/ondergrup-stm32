/*
 * Update.h
 *
 *  Created on: Dec 31, 2023
 *      Author: hidirektor
 */

#ifndef INC_UPDATE_H_
#define INC_UPDATE_H_

#include "main.h"

uint32_t calculateCRC32(uint8_t *buffer, size_t length);

void updateFirmware(UART_HandleTypeDef *huart1);

#endif /* INC_UPDATE_H_ */
