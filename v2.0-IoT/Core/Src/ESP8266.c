#include "ESP8266.h"

#include "SystemDefaults.h"

void ESP8266_Init(UART_HandleTypeDef *huart1, const char *wifiSS, const char *wifiPA) {
	sprintf(bufferTX, "AT+RESTORE\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(1000);

	sprintf(bufferTX, "AT+RST\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(1000);

	sprintf(bufferTX, "AT\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);

	sprintf(bufferTX, "AT+CWMODE=1\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);

	char str[100];
	strcpy(str, "AT+CWJAP_DEF=\"");
	strcat(str, wifiSS);
	strcat(str, "\",\"");
	strcat(str, wifiPA);
	strcat(str, "\"\r\n");
	sprintf(bufferTX, "%s", str);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);
}

void sendMachineData(UART_HandleTypeDef *huart1, const char *machineID, const char *machineData) {
	char local_txA[200];
	char local_txB[50];
	int len;

	sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(4000);

	sprintf(local_txA,
			"GET /api/machine/updateMachineDataRaw?machineID=%s&machineData=%s HTTP/1.0\r\nHost: %s\r\n\r\n", machineID, machineData, mainServerWithPort);
	len = strlen(local_txA);
	sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
	HAL_Delay(4000);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txA, strlen(local_txA));
	HAL_Delay(3000);
}

int checkMachineID(UART_HandleTypeDef *huart1, const char *machineID) {
	char local_txA[200];
	char local_txB[50];
	int len;

	char bufferRX[200];

	sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);

	sprintf(local_txA,
			"GET /api/machine/checkMachineID?machineID=%s HTTP/1.0\r\nHost: %s\r\n\r\n", machineID, mainServerWithPort);
	len = strlen(local_txA);
	sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
	HAL_Delay(4000);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txA, strlen(local_txA));
	HAL_Delay(6000);

	HAL_UART_Receive_IT(huart1, (uint8_t*) bufferRX, sizeof(bufferRX));
	HAL_Delay(5000);

	if (strstr(bufferRX, "HTTP/1.1 200 OK") != NULL && strstr(bufferRX, "\"message\": \"Machine ID is available.\"") != NULL) {
	    return 1; // Success
	}

	return 0; // Yanıt başarısız
}
