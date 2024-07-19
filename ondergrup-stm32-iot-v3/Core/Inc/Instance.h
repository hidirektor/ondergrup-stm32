/*
 * Instance.h
 *
 *  Created on: Jun 10, 2024
 *      Author: hidirektor
 */

#ifndef INC_INSTANCE_H_
#define INC_INSTANCE_H_

#include "GlobalVariables.h"
#include "SystemDefaults.h"
#include "EEPROMProcess.h"
#include "ErrorProcess.h"
#include "ESP8266.h"
#include "Process.h"
#include "HardwareTest.h"
#include "WifiProcess.h"
#include "TextVariables.h"
#include "Translation.h"
#include "LCD.h"
#include "Util.h"
#include "IoTMenu.h"


extern GlobalVariables& globalVars;
extern SystemDefaults& systemDefaults;
extern EEPROMProcess& eepromProcess;
extern Translation& translation;
extern TextVariables& textVars;
extern ESP8266& esp;
extern I2CLCD& lcd;
extern Process& process;
extern WifiProcess& wifiProcess;
extern ErrorProcess& errorProcess;
extern IoTMenu& iotMenu;


#endif /* INC_INSTANCE_H_ */
