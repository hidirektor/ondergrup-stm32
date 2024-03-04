/*
 * SystemDefaults.h
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#ifndef INC_SYSTEMDEFAULTS_H_
#define INC_SYSTEMDEFAULTS_H_

#define machineIDCharacterLimit 12
#define wifiCharacterLimit 20
#define lcdBacklightSure  6 //Buradaki değer 10 ile çarpılıyor. Maksimum 90 saniyeyi destekler.

#define demoWifiSSID "ONDERLIFT_PERSONEL"
#define demoWifiPass "PersonelOt2022*-"

#define mainServer "85.95.231.92"
#define mainServerWithPort "85.95.231.92:3000"
extern char bufferTX[250];

extern int idStartPos;
extern int ssidStartPos;
extern int passStartPos;

extern char emptyArray[];
extern char idCharactersArray[];
extern char charactersArray[];

extern int eepromVal[10];
extern int eepromFull[10];
extern int indeksSayisi;
extern int eepromHataBaslangic;

#endif /* INC_SYSTEMDEFAULTS_H_ */
