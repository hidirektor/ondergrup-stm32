/*
 * EEPROMProcess.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


#include "EEPROMProcess.h"
#include "Instance.h"
#include "main.h"

#include <cstdint>

EEPROMProcess& EEPROMProcess::getInstance() {
    static EEPROMProcess instance;
    return instance;
}

EEPROMProcess::EEPROMProcess() {}

void EEPROMProcess::eepromKontrol() {
    HAL_I2C_Mem_Read(&hi2c1, 0xA0, 0, 110, globalVars.eepromData.data(), 110, 3000);
    HAL_Delay(1500);

    globalVars.kaydedilenDeger = globalVars.eepromData[3];
    globalVars.calismaSekli = globalVars.eepromData[1];
    globalVars.emniyetCercevesi = globalVars.eepromData[2];
    globalVars.yavaslamaLimit = globalVars.eepromData[4];
    globalVars.altLimit = globalVars.eepromData[5];
    globalVars.basincSalteri = globalVars.eepromData[6];
    globalVars.kapiSecimleri = globalVars.eepromData[7];
    globalVars.kapi1Tip = globalVars.eepromData[8];
    globalVars.kapi1AcSure = globalVars.eepromData[9];
    globalVars.kapi2Tip = globalVars.eepromData[10];
    globalVars.kapi2AcSure = globalVars.eepromData[11];
    globalVars.kapitablaTip = globalVars.eepromData[12];
    globalVars.kapiTablaAcSure = globalVars.eepromData[13];
    globalVars.yukariYavasLimit = globalVars.eepromData[14];
    globalVars.devirmeYuruyusSecim = globalVars.eepromData[15];
    globalVars.devirmeYukariIleriLimit = globalVars.eepromData[16];
    globalVars.devirmeAsagiGeriLimit = globalVars.eepromData[17];
    globalVars.devirmeSilindirTipi = globalVars.eepromData[18];
    globalVars.platformSilindirTipi = globalVars.eepromData[19];
    globalVars.yukariValfTmr = globalVars.eepromData[20];
    globalVars.asagiValfTmr = globalVars.eepromData[21];
    globalVars.devirmeYukariIleriTmr = globalVars.eepromData[22];
    globalVars.devirmeAsagiGeriTmr = globalVars.eepromData[23];
    globalVars.makineCalismaTmr = globalVars.eepromData[24];
    globalVars.buzzer = globalVars.eepromData[25];
    globalVars.demoMode = globalVars.eepromData[26];
    globalVars.calismaSayisi = globalVars.eepromData[27];
    globalVars.calismaSayisi1 = globalVars.eepromData[28];
    globalVars.calismaSayisi10 = globalVars.eepromData[29];
    globalVars.calismaSayisi100 = globalVars.eepromData[30];
    globalVars.calismaSayisi1000 = globalVars.eepromData[31];
    globalVars.calismaSayisi10000 = globalVars.eepromData[32];
    globalVars.dilSecim = globalVars.eepromData[33];
    globalVars.iotMode = globalVars.eepromData[48];
    globalVars.kapiTablaAcKonum = globalVars.eepromData[34];
    globalVars.calismaSayModu = globalVars.eepromData[35];
    globalVars.kapiAcTipi = globalVars.eepromData[36];
    globalVars.hataKayit1 = globalVars.eepromData[38];
    globalVars.hataKayit2 = globalVars.eepromData[39];
    globalVars.hataKayit3 = globalVars.eepromData[40];
    globalVars.hataKayit4 = globalVars.eepromData[41];
    globalVars.hataKayit5 = globalVars.eepromData[42];
    globalVars.hataKayit6 = globalVars.eepromData[43];
    globalVars.hataKayit7 = globalVars.eepromData[44];
    globalVars.hataKayit8 = globalVars.eepromData[45];
    globalVars.hataKayit9 = globalVars.eepromData[46];
    globalVars.hataKayit10 = globalVars.eepromData[47];

    globalVars.setupCompleted = globalVars.eepromData[104];

    if (globalVars.calismaSayisi10000 > 9) globalVars.calismaSayisi10000 = 0;
    if (globalVars.calismaSayisi1000 > 9) globalVars.calismaSayisi1000 = 0;
    if (globalVars.calismaSayisi100 > 9) globalVars.calismaSayisi100 = 0;
    if (globalVars.calismaSayisi10 > 9) globalVars.calismaSayisi10 = 0;
    if (globalVars.calismaSayisi1 > 9) globalVars.calismaSayisi1 = 0;
    if (globalVars.calismaSekli > 1) globalVars.calismaSekli = 0;
    if (globalVars.emniyetCercevesi > 1) globalVars.emniyetCercevesi = 1;
    if (globalVars.yavaslamaLimit > 1) globalVars.yavaslamaLimit = 0;
    if (globalVars.altLimit > 1) globalVars.altLimit = 1;
    if (globalVars.basincSalteri > 1) globalVars.basincSalteri = 1;
    if (globalVars.kapiSecimleri > 3) globalVars.kapiSecimleri = 3;
    if (globalVars.kapiAcTipi > 1) globalVars.kapiAcTipi = 0;
    if (globalVars.kapi1Tip > 2) globalVars.kapi1Tip = 1;
    if (globalVars.kapi1AcSure > 5) globalVars.kapi1AcSure = 5;
    if (globalVars.kapi2Tip > 2) globalVars.kapi2Tip = 1;
    if (globalVars.kapi2AcSure > 5) globalVars.kapi2AcSure = 5;
    if (globalVars.kapitablaTip > 2) globalVars.kapitablaTip = 1;
    if (globalVars.kapiTablaAcKonum > 2) globalVars.kapiTablaAcKonum = 2;
    if (globalVars.kapiTablaAcSure > 5) globalVars.kapiTablaAcSure = 5;
    if (globalVars.yukariYavasLimit > 1) globalVars.yukariYavasLimit = 0;
    if (globalVars.devirmeYuruyusSecim > 2) globalVars.devirmeYuruyusSecim = 0;
    if (globalVars.devirmeYukariIleriLimit > 1) globalVars.devirmeYukariIleriLimit = 1;
    if (globalVars.devirmeAsagiGeriLimit > 1) globalVars.devirmeAsagiGeriLimit = 1;
    if (globalVars.devirmeSilindirTipi > 1) globalVars.devirmeSilindirTipi = 0;
    if (globalVars.platformSilindirTipi > 1) globalVars.platformSilindirTipi = 0;
    if (globalVars.yukariValfTmr > 5) globalVars.yukariValfTmr = 0;
    if (globalVars.asagiValfTmr > 5) globalVars.asagiValfTmr = 0;
    if (globalVars.devirmeYukariIleriTmr > 5) globalVars.devirmeYukariIleriTmr = 0;
    if (globalVars.devirmeAsagiGeriTmr > 5) globalVars.devirmeAsagiGeriTmr = 0;
    if (globalVars.makineCalismaTmr > 180) globalVars.makineCalismaTmr = 60;
    if (globalVars.buzzer > 1) globalVars.buzzer = 0;
    if (globalVars.demoMode > 1) globalVars.demoMode = 0;
    if (globalVars.calismaSayModu > 1) globalVars.calismaSayModu = 0;
    if (globalVars.dilSecim > 1) globalVars.dilSecim = 0;
    if (globalVars.iotMode > 1) globalVars.iotMode = 0;

    convertArrays(1);
    HAL_Delay(250);

    convertArrays(2);
    HAL_Delay(250);

    convertArrays(3);
    HAL_Delay(250);

    textVars.loadMenuTexts(globalVars.dilSecim);
}

void EEPROMProcess::firstSetup() {
    if (globalVars.eepromData[0] == 0xFF) {
        memset(globalVars.eepromData.data(), 0, 110);

        HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, globalVars.eepromData.data(), 110, 3000);
        HAL_Delay(1000);

        lcd.print(1, 1, "LUTFEN  KURULUMU");
        lcd.print(2, 1, "   TAMAMLAYIN   ");
        HAL_Delay(500);
        lcd.clear();
    }
}

void EEPROMProcess::convertArrays(int state) {
    if (state == 1) {
        int eepromVal = systemDefaults.idStartPos;
        int characterPos;

        for (int i = 0; i < systemDefaults.machineIDCharacterLimit; i++) {
            characterPos = globalVars.eepromData[eepromVal];
            globalVars.machineID[i] = systemDefaults.idCharactersArray[characterPos];
            eepromVal++;
        }
    } else if (state == 2) {
        int eepromVal = systemDefaults.ssidStartPos;

        for (int i = 0; i < systemDefaults.wifiCharacterLimit; i++) {
            if (globalVars.eepromData[eepromVal] != 0) {
                globalVars.wifiSSID[i] = systemDefaults.charactersArray[globalVars.eepromData[eepromVal]];
                eepromVal++;
            }
        }
    } else {
        int eepromVal = systemDefaults.passStartPos;

        for (int i = 0; i < systemDefaults.wifiCharacterLimit; i++) {
            if (globalVars.eepromData[eepromVal] != 0) {
                globalVars.wifiPass[i] = systemDefaults.charactersArray[globalVars.eepromData[eepromVal]];
                eepromVal++;
            }
        }
    }
}
