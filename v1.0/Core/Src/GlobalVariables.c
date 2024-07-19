/*
 * GlobalVariables.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "GlobalVariables.h"


uint64_t eepromData[110];
char snum[5];

uint64_t kaydedilenDeger = 0;

unsigned long millis = 0;
unsigned long timer = 0;
unsigned long timer1 = 0;
unsigned long timer2 = 0;
unsigned long timer3 = 0;
unsigned long timer4 = 0;				// maksimum calisma kayit suresi
unsigned long timer5 = 0;				// basinc kayit suresi
unsigned long timer6 = 0;				// lcd update suresi
unsigned long backLightTimer = 0;

uint64_t idKontrol = 0;
uint64_t safeVal = 0;

uint64_t x = 0;
uint64_t y = 0;
uint64_t calismaSayisi = 0;
uint64_t calismaSayisiDemo = 0;
//Menü içi parametreler
uint64_t menuSayac = 0;
uint64_t durakSayisi = 0;
uint64_t calismaSekli = 0;
uint64_t hataGostermeSirasi = 0;
uint64_t basincVar = 0;
uint64_t basincVartmr = 0;
uint64_t emniyetCercevesi = 0;
uint64_t yavaslamaLimit = 0;
uint64_t altLimit = 0;
uint64_t basincSalteri = 0;
uint64_t kapiSecimleri = 0;
uint64_t kapi1Tip = 0;
uint64_t kapi2Tip = 0;
uint64_t kapitablaTip = 0;
uint64_t kapiAcTipi = 0;
uint64_t kapiTablaAcKonum = 0;
uint64_t yukariYavasLimit = 0;
uint64_t devirmeYuruyusSecim = 0;
uint64_t devirmeYukariIleriLimit = 0;
uint64_t devirmeAsagiGeriLimit = 0;
uint64_t devirmeSilindirTipi = 0;
uint64_t platformSilindirTipi = 0;
uint64_t yukariValfTmr = 0;
uint64_t asagiValfTmr = 0;
uint64_t devirmeYukariIleriTmr = 0;
uint64_t devirmeAsagiGeriTmr = 0;
uint64_t makineCalismaTmr = 0;
uint64_t kapi1AcSure = 0;
uint64_t kapi2AcSure = 0;
uint64_t kapiTablaAcSure = 0;
uint64_t buzzer = 0;
uint64_t menuGiris = 0;
uint64_t demoMode = 0;
uint64_t iotMode = 0;
uint64_t calismaSayModu = 0;
uint64_t dilSecim = 0;
uint64_t hataKayit1 = 0;
uint64_t hataKayit2 = 0;
uint64_t hataKayit3 = 0;
uint64_t hataKayit4 = 0;
uint64_t hataKayit5 = 0;
uint64_t hataKayit6 = 0;
uint64_t hataKayit7 = 0;
uint64_t hataKayit8 = 0;
uint64_t hataKayit9 = 0;
uint64_t hataKayit10 = 0;
bool hafizaYaz = 0;
bool hafizaOku = 0;
bool ilkOkuma = 0;
bool butonKontrol = 0;
bool butonKontrol2 = 0;
bool butonKontrol3 = 0;
bool butonKontrol4 = 0;
bool butonKontrol5 = 0;
bool mesajYazildi = 0;
bool yukarimotorcalisiyor = 0;
bool devmotoryukaricalisiyor = 0;
bool devmotorasagicalisiyor = 0;
bool asagivalfcalisiyor = 0;
bool yukarivalfcalisiyor = 0;
bool devyukarivalfcalisiyor = 0;
bool devasagivalfcalisiyor = 0;
bool basgondercalisyukari = 0;
bool basgondercalisasagi = 0;
bool demoCalismaSayisiYar = 0;
bool CalismaSayisiYukari = 0;
bool CalismaSayisiAsagi = 0;
bool calismaSayisiYar = 0;
bool makineStop = 0;
bool kapi1prudhome = 0; bool kapi1butonkontrol = 0; bool kapi1pizzato = 0;
bool kapi2prudhome = 0; bool kapi2butonkontrol = 0; bool kapi2pizzato = 0;
bool kapiTablaprudhome = 0; bool kapiTablabutonkontrol = 0; bool kapiTablapizzato = 0;
bool kapiTablaAcKonumKat1 = 0; bool kapiTablaAcKonumKat2 = 0;
bool startBasili = 0;
bool maksimumcalismahatasi = 0;
bool acilstophatasi = 0;
bool emniyetCercevesihatasi = 0;
bool stopVar = 0;
bool kapiSivicVar = 0;
bool motorcalisiyor = 0;
bool hataVar = 0;
bool makineCalisiyor = 0;
bool cerceveVar = 0;
bool demoYukariCalis = 0;
bool demoAsagiCalis = 0;
bool demoDevYukari = 0;
bool demoDevAsagi = 0;
bool kapiactablaesp1 = 0;
bool kapiactablaesp2 = 0;
bool basinchatasi = 0;
bool katkapisivicihatasi = 0;
bool tablakapisivicihatasi = 0;
bool cercevesasagicalisma = 0;
bool HataMakineCalisiyorkapi = 0;
bool HataMakineCalisiyortabla = 0;
bool EmnCerHataMakYukariCalis = 0;
bool EmnStopVar = 0;
