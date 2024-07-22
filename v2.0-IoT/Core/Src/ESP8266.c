#include "ESP8266.h"

#include "SystemDefaults.h"
#include "GlobalVariables.h"

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

void ESP8266_Init_AP(UART_HandleTypeDef *huart1) {
	sprintf(bufferTX, "AT+RESTORE\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(1000);

	sprintf(bufferTX, "AT+RST\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(1000);

	sprintf(bufferTX, "AT\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);

    // SoftAP + Client
    sprintf(bufferTX, "AT+CWMODE=2\r\n");
    HAL_UART_Transmit_IT(huart1, (uint8_t *)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    //AP Name
    sprintf(bufferTX, "AT+CWSAP=\"%s\",\"%s\",5,3\r\n", apSSID, apPassword);
    HAL_UART_Transmit_IT(huart1, (uint8_t *)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);
}

void connectWifiNetwork(UART_HandleTypeDef *huart1, const char *wifiSS, const char *wifiPA) {
	char str[100];
	strcpy(str, "AT+CWJAP=\"");
	strcat(str, wifiSS);
	strcat(str, "\",\"");
	strcat(str, wifiPA);
	strcat(str, "\"\r\n");
	sprintf(bufferTX, "%s", str);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);
}

void startWebServer(UART_HandleTypeDef *huart1) {
    // Start the TCP on 2805
    sprintf(bufferTX, "AT+CIPMUX=1\r\n");
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(2000);
    sprintf(bufferTX, "AT+CIPSERVER=1,2805\r\n");
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    sprintf(bufferTX, "AT+CIPSEND=0,50");
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    sprintf(bufferTX, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from ESP8266 AP mode!");
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    sprintf(bufferTX, "AT+CIPCLOSE=0");
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(2000);
}

void sendMachineData(UART_HandleTypeDef *huart1, const char *machineID, const char *wifiSSID, const char *wifiPass, const char *machineData) {
	char local_txA[500];
	char local_txB[50];
	int len;

	char subMachineID[13];
	strncpy(subMachineID, machineID, 12);
	subMachineID[12] = '\0';

	sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(4000);

	sprintf(local_txA,
			"GET /api/machine/updateMachineDataRaw?machineID=%s&wifiSSID=%s&wifiPass=%s&machineData=%s HTTP/1.0\r\nHost: %s\r\n\r\n", subMachineID, wifiSSID, wifiPass, machineData, mainServerWithPort);
	len = strlen(local_txA);
	sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
	HAL_Delay(4000);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txA, strlen(local_txA));
	HAL_Delay(3000);
}

int checkMachineID(UART_HandleTypeDef *huart1, const char *machineID) {
	char local_txA[500];
	char local_txB[50];
	int len;

	char bufferRX[2000];

	char subMachineID[13];
	strncpy(subMachineID, machineID, 12);
	subMachineID[12] = '\0';

	sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);

	sprintf(local_txA,
			"GET /api/machine/checkMachineID?machineID=%s HTTP/1.0\r\nHost: %s\r\n\r\n", subMachineID, mainServerWithPort);
	len = strlen(local_txA);
	sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
	HAL_Delay(4000);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txA, strlen(local_txA));
	HAL_Delay(6000);

	HAL_UART_Receive_IT(huart1, (uint8_t*) bufferRX, sizeof(bufferRX));
	HAL_Delay(5000);

	if (strstr(bufferRX, "HTTP/1.1 200 OK") || strstr(bufferRX, "HTTP/1.0 200 OK")) {
	    return 1; // Başarılı yanıt
	}

	return 0; // Yanıt başarısız
}
