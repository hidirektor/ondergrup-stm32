/*
 * requestHeaders.c
 *
 *  Created on: Aug 10, 2024
 *      Author: hidirektor
 */
#include "requestHeaders.h"
#include "GlobalVariables.h"

// JSON verisini oluşturma fonksiyonu
void createMachineDataJson(char *json_data, size_t size, const char *machineID, const char *wifiSSID, const char *wifiPass) {
    snprintf(json_data, size,
             "{\"machineID\":\"%s\","
             "\"updateData\":{"
             "\"wifiSSID\":\"%s\","
             "\"wifiPass\":\"%s\","
             "\"devirmeYuruyusSecim\":\"%d\","
             "\"calismaSekli\":\"%d\","
             "\"emniyetCercevesi\":\"%d\","
             "\"yavaslamaLimit\":\"%d\","
             "\"altLimit\":\"%d\","
             "\"kapiTablaAcKonum\":\"%d\","
             "\"basincSalteri\":\"%d\","
             "\"kapiSecimleri\":\"%d\","
             "\"kapiAcTipi\":\"%d\","
             "\"kapi1Tip\":\"%d\","
             "\"kapi1AcSure\":\"%d\","
             "\"kapi2Tip\":\"%d\","
             "\"kapi2AcSure\":\"%d\","
             "\"kapitablaTip\":\"%d\","
             "\"kapiTablaAcSure\":\"%d\","
             "\"yukariYavasLimit\":\"%d\","
             "\"devirmeYukariIleriLimit\":\"%d\","
             "\"devirmeAsagiGeriLimit\":\"%d\","
             "\"devirmeSilindirTipi\":\"%d\","
             "\"platformSilindirTipi\":\"%d\","
             "\"yukariValfTmr\":\"%d\","
             "\"asagiValfTmr\":\"%d\","
             "\"devirmeYukariIleriTmr\":\"%d\","
             "\"devirmeAsagiGeriTmr\":\"%d\","
             "\"makineCalismaTmr\":\"%d\","
             "\"buzzer\":\"%d\","
             "\"demoMode\":\"%d\","
             "\"calismaSayisi\":\"%d\","
             "\"calismaSayisiDemo\":\"%d\","
             "\"dilSecim\":\"%d\","
             "\"eepromData38\":\"%d\","
             "\"eepromData39\":\"%d\","
             "\"eepromData40\":\"%d\","
             "\"eepromData41\":\"%d\","
             "\"eepromData42\":\"%d\","
             "\"eepromData43\":\"%d\","
             "\"eepromData44\":\"%d\","
             "\"eepromData45\":\"%d\","
             "\"eepromData46\":\"%d\","
             "\"eepromData47\":\"%d\","
             "\"lcdBacklightSure\":\"%d\""
             "}}",
             machineID, wifiSSID, wifiPass, devirmeYuruyusSecim, calismaSekli, emniyetCercevesi, yavaslamaLimit, altLimit,
             kapiTablaAcKonum, basincSalteri, kapiSecimleri, kapiAcTipi, kapi1Tip, kapi1AcSure, kapi2Tip, kapi2AcSure,
             kapitablaTip, kapiTablaAcSure, yukariYavasLimit, devirmeYukariIleriLimit, devirmeAsagiGeriLimit,
             devirmeSilindirTipi, platformSilindirTipi, yukariValfTmr, asagiValfTmr, devirmeYukariIleriTmr,
             devirmeAsagiGeriTmr, makineCalismaTmr, buzzer, demoMode, calismaSayisi, calismaSayisiDemo, dilSecim,
             eepromData[38], eepromData[39], eepromData[40], eepromData[41], eepromData[42], eepromData[43], eepromData[44], eepromData[45],
             eepromData[46], eepromData[47], lcdBacklightSure);
}
