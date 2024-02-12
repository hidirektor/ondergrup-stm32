/*
 * WifiProcess.h
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#ifndef INC_WIFIPROCESS_H_
#define INC_WIFIPROCESS_H_

void takeMachineID(void);
void takeWifiSSID(void);
void takeWifiPass(void);

char* mergeData(void);
void convertAndSendData(void);

void iotSetup(void);

void saveCharacter(int *loc, int *writeLoc, char *data, int startPos, char type);

#endif /* INC_WIFIPROCESS_H_ */
