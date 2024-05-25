/*
 * ESP8266.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef INC_ESP8266_H_
#define INC_ESP8266_H_

#include "stm32f1xx_hal.h"
#include "SystemDefaults.h"
#include "JSONParser.h"
#include <string>
#include <cstring>

using namespace std;

enum class WiFiMode {
    STA = 1,
    AP,
    STA_AP
};

class ESP8266 {
public:
    static ESP8266& getInstance();
    void init(UART_HandleTypeDef *huart, const string& ssid, const string& password);
    void sendMachineData(UART_HandleTypeDef *huart, const string& machineID, const string& machineData);
    bool checkMachineID(UART_HandleTypeDef *huart, const string& machineID);
    bool checkForUpdate(UART_HandleTypeDef *huart, const string& currentVersion, string& newVersion, int& fileSize, string& crc);
    bool downloadNewVersion(UART_HandleTypeDef *huart, const string& versionCode, uint8_t* buffer, int bufferSize);
    bool verifyCRC(uint8_t* data, int size, const string& expectedCRC);
    void updateFirmware(UART_HandleTypeDef *huart, uint8_t* data, int size);

private:
    ESP8266() = default;
    void sendCommand(UART_HandleTypeDef *huart, const string& command, uint32_t delayMs);
    char bufferTX[500];
};

#endif /* INC_ESP8266_H_ */
