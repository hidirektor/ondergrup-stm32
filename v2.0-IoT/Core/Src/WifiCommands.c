/*
 * WifiCommands.c
 *
 *  Created on: Aug 10, 2024
 *      Author: hidirektor
 */
#include "WifiCommands.h"
#include "ESPDriver.h"
#include "SystemDefaults.h"
#include "GlobalVariables.h"
#include "Flash.h"
#include "i2c-lcd.h"
#include "requestHeaders.h"

#define SHORT_DELAY_MS 2000
#define LONG_DELAY_MS 3000

// Temel WiFi İşlemleri için Yardımcı Fonksiyon
static void BasicWifiSetup(UART_HandleTypeDef *huart) {
    Wifi_FactoryReset(huart);
    HAL_Delay(SHORT_DELAY_MS);

    Wifi_Restart(huart);
    HAL_Delay(SHORT_DELAY_MS);

    Wifi_Init(huart);
    HAL_Delay(LONG_DELAY_MS);
}

// ESP8266'yı WiFi ağına bağlamak için kullanılan fonksiyon
void ESP8266_Init(UART_HandleTypeDef *huart, const char *wifiSS, const char *wifiPA) {
    BasicWifiSetup(huart);
    Wifi_SetMode(huart, WifiMode_Station);
    HAL_Delay(LONG_DELAY_MS);

    Wifi_Station_ConnectToAp(huart, (char *)wifiSS, (char *)wifiPA, NULL);
    HAL_Delay(LONG_DELAY_MS);
}

// ESP8266'yı SoftAP modunda başlatmak için kullanılan fonksiyon
void ESP8266_Init_AP(UART_HandleTypeDef *huart) {
    BasicWifiSetup(huart);
    Wifi_SetMode(huart, WifiMode_SoftAP);
    HAL_Delay(LONG_DELAY_MS);

    Wifi_SoftAp_Create(huart, apSSID, apPassword, 5, WifiEncryptionType_WPA2_PSK, 4, false);
    HAL_Delay(LONG_DELAY_MS);
}

// WiFi ağına bağlanmak için kullanılan fonksiyon
void connectWifiNetwork(UART_HandleTypeDef *huart, const char *wifiSS, const char *wifiPA) {
    Wifi_Station_ConnectToAp(huart, (char *)wifiSS, (char *)wifiPA, NULL);
    HAL_Delay(LONG_DELAY_MS);
}

// Web sunucusu başlatmak için kullanılan fonksiyon
void startWebServer(UART_HandleTypeDef *huart) {
    Wifi_TcpIp_SetMultiConnection(huart, true);
    HAL_Delay(LONG_DELAY_MS);

    Wifi_TcpIp_SetEnableTcpServer(huart, 2805);
    HAL_Delay(LONG_DELAY_MS);

    const char *responseHeader = "AT+CIPSEND=0,50\r\n";
    HAL_UART_Transmit_IT(huart, (uint8_t *)responseHeader, strlen(responseHeader));
    HAL_Delay(LONG_DELAY_MS);

    const char *responseBody = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from ESP8266 AP mode!";
    HAL_UART_Transmit_IT(huart, (uint8_t *)responseBody, strlen(responseBody));
    HAL_Delay(LONG_DELAY_MS);

    Wifi_TcpIp_Close(huart, 0);
    HAL_Delay(LONG_DELAY_MS);
}

// Makine verilerini sunucuya göndermek için kullanılan fonksiyon
void sendMachineData(UART_HandleTypeDef *huart, const char *machineID, const char *wifiSSID, const char *wifiPass, const char *machineData) {
    char local_txA[1500];
    char local_txB[50];

    snprintf(local_txA, sizeof(local_txA), URL_UPDATE_MACHINE_RAW, machineID, wifiSSID, wifiPass,
             devirmeYuruyusSecim, calismaSekli, emniyetCercevesi, yavaslamaLimit, altLimit,
             kapiTablaAcKonum, basincSalteri, kapiSecimleri, kapiAcTipi, kapi1Tip, kapi1AcSure,
             kapi2Tip, kapi2AcSure, kapitablaTip, kapiTablaAcSure, yukariYavasLimit, devirmeYukariIleriLimit,
             devirmeAsagiGeriLimit, devirmeSilindirTipi, platformSilindirTipi, yukariValfTmr, asagiValfTmr,
             devirmeYukariIleriTmr, devirmeAsagiGeriTmr, makineCalismaTmr, buzzer, demoMode,
             calismaSayisi, calismaSayisiDemo, dilSecim, eepromData[38], eepromData[39],
             eepromData[40], eepromData[41], eepromData[42], eepromData[43], eepromData[44],
             eepromData[45], eepromData[46], eepromData[47], lcdBacklightSure, MAIN_SERVER_WITH_PORT);

    int len = strlen(local_txA);
    snprintf(local_txB, sizeof(local_txB), "AT+CIPSEND=%d\r\n", len);

    HAL_UART_Transmit_IT(huart, (uint8_t *)local_txB, strlen(local_txB));
    HAL_Delay(2000);

    HAL_UART_Transmit_IT(huart, (uint8_t *)local_txA, strlen(local_txA));
    HAL_Delay(2000);
}


// JSON Body Şablonunu kullanarak makine verilerini gönderme
void sendMachineDataDemo(UART_HandleTypeDef *huart, const char *machineID, const char *wifiSSID, const char *wifiPass, const char *machineData) {
    char bufferTX[4000];
    char local_txB[50];
    char json_data[2000];

    snprintf(json_data, sizeof(json_data), JSON_UPDATE_MACHINE_DATA, machineID, wifiSSID, wifiPass,
             devirmeYuruyusSecim, calismaSekli, emniyetCercevesi, yavaslamaLimit, altLimit,
             kapiTablaAcKonum, basincSalteri, kapiSecimleri, kapiAcTipi, kapi1Tip, kapi1AcSure,
             kapi2Tip, kapi2AcSure, kapitablaTip, kapiTablaAcSure, yukariYavasLimit, devirmeYukariIleriLimit,
             devirmeAsagiGeriLimit, devirmeSilindirTipi, platformSilindirTipi, yukariValfTmr, asagiValfTmr,
             devirmeYukariIleriTmr, devirmeAsagiGeriTmr, makineCalismaTmr, buzzer, demoMode,
             calismaSayisi, calismaSayisiDemo, dilSecim, eepromData[38], eepromData[39],
             eepromData[40], eepromData[41], eepromData[42], eepromData[43], eepromData[44],
             eepromData[45], eepromData[46], eepromData[47], lcdBacklightSure);

    snprintf(bufferTX, sizeof(bufferTX),
             "POST /api/v2/machine/updateMachineData HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Content-Type: application/json\r\n"
             "Content-Length: %d\r\n\r\n"
             "%s", MAIN_SERVER_WITH_PORT, strlen(json_data), json_data);

    int len = strlen(bufferTX);
    snprintf(local_txB, sizeof(local_txB), "AT+CIPSEND=%d\r\n", len);

    HAL_UART_Transmit_IT(huart, (uint8_t *)local_txB, strlen(local_txB));
    HAL_Delay(2000);

    HAL_UART_Transmit_IT(huart, (uint8_t *)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);
}

// Makine ID'sini kontrol eden fonksiyon
int checkMachineID(UART_HandleTypeDef *huart, const char *machineID) {
    char local_txA[1000];
    char local_txB[50];
    char bufferRX[1500];

    snprintf(local_txA, sizeof(local_txA),
             "GET /api/v2/machine/checkMachineIDRaw?machineID=%s HTTP/1.0\r\nHost: %s\r\n\r\n",
             machineID, mainServerWithPort);

    int len = strlen(local_txA);
    snprintf(local_txB, sizeof(local_txB), "AT+CIPSEND=%d\r\n", len);

    HAL_UART_Transmit_IT(huart, (uint8_t *)local_txB, strlen(local_txB));
    HAL_Delay(LONG_DELAY_MS);

    HAL_UART_Transmit_IT(huart, (uint8_t *)local_txA, strlen(local_txA));
    HAL_Delay(LONG_DELAY_MS);

    HAL_UART_Receive_IT(huart, (uint8_t *)bufferRX, sizeof(bufferRX));
    HAL_Delay(LONG_DELAY_MS);

    return strstr(bufferRX, "HTTP/1.1 200 OK") ? 1 : 0;
}

// Güncelleme kontrolü yapan fonksiyon
void checkForUpdates(UART_HandleTypeDef *huart, const char *currentVersion) {
    char checkUpdateCommand[150];
    snprintf(checkUpdateCommand, sizeof(checkUpdateCommand),
             "GET /api/v2/updateChecker/checkUpdatesRaw?currentVersion=%s HTTP/1.0\r\nHost: %s\r\n\r\n",
             currentVersion, mainServerWithPort);

    Wifi_TcpIp_StartTcpConnection(huart, 0, mainServer, 3000, 30);
    HAL_Delay(LONG_DELAY_MS);

    Wifi_TcpIp_SendDataTcp(huart, 0, strlen(checkUpdateCommand), (uint8_t *)checkUpdateCommand);
    HAL_Delay(LONG_DELAY_MS);

    HAL_UART_Receive_IT(huart, (uint8_t *)bufferRX, sizeof(bufferRX));
    HAL_Delay(LONG_DELAY_MS);

    if (strstr(bufferRX, "HTTP/1.1 200 OK")) {
        const char *updateAvailable = strstr(bufferRX, "\"updateAvailable\":true") ? "New Update Available" : "No Update Available";
        lcd_print(1, 1, updateAvailable);
    } else {
        lcd_print(1, 1, "Update Check Failed");
    }
    HAL_Delay(LONG_DELAY_MS);
    lcd_clear();
}

// Yeni versiyonu indirmek için kullanılan fonksiyon
void downloadNewVersion(UART_HandleTypeDef *huart, const char *versionCode) {
    char downloadCommand[150];
    snprintf(downloadCommand, sizeof(downloadCommand),
             "GET /api/v2/updateChecker/downloadNewVersionRaw?versionCode=%s HTTP/1.0\r\nHost: %s\r\n\r\n",
             versionCode, mainServerWithPort);

    Wifi_TcpIp_StartTcpConnection(huart, 0, "85.95.231.92", 3000, 30);
    HAL_Delay(LONG_DELAY_MS);

    Wifi_TcpIp_SendDataTcp(huart, 0, strlen(downloadCommand), (uint8_t *)downloadCommand);
    HAL_Delay(LONG_DELAY_MS);

    HAL_UART_Receive_IT(huart, (uint8_t *)bufferRX, sizeof(bufferRX));
    HAL_Delay(LONG_DELAY_MS);

    uint32_t receivedData[1024];
    int dataSize = 0;

    parseHexDataToBuffer(bufferRX, receivedData, &dataSize);

    lcd_print(1, 1, "Writing to Flash...");
    HAL_Delay(SHORT_DELAY_MS);

    writeFlash(receivedData, dataSize);
}
