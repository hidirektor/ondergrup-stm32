/*
 * WifiProcess.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef INC_WIFIPROCESS_H_
#define INC_WIFIPROCESS_H_

#include <stdint.h>
#include <string>

class WifiProcess {
public:
    static WifiProcess& getInstance() {
        static WifiProcess instance;
        return instance;
    }

    void takeMachineIDWithConfirmation();
    void takeMachineID();
    uint8_t ssidConfirmation();
    void takeWifiSSID();
    uint8_t passConfirmation();
    void takeWifiPass();

    std::string mergeData();
    void convertAndSendData();
    std::string getCredentials(int type);

    void iotSetup();
    int checkEEPROM4ID();

private:
    WifiProcess() {}
    WifiProcess(const WifiProcess&) = delete;
    WifiProcess& operator=(const WifiProcess&) = delete;
};

#endif /* INC_WIFIPROCESS_H_ */
