/*
 * Instance.cpp
 *
 *  Created on: Jun 10, 2024
 *      Author: hidirektor
 */

#include "Instance.h"

#include "main.h"

GlobalVariables& globalVars = GlobalVariables::getInstance();
SystemDefaults& systemDefaults = SystemDefaults::getInstance();
EEPROMProcess& eepromProcess = EEPROMProcess::getInstance();
Translation& translation = Translation::getInstance();
TextVariables& textVars = TextVariables::getInstance();
ESP8266& esp = ESP8266::getInstance();
I2CLCD& lcd = I2CLCD::getInstance(hi2c1, 0x27);
Process& process = Process::getInstance();
WifiProcess& wifiProcess = WifiProcess::getInstance();
ErrorProcess& errorProcess = ErrorProcess::getInstance();
IoTMenu& iotMenu = IoTMenu::getInstance();
