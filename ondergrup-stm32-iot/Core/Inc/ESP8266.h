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

private:
    ESP8266() = default;
    void sendCommand(UART_HandleTypeDef *huart, const string& command, uint32_t delayMs);
    char bufferTX[500];
};

#endif /* INC_ESP8266_H_ */

