/*
 * WifiProcess.h
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include <stdint.h>

#ifndef INC_WIFIPROCESS_H_
#define INC_WIFIPROCESS_H_

void takeMachineIDWithConfirmation(void);
void takeMachineID(void);
void takeWifiSSID(void);
void takeWifiPass(void);

char* mergeData(void);
void convertAndSendData(void);
char* getCredentials(int type);

void iotSetup(void);
int checkEEPROM4ID(void);

#endif /* INC_WIFIPROCESS_H_ */
