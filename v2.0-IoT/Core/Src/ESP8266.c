#include "ESP8266.h"

#include "SystemDefaults.h"

void sendATCommand(UART_HandleTypeDef *huart1, const char *cmd, uint16_t delayAfter) {
    HAL_UART_Transmit_IT(huart1, (uint8_t*)cmd, strlen(cmd));
    HAL_Delay(delayAfter); // Bekleme süresi komuta göre ayarlanabilir
}

void ESP8266_Init(UART_HandleTypeDef *huart, const char *wifiSS, const char *wifiPA) {
    sendATCommand(huart, "AT+RESTORE\r\n", 1000);
    sendATCommand(huart, "AT+RST\r\n", 1000);
    sendATCommand(huart, "AT\r\n", 2000);
    sendATCommand(huart, "AT+CWMODE=1\r\n", 2000);

    char cmd[100]; // Komutu oluşturmak için yeterli uzunlukta bir dizi
    snprintf(cmd, sizeof(cmd), "AT+CWJAP_DEF=\"%s\",\"%s\"\r\n", wifiSS, wifiPA);
    sendATCommand(huart, cmd, 2000);
}

void sendMachineData(UART_HandleTypeDef *huart, const char *machineID, const char *machineData) {
    char cmd[200]; // Komutu oluşturmak için yeterli uzunlukta bir dizi
    snprintf(cmd, sizeof(cmd), "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
    sendATCommand(huart, cmd, 4000);

    int len = snprintf(cmd, sizeof(cmd),
        "GET /api/machine/updateMachineDataRaw?machineID=%s&machineData=%s HTTP/1.0\r\nHost: %s\r\n\r\n",
        machineID, machineData, mainServerWithPort);

    char lenCmd[50];
    snprintf(lenCmd, sizeof(lenCmd), "AT+CIPSEND=%d\r\n", len);
    sendATCommand(huart, lenCmd, 4000); // Uzunluk komutunu gönder
    sendATCommand(huart, cmd, 4000); // Asıl komutu gönder
}

int checkMachineID(UART_HandleTypeDef *huart, const char *machineID) {
    char cmd[200], lenCmd[50];
    int len;

    // TCP bağlantısını başlat
    snprintf(cmd, sizeof(cmd), "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
    sendATCommand(huart, cmd, 2000);

    // HTTP GET isteğini hazırla
    len = snprintf(cmd, sizeof(cmd),
                   "GET /api/machine/checkMachineID?machineID=%s HTTP/1.0\r\nHost: %s\r\n\r\n",
                   machineID, mainServerWithPort);
    if(len > sizeof(cmd) || len < 0) {
        return 0; // Hata durumu
    }

    // AT+CIPSEND komutunu hazırla ve gönder
    snprintf(lenCmd, sizeof(lenCmd), "AT+CIPSEND=%d\r\n", len);
    sendATCommand(huart, lenCmd, 4000); // Uzunluk komutunu gönder

    // HTTP GET isteğini gönder
    sendATCommand(huart, cmd, 4000);

    // Gelen yanıtı kontrol et
    char bufferRX[200];
    HAL_UART_Receive_IT(huart, (uint8_t*)bufferRX, sizeof(bufferRX));
    HAL_Delay(5000); // Yanıt için bekle

    if (strstr(bufferRX, "HTTP/1.1 200 OK") != NULL && strstr(bufferRX, "\"message\": \"Machine ID is available.\"") != NULL) {
        return 1; // Başarılı
    }

    return 0; // Yanıt başarısız
}
