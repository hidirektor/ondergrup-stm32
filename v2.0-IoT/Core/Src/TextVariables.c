/*
 * TextVariables.c
 *
 *  Created on: Mar 6, 2024
 *      Author: hidirektor
 */

#include "TextVariables.h"
#include "Translation.h"
#include "string.h"

char menuyeGirildiText[16];
char ayarlarText[16];
char hataKayitListText[16];
char birHataKoduText[16];
char ikiHataKoduText[16];
char ucHataKoduText[16];
char dortHataKoduText[16];
char besHataKoduText[16];
char altiHataKoduText[16];
char yediHataKoduText[16];
char sekizHataKoduText[16];
char dokuzHataKoduText[16];
char onHataKoduText[16];
char silmekIcinText[16];
char calismaSekliText[16];
char devirmeYuruyusText[16];
char bastikcaCalisanText[16];
char basGonderText[16];
char emniyetCercevesiText[16];
char pasifText[16];
char aktifText[16];
char yavaslamaLimitText[16];
char altLimitText[16];
char basincSalteriText[16];
char kapiSecimleriText[16];
char katKapisiAktifText[16];
char tablaKapiAktifText[16];
char katArtiTablaAktifText[16];
char kapiAcmaTipiText[16];
char kapiButonuESPText[16];
char katButonuEXTText[16];
char birKatKapiTipiText[16];
char butonKontrolluText[16];
char birinciKapiAcSuresiText[16];
char kacSaniyeText[16];
char ikinciKatKapiTipiText[16];
char ikinciKapiAcSuresiText[16];
char tablaKapiTipiText[16];
char tablaKapiAcKonumText[16];
char birinciKattaAcText[16];
char ikinciKattaAcText[16];
char birVeIkinciKattaAcText[16];
char tablaKapiAcSureText[16];
char yukariYavaslamaLimitiText[16];
char devirmeYuruyusMenuText[16];
char devirmeAktifText[16];
char yuruyusAktifText[16];
char devirmeYukariText[16];
char yuruyusIleriText[16];
char devirmeAsagiSivicText[16];
char yuruyusGeriSivicText[16];
char yuruyusSecildiText[16];
char devirmeSilindirTipiText[16];
char tekTesirText[16];
char ciftTesirText[16];
char platformSilindirTipiText[16];
char yukariValfSureText[16];
char asagiValfSureText[16];
char devirmeYukariValfSureText[16];
char ileriValfSureText[16];
char devirmeAsagiValfSureText[16];
char geriValfSureText[16];
char calismaSuresiText[16];
char calismaSayisiText[16];
char enterlaSifirlaText[16];
char dilSecimText[16];
char secilenDilText[16];
char menudenCikisText[16];
char enteraBasinizText[16];
char hataKoduText[16];

//IoT Messages:
char dataSynchText[16];
char dataSynch2Text[16];
char mustBeUniqueText[16];
char mustBeUnique2Text[16];
char mustBe12Text[16];
char mustBe122Text[16];
char ssidExceedErrorText[16];
char ssidExceedError2Text[16];
char passExceedErrorText[16];
char passExceedError2Text[16];

void loadMenuTexts(uint8_t dilSecim) {
	if(dilSecim == 0) {
		memcpy(menuyeGirildiText, menuyeGirildiTextTR, 16); //destination, source, size
		memcpy(ayarlarText, ayarlarTextTR, 16);
		memcpy(hataKayitListText, hataKayitListTextTR, 16);
		memcpy(birHataKoduText, birHataKoduTextTR, 16);
		memcpy(ikiHataKoduText, ikiHataKoduTextTR, 16);
		memcpy(ucHataKoduText, ucHataKoduTextTR, 16);
		memcpy(dortHataKoduText, dortHataKoduTextTR, 16);
		memcpy(besHataKoduText, besHataKoduTextTR, 16);
		memcpy(altiHataKoduText, altiHataKoduTextTR, 16);
		memcpy(yediHataKoduText, yediHataKoduTextTR, 16);
		memcpy(sekizHataKoduText, sekizHataKoduTextTR, 16);
		memcpy(dokuzHataKoduText, dokuzHataKoduTextTR, 16);
		memcpy(onHataKoduText, onHataKoduTextTR, 16);
		memcpy(silmekIcinText, silmekIcinTextTR, 16);
		memcpy(calismaSekliText, calismaSekliTextTR, 16);
		memcpy(devirmeYuruyusText, devirmeYuruyusTextTR, 16);
		memcpy(bastikcaCalisanText, bastikcaCalisanTextTR, 16);
		memcpy(basGonderText, basGonderTextTR, 16);
		memcpy(emniyetCercevesiText, emniyetCercevesiTextTR, 16);
		memcpy(pasifText, pasifTextTR, 16);
		memcpy(aktifText, aktifTextTR, 16);
		memcpy(yavaslamaLimitText, yavaslamaLimitTextTR, 16);
		memcpy(altLimitText, altLimitTextTR, 16);
		memcpy(basincSalteriText, basincSalteriTextTR, 16);
		memcpy(kapiSecimleriText, kapiSecimleriTextTR, 16);
		memcpy(katKapisiAktifText, katKapisiAktifTextTR, 16);
		memcpy(tablaKapiAktifText, tablaKapiAktifTextTR, 16);
		memcpy(katArtiTablaAktifText, katArtiTablaAktifTextTR, 16);
		memcpy(kapiAcmaTipiText, kapiAcmaTipiTextTR, 16);
		memcpy(kapiButonuESPText, kapiButonuESPTextTR, 16);
		memcpy(katButonuEXTText, katButonuEXTTextTR, 16);
		memcpy(birKatKapiTipiText, birKatKapiTipiTextTR, 16);
		memcpy(butonKontrolluText, butonKontrolluTextTR, 16);
		memcpy(birinciKapiAcSuresiText, birinciKapiAcSuresiTextTR, 16);
		memcpy(kacSaniyeText, kacSaniyeTextTR, 16);
		memcpy(ikinciKatKapiTipiText, ikinciKatKapiTipiTextTR, 16);
		memcpy(ikinciKapiAcSuresiText, ikinciKapiAcSuresiTextTR, 16);
		memcpy(tablaKapiTipiText, tablaKapiTipiTextTR, 16);
		memcpy(tablaKapiAcKonumText, tablaKapiAcKonumTextTR, 16);
		memcpy(birinciKattaAcText, birinciKattaAcTextTR, 16);
		memcpy(ikinciKattaAcText, ikinciKattaAcTextTR, 16);
		memcpy(birVeIkinciKattaAcText, birVeIkinciKattaAcTextTR, 16);
		memcpy(tablaKapiAcSureText, tablaKapiAcSureTextTR, 16);
		memcpy(yukariYavaslamaLimitiText, yukariYavaslamaLimitiTextTR, 16);
		memcpy(devirmeYuruyusMenuText, devirmeYuruyusMenuTextTR, 16);
		memcpy(devirmeAktifText, devirmeAktifTextTR, 16);
		memcpy(yuruyusAktifText, yuruyusAktifTextTR, 16);
		memcpy(devirmeYukariText, devirmeYukariTextTR, 16);
		memcpy(yuruyusIleriText, yuruyusIleriTextTR, 16);
		memcpy(devirmeAsagiSivicText, devirmeAsagiSivicTextTR, 16);
		memcpy(yuruyusGeriSivicText, yuruyusGeriSivicTextTR, 16);
		memcpy(yuruyusSecildiText, yuruyusSecildiTextTR, 16);
		memcpy(devirmeSilindirTipiText, devirmeSilindirTipiTextTR, 16);
		memcpy(tekTesirText, tekTesirTextTR, 16);
		memcpy(ciftTesirText, ciftTesirTextTR, 16);
		memcpy(platformSilindirTipiText, platformSilindirTipiTextTR, 16);
		memcpy(yukariValfSureText, yukariValfSureTextTR, 16);
		memcpy(asagiValfSureText, asagiValfSureTextTR, 16);
		memcpy(devirmeYukariValfSureText, devirmeYukariValfSureTextTR, 16);
		memcpy(ileriValfSureText, ileriValfSureTextTR, 16);
		memcpy(devirmeAsagiValfSureText, devirmeAsagiValfSureTextTR, 16);
		memcpy(geriValfSureText, geriValfSureTextTR, 16);
		memcpy(calismaSuresiText, calismaSuresiTextTR, 16);
		memcpy(calismaSayisiText, calismaSayisiTextTR, 16);
		memcpy(enterlaSifirlaText, enterlaSifirlaTextTR, 16);
		memcpy(dilSecimText, dilSecimTextTR, 16);
		memcpy(secilenDilText, secilenDilTextTR, 16);
		memcpy(menudenCikisText, menudenCikisTextTR, 16);
		memcpy(enteraBasinizText, enteraBasinizTextTR, 16);
		memcpy(hataKoduText, hataKoduTextTR, 16);
		memcpy(dataSynchText, dataSynchTextTR, 16);
		memcpy(dataSynch2Text, dataSynch2TextTR, 16);
		memcpy(mustBeUniqueText, mustBeUniqueTextTR, 16);
		memcpy(mustBeUnique2Text, mustBeUnique2TextTR, 16);
		memcpy(mustBe12Text, mustBe12TextTR, 16);
		memcpy(mustBe122Text, mustBe122TextTR, 16);
		memcpy(ssidExceedErrorText, ssidExceedErrorTextTR, 16);
		memcpy(ssidExceedError2Text, ssidExceedError2TextTR, 16);
		memcpy(passExceedErrorText, passExceedErrorTextTR, 16);
		memcpy(passExceedError2Text, passExceedError2TextTR, 16);
	} else {
		memcpy(menuyeGirildiText, menuyeGirildiTextEN, 16); //destination, source, size
		memcpy(ayarlarText, ayarlarTextEN, 16);
		memcpy(hataKayitListText, hataKayitListTextEN, 16);
		memcpy(birHataKoduText, birHataKoduTextEN, 16);
		memcpy(ikiHataKoduText, ikiHataKoduTextEN, 16);
		memcpy(ucHataKoduText, ucHataKoduTextEN, 16);
		memcpy(dortHataKoduText, dortHataKoduTextEN, 16);
		memcpy(besHataKoduText, besHataKoduTextEN, 16);
		memcpy(altiHataKoduText, altiHataKoduTextEN, 16);
		memcpy(yediHataKoduText, yediHataKoduTextEN, 16);
		memcpy(sekizHataKoduText, sekizHataKoduTextEN, 16);
		memcpy(dokuzHataKoduText, dokuzHataKoduTextEN, 16);
		memcpy(onHataKoduText, onHataKoduTextEN, 16);
		memcpy(silmekIcinText, silmekIcinTextEN, 16);
		memcpy(calismaSekliText, calismaSekliTextEN, 16);
		memcpy(devirmeYuruyusText, devirmeYuruyusTextEN, 16);
		memcpy(bastikcaCalisanText, bastikcaCalisanTextEN, 16);
		memcpy(basGonderText, basGonderTextEN, 16);
		memcpy(emniyetCercevesiText, emniyetCercevesiTextEN, 16);
		memcpy(pasifText, pasifTextEN, 16);
		memcpy(aktifText, aktifTextEN, 16);
		memcpy(yavaslamaLimitText, yavaslamaLimitTextEN, 16);
		memcpy(altLimitText, altLimitTextEN, 16);
		memcpy(basincSalteriText, basincSalteriTextEN, 16);
		memcpy(kapiSecimleriText, kapiSecimleriTextEN, 16);
		memcpy(katKapisiAktifText, katKapisiAktifTextEN, 16);
		memcpy(tablaKapiAktifText, tablaKapiAktifTextEN, 16);
		memcpy(katArtiTablaAktifText, katArtiTablaAktifTextEN, 16);
		memcpy(kapiAcmaTipiText, kapiAcmaTipiTextEN, 16);
		memcpy(kapiButonuESPText, kapiButonuESPTextEN, 16);
		memcpy(katButonuEXTText, katButonuEXTTextEN, 16);
		memcpy(birKatKapiTipiText, birKatKapiTipiTextEN, 16);
		memcpy(butonKontrolluText, butonKontrolluTextEN, 16);
		memcpy(birinciKapiAcSuresiText, birinciKapiAcSuresiTextEN, 16);
		memcpy(kacSaniyeText, kacSaniyeTextEN, 16);
		memcpy(ikinciKatKapiTipiText, ikinciKatKapiTipiTextEN, 16);
		memcpy(ikinciKapiAcSuresiText, ikinciKapiAcSuresiTextEN, 16);
		memcpy(tablaKapiTipiText, tablaKapiTipiTextEN, 16);
		memcpy(tablaKapiAcKonumText, tablaKapiAcKonumTextEN, 16);
		memcpy(birinciKattaAcText, birinciKattaAcTextEN, 16);
		memcpy(ikinciKattaAcText, ikinciKattaAcTextEN, 16);
		memcpy(birVeIkinciKattaAcText, birVeIkinciKattaAcTextEN, 16);
		memcpy(tablaKapiAcSureText, tablaKapiAcSureTextEN, 16);
		memcpy(yukariYavaslamaLimitiText, yukariYavaslamaLimitiTextEN, 16);
		memcpy(devirmeYuruyusMenuText, devirmeYuruyusMenuTextEN, 16);
		memcpy(devirmeAktifText, devirmeAktifTextEN, 16);
		memcpy(yuruyusAktifText, yuruyusAktifTextEN, 16);
		memcpy(devirmeYukariText, devirmeYukariTextEN, 16);
		memcpy(yuruyusIleriText, yuruyusIleriTextEN, 16);
		memcpy(devirmeAsagiSivicText, devirmeAsagiSivicTextEN, 16);
		memcpy(yuruyusGeriSivicText, yuruyusGeriSivicTextEN, 16);
		memcpy(yuruyusSecildiText, yuruyusSecildiTextEN, 16);
		memcpy(devirmeSilindirTipiText, devirmeSilindirTipiTextEN, 16);
		memcpy(tekTesirText, tekTesirTextEN, 16);
		memcpy(ciftTesirText, ciftTesirTextEN, 16);
		memcpy(platformSilindirTipiText, platformSilindirTipiTextEN, 16);
		memcpy(yukariValfSureText, yukariValfSureTextEN, 16);
		memcpy(asagiValfSureText, asagiValfSureTextEN, 16);
		memcpy(devirmeYukariValfSureText, devirmeYukariValfSureTextEN, 16);
		memcpy(ileriValfSureText, ileriValfSureTextEN, 16);
		memcpy(devirmeAsagiValfSureText, devirmeAsagiValfSureTextEN, 16);
		memcpy(geriValfSureText, geriValfSureTextEN, 16);
		memcpy(calismaSuresiText, calismaSuresiTextEN, 16);
		memcpy(calismaSayisiText, calismaSayisiTextEN, 16);
		memcpy(enterlaSifirlaText, enterlaSifirlaTextEN, 16);
		memcpy(dilSecimText, dilSecimTextEN, 16);
		memcpy(secilenDilText, secilenDilTextEN, 16);
		memcpy(menudenCikisText, menudenCikisTextEN, 16);
		memcpy(enteraBasinizText, enteraBasinizTextEN, 16);
		memcpy(hataKoduText, hataKoduTextEN, 16);
		memcpy(dataSynchText, dataSynchTextEN, 16);
		memcpy(dataSynch2Text, dataSynch2TextEN, 16);
		memcpy(mustBeUniqueText, mustBeUniqueTextEN, 16);
		memcpy(mustBeUnique2Text, mustBeUnique2TextEN, 16);
		memcpy(mustBe12Text, mustBe12TextEN, 16);
		memcpy(mustBe122Text, mustBe122TextEN, 16);
		memcpy(ssidExceedErrorText, ssidExceedErrorTextEN, 16);
		memcpy(ssidExceedError2Text, ssidExceedError2TextEN, 16);
		memcpy(passExceedErrorText, passExceedErrorTextEN, 16);
		memcpy(passExceedError2Text, passExceedError2TextEN, 16);
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
}
