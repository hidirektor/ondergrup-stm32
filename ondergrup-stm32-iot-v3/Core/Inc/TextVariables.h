/*
 * TextVariables.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef INC_TEXTVARIABLES_H_
#define INC_TEXTVARIABLES_H_

#include <stdint.h>
#include <string>

class TextVariables {
public:
    static TextVariables& getInstance();
    void loadMenuTexts(uint8_t dilSecim);

    std::string menuyeGirildiText;
    std::string ayarlarText;
    std::string hataKayitListText;
    std::string birHataKoduText;
    std::string ikiHataKoduText;
    std::string ucHataKoduText;
    std::string dortHataKoduText;
    std::string besHataKoduText;
    std::string altiHataKoduText;
    std::string yediHataKoduText;
    std::string sekizHataKoduText;
    std::string dokuzHataKoduText;
    std::string onHataKoduText;
    std::string silmekIcinText;
    std::string calismaSekliText;
    std::string devirmeYuruyusText;
    std::string bastikcaCalisanText;
    std::string basGonderText;
    std::string emniyetCercevesiText;
    std::string pasifText;
    std::string aktifText;
    std::string yavaslamaLimitText;
    std::string altLimitText;
    std::string basincSalteriText;
    std::string kapiSecimleriText;
    std::string katKapisiAktifText;
    std::string tablaKapiAktifText;
    std::string katArtiTablaAktifText;
    std::string kapiAcmaTipiText;
    std::string kapiButonuESPText;
    std::string katButonuEXTText;
    std::string birKatKapiTipiText;
    std::string butonKontrolluText;
    std::string birinciKapiAcSuresiText;
    std::string kacSaniyeText;
    std::string ikinciKatKapiTipiText;
    std::string ikinciKapiAcSuresiText;
    std::string tablaKapiTipiText;
    std::string tablaKapiAcKonumText;
    std::string birinciKattaAcText;
    std::string ikinciKattaAcText;
    std::string birVeIkinciKattaAcText;
    std::string tablaKapiAcSureText;
    std::string yukariYavaslamaLimitiText;
    std::string devirmeYuruyusMenuText;
    std::string devirmeAktifText;
    std::string yuruyusAktifText;
    std::string devirmeYukariText;
    std::string yuruyusIleriText;
    std::string devirmeAsagiSivicText;
    std::string yuruyusGeriSivicText;
    std::string yuruyusSecildiText;
    std::string devirmeSilindirTipiText;
    std::string tekTesirText;
    std::string ciftTesirText;
    std::string platformSilindirTipiText;
    std::string yukariValfSureText;
    std::string asagiValfSureText;
    std::string devirmeYukariValfSureText;
    std::string ileriValfSureText;
    std::string devirmeAsagiValfSureText;
    std::string geriValfSureText;
    std::string calismaSuresiText;
    std::string calismaSayisiText;
    std::string enterlaSifirlaText;
    std::string dilSecimText;
    std::string secilenDilText;
    std::string menudenCikisText;
    std::string enteraBasinizText;
    std::string hataKoduText;

    // IoT Messages:
    std::string dataSynchText;
    std::string dataSynch2Text;
    std::string mustBeUniqueText;
    std::string mustBeUnique2Text;
    std::string mustBe12Text;
    std::string mustBe122Text;
    std::string ssidExceedErrorText;
    std::string ssidExceedError2Text;
    std::string passExceedErrorText;
    std::string passExceedError2Text;

    // EEPROM Messages:
    std::string dataYazildiText;
    std::string dataOkunuyorText;
    std::string dataOkunduText;
    std::string degerKaydedildiText;

    // Error Code Messages:
    std::string errorCodeText;

    // Hardware texts:
    std::string machineIDText;

    // Confirmation Texts:
    std::string idConfirmationText;
    std::string idConfirmationSubText;
    std::string wifiConfirmationText;

private:
    TextVariables() = default;
    void menuVariableFinisher();
};

#endif /* INC_TEXTVARIABLES_H_ */
