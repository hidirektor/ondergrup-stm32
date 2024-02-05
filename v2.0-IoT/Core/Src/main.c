/* USER CODE BEGIN Header */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include <Data.h>
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ESP8266.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
CAN_HandleTypeDef hcan;
I2C_HandleTypeDef hi2c1;
TIM_HandleTypeDef htim1;
UART_HandleTypeDef huart1;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

//Tüm fonksiyonlar:

void lcdUpdate(uint8_t y) {
	if(y==1) {
		lcd_print(2, 1, " ");
	} else if(y==2) {
		lcd_print(2, 2, " ");
	} else if(y==3) {
		lcd_print(2, 3, " ");
	} else if(y==4) {
		lcd_print(2, 4, " ");
	} else if(y==5) {
		lcd_print(2, 5, " ");
	} else if(y==6) {
		lcd_print(2, 6, " ");
	} else if (y==7) {
		lcd_clear();
		lcd_print(1, 4, "ESP-RMK");
		lcd_print(2, 6, "RUN");
	}
}

void hataKoduLcdGoster(uint8_t x) {
	if(x==1) {
		if(dilSecim==0) {
			lcd_print(1, 1, "   HATA KODU");
		} else if(dilSecim==1) {
			lcd_print(1, 1, "   ERROR CODE");
		}
		lcd_print(2, 1, "1");
		lcd_print(2, 7, "          ");
	} else if(x==2){
		if(dilSecim==0){
			lcd_print(1, 1, "   HATA KODU");
		} else if(dilSecim==1) {
			lcd_print(1, 1, "   ERROR CODE");
		}
		lcd_print(2, 2, "2");
		lcd_print(2, 7, "          ");
	} else if(x==3) {
		if(dilSecim==0) {
			lcd_print(1, 1, "   HATA KODU");
		} else if(dilSecim==1) {
			lcd_print(1, 1, "   ERROR CODE");
		}
		lcd_print(2, 3, "3");
		lcd_print(2, 7, "          ");
	} else if(x==4){
		if(dilSecim==0) {
			lcd_print(1, 1, "   HATA KODU");
		} else if(dilSecim==1) {
			lcd_print(1, 1, "   ERROR CODE");
		}
		lcd_print(2, 4, "4");
		lcd_print(2, 7, "          ");
	} else if(x==5) {
		if(dilSecim==0) {
			lcd_print(1, 1, "   HATA KODU");
		} else if(dilSecim==1) {
			lcd_print(1, 1, "   ERROR CODE");
		}
		lcd_print(2, 5, "5");
		lcd_print(2, 7, "          ");
	} else if(x==6) {
		if(dilSecim==0) {
			lcd_print(1, 1, "   HATA KODU");
		} else if(dilSecim==1) {
			lcd_print(1, 1, "   ERROR CODE");
		}
		lcd_print(2, 6, "6");
		lcd_print(2, 7, "          ");
	}
}

char* mergeData() {
	char combinedString[45] = "";
	char temp[10];

	uint8_t uintVariables[] = {
			devirmeYuruyusSecim,
			calismaSekli,
			emniyetCercevesi,
			yavaslamaLimit,
			altLimit,
			kapiTablaAcKonum,
			basincSalteri,
			kapiSecimleri,
			kapiAcTipi,
			kapi1Tip,
			kapi1AcSure,
			kapi2Tip,
			kapi2AcSure,
			kapitablaTip,
			kapiTablaAcSure,
			yukariYavasLimit,
			devirmeYukariIleriLimit,
			devirmeAsagiGeriLimit,
			devirmeSilindirTipi,
			platformSilindirTipi,
			yukariValfTmr,
			asagiValfTmr,
			devirmeYukariIleriTmr,
			devirmeAsagiGeriTmr,
			makineCalismaTmr,
			buzzer,
			demoMode,
			calismaSayisi1,
			calismaSayisi10,
			calismaSayisi100,
			calismaSayisi1000,
			calismaSayisi10000,
			dilSecim,
			eepromData[37],
			eepromData[38],
			eepromData[39],
			eepromData[40],
			eepromData[41],
			eepromData[42],
			eepromData[43],
			eepromData[44],
			eepromData[45],
			eepromData[46],
			eepromData[47],
			lcdBacklightSure
	};

	for (int i = 0; i < sizeof(uintVariables) / sizeof(uintVariables[0]); ++i) {
	    sprintf(temp, "%u", uintVariables[i]);
	    strcat(combinedString, temp);
	}

	char* result = malloc(strlen(combinedString) + 1);
	strcpy(result, combinedString);
	return result;
}

void convertAndSendData() {
	lcd_print(1, 1, "Veri Esleme");
	lcd_print(2, 1, "Baslatildi...");
	for(int i=0; i<2; i++) {
		sendMachineData(&huart1, machineID, mergeData());
	}
	HAL_Delay(500);
	lcd_clear();
	HAL_Delay(500);
}

void eepromKontrol(int type) {
	HAL_I2C_Mem_Read(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
	HAL_Delay(1500);

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
	calismaSayisi1 = eepromData[28];
	calismaSayisi10 = eepromData[29];
	calismaSayisi100 = eepromData[30];
	calismaSayisi1000 = eepromData[31];
	calismaSayisi10000 = eepromData[32];
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

	if(calismaSayisi10000>9) {
	    calismaSayisi10000=0;
	}

	if(calismaSayisi1000>9) {
	    calismaSayisi1000=0;
	}

	if(calismaSayisi100>9) {
	    calismaSayisi100=0;
	}

	if(calismaSayisi10>9) {
	    calismaSayisi10=0;
	}

	if(calismaSayisi1>9) {
	    calismaSayisi1=0;
	}

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

	memcpy(machineID, &eepromData[idStartPos], 12);
	HAL_Delay(250);
	readFromEEPROM(1);
	HAL_Delay(250);
	readFromEEPROM(2);
}

void hata2EEPROM(uint8_t hataKodu) {
	if(eepromData[eepromHataBaslangic+(indeksSayisi-1)] != 0) {
		eepromDataFillWithEmpty();
		goto veriEkleme;
	} else {
		veriEkleme:
			for(int i=0; i<indeksSayisi; i++) {
				if(eepromData[eepromHataBaslangic+i] == 0) {
					eepromData[eepromHataBaslangic+i] = hataKodu;
					break;
				}
			}
	}

	HAL_I2C_Mem_Write(&hi2c1, 0xA0, eepromHataBaslangic, indeksSayisi, &eepromData[eepromHataBaslangic], indeksSayisi, 3000);
	HAL_Delay(500);
	eepromKontrol(1);
}

void eepromDataFillWithEmpty(void) {
	for(int i=0; i<indeksSayisi; i++) {
		eepromData[eepromVal[i]] = 0;
	}
}

uint8_t buttonCheck(void) {
	if((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin) == 1)
			|| (HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port,butonGeriIn_Pin) == 1)
			|| (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1)
			|| (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1)
			|| (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1)) {
		backLightTimer = 0;
		return 1;
	}
	return 0;
}

void bekle() {
	timer1=millis;
    while((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin) == 1) && (millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port,butonGeriIn_Pin) == 1) && (millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin) == 1) && (millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin) == 1) && (millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin) == 1) && (millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port,kapi1AcButonIn_Pin) == 0) && (millis-timer1<1)){
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port,kapi2AcButonIn_Pin) == 0) && (millis-timer1<1)){
    	butonKontrol = 1;
    }

    while((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port,kapiTablaAcButonIn_Pin) == 0) && (millis-timer1<1)){
    	butonKontrol = 1;
    }

}

void i2cTest() {
	GPIO_InitTypeDef strutturaGPIO = {0};

	hi2c1.Instance->CR1 &= ~(1 << 0);
	HAL_I2C_DeInit(&hi2c1);

	strutturaGPIO.Pin = GPIO_PIN_6|GPIO_PIN_7;
	strutturaGPIO.Mode = GPIO_MODE_OUTPUT_OD;
	strutturaGPIO.Pull = GPIO_PULLUP;
	strutturaGPIO.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOB, &strutturaGPIO);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);

    //lcd_print(1,1," test-1         ");
    //lcd_print(2,1,"SCL and SDL LOW ");
    HAL_Delay(10);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) != GPIO_PIN_SET && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) != GPIO_PIN_SET){

	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
  //  lcd_print(1,1," test-2         ");
  //  lcd_print(2,1,"SCL and SDL HIGH");
    HAL_Delay(10);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_SET){

	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
  //  lcd_print(1,1," test-3         ");
  //  lcd_print(2,1,"SCL   ----- HIGH");
    HAL_Delay(10);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == GPIO_PIN_SET){

	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
  //  lcd_print(1,1," test-4         ");
 //   lcd_print(2,1,"SCL   ----- HIGH");
    HAL_Delay(10);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) != GPIO_PIN_SET){

	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
   // lcd_print(1,1," test-5         ");
   // lcd_print(2,1,"SCL   ----- HIGH");
    HAL_Delay(10);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) != GPIO_PIN_SET){

	}

	strutturaGPIO.Pin = GPIO_PIN_6|GPIO_PIN_7;
	strutturaGPIO.Mode = GPIO_MODE_AF_OD;
	strutturaGPIO.Pull = GPIO_PULLUP;
	strutturaGPIO.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOB, &strutturaGPIO);

	hi2c1.Instance->CR1 |= 1 << 15;

	hi2c1.Instance->CR1 &= ~(1 << 15);

	hi2c1.Instance->CR1 |= 1 << 0;

	HAL_I2C_Init(&hi2c1);
}

void checkLCDBacklight() {
	if(millis - backLightTimer >= lcdBacklightSure*10) {
		lcd_backlight(0);
	} else {
		lcd_backlight(1);
	}
}

void checkBasincSalteri() {
	if(basincSalteri==0) {
		basincVar=1;
	}

	if(basincSalteri==1) {
		if(HAL_GPIO_ReadPin(basincSalteriIn_GPIO_Port, basincSalteriIn_Pin)==0) {
			if(millis-timer5>=3) {
				basincVar=1;
			}
		} else {
			timer5=millis;
			basincVar=0;
		}
	}
}

void checkBasGonder() {
	if((calismaSekli==1)&&(yukarimotorcalisiyor==1)&&(devirmeYuruyusSecim==0)) {
		basgondercalisyukari=1;
	} else if(yukarimotorcalisiyor==0) {
		basgondercalisyukari=0;
	}

	if((calismaSekli==1)&&(asagivalfcalisiyor==1)&&(devirmeYuruyusSecim==0)) {
		basgondercalisasagi=1;
	} else if(asagivalfcalisiyor==0) {
		basgondercalisasagi=0;
	}
}

void checkKapiSecimleri() {
	if(kapiSecimleri==0) {
		kapiSivicVar=1;
	}

	if(kapiSecimleri==1) {
		if(HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==0) {
			kapiSivicVar=1;
		} else {
			kapiSivicVar=0;
		}
	}

	if(kapiSecimleri==2){
		if(HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==0) {
			kapiSivicVar=1;
		} else {
			kapiSivicVar=0;
		}
	}

	if(kapiSecimleri==3) {
		if((HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==0)&&(HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==0)) {
			kapiSivicVar=1;
		} else {
			kapiSivicVar=0;
		}
	}
}

void checkAktifCalisma() {
	if(demoMode==0 && menuGiris==0) {
		if(((yukarimotorcalisiyor)||(devmotoryukaricalisiyor)||((asagivalfcalisiyor)&&(butonKontrol2==0)&&(platformSilindirTipi==1))||((devmotorasagicalisiyor)&&(devirmeSilindirTipi)==1))&&(stopVar)&&(kapiSivicVar)) {
			HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_SET);
			motorcalisiyor=1;
			CalismaSayisiYukari=1;
		} else {
			HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
			motorcalisiyor=0;
		}

		/*YUKARI ÇALISMA*/

		if((menuGiris==0) && (stopVar) && (kapiSivicVar)																		/********* motor calısması ***********/
				&& ((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0)||(basgondercalisyukari))
				&& (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
				&& (basincVar)
				&& (((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==1))||(yukarimotorcalisiyor))
				&& (asagivalfcalisiyor==0)
				&& (devmotoryukaricalisiyor==0)
				&& (devmotorasagicalisiyor==0)
				&&(devyukarivalfcalisiyor==0)
				&&(devasagivalfcalisiyor==0)) {
			yukarimotorcalisiyor=1;
		} else {
			yukarimotorcalisiyor=0;
		}

		if((yukarimotorcalisiyor==1)&&(((HAL_GPIO_ReadPin(yukariYavaslamaLimitIn_GPIO_Port, yukariYavaslamaLimitIn_Pin)==1))&&(yukariYavasLimit))) {	/* ikinci hız */
			HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
		}

		if(yukarimotorcalisiyor && (devirmeYuruyusSecim==1 || devirmeYuruyusSecim==2 || platformSilindirTipi==1)) {
			HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_SET);
			yukarivalfcalisiyor=1;
		}

		// yukari valf timer calisması

		if((yukarivalfcalisiyor==1)&&(((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1)&&(basgondercalisyukari==0))||(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1))&&(stopVar)&&(kapiSivicVar)&&(basincVar)&&(butonKontrol3==0)) {
			timer2=millis;
			butonKontrol3=1;
		}

		if((((millis-timer2 >= yukariValfTmr)&&(butonKontrol3==1))||((stopVar==0)||(kapiSivicVar==0)||(basincVar==0)))) {
			HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
			yukarivalfcalisiyor=0;
			butonKontrol3=0;
		}

		//Ond safety

		if(emniyetCercevesi==0) {
			cerceveVar=1;
		}

		if((emniyetCercevesi==1)&&(calismaSekli==0)&&(HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin)==0)&&(HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0)) {
			cerceveVar=1;
		} else if((emniyetCercevesi==1)&&(HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin)==1)&&(calismaSekli==0)) {
			cerceveVar=0;
		}

		if (emniyetCercevesi==1 && calismaSekli==1) {
			if(HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin)==0) {
				cerceveVar=1;
			} else {
				cerceveVar=0;
			}
		}

		//Asagi calisma
		if((menuGiris==0)&& (stopVar)&& (kapiSivicVar)
				&& ((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0)||(basgondercalisasagi))
				&& (cerceveVar)&&(emniyetCercevesihatasi==0)
				&& ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)||!(altLimit))
				&& (((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==1))||(asagivalfcalisiyor))
				&& (yukarimotorcalisiyor==0)
				&& (yukarivalfcalisiyor==0)
		  	  	&& (devmotoryukaricalisiyor==0)
				&& (devmotorasagicalisiyor==0)
				&& (devyukarivalfcalisiyor==0)
				&& (devasagivalfcalisiyor==0)) {
			HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_SET);
			asagivalfcalisiyor=1;
			CalismaSayisiAsagi=1;
			cercevesasagicalisma=1;
		}

		// asagi valf timer calisması

		if((asagivalfcalisiyor==1)&&(((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==1)&&(basgondercalisasagi==0))||((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)&&(altLimit)))&&(stopVar)&&(kapiSivicVar)&&(cerceveVar)&&(butonKontrol2==0)) {
			timer2=millis;
			butonKontrol2=1;
		}

		if((((millis-timer2 >= asagiValfTmr)&&(butonKontrol2==1))||((stopVar==0)||(kapiSivicVar==0)||(cerceveVar==0)))) {
			HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
			asagivalfcalisiyor=0;
			butonKontrol2=0;
		}

		//yavaslama valf

		if((asagivalfcalisiyor==1)&&(((HAL_GPIO_ReadPin(yavaslamaLimitIn_GPIO_Port, yavaslamaLimitIn_Pin)==0))&&(yavaslamaLimit))) {	/* ikinci hız */
			HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
		}

		/*DEVIRME veya YURUYUS Baslangic*/

		// Devirme Yukari veya yuruyus ileri calisma
		if((menuGiris==0)
				&& ((devirmeYuruyusSecim==1)||(devirmeYuruyusSecim==2))
				&& (stopVar) && (kapiSivicVar)
				&& (HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==0)
				&& ((HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==0)||!(devirmeYukariIleriLimit))
				&& (((HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==1))||(devmotoryukaricalisiyor))
				&& (yukarimotorcalisiyor==0)
				&& (yukarivalfcalisiyor==0)
				&& (asagivalfcalisiyor==0)
				&& (devmotorasagicalisiyor==0)
				&&(devasagivalfcalisiyor==0)) {
			devmotoryukaricalisiyor=1;
		} else {
			devmotoryukaricalisiyor=0;
		}

		if(devmotoryukaricalisiyor==1) {
			HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_SET);
			devyukarivalfcalisiyor=1;
		}
		// devirme yukari + yuruyus ileri valf timer calismasi

		if((devyukarivalfcalisiyor==1)&&((HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==1)||(HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==1))&&(stopVar)&&(kapiSivicVar)&&(butonKontrol4==0)) {
			timer2=millis;
			butonKontrol4=1;
		}

		if((((millis-timer2 >= devirmeYukariIleriTmr)&&(butonKontrol4==1))||((stopVar==0)||(kapiSivicVar==0)))) {
			HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
			devyukarivalfcalisiyor=0;
			butonKontrol4=0;
		}

		// Devirme Asagi veya yuruyus geri calisma

		if((menuGiris==0)
				&& ((devirmeYuruyusSecim==1)||(devirmeYuruyusSecim==2))
				&& (stopVar) && (kapiSivicVar)
				&& (HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==0)
				&& ((HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin)==0)||!(devirmeAsagiGeriLimit))
				&& (((HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==1))||(devmotorasagicalisiyor))
				&& (yukarimotorcalisiyor==0)
				&& (yukarivalfcalisiyor==0)
				&& (asagivalfcalisiyor==0)
				&& (devyukarivalfcalisiyor==0)
				&& (devmotoryukaricalisiyor==0)) {
			devmotorasagicalisiyor=1;
		} else {
			devmotorasagicalisiyor=0;
		}

		if(devmotorasagicalisiyor==1) {
			HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_SET);
			devasagivalfcalisiyor=1;
		}

		//devirme asagi + geri valf timer calismasi

		if((devasagivalfcalisiyor==1)&&((HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==1)||(HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin)==1))&&(stopVar)&&(kapiSivicVar)&&(butonKontrol5==0)) {
			timer2=millis;
			butonKontrol5=1;
		}

		if((((millis-timer2 >= devirmeYukariIleriTmr)&&(butonKontrol5==1))||((stopVar==0)||(kapiSivicVar==0)))) {
			HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
			devasagivalfcalisiyor=0;
			butonKontrol5=0;
		}

		// makine durum kontrolü

		if(HAL_GPIO_ReadPin(motorOut_GPIO_Port, motorOut_Pin)==0
				&&(HAL_GPIO_ReadPin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin)==0)
				&&(HAL_GPIO_ReadPin(yukariValfOut_GPIO_Port, yukariValfOut_Pin)==0)
				&&(HAL_GPIO_ReadPin(asagiValfOut_GPIO_Port, asagiValfOut_Pin)==0)
				&&(HAL_GPIO_ReadPin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin)==0)) {
			makineStop=1;
		} else {
			makineStop=0;
		}

		//kapi 1 kontrol

		// kapi 1 prudhome
		if((kapi1Tip==0)&&((kapiSecimleri==1)||(kapiSecimleri==3))
				&&((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0 && (kapiAcTipi==1)))
				&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
				&&(butonKontrol==0)
				&&(makineStop==1)) {
			kapi1prudhome=1;
			timer = millis;
			bekle();
		}

		if((millis-timer >= kapi1AcSure)||((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)||!(altLimit))||(makineStop==0)) {
			kapi1prudhome=0;
		}

		// kapi 1 buton kontrol

		if((kapi1Tip==1)&&((kapiSecimleri==1)||(kapiSecimleri==3))

				&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
				&&((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0 && (kapiAcTipi==1)))
				&&(makineStop==1)) {
			kapi1butonkontrol=1;
		} else {
			kapi1butonkontrol=0;
		}

		// kapi 1 pizzato

		if((kapi1Tip==2)&&((kapiSecimleri==1)||(kapiSecimleri==3))

				&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
				&&(makineStop==1)) {
			kapi1pizzato=1;
		} else {
			kapi1pizzato=0;
		}

		// kapi 1 çıkış

		if(kapi1butonkontrol==1 || kapi1pizzato==1 || kapi1prudhome==1) {
			HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
		}

		//kapi2 kontrol

		// kapi 2 prudhome

		if((kapi2Tip==0)&&((kapiSecimleri==1)||(kapiSecimleri==3))
				&&((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0 && (kapiAcTipi==1)))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
				&&(makineStop==1)
				&&(butonKontrol==0)) {
			kapi2prudhome=1;
			timer = millis;
			bekle();
		}

		if((millis-timer >= kapi2AcSure) || (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)||(makineStop==0)) {
			kapi2prudhome=0;
		}

		// kapi 2 buton kontrol

		if((kapi2Tip==1)&&((kapiSecimleri==1)||(kapiSecimleri==3))

				&&((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0 && (kapiAcTipi==1)))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
				&&(makineStop==1)) {
			kapi2butonkontrol=1;
		} else {
			kapi2butonkontrol=0;
		}

		// kapi 2 pizzato

		if((kapi2Tip==2)&&((kapiSecimleri==1)||(kapiSecimleri==3))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
				&&(makineStop==1)) {
			kapi2pizzato=1;
		} else {
			kapi2pizzato=0;
		}

		// kapi 2 çıkış

		if(kapi2butonkontrol==1 || kapi2pizzato==1 || kapi2prudhome==1) {
			HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
		}

		//   kapi tabla kontrol ***

		if((kapiTablaAcKonum==0 || kapiTablaAcKonum==2)
				&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
				&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)) {
			kapiTablaAcKonumKat1=1;
		} else {
			kapiTablaAcKonumKat1=0;
		}

		if((kapiTablaAcKonum==1 || kapiTablaAcKonum==2)
				&& (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)) {
			kapiTablaAcKonumKat2=1;
		} else {
			kapiTablaAcKonumKat2=0;
		}

		if(kapiTablaAcKonumKat1==1
				&& kapiAcTipi==1
				&& HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0) {
			kapiactablaesp1=1;
		} else {
			kapiactablaesp1=0;
		}

		if(kapiTablaAcKonumKat2==1
				&& kapiAcTipi==1
				&& HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0) {
			kapiactablaesp2=1;
		} else {
			kapiactablaesp2=0;
		}

		// tabla kapısı prudhome

		if((kapitablaTip==0)&&((kapiSecimleri==2)||(kapiSecimleri==3))
				&&((kapiTablaAcKonumKat1==1)||(kapiTablaAcKonumKat2==1))
				&&(((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin)==0)&&(kapiAcTipi==0))
				||(kapiactablaesp1)==1 || (kapiactablaesp2)==1)
				&&(makineStop==1)
				&&(butonKontrol==0)) {

			kapiTablaprudhome=1;
			timer = millis;
			bekle();
		}

		if((millis-timer >= kapiTablaAcSure)||((kapiTablaAcKonumKat1==0)&&(kapiTablaAcKonumKat2==0))||(makineStop==0)) {
			kapiTablaprudhome=0;
		}

		// tabla kapı buton kontrol

		if((kapitablaTip==1)&&((kapiSecimleri==2)||(kapiSecimleri==3))

				&&((kapiTablaAcKonumKat1==1)||(kapiTablaAcKonumKat2==1))
				&&(((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin)==0)&&(kapiAcTipi==0))
				||(kapiactablaesp1)==1 || (kapiactablaesp2)==1)
				&&(makineStop==1)) {
			kapiTablabutonkontrol=1;
		} else {
			kapiTablabutonkontrol=0;
		}

		// tabla kapı pizzato

		if((kapitablaTip==2)&&((kapiSecimleri==2)||(kapiSecimleri==3))
				&&((kapiTablaAcKonumKat1==1)||(kapiTablaAcKonumKat2==1))
				&&(makineStop==1)) {
			kapiTablapizzato=1;
		} else { /* if((kapitablaTip==1)&&((kapiSecimleri==2)||(kapiSecimleri==3))) */
			kapiTablapizzato=0;
		}

		// kapi Tabla çıkış

		if(kapiTablabutonkontrol==1 || kapiTablaprudhome==1 || kapiTablapizzato==1) {
			HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
		}

		/********************************* CALİSMA SAYISI KAYIT YERİ *************************************/

		if(((CalismaSayisiYukari==1)&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)&&(altLimit==0)&&(makineStop==1))
				||((CalismaSayisiAsagi==1)&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)&&(altLimit))&&(makineStop==1))) {
			calismaSayisi1=calismaSayisi1+1;
			if(calismaSayisi1>9) {
			  	calismaSayisi1=0;
			  	calismaSayisi10=calismaSayisi10+1;
			}
			if(calismaSayisi10>9) {
			  	calismaSayisi10=0;
			  	calismaSayisi100=calismaSayisi100+1;
			}
			if(calismaSayisi100>9) {
			  	calismaSayisi100=0;
			  	calismaSayisi1000=calismaSayisi1000+1;
			}
			if(calismaSayisi1000>9) {
			  	calismaSayisi1000=0;
			  	calismaSayisi10000=calismaSayisi10000+1;
			}
			eepromData[32]=calismaSayisi10000;
			eepromData[31]=calismaSayisi1000;
			eepromData[30]=calismaSayisi100;
			eepromData[29]=calismaSayisi10;
			eepromData[28]=calismaSayisi1;

			hafizaYaz=1;

			CalismaSayisiYukari=0;
			CalismaSayisiAsagi=0;

		}

		/******************************************* HATA BASLIYOR *******************************************/

		/************************************ ACİL STOP HATA BASLANGICI **************************************************/
		if((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0
			  	||HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0
			  	||HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==0
			  	||HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==0)) {
			startBasili=1;
		} else {
			startBasili=0;
		}


		if(startBasili && HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin)==1) {
			hataVar=1;
			hataKoduLcdGoster(1);
			hata2EEPROM(1);
			convertAndSendData();
			acilstophatasi=1;
		} else if(acilstophatasi && HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin)==0 && startBasili==0) {
			acilstophatasi=0;
			lcdUpdate(1);
		}

		/************************************ Emniyet Çerçevesi Hatasi ***************************************************/

		if(cerceveVar==0 && (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0 || cercevesasagicalisma)&& (emniyetCercevesi==1)) {
			hataVar=1;
			hataKoduLcdGoster(2);
			hata2EEPROM(2);
			convertAndSendData();
			emniyetCercevesihatasi=1;
		} else if(emniyetCercevesihatasi && cerceveVar==1 && asagivalfcalisiyor==0) {
			emniyetCercevesihatasi=0;
			cercevesasagicalisma=0;
			lcdUpdate(2);
		}

		/************************************ BASINC ASIRI YUK HATASI **************************************************/

		if(basincVar==0 && basincSalteri==1 && motorcalisiyor==1 && HAL_GPIO_ReadPin(basincSalteriIn_GPIO_Port, basincSalteriIn_Pin)==1) {
			hataVar=1;
			hataKoduLcdGoster(3);
			hata2EEPROM(3);
			convertAndSendData();
			basinchatasi=1;
		} else if(basinchatasi && basincVar==1 && HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1) {
			basinchatasi=0;
			lcdUpdate(3);
		}

		/************************************ KAPI SİVİÇ HATASI **************************************************/
		if((startBasili || HataMakineCalisiyorkapi) && HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==1 && (kapiSecimleri==1 || kapiSecimleri==3)) {
			hataVar=1;
			hataKoduLcdGoster(4);
			hata2EEPROM(4);
			convertAndSendData();
			katkapisivicihatasi=1;
		} else if (katkapisivicihatasi && makineStop && startBasili==0 && HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==0) {
			katkapisivicihatasi=0;
			HataMakineCalisiyorkapi=0;
			lcdUpdate(4);
		}

		/************************************ TABLA KAPI SİVİÇ HATASI **************************************************/

		if((startBasili || HataMakineCalisiyortabla)&& HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==1 && (kapiSecimleri==1 || kapiSecimleri==3)) {
			hataVar=1;
			hataKoduLcdGoster(5);
			hata2EEPROM(5);
			convertAndSendData();
			tablakapisivicihatasi=1;
		} else if (tablakapisivicihatasi && makineStop && startBasili==0 && HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==0 && makineStop==1) {
			tablakapisivicihatasi=0;
			HataMakineCalisiyortabla=0;
			lcdUpdate(5);
		}

		/************************************ MAX CALİSMA HATASI BASLANGIC ******************************************/

		if((motorcalisiyor)||(asagivalfcalisiyor)||(devmotorasagicalisiyor)) {
		    if(millis-timer4>=makineCalismaTmr) {
			  	hataVar=1;
			  	hataKoduLcdGoster(6);
			  	hata2EEPROM(6);
			  	convertAndSendData();
			  	maksimumcalismahatasi=1;
			  }
		}

		if(maksimumcalismahatasi && HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) && startBasili==0) {
			maksimumcalismahatasi=0;
			lcdUpdate(6);
		}

		if((yukarimotorcalisiyor==1)||(asagivalfcalisiyor==1)||(devmotoryukaricalisiyor==1)||(devmotorasagicalisiyor==1)) {
			makineCalisiyor=0;
			HataMakineCalisiyorkapi=1;
			HataMakineCalisiyortabla=1;
		} else {
			makineCalisiyor=1;
			timer4=millis;
		}

		/*********************************** HATA YOKSA HATA VAR SIFIRLA **************************************************/
		if(hataVar==1 && acilstophatasi==0 && emniyetCercevesihatasi==0 && basinchatasi==0
				&& katkapisivicihatasi==0 && tablakapisivicihatasi==0 && maksimumcalismahatasi==0) {
			hataVar=0;
			lcdUpdate(7);
		}


		/************************************ HATA LCD GÖSTERME ************************************************************/
	} 		// aktif calisma son parantez.
}

void checkDemoModCalisma() {
	if((demoMode==1)&&(stopVar)&&(menuGiris==0)) {

		if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
				&& (demoAsagiCalis==0)
				&& (demoDevYukari==0)
				&& (demoDevAsagi==0)) {

			HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_SET);
			demoYukariCalis=1;
		} else if(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1) {

			HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
			demoYukariCalis=0;
		}

		// DEMO MOTOR CALISMASI

		if((demoYukariCalis)||(demoDevYukari)||(demoDevAsagi)||(demoAsagiCalis)) {
			HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
		}

		if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&& (HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==0)
				&& (demoYukariCalis==0)
				&& (demoAsagiCalis==0)) {
			//bos burası
		}

		//DEVİRME YUKARI CALIS
		if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==0)
				&&(demoYukariCalis==0)
				&&(demoAsagiCalis==0)
				&& (demoDevAsagi==0)) {

			HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_SET);
			demoDevYukari=1;
		} else {
			HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
			demoDevYukari=0;
		}

		// DEVIRME ASAGI CALIS

		if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
				&&(HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin)==0)
				&&(demoYukariCalis==0)
				&&(demoDevYukari==0)
				&& (demoAsagiCalis==0)) {

			HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_SET);
			demoDevAsagi=1;
		} else {
			HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
			demoDevAsagi=0;
		}

		// DEMO ASAGI CALISMA

		if((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
				&& (demoYukariCalis==0)
				&& (demoDevAsagi==0)
				&& (demoDevYukari==0)) {

			HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_SET);
			demoAsagiCalis=1;
			demoCalismaSayisiYar=1;
		} else if ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)) {
			HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
			demoAsagiCalis=0;
		}

		if(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1) {
			HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
			timer3 = millis;
		}

		if(millis-timer3 >= 5) {
			HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
		}

		if(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1) {
			HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
			timer3 = millis;
		}

		if(millis-timer3 >= 5) {
			HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
		}

		if((demoYukariCalis==1) && (demoCalismaSayisiYar==1)) {
			//mesajYazildi=0;
			calismaSayisi1=calismaSayisi1+1;

			if(calismaSayisi1>9) {
				calismaSayisi1=0;
				calismaSayisi10=calismaSayisi10+1;
			}

			if(calismaSayisi10>9) {
				calismaSayisi10=0;
				calismaSayisi100=calismaSayisi100+1;
			}

			if(calismaSayisi100>9) {
				calismaSayisi100=0;
				calismaSayisi1000=calismaSayisi1000+1;
			}

			if(calismaSayisi1000>9) {
				calismaSayisi1000=0;
				calismaSayisi10000=calismaSayisi10000+1;
			}
			eepromData[32]=calismaSayisi10000;
			eepromData[31]=calismaSayisi1000;
			eepromData[30]=calismaSayisi100;
			eepromData[29]=calismaSayisi10;
			eepromData[28]=calismaSayisi1;
			hafizaYaz=1;
		 		//mesajYazildi=0;
			demoCalismaSayisiYar=0;
		}

		if (menuGiris==0) {
			lcd_print(2,1,"Cycle      ");
			lcd_print(1,1, "    DEMO MODE   ");
			itoa(calismaSayisi10000, snum, 10);
			lcd_print(2,12,snum);
			itoa(calismaSayisi1000, snum, 10);
			lcd_print(2,13,snum);
			itoa(calismaSayisi100, snum, 10);
			lcd_print(2,14,snum);
			itoa(calismaSayisi10, snum, 10);
			lcd_print(2,15,snum);
			itoa(calismaSayisi1, snum, 10);
			lcd_print(2,16,snum);
			mesajYazildi=1;
		}
	} else if(demoMode==1 || menuGiris==1) {
		HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
		//HAL_GPIO_WritePin(buzzerOut_GPIO_Port, buzzerOut_Pin, GPIO_PIN_RESET);
	}
}

void mainLoop() {
	while(1) {
		checkLCDBacklight();

		if((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port,butonGeriIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==0)&&(HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin)==1)&&(HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin)==1)&&(HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin)==1)) {
			butonKontrol=0;
		} else {
			backLightTimer = millis;
		}

		if(hafizaYaz==1) {
		  while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
		  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);

		  HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, 110, eepromData, 110, 3000);
		  HAL_Delay(500);

		  hafizaYaz=0;
		  if(dilSecim==0) {
			  lcd_print(2,1,"Data yazildi    ");
		  } else if(dilSecim==1) {
			  lcd_print(2,1,"Data Wrote      ");
		  }

		  HAL_Delay(1000);
		  lcd_clear();
		}

		if((hafizaOku==0)&&(HAL_I2C_GetState(&hi2c1) == HAL_I2C_STATE_READY)) {
		  if(ilkOkuma==0) {
			  lcd_print(1,1,"   **EEPROM**   ");
			  if(dilSecim==0) {
				  lcd_print(2,1,"Data Okunuyor...");
			  } else if(dilSecim==1) {
				  lcd_print(2,1,"Data Reading... ");
			  }
			  HAL_Delay(1000);

			  while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
			  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY) {
				  HAL_Delay(1000);
			  }

			  if(dilSecim==0) {
				  lcd_print(2,1,"Data Okundu.    ");
			  } else if(dilSecim==1) {
				  lcd_print(2,1,"Data Read.      ");
			  }

			  ilkOkuma=1;
		  } else {
			  if(dilSecim==0) {
				  lcd_print(2,1,"Deger Kaydedildi");
			  } else if(dilSecim==1) {
				  lcd_print(2,1,"Value Saved     ");
			  }
			  lcd_clear();
		  }

		  lcd_clear();

		  eepromKontrol(1);
		  hafizaOku=1;
		}

		if((menuGiris==0)&&(mesajYazildi==0)&&(demoMode==0)) {
			lcd_clear();
			HAL_Delay(10);
			lcd_print(1, 1, "    ESP-RMK     ");
			lcd_print(2, 1, "      RUN       ");
			mesajYazildi=1;
		}

		if ((menuGiris==0) && (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)) {
			menuGiris=1;
			lcd_clear();
		}

		if(menuGiris==1) {
			menu();
		}

		HAL_GPIO_TogglePin(cycleLed_GPIO_Port, cycleLed_Pin);

		/* GİRİLEN PARAMETRELERE GÖRE AYARLARIN YAPILMASI*/

		if(HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin)==0 && hataVar==0) {
			stopVar=1;
		} else {
			stopVar=0;
		}

		/****************************************  BASINC SALTERI ********************************************/
		checkBasincSalteri();

		/******** Bas gönder ***********/
		checkBasGonder();

		/******** Kapı Secimleri ***********/
		checkKapiSecimleri();

		/* PARAMETRELERE GÖRE ÇIKISLARIN AYARLANMASI*/
		/*MOTOR CALISIYOR*/
		checkAktifCalisma();

		// DEMO MOD BASLIYOR
		// DEMO YUKARI CALISMA
		checkDemoModCalisma();
	}
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) { /*------timer kesmesinde islem yapmak için */
	millis=millis+1;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  HAL_Delay(500);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
  HAL_Delay(10);
  lcd_init();
  HAL_Delay(10);
  HAL_TIM_Base_Start_IT(&htim1);
  while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);

  HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(buzzerOut_GPIO_Port, buzzerOut_Pin, GPIO_PIN_RESET);

  i2cTest();
  HAL_Delay(100);
  lcd_print(1,1,"     RMK-V1     ");
  lcd_print(2,1,"ONDTECH ESP CONT");
  HAL_Delay(1000);
  lcd_clear();

  eepromKontrol(0);
  HAL_Delay(200);

  lcd_clear();
  HAL_Delay(200);

  backLightTimer = millis;

  /*if(iotMode != 0) {
	  if(machineID[11] == '\0') {
		  takeMachineID(0);
	  }

	  if(wifiSSID[0] != '\0') {
		  takeWifiSSID(0);
	  }

	  if(wifiPass[0] != '\0') {
		  takeWifiPass(0);
	  }
  }*/

  ESP8266_Init(&huart1, "iPhone", "ipek123456");
  HAL_Delay(250);
  convertAndSendData();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  mainLoop();
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */
  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */
  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 16;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_1TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */
  /* USER CODE END CAN_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */
  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */
  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */
  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 35999;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 1999;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, buzzerOut_Pin|tablaKapiOut_Pin|kapi2Out_Pin|kapi1Out_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, devirmeAsagiGeriOut_Pin|devirmeYukariIleriOut_Pin|cycleLed_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, yavaslamaValfOut_Pin|asagiValfOut_Pin|yukariValfOut_Pin|motorIkinciHizOut_Pin
                          |motorOut_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : yukariYavaslamaLimitIn_Pin yavaslamaLimitIn_Pin basincSalteriIn_Pin emniyetCercevesiIn_Pin
                           ustLimitIn_Pin altLimitIn_Pin butonGeriIn_Pin devAsagiStartIn_Pin
                           kapi1AcButonIn_Pin kapi2AcButonIn_Pin kapiTablaAcButonIn_Pin devirmeYukariLimitIn_Pin
                           devirmeAsagiLimitIn_Pin */
  GPIO_InitStruct.Pin = yukariYavaslamaLimitIn_Pin|yavaslamaLimitIn_Pin|basincSalteriIn_Pin|emniyetCercevesiIn_Pin
                          |ustLimitIn_Pin|altLimitIn_Pin|butonGeriIn_Pin|devAsagiStartIn_Pin
                          |kapi1AcButonIn_Pin|kapi2AcButonIn_Pin|kapiTablaAcButonIn_Pin|devirmeYukariLimitIn_Pin
                          |devirmeAsagiLimitIn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : butonIleriIn_Pin butonYukariIn_Pin butonAsagiIn_Pin butonEnterIn_Pin
                           tablaKapiSiviciIn_Pin kapiSiviciIn_Pin */
  GPIO_InitStruct.Pin = butonIleriIn_Pin|butonYukariIn_Pin|butonAsagiIn_Pin|butonEnterIn_Pin
                          |tablaKapiSiviciIn_Pin|kapiSiviciIn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : buzzerOut_Pin tablaKapiOut_Pin kapi2Out_Pin kapi1Out_Pin */
  GPIO_InitStruct.Pin = buzzerOut_Pin|tablaKapiOut_Pin|kapi2Out_Pin|kapi1Out_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : devirmeAsagiGeriOut_Pin devirmeYukariIleriOut_Pin cycleLed_Pin */
  GPIO_InitStruct.Pin = devirmeAsagiGeriOut_Pin|devirmeYukariIleriOut_Pin|cycleLed_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : yavaslamaValfOut_Pin asagiValfOut_Pin yukariValfOut_Pin motorIkinciHizOut_Pin
                           motorOut_Pin */
  GPIO_InitStruct.Pin = yavaslamaValfOut_Pin|asagiValfOut_Pin|yukariValfOut_Pin|motorIkinciHizOut_Pin
                          |motorOut_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : acilStop1In_Pin yukariStartIn_Pin asagiStartIn_Pin devYukariStartIn_Pin */
  GPIO_InitStruct.Pin = acilStop1In_Pin|yukariStartIn_Pin|asagiStartIn_Pin|devYukariStartIn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
