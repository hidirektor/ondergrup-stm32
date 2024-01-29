/*
 * Limitations.h
 *
 *  Created on: Jan 29, 2024
 *      Author: hidirektor
 */

#ifndef INC_LIMITATIONS_H_
#define INC_LIMITATIONS_H_

#include <stdint.h>

#define eepromSize 110
#define wifiCharLimit 20

int eepromVal[] = {38, 39, 40, 41, 42, 43, 44, 45, 46, 47};
int eepromFull[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int indeksSayisi = sizeof(eepromVal)/sizeof(eepromVal[0]);
int eepromHataBaslangic = 38;

int cursorPosition = 1;
int page = 1;
char emptyArray[] = "                ";
char charactersArray[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=<>? ";

uint8_t idStartPos = 50;
uint8_t ssidStartPos = 62;
uint8_t passStartPos = 82;

#endif /* INC_LIMITATIONS_H_ */
