#include "ESP8266.h"
#include "WifiData.h"


void ESP8266_Init(UART_HandleTypeDef *huart1) {
	sprintf(Tx_buffer, "AT+RESTORE\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) Tx_buffer, strlen(Tx_buffer));
	HAL_Delay(3000);

	sprintf(Tx_buffer, "AT+RST\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) Tx_buffer, strlen(Tx_buffer));
	HAL_Delay(3000);

	sprintf(Tx_buffer, "AT\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) Tx_buffer, strlen(Tx_buffer));
	HAL_Delay(2000);

	sprintf(Tx_buffer, "AT+CWMODE=1\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) Tx_buffer, strlen(Tx_buffer));
	HAL_Delay(2000);

	char str[100];
	strcpy(str, "AT+CWJAP=\"");
	strcat(str, Wifi_name);
	strcat(str, "\",\"");
	strcat(str, Wifi_pass);
	strcat(str, "\"\r\n");
	sprintf(Tx_buffer, "%s", str);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) Tx_buffer, strlen(Tx_buffer));
	HAL_Delay(6000);
}

void SendMachineData(UART_HandleTypeDef *huart1) {
	char local_txA[250];
	char local_txB[50];
	int len;

	sprintf(Tx_buffer, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", Server);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) Tx_buffer, strlen(Tx_buffer));
	HAL_Delay(5000);

	sprintf(local_txA,
			"GET /api/machine/updateMachineDataRaw?machineID=12345&machineData=111001011021210101001210000102012345678923456 HTTP/1.0\r\nHost: %s\r\n\r\n", Server2);
	len = strlen(local_txA);
	sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
	HAL_Delay(5000);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txA, strlen(local_txA));
	HAL_Delay(5000);
}
