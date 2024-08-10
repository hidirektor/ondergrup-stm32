#ifndef INC_ESPDATALOGGER_H_
#define INC_ESPDATALOGGER_H_

#include "stm32f1xx_hal.h"

#include "stdio.h"
#include "string.h"

void ESP8266_Init(UART_HandleTypeDef *huart, const char *wifiSS, const char *wifiPA);
void ESP8266_Init_AP(UART_HandleTypeDef *huart1);
void connectWifiNetwork(UART_HandleTypeDef *huart1, const char *wifiSS, const char *wifiPA);
void startWebServer(UART_HandleTypeDef *huart1);

void sendMachineData(UART_HandleTypeDef *huart, const char *machineID, const char *wifiSSID, const char *wifiPass, const char *machineData);
int checkMachineID(UART_HandleTypeDef *huart1, const char *machineID);

void checkForUpdates(UART_HandleTypeDef *huart, const char *currentVersion);
void downloadNewVersion(UART_HandleTypeDef *huart, const char *versionCode);
void parseHexDataToBuffer(char *bufferRX, uint32_t *receivedData, int *dataSize);
void writeFlash(uint32_t* data, uint32_t dataSize);

#endif /* INC_ESPDATALOGGER_H_ */
