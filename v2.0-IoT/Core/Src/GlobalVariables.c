/*
 * GlobalVariables.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "GlobalVariables.h"


uint8_t eepromData[110] = {0};
char snum[5] = {0};
char machineID[machineIDCharacterLimit] = {0};
char wifiSSID[wifiCharacterLimit] = {0};
char wifiPass[wifiCharacterLimit] = {0};
uint8_t machineIDInt[machineIDCharacterLimit] = {0};
uint8_t wifiSSIDInt[wifiCharacterLimit] = {0};
uint8_t wifiPassInt[wifiCharacterLimit] = {0};

uint8_t setupCompleted = 0;

uint8_t kaydedilenDeger = 0;

unsigned long millis = 0;
unsigned long timer = 0;
unsigned long timer1 = 0;
unsigned long timer2 = 0;
unsigned long timer3 = 0;
unsigned long timer4 = 0;				// maksimum calisma kayit suresi
unsigned long timer5 = 0;				// basinc kayit suresi
unsigned long timer6 = 0;				// lcd update suresi
unsigned long backLightTimer = 0;

uint8_t idKontrol = 0;
uint8_t safeVal = 0;

uint8_t x = 0;
uint8_t y = 0;
uint8_t calismaSayisi = 0; //
uint8_t calismaSayisi1 = 0; //
uint8_t calismaSayisi10 = 0; //
uint8_t calismaSayisi100 = 2; //
uint8_t calismaSayisi1000 = 1; //
uint8_t calismaSayisi10000 = 0; //
//Menü içi parametreler
uint8_t menuSayac = 0;
uint8_t durakSayisi = 0;
uint8_t calismaSekli = 0;
uint8_t hataGostermeSirasi = 0;
uint8_t basincVar = 0;
uint8_t basincVartmr = 0;
uint8_t emniyetCercevesi = 0;
uint8_t yavaslamaLimit = 0;
uint8_t altLimit = 0;
uint8_t basincSalteri = 0;
uint8_t kapiSecimleri = 0;
uint8_t kapi1Tip = 0;
uint8_t kapi2Tip = 0;
uint8_t kapitablaTip = 0;
uint8_t kapiAcTipi = 0;
uint8_t kapiTablaAcKonum = 0;
uint8_t yukariYavasLimit = 0;
uint8_t devirmeYuruyusSecim = 0;
uint8_t devirmeYukariIleriLimit = 0;
uint8_t devirmeAsagiGeriLimit = 0;
uint8_t devirmeSilindirTipi = 0;
uint8_t platformSilindirTipi = 0;
uint8_t yukariValfTmr = 0;
uint8_t asagiValfTmr = 0;
uint8_t devirmeYukariIleriTmr = 0;
uint8_t devirmeAsagiGeriTmr = 0;
uint8_t makineCalismaTmr = 0;
uint8_t kapi1AcSure = 0;
uint8_t kapi2AcSure = 0;
uint8_t kapiTablaAcSure = 0;
uint8_t buzzer = 0;
uint8_t menuGiris = 0;
uint8_t demoMode = 0;
uint8_t iotMode = 0;
uint8_t calismaSayModu = 0;
uint8_t dilSecim = 0;
uint8_t hataKayit1 = 0;
uint8_t hataKayit2 = 0;
uint8_t hataKayit3 = 0;
uint8_t hataKayit4 = 0;
uint8_t hataKayit5 = 0;
uint8_t hataKayit6 = 0;
uint8_t hataKayit7 = 0;
uint8_t hataKayit8 = 0;
uint8_t hataKayit9 = 0;
uint8_t hataKayit10 = 0;
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
