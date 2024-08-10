#include "ESPDriver.h"
#include "SystemDefaults.h"
#include "GlobalVariables.h"
#include "Flash.h"

// ESP8266'yı WiFi ağına bağlamak için kullanılan fonksiyon
void ESP8266_Init(UART_HandleTypeDef *huart, const char *wifiSS, const char *wifiPA) {
    Wifi_FactoryReset(huart);
    HAL_Delay(1000);

    Wifi_Restart(huart);
    HAL_Delay(1000);

    Wifi_Init(huart);
    HAL_Delay(2000);

    Wifi_SetMode(huart, WifiMode_Station);
    HAL_Delay(2000);

    Wifi_Station_ConnectToAp(huart, (char *)wifiSS, (char *)wifiPA, NULL);
    HAL_Delay(2000);
}

// ESP8266'yı SoftAP modunda başlatmak için kullanılan fonksiyon
void ESP8266_Init_AP(UART_HandleTypeDef *huart) {
    Wifi_FactoryReset(huart);
    HAL_Delay(1000);

    Wifi_Restart(huart);
    HAL_Delay(1000);

    Wifi_Init(huart);
    HAL_Delay(2000);

    Wifi_SetMode(huart, WifiMode_SoftAP);
    HAL_Delay(2000);

    Wifi_SoftAp_Create(huart, apSSID, apPassword, 5, WifiEncryptionType_WPA2_PSK, 4, false);
    HAL_Delay(2000);
}

// WiFi ağına bağlanmak için kullanılan fonksiyon
void connectWifiNetwork(UART_HandleTypeDef *huart, const char *wifiSS, const char *wifiPA) {
    Wifi_Station_ConnectToAp(huart, (char *)wifiSS, (char *)wifiPA, NULL);
    HAL_Delay(2000);
}

// Web sunucusu başlatmak için kullanılan fonksiyon
void startWebServer(UART_HandleTypeDef *huart) {
    Wifi_TcpIp_SetMultiConnection(huart, true);
    HAL_Delay(2000);

    Wifi_TcpIp_SetEnableTcpServer(huart, 2805);
    HAL_Delay(2000);

    sprintf(bufferTX, "AT+CIPSEND=0,50\r\n");
    HAL_UART_Transmit_IT(huart, (uint8_t *)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    sprintf(bufferTX, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from ESP8266 AP mode!");
    HAL_UART_Transmit_IT(huart, (uint8_t *)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    Wifi_TcpIp_Close(huart, 0);
    HAL_Delay(2000);
}

// Makine verilerini sunucuya göndermek için kullanılan fonksiyon
void sendMachineData(UART_HandleTypeDef *huart, const char *machineID, const char *wifiSSID, const char *wifiPass, const char *machineData) {
    char local_txA[1500];
    char local_txB[50];
    int len;

    char subMachineID[13];
    strncpy(subMachineID, machineID, 12);
    subMachineID[12] = '\0';

    sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
    HAL_UART_Transmit_IT(huart, (uint8_t *)bufferTX, strlen(bufferTX));
    HAL_Delay(1000);

    sprintf(local_txA,
        "GET /api/v2/machine/updateMachineRaw?machineID=%s&wifiSSID=%s&wifiPass=%s&devirmeYuruyusSecim=%d&calismaSekli=%d&emniyetCercevesi=%d&yavaslamaLimit=%d&altLimit=%d&kapiTablaAcKonum=%d&basincSalteri=%d&kapiSecimleri=%d&kapiAcTipi=%d&kapi1Tip=%d&kapi1AcSure=%d&kapi2Tip=%d&kapi2AcSure=%d&kapitablaTip=%d&kapiTablaAcSure=%d&yukariYavasLimit=%d&devirmeYukariIleriLimit=%d&devirmeAsagiGeriLimit=%d&devirmeSilindirTipi=%d&platformSilindirTipi=%d&yukariValfTmr=%d&asagiValfTmr=%d&devirmeYukariIleriTmr=%d&devirmeAsagiGeriTmr=%d&makineCalismaTmr=%d&buzzer=%d&demoMode=%d&calismaSayisi=%d&calismaSayisiDemo=%d&dilSecim=%d&eepromData38=%d&eepromData39=%d&eepromData40=%d&eepromData41=%d&eepromData42=%d&eepromData43=%d&eepromData44=%d&eepromData45=%d&eepromData46=%d&eepromData47=%d&lcdBacklightSure=%d HTTP/1.0\r\nHost: %s\r\n\r\n",
        subMachineID, wifiSSID, wifiPass, devirmeYuruyusSecim, calismaSekli, emniyetCercevesi, yavaslamaLimit, altLimit, kapiTablaAcKonum, basincSalteri, kapiSecimleri, kapiAcTipi, kapi1Tip, kapi1AcSure, kapi2Tip, kapi2AcSure, kapitablaTip, kapiTablaAcSure, yukariYavasLimit, devirmeYukariIleriLimit, devirmeAsagiGeriLimit, devirmeSilindirTipi, platformSilindirTipi, yukariValfTmr, asagiValfTmr, devirmeYukariIleriTmr, devirmeAsagiGeriTmr, makineCalismaTmr, buzzer, demoMode, calismaSayisi, calismaSayisiDemo, dilSecim, eepromData[38], eepromData[39], eepromData[40], eepromData[41], eepromData[42], eepromData[43], eepromData[44], eepromData[45], eepromData[46], eepromData[47], lcdBacklightSure, mainServerWithPort);

    len = strlen(local_txA);
    sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

    HAL_UART_Transmit_IT(huart, (uint8_t *)local_txB, strlen(local_txB));
    HAL_Delay(2000);

    HAL_UART_Transmit_IT(huart, (uint8_t *)local_txA, strlen(local_txA));
    HAL_Delay(2000);
}

// Makine verilerini sunucuya JSON formatında göndermek için kullanılan fonksiyon (Demo Modu)
void sendMachineDataDemo(UART_HandleTypeDef *huart, const char *machineID, const char *wifiSSID, const char *wifiPass, const char *machineData) {
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
    HAL_UART_Transmit_IT(huart, (uint8_t *)bufferTX, strlen(bufferTX));
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

    HAL_UART_Transmit_IT(huart, (uint8_t *)local_txB, strlen(local_txB));
    HAL_Delay(4000);

    HAL_UART_Transmit_IT(huart, (uint8_t *)bufferTX, strlen(bufferTX));
    HAL_Delay(15000);
}

// Makine ID'sini kontrol eden fonksiyon
int checkMachineID(UART_HandleTypeDef *huart, const char *machineID) {
    char local_txA[1000];
    char local_txB[50];
    int len;

    char bufferRX[1500];

    char subMachineID[13];
    strncpy(subMachineID, machineID, 12);
    subMachineID[12] = '\0';

    sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
    HAL_UART_Transmit_IT(huart, (uint8_t *)bufferTX, strlen(bufferTX));
    HAL_Delay(1000);

    sprintf(local_txA,
            "GET /api/v2/machine/checkMachineIDRaw?machineID=%s HTTP/1.0\r\nHost: %s\r\n\r\n",
            subMachineID, mainServerWithPort);

    len = strlen(local_txA);
    sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

    HAL_UART_Transmit_IT(huart, (uint8_t *)local_txB, strlen(local_txB));
    HAL_Delay(2000);

    HAL_UART_Transmit_IT(huart, (uint8_t *)local_txA, strlen(local_txA));
    HAL_Delay(2000);

    HAL_UART_Receive_IT(huart, (uint8_t *)bufferRX, sizeof(bufferRX));
    HAL_Delay(5000);

    // HTTP yanıt kodunu kontrol et
    if (strstr(bufferRX, "HTTP/1.1 200 OK")) {
        return 1;  // Başarılı
    } else {
        return 0;  // Başarısız
    }
}

// Güncelleme kontrolü yapan fonksiyon
void checkForUpdates(UART_HandleTypeDef *huart, const char *currentVersion) {
    char checkUpdateCommand[150];
    sprintf(checkUpdateCommand, "GET /api/v2/updateChecker/checkUpdatesRaw?currentVersion=%s HTTP/1.0\r\nHost: %s\r\n\r\n", currentVersion, mainServerWithPort);

    Wifi_TcpIp_StartTcpConnection(huart, 0, mainServer, 3000, 30);
    HAL_Delay(2000);

    Wifi_TcpIp_SendDataTcp(huart, 0, strlen(checkUpdateCommand), (uint8_t *)checkUpdateCommand);
    HAL_Delay(5000);

    HAL_UART_Receive_IT(huart, (uint8_t *)bufferRX, sizeof(bufferRX));
    HAL_Delay(5000);

    if (strstr(bufferRX, "HTTP/1.1 200 OK")) {
        if (strstr(bufferRX, "\"updateAvailable\":true")) {
            lcd_print(1, 1, "New Update Available");
            HAL_Delay(2000);
            lcd_clear();
        } else {
            lcd_print(1, 1, "No Update Available");
            HAL_Delay(2000);
            lcd_clear();
        }
    } else {
        lcd_print(1, 1, "Update Check Failed");
        HAL_Delay(2000);
        lcd_clear();
    }
}

// Yeni versiyonu indirmek için kullanılan fonksiyon
void downloadNewVersion(UART_HandleTypeDef *huart, const char *versionCode) {
    char downloadCommand[150];
    sprintf(downloadCommand, "GET /api/v2/updateChecker/downloadNewVersionRaw?versionCode=%s HTTP/1.0\r\nHost: %s\r\n\r\n", versionCode, mainServerWithPort);

    Wifi_TcpIp_StartTcpConnection(huart, 0, "85.95.231.92", 3000, 30);
    HAL_Delay(2000);

    Wifi_TcpIp_SendDataTcp(huart, 0, strlen(downloadCommand), (uint8_t *)downloadCommand);
    HAL_Delay(5000);

    HAL_UART_Receive_IT(huart, (uint8_t *)bufferRX, sizeof(bufferRX));
    HAL_Delay(5000);

    uint32_t receivedData[1024];
    int dataSize = 0;

    parseHexDataToBuffer(bufferRX, receivedData, &dataSize);

    lcd_print(1, 1, "Writing to Flash...");
    HAL_Delay(2000);

    writeFlash(receivedData, dataSize);
}

// .hex verisini buffer'a parse eden fonksiyon
void parseHexDataToBuffer(char *bufferRX, uint32_t *receivedData, int *dataSize) {
    char *line = strtok(bufferRX, "\r\n");
    *dataSize = 0;

    while (line != NULL) {
        if (line[0] == ':') {
            int byteCount = strtol(&line[1], NULL, 16);
            int address = strtol(&line[3], NULL, 16);
            int recordType = strtol(&line[7], NULL, 16);

            if (recordType == 0) {
                for (int i = 0; i < byteCount; i++) {
                    char byteStr[3];
                    byteStr[0] = line[9 + i * 2];
                    byteStr[1] = line[9 + i * 2 + 1];
                    byteStr[2] = '\0';

                    uint32_t dataByte = strtol(byteStr, NULL, 16);

                    if (i % 4 == 0) {
                        receivedData[*dataSize] = 0;
                    }

                    receivedData[*dataSize] |= dataByte << ((i % 4) * 8);

                    if (i % 4 == 3) {
                        (*dataSize)++;
                    }
                }
            }
        }
        line = strtok(NULL, "\r\n");
    }
}
