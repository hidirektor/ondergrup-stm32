/*
 * Translation.c
 *
 *  Created on: Mar 6, 2024
 *      Author: hidirektor
 */

#include "Translation.h"


//Genel Metinler:
char splashTextGN[17] = "     RMK-V1     ";
char splashText2GN[17] = "ONDTECH ESP CONT";
char mainTextGN[17] = "    ESP-RMK     ";
char mainText2GN[17] = "      RUN       ";
char ondSafetyTextGN[17] = "OND Safety      ";
char prudhomeTextGN[17] = "Prudhome        ";
char pizzattoTextGN[17] = "Pizzato         ";
char buzzerTextGN[17] = "BUZZER          ";
char demoModTextGN[17] = "DEMO MODE      ";
char iotModTextGN[17] = "IoT MODE        ";
char cycleTextGN[17] = "Cycle      ";
char eepromTextGN[17] = "   **EEPROM**   ";


//Türkçe Metinler:
char menuyeGirildiTextTR[17] = "MENUYE  GiRDiNiZ";
char ayarlarTextTR[17] = "    AYARLAR     ";
char hataKayitListTextTR[17] = "HATA KAYIT LiST.";
char birHataKoduTextTR[17] = "1.Hata Kodu: ";
char ikiHataKoduTextTR[17] = "2.Hata Kodu: ";
char ucHataKoduTextTR[17] = "3.Hata Kodu: ";
char dortHataKoduTextTR[17] = "4.Hata Kodu: ";
char besHataKoduTextTR[17] = "5.Hata Kodu: ";
char altiHataKoduTextTR[17] = "6.Hata Kodu: ";
char yediHataKoduTextTR[17] = "7.Hata Kodu: ";
char sekizHataKoduTextTR[17] = "8.Hata Kodu: ";
char dokuzHataKoduTextTR[17] = "9.Hata Kodu: ";
char onHataKoduTextTR[17] = "10.Hata Kodu: ";
char silmekIcinTextTR[17] = "Silmek icin ent.";
char calismaSekliTextTR[17] = "CALISMA SEKLi   ";
char devirmeYuruyusTextTR[17] = "Dvr Yrys secildi";
char bastikcaCalisanTextTR[17] = "Bastikca cal.   ";
char basGonderTextTR[17] = "Bas gonder     ";
char emniyetCercevesiTextTR[17] = "EMNIYET CER.    ";
char pasifTextTR[17] = "Pasif           ";
char aktifTextTR[17] = "Aktif           ";
char yavaslamaLimitTextTR[17] = "YAVASLAMA LIMIT ";
char altLimitTextTR[17] = "ALT LIMIT       ";
char basincSalteriTextTR[17] = "BASINC SALTERI ";
char kapiSecimleriTextTR[17] = "KAPI SECIMLERI  ";
char katKapisiAktifTextTR[17] = "Kat kapisi aktif";
char tablaKapiAktifTextTR[17] = "Tabla kapi aktif";
char katArtiTablaAktifTextTR[17] = "Kat + Tabl aktif";
char kapiAcmaTipiTextTR[17] = "KAPI ACMA TIPI  ";
char kapiButonuESPTextTR[17] = "Kapi butonu ESP";
char katButonuEXTTextTR[17] = "Kat butonu EXT  ";
char birKatKapiTipiTextTR[17] = "1.KAT KAPI TiPi ";
char butonKontrolluTextTR[17] = "Buton kontrollu";
char birinciKapiAcSuresiTextTR[17] = "1.KAPI AC SURESi";
char kacSaniyeTextTR[17] = "Kac Saniye     ";
char ikinciKatKapiTipiTextTR[17] = "2.KAT KAPI TiPi ";
char ikinciKapiAcSuresiTextTR[17] = "2.KAPI AC SURESi";
char tablaKapiTipiTextTR[17] = "TABLA KAPI TiPi ";
char tablaKapiAcKonumTextTR[17] = "TBL KPI AC KONUM";
char birinciKattaAcTextTR[17] = "1. Katta ac    ";
char ikinciKattaAcTextTR[17] = "2. Katta ac    ";
char birVeIkinciKattaAcTextTR[17] = "1.+2. Katta ac  ";
char tablaKapiAcSureTextTR[17] = "TABLA KP AC SURE";
char yukariYavaslamaLimitiTextTR[17] = "YUKARI YAVAS LMT";
char devirmeYuruyusMenuTextTR[17] = "DEVIRME-YURUYUS ";
char devirmeAktifTextTR[17] = "Devirme aktif  ";
char yuruyusAktifTextTR[17] = "Yuruyus aktif  ";
char devirmeYukariTextTR[17] = "DEVRM YUKARI SVC";
char yuruyusIleriTextTR[17] = "YURUYUS ILER SVC";
char devirmeAsagiSivicTextTR[17] = "DEVIRM ASAGI SVC";
char yuruyusGeriSivicTextTR[17] = "YURUYUS GERI SVC";
char yuruyusSecildiTextTR[17] = "YURUYUS SECiLDi ";
char devirmeSilindirTipiTextTR[17] = "DEVIRME SLN TIPI";
char tekTesirTextTR[17] = "Tek tesir       ";
char ciftTesirTextTR[17] = "Cift tesir      ";
char platformSilindirTipiTextTR[17] = "PLATFRM SLN TIPI";
char yukariValfSureTextTR[17] = "YUKARI VALF SURE";
char asagiValfSureTextTR[17] = "ASAGI VALF SURE ";
char devirmeYukariValfSureTextTR[17] = "DVRM YKR VLF SN ";
char ileriValfSureTextTR[17] = "iLERi VALF SURE ";
char devirmeAsagiValfSureTextTR[17] = "DVRM ASG VALF SN";
char geriValfSureTextTR[17] = "GERi VALF SURE  ";
char calismaSuresiTextTR[17] = "CALiSMA SURESi  ";
char calismaSayisiTextTR[17] = "Calisma Sayisi  ";
char enterlaSifirlaTextTR[17] = "Enter'la Sifirla";
char dilSecimTextTR[17] = "DIL SECIMI      ";
char secilenDilTextTR[17] = "TURKCE         ";
char menudenCikisTextTR[17] = " MENUDEN CIKIS  ";
char enteraBasinizTextTR[17] = "ENTER'A BASINIZ ";
char hataKoduTextTR[17] = "   HATA KODU    ";

//İngilizce Metinler:
char menuyeGirildiTextEN[17] = "ENTERED THE MENU";
char ayarlarTextEN[17] = "    SETTINGS    ";
char hataKayitListTextEN[17] = "ERROR SAVE LiST.";
char birHataKoduTextEN[17] = "1.Error Code:";
char ikiHataKoduTextEN[17] = "2.Error Code:";
char ucHataKoduTextEN[17] = "3.Error Code:";
char dortHataKoduTextEN[17] = "4.Error Code:";
char besHataKoduTextEN[17] = "5.Error Code:";
char altiHataKoduTextEN[17] = "6.Error Code:";
char yediHataKoduTextEN[17] = "7.Error Code:";
char sekizHataKoduTextEN[17] = "8.Error Code:";
char dokuzHataKoduTextEN[17] = "9.Error Code:";
char onHataKoduTextEN[17] = "10.Error Code:";
char silmekIcinTextEN[17] = "Del. press enter";
char calismaSekliTextEN[17] = "WORKNG PRINCIPLE";
char devirmeYuruyusTextEN[17] = "Tppng Mobil slct";
char bastikcaCalisanTextEN[17] = "Deadman Control";
char basGonderTextEN[17] = "Call & Send    ";
char emniyetCercevesiTextEN[17] = "SAFETY FRAME    ";
char pasifTextEN[17] = "Passive         ";
char aktifTextEN[17] = "Active          ";
char yavaslamaLimitTextEN[17] = "SLOW DOWN LIMIT ";
char altLimitTextEN[17] = "DOWN LIMIT      ";
char basincSalteriTextEN[17] = "PRESSURE SWITCH";
char kapiSecimleriTextEN[17] = "DOOR SELECTION  ";
char katKapisiAktifTextEN[17] = "Floor door act  ";
char tablaKapiAktifTextEN[17] = "Pltfrm door act ";
char katArtiTablaAktifTextEN[17] = "Flr + Plrfrm act";
char kapiAcmaTipiTextEN[17] = "OPEN DOOR TYPE  ";
char kapiButonuESPTextEN[17] = "Door Button ESP";
char katButonuEXTTextEN[17] = "Floor button EXT";
char birKatKapiTipiTextEN[17] = "1.FLOOR DOOR TYP";
char butonKontrolluTextEN[17] = "Button cntrolled";
char birinciKapiAcSuresiTextEN[17] = "1.FLR DR OPN TMR";
char kacSaniyeTextEN[17] = "Seconds        ";
char ikinciKatKapiTipiTextEN[17] = "2.FLOOR DOOR TYP";
char ikinciKapiAcSuresiTextEN[17] = "2.FLR DR OPN TMR";
char tablaKapiTipiTextEN[17] = "PLTFRM DOOR TYPE";
char tablaKapiAcKonumTextEN[17] = "PLTFRM DR OP LOC";
char birinciKattaAcTextEN[17] = "1. Floor open  ";
char ikinciKattaAcTextEN[17] = "2. Floor open  ";
char birVeIkinciKattaAcTextEN[17] = "1.+2. Floor open";
char tablaKapiAcSureTextEN[17] = "PLTFM DR OPN TMR";
char yukariYavaslamaLimitiTextEN[17] = "UPPR SLW DWN LMT";
char devirmeYuruyusMenuTextEN[17] = "TPPNG-MOBIL PLT ";
char devirmeAktifTextEN[17] = "Tipping active ";
char yuruyusAktifTextEN[17] = "Drive active   ";
char devirmeYukariTextEN[17] = "TPPNG SWTCH/OPN";
char yuruyusIleriTextEN[17] = "DRVE FRWRD SWTCH";
char devirmeAsagiSivicTextEN[17] = "TPPNG SWTCH/CLSD";
char yuruyusGeriSivicTextEN[17] = "DRIVE BACK SWTCH";
char yuruyusSecildiTextEN[17] = "DRIVE SELECTED  ";
char devirmeSilindirTipiTextEN[17] = "CYLNDR TYP/TIPPD";
char tekTesirTextEN[17] = "Single acting  ";
char ciftTesirTextEN[17] = "Double acting  ";
char platformSilindirTipiTextEN[17] = "CYLNDR TYPE/PLT";
char yukariValfSureTextEN[17] = "UP VALVE TIMER  ";
char asagiValfSureTextEN[17] = "DOWN VALVE TIMER";
char devirmeYukariValfSureTextEN[17] = "TIPPD UP VLV TMR";
char ileriValfSureTextEN[17] = "FRWD DRV VLV TMR";
char devirmeAsagiValfSureTextEN[17] = "TPPD DWN VLV TMR";
char geriValfSureTextEN[17] = "REVERSE VLV TMR ";
char calismaSuresiTextEN[17] = "WORKING TIME    ";
char calismaSayisiTextEN[17] = "Working Cycle   ";
char enterlaSifirlaTextEN[17] = "Del. with Enter ";
char dilSecimTextEN[17] = "LANGUAGE SELECT ";
char secilenDilTextEN[17] = "ENGLISH        ";
char menudenCikisTextEN[17] = " EXIT THE MENU  ";
char enteraBasinizTextEN[17] = "PUSH ENTER BUTON";
char hataKoduTextEN[17] = "   ERROR CODE   ";

//IoT Messages:
char dataSynchTextTR[17] = "  Veri  Esleme  ";
char dataSynch2TextTR[17] = " Baslatildi ... ";
char mustBeUniqueTextTR[17] = " BU ID MAKINEDE ";
char mustBeUnique2TextTR[17] = " KULLANILAMAZ ! ";
char mustBeUniqueTextEN[17] = " THIS ID IS NOT ";
char mustBeUnique2TextEN[17] = "    AVAILABLE   ";

char dataSynchTextEN[17] = " Syncronization ";
char dataSynch2TextEN[17] = "   Started...   ";
char mustBe12TextTR[17] = " ID 12 KARAKTER ";
char mustBe122TextTR[17] = " OLMAK ZORUNDA! ";
char mustBe12TextEN[17] = " ID MUST BE  12 ";
char mustBe122TextEN[17] = "   CHARACTERS   ";

char ssidExceedErrorTextTR[17] = " 20 KARAKTERDEN ";
char ssidExceedError2TextTR[17] = "FAZLA SSID OLMAZ";
char ssidExceedErrorTextEN[17] = "SSID CANT EXCEED";
char ssidExceedError2TextEN[17] = " 20  CHARACTERS ";

char passExceedErrorTextTR[17] = " 20 KARAKTERDEN ";
char passExceedError2TextTR[17] = "FAZLA PASS OLMAZ";
char passExceedErrorTextEN[17] = "PASS CANT EXCEED";
char passExceedError2TextEN[17] = " 20  CHARACTERS ";

//EEPROM Messages:
char dataYazildiTextTR[17] = "Data yazildi    ";
char dataYazildiTextEN[17] = "Data Wrote      ";

char dataOkunuyorTextTR[17] = "Data Okunuyor...";
char dataOkunuyorTextEN[17] = "Data Reading... ";

char dataOkunduTextTR[17] = "Data Okundu.    ";
char dataOkunduTextEN[17] = "Data Read.      ";

char degerKaydedildiTextTR[17] = "Deger Kaydedildi";
char degerKaydedildiTextEN[17] = "Value Saved     ";

//Error List:
char errorCodeTextTR[17] = "   HATA KODU";
char errorCodeTextEN[17] = "   ERROR CODE";

//Hardware Test:
char machineIDTextTR[17] = "MAKINE ID       ";
char machineIDTextEN[17] = "MACHINE ID      ";
