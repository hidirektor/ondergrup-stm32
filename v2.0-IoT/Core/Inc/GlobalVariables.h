/*
 * GlobalVariables.h
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#ifndef INC_GLOBALVARIABLES_H_
#define INC_GLOBALVARIABLES_H_

#include "SystemDefaults.h"
#include <stdint.h>
#include <stdbool.h>

extern uint8_t eepromData[110];
extern char snum[5];
extern char machineID[machineIDCharacterLimit];
extern char wifiSSID[wifiCharacterLimit];
extern char wifiPass[wifiCharacterLimit];
extern uint8_t wifiSSIDInt[wifiCharacterLimit];
extern uint8_t wifiPassInt[wifiCharacterLimit];

extern uint8_t setupCompleted;

extern uint8_t kaydedilenDeger;
extern unsigned long millis;
extern unsigned long timer;
extern unsigned long timer1;
extern unsigned long timer2;
extern unsigned long timer3;
extern unsigned long timer4;				// maksimum calisma kayit suresi
extern unsigned long timer5;				// basinc kayit suresi
extern unsigned long timer6;				// lcd update suresi
extern unsigned long backLightTimer;

extern int cursorPosition;
extern int page;

extern uint8_t idKontrol;
extern uint8_t safeVal;

extern uint8_t x;
extern uint8_t y;
extern uint8_t calismaSayisi; //
extern uint8_t calismaSayisi1; //
extern uint8_t calismaSayisi10; //
extern uint8_t calismaSayisi100; //
extern uint8_t calismaSayisi1000; //
extern uint8_t calismaSayisi10000; //
//Menü içi parametreler
extern uint8_t menuSayac;
extern uint8_t durakSayisi;
extern uint8_t calismaSekli;
extern uint8_t hataGostermeSirasi;
extern uint8_t basincVar;
extern uint8_t basincVartmr;
extern uint8_t emniyetCercevesi;
extern uint8_t yavaslamaLimit;
extern uint8_t altLimit;
extern uint8_t basincSalteri;
extern uint8_t kapiSecimleri;
extern uint8_t kapi1Tip;
extern uint8_t kapi2Tip;
extern uint8_t kapitablaTip;
extern uint8_t kapiAcTipi;
extern uint8_t kapiTablaAcKonum;
extern uint8_t yukariYavasLimit;
extern uint8_t devirmeYuruyusSecim;
extern uint8_t devirmeYukariIleriLimit;
extern uint8_t devirmeAsagiGeriLimit;
extern uint8_t devirmeSilindirTipi;
extern uint8_t platformSilindirTipi;
extern uint8_t yukariValfTmr;
extern uint8_t asagiValfTmr;
extern uint8_t devirmeYukariIleriTmr;
extern uint8_t devirmeAsagiGeriTmr;
extern uint8_t makineCalismaTmr;
extern uint8_t kapi1AcSure;
extern uint8_t kapi2AcSure;
extern uint8_t kapiTablaAcSure;
extern uint8_t buzzer;
extern uint8_t menuGiris;
extern uint8_t demoMode;
extern uint8_t iotMode;
extern uint8_t calismaSayModu;
extern uint8_t dilSecim;
extern uint8_t hataKayit1;
extern uint8_t hataKayit2;
extern uint8_t hataKayit3;
extern uint8_t hataKayit4;
extern uint8_t hataKayit5;
extern uint8_t hataKayit6;
extern uint8_t hataKayit7;
extern uint8_t hataKayit8;
extern uint8_t hataKayit9;
extern uint8_t hataKayit10;
extern bool hafizaYaz;
extern bool hafizaOku;
extern bool ilkOkuma;
extern bool butonKontrol;
extern bool butonKontrol2;
extern bool butonKontrol3;
extern bool butonKontrol4;
extern bool butonKontrol5;
extern bool mesajYazildi;
extern bool yukarimotorcalisiyor;
extern bool devmotoryukaricalisiyor;
extern bool devmotorasagicalisiyor;
extern bool asagivalfcalisiyor;
extern bool yukarivalfcalisiyor;
extern bool devyukarivalfcalisiyor;
extern bool devasagivalfcalisiyor;
extern bool basgondercalisyukari;
extern bool basgondercalisasagi;
extern bool demoCalismaSayisiYar;
extern bool CalismaSayisiYukari;
extern bool CalismaSayisiAsagi;
extern bool calismaSayisiYar;
extern bool makineStop;
extern bool kapi1prudhome; extern bool kapi1butonkontrol; extern bool kapi1pizzato;
extern bool kapi2prudhome; extern bool kapi2butonkontrol; extern bool kapi2pizzato;
extern bool kapiTablaprudhome; extern bool kapiTablabutonkontrol; extern bool kapiTablapizzato;
extern bool kapiTablaAcKonumKat1; extern bool kapiTablaAcKonumKat2;
extern bool startBasili;
extern bool maksimumcalismahatasi;
extern bool acilstophatasi;
extern bool emniyetCercevesihatasi;
extern bool stopVar;
extern bool kapiSivicVar;
extern bool motorcalisiyor;
extern bool hataVar;
extern bool makineCalisiyor;
extern bool cerceveVar;
extern bool demoYukariCalis;
extern bool demoAsagiCalis;
extern bool demoDevYukari;
extern bool demoDevAsagi;
extern bool kapiactablaesp1;
extern bool kapiactablaesp2;
extern bool basinchatasi;
extern bool katkapisivicihatasi;
extern bool tablakapisivicihatasi;
extern bool cercevesasagicalisma;
extern bool HataMakineCalisiyorkapi;
extern bool HataMakineCalisiyortabla;

#endif /* INC_GLOBALVARIABLES_H_ */
