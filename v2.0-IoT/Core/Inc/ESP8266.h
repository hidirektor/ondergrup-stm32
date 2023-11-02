#ifndef INC_ESPDATALOGGER_H_
#define INC_ESPDATALOGGER_H_

#include "stm32f1xx_hal.h"

void ESP8266_Init(UART_HandleTypeDef *huart);
void SendMachineData(UART_HandleTypeDef *huart);

#endif /* INC_ESPDATALOGGER_H_ */
