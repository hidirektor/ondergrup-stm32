/*
 * ESPDriver.c
 *
 *  Created on: Aug 10, 2024
 *      Author: hidir
 */

#include "ESPDriver.h"
#include "GlobalVariables.h"

void Wifi_RxClear(void) {
    memset(esp8266_rx_buffer, 0, sizeof(esp8266_rx_buffer));
}

bool Wifi_SendString(UART_HandleTypeDef *huart, char *data) {
    return HAL_UART_Transmit(huart, (uint8_t *)data, strlen(data), HAL_MAX_DELAY) == HAL_OK;
}

bool Wifi_WaitForString(UART_HandleTypeDef *huart, uint32_t TimeOut_ms, uint8_t *result, uint8_t CountOfParameter, ...) {
    uint32_t tickstart = HAL_GetTick();
    memset(esp8266_rx_buffer, 0, sizeof(esp8266_rx_buffer));
    int index = 0;
    va_list args;
    va_start(args, CountOfParameter);

    while ((HAL_GetTick() - tickstart) < TimeOut_ms) {
        if (HAL_UART_Receive(huart, (uint8_t *)&esp8266_rx_buffer[index], 1, 100) == HAL_OK) {
            if (esp8266_rx_buffer[index] == '\n') {
                for (uint8_t i = 0; i < CountOfParameter; i++) {
                    if (strstr(esp8266_rx_buffer, va_arg(args, char *)) != NULL) {
                        *result = i;
                        va_end(args);
                        return true;
                    }
                }
            }
            index++;
        }
    }
    va_end(args);
    return false;
}

void Wifi_RxCallBack(UART_HandleTypeDef *huart) {
    // Gelen byte'ı okuyun
    uint8_t receivedByte;

    // Gelen byte'ı UART'tan okuyun (örneğin, HAL_UART_Receive_IT ile)
    if (HAL_UART_Receive_IT(&huart, &receivedByte, 1) == HAL_OK) {
        // RX buffer doluysa, başa sarın
        if (Wifi_RxBufferIndex >= WIFI_RX_BUFFER_SIZE) {
            Wifi_RxBufferIndex = 0;
        }

        // Gelen byte'ı buffer'a ekleyin
        Wifi_RxBuffer[Wifi_RxBufferIndex++] = receivedByte;

        // Gelen byte yeni bir satır başlatıyorsa veya sonlandırıyorsa, buffer'ı işleme alınabilir
        if (receivedByte == '\n' || receivedByte == '\r') {
            // Gelen veriyi işlemek için fonksiyonu çağırın
            Wifi_ProcessReceivedData(Wifi_RxBuffer, Wifi_RxBufferIndex);

            // Buffer'ı temizleyin
            Wifi_RxBufferIndex = 0;
            memset(Wifi_RxBuffer, 0, WIFI_RX_BUFFER_SIZE);
        }
    }
}

void Wifi_ProcessReceivedData(uint8_t* buffer, uint16_t length) {
    // Gelen veriyi işleyin
    // Örneğin, belirli bir komutu veya cevabı kontrol edebilir ve işlem yapabilirsiniz

    // Gelen veriyi global değişkene aktaralım
    memcpy(esp8266_rx_buffer, buffer, length);

    // Belirli bir stringi aramak için kullanabilirsiniz (örneğin, "OK" yanıtı)
    if (strstr((char*)buffer, "OK") != NULL) {
        // "OK" yanıtı bulundu, işlem yapabilirsiniz
    }
}

bool Wifi_Init(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT\r\n") &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

void Wifi_Enable(void) {
    // Wifi açma işlemleri buraya eklenecek
}

void Wifi_Disable(void) {
    // Wifi kapama işlemleri buraya eklenecek
}

bool Wifi_Restart(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+RST\r\n") &&
           Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

bool Wifi_DeepSleep(UART_HandleTypeDef *huart, uint16_t DelayMs) {
    char cmd[64];
    sprintf(cmd, "AT+GSLP=%d\r\n", DelayMs);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

bool Wifi_FactoryReset(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+RESTORE\r\n") &&
           Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

bool Wifi_Update(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+CIUPDATE\r\n"); //&&
           //Wifi_WaitForString(huart, 60000, NULL, 1, "OK");
}

bool Wifi_SetRfPower(UART_HandleTypeDef *huart, uint8_t Power_0_to_82) {
    char cmd[64];
    sprintf(cmd, "AT+RFPOWER=%d\r\n", Power_0_to_82);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

bool Wifi_SetMode(UART_HandleTypeDef *huart, WifiMode_t WifiMode_) {
    char cmd[32];
    sprintf(cmd, "AT+CWMODE=%d\r\n", WifiMode_);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

bool Wifi_GetMode(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+CWMODE?\r\n"); //&&
           //Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

bool Wifi_GetMyIp(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+CIFSR\r\n"); //&&
           //Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

bool Wifi_Station_ConnectToAp(UART_HandleTypeDef *huart, char *SSID, char *Pass, char *MAC) {
    char cmd[256];
    sprintf(cmd, "AT+CWJAP=\"%s\",\"%s\"\r\n", SSID, Pass);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

bool Wifi_Station_Disconnect(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+CWQAP\r\n"); //&&
           //Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

bool Wifi_Station_DhcpEnable(UART_HandleTypeDef *huart, bool Enable) {
    char cmd[32];
    sprintf(cmd, "AT+CWDHCP=1,%d\r\n", Enable ? 1 : 0);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

bool Wifi_Station_DhcpIsEnable(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+CWDHCP?\r\n"); //&&
           //Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

bool Wifi_Station_SetIp(UART_HandleTypeDef *huart, char *IP, char *GateWay, char *NetMask) {
    char cmd[128];
    sprintf(cmd, "AT+CIPSTA=\"%s\",\"%s\",\"%s\"\r\n", IP, GateWay, NetMask);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

bool Wifi_SoftAp_Create(UART_HandleTypeDef *huart, char *SSID, char *password, uint8_t channel,
                        WifiEncryptionType_t WifiEncryptionType, uint8_t MaxConnections_1_to_4,
                        bool HiddenSSID) {
    char cmd[256];
    sprintf(cmd, "AT+CWSAP=\"%s\",\"%s\",%d,%d,%d,%d\r\n", SSID, password, channel, WifiEncryptionType, MaxConnections_1_to_4, HiddenSSID ? 1 : 0);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

bool Wifi_GetApConnection(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+CWJAP?\r\n"); //&&
           //Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

bool Wifi_SoftAp_GetConnectedDevices(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+CWLIF\r\n"); //&&
           //Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

bool Wifi_TcpIp_GetConnectionStatus(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+CIPSTATUS\r\n"); //&&
           //Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

bool Wifi_TcpIp_Ping(UART_HandleTypeDef *huart, char *PingTo) {
    char cmd[128];
    sprintf(cmd, "AT+PING=\"%s\"\r\n", PingTo);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

bool Wifi_TcpIp_SetMultiConnection(UART_HandleTypeDef *huart, bool EnableMultiConnections) {
    char cmd[32];
    sprintf(cmd, "AT+CIPMUX=%d\r\n", EnableMultiConnections ? 1 : 0);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

bool Wifi_TcpIp_GetMultiConnection(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, "AT+CIPMUX?\r\n"); //&&
           //Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

bool Wifi_TcpIp_StartTcpConnection(UART_HandleTypeDef *huart, uint8_t LinkId, char *RemoteIp, uint16_t RemotePort,
                                   uint16_t TimeOut_S) {
    char cmd[128];
    sprintf(cmd, "AT+CIPSTART=%d,\"TCP\",\"%s\",%d,%d\r\n", LinkId, RemoteIp, RemotePort, TimeOut_S);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

bool Wifi_TcpIp_StartUdpConnection(UART_HandleTypeDef *huart, uint8_t LinkId, char *RemoteIp, uint16_t RemotePort,
                                   uint16_t LocalPort) {
    char cmd[128];
    sprintf(cmd, "AT+CIPSTART=%d,\"UDP\",\"%s\",%d,%d\r\n", LinkId, RemoteIp, RemotePort, LocalPort);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

bool Wifi_TcpIp_Close(UART_HandleTypeDef *huart, uint8_t LinkId) {
    char cmd[32];
    sprintf(cmd, "AT+CIPCLOSE=%d\r\n", LinkId);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

bool Wifi_TcpIp_SetEnableTcpServer(UART_HandleTypeDef *huart, uint16_t PortNumber) {
    char cmd[64];
    sprintf(cmd, "AT+CIPSERVER=1,%d\r\n", PortNumber);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

bool Wifi_TcpIp_SetDisableTcpServer(UART_HandleTypeDef *huart, uint16_t PortNumber) {
    char cmd[64];
    sprintf(cmd, "AT+CIPSERVER=0,%d\r\n", PortNumber);
    return Wifi_SendString(huart, cmd); //&&
           //Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

bool Wifi_TcpIp_SendDataUdp(UART_HandleTypeDef *huart, uint8_t LinkId, uint16_t dataLen, uint8_t *data) {
    char cmd[64];
    sprintf(cmd, "AT+CIPSEND=%d,%d\r\n", LinkId, dataLen);
    if (!Wifi_SendString(huart, cmd)){ //||
        //!Wifi_WaitForString(huart, 5000, NULL, 1, ">")) {
        return false;
    }
    HAL_UART_Transmit(huart, data, dataLen, HAL_MAX_DELAY);
    return true;
    //return Wifi_WaitForString(huart, 10000, NULL, 1, "SEND OK");
}

bool Wifi_TcpIp_SendDataTcp(UART_HandleTypeDef *huart, uint8_t LinkId, uint16_t dataLen, uint8_t *data) {
    char cmd[64];
    sprintf(cmd, "AT+CIPSEND=%d,%d\r\n", LinkId, dataLen);
    if (!Wifi_SendString(huart, cmd)){ //||
        //!Wifi_WaitForString(huart, 5000, NULL, 1, ">")) {
        return false;
    }
    HAL_UART_Transmit(huart, data, dataLen, HAL_MAX_DELAY);
    return true;
    //return Wifi_WaitForString(huart, 10000, NULL, 1, "SEND OK");
}
