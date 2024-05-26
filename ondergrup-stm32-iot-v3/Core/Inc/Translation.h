/*
 * Translation.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef INC_TRANSLATION_H_
#define INC_TRANSLATION_H_

#include <string>

class Translation {
public:
    static Translation& getInstance();

    // Genel Metinler
    std::string splashTextGN;
    std::string splashText2GN;
    std::string mainTextGN;
    std::string mainText2GN;
    std::string ondSafetyTextGN;
    std::string prudhomeTextGN;
    std::string pizzattoTextGN;
    std::string buzzerTextGN;
    std::string demoModTextGN;
    std::string iotModTextGN;
    std::string cycleTextGN;
    std::string eepromTextGN;

    // Türkçe Metinler
    std::string menuyeGirildiTextTR;
    std::string ayarlarTextTR;
    std::string hataKayitListTextTR;
    std::string birHataKoduTextTR;
    std::string ikiHataKoduTextTR;
    std::string ucHataKoduTextTR;
    std::string dortHataKoduTextTR;
    std::string besHataKoduTextTR;
    std::string altiHataKoduTextTR;
    std::string yediHataKoduTextTR;
    std::string sekizHataKoduTextTR;
    std::string dokuzHataKoduTextTR;
    std::string onHataKoduTextTR;
    std::string silmekIcinTextTR;
    std::string calismaSekliTextTR;
    std::string devirmeYuruyusTextTR;
    std::string bastikcaCalisanTextTR;
    std::string basGonderTextTR;
    std::string emniyetCercevesiTextTR;
    std::string pasifTextTR;
    std::string aktifTextTR;
    std::string yavaslamaLimitTextTR;
    std::string altLimitTextTR;
    std::string basincSalteriTextTR;
    std::string kapiSecimleriTextTR;
    std::string katKapisiAktifTextTR;
    std::string tablaKapiAktifTextTR;
    std::string katArtiTablaAktifTextTR;
    std::string kapiAcmaTipiTextTR;
    std::string kapiButonuESPTextTR;
    std::string katButonuEXTTextTR;
    std::string birKatKapiTipiTextTR;
    std::string butonKontrolluTextTR;
    std::string birinciKapiAcSuresiTextTR;
    std::string kacSaniyeTextTR;
    std::string ikinciKatKapiTipiTextTR;
    std::string ikinciKapiAcSuresiTextTR;
    std::string tablaKapiTipiTextTR;
    std::string tablaKapiAcKonumTextTR;
    std::string birinciKattaAcTextTR;
    std::string ikinciKattaAcTextTR;
    std::string birVeIkinciKattaAcTextTR;
    std::string tablaKapiAcSureTextTR;
    std::string yukariYavaslamaLimitiTextTR;
    std::string devirmeYuruyusMenuTextTR;
    std::string devirmeAktifTextTR;
    std::string yuruyusAktifTextTR;
    std::string devirmeYukariTextTR;
    std::string yuruyusIleriTextTR;
    std::string devirmeAsagiSivicTextTR;
    std::string yuruyusGeriSivicTextTR;
    std::string yuruyusSecildiTextTR;
    std::string devirmeSilindirTipiTextTR;
    std::string tekTesirTextTR;
    std::string ciftTesirTextTR;
    std::string platformSilindirTipiTextTR;
    std::string yukariValfSureTextTR;
    std::string asagiValfSureTextTR;
    std::string devirmeYukariValfSureTextTR;
    std::string ileriValfSureTextTR;
    std::string devirmeAsagiValfSureTextTR;
    std::string geriValfSureTextTR;
    std::string calismaSuresiTextTR;
    std::string calismaSayisiTextTR;
    std::string enterlaSifirlaTextTR;
    std::string dilSecimTextTR;
    std::string secilenDilTextTR;
    std::string menudenCikisTextTR;
    std::string enteraBasinizTextTR;
    std::string hataKoduTextTR;

    // İngilizce Metinler
    std::string menuyeGirildiTextEN;
    std::string ayarlarTextEN;
    std::string hataKayitListTextEN;
    std::string birHataKoduTextEN;
    std::string ikiHataKoduTextEN;
    std::string ucHataKoduTextEN;
    std::string dortHataKoduTextEN;
    std::string besHataKoduTextEN;
    std::string altiHataKoduTextEN;
    std::string yediHataKoduTextEN;
    std::string sekizHataKoduTextEN;
    std::string dokuzHataKoduTextEN;
    std::string onHataKoduTextEN;
    std::string silmekIcinTextEN;
    std::string calismaSekliTextEN;
    std::string devirmeYuruyusTextEN;
    std::string bastikcaCalisanTextEN;
    std::string basGonderTextEN;
    std::string emniyetCercevesiTextEN;
    std::string pasifTextEN;
    std::string aktifTextEN;
    std::string yavaslamaLimitTextEN;
    std::string altLimitTextEN;
    std::string basincSalteriTextEN;
    std::string kapiSecimleriTextEN;
    std::string katKapisiAktifTextEN;
    std::string tablaKapiAktifTextEN;
    std::string katArtiTablaAktifTextEN;
    std::string kapiAcmaTipiTextEN;
    std::string kapiButonuESPTextEN;
    std::string katButonuEXTTextEN;
    std::string birKatKapiTipiTextEN;
    std::string butonKontrolluTextEN;
    std::string birinciKapiAcSuresiTextEN;
    std::string kacSaniyeTextEN;
    std::string ikinciKatKapiTipiTextEN;
    std::string ikinciKapiAcSuresiTextEN;
    std::string tablaKapiTipiTextEN;
    std::string tablaKapiAcKonumTextEN;
    std::string birinciKattaAcTextEN;
    std::string ikinciKattaAcTextEN;
    std::string birVeIkinciKattaAcTextEN;
    std::string tablaKapiAcSureTextEN;
    std::string yukariYavaslamaLimitiTextEN;
    std::string devirmeYuruyusMenuTextEN;
    std::string devirmeAktifTextEN;
    std::string yuruyusAktifTextEN;
    std::string devirmeYukariTextEN;
    std::string yuruyusIleriTextEN;
    std::string devirmeAsagiSivicTextEN;
    std::string yuruyusGeriSivicTextEN;
    std::string yuruyusSecildiTextEN;
    std::string devirmeSilindirTipiTextEN;
    std::string tekTesirTextEN;
    std::string ciftTesirTextEN;
    std::string platformSilindirTipiTextEN;
    std::string yukariValfSureTextEN;
    std::string asagiValfSureTextEN;
    std::string devirmeYukariValfSureTextEN;
    std::string ileriValfSureTextEN;
    std::string devirmeAsagiValfSureTextEN;
    std::string geriValfSureTextEN;
    std::string calismaSuresiTextEN;
    std::string calismaSayisiTextEN;
    std::string enterlaSifirlaTextEN;
    std::string dilSecimTextEN;
    std::string secilenDilTextEN;
    std::string menudenCikisTextEN;
    std::string enteraBasinizTextEN;
    std::string hataKoduTextEN;

    // IoT Messages
    std::string dataSynchTextTR;
    std::string dataSynch2TextTR;
    std::string mustBeUniqueTextTR;
    std::string mustBeUnique2TextTR;
    std::string mustBe12TextTR;
    std::string mustBe122TextTR;
    std::string ssidExceedErrorTextTR;
    std::string ssidExceedError2TextTR;
    std::string passExceedErrorTextTR;
    std::string passExceedError2TextTR;

    std::string dataSynchTextEN;
    std::string dataSynch2TextEN;
    std::string mustBeUniqueTextEN;
    std::string mustBeUnique2TextEN;
    std::string mustBe12TextEN;
    std::string mustBe122TextEN;
    std::string ssidExceedErrorTextEN;
    std::string ssidExceedError2TextEN;
    std::string passExceedErrorTextEN;
    std::string passExceedError2TextEN;

    // EEPROM Messages
    std::string dataYazildiTextTR;
    std::string dataYazildiTextEN;
    std::string dataOkunuyorTextTR;
    std::string dataOkunuyorTextEN;
    std::string dataOkunduTextTR;
    std::string dataOkunduTextEN;
    std::string degerKaydedildiTextTR;
    std::string degerKaydedildiTextEN;

    // ErrorCode Messages
    std::string errorCodeTextTR;
    std::string errorCodeTextEN;

    // Hardware texts
    std::string machineIDTextTR;
    std::string machineIDTextEN;

    // Confirmation Texts
    std::string idConfirmationTextTR;
    std::string idConfirmationTextEN;
    std::string idConfirmationSubTextTR;
    std::string idConfirmationSubTextEN;
    std::string wifiConfirmationTextTR;
    std::string wifiConfirmationTextEN;

private:
    Translation();
    void initializeTexts();
};

#endif /* INC_TRANSLATION_H_ */

