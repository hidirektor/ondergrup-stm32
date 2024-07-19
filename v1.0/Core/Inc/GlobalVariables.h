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

extern uint64_t eepromData[110];
extern char snum[5];

extern uint64_t kaydedilenDeger;
extern unsigned long millis;
extern unsigned long timer;
extern unsigned long timer1;
extern unsigned long timer2;
extern unsigned long timer3;
extern unsigned long timer4;				// maksimum calisma kayit suresi
extern unsigned long timer5;				// basinc kayit suresi
extern unsigned long timer6;				// lcd update suresi
extern unsigned long backLightTimer;

extern uint64_t x;
extern uint64_t y;
extern uint64_t calismaSayisi;
extern uint64_t calismaSayisiDemo;
//Menü içi parametreler
extern uint64_t menuSayac;
extern uint64_t durakSayisi;
extern uint64_t calismaSekli;
extern uint64_t hataGostermeSirasi;
extern uint64_t basincVar;
extern uint64_t basincVartmr;
extern uint64_t emniyetCercevesi;
extern uint64_t yavaslamaLimit;
extern uint64_t altLimit;
extern uint64_t basincSalteri;
extern uint64_t kapiSecimleri;
extern uint64_t kapi1Tip;
extern uint64_t kapi2Tip;
extern uint64_t kapitablaTip;
extern uint64_t kapiAcTipi;
extern uint64_t kapiTablaAcKonum;
extern uint64_t yukariYavasLimit;
extern uint64_t devirmeYuruyusSecim;
extern uint64_t devirmeYukariIleriLimit;
extern uint64_t devirmeAsagiGeriLimit;
extern uint64_t devirmeSilindirTipi;
extern uint64_t platformSilindirTipi;
extern uint64_t yukariValfTmr;
extern uint64_t asagiValfTmr;
extern uint64_t devirmeYukariIleriTmr;
extern uint64_t devirmeAsagiGeriTmr;
extern uint64_t makineCalismaTmr;
extern uint64_t kapi1AcSure;
extern uint64_t kapi2AcSure;
extern uint64_t kapiTablaAcSure;
extern uint64_t buzzer;
extern uint64_t menuGiris;
extern uint64_t demoMode;
extern uint64_t iotMode;
extern uint64_t calismaSayModu;
extern uint64_t dilSecim;
extern uint64_t hataKayit1;
extern uint64_t hataKayit2;
extern uint64_t hataKayit3;
extern uint64_t hataKayit4;
extern uint64_t hataKayit5;
extern uint64_t hataKayit6;
extern uint64_t hataKayit7;
extern uint64_t hataKayit8;
extern uint64_t hataKayit9;
extern uint64_t hataKayit10;
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
extern bool EmnCerHataMakYukariCalis;
extern bool EmnStopVar;

#endif /* INC_GLOBALVARIABLES_H_ */
