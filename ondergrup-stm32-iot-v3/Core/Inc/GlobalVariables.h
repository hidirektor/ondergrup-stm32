#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

#include <algorithm>
#include <cstdint>
#include <array>

class GlobalVariables {
public:
    static GlobalVariables& getInstance() {
        static GlobalVariables instance;
        return instance;
    }

    // Disallow copy and assignment
    GlobalVariables(const GlobalVariables&) = delete;
    void operator=(const GlobalVariables&) = delete;

    // Member variables
    int setupCompleted;
    int kaydedilenDeger;
    uint32_t millis;
    uint32_t timer;
    uint32_t timer1;
    uint32_t timer2;
    uint32_t timer3;
    uint32_t timer4;
    uint32_t timer5;
    uint32_t timer6;
    uint32_t backLightTimer;
    uint8_t cursorPosition;
    uint8_t page;
    uint8_t idKontrol;
    uint8_t safeVal;
    uint8_t x;
    uint8_t y;
    uint8_t calismaSayisi;
    uint8_t calismaSayisi1;
    uint8_t calismaSayisi10;
    uint8_t calismaSayisi100;
    uint8_t calismaSayisi1000;
    uint8_t calismaSayisi10000;
    uint8_t menuSayac;
    uint8_t durakSayisi;
    uint8_t calismaSekli;
    uint8_t hataGostermeSirasi;
    uint8_t basincVar;
    uint8_t basincVartmr;
    uint8_t emniyetCercevesi;
    uint8_t yavaslamaLimit;
    uint8_t altLimit;
    uint8_t basincSalteri;
    uint8_t kapiSecimleri;
    uint8_t kapi1Tip;
    uint8_t kapi2Tip;
    uint8_t kapitablaTip;
    uint8_t kapiAcTipi;
    uint8_t kapiTablaAcKonum;
    uint8_t yukariYavasLimit;
    uint8_t devirmeYuruyusSecim;
    uint8_t devirmeYukariIleriLimit;
    uint8_t devirmeAsagiGeriLimit;
    uint8_t devirmeSilindirTipi;
    uint8_t platformSilindirTipi;
    uint8_t yukariValfTmr;
    uint8_t asagiValfTmr;
    uint8_t devirmeYukariIleriTmr;
    uint8_t devirmeAsagiGeriTmr;
    uint8_t makineCalismaTmr;
    uint8_t kapi1AcSure;
    uint8_t kapi2AcSure;
    uint8_t kapiTablaAcSure;
    uint8_t buzzer;
    uint8_t menuGiris;
    uint8_t demoMode;
    uint8_t iotMode;
    uint8_t calismaSayModu;
    uint8_t dilSecim;
    uint8_t hataKayit1;
    uint8_t hataKayit2;
    uint8_t hataKayit3;
    uint8_t hataKayit4;
    uint8_t hataKayit5;
    uint8_t hataKayit6;
    uint8_t hataKayit7;
    uint8_t hataKayit8;
    uint8_t hataKayit9;
    uint8_t hataKayit10;

    bool hafizaYaz;
    bool hafizaOku;
    bool ilkOkuma;
    bool butonKontrol;
    bool butonKontrol2;
    bool butonKontrol3;
    bool butonKontrol4;
    bool butonKontrol5;
    bool mesajYazildi;
    bool yukarimotorcalisiyor;
    bool devmotoryukaricalisiyor;
    bool devmotorasagicalisiyor;
    bool asagivalfcalisiyor;
    bool yukarivalfcalisiyor;
    bool devyukarivalfcalisiyor;
    bool devasagivalfcalisiyor;
    bool basgondercalisyukari;
    bool basgondercalisasagi;
    bool demoCalismaSayisiYar;
    bool CalismaSayisiYukari;
    bool CalismaSayisiAsagi;
    bool calismaSayisiYar;
    bool makineStop;
    bool kapi1prudhome;
    bool kapi1butonkontrol;
    bool kapi1pizzato;
    bool kapi2prudhome;
    bool kapi2butonkontrol;
    bool kapi2pizzato;
    bool kapiTablaprudhome;
    bool kapiTablabutonkontrol;
    bool kapiTablapizzato;
    bool kapiTablaAcKonumKat1;
    bool kapiTablaAcKonumKat2;
    bool startBasili;
    bool maksimumcalismahatasi;
    bool acilstophatasi;
    bool emniyetCercevesihatasi;
    bool stopVar;
    bool kapiSivicVar;
    bool motorcalisiyor;
    bool hataVar;
    bool makineCalisiyor;
    bool cerceveVar;
    bool demoYukariCalis;
    bool demoAsagiCalis;
    bool demoDevYukari;
    bool demoDevAsagi;
    bool kapiactablaesp1;
    bool kapiactablaesp2;
    bool basinchatasi;
    bool katkapisivicihatasi;
    bool tablakapisivicihatasi;
    bool cercevesasagicalisma;
    bool HataMakineCalisiyorkapi;
    bool HataMakineCalisiyortabla;

    std::array<uint8_t, 110> eepromData;
    std::array<char, 4> snum;
    std::array<char, 12> machineID;
    std::array<char, 20> wifiSSID;
    std::array<char, 20> wifiPass;

private:
    GlobalVariables();
};

#endif /* GLOBALVARIABLES_H_ */

