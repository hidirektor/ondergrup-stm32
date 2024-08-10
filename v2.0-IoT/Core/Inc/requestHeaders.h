/*
 * requestHeaders.h
 *
 *  Created on: Aug 10, 2024
 *      Author: hidirektor
 */

#ifndef INC_REQUESTHEADERS_H_
#define INC_REQUESTHEADERS_H_

#include <stdio.h>

void createMachineDataJson(char *json_data, size_t size, const char *machineID, const char *wifiSSID, const char *wifiPass);

// Sunucu Adresleri ve Portlar
#define MAIN_SERVER           "http://ondergrup.hidirektor.com.tr"
#define MAIN_SERVER_WITH_PORT "http://ondergrup.hidirektor.com.tr:3000"

// URL Şablonları
#define URL_UPDATE_MACHINE_RAW        "GET /api/v2/machine/updateMachineRaw?machineID=%s&wifiSSID=%s&wifiPass=%s&devirmeYuruyusSecim=%d&calismaSekli=%d&emniyetCercevesi=%d&yavaslamaLimit=%d&altLimit=%d&kapiTablaAcKonum=%d&basincSalteri=%d&kapiSecimleri=%d&kapiAcTipi=%d&kapi1Tip=%d&kapi1AcSure=%d&kapi2Tip=%d&kapi2AcSure=%d&kapitablaTip=%d&kapiTablaAcSure=%d&yukariYavasLimit=%d&devirmeYukariIleriLimit=%d&devirmeAsagiGeriLimit=%d&devirmeSilindirTipi=%d&platformSilindirTipi=%d&yukariValfTmr=%d&asagiValfTmr=%d&devirmeYukariIleriTmr=%d&devirmeAsagiGeriTmr=%d&makineCalismaTmr=%d&buzzer=%d&demoMode=%d&calismaSayisi=%d&calismaSayisiDemo=%d&dilSecim=%d&eepromData38=%d&eepromData39=%d&eepromData40=%d&eepromData41=%d&eepromData42=%d&eepromData43=%d&eepromData44=%d&eepromData45=%d&eepromData46=%d&eepromData47=%d&lcdBacklightSure=%d HTTP/1.0\r\nHost: %s\r\n\r\n"
#define URL_CHECK_MACHINE_ID          "GET /api/v2/machine/checkMachineIDRaw?machineID=%s HTTP/1.0\r\nHost: %s\r\n\r\n"
#define URL_CHECK_UPDATES             "GET /api/v2/updateChecker/checkUpdatesRaw?currentVersion=%s HTTP/1.0\r\nHost: %s\r\n\r\n"
#define URL_DOWNLOAD_NEW_VERSION      "GET /api/v2/updateChecker/downloadNewVersionRaw?versionCode=%s HTTP/1.0\r\nHost: %s\r\n\r\n"

// JSON Body Şablonu
#define JSON_UPDATE_MACHINE_DATA      "{\"machineID\":\"%s\",\"updateData\":{\"wifiSSID\":\"%s\",\"wifiPass\":\"%s\",\"devirmeYuruyusSecim\":\"%d\",\"calismaSekli\":\"%d\",\"emniyetCercevesi\":\"%d\",\"yavaslamaLimit\":\"%d\",\"altLimit\":\"%d\",\"kapiTablaAcKonum\":\"%d\",\"basincSalteri\":\"%d\",\"kapiSecimleri\":\"%d\",\"kapiAcTipi\":\"%d\",\"kapi1Tip\":\"%d\",\"kapi1AcSure\":\"%d\",\"kapi2Tip\":\"%d\",\"kapi2AcSure\":\"%d\",\"kapitablaTip\":\"%d\",\"kapiTablaAcSure\":\"%d\",\"yukariYavasLimit\":\"%d\",\"devirmeYukariIleriLimit\":\"%d\",\"devirmeAsagiGeriLimit\":\"%d\",\"devirmeSilindirTipi\":\"%d\",\"platformSilindirTipi\":\"%d\",\"yukariValfTmr\":\"%d\",\"asagiValfTmr\":\"%d\",\"devirmeYukariIleriTmr\":\"%d\",\"devirmeAsagiGeriTmr\":\"%d\",\"makineCalismaTmr\":\"%d\",\"buzzer\":\"%d\",\"demoMode\":\"%d\",\"calismaSayisi\":\"%d\",\"calismaSayisiDemo\":\"%d\",\"dilSecim\":\"%d\",\"eepromData38\":\"%d\",\"eepromData39\":\"%d\",\"eepromData40\":\"%d\",\"eepromData41\":\"%d\",\"eepromData42\":\"%d\",\"eepromData43\":\"%d\",\"eepromData44\":\"%d\",\"eepromData45\":\"%d\",\"eepromData46\":\"%d\",\"eepromData47\":\"%d\",\"lcdBacklightSure\":\"%d\"}}"


#endif /* INC_REQUESTHEADERS_H_ */
