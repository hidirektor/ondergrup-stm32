#include "ESP8266.h"
#include "WifiData.h"


void ESP8266_Init(UART_HandleTypeDef *huart1) {
	sprintf(bufferTX, "AT+RESTORE\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(3000);

	sprintf(bufferTX, "AT+RST\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(4000);

	sprintf(bufferTX, "AT\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(5000);

	sprintf(bufferTX, "AT+CWMODE=1\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(5000);

	char str[100];
	strcpy(str, "AT+CWJAP=\"");
	strcat(str, Wifi_name);
	strcat(str, "\",\"");
	strcat(str, Wifi_pass);
	strcat(str, "\"\r\n");
	sprintf(bufferTX, "%s", str);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(6000);
}

void sendMachineData(UART_HandleTypeDef *huart1, const char *machineID, const char *machineData) {
	char local_txA[200];
	char local_txB[50];
	int len;

	sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", Server);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(6000);

	sprintf(local_txA,
			"GET /api/machine/updateMachineDataRaw?machineID=%s&machineData=%s HTTP/1.0\r\nHost: %s\r\n\r\n", machineID, machineData, Server2);
	len = strlen(local_txA);
	sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
	HAL_Delay(7000);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txA, strlen(local_txA));
	HAL_Delay(10000);
}

void createAPandConnect(UART_HandleTypeDef *huart1) {
	sprintf(bufferTX, "AT+RESTORE\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(3000);

	char received_data[100];
	char wifiSetupCommand[150];
	char wifiConnectCommand[150];
	sprintf(wifiSetupCommand, "AT+CWSAP=\"%s\",\"%s\",1,0\r\n", mainWifiName, mainWifiPass);

	HAL_UART_Transmit_IT(&huart1, (uint8_t *)"AT+RST\r\n", strlen("AT+RST\r\n"));
	HAL_UART_Transmit_IT(&huart1, (uint8_t *)"AT+CWMODE=2\r\n", strlen("AT+CWMODE=2\r\n"));
	HAL_UART_Transmit_IT(&huart1, (uint8_t *)wifiSetupCommand, strlen(wifiSetupCommand));

	HAL_UART_Transmit_IT(&huart1, (uint8_t *)"AT+CWLIF\r\n", strlen("AT+CWLIF\r\n"));

	while(1) {
		if (strstr(received_data, "+CWJAP:")) {
			sscanf(received_data, "+CWJAP:\"%[^\"]\",\"%[^\"]\"", takenWifiName, takenWifiPass);

			HAL_UART_Transmit_IT(&huart1, (uint8_t *)"AT+CWQAP\r\n", strlen("AT+CWQAP\r\n"));

			sprintf(wifiConnectCommand, "AT+CWSAP=\"%s\",\"%s\",1,0\r\n", takenWifiName, takenWifiPass);
			HAL_UART_Transmit_IT(&huart1, (uint8_t *)wifiConnectCommand, strlen(wifiConnectCommand));
		}
	}
}
