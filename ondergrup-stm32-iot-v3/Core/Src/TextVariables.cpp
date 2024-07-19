/*
 * TextVariables.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


#include "TextVariables.h"

#include "Instance.h"
#include "main.h"

#include <cstring>

TextVariables& TextVariables::getInstance() {
    static TextVariables instance;
    return instance;
}

void TextVariables::loadMenuTexts(uint8_t dilSecim) {
    if (dilSecim == 0) {
        textVars.menuyeGirildiText = translation.menuyeGirildiTextTR;
        textVars.ayarlarText = translation.ayarlarTextTR;
        textVars.hataKayitListText = translation.hataKayitListTextTR;
        textVars.birHataKoduText = translation.birHataKoduTextTR;
        textVars.ikiHataKoduText = translation.ikiHataKoduTextTR;
        textVars.ucHataKoduText = translation.ucHataKoduTextTR;
        textVars.dortHataKoduText = translation.dortHataKoduTextTR;
        textVars.besHataKoduText = translation.besHataKoduTextTR;
        textVars.altiHataKoduText = translation.altiHataKoduTextTR;
        textVars.yediHataKoduText = translation.yediHataKoduTextTR;
        textVars.sekizHataKoduText = translation.sekizHataKoduTextTR;
        textVars.dokuzHataKoduText = translation.dokuzHataKoduTextTR;
        textVars.onHataKoduText = translation.onHataKoduTextTR;
        textVars.silmekIcinText = translation.silmekIcinTextTR;
        textVars.calismaSekliText = translation.calismaSekliTextTR;
        textVars.devirmeYuruyusText = translation.devirmeYuruyusTextTR;
        textVars.bastikcaCalisanText = translation.bastikcaCalisanTextTR;
        textVars.basGonderText = translation.basGonderTextTR;
        textVars.emniyetCercevesiText = translation.emniyetCercevesiTextTR;
        textVars.pasifText = translation.pasifTextTR;
        textVars.aktifText = translation.aktifTextTR;
        textVars.yavaslamaLimitText = translation.yavaslamaLimitTextTR;
        textVars.altLimitText = translation.altLimitTextTR;
        textVars.basincSalteriText = translation.basincSalteriTextTR;
        textVars.kapiSecimleriText = translation.kapiSecimleriTextTR;
        textVars.katKapisiAktifText = translation.katKapisiAktifTextTR;
        textVars.tablaKapiAktifText = translation.tablaKapiAktifTextTR;
        textVars.katArtiTablaAktifText = translation.katArtiTablaAktifTextTR;
        textVars.kapiAcmaTipiText = translation.kapiAcmaTipiTextTR;
        textVars.kapiButonuESPText = translation.kapiButonuESPTextTR;
        textVars.katButonuEXTText = translation.katButonuEXTTextTR;
        textVars.birKatKapiTipiText = translation.birKatKapiTipiTextTR;
        textVars.butonKontrolluText = translation.butonKontrolluTextTR;
        textVars.birinciKapiAcSuresiText = translation.birinciKapiAcSuresiTextTR;
        textVars.kacSaniyeText = translation.kacSaniyeTextTR;
        textVars.ikinciKatKapiTipiText = translation.ikinciKatKapiTipiTextTR;
        textVars.ikinciKapiAcSuresiText = translation.ikinciKapiAcSuresiTextTR;
        textVars.tablaKapiTipiText = translation.tablaKapiTipiTextTR;
        textVars.tablaKapiAcKonumText = translation.tablaKapiAcKonumTextTR;
        textVars.birinciKattaAcText = translation.birinciKattaAcTextTR;
        textVars.ikinciKattaAcText = translation.ikinciKattaAcTextTR;
        textVars.birVeIkinciKattaAcText = translation.birVeIkinciKattaAcTextTR;
        textVars.tablaKapiAcSureText = translation.tablaKapiAcSureTextTR;
        textVars.yukariYavaslamaLimitiText = translation.yukariYavaslamaLimitiTextTR;
        textVars.devirmeYuruyusMenuText = translation.devirmeYuruyusMenuTextTR;
        textVars.devirmeAktifText = translation.devirmeAktifTextTR;
        textVars.yuruyusAktifText = translation.yuruyusAktifTextTR;
        textVars.devirmeYukariText = translation.devirmeYukariTextTR;
        textVars.yuruyusIleriText = translation.yuruyusIleriTextTR;
        textVars.devirmeAsagiSivicText = translation.devirmeAsagiSivicTextTR;
        textVars.yuruyusGeriSivicText = translation.yuruyusGeriSivicTextTR;
        textVars.yuruyusSecildiText = translation.yuruyusSecildiTextTR;
        textVars.devirmeSilindirTipiText = translation.devirmeSilindirTipiTextTR;
        textVars.tekTesirText = translation.tekTesirTextTR;
        textVars.ciftTesirText = translation.ciftTesirTextTR;
        textVars.platformSilindirTipiText = translation.platformSilindirTipiTextTR;
        textVars.yukariValfSureText = translation.yukariValfSureTextTR;
        textVars.asagiValfSureText = translation.asagiValfSureTextTR;
        textVars.devirmeYukariValfSureText = translation.devirmeYukariValfSureTextTR;
        textVars.ileriValfSureText = translation.ileriValfSureTextTR;
        textVars.devirmeAsagiValfSureText = translation.devirmeAsagiValfSureTextTR;
        textVars.geriValfSureText = translation.geriValfSureTextTR;
        textVars.calismaSuresiText = translation.calismaSuresiTextTR;
        textVars.calismaSayisiText = translation.calismaSayisiTextTR;
        textVars.enterlaSifirlaText = translation.enterlaSifirlaTextTR;
        textVars.dilSecimText = translation.dilSecimTextTR;
        textVars.secilenDilText = translation.secilenDilTextTR;
        textVars.menudenCikisText = translation.menudenCikisTextTR;
        textVars.enteraBasinizText = translation.enteraBasinizTextTR;
        textVars.hataKoduText = translation.hataKoduTextTR;
        textVars.dataSynchText = translation.dataSynchTextTR;
        textVars.dataSynch2Text = translation.dataSynch2TextTR;
        textVars.mustBeUniqueText = translation.mustBeUniqueTextTR;
        textVars.mustBeUnique2Text = translation.mustBeUnique2TextTR;
        textVars.mustBe12Text = translation.mustBe12TextTR;
        textVars.mustBe122Text = translation.mustBe122TextTR;
        textVars.ssidExceedErrorText = translation.ssidExceedErrorTextTR;
        textVars.ssidExceedError2Text = translation.ssidExceedError2TextTR;
        textVars.passExceedErrorText = translation.passExceedErrorTextTR;
        textVars.passExceedError2Text = translation.passExceedError2TextTR;
        textVars.dataYazildiText = translation.dataYazildiTextTR;
        textVars.dataOkunuyorText = translation.dataOkunuyorTextTR;
        textVars.dataOkunduText = translation.dataOkunduTextTR;
        textVars.degerKaydedildiText = translation.degerKaydedildiTextTR;
        textVars.errorCodeText = translation.errorCodeTextTR;
        textVars.machineIDText = translation.machineIDTextTR;
        textVars.idConfirmationText = translation.idConfirmationTextTR;
        textVars.idConfirmationSubText = translation.idConfirmationSubTextTR;
        textVars.wifiConfirmationText = translation.wifiConfirmationTextTR;
    } else {
        textVars.menuyeGirildiText = translation.menuyeGirildiTextEN;
        textVars.ayarlarText = translation.ayarlarTextEN;
        textVars.hataKayitListText = translation.hataKayitListTextEN;
        textVars.birHataKoduText = translation.birHataKoduTextEN;
        textVars.ikiHataKoduText = translation.ikiHataKoduTextEN;
        textVars.ucHataKoduText = translation.ucHataKoduTextEN;
        textVars.dortHataKoduText = translation.dortHataKoduTextEN;
        textVars.besHataKoduText = translation.besHataKoduTextEN;
        textVars.altiHataKoduText = translation.altiHataKoduTextEN;
        textVars.yediHataKoduText = translation.yediHataKoduTextEN;
        textVars.sekizHataKoduText = translation.sekizHataKoduTextEN;
        textVars.dokuzHataKoduText = translation.dokuzHataKoduTextEN;
        textVars.onHataKoduText = translation.onHataKoduTextEN;
        textVars.silmekIcinText = translation.silmekIcinTextEN;
        textVars.calismaSekliText = translation.calismaSekliTextEN;
        textVars.devirmeYuruyusText = translation.devirmeYuruyusTextEN;
        textVars.bastikcaCalisanText = translation.bastikcaCalisanTextEN;
        textVars.basGonderText = translation.basGonderTextEN;
        textVars.emniyetCercevesiText = translation.emniyetCercevesiTextEN;
        textVars.pasifText = translation.pasifTextEN;
        textVars.aktifText = translation.aktifTextEN;
        textVars.yavaslamaLimitText = translation.yavaslamaLimitTextEN;
        textVars.altLimitText = translation.altLimitTextEN;
        textVars.basincSalteriText = translation.basincSalteriTextEN;
        textVars.kapiSecimleriText = translation.kapiSecimleriTextEN;
        textVars.katKapisiAktifText = translation.katKapisiAktifTextEN;
        textVars.tablaKapiAktifText = translation.tablaKapiAktifTextEN;
        textVars.katArtiTablaAktifText = translation.katArtiTablaAktifTextEN;
        textVars.kapiAcmaTipiText = translation.kapiAcmaTipiTextEN;
        textVars.kapiButonuESPText = translation.kapiButonuESPTextEN;
        textVars.katButonuEXTText = translation.katButonuEXTTextEN;
        textVars.birKatKapiTipiText = translation.birKatKapiTipiTextEN;
        textVars.butonKontrolluText = translation.butonKontrolluTextEN;
        textVars.birinciKapiAcSuresiText = translation.birinciKapiAcSuresiTextEN;
        textVars.kacSaniyeText = translation.kacSaniyeTextEN;
        textVars.ikinciKatKapiTipiText = translation.ikinciKatKapiTipiTextEN;
        textVars.ikinciKapiAcSuresiText = translation.ikinciKapiAcSuresiTextEN;
        textVars.tablaKapiTipiText = translation.tablaKapiTipiTextEN;
        textVars.tablaKapiAcKonumText = translation.tablaKapiAcKonumTextEN;
        textVars.birinciKattaAcText = translation.birinciKattaAcTextEN;
        textVars.ikinciKattaAcText = translation.ikinciKattaAcTextEN;
        textVars.birVeIkinciKattaAcText = translation.birVeIkinciKattaAcTextEN;
        textVars.tablaKapiAcSureText = translation.tablaKapiAcSureTextEN;
        textVars.yukariYavaslamaLimitiText = translation.yukariYavaslamaLimitiTextEN;
        textVars.devirmeYuruyusMenuText = translation.devirmeYuruyusMenuTextEN;
        textVars.devirmeAktifText = translation.devirmeAktifTextEN;
        textVars.yuruyusAktifText = translation.yuruyusAktifTextEN;
        textVars.devirmeYukariText = translation.devirmeYukariTextEN;
        textVars.yuruyusIleriText = translation.yuruyusIleriTextEN;
        textVars.devirmeAsagiSivicText = translation.devirmeAsagiSivicTextEN;
        textVars.yuruyusGeriSivicText = translation.yuruyusGeriSivicTextEN;
        textVars.yuruyusSecildiText = translation.yuruyusSecildiTextEN;
        textVars.devirmeSilindirTipiText = translation.devirmeSilindirTipiTextEN;
        textVars.tekTesirText = translation.tekTesirTextEN;
        textVars.ciftTesirText = translation.ciftTesirTextEN;
        textVars.platformSilindirTipiText = translation.platformSilindirTipiTextEN;
        textVars.yukariValfSureText = translation.yukariValfSureTextEN;
        textVars.asagiValfSureText = translation.asagiValfSureTextEN;
        textVars.devirmeYukariValfSureText = translation.devirmeYukariValfSureTextEN;
        textVars.ileriValfSureText = translation.ileriValfSureTextEN;
        textVars.devirmeAsagiValfSureText = translation.devirmeAsagiValfSureTextEN;
        textVars.geriValfSureText = translation.geriValfSureTextEN;
        textVars.calismaSuresiText = translation.calismaSuresiTextEN;
        textVars.calismaSayisiText = translation.calismaSayisiTextEN;
        textVars.enterlaSifirlaText = translation.enterlaSifirlaTextEN;
        textVars.dilSecimText = translation.dilSecimTextEN;
        textVars.secilenDilText = translation.secilenDilTextEN;
        textVars.menudenCikisText = translation.menudenCikisTextEN;
        textVars.enteraBasinizText = translation.enteraBasinizTextEN;
        textVars.hataKoduText = translation.hataKoduTextEN;
        textVars.dataSynchText = translation.dataSynchTextEN;
        textVars.dataSynch2Text = translation.dataSynch2TextEN;
        textVars.mustBeUniqueText = translation.mustBeUniqueTextEN;
        textVars.mustBeUnique2Text = translation.mustBeUnique2TextEN;
        textVars.mustBe12Text = translation.mustBe12TextEN;
        textVars.mustBe122Text = translation.mustBe122TextEN;
        textVars.ssidExceedErrorText = translation.ssidExceedErrorTextEN;
        textVars.ssidExceedError2Text = translation.ssidExceedError2TextEN;
        textVars.passExceedErrorText = translation.passExceedErrorTextEN;
        textVars.passExceedError2Text = translation.passExceedError2TextEN;
        textVars.dataYazildiText = translation.dataYazildiTextEN;
        textVars.dataOkunuyorText = translation.dataOkunuyorTextEN;
        textVars.dataOkunduText = translation.dataOkunduTextEN;
        textVars.degerKaydedildiText = translation.degerKaydedildiTextEN;
        textVars.errorCodeText = translation.errorCodeTextEN;
        textVars.machineIDText = translation.machineIDTextEN;
        textVars.idConfirmationText = translation.idConfirmationTextEN;
        textVars.idConfirmationSubText = translation.idConfirmationSubTextEN;
        textVars.wifiConfirmationText = translation.wifiConfirmationTextEN;
    }
    menuVariableFinisher();
}

void TextVariables::menuVariableFinisher() {
	textVars.menuyeGirildiText.resize(16, '\0');
	textVars.ayarlarText.resize(16, '\0');
	textVars.hataKayitListText.resize(16, '\0');
	textVars.birHataKoduText.resize(16, '\0');
	textVars.ikiHataKoduText.resize(16, '\0');
	textVars.ucHataKoduText.resize(16, '\0');
	textVars.dortHataKoduText.resize(16, '\0');
	textVars.besHataKoduText.resize(16, '\0');
	textVars.altiHataKoduText.resize(16, '\0');
	textVars.yediHataKoduText.resize(16, '\0');
	textVars.sekizHataKoduText.resize(16, '\0');
	textVars.dokuzHataKoduText.resize(16, '\0');
	textVars.onHataKoduText.resize(16, '\0');
	textVars.silmekIcinText.resize(16, '\0');
	textVars.calismaSekliText.resize(16, '\0');
	textVars.devirmeYuruyusText.resize(16, '\0');
	textVars.bastikcaCalisanText.resize(16, '\0');
	textVars.basGonderText.resize(16, '\0');
	textVars.emniyetCercevesiText.resize(16, '\0');
	textVars.pasifText.resize(16, '\0');
	textVars.aktifText.resize(16, '\0');
	textVars.yavaslamaLimitText.resize(16, '\0');
	textVars.altLimitText.resize(16, '\0');
	textVars.basincSalteriText.resize(16, '\0');
	textVars.kapiSecimleriText.resize(16, '\0');
	textVars.katKapisiAktifText.resize(16, '\0');
	textVars.tablaKapiAktifText.resize(16, '\0');
	textVars.katArtiTablaAktifText.resize(16, '\0');
	textVars.kapiAcmaTipiText.resize(16, '\0');
	textVars.kapiButonuESPText.resize(16, '\0');
	textVars.katButonuEXTText.resize(16, '\0');
	textVars.birKatKapiTipiText.resize(16, '\0');
	textVars.butonKontrolluText.resize(16, '\0');
	textVars.birinciKapiAcSuresiText.resize(16, '\0');
	textVars.kacSaniyeText.resize(16, '\0');
	textVars.ikinciKatKapiTipiText.resize(16, '\0');
	textVars.ikinciKapiAcSuresiText.resize(16, '\0');
	textVars.tablaKapiTipiText.resize(16, '\0');
	textVars.tablaKapiAcKonumText.resize(16, '\0');
	textVars.birinciKattaAcText.resize(16, '\0');
    textVars.ikinciKattaAcText.resize(16, '\0');
    textVars.birVeIkinciKattaAcText.resize(16, '\0');
    textVars.tablaKapiAcSureText.resize(16, '\0');
    textVars.yukariYavaslamaLimitiText.resize(16, '\0');
    textVars.devirmeYuruyusMenuText.resize(16, '\0');
    textVars.devirmeAktifText.resize(16, '\0');
    textVars.yuruyusAktifText.resize(16, '\0');
    textVars.devirmeYukariText.resize(16, '\0');
    textVars.yuruyusIleriText.resize(16, '\0');
    textVars.devirmeAsagiSivicText.resize(16, '\0');
    textVars.yuruyusGeriSivicText.resize(16, '\0');
    textVars.yuruyusSecildiText.resize(16, '\0');
    textVars.devirmeSilindirTipiText.resize(16, '\0');
    textVars.tekTesirText.resize(16, '\0');
    textVars.ciftTesirText.resize(16, '\0');
    textVars.platformSilindirTipiText.resize(16, '\0');
    textVars.yukariValfSureText.resize(16, '\0');
    textVars.asagiValfSureText.resize(16, '\0');
    textVars.devirmeYukariValfSureText.resize(16, '\0');
    textVars.ileriValfSureText.resize(16, '\0');
    textVars.devirmeAsagiValfSureText.resize(16, '\0');
    textVars.geriValfSureText.resize(16, '\0');
    textVars.calismaSuresiText.resize(16, '\0');
    textVars.calismaSayisiText.resize(16, '\0');
    textVars.enterlaSifirlaText.resize(16, '\0');
    textVars.dilSecimText.resize(16, '\0');
    textVars.secilenDilText.resize(16, '\0');
    textVars.menudenCikisText.resize(16, '\0');
    textVars.enteraBasinizText.resize(16, '\0');
    textVars.hataKoduText.resize(16, '\0');

    // IoT Messages:
    textVars.dataSynchText.resize(16, '\0');
    textVars.dataSynch2Text.resize(16, '\0');
    textVars.mustBeUniqueText.resize(16, '\0');
    textVars.mustBeUnique2Text.resize(16, '\0');
    textVars.mustBe12Text.resize(16, '\0');
    textVars.mustBe122Text.resize(16, '\0');
    textVars.ssidExceedErrorText.resize(16, '\0');
    textVars.ssidExceedError2Text.resize(16, '\0');
    textVars.passExceedErrorText.resize(16, '\0');
    textVars.passExceedError2Text.resize(16, '\0');

    // EEPROM Messages:
    textVars.dataYazildiText.resize(16, '\0');
    textVars.dataOkunuyorText.resize(16, '\0');
    textVars.dataOkunduText.resize(16, '\0');
    textVars.degerKaydedildiText.resize(16, '\0');

    // Error Code Messages:
    textVars.errorCodeText.resize(16, '\0');

    // Hardware texts:
    textVars.machineIDText.resize(16, '\0');

    // Confirmation Texts:
    textVars.idConfirmationText.resize(16, '\0');
    textVars.idConfirmationSubText.resize(16, '\0');
    textVars.wifiConfirmationText.resize(16, '\0');
}
