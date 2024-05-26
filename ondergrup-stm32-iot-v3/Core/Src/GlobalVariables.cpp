/*
 * GlobalVariables.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


#include "GlobalVariables.h"

GlobalVariables::GlobalVariables()
    : setupCompleted(0), kaydedilenDeger(0), millis(0), timer(0), timer1(0), timer2(0), timer3(0), timer4(0),
      timer5(0), timer6(0), backLightTimer(0), cursorPosition(0), page(0), idKontrol(0), safeVal(0), x(0), y(0),
      calismaSayisi(0), calismaSayisi1(0), calismaSayisi10(0), calismaSayisi100(2), calismaSayisi1000(1), calismaSayisi10000(0),
      menuSayac(0), durakSayisi(0), calismaSekli(0), hataGostermeSirasi(0), basincVar(0), basincVartmr(0), emniyetCercevesi(0),
      yavaslamaLimit(0), altLimit(0), basincSalteri(0), kapiSecimleri(0), kapi1Tip(0), kapi2Tip(0), kapitablaTip(0),
      kapiAcTipi(0), kapiTablaAcKonum(0), yukariYavasLimit(0), devirmeYuruyusSecim(0), devirmeYukariIleriLimit(0),
      devirmeAsagiGeriLimit(0), devirmeSilindirTipi(0), platformSilindirTipi(0), yukariValfTmr(0), asagiValfTmr(0),
      devirmeYukariIleriTmr(0), devirmeAsagiGeriTmr(0), makineCalismaTmr(0), kapi1AcSure(0), kapi2AcSure(0), kapiTablaAcSure(0),
      buzzer(0), menuGiris(0), demoMode(0), iotMode(0), calismaSayModu(0), dilSecim(0), hataKayit1(0), hataKayit2(0),
      hataKayit3(0), hataKayit4(0), hataKayit5(0), hataKayit6(0), hataKayit7(0), hataKayit8(0), hataKayit9(0), hataKayit10(0),
      hafizaYaz(false), hafizaOku(false), ilkOkuma(false), butonKontrol(false), butonKontrol2(false), butonKontrol3(false),
      butonKontrol4(false), butonKontrol5(false), mesajYazildi(false), yukarimotorcalisiyor(false), devmotoryukaricalisiyor(false),
      devmotorasagicalisiyor(false), asagivalfcalisiyor(false), yukarivalfcalisiyor(false), devyukarivalfcalisiyor(false),
      devasagivalfcalisiyor(false), basgondercalisyukari(false), basgondercalisasagi(false), demoCalismaSayisiYar(false),
      CalismaSayisiYukari(false), CalismaSayisiAsagi(false), calismaSayisiYar(false), makineStop(false), kapi1prudhome(false),
      kapi1butonkontrol(false), kapi1pizzato(false), kapi2prudhome(false), kapi2butonkontrol(false), kapi2pizzato(false),
      kapiTablaprudhome(false), kapiTablabutonkontrol(false), kapiTablapizzato(false), kapiTablaAcKonumKat1(false),
      kapiTablaAcKonumKat2(false), startBasili(false), maksimumcalismahatasi(false), acilstophatasi(false),
      emniyetCercevesihatasi(false), stopVar(false), kapiSivicVar(false), motorcalisiyor(false), hataVar(false),
      makineCalisiyor(false), cerceveVar(false), demoYukariCalis(false), demoAsagiCalis(false), demoDevYukari(false),
      demoDevAsagi(false), kapiactablaesp1(false), kapiactablaesp2(false), basinchatasi(false), katkapisivicihatasi(false),
      tablakapisivicihatasi(false), cercevesasagicalisma(false), HataMakineCalisiyorkapi(false), HataMakineCalisiyortabla(false) {

    // Initialize arrays
    std::fill(std::begin(eepromData), std::end(eepromData), 0);
    std::fill(std::begin(snum), std::end(snum), 0);
    std::fill(std::begin(machineID), std::end(machineID), 0);
    std::fill(std::begin(wifiSSID), std::end(wifiSSID), 0);
    std::fill(std::begin(wifiPass), std::end(wifiPass), 0);
}
