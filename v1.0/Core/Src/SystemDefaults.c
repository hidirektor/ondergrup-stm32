/*
 * SystemDefaults.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "SystemDefaults.h"

char emptyArray[] = "                ";

int eepromVal[10] = {38, 39, 40, 41, 42, 43, 44, 45, 46, 47};
int eepromFull[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int indeksSayisi = sizeof(eepromVal)/sizeof(eepromVal[0]);
int eepromHataBaslangic = 38;

