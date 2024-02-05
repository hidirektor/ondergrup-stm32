/*
 * Data.h
 *
 *  Created on: Jul 27, 2023
 *      Author: hidir
 */
#ifndef INC_IOTMENU_H_
#define INC_IOTMENU_H_

#include "main.h"
#include "SystemDefaults.h"
#include "GlobalVariables.h"
#include "i2c-lcd.h"

void printTemplate(int type, int page);
int checkSlideVal(int state);
void slideText(const char* text, int startPos, int startLine, int state);

#endif /* INC_IOTMENU_H_ */
