/*
 * SystemDefaults.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "SystemDefaults.h"

char bufferTX[250];
char bufferRX[250];

int idStartPos = 50;
int ssidStartPos = 62;
int passStartPos = 83;

char emptyArray[] = "                ";
char idCharactersArray[] = "0123456789";
char charactersArray[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIİJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=<>?";

int eepromVal[10] = {38, 39, 40, 41, 42, 43, 44, 45, 46, 47};
int eepromFull[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int indeksSayisi = sizeof(eepromVal)/sizeof(eepromVal[0]);
int eepromHataBaslangic = 38;

