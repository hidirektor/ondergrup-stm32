/*
 * EEPROMProcess.h
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#ifndef INC_EEPROMPROCESS_H_
#define INC_EEPROMPROCESS_H_

#include <stdint.h>

void eepromKontrol(void);
char getCharFromCursorPosition(int cursorPosition);
char getIDCharFromCursorPosition(uint8_t selectedInt);
void writeToEEPROM(int state);
void readFromEEPROM(int state);

#endif /* INC_EEPROMPROCESS_H_ */
