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
void readFromEEPROM(int state);
void convertArrays(int state);

#endif /* INC_EEPROMPROCESS_H_ */
