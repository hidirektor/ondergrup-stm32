/*
 * TextVariables.c
 *
 *  Created on: Mar 6, 2024
 *      Author: hidirektor
 */

#include "TextVariables.h"
#include "Translation.h"
#include "string.h"

char menuyeGirildiText[17];
char ayarlarText[17];
char hataKayitListText[17];
char birHataKoduText[17];
char ikiHataKoduText[17];
char ucHataKoduText[17];
char dortHataKoduText[17];
char besHataKoduText[17];
char altiHataKoduText[17];
char yediHataKoduText[17];
char sekizHataKoduText[17];
char dokuzHataKoduText[17];
char onHataKoduText[17];
char silmekIcinText[17];
char calismaSekliText[17];
char devirmeYuruyusText[17];
char bastikcaCalisanText[17];
char basGonderText[17];
char emniyetCercevesiText[17];
char pasifText[17];
char aktifText[17];
char yavaslamaLimitText[17];
char altLimitText[17];
char basincSalteriText[17];
char kapiSecimleriText[17];
char katKapisiAktifText[17];
char tablaKapiAktifText[17];
char katArtiTablaAktifText[17];
char kapiAcmaTipiText[17];
char kapiButonuESPText[17];
char katButonuEXTText[17];
char birKatKapiTipiText[17];
char butonKontrolluText[17];
char birinciKapiAcSuresiText[17];
char kacSaniyeText[17];
char ikinciKatKapiTipiText[17];
char ikinciKapiAcSuresiText[17];
char tablaKapiTipiText[17];
char tablaKapiAcKonumText[17];
char birinciKattaAcText[17];
char ikinciKattaAcText[17];
char birVeIkinciKattaAcText[17];
char tablaKapiAcSureText[17];
char yukariYavaslamaLimitiText[17];
char devirmeYuruyusMenuText[17];
char devirmeAktifText[17];
char yuruyusAktifText[17];
char devirmeYukariText[17];
char yuruyusIleriText[17];
char devirmeAsagiSivicText[17];
char yuruyusGeriSivicText[17];
char yuruyusSecildiText[17];
char devirmeSilindirTipiText[17];
char tekTesirText[17];
char ciftTesirText[17];
char platformSilindirTipiText[17];
char yukariValfSureText[17];
char asagiValfSureText[17];
char devirmeYukariValfSureText[17];
char ileriValfSureText[17];
char devirmeAsagiValfSureText[17];
char geriValfSureText[17];
char calismaSuresiText[17];
char calismaSayisiText[17];
char enterlaSifirlaText[17];
char dilSecimText[17];
char secilenDilText[17];
char menudenCikisText[17];
char enteraBasinizText[17];
char hataKoduText[17];

//IoT Messages:
char dataSynchText[17];
char dataSynch2Text[17];
char mustBeUniqueText[17];
char mustBeUnique2Text[17];
char mustBe12Text[17];
char mustBe122Text[17];
char ssidExceedErrorText[17];
char ssidExceedError2Text[17];
char passExceedErrorText[17];
char passExceedError2Text[17];

//EEPROM Messages:
char dataYazildiText[17];
char dataOkunuyorText[17];
char dataOkunduText[17];
char degerKaydedildiText[17];

//Error Code:
char errorCodeText[17];

//Hardware texts:
char machineIDText[17];

void loadMenuTexts(uint8_t dilSecim) {
	if(dilSecim == 0) {
		memcpy(menuyeGirildiText, menuyeGirildiTextTR, 17); //destination, source, size
		memcpy(ayarlarText, ayarlarTextTR, 17);
		memcpy(hataKayitListText, hataKayitListTextTR, 17);
		memcpy(birHataKoduText, birHataKoduTextTR, 17);
		memcpy(ikiHataKoduText, ikiHataKoduTextTR, 17);
		memcpy(ucHataKoduText, ucHataKoduTextTR, 17);
		memcpy(dortHataKoduText, dortHataKoduTextTR, 17);
		memcpy(besHataKoduText, besHataKoduTextTR, 17);
		memcpy(altiHataKoduText, altiHataKoduTextTR, 17);
		memcpy(yediHataKoduText, yediHataKoduTextTR, 17);
		memcpy(sekizHataKoduText, sekizHataKoduTextTR, 17);
		memcpy(dokuzHataKoduText, dokuzHataKoduTextTR, 17);
		memcpy(onHataKoduText, onHataKoduTextTR, 17);
		memcpy(silmekIcinText, silmekIcinTextTR, 17);
		memcpy(calismaSekliText, calismaSekliTextTR, 17);
		memcpy(devirmeYuruyusText, devirmeYuruyusTextTR, 17);
		memcpy(bastikcaCalisanText, bastikcaCalisanTextTR, 17);
		memcpy(basGonderText, basGonderTextTR, 17);
		memcpy(emniyetCercevesiText, emniyetCercevesiTextTR, 17);
		memcpy(pasifText, pasifTextTR, 17);
		memcpy(aktifText, aktifTextTR, 17);
		memcpy(yavaslamaLimitText, yavaslamaLimitTextTR, 17);
		memcpy(altLimitText, altLimitTextTR, 17);
		memcpy(basincSalteriText, basincSalteriTextTR, 17);
		memcpy(kapiSecimleriText, kapiSecimleriTextTR, 17);
		memcpy(katKapisiAktifText, katKapisiAktifTextTR, 17);
		memcpy(tablaKapiAktifText, tablaKapiAktifTextTR, 17);
		memcpy(katArtiTablaAktifText, katArtiTablaAktifTextTR, 17);
		memcpy(kapiAcmaTipiText, kapiAcmaTipiTextTR, 17);
		memcpy(kapiButonuESPText, kapiButonuESPTextTR, 17);
		memcpy(katButonuEXTText, katButonuEXTTextTR, 17);
		memcpy(birKatKapiTipiText, birKatKapiTipiTextTR, 17);
		memcpy(butonKontrolluText, butonKontrolluTextTR, 17);
		memcpy(birinciKapiAcSuresiText, birinciKapiAcSuresiTextTR, 17);
		memcpy(kacSaniyeText, kacSaniyeTextTR, 17);
		memcpy(ikinciKatKapiTipiText, ikinciKatKapiTipiTextTR, 17);
		memcpy(ikinciKapiAcSuresiText, ikinciKapiAcSuresiTextTR, 17);
		memcpy(tablaKapiTipiText, tablaKapiTipiTextTR, 17);
		memcpy(tablaKapiAcKonumText, tablaKapiAcKonumTextTR, 17);
		memcpy(birinciKattaAcText, birinciKattaAcTextTR, 17);
		memcpy(ikinciKattaAcText, ikinciKattaAcTextTR, 17);
		memcpy(birVeIkinciKattaAcText, birVeIkinciKattaAcTextTR, 17);
		memcpy(tablaKapiAcSureText, tablaKapiAcSureTextTR, 17);
		memcpy(yukariYavaslamaLimitiText, yukariYavaslamaLimitiTextTR, 17);
		memcpy(devirmeYuruyusMenuText, devirmeYuruyusMenuTextTR, 17);
		memcpy(devirmeAktifText, devirmeAktifTextTR, 17);
		memcpy(yuruyusAktifText, yuruyusAktifTextTR, 17);
		memcpy(devirmeYukariText, devirmeYukariTextTR, 17);
		memcpy(yuruyusIleriText, yuruyusIleriTextTR, 17);
		memcpy(devirmeAsagiSivicText, devirmeAsagiSivicTextTR, 17);
		memcpy(yuruyusGeriSivicText, yuruyusGeriSivicTextTR, 17);
		memcpy(yuruyusSecildiText, yuruyusSecildiTextTR, 17);
		memcpy(devirmeSilindirTipiText, devirmeSilindirTipiTextTR, 17);
		memcpy(tekTesirText, tekTesirTextTR, 17);
		memcpy(ciftTesirText, ciftTesirTextTR, 17);
		memcpy(platformSilindirTipiText, platformSilindirTipiTextTR, 17);
		memcpy(yukariValfSureText, yukariValfSureTextTR, 17);
		memcpy(asagiValfSureText, asagiValfSureTextTR, 17);
		memcpy(devirmeYukariValfSureText, devirmeYukariValfSureTextTR, 17);
		memcpy(ileriValfSureText, ileriValfSureTextTR, 17);
		memcpy(devirmeAsagiValfSureText, devirmeAsagiValfSureTextTR, 17);
		memcpy(geriValfSureText, geriValfSureTextTR, 17);
		memcpy(calismaSuresiText, calismaSuresiTextTR, 17);
		memcpy(calismaSayisiText, calismaSayisiTextTR, 17);
		memcpy(enterlaSifirlaText, enterlaSifirlaTextTR, 17);
		memcpy(dilSecimText, dilSecimTextTR, 17);
		memcpy(secilenDilText, secilenDilTextTR, 17);
		memcpy(menudenCikisText, menudenCikisTextTR, 17);
		memcpy(enteraBasinizText, enteraBasinizTextTR, 17);
		memcpy(hataKoduText, hataKoduTextTR, 17);
		memcpy(dataSynchText, dataSynchTextTR, 17);
		memcpy(dataSynch2Text, dataSynch2TextTR, 17);
		memcpy(mustBeUniqueText, mustBeUniqueTextTR, 17);
		memcpy(mustBeUnique2Text, mustBeUnique2TextTR, 17);
		memcpy(mustBe12Text, mustBe12TextTR, 17);
		memcpy(mustBe122Text, mustBe122TextTR, 17);
		memcpy(ssidExceedErrorText, ssidExceedErrorTextTR, 17);
		memcpy(ssidExceedError2Text, ssidExceedError2TextTR, 17);
		memcpy(passExceedErrorText, passExceedErrorTextTR, 17);
		memcpy(passExceedError2Text, passExceedError2TextTR, 17);
		memcpy(dataYazildiText, dataYazildiTextTR, 17);
		memcpy(dataOkunuyorText, dataOkunuyorTextTR, 17);
		memcpy(dataOkunduText, dataOkunduTextTR, 17);
		memcpy(degerKaydedildiText, degerKaydedildiTextTR, 17);
		memcpy(errorCodeText, errorCodeTextTR, 17);
		memcpy(machineIDText, machineIDTextTR, 17);
	} else {
		memcpy(menuyeGirildiText, menuyeGirildiTextEN, 17); //destination, source, size
		memcpy(ayarlarText, ayarlarTextEN, 17);
		memcpy(hataKayitListText, hataKayitListTextEN, 17);
		memcpy(birHataKoduText, birHataKoduTextEN, 17);
		memcpy(ikiHataKoduText, ikiHataKoduTextEN, 17);
		memcpy(ucHataKoduText, ucHataKoduTextEN, 17);
		memcpy(dortHataKoduText, dortHataKoduTextEN, 17);
		memcpy(besHataKoduText, besHataKoduTextEN, 17);
		memcpy(altiHataKoduText, altiHataKoduTextEN, 17);
		memcpy(yediHataKoduText, yediHataKoduTextEN, 17);
		memcpy(sekizHataKoduText, sekizHataKoduTextEN, 17);
		memcpy(dokuzHataKoduText, dokuzHataKoduTextEN, 17);
		memcpy(onHataKoduText, onHataKoduTextEN, 17);
		memcpy(silmekIcinText, silmekIcinTextEN, 17);
		memcpy(calismaSekliText, calismaSekliTextEN, 17);
		memcpy(devirmeYuruyusText, devirmeYuruyusTextEN, 17);
		memcpy(bastikcaCalisanText, bastikcaCalisanTextEN, 17);
		memcpy(basGonderText, basGonderTextEN, 17);
		memcpy(emniyetCercevesiText, emniyetCercevesiTextEN, 17);
		memcpy(pasifText, pasifTextEN, 17);
		memcpy(aktifText, aktifTextEN, 17);
		memcpy(yavaslamaLimitText, yavaslamaLimitTextEN, 17);
		memcpy(altLimitText, altLimitTextEN, 17);
		memcpy(basincSalteriText, basincSalteriTextEN, 17);
		memcpy(kapiSecimleriText, kapiSecimleriTextEN, 17);
		memcpy(katKapisiAktifText, katKapisiAktifTextEN, 17);
		memcpy(tablaKapiAktifText, tablaKapiAktifTextEN, 17);
		memcpy(katArtiTablaAktifText, katArtiTablaAktifTextEN, 17);
		memcpy(kapiAcmaTipiText, kapiAcmaTipiTextEN, 17);
		memcpy(kapiButonuESPText, kapiButonuESPTextEN, 17);
		memcpy(katButonuEXTText, katButonuEXTTextEN, 17);
		memcpy(birKatKapiTipiText, birKatKapiTipiTextEN, 17);
		memcpy(butonKontrolluText, butonKontrolluTextEN, 17);
		memcpy(birinciKapiAcSuresiText, birinciKapiAcSuresiTextEN, 17);
		memcpy(kacSaniyeText, kacSaniyeTextEN, 17);
		memcpy(ikinciKatKapiTipiText, ikinciKatKapiTipiTextEN, 17);
		memcpy(ikinciKapiAcSuresiText, ikinciKapiAcSuresiTextEN, 17);
		memcpy(tablaKapiTipiText, tablaKapiTipiTextEN, 17);
		memcpy(tablaKapiAcKonumText, tablaKapiAcKonumTextEN, 17);
		memcpy(birinciKattaAcText, birinciKattaAcTextEN, 17);
		memcpy(ikinciKattaAcText, ikinciKattaAcTextEN, 17);
		memcpy(birVeIkinciKattaAcText, birVeIkinciKattaAcTextEN, 17);
		memcpy(tablaKapiAcSureText, tablaKapiAcSureTextEN, 17);
		memcpy(yukariYavaslamaLimitiText, yukariYavaslamaLimitiTextEN, 17);
		memcpy(devirmeYuruyusMenuText, devirmeYuruyusMenuTextEN, 17);
		memcpy(devirmeAktifText, devirmeAktifTextEN, 17);
		memcpy(yuruyusAktifText, yuruyusAktifTextEN, 17);
		memcpy(devirmeYukariText, devirmeYukariTextEN, 17);
		memcpy(yuruyusIleriText, yuruyusIleriTextEN, 17);
		memcpy(devirmeAsagiSivicText, devirmeAsagiSivicTextEN, 17);
		memcpy(yuruyusGeriSivicText, yuruyusGeriSivicTextEN, 17);
		memcpy(yuruyusSecildiText, yuruyusSecildiTextEN, 17);
		memcpy(devirmeSilindirTipiText, devirmeSilindirTipiTextEN, 17);
		memcpy(tekTesirText, tekTesirTextEN, 17);
		memcpy(ciftTesirText, ciftTesirTextEN, 17);
		memcpy(platformSilindirTipiText, platformSilindirTipiTextEN, 17);
		memcpy(yukariValfSureText, yukariValfSureTextEN, 17);
		memcpy(asagiValfSureText, asagiValfSureTextEN, 17);
		memcpy(devirmeYukariValfSureText, devirmeYukariValfSureTextEN, 17);
		memcpy(ileriValfSureText, ileriValfSureTextEN, 17);
		memcpy(devirmeAsagiValfSureText, devirmeAsagiValfSureTextEN, 17);
		memcpy(geriValfSureText, geriValfSureTextEN, 17);
		memcpy(calismaSuresiText, calismaSuresiTextEN, 17);
		memcpy(calismaSayisiText, calismaSayisiTextEN, 17);
		memcpy(enterlaSifirlaText, enterlaSifirlaTextEN, 17);
		memcpy(dilSecimText, dilSecimTextEN, 17);
		memcpy(secilenDilText, secilenDilTextEN, 17);
		memcpy(menudenCikisText, menudenCikisTextEN, 17);
		memcpy(enteraBasinizText, enteraBasinizTextEN, 17);
		memcpy(hataKoduText, hataKoduTextEN, 17);
		memcpy(dataSynchText, dataSynchTextEN, 17);
		memcpy(dataSynch2Text, dataSynch2TextEN, 17);
		memcpy(mustBeUniqueText, mustBeUniqueTextEN, 17);
		memcpy(mustBeUnique2Text, mustBeUnique2TextEN, 17);
		memcpy(mustBe12Text, mustBe12TextEN, 17);
		memcpy(mustBe122Text, mustBe122TextEN, 17);
		memcpy(ssidExceedErrorText, ssidExceedErrorTextEN, 17);
		memcpy(ssidExceedError2Text, ssidExceedError2TextEN, 17);
		memcpy(passExceedErrorText, passExceedErrorTextEN, 17);
		memcpy(passExceedError2Text, passExceedError2TextEN, 17);
		memcpy(dataYazildiText, dataYazildiTextEN, 17);
		memcpy(dataOkunuyorText, dataOkunuyorTextEN, 17);
		memcpy(dataOkunduText, dataOkunduTextEN, 17);
		memcpy(degerKaydedildiText, degerKaydedildiTextEN, 17);
		memcpy(errorCodeText, errorCodeTextEN, 17);
		memcpy(machineIDText, machineIDTextEN, 17);
	}
	menuVariableFinisher();
}

void menuVariableFinisher(void) {
	splashTextGN[16] = '\0';
	splashText2GN[16] = '\0';
	mainTextGN[16] = '\0';
	mainText2GN[16] = '\0';
	ondSafetyTextGN[16] = '\0';
	prudhomeTextGN[16] = '\0';
	pizzattoTextGN[16] = '\0';
	buzzerTextGN[16] = '\0';
	demoModTextGN[16] = '\0';
	iotModTextGN[16] = '\0';
	cycleTextGN[16] = '\0';
	eepromTextGN[16] = '\0';

	menuyeGirildiText[16] = '\0';
	ayarlarText[16] = '\0';
	hataKayitListText[16] = '\0';
	birHataKoduText[16] = '\0';
	ikiHataKoduText[16] = '\0';
	ucHataKoduText[16] = '\0';
	dortHataKoduText[16] = '\0';
	besHataKoduText[16] = '\0';
	altiHataKoduText[16] = '\0';
	yediHataKoduText[16] = '\0';
	sekizHataKoduText[16] = '\0';
	dokuzHataKoduText[16] = '\0';
	onHataKoduText[16] = '\0';
	silmekIcinText[16] = '\0';
	calismaSekliText[16] = '\0';
	devirmeYuruyusText[16] = '\0';
	bastikcaCalisanText[16] = '\0';
	basGonderText[16] = '\0';
	emniyetCercevesiText[16] = '\0';
	pasifText[16] = '\0';
	aktifText[16] = '\0';
	yavaslamaLimitText[16] = '\0';
	altLimitText[16] = '\0';
	basincSalteriText[16] = '\0';
	kapiSecimleriText[16] = '\0';
	katKapisiAktifText[16] = '\0';
	tablaKapiAktifText[16] = '\0';
	katArtiTablaAktifText[16] = '\0';
	kapiAcmaTipiText[16] = '\0';
	kapiButonuESPText[16] = '\0';
	katButonuEXTText[16] = '\0';
	birKatKapiTipiText[16] = '\0';
	butonKontrolluText[16] = '\0';
	birinciKapiAcSuresiText[16] = '\0';
	kacSaniyeText[16] = '\0';
	ikinciKatKapiTipiText[16] = '\0';
	ikinciKapiAcSuresiText[16] = '\0';
	tablaKapiTipiText[16] = '\0';
	tablaKapiAcKonumText[16] = '\0';
	birinciKattaAcText[16] = '\0';
	ikinciKattaAcText[16] = '\0';
	birVeIkinciKattaAcText[16] = '\0';
	tablaKapiAcSureText[16] = '\0';
	yukariYavaslamaLimitiText[16] = '\0';
	devirmeYuruyusMenuText[16] = '\0';
	devirmeAktifText[16] = '\0';
	yuruyusAktifText[16] = '\0';
	devirmeYukariText[16] = '\0';
	yuruyusIleriText[16] = '\0';
	devirmeAsagiSivicText[16] = '\0';
	yuruyusGeriSivicText[16] = '\0';
	yuruyusSecildiText[16] = '\0';
	devirmeSilindirTipiText[16] = '\0';
	tekTesirText[16] = '\0';
	ciftTesirText[16] = '\0';
	platformSilindirTipiText[16] = '\0';
	yukariValfSureText[16] = '\0';
	asagiValfSureText[16] = '\0';
	devirmeYukariValfSureText[16] = '\0';
	ileriValfSureText[16] = '\0';
	devirmeAsagiValfSureText[16] = '\0';
	geriValfSureText[16] = '\0';
	calismaSuresiText[16] = '\0';
	calismaSayisiText[16] = '\0';
	enterlaSifirlaText[16] = '\0';
	dilSecimText[16] = '\0';
	secilenDilText[16] = '\0';
	menudenCikisText[16] = '\0';
	enteraBasinizText[16] = '\0';
	hataKoduText[16] = '\0';

	//IoT Messages:
	dataSynchText[16] = '\0';
	dataSynch2Text[16] = '\0';
	mustBeUniqueText[16] = '\0';
	mustBeUnique2Text[16] = '\0';
	mustBe12Text[16] = '\0';
	mustBe122Text[16] = '\0';
	ssidExceedErrorText[16] = '\0';
	ssidExceedError2Text[16] = '\0';
	passExceedErrorText[16] = '\0';
	passExceedError2Text[16] = '\0';

	//Eeprom Messages:
	dataYazildiText[16] = '\0';
	dataOkunuyorText[16] = '\0';
	dataOkunduText[16] = '\0';
	degerKaydedildiText[16] = '\0';

	//Error Code Messages:
	errorCodeText[16] = '\0';

	//Hardware texts:
	machineIDText[16] = '\0';
}
