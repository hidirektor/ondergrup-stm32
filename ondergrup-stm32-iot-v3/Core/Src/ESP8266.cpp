/*
 * ESP8266.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#include "ESP8266.h"
#include "main.h"
#include "JSONParser.h"
#include <iomanip>

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

    string connectCmd = "AT+CIPSTART=\"TCP\",\"" + systemDefaults.MAIN_SERVER + "\"," + to_string(systemDefaults.MAIN_SERVER_PORT) + "\r\n";
    sendCommand(huart, connectCmd, 4000);

    string getDataCmd = "GET /api/machine/updateMachineDataRaw?machineID=" + subMachineID +
                        "&machineData=" + machineData + " HTTP/1.0\r\nHost: " + systemDefaults.MAIN_SERVER_WITH_PORT + "\r\n\r\n";
    string sendCmd = "AT+CIPSEND=" + to_string(getDataCmd.length()) + "\r\n";

    sendCommand(huart, sendCmd, 4000);
    sendCommand(huart, getDataCmd, 3000);
}

bool ESP8266::checkMachineID(UART_HandleTypeDef *huart, const string& machineID) {
    string subMachineID = machineID.substr(0, 12);

    string connectCmd = "AT+CIPSTART=\"TCP\",\"" + systemDefaults.MAIN_SERVER + "\"," + to_string(systemDefaults.MAIN_SERVER_PORT) + "\r\n";
    sendCommand(huart, connectCmd, 2000);

    string checkIDCmd = "GET /api/machine/checkMachineID?machineID=" + subMachineID + " HTTP/1.0\r\nHost: " + systemDefaults.MAIN_SERVER_WITH_PORT + "\r\n\r\n";
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

bool ESP8266::checkForUpdate(UART_HandleTypeDef *huart, const string& currentVersion, string& newVersion, int& fileSize, string& crc) {
    string checkUpdateCmd = "GET /api/update/checkUpdates HTTP/1.0\r\nHost: " + systemDefaults.MAIN_SERVER_WITH_PORT + "\r\nContent-Type: application/json\r\nContent-Length: " + to_string(currentVersion.length()) + "\r\n\r\n" + "{\"currentVersion\":\"" + currentVersion + "\"}\r\n";
    sendCommand(huart, "AT+CIPSEND=" + to_string(checkUpdateCmd.length()) + "\r\n", 4000);
    sendCommand(huart, checkUpdateCmd, 3000);

    char bufferRX[2000];
    HAL_UART_Receive_IT(huart, (uint8_t*) bufferRX, sizeof(bufferRX));
    HAL_Delay(5000);

    JSONParser parser;
    if (parser.parse(bufferRX)) {
        bool updateAvailable = parser.getBool("updateAvailable");
        if (updateAvailable) {
            newVersion = parser.getString("update.version");
            fileSize = parser.getInt("update.fileSize");
            crc = parser.getString("update.crc");
            return true;
        }
    }

    return false;
}

bool ESP8266::downloadNewVersion(UART_HandleTypeDef *huart, const string& versionCode, uint8_t* buffer, int bufferSize) {
    string downloadCmd = "GET /api/update/downloadNewVersion HTTP/1.0\r\nHost: " + systemDefaults.MAIN_SERVER_WITH_PORT + "\r\nContent-Type: application/json\r\nContent-Length: " + to_string(versionCode.length()) + "\r\n\r\n" + "{\"versionCode\":\"" + versionCode + "\"}\r\n";
    sendCommand(huart, "AT+CIPSEND=" + to_string(downloadCmd.length()) + "\r\n", 4000);
    sendCommand(huart, downloadCmd, 3000);

    memset(buffer, 0, bufferSize); // reset Buffer
    HAL_UART_Receive(huart, buffer, bufferSize, HAL_MAX_DELAY);

    if (strstr((char*)buffer, "HTTP/1.1 200 OK") != NULL || strstr((char*)buffer, "HTTP/1.0 200 OK") != NULL) {
        char* dataStart = strstr((char*)buffer, "\r\n\r\n");
        if (dataStart != NULL) {
            dataStart += 4; // "\r\n\r\n" atla
            int dataSize = bufferSize - (dataStart - (char*)buffer);

            if (dataSize > 0 && dataSize <= bufferSize) {
                memmove(buffer, dataStart, dataSize); // Data to buffer
                return true;
            }
        }
    }

    return false; // Download error
}


bool ESP8266::verifyCRC(uint8_t* data, int size, const string& expectedCRC) {
    CRC_HandleTypeDef hcrc;
    hcrc.Instance = CRC;
    uint32_t crc = HAL_CRC_Calculate(&hcrc, (uint32_t*)data, size / 4);
    stringstream ss;
    ss << hex << setw(8) << setfill('0') << crc;
    return ss.str() == expectedCRC;
}

void ESP8266::updateFirmware(UART_HandleTypeDef *huart, uint8_t* data, int size) {
    HAL_FLASH_Unlock();
    uint32_t Address = 0x08008000;  // Başlangıç adresi
    for (int i = 0; i < size; i += 2) {
        uint16_t data16 = data[i] | (data[i + 1] << 8);
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, Address, data16);
        Address += 2;
    }
    HAL_FLASH_Lock();

    // Reset system
    NVIC_SystemReset();
}

void ESP8266::sendCommand(UART_HandleTypeDef *huart, const string& command, uint32_t delayMs) {
    sprintf(bufferTX, "%s", command.c_str());
    HAL_UART_Transmit_IT(huart, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(delayMs);
}
