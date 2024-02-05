/*
 * WifiProcess.h
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#ifndef INC_WIFIPROCESS_H_
#define INC_WIFIPROCESS_H_

void takeMachineID(int state);
void takeWifiSSID(int state);
void takeWifiPass(int state);

char* mergeData(void);
void convertAndSendData(void);

void iotSetup(void);

#endif /* INC_WIFIPROCESS_H_ */
