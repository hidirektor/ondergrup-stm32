/*
 * Translation.c
 *
 *  Created on: Mar 6, 2024
 *      Author: hidirektor
 */

#include "Translation.h"


//Genel Metinler:
char splashTextGN[16] = "     RMK-V1     ";
char splashText2GN[16] = "ONDTECH ESP CONT";
char mainTextGN[16] = "    ESP-RMK     ";
char mainText2GN[16] = "      RUN       ";
char ondSafetyTextGN[16] = "OND Safety      ";
char prudhomeTextGN[16] = "Prudhome        ";
char pizzattoTextGN[16] = "Pizzato         ";
char buzzerTextGN[16] = "BUZZER          ";
char demoModTextGN[16] = "DEMO MODE      ";
char iotModTextGN[16] = "IoT MODE        ";


//Türkçe Metinler:
char menuyeGirildiTextTR[16] = "MENUYE  GiRDiNiZ";
char ayarlarTextTR[16] = "    AYARLAR     ";
char hataKayitListTextTR[16] = "HATA KAYIT LiST.";
char birHataKoduTextTR[16] = "1.Hata Kodu: ";
char ikiHataKoduTextTR[16] = "2.Hata Kodu: ";
char ucHataKoduTextTR[16] = "3.Hata Kodu: ";
char dortHataKoduTextTR[16] = "4.Hata Kodu: ";
char besHataKoduTextTR[16] = "5.Hata Kodu: ";
char altiHataKoduTextTR[16] = "6.Hata Kodu: ";
char yediHataKoduTextTR[16] = "7.Hata Kodu: ";
char sekizHataKoduTextTR[16] = "8.Hata Kodu: ";
char dokuzHataKoduTextTR[16] = "9.Hata Kodu: ";
char onHataKoduTextTR[16] = "10.Hata Kodu: ";
char silmekIcinTextTR[16] = "Silmek icin ent.";
char calismaSekliTextTR[16] = "CALISMA SEKLi   ";
char devirmeYuruyusTextTR[16] = "Dvr Yrys secildi";
char bastikcaCalisanTextTR[16] = "Bastikca cal.   ";
char basGonderTextTR[16] = "Bas gonder     ";
char emniyetCercevesiTextTR[16] = "EMNIYET CER.    ";
char pasifTextTR[16] = "Pasif           ";
char aktifTextTR[16] = "Aktif           ";
char yavaslamaLimitTextTR[16] = "YAVASLAMA LIMIT ";
char altLimitTextTR[16] = "ALT LIMIT       ";
char basincSalteriTextTR[16] = "BASINC SALTERI ";
char kapiSecimleriTextTR[16] = "KAPI SECIMLERI  ";
char katKapisiAktifTextTR[16] = "Kat kapisi aktif";
char tablaKapiAktifTextTR[16] = "Tabla kapi aktif";
char katArtiTablaAktifTextTR[16] = "Kat + Tabl aktif";
char kapiAcmaTipiTextTR[16] = "KAPI ACMA TIPI  ";
char kapiButonuESPTextTR[16] = "Kapi butonu ESP";
char katButonuEXTTextTR[16] = "Kat butonu EXT  ";
char birKatKapiTipiTextTR[16] = "1.KAT KAPI TiPi ";
char butonKontrolluTextTR[16] = "Buton kontrollu";
char birinciKapiAcSuresiTextTR[16] = "1.KAPI AC SURESi";
char kacSaniyeTextTR[16] = "Kac Saniye     ";
char ikinciKatKapiTipiTextTR[16] = "2.KAT KAPI TiPi ";
char ikinciKapiAcSuresiTextTR[16] = "2.KAPI AC SURESi";
char tablaKapiTipiTextTR[16] = "TABLA KAPI TiPi ";
char tablaKapiAcKonumTextTR[16] = "TBL KPI AC KONUM";
char birinciKattaAcTextTR[16] = "1. Katta ac    ";
char ikinciKattaAcTextTR[16] = "2. Katta ac    ";
char birVeIkinciKattaAcTextTR[16] = "1.+2. Katta ac  ";
char tablaKapiAcSureTextTR[16] = "TABLA KP AC SURE";
char yukariYavaslamaLimitiTextTR[16] = "YUKARI YAVAS LMT";
char devirmeYuruyusMenuTextTR[16] = "DEVIRME-YURUYUS ";
char devirmeAktifTextTR[16] = "Devirme aktif  ";
char yuruyusAktifTextTR[16] = "Yuruyus aktif  ";
char devirmeYukariTextTR[16] = "DEVRM YUKARI SVC";
char yuruyusIleriTextTR[16] = "YURUYUS ILER SVC";
char devirmeAsagiSivicTextTR[16] = "DEVIRM ASAGI SVC";
char yuruyusGeriSivicTextTR[16] = "YURUYUS GERI SVC";
char yuruyusSecildiTextTR[16] = "YURUYUS SECiLDi ";
char devirmeSilindirTipiTextTR[16] = "DEVIRME SLN TIPI";
char tekTesirTextTR[16] = "Tek tesir       ";
char ciftTesirTextTR[16] = "Cift tesir      ";
char platformSilindirTipiTextTR[16] = "PLATFRM SLN TIPI";
char yukariValfSureTextTR[16] = "YUKARI VALF SURE";
char asagiValfSureTextTR[16] = "ASAGI VALF SURE ";
char devirmeYukariValfSureTextTR[16] = "DVRM YKR VLF SN ";
char ileriValfSureTextTR[16] = "iLERi VALF SURE ";
char devirmeAsagiValfSureTextTR[16] = "DVRM ASG VALF SN";
char geriValfSureTextTR[16] = "GERi VALF SURE  ";
char calismaSuresiTextTR[16] = "CALiSMA SURESi  ";
char calismaSayisiTextTR[16] = "Calisma Sayisi  ";
char enterlaSifirlaTextTR[16] = "Enter'la Sifirla";
char dilSecimTextTR[16] = "DIL SECIMI      ";
char secilenDilTextTR[16] = "TURKCE         ";
char menudenCikisTextTR[16] = " MENUDEN CIKIS  ";
char enteraBasinizTextTR[16] = "ENTER'A BASINIZ ";
char hataKoduTextTR[16] = "   HATA KODU    ";

//İngilizce Metinler:
char menuyeGirildiTextEN[16] = "ENTERED THE MENU";
char ayarlarTextEN[16] = "    SETTINGS    ";
char hataKayitListTextEN[16] = "ERROR SAVE LiST.";
char birHataKoduTextEN[16] = "1.Error Code:";
char ikiHataKoduTextEN[16] = "2.Error Code:";
char ucHataKoduTextEN[16] = "3.Error Code:";
char dortHataKoduTextEN[16] = "4.Error Code:";
char besHataKoduTextEN[16] = "5.Error Code:";
char altiHataKoduTextEN[16] = "6.Error Code:";
char yediHataKoduTextEN[16] = "7.Error Code:";
char sekizHataKoduTextEN[16] = "8.Error Code:";
char dokuzHataKoduTextEN[16] = "9.Error Code:";
char onHataKoduTextEN[16] = "10.Error Code:";
char silmekIcinTextEN[16] = "Del. press enter";
char calismaSekliTextEN[16] = "WORKNG PRINCIPLE";
char devirmeYuruyusTextEN[16] = "Tppng Mobil slct";
char bastikcaCalisanTextEN[16] = "Deadman Control";
char basGonderTextEN[16] = "Call & Send    ";
char emniyetCercevesiTextEN[16] = "SAFETY FRAME    ";
char pasifTextEN[16] = "Passive         ";
char aktifTextEN[16] = "Active          ";
char yavaslamaLimitTextEN[16] = "SLOW DOWN LIMIT ";
char altLimitTextEN[16] = "DOWN LIMIT      ";
char basincSalteriTextEN[16] = "PRESSURE SWITCH";
char kapiSecimleriTextEN[16] = "DOOR SELECTION  ";
char katKapisiAktifTextEN[16] = "Floor door act  ";
char tablaKapiAktifTextEN[16] = "Pltfrm door act ";
char katArtiTablaAktifTextEN[16] = "Flr + Plrfrm act";
char kapiAcmaTipiTextEN[16] = "OPEN DOOR TYPE  ";
char kapiButonuESPTextEN[16] = "Door Button ESP";
char katButonuEXTTextEN[16] = "Floor button EXT";
char birKatKapiTipiTextEN[16] = "1.FLOOR DOOR TYP";
char butonKontrolluTextEN[16] = "Button cntrolled";
char birinciKapiAcSuresiTextEN[16] = "1.FLR DR OPN TMR";
char kacSaniyeTextEN[16] = "Seconds        ";
char ikinciKatKapiTipiTextEN[16] = "2.FLOOR DOOR TYP";
char ikinciKapiAcSuresiTextEN[16] = "2.FLR DR OPN TMR";
char tablaKapiTipiTextEN[16] = "PLTFRM DOOR TYPE";
char tablaKapiAcKonumTextEN[16] = "PLTFRM DR OP LOC";
char birinciKattaAcTextEN[16] = "1. Floor open  ";
char ikinciKattaAcTextEN[16] = "2. Floor open  ";
char birVeIkinciKattaAcTextEN[16] = "1.+2. Floor open";
char tablaKapiAcSureTextEN[16] = "PLTFM DR OPN TMR";
char yukariYavaslamaLimitiTextEN[16] = "UPPR SLW DWN LMT";
char devirmeYuruyusMenuTextEN[16] = "TPPNG-MOBIL PLT ";
char devirmeAktifTextEN[16] = "Tipping active ";
char yuruyusAktifTextEN[16] = "Drive active   ";
char devirmeYukariTextEN[16] = "TPPNG SWTCH/OPN";
char yuruyusIleriTextEN[16] = "DRVE FRWRD SWTCH";
char devirmeAsagiSivicTextEN[16] = "TPPNG SWTCH/CLSD";
char yuruyusGeriSivicTextEN[16] = "DRIVE BACK SWTCH";
char yuruyusSecildiTextEN[16] = "DRIVE SELECTED  ";
char devirmeSilindirTipiTextEN[16] = "CYLNDR TYP/TIPPD";
char tekTesirTextEN[16] = "Single acting  ";
char ciftTesirTextEN[16] = "Double acting  ";
char platformSilindirTipiTextEN[16] = "CYLNDR TYPE/PLT";
char yukariValfSureTextEN[16] = "UP VALVE TIMER  ";
char asagiValfSureTextEN[16] = "DOWN VALVE TIMER";
char devirmeYukariValfSureTextEN[16] = "TIPPD UP VLV TMR";
char ileriValfSureTextEN[16] = "FRWD DRV VLV TMR";
char devirmeAsagiValfSureTextEN[16] = "TPPD DWN VLV TMR";
char geriValfSureTextEN[16] = "REVERSE VLV TMR ";
char calismaSuresiTextEN[16] = "WORKING TIME    ";
char calismaSayisiTextEN[16] = "Working Cycle   ";
char enterlaSifirlaTextEN[16] = "Del. with Enter ";
char dilSecimTextEN[16] = "LANGUAGE SELECT ";
char secilenDilTextEN[16] = "ENGLISH        ";
char menudenCikisTextEN[16] = " EXIT THE MENU  ";
char enteraBasinizTextEN[16] = "PUSH ENTER BUTON";
char hataKoduTextEN[16] = "   ERROR CODE   ";

//IoT Messages:
char dataSynchTextTR[16] = "  Veri  Esleme  ";
char dataSynch2TextTR[16] = " Baslatildi ... ";
char mustBeUniqueTextTR[16] = " BU ID MAKINEDE ";
char mustBeUnique2TextTR[16] = " KULLANILAMAZ ! ";
char mustBeUniqueTextEN[16] = " THIS ID IS NOT ";
char mustBeUnique2TextEN[16] = "    AVAILABLE   ";

char dataSynchTextEN[16] = " Syncronization ";
char dataSynch2TextEN[16] = "   Started...   ";
char mustBe12TextTR[16] = " ID 12 KARAKTER ";
char mustBe122TextTR[16] = " OLMAK ZORUNDA! ";
char mustBe12TextEN[16] = " ID MUST BE  12 ";
char mustBe122TextEN[16] = "   CHARACTERS   ";

char ssidExceedErrorTextTR[16] = " 20 KARAKTERDEN ";
char ssidExceedError2TextTR[16] = "FAZLA SSID OLMAZ";
char ssidExceedErrorTextEN[16] = "SSID CANT EXCEED";
char ssidExceedError2TextEN[16] = " 20  CHARACTERS ";

char passExceedErrorTextTR[16] = " 20 KARAKTERDEN ";
char passExceedError2TextTR[16] = "FAZLA PASS OLMAZ";
char passExceedErrorTextEN[16] = "PASS CANT EXCEED";
char passExceedError2TextEN[16] = " 20  CHARACTERS ";