/*
 * ErrorProcess.h
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#ifndef INC_ERRORPROCESS_H_
#define INC_ERRORPROCESS_H_

#include <stdint.h>

void hata2EEPROM(uint8_t);
void hataKoduLcdGoster(uint8_t);
void eepromDataFillWithEmpty(void);


#endif /* INC_ERRORPROCESS_H_ */
