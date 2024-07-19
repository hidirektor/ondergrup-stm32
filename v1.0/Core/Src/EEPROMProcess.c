/*
 * EEPROMProcess.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "EEPROMProcess.h"
#include "main.h"
#include "GlobalVariables.h"
#include "i2c-lcd.h"
#include "TextVariables.h"

void eepromKontrol() {
	HAL_I2C_Mem_Read(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
	HAL_Delay(1500);

	//Sürekli sıfırlama işlemi yapıyor
	//firstSetup();

	kaydedilenDeger = eepromData[3];
	calismaSekli = eepromData[1];
	emniyetCercevesi = eepromData[2];
	yavaslamaLimit = eepromData[4];
	altLimit = eepromData[5];
	basincSalteri = eepromData[6];
	kapiSecimleri = eepromData[7];
	kapi1Tip = eepromData[8];
	kapi1AcSure = eepromData[9];
	kapi2Tip = eepromData[10];
	kapi2AcSure = eepromData[11];
	kapitablaTip = eepromData[12];
	kapiTablaAcSure = eepromData[13];
	yukariYavasLimit = eepromData[14];
	devirmeYuruyusSecim = eepromData[15];
	devirmeYukariIleriLimit = eepromData[16];
	devirmeAsagiGeriLimit = eepromData[17];
	devirmeSilindirTipi = eepromData[18];
	platformSilindirTipi = eepromData[19];
	yukariValfTmr = eepromData[20];
	asagiValfTmr = eepromData[21];
	devirmeYukariIleriTmr = eepromData[22];
	devirmeAsagiGeriTmr = eepromData[23];
	makineCalismaTmr = eepromData[24];
	buzzer = eepromData[25];
	demoMode = eepromData[26];
	calismaSayisi = eepromData[27];
	calismaSayisiDemo = eepromData[28];
	dilSecim = eepromData[33];
	iotMode = eepromData[48];
	kapiTablaAcKonum = eepromData[34];
	calismaSayModu = eepromData[35];
	kapiAcTipi = eepromData[36];
	hataKayit1 = eepromData[38];
	hataKayit2 = eepromData[39];
	hataKayit3 = eepromData[40];
	hataKayit4 = eepromData[41];
	hataKayit5 = eepromData[42];
	hataKayit6 = eepromData[43];
	hataKayit7 = eepromData[44];
	hataKayit8 = eepromData[45];
	hataKayit9 = eepromData[46];
	hataKayit10 = eepromData[47];

	/*if(acilStop1>0) {
		acilStop1=0;
	}*/

	if(calismaSekli>1) {
	    calismaSekli=0;
	}

	if(emniyetCercevesi>1) {
	    emniyetCercevesi=1;
	}

	if(yavaslamaLimit>1) {
	    yavaslamaLimit=0;
	}

	if(altLimit>1) {
	    altLimit=1;
	}

	if(basincSalteri>1) {
	    basincSalteri=1;
	}

	if(kapiSecimleri>3) {
	    kapiSecimleri=3;
	}

	if(kapiAcTipi>1) {
	    kapiAcTipi=0;
	}

	if(kapi1Tip>2) {
	    kapi1Tip=1;
	}

	if(kapi1AcSure>5) {
	    kapi1AcSure=5;
	}

	if(kapi2Tip>2) {
	    kapi2Tip=1;
	}

	if(kapi2AcSure>5) {
	    kapi2AcSure=5;
	}

	if(kapitablaTip>2) {
	    kapitablaTip=1;
	}

	if(kapiTablaAcKonum>2) {
	    kapiTablaAcKonum=2;
	}

	if(kapiTablaAcSure>5) {
	    kapiTablaAcSure=5;
	}

	if(yukariYavasLimit>1) {
	    yukariYavasLimit=0;
	}

	if(devirmeYuruyusSecim>2) {
	    devirmeYuruyusSecim=0;
	}

	if(devirmeYukariIleriLimit>1) {
	    devirmeYukariIleriLimit=1;
	}

	if(devirmeAsagiGeriLimit>1) {
	    devirmeAsagiGeriLimit=1;
	}

	if(devirmeSilindirTipi>1) {
	    devirmeSilindirTipi=0;
	}

	if(platformSilindirTipi>1) {
	    platformSilindirTipi=0;
	}

	if(yukariValfTmr>5) {
	    yukariValfTmr=0;
	}

	if(asagiValfTmr>5) {
	    asagiValfTmr=0;
	}

	if(devirmeYukariIleriTmr>5) {
	    devirmeYukariIleriTmr=0;
	}

	if(devirmeAsagiGeriTmr>5) {
	    devirmeAsagiGeriTmr=0;
	}

	if(makineCalismaTmr>180) {
	    makineCalismaTmr=60;
	}

	if(buzzer>1) {
	    buzzer=0;
	}

	if(demoMode>1) {
	    demoMode=0;
	}

	if(calismaSayModu>1) {
	    calismaSayModu=0;
	}

	if(dilSecim>1) {
	    dilSecim=0;
	}

	if(iotMode>1) {
		iotMode=0;
	}

	loadMenuTexts(dilSecim);
}

void firstSetup() {
	//EEPROM ilk kez takıldıysa standart sistem verilerini yükle:
	if (eepromData[0] == 0xFF) {
		memset(eepromData, 0, 110);

		//Default değerleri eeproma kaydet:
		HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
		HAL_Delay(1000);

		lcd_print(1, 1, "LUTFEN  KURULUMU");
		lcd_print(2, 1, "   TAMAMLAYIN   ");
		HAL_Delay(500);
		lcd_clear();
	}
}
