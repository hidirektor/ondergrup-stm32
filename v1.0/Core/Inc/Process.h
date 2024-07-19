/*
 * Process.h
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#ifndef INC_PROCESS_H_
#define INC_PROCESS_H_

void lcdUpdate(uint8_t);
void bekle(void);
void checkLCDBacklight(void);
uint8_t buttonCheck(void);
void checkBasincSalteri(void);
void checkBasGonder(void);
void checkKapiSecimleri(void);
void checkAktifCalisma(void);
void checkDemoModCalisma(void);
void mainLoop(void);

#endif /* INC_PROCESS_H_ */
