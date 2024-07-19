/*
 * SystemDefaults.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


#include "SystemDefaults.h"

#include "Instance.h"
#include "main.h"

#include <array>
#include <cstdint>

std::array<char, 250> systemDefaults.bufferTX;

systemDefaults.idStartPos = 50;
systemDefaults.ssidStartPos = 62;
systemDefaults.passStartPos = 83;

std::string systemDefaults.emptyArray = "                ";
std::string systemDefaults.idCharactersArray = "0123456789";
std::string systemDefaults.charactersArray = " abcdefghijklmnopqrstuvwxyzABCDEFGHIİJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=<>?";

std::array<int, 10> systemDefaults.eepromVal = {38, 39, 40, 41, 42, 43, 44, 45, 46, 47};
std::array<int, 10> systemDefaults.eepromFull = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int systemDefaults.indeksSayisi = systemDefaults.eepromVal.size();
int systemDefaults.eepromHataBaslangic = 38;

const std::string systemDefaults.MAIN_SERVER = "http://85.95.231.92";
const int systemDefaults.MAIN_SERVER_PORT = 3000;
const std::string systemDefaults.MAIN_SERVER_WITH_PORT = systemDefaults.MAIN_SERVER + ":" + std::to_string(SystemDefaults::MAIN_SERVER_PORT);
