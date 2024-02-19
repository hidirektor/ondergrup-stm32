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
void convertArrays(int state);
void resetEEPROM4Wifi(int state);
void customArrayConvert(const uint8_t *inputArray, int state);

#endif /* INC_EEPROMPROCESS_H_ */
