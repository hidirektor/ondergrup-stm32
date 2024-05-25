/*
 * Util.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef UTIL_H
#define UTIL_H

#include "stm32f1xx_hal.h"
#include <string>

void checkAndUpdateFirmware(UART_HandleTypeDef *huart1);

#endif // UTIL_H

