/*
 * ESPDriver.c
 *
 *  Created on: Aug 10, 2024
 *      Author: hidir
 */

#include "ESPDriver.h"
#include "GlobalVariables.h"
#include <stdio.h>

void Wifi_RxClear(void) {
    memset(esp8266_rx_buffer, 0, sizeof(esp8266_rx_buffer));
    Wifi_RxBufferIndex = 0;  // Ayrıca buffer indexi sıfırlayın
}

int Wifi_SendString(UART_HandleTypeDef *huart, char *data) {
    return HAL_UART_Transmit(huart, (uint8_t *)data, strlen(data), HAL_MAX_DELAY) == HAL_OK ? 1 : 0;
}

int Wifi_WaitForString(UART_HandleTypeDef *huart, uint32_t TimeOut_ms, uint8_t *result, uint8_t CountOfParameter, ...) {
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
                        return 1;
                    }
                }
            }
            index++;
        } else {
            HAL_UART_AbortReceive(huart);  // Hatalı durumu temizle
            HAL_UART_Receive_IT(huart, (uint8_t *)&esp8266_rx_buffer[index], 1); // Tekrar başlat
        }
    }
    *result = 0xFF;
    va_end(args);
    return 0;
}

void Wifi_RxCallBack(UART_HandleTypeDef *huart) {
    uint8_t receivedByte;

    if (HAL_UART_Receive_IT(huart, &receivedByte, 1) == HAL_OK) {
        if (Wifi_RxBufferIndex >= WIFI_RX_BUFFER_SIZE) {
            Wifi_RxBufferIndex = 0;  // Bu aşamada veriyi yeniden başlatmak yerine işleyin
        }

        Wifi_RxBuffer[Wifi_RxBufferIndex++] = receivedByte;

        if (receivedByte == '\n' || receivedByte == '\r') {
            Wifi_ProcessReceivedData(Wifi_RxBuffer, Wifi_RxBufferIndex);
            Wifi_RxBufferIndex = 0;
            memset(Wifi_RxBuffer, 0, WIFI_RX_BUFFER_SIZE);
        }
    }
}

void Wifi_ProcessReceivedData(uint8_t* buffer, uint16_t length) {
    memcpy(esp8266_rx_buffer, buffer, length);

    if (strstr((char*)buffer, "OK") != NULL) {
        // "OK" yanıtı bulundu, diğer işlemler yapılabilir
    }
}

int Wifi_Init(UART_HandleTypeDef *huart) {
    if (!Wifi_SendString(huart, AT_CMD)) {
        return 0;
    }

    uint8_t result;
    if (!Wifi_WaitForString(huart, 2000, &result, 2, "OK", "ERROR")) {
        return 0;
    }

    if (result == 1) {
        return 0;
    }

    return 1;
}

void Wifi_Enable(void) {
    // Wifi açma işlemleri buraya eklenecek
}

void Wifi_Disable(void) {
    // Wifi kapama işlemleri buraya eklenecek
}

int Wifi_Restart(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_RST_CMD) &&
           Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

int Wifi_DeepSleep(UART_HandleTypeDef *huart, uint16_t DelayMs) {
    char cmd[64];
    sprintf(cmd, AT_GSLP_CMD, DelayMs);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

int Wifi_FactoryReset(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_RESTORE_CMD) &&
           Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

int Wifi_Update(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_CIUPDATE_CMD) &&
           Wifi_WaitForString(huart, 60000, NULL, 1, "OK");
}

int Wifi_SetRfPower(UART_HandleTypeDef *huart, uint8_t Power_0_to_82) {
    char cmd[64];
    sprintf(cmd, AT_RFPOWER_CMD, Power_0_to_82);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

int Wifi_SetMode(UART_HandleTypeDef *huart, WifiMode_t WifiMode_) {
    char cmd[32];
    sprintf(cmd, AT_CWMODE_CMD, WifiMode_);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

int Wifi_GetMode(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_CWMODE_QUERY_CMD) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

int Wifi_GetMyIp(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_CIFSR_CMD) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

int Wifi_Station_ConnectToAp(UART_HandleTypeDef *huart, char *SSID, char *Pass, char *MAC) {
    char cmd[256];
    sprintf(cmd, AT_CWJAP_CMD, SSID, Pass);

    if (Wifi_SendString(huart, cmd)) {
        uint8_t result;
        if (Wifi_WaitForString(huart, 20000, &result, 2, "OK", "FAIL")) {
            if (result == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    return 0;
}

int Wifi_Station_Disconnect(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_CWQAP_CMD) &&
           Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

int Wifi_Station_DhcpEnable(UART_HandleTypeDef *huart, bool Enable) {
    char cmd[32];
    sprintf(cmd, AT_CWDHCP_CMD, Enable ? 1 : 0);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

int Wifi_Station_DhcpIsEnable(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_CWDHCP_QUERY_CMD) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

int Wifi_Station_SetIp(UART_HandleTypeDef *huart, char *IP, char *GateWay, char *NetMask) {
    char cmd[128];
    sprintf(cmd, AT_CIPSTA_CMD, IP, GateWay, NetMask);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

int Wifi_SoftAp_Create(UART_HandleTypeDef *huart, char *SSID, char *password, uint8_t channel,
                        WifiEncryptionType_t WifiEncryptionType, uint8_t MaxConnections_1_to_4,
                        bool HiddenSSID) {
    char cmd[256];
    sprintf(cmd, AT_CWSAP_CMD, SSID, password, channel, WifiEncryptionType, MaxConnections_1_to_4, HiddenSSID ? 1 : 0);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

int Wifi_GetApConnection(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_CWJAP_QUERY_CMD) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

int Wifi_SoftAp_GetConnectedDevices(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_CWLIF_CMD) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

int Wifi_TcpIp_GetConnectionStatus(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_CIPSTATUS_CMD) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

int Wifi_TcpIp_Ping(UART_HandleTypeDef *huart, char *PingTo) {
    char cmd[128];
    sprintf(cmd, AT_PING_CMD, PingTo);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

int Wifi_TcpIp_SetMultiConnection(UART_HandleTypeDef *huart, bool EnableMultiConnections) {
    char cmd[32];
    sprintf(cmd, AT_CIPMUX_CMD, EnableMultiConnections ? 1 : 0);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

int Wifi_TcpIp_GetMultiConnection(UART_HandleTypeDef *huart) {
    return Wifi_SendString(huart, AT_CIPMUX_QUERY_CMD) &&
           Wifi_WaitForString(huart, 1000, NULL, 1, "OK");
}

int Wifi_TcpIp_StartTcpConnection(UART_HandleTypeDef *huart, uint8_t LinkId, char *RemoteIp, uint16_t RemotePort,
                                   uint16_t TimeOut_S) {
    char cmd[128];
    sprintf(cmd, AT_CIPSTART_TCP_CMD, LinkId, RemoteIp, RemotePort, TimeOut_S);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

int Wifi_TcpIp_StartUdpConnection(UART_HandleTypeDef *huart, uint8_t LinkId, char *RemoteIp, uint16_t RemotePort,
                                   uint16_t LocalPort) {
    char cmd[128];
    sprintf(cmd, AT_CIPSTART_UDP_CMD, LinkId, RemoteIp, RemotePort, LocalPort);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

int Wifi_TcpIp_Close(UART_HandleTypeDef *huart, uint8_t LinkId) {
    char cmd[32];
    sprintf(cmd, AT_CIPCLOSE_CMD, LinkId);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 5000, NULL, 1, "OK");
}

int Wifi_TcpIp_SetEnableTcpServer(UART_HandleTypeDef *huart, uint16_t PortNumber) {
    char cmd[64];
    sprintf(cmd, AT_CIPSERVER_ENABLE_CMD, PortNumber);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

int Wifi_TcpIp_SetDisableTcpServer(UART_HandleTypeDef *huart, uint16_t PortNumber) {
    char cmd[64];
    sprintf(cmd, AT_CIPSERVER_DISABLE_CMD, PortNumber);
    return Wifi_SendString(huart, cmd) &&
           Wifi_WaitForString(huart, 10000, NULL, 1, "OK");
}

int Wifi_TcpIp_SendDataUdp(UART_HandleTypeDef *huart, uint8_t LinkId, uint16_t dataLen, uint8_t *data) {
    char cmd[64];
    sprintf(cmd, AT_CIPSEND_CMD, LinkId, dataLen);
    if (!Wifi_SendString(huart, cmd) ||
        !Wifi_WaitForString(huart, 5000, NULL, 1, ">")) {
        return 0;
    }
    HAL_UART_Transmit(huart, data, dataLen, HAL_MAX_DELAY);
    return Wifi_WaitForString(huart, 10000, NULL, 1, "SEND OK");
}

int Wifi_TcpIp_SendDataTcp(UART_HandleTypeDef *huart, uint8_t LinkId, uint16_t dataLen, uint8_t *data) {
    char cmd[64];
    sprintf(cmd, AT_CIPSEND_CMD, LinkId, dataLen);
    if (!Wifi_SendString(huart, cmd) ||
        !Wifi_WaitForString(huart, 5000, NULL, 1, ">")) {
        return 0;
    }
    HAL_UART_Transmit(huart, data, dataLen, HAL_MAX_DELAY);
    return Wifi_WaitForString(huart, 10000, NULL, 1, "SEND OK");
}
