/*
 * Translation.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


#include "Translation.h"

Translation& Translation::getInstance() {
    static Translation instance;
    return instance;
}

Translation::Translation() {
    initializeTexts();
}

void Translation::initializeTexts() {
    // Genel Metinler
    splashTextGN = "     RMK-V1     ";
    splashText2GN = "ONDTECH ESP CONT";
    mainTextGN = "    ESP-RMK     ";
    mainText2GN = "      RUN       ";
    ondSafetyTextGN = "OND Safety      ";
    prudhomeTextGN = "Prudhome        ";
    pizzattoTextGN = "Pizzato         ";
    buzzerTextGN = "BUZZER          ";
    demoModTextGN = "DEMO MODE       ";
    iotModTextGN = "IoT MODE        ";
    cycleTextGN = "Cycle           ";
    eepromTextGN = "   **EEPROM**   ";

    // Türkçe Metinler
    menuyeGirildiTextTR = "MENUYE  GiRDiNiZ";
    ayarlarTextTR = "    AYARLAR     ";
    hataKayitListTextTR = "HATA KAYIT LiST.";
    birHataKoduTextTR = "1.Hata Kodu:    ";
    ikiHataKoduTextTR = "2.Hata Kodu:    ";
    ucHataKoduTextTR = "3.Hata Kodu:    ";
    dortHataKoduTextTR = "4.Hata Kodu:    ";
    besHataKoduTextTR = "5.Hata Kodu:    ";
    altiHataKoduTextTR = "6.Hata Kodu:    ";
    yediHataKoduTextTR = "7.Hata Kodu:    ";
    sekizHataKoduTextTR = "8.Hata Kodu:    ";
    dokuzHataKoduTextTR = "9.Hata Kodu:    ";
    onHataKoduTextTR = "10.Hata Kodu:   ";
    silmekIcinTextTR = "Silmek icin ent.";
    calismaSekliTextTR = "CALISMA SEKLi   ";
    devirmeYuruyusTextTR = "Dvr Yrys secildi";
    bastikcaCalisanTextTR = "Bastikca cal.   ";
    basGonderTextTR = "Bas gonder      ";
    emniyetCercevesiTextTR = "EMNIYET CER.    ";
    pasifTextTR = "Pasif           ";
    aktifTextTR = "Aktif           ";
    yavaslamaLimitTextTR = "YAVASLAMA LIMIT ";
    altLimitTextTR = "ALT LIMIT       ";
    basincSalteriTextTR = "BASINC SALTERI  ";
    kapiSecimleriTextTR = "KAPI SECIMLERI  ";
    katKapisiAktifTextTR = "Kat kapisi aktif";
    tablaKapiAktifTextTR = "Tabla kapi aktif";
    katArtiTablaAktifTextTR = "Kat + Tabl aktif";
    kapiAcmaTipiTextTR = "KAPI ACMA TIPI  ";
    kapiButonuESPTextTR = "Kapi butonu ESP ";
    katButonuEXTTextTR = "Kat butonu EXT  ";
    birKatKapiTipiTextTR = "1.KAT KAPI TiPi ";
    butonKontrolluTextTR = "Buton kontrollu ";
    birinciKapiAcSuresiTextTR = "1.KAPI AC SURESi";
    kacSaniyeTextTR = "Kac Saniye      ";
    ikinciKatKapiTipiTextTR = "2.KAT KAPI TiPi ";
    ikinciKapiAcSuresiTextTR = "2.KAPI AC SURESi";
    tablaKapiTipiTextTR = "TABLA KAPI TiPi ";
    tablaKapiAcKonumTextTR = "TBL KPI AC KONUM";
    birinciKattaAcTextTR = "1. Katta ac     ";
    ikinciKattaAcTextTR = "2. Katta ac     ";
    birVeIkinciKattaAcTextTR = "1.+2. Katta ac  ";
    tablaKapiAcSureTextTR = "TABLA KP AC SURE";
    yukariYavaslamaLimitiTextTR = "YUKARI YAVAS LMT";
    devirmeYuruyusMenuTextTR = "DEVIRME-YURUYUS ";
    devirmeAktifTextTR = "Devirme aktif   ";
    yuruyusAktifTextTR = "Yuruyus aktif   ";
    devirmeYukariTextTR = "DEVRM YUKARI SVC";
    yuruyusIleriTextTR = "YURUYUS ILER SVC";
    devirmeAsagiSivicTextTR = "DEVIRM ASAGI SVC";
    yuruyusGeriSivicTextTR = "YURUYUS GERI SVC";
    yuruyusSecildiTextTR = "YURUYUS SECiLDi ";
    devirmeSilindirTipiTextTR = "DEVIRME SLN TIPI";
    tekTesirTextTR = "Tek tesir       ";
    ciftTesirTextTR = "Cift tesir      ";
    platformSilindirTipiTextTR = "PLATFRM SLN TIPI";
    yukariValfSureTextTR = "YUKARI VALF SURE";
    asagiValfSureTextTR = "ASAGI VALF SURE ";
    devirmeYukariValfSureTextTR = "DVRM YKR VLF SURE";
    ileriValfSureTextTR = "iLERi VALF SURE ";
    devirmeAsagiValfSureTextTR = "DVRM ASG VLF SURE";
    geriValfSureTextTR = "GERi VALF SURE  ";
    calismaSuresiTextTR = "CALiSMA SURESi  ";
    calismaSayisiTextTR = "Calisma Sayisi  ";
    enterlaSifirlaTextTR = "Enter'la Sifirla";
    dilSecimTextTR = "DIL SECIMI      ";
    secilenDilTextTR = "TURKCE          ";
    menudenCikisTextTR = " MENUDEN CIKIS  ";
    enteraBasinizTextTR = "ENTER'A BASINIZ ";
    hataKoduTextTR = "   HATA KODU    ";

    // İngilizce Metinler
    menuyeGirildiTextEN = "ENTERED THE MENU";
    ayarlarTextEN = "    SETTINGS    ";
    hataKayitListTextEN = "ERROR SAVE LiST.";
    birHataKoduTextEN = "1.Error Code:   ";
    ikiHataKoduTextEN = "2.Error Code:   ";
    ucHataKoduTextEN = "3.Error Code:   ";
    dortHataKoduTextEN = "4.Error Code:   ";
    besHataKoduTextEN = "5.Error Code:   ";
    altiHataKoduTextEN = "6.Error Code:   ";
    yediHataKoduTextEN = "7.Error Code:   ";
    sekizHataKoduTextEN = "8.Error Code:   ";
    dokuzHataKoduTextEN = "9.Error Code:   ";
    onHataKoduTextEN = "10.Error Code:  ";
    silmekIcinTextEN = "Del. press enter";
    calismaSekliTextEN = "WORKNG PRINCIPLE";
    devirmeYuruyusTextEN = "Tppng Mobil slct";
    bastikcaCalisanTextEN = "Deadman Control ";
    basGonderTextEN = "Call & Send     ";
    emniyetCercevesiTextEN = "SAFETY FRAME    ";
    pasifTextEN = "Passive         ";
    aktifTextEN = "Active          ";
    yavaslamaLimitTextEN = "SLOW DOWN LIMIT ";
    altLimitTextEN = "DOWN LIMIT      ";
    basincSalteriTextEN = "PRESSURE SWITCH ";
    kapiSecimleriTextEN = "DOOR SELECTION  ";
    katKapisiAktifTextEN = "Floor door act  ";
    tablaKapiAktifTextEN = "Pltfrm door act ";
    katArtiTablaAktifTextEN = "Flr + Plrfrm act";
    kapiAcmaTipiTextEN = "OPEN DOOR TYPE  ";
    kapiButonuESPTextEN = "Door Button ESP ";
    katButonuEXTTextEN = "Floor button EXT";
    birKatKapiTipiTextEN = "1.FLOOR DOOR TYP";
    butonKontrolluTextEN = "Button cntrolled";
    birinciKapiAcSuresiTextEN = "1.FLR DR OPN TMR";
    kacSaniyeTextEN = "Seconds         ";
    ikinciKatKapiTipiTextEN = "2.FLOOR DOOR TYP";
    ikinciKapiAcSuresiTextEN = "2.FLR DR OPN TMR";
    tablaKapiTipiTextEN = "PLTFRM DOOR TYPE";
    tablaKapiAcKonumTextEN = "PLTFRM DR OP LOC";
    birinciKattaAcTextEN = "1. Floor open   ";
    ikinciKattaAcTextEN = "2. Floor open   ";
    birVeIkinciKattaAcTextEN = "1.+2. Floor open";
    tablaKapiAcSureTextEN = "PLTFM DR OPN TMR";
    yukariYavaslamaLimitiTextEN = "UPPR SLW DWN LMT";
    devirmeYuruyusMenuTextEN = "TPPNG-MOBIL PLT ";
    devirmeAktifTextEN = "Tipping active  ";
    yuruyusAktifTextEN = "Drive active    ";
    devirmeYukariTextEN = "TPPNG SWTCH/OPEN";
    yuruyusIleriTextEN = "DRVE FRWRD SWTCH";
    devirmeAsagiSivicTextEN = "TPPNG SWTCH/CLSD";
    yuruyusGeriSivicTextEN = "DRIVE BACK SWTCH";
    yuruyusSecildiTextEN = "DRIVE SELECTED  ";
    devirmeSilindirTipiTextEN = "CYLNDR TYP/TIPPD";
    tekTesirTextEN = "Single acting   ";
    ciftTesirTextEN = "Double acting   ";
    platformSilindirTipiTextEN = "CYLNDR TYPE/PLT ";
    yukariValfSureTextEN = "UP VALVE TIMER  ";
    asagiValfSureTextEN = "DOWN VALVE TIMER";
    devirmeYukariValfSureTextEN = "TIPPD UP VLV TMR";
    ileriValfSureTextEN = "FRWD DRV VLV TMR";
    devirmeAsagiValfSureTextEN = "TPPD DWN VLV TMR";
    geriValfSureTextEN = "REVERSE VLV TMR ";
    calismaSuresiTextEN = "WORKING TIME    ";
    calismaSayisiTextEN = "Working Cycle   ";
    enterlaSifirlaTextEN = "Del. with Enter ";
    dilSecimTextEN = "LANGUAGE SELECT ";
    secilenDilTextEN = "ENGLISH         ";
    menudenCikisTextEN = " EXIT THE MENU  ";
    enteraBasinizTextEN = "PUSH ENTER BUTON";
    hataKoduTextEN = "   ERROR CODE   ";

    // IoT Messages
    dataSynchTextTR = "  Veri  Esleme  ";
    dataSynch2TextTR = " Baslatildi ... ";
    mustBeUniqueTextTR = " BU ID MAKINEDE ";
    mustBeUnique2TextTR = " KULLANILAMAZ ! ";
    mustBe12TextTR = " ID 12 KARAKTER ";
    mustBe122TextTR = " OLMAK ZORUNDA! ";
    ssidExceedErrorTextTR = " 20 KARAKTERDEN ";
    ssidExceedError2TextTR = "FAZLA SSID OLMAZ";
    passExceedErrorTextTR = " 20 KARAKTERDEN ";
    passExceedError2TextTR = "FAZLA PASS OLMAZ";
    dataYazildiTextTR = "Data yazildi    ";
    dataOkunuyorTextTR = "Data Okunuyor...";
    dataOkunduTextTR = "Data Okundu.    ";
    degerKaydedildiTextTR = "Deger Kaydedildi";
    errorCodeTextTR = "   HATA KODU    ";
    machineIDTextTR = "MAKINE ID       ";
    idConfirmationTextTR = "ID DEGISIM ONAYI";
    idConfirmationSubTextTR = "  YUKARI BASIN  ";
    wifiConfirmationTextTR = "ONAY: YUKARI BTN";

    dataSynchTextEN = " Syncronization ";
    dataSynch2TextEN = "   Started...   ";
    mustBeUniqueTextEN = " THIS ID IS NOT ";
    mustBeUnique2TextEN = "    AVAILABLE   ";
    mustBe12TextEN = " ID MUST BE  12 ";
    mustBe122TextEN = "   CHARACTERS   ";
    ssidExceedErrorTextEN = "SSID CANT EXCEED";
    ssidExceedError2TextEN = " 20  CHARACTERS ";
    passExceedErrorTextEN = "PASS CANT EXCEED";
    passExceedError2TextEN = " 20  CHARACTERS ";
    dataYazildiTextEN = "Data Wrote      ";
    dataOkunuyorTextEN = "Data Reading... ";
    dataOkunduTextEN = "Data Read.      ";
    degerKaydedildiTextEN = "Value Saved     ";
    errorCodeTextEN = "   ERROR CODE   ";
    machineIDTextEN = "MACHINE ID      ";
    idConfirmationTextEN = "ID  CONFIRMATION";
    idConfirmationSubTextEN = "PRESS UP  BUTTON";
    wifiConfirmationTextEN = "CONFRM: PRESS UP";
}
