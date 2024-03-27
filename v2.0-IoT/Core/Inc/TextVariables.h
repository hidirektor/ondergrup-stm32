/*
 * TextVariables.h
 *
 *  Created on: Mar 6, 2024
 *      Author: hidirektor
 */

#ifndef INC_TEXTVARIABLES_H_
#define INC_TEXTVARIABLES_H_

#include <stdint.h>

void loadMenuTexts(uint8_t dilSecim);
void menuVariableFinisher(void);

extern char menuyeGirildiText[17];
extern char ayarlarText[17];
extern char hataKayitListText[17];
extern char birHataKoduText[17];
extern char ikiHataKoduText[17];
extern char ucHataKoduText[17];
extern char dortHataKoduText[17];
extern char besHataKoduText[17];
extern char altiHataKoduText[17];
extern char yediHataKoduText[17];
extern char sekizHataKoduText[17];
extern char dokuzHataKoduText[17];
extern char onHataKoduText[17];
extern char silmekIcinText[17];
extern char calismaSekliText[17];
extern char devirmeYuruyusText[17];
extern char bastikcaCalisanText[17];
extern char basGonderText[17];
extern char emniyetCercevesiText[17];
extern char pasifText[17];
extern char aktifText[17];
extern char yavaslamaLimitText[17];
extern char altLimitText[17];
extern char basincSalteriText[17];
extern char kapiSecimleriText[17];
extern char katKapisiAktifText[17];
extern char tablaKapiAktifText[17];
extern char katArtiTablaAktifText[17];
extern char kapiAcmaTipiText[17];
extern char kapiButonuESPText[17];
extern char katButonuEXTText[17];
extern char birKatKapiTipiText[17];
extern char butonKontrolluText[17];
extern char birinciKapiAcSuresiText[17];
extern char kacSaniyeText[17];
extern char ikinciKatKapiTipiText[17];
extern char ikinciKapiAcSuresiText[17];
extern char tablaKapiTipiText[17];
extern char tablaKapiAcKonumText[17];
extern char birinciKattaAcText[17];
extern char ikinciKattaAcText[17];
extern char birVeIkinciKattaAcText[17];
extern char tablaKapiAcSureText[17];
extern char yukariYavaslamaLimitiText[17];
extern char devirmeYuruyusMenuText[17];
extern char devirmeAktifText[17];
extern char yuruyusAktifText[17];
extern char devirmeYukariText[17];
extern char yuruyusIleriText[17];
extern char devirmeAsagiSivicText[17];
extern char yuruyusGeriSivicText[17];
extern char yuruyusSecildiText[17];
extern char devirmeSilindirTipiText[17];
extern char tekTesirText[17];
extern char ciftTesirText[17];
extern char platformSilindirTipiText[17];
extern char yukariValfSureText[17];
extern char asagiValfSureText[17];
extern char devirmeYukariValfSureText[17];
extern char ileriValfSureText[17];
extern char devirmeAsagiValfSureText[17];
extern char geriValfSureText[17];
extern char calismaSuresiText[17];
extern char calismaSayisiText[17];
extern char enterlaSifirlaText[17];
extern char dilSecimText[17];
extern char secilenDilText[17];
extern char menudenCikisText[17];
extern char enteraBasinizText[17];
extern char hataKoduText[17];

//IoT Messages:
extern char dataSynchText[17];
extern char dataSynch2Text[17];
extern char mustBeUniqueText[17];
extern char mustBeUnique2Text[17];
extern char mustBe12Text[17];
extern char mustBe122Text[17];
extern char ssidExceedErrorText[17];
extern char ssidExceedError2Text[17];
extern char passExceedErrorText[17];
extern char passExceedError2Text[17];

//EEPROM Messages:
extern char dataYazildiText[17];
extern char dataOkunuyorText[17];
extern char dataOkunduText[17];
extern char degerKaydedildiText[17];

//ErrorCode Messages:
extern char errorCodeText[17];

//Hardware texts:
extern char machineIDText[17];

//Confirmation Texts:
extern char idConfirmationText[17];
extern char idConfirmationSubText[17];

extern char wifiConfirmationText[17];

#endif /* INC_TEXTVARIABLES_H_ */
