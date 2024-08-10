/*
 * ESPDriver.h
 *
 *  Created on: Aug 10, 2024
 *      Author: hidir
 */

#ifndef INC_ESPDRIVER_H_
#define INC_ESPDRIVER_H_

#ifndef ESP8266_DRIVER_H
#define ESP8266_DRIVER_H

#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#define WIFI_RX_BUFFER_SIZE 512

// RX buffer ve buffer indexi
static uint8_t Wifi_RxBuffer[WIFI_RX_BUFFER_SIZE];
static uint16_t Wifi_RxBufferIndex = 0;

// Wifi Modları
typedef enum {
    WifiMode_Station = 1,
    WifiMode_SoftAP,
    WifiMode_StationAndSoftAP
} WifiMode_t;

// Wifi Şifreleme Türleri
typedef enum {
    WifiEncryptionType_OPEN = 0,
    WifiEncryptionType_WPA_PSK,
    WifiEncryptionType_WPA2_PSK,
    WifiEncryptionType_WPA_WPA2_PSK
} WifiEncryptionType_t;

// Wifi Rx Temizleme
void Wifi_RxClear(void);

// String Gönderme
bool Wifi_SendString(UART_HandleTypeDef *huart, char *data);

// String Bekleme
bool Wifi_WaitForString(UART_HandleTypeDef *huart, uint32_t TimeOut_ms, uint8_t *result, uint8_t CountOfParameter, ...);

// Wifi Rx Callback
void Wifi_RxCallBack(UART_HandleTypeDef *huart);
void Wifi_ProcessReceivedData(uint8_t* buffer, uint16_t length);

// ESP8266'nın Temel Fonksiyonları
bool Wifi_Init(UART_HandleTypeDef *huart);
void Wifi_Enable(void);
void Wifi_Disable(void);
bool Wifi_Restart(UART_HandleTypeDef *huart);
bool Wifi_DeepSleep(UART_HandleTypeDef *huart, uint16_t DelayMs);
bool Wifi_FactoryReset(UART_HandleTypeDef *huart);
bool Wifi_Update(UART_HandleTypeDef *huart);
bool Wifi_SetRfPower(UART_HandleTypeDef *huart, uint8_t Power_0_to_82);

// ESP8266'nın Mod Ayarları: Station, SoftAP veya her ikisi
bool Wifi_SetMode(UART_HandleTypeDef *huart, WifiMode_t WifiMode_);
bool Wifi_GetMode(UART_HandleTypeDef *huart);
bool Wifi_GetMyIp(UART_HandleTypeDef *huart);

// Station Modu İşlemleri
bool Wifi_Station_ConnectToAp(UART_HandleTypeDef *huart, char *SSID, char *Pass, char *MAC);
bool Wifi_Station_Disconnect(UART_HandleTypeDef *huart);
bool Wifi_Station_DhcpEnable(UART_HandleTypeDef *huart, bool Enable);
bool Wifi_Station_DhcpIsEnable(UART_HandleTypeDef *huart);
bool Wifi_Station_SetIp(UART_HandleTypeDef *huart, char *IP, char *GateWay, char *NetMask);

// SoftAP Modu İşlemleri
bool Wifi_SoftAp_Create(UART_HandleTypeDef *huart, char *SSID, char *password, uint8_t channel,
		WifiEncryptionType_t WifiEncryptionType, uint8_t MaxConnections_1_to_4,
		bool HiddenSSID);
bool Wifi_GetApConnection(UART_HandleTypeDef *huart);
bool Wifi_SoftAp_GetConnectedDevices(UART_HandleTypeDef *huart);

// TCP/IP İşlemleri
bool Wifi_TcpIp_GetConnectionStatus(UART_HandleTypeDef *huart);
bool Wifi_TcpIp_Ping(UART_HandleTypeDef *huart, char *PingTo);
bool Wifi_TcpIp_SetMultiConnection(UART_HandleTypeDef *huart, bool EnableMultiConnections);
bool Wifi_TcpIp_GetMultiConnection(UART_HandleTypeDef *huart);
bool Wifi_TcpIp_StartTcpConnection(UART_HandleTypeDef *huart, uint8_t LinkId, char *RemoteIp, uint16_t RemotePort,
		uint16_t TimeOut_S);
bool Wifi_TcpIp_StartUdpConnection(UART_HandleTypeDef *huart, uint8_t LinkId, char *RemoteIp, uint16_t RemotePort,
		uint16_t LocalPort);
bool Wifi_TcpIp_Close(UART_HandleTypeDef *huart, uint8_t LinkId);
bool Wifi_TcpIp_SetEnableTcpServer(UART_HandleTypeDef *huart, uint16_t PortNumber);
bool Wifi_TcpIp_SetDisableTcpServer(UART_HandleTypeDef *huart, uint16_t PortNumber);
bool Wifi_TcpIp_SendDataUdp(UART_HandleTypeDef *huart, uint8_t LinkId, uint16_t dataLen, uint8_t *data);
bool Wifi_TcpIp_SendDataTcp(UART_HandleTypeDef *huart, uint8_t LinkId, uint16_t dataLen, uint8_t *data);

#endif // ESP8266_DRIVER_H


#endif /* INC_ESPDRIVER_H_ */
