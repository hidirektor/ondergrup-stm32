#ifndef INC_ESPDATALOGGER_H_
#define INC_ESPDATALOGGER_H_

#include "stm32f1xx_hal.h"

#include "stdio.h"
#include "string.h"

#define demoWifi "ONDERLIFT_PERSONEL"
#define demoWifiPass "PersonelOt2022*-"

#define serverIP "85.95.231.92"
#define serverIPWithPort "85.95.231.92:3000"

void ESP8266_Init(UART_HandleTypeDef *huart, const char *wifiSS, const char *wifiPA);
void sendMachineData(UART_HandleTypeDef *huart, const char *machineID, const char *machineData);
int checkMachineID(UART_HandleTypeDef *huart1, const char *machineID);

#endif /* INC_ESPDATALOGGER_H_ */
