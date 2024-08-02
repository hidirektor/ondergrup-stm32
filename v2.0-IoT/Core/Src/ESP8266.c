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
	char local_txA[1500];
	char local_txB[50];
	int len;

	char subMachineID[13];
	strncpy(subMachineID, machineID, 12);
	subMachineID[12] = '\0';

	sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(1000);

	sprintf(local_txA,
	    "GET /api/v2/machine/updateMachineRaw?machineID=%s&wifiSSID=%s&wifiPass=%s&devirmeYuruyusSecim=%d&calismaSekli=%d&emniyetCercevesi=%d&yavaslamaLimit=%d&altLimit=%d&kapiTablaAcKonum=%d&basincSalteri=%d&kapiSecimleri=%d&kapiAcTipi=%d&kapi1Tip=%d&kapi1AcSure=%d&kapi2Tip=%d&kapi2AcSure=%d&kapitablaTip=%d&kapiTablaAcSure=%d&yukariYavasLimit=%d&devirmeYukariIleriLimit=%d&devirmeAsagiGeriLimit=%d&devirmeSilindirTipi=%d&platformSilindirTipi=%d&yukariValfTmr=%d&asagiValfTmr=%d&devirmeYukariIleriTmr=%d&devirmeAsagiGeriTmr=%d&makineCalismaTmr=%d&buzzer=%d&demoMode=%d&calismaSayisi=%d&calismaSayisiDemo=%d&dilSecim=%d&eepromData38=%d&eepromData39=%d&eepromData40=%d&eepromData41=%d&eepromData42=%d&eepromData43=%d&eepromData44=%d&eepromData45=%d&eepromData46=%d&eepromData47=%d&lcdBacklightSure=%d HTTP/1.0\r\nHost: %s\r\n\r\n",
	    subMachineID, wifiSSID, wifiPass, devirmeYuruyusSecim, calismaSekli, emniyetCercevesi,
	    yavaslamaLimit, altLimit, kapiTablaAcKonum, basincSalteri, kapiSecimleri, kapiAcTipi, kapi1Tip, kapi1AcSure,
	    kapi2Tip, kapi2AcSure, kapitablaTip, kapiTablaAcSure, yukariYavasLimit, devirmeYukariIleriLimit, devirmeAsagiGeriLimit,
	    devirmeSilindirTipi, platformSilindirTipi, yukariValfTmr, asagiValfTmr, devirmeYukariIleriTmr, devirmeAsagiGeriTmr,
	    makineCalismaTmr, buzzer, demoMode, calismaSayisi, calismaSayisiDemo, dilSecim, eepromData[38], eepromData[39],
	    eepromData[40], eepromData[41], eepromData[42], eepromData[43], eepromData[44], eepromData[45],
	    eepromData[46], eepromData[47], lcdBacklightSure, mainServerWithPort);

	len = strlen(local_txA);
	sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
	HAL_Delay(2000);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txA, strlen(local_txA));
	HAL_Delay(2000);
}

void sendMachineDataDemo(UART_HandleTypeDef *huart1, const char *machineID, const char *wifiSSID, const char *wifiPass, const char *machineData) {
    char bufferTX[4000];
    char local_txB[50];
    char json_data[2000];
    int len;

    // JSON verisini manuel olarak oluşturma
    snprintf(json_data, sizeof(json_data),
             "{\"machineID\":\"%s\","
             "\"updateData\":{"
             "\"wifiSSID\":\"%s\","
             "\"wifiPass\":\"%s\","
             "\"devirmeYuruyusSecim\":\"%d\","
             "\"calismaSekli\":\"%d\","
             "\"emniyetCercevesi\":\"%d\","
             "\"yavaslamaLimit\":\"%d\","
             "\"altLimit\":\"%d\","
             "\"kapiTablaAcKonum\":\"%d\","
             "\"basincSalteri\":\"%d\","
             "\"kapiSecimleri\":\"%d\","
             "\"kapiAcTipi\":\"%d\","
             "\"kapi1Tip\":\"%d\","
             "\"kapi1AcSure\":\"%d\","
             "\"kapi2Tip\":\"%d\","
             "\"kapi2AcSure\":\"%d\","
             "\"kapitablaTip\":\"%d\","
             "\"kapiTablaAcSure\":\"%d\","
             "\"yukariYavasLimit\":\"%d\","
             "\"devirmeYukariIleriLimit\":\"%d\","
             "\"devirmeAsagiGeriLimit\":\"%d\","
             "\"devirmeSilindirTipi\":\"%d\","
             "\"platformSilindirTipi\":\"%d\","
             "\"yukariValfTmr\":\"%d\","
             "\"asagiValfTmr\":\"%d\","
             "\"devirmeYukariIleriTmr\":\"%d\","
             "\"devirmeAsagiGeriTmr\":\"%d\","
             "\"makineCalismaTmr\":\"%d\","
             "\"buzzer\":\"%d\","
             "\"demoMode\":\"%d\","
             "\"calismaSayisi\":\"%d\","
             "\"calismaSayisiDemo\":\"%d\","
             "\"dilSecim\":\"%d\","
             "\"eepromData38\":\"%d\","
             "\"eepromData39\":\"%d\","
             "\"eepromData40\":\"%d\","
             "\"eepromData41\":\"%d\","
             "\"eepromData42\":\"%d\","
             "\"eepromData43\":\"%d\","
             "\"eepromData44\":\"%d\","
             "\"eepromData45\":\"%d\","
             "\"eepromData46\":\"%d\","
             "\"eepromData47\":\"%d\","
             "\"lcdBacklightSure\":\"%d\""
             "}}",
             machineID, wifiSSID, wifiPass, devirmeYuruyusSecim, calismaSekli, emniyetCercevesi, yavaslamaLimit, altLimit,
             kapiTablaAcKonum, basincSalteri, kapiSecimleri, kapiAcTipi, kapi1Tip, kapi1AcSure, kapi2Tip, kapi2AcSure,
             kapitablaTip, kapiTablaAcSure, yukariYavasLimit, devirmeYukariIleriLimit, devirmeAsagiGeriLimit,
             devirmeSilindirTipi, platformSilindirTipi, yukariValfTmr, asagiValfTmr, devirmeYukariIleriTmr,
             devirmeAsagiGeriTmr, makineCalismaTmr, buzzer, demoMode, calismaSayisi, calismaSayisiDemo, dilSecim,
             eepromData[38], eepromData[39], eepromData[40], eepromData[41], eepromData[42], eepromData[43], eepromData[44], eepromData[45],
             eepromData[46], eepromData[47], lcdBacklightSure);

    sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(4000);

    snprintf(bufferTX, sizeof(bufferTX),
             "POST /api/v2/machine/updateMachineData HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Content-Type: application/json\r\n"
             "Content-Length: %d\r\n\r\n"
             "%s",
             mainServerWithPort, strlen(json_data), json_data);
    len = strlen(bufferTX);
    sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

    HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
    HAL_Delay(4000);

    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(15000);
}

int checkMachineID(UART_HandleTypeDef *huart1, const char *machineID) {
    char local_txA[1000];
    char local_txB[50];
    int len;

    char bufferRX[1500];
    volatile uint8_t uart_rx_complete = 0;

    char subMachineID[13];
    strncpy(subMachineID, machineID, 12);
    subMachineID[12] = '\0';

    sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
    HAL_UART_Transmit_DMA(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(1000);

    sprintf(local_txA,
            "GET /api/v2/machine/checkMachineIDRaw?machineID=%s HTTP/1.0\r\nHost: %s\r\n\r\n", subMachineID, mainServerWithPort);

    len = strlen(local_txA);
    sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

    HAL_UART_Transmit_DMA(huart1, (uint8_t*) local_txB, strlen(local_txB));
    HAL_Delay(2000);

    HAL_UART_Transmit_DMA(huart1, (uint8_t*) local_txA, strlen(local_txA));
    HAL_Delay(2000);

    uart_rx_complete = 0;
    HAL_UART_Receive_DMA(huart1, (uint8_t*) bufferRX, sizeof(bufferRX));
    HAL_Delay(5000);

    uint32_t startTick = HAL_GetTick();
    while (uart_rx_complete == 0) {
        if ((HAL_GetTick() - startTick) > 5000) { // 5 saniye bekle
            return 0; // Zaman aşımı
        }
    }

    // HTTP yanıt kodunu kontrol et
    if (strstr(bufferRX, "HTTP/1.1 200 OK")) {
        return 1;  // Başarılı
    } else {
        return 0;  // Başarısız
    }
}

