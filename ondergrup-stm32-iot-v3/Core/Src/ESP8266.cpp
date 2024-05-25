/*
 * ESP8266.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#include "ESP8266.h"

using namespace std;

ESP8266& ESP8266::getInstance() {
    static ESP8266 instance;
    return instance;
}

void ESP8266::init(UART_HandleTypeDef *huart, const string& ssid, const string& password) {
    sendCommand(huart, "AT+RESTORE\r\n", 1000);
    sendCommand(huart, "AT+RST\r\n", 1000);
    sendCommand(huart, "AT\r\n", 2000);
    sendCommand(huart, "AT+CWMODE=1\r\n", 2000);

    string connectCmd = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\"\r\n";
    sendCommand(huart, connectCmd, 2000);
}

void ESP8266::sendMachineData(UART_HandleTypeDef *huart, const string& machineID, const string& machineData) {
    string subMachineID = machineID.substr(0, 12);

    string connectCmd = "AT+CIPSTART=\"TCP\",\"" + MAIN_SERVER + "\"," + to_string(MAIN_SERVER_PORT) + "\r\n";
    sendCommand(huart, connectCmd, 4000);

    string getDataCmd = "GET /api/machine/updateMachineDataRaw?machineID=" + subMachineID +
                        "&machineData=" + machineData + " HTTP/1.0\r\nHost: " + MAIN_SERVER_WITH_PORT + "\r\n\r\n";
    string sendCmd = "AT+CIPSEND=" + to_string(getDataCmd.length()) + "\r\n";

    sendCommand(huart, sendCmd, 4000);
    sendCommand(huart, getDataCmd, 3000);
}

bool ESP8266::checkMachineID(UART_HandleTypeDef *huart, const string& machineID) {
    string subMachineID = machineID.substr(0, 12);

    string connectCmd = "AT+CIPSTART=\"TCP\",\"" + MAIN_SERVER + "\"," + to_string(MAIN_SERVER_PORT) + "\r\n";
    sendCommand(huart, connectCmd, 2000);

    string checkIDCmd = "GET /api/machine/checkMachineID?machineID=" + subMachineID + " HTTP/1.0\r\nHost: " + MAIN_SERVER_WITH_PORT + "\r\n\r\n";
    string sendCmd = "AT+CIPSEND=" + to_string(checkIDCmd.length()) + "\r\n";

    sendCommand(huart, sendCmd, 4000);
    sendCommand(huart, checkIDCmd, 6000);

    char bufferRX[2000];
    HAL_UART_Receive_IT(huart, (uint8_t*) bufferRX, sizeof(bufferRX));
    HAL_Delay(5000);

    if (strstr(bufferRX, "HTTP/1.1 200 OK") || strstr(bufferRX, "HTTP/1.0 200 OK")) {
        return true; // Başarılı yanıt
    }

    return false; // Yanıt başarısız
}

void ESP8266::sendCommand(UART_HandleTypeDef *huart, const string& command, uint32_t delayMs) {
    sprintf(bufferTX, "%s", command.c_str());
    HAL_UART_Transmit_IT(huart, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(delayMs);
}



