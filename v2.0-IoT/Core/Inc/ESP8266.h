#ifndef INC_ESPDATALOGGER_H_
#define INC_ESPDATALOGGER_H_

#include "stm32f1xx_hal.h"

#include "stdio.h"
#include "string.h"

void ESP8266_Init(UART_HandleTypeDef *huart);
void sendMachineData(UART_HandleTypeDef *huart, const char *machineID, const char *machineData);
void createAPandConnect(UART_HandleTypeDef *huart);

#endif /* INC_ESPDATALOGGER_H_ */
