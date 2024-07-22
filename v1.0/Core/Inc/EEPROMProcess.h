/*
 * EEPROMProcess.h
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#ifndef INC_EEPROMPROCESS_H_
#define INC_EEPROMPROCESS_H_

#include <stdint.h>

#define PAGE_SIZE 64  // EEPROM Page Size
#define EEPROM_ADDR 0xA0  // EEPROM adresi
#define EEPROM_SIZE 256   // EEPROM Size

void eepromKontrol(void);
void firstSetup(void);
void resetEEPROM(void);
void saveEEPROM(int resultText);
void EEPROM_Write(uint16_t page, uint16_t offset, uint8_t *data, uint16_t size);
void EEPROM_Read(uint16_t page, uint16_t offset, uint8_t *data, uint16_t size);
void convertArrays(int state);

#endif /* INC_EEPROMPROCESS_H_ */
