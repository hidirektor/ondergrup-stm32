/* USER CODE BEGIN Header */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <i2c-lcd.h>
#include "Translate.h"

void bekle(void);
void menu(void);
void i2cTest(void);
void hataKoduLcdGoster(uint8_t);
void lcdupdate(uint8_t);
void run_delay(void);
void eepromKontrol(void);
void hata2EEPROM(uint8_t);
void hataSifirla(void);
void loadMenuTexts(int);
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint8_t eepromData[63];
uint8_t kaydedilenDeger=0;
char snum[5];
unsigned long millis=0;
unsigned long timer=0;
unsigned long timer1=0;
unsigned long timer2=0;
unsigned long timer3=0;
unsigned long timer4=0;				// maksimum calisma kayit suresi
unsigned long timer5=0;				// basinc kayit suresi
unsigned long timer6=0;				// lcd update suresi
int eepromVal[] = {37, 38, 39, 40, 41, 42, 43, 44, 45, 46};
int eepromFull[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int indeksSayisi = sizeof(eepromVal)/sizeof(eepromVal[0]);
int eepromHataBaslangic = 37;
uint8_t x=0;
uint8_t y=0;
uint8_t calismaSayisi=0;
uint8_t calismaSayisi1=0;
uint8_t calismaSayisi10=0;
uint8_t calismaSayisi100=2;
uint8_t calismaSayisi1000=1;
uint8_t calismaSayisi10000=0;
uint8_t menuSayac=0;
uint8_t durakSayisi=0;
uint8_t calismaSekli=0;
uint8_t hataGostermeSirasi=0;
uint8_t basincVar=0;
uint8_t basincVartmr=0;
uint8_t emniyetCercevesi=0;
uint8_t yavaslamaLimit=0;
uint8_t altLimit=0;
uint8_t basincSalteri=0;
uint8_t kapiSecimleri=0;
uint8_t kapi1Tip=0;
uint8_t kapi2Tip=0;
uint8_t kapitablaTip=0;
uint8_t kapiAcTipi=0;
uint8_t kapiTablaAcKonum=0;
uint8_t yukariYavasLimit=0;
uint8_t devirmeYuruyusSecim=0;
uint8_t devirmeYukariIleriLimit=0;
uint8_t devirmeAsagiGeriLimit=0;
uint8_t devirmeSilindirTipi=0;
uint8_t platformSilindirTipi=0;
uint8_t yukariValfTmr=0;
uint8_t asagiValfTmr=0;
uint8_t devirmeYukariIleriTmr=0;
uint8_t devirmeAsagiGeriTmr=0;
uint8_t makineCalismaTmr=0;
uint8_t kapi1AcSure=0;
uint8_t kapi2AcSure=0;
uint8_t kapiTablaAcSure=0;
uint8_t buzzer=0;
uint8_t menuGiris=0;
uint8_t demoMode=0;
uint8_t calismaSayModu=0;
uint8_t dilSecim=0;
uint8_t hataKayit1=0;
uint8_t hataKayit2=0;
uint8_t hataKayit3=0;
uint8_t hataKayit4=0;
uint8_t hataKayit5=0;
uint8_t hataKayit6=0;
uint8_t hataKayit7=0;
uint8_t hataKayit8=0;
uint8_t hataKayit9=0;
uint8_t hataKayit10=0;
bool hafizaYaz=0;
bool hafizaOku=0;
bool ilkOkuma=0;
bool butonKontrol=0;
bool butonKontrol2=0;
bool butonKontrol3=0;
bool butonKontrol4=0;
bool butonKontrol5=0;
bool mesajYazildi=0;
bool yukarimotorcalisiyor=0;
bool devmotoryukaricalisiyor=0;
bool devmotorasagicalisiyor=0;
bool asagivalfcalisiyor=0;
bool yukarivalfcalisiyor=0;
bool devyukarivalfcalisiyor=0;
bool devasagivalfcalisiyor=0;
bool basgondercalisyukari=0;
bool basgondercalisasagi=0;
bool demoCalismaSayisiYar=0;
bool CalismaSayisiYukari=0;
bool CalismaSayisiAsagi=0;
bool calismaSayisiYar=0;
bool makineStop=0;
bool kapi1prudhome=0; bool kapi1butonkontrol=0; bool kapi1pizzato=0;
bool kapi2prudhome=0; bool kapi2butonkontrol=0; bool kapi2pizzato=0;
bool kapiTablaprudhome=0; bool kapiTablabutonkontrol=0; bool kapiTablapizzato=0;
bool kapiTablaAcKonumKat1=0; bool kapiTablaAcKonumKat2=0;
bool startBasili=0;
bool maksimumcalismahatasi=0;
bool acilstophatasi=0;
bool emniyetCercevesihatasi=0;
bool stopVar=0;
bool kapiSivicVar=0;
bool motorcalisiyor=0;
bool hataVar=0;
bool makineCalisiyor=0;
bool cerceveVar=0;
bool demoYukariCalis=0;
bool demoAsagiCalis=0;
bool demoDevYukari=0;
bool demoDevAsagi=0;
bool kapiactablaesp1=0;
bool kapiactablaesp2=0;
bool basinchatasi=0;
bool katkapisivicihatasi=0;
bool tablakapisivicihatasi=0;
bool cercevesasagicalisma=0;
bool HataMakineCalisiyorkapi=0;
bool HataMakineCalisiyortabla=0;

//Menü için text değişkenleri
char mainText[16];
char mainText2[16];
char menuyeGirildiText[16];
char ayarlarText[16];
char hataKayitListText[16];
char birHataKoduText[16];
char ikiHataKoduText[16];
char ucHataKoduText[16];
char dortHataKoduText[16];
char besHataKoduText[16];
char altiHataKoduText[16];
char yediHataKoduText[16];
char sekizHataKoduText[16];
char dokuzHataKoduText[16];
char onHataKoduText[16];
char silmekIcinText[16];
char calismaSekliText[16];
char devirmeYuruyusText[16];
char bastikcaCalisanText[16];
char basGonderText[16];
char emniyetCercevesiText[16];
char pasifText[16];
char aktifText[16];
char ondSafetyText[16];
char yavaslamaLimitText[16];
char altLimitText[16];
char basincSalteriText[16];
char kapiSecimleriText[16];
char katKapisiAktifText[16];
char tablaKapiAktifText[16];
char katArtiTablaAktifText[16];
char kapiAcmaTipiText[16];
char kapiButonuESPText[16];
char katButonuEXTText[16];
char birKatKapiTipiText[16];
char prudhomeText[16];
char butonKontrolluText[16];
char pizzattoText[16];
char birinciKapiAcSuresiText[16];
char kacSaniyeText[16];
char ikinciKatKapiTipiText[16];
char ikinciKapiAcSuresiText[16];
char tablaKapiTipiText[16];
char tablaKapiAcKonumText[16];
char birinciKattaAcText[16];
char ikinciKattaAcText[16];
char birVeIkinciKattaAcText[16];
char tablaKapiAcSureText[16];
char yukariYavaslamaLimitiText[16];
char devirmeYuruyusMenuText[16];
char devirmeAktifText[16];
char yuruyusAktifText[16];
char devirmeYukariText[16];
char yuruyusIleriText[16];
char devirmeAsagiSivicText[16];
char yuruyusGeriSivicText[16];
char yuruyusSecildiText[16];
char devirmeSilindirTipiText[16];
char tekTesirText[16];
char ciftTesirText[16];
char platformSilindirTipiText[16];
char asagiValfSureText[16];
char devirmeYukariValfSureText[16];
char ileriValfSureText[16];
char devirmeAsagiValfSureText[16];
char geriValfSureText[16];
char calismaSuresiText[16];
char buzzerText[16];
char demoModText[16];
char calismaSayisiText[16];
char enterlaSifirlaText[16];
char dilSecimText[16];
char secilenDilText[16];
char menudenCikisText[16];
char enteraBasinizText[16];
char hataKoduText[16];

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan;

I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART1_UART_Init(void);
void StartDefaultTask(void const * argument);
void wifiTask(void *pvParameters);
void ledTask(void *pvParameters);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void menu(void)     //--------------------------------------------------------menuye girdik
{
	if ((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin)==1)&&(butonKontrol==0)){
		menuSayac=menuSayac+1;
		if (menuSayac==32){    //MENÜ BÜYÜDÜKÇE DE ?İ ?TİR
			menuSayac=1;
		}

		if((menuSayac==18)&&(devirmeYuruyusSecim==0)){
			menuSayac=21;
		}

		if((menuSayac==8)&&(kapiSecimleri==0)){
			menuSayac=16;
		}
		if ((menuSayac==13)&&(kapiSecimleri==1)){			// kapi kat sivici aktif ise tabla kapı hariç ayarlar gösterilir.
			menuSayac=16;
		}
		if((menuSayac==9)&&(kapiSecimleri==2)){			// tabla aktif ise kat harici kapılar gösterilir.
			menuSayac=13;
		}

		if((menuSayac==10)&&((kapi1Tip==1)||(kapi1Tip==2))){
			menuSayac=11;
		}

		if((menuSayac==12)&&((kapi2Tip==1)||(kapi2Tip==2))&&(kapiSecimleri==1)){
			menuSayac=16;
		}
		if((menuSayac==12)&&((kapi2Tip==1)||(kapi2Tip==2))&&(kapiSecimleri==3)){
			menuSayac=13;
		}

		if((menuSayac==15)&&(kapitablaTip==1)){
			menuSayac=16;
		}

		if((menuSayac==24)&&(devirmeYuruyusSecim==0)){
			menuSayac=26;
		}

		bekle();
	}

	if ((HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port,butonGeriIn_Pin)==1)&&(butonKontrol==0)){
		if (menuSayac<=1){
			menuSayac=32;     //MENÜ BÜYÜDÜKÇE DE ?İ ?TİR
		}

		menuSayac=menuSayac-1;
		if((menuSayac==20)&&(devirmeYuruyusSecim==0)){
			menuSayac=17;
		}

		if((menuSayac==15)&&(kapiSecimleri==0)){
			menuSayac=7;
		}

		if((menuSayac==15)&&(kapiSecimleri==1)){
			menuSayac=12;
		}

		if((menuSayac==12)&&(kapiSecimleri==2)){
			menuSayac=8;
		}

		if((menuSayac==10)&&((kapi1Tip==1)||(kapi1Tip==2))){
			menuSayac=9;
		}

		if((menuSayac==12)&&((kapi2Tip==1)||(kapi2Tip==2))){
			menuSayac=11;
		}

		if((menuSayac==15)&&(kapitablaTip==1)){
			menuSayac=14;
		}

		if((menuSayac==25)&&(devirmeYuruyusSecim==0)){
			menuSayac=23;
		}

		bekle();
	}

	if (menuSayac==0){
		if(dilSecim==0){
			lcd_print(1,1,"MENUYE  GiRDiNiZ");
			lcd_print(2,1,"    AYARLAR     ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"ENTERED THE MENU");
			lcd_print(2,1,"    SETTINGS    ");
		}
		}

	if (menuSayac==1){
		if(dilSecim==0){
			lcd_print(1,1,"HATA KAYIT LiST.");
		}
		if(dilSecim==1){
			lcd_print(1,1,"ERROR SAVE LiST.");
		}

		if(hataGostermeSirasi==0){
			if(dilSecim==0){
			lcd_print(2,1,"1.Hata Kodu:");
			lcd_print(2,14,"   ");
			itoa(hataKayit1, snum, 10);
			lcd_print(2,13,snum);
			}
			if(dilSecim==1){
			lcd_print(2,1,"1.Error Code:");
			lcd_print(2,15,"  ");
		    itoa(hataKayit1, snum, 10);
		    lcd_print(2,14,snum);
			}
		}
		if(hataGostermeSirasi==1){
			if(dilSecim==0){
			lcd_print(2,1,"2.Hata Kodu:");
			lcd_print(2,14,"   ");
			itoa(hataKayit2, snum, 10);
			lcd_print(2,13,snum);
			}
			if(dilSecim==1){
			lcd_print(2,1,"2.Error Code:");
			lcd_print(2,15,"  ");
		    itoa(hataKayit2, snum, 10);
		    lcd_print(2,14,snum);
			}
		}
		if(hataGostermeSirasi==2){
			if(dilSecim==0){
			lcd_print(2,1,"3.Hata Kodu:");
			lcd_print(2,14,"   ");
			itoa(hataKayit3, snum, 10);
			lcd_print(2,13,snum);
			}
			if(dilSecim==1){
			lcd_print(2,1,"3.Error Code:");
			lcd_print(2,15,"  ");
		    itoa(hataKayit3, snum, 10);
		    lcd_print(2,14,snum);
			}
		}
		if(hataGostermeSirasi==3){
			if(dilSecim==0){
			lcd_print(2,1,"4.Hata Kodu:");
			lcd_print(2,14,"   ");
			itoa(hataKayit4, snum, 10);
			lcd_print(2,13,snum);
			}
			if(dilSecim==1){
			lcd_print(2,1,"4.Error Code:");
			lcd_print(2,15,"  ");
		    itoa(hataKayit4, snum, 10);
		    lcd_print(2,14,snum);
			}
		}
		if(hataGostermeSirasi==4){
			if(dilSecim==0){
			lcd_print(2,1,"5.Hata Kodu:");
			lcd_print(2,14,"   ");
			itoa(hataKayit5, snum, 10);
			lcd_print(2,13,snum);
			}
			if(dilSecim==1){
			lcd_print(2,1,"5.Error Code:");
			lcd_print(2,15,"  ");
		    itoa(hataKayit5, snum, 10);
		    lcd_print(2,14,snum);
			}
		}
		if(hataGostermeSirasi==5){
			if(dilSecim==0){
			lcd_print(2,1,"6.Hata Kodu:");
			lcd_print(2,14,"   ");
			itoa(hataKayit6, snum, 10);
			lcd_print(2,13,snum);
			}
			if(dilSecim==1){
			lcd_print(2,1,"6.Error Code:");
			lcd_print(2,15,"  ");
		    itoa(hataKayit6, snum, 10);
		    lcd_print(2,14,snum);
			}
		}
		if(hataGostermeSirasi==6){
			if(dilSecim==0){
			lcd_print(2,1,"7.Hata Kodu:");
			lcd_print(2,14,"   ");
			itoa(hataKayit7, snum, 10);
			lcd_print(2,13,snum);
			}
			if(dilSecim==1){
			lcd_print(2,1,"7.Error Code:");
			lcd_print(2,15,"  ");
		    itoa(hataKayit7, snum, 10);
		    lcd_print(2,14,snum);
			}
		}
		if(hataGostermeSirasi==7){
			if(dilSecim==0){
			lcd_print(2,1,"8.Hata Kodu:");
			lcd_print(2,14,"   ");
			itoa(hataKayit8, snum, 10);
			lcd_print(2,13,snum);
			}
			if(dilSecim==1){
			lcd_print(2,1,"8.Error Code:");
			lcd_print(2,15,"  ");
		    itoa(hataKayit8, snum, 10);
		    lcd_print(2,14,snum);
			}
		}
		if(hataGostermeSirasi==8){
			if(dilSecim==0){
			lcd_print(2,1,"9.Hata Kodu:");
			lcd_print(2,14,"   ");
			itoa(hataKayit9, snum, 10);
			lcd_print(2,13,snum);
			}
			if(dilSecim==1){
			lcd_print(2,1,"9.Error Code:");
			lcd_print(2,15,"  ");
		    itoa(hataKayit9, snum, 10);
		    lcd_print(2,14,snum);
			}
		}
		if(hataGostermeSirasi==9){
			if(dilSecim==0){
			lcd_print(2,1,"10.Hata Kodu:");
			lcd_print(2,15,"  ");
			itoa(hataKayit1, snum, 10);
			lcd_print(2,14,snum);
			}
			if(dilSecim==1){
			lcd_print(2,1,"10.Error Code:");
			lcd_print(2,16," ");
		    itoa(hataKayit1, snum, 10);
		    lcd_print(2,15,snum);
			}
		}
		if(hataGostermeSirasi==10){
			if(dilSecim==0){
			lcd_print(2,1,"Silmek icin ent.");
			}
			if(dilSecim==1){
			lcd_print(2,1,"Del. press enter");
			}
		}


		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)&&(devirmeYuruyusSecim==0)){
			hataGostermeSirasi=hataGostermeSirasi+1;
			if(hataGostermeSirasi>10){
				hataGostermeSirasi=0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)&&(devirmeYuruyusSecim==0)){
			hataGostermeSirasi=hataGostermeSirasi-1;
	    	if(hataGostermeSirasi>11){
	    		hataGostermeSirasi=10;
	    	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)&& hataGostermeSirasi==10){

				  hataKayit1=0; eepromData[37]=0;
				  hataKayit2=0; eepromData[38]=0;
				  hataKayit3=0; eepromData[39]=0;
				  hataKayit4=0; eepromData[40]=0;
				  hataKayit5=0; eepromData[41]=0;
				  hataKayit6=0; eepromData[42]=0;
				  hataKayit7=0; eepromData[43]=0;
				  hataKayit8=0; eepromData[44]=0;
				  hataKayit9=0; eepromData[45]=0;
				  hataKayit10=0; eepromData[46]=0;
				  hafizaYaz=1;
		}
	}

	if (menuSayac==2){
		if(dilSecim==0){
			lcd_print(1,1,"CALISMA SEKLi   ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"WORKNG PRINCIPLE");
		}
		if((devirmeYuruyusSecim==1)||(devirmeYuruyusSecim==2)){
			if(dilSecim==0){
				lcd_print(2,1,"Dvr Yrys secildi");
			}
			if(dilSecim==1){
				lcd_print(2,1,"Tppng Mobil slct");
			}
		}
		if((calismaSekli==0)&&(devirmeYuruyusSecim==0)){

			if(dilSecim==0){
				lcd_print(2,1,"Bastikca cal.  ");
			}
			if(dilSecim==1){
				lcd_print(2,1,"Deadman Control");
			}
		}

		if((calismaSekli==1)&&(devirmeYuruyusSecim==0)){
			if(dilSecim==0){
				lcd_print(2,1,"Bas gonder     ");
			}
			if(dilSecim==1){
				lcd_print(2,1,"Call & Send    ");
			}
		}

		itoa(calismaSekli, snum, 10);
		lcd_print(2,16,snum);

		if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)&&(devirmeYuruyusSecim==0)){
			calismaSekli=calismaSekli+1;
			if(calismaSekli>1){
				calismaSekli=0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)&&(devirmeYuruyusSecim==0)){
			calismaSekli=calismaSekli-1;
	    	if(calismaSekli>0){
	    		calismaSekli=1;
	    	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
			eepromData[1]=calismaSekli;
			if(calismaSekli==1){
				altLimit=1;
				eepromData[5]=altLimit;
			}
			hafizaYaz=1;
		}
	}

	if (menuSayac==3){
		if(dilSecim==0){
			lcd_print(1,1,"EMNIYET CER.    ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"SAFETY FRAME    ");
		}
			if(emniyetCercevesi==0){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}
			}

			if(emniyetCercevesi==1){
				lcd_print(2,1,"OND Safety     ");
			}

			itoa(emniyetCercevesi, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				emniyetCercevesi=emniyetCercevesi+1;
				if(emniyetCercevesi>1){
					emniyetCercevesi=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				emniyetCercevesi=emniyetCercevesi-1;
		    	if(emniyetCercevesi>0){
		    		emniyetCercevesi=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[2]=emniyetCercevesi;
				hafizaYaz=1;
			}
		}

	if (menuSayac==4){
		if(dilSecim==0){
			lcd_print(1,1,"YAVASLAMA LIMIT ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"SLOW DOWN LIMIT ");
		}
			if(yavaslamaLimit==0){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}
			}

			if(yavaslamaLimit==1){
				if(dilSecim==0){
					lcd_print(2,1,"Aktif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Active         ");
				}
			}

			itoa(yavaslamaLimit, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				yavaslamaLimit=yavaslamaLimit+1;
				if(yavaslamaLimit>1){
					yavaslamaLimit=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				yavaslamaLimit=yavaslamaLimit-1;
		    	if(yavaslamaLimit>0){
		    		yavaslamaLimit=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[4]=yavaslamaLimit;
				hafizaYaz=1;
			}
		}

	if (menuSayac==5){
		if(dilSecim==0){
			lcd_print(1,1,"ALT LIMIT       ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"DOWN LIMIT      ");
		}
			if(altLimit==0){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}
			}

			if(altLimit==1){
				if(dilSecim==0){
					lcd_print(2,1,"Aktif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Active         ");
				}
			}

			itoa(altLimit, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)&&(calismaSekli==0)){
				altLimit=altLimit+1;
				if(altLimit>1){
					altLimit=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)&&calismaSekli==0){
				altLimit=altLimit-1;
		    	if(altLimit>0){
		    		altLimit=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[5]=altLimit;
				if(altLimit==0 && (kapiTablaAcKonum==0 || kapiTablaAcKonum==2)){
					kapiTablaAcKonum=3;
					eepromData[34]=kapiTablaAcKonum;
				}
					if(altLimit==0){
						platformSilindirTipi=0;
						eepromData[19]=platformSilindirTipi;
					}


				hafizaYaz=1;
			}
		}

	if (menuSayac==6){
		if(dilSecim==0){
			lcd_print(1,1,"BASINC SALTERI ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"PRESSURE SWITCH");
		}
			if(basincSalteri==0){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}
			}

			if(basincSalteri==1){
				if(dilSecim==0){
					lcd_print(2,1,"Aktif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Active         ");
				}
			}

			itoa(basincSalteri, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				basincSalteri=basincSalteri+1;
				if(basincSalteri>1){
					basincSalteri=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				basincSalteri=basincSalteri-1;
		    	if(basincSalteri>0){
		    		basincSalteri=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[6]=basincSalteri;
				hafizaYaz=1;
			}
		}

	if (menuSayac==7){
		if(dilSecim==0){
			lcd_print(1,1,"KAPI SECIMLERI     ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"DOOR SELECTION     ");
		}
			if(kapiSecimleri==0){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}
			}

			if(kapiSecimleri==1){
				if(dilSecim==0){
					lcd_print(2,1,"Kat kapisi aktif");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Floor door act  ");
				}
			}

			if(kapiSecimleri==2){
				if(dilSecim==0){
					lcd_print(2,1,"Tabla kapi aktif");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Pltfrm door act ");
				}
			}
			if(kapiSecimleri==3){
				if(dilSecim==0){
					lcd_print(2,1,"Kat + Tabl aktif");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Flr + Plrfrm act");
				}
			}

			itoa(kapiSecimleri, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				kapiSecimleri=kapiSecimleri+1;
				if(kapiSecimleri>3){
					kapiSecimleri=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				kapiSecimleri=kapiSecimleri-1;
		    	if(kapiSecimleri>4){
		    		kapiSecimleri=3;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[7]=kapiSecimleri;
				if(kapiSecimleri>=1){
					altLimit=1;
					eepromData[5]=altLimit;
				}
				hafizaYaz=1;
			}
		}

	if (menuSayac==8){
		if(dilSecim==0){
			lcd_print(1,1,"KAPI ACMA TIPI  ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"OPEN DOOR TYPE");
		}
			if(kapiAcTipi==0){
				if(dilSecim==0){
					lcd_print(2,1,"Kapi butonu ESP");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Door Button ESP");
				}
			}

			if(kapiAcTipi==1){
				if(dilSecim==0){
					lcd_print(2,1,"Kat butonu EXT  ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Floor button EXT");
				}
			}

			itoa(kapiAcTipi, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				kapiAcTipi=kapiAcTipi+1;
				if(kapiAcTipi>1){
					kapiAcTipi=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				kapiAcTipi=kapiAcTipi-1;
		    	if(kapiAcTipi>0){
		    		kapiAcTipi=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[36]=kapiAcTipi;
				hafizaYaz=1;
			}
		}

	if (menuSayac==9){
		if(dilSecim==0){
			lcd_print(1,1,"1.KAT KAPI TiPi ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"1.FLOOR DOOR TYP");
		}
			if(kapi1Tip==0){
				lcd_print(2,1,"Prudhome       ");
			}

			if(kapi1Tip==1){
				if(dilSecim==0){
					lcd_print(2,1,"Buton kontrollu");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Button cntrolled");
				}
			}

			if(kapi1Tip==2){
				lcd_print(2,1,"Pizzato        ");
			}

			itoa(kapi1Tip, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				kapi1Tip=kapi1Tip+1;
				if(kapi1Tip>2){
					kapi1Tip=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				kapi1Tip=kapi1Tip-1;
		    	if(kapi1Tip>3){
		    		kapi1Tip=2;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[8]=kapi1Tip;
				hafizaYaz=1;
			}
		}
	if (menuSayac==10){
			if(dilSecim==0){
				lcd_print(1,1,"1.KAPI AC SURESi");
				lcd_print(2,1,"Kac Saniye     ");
			}
			if(dilSecim==1){
				lcd_print(1,1,"1.FLR DR OPN TMR");
				lcd_print(2,1,"Seconds         ");
			}

				itoa(kapi1AcSure, snum, 10);
				lcd_print(2,16,snum);

				if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)&&(kapi1Tip==0)){
					kapi1AcSure=kapi1AcSure+1;
					if(kapi1AcSure>5){
						kapi1AcSure=0;
					}
					bekle();
				}

				if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)&&(kapi1Tip==0)){
					kapi1AcSure=kapi1AcSure-1;
			    	if(kapi1AcSure>6){
			    		kapi1AcSure=5;
			    	}
					bekle();

				}
				if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
					eepromData[9]=kapi1AcSure;
					hafizaYaz=1;
				}
			}


	if (menuSayac==11){
		if(dilSecim==0){
			lcd_print(1,1,"2.KAT KAPI TiPi ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"2.FLOOR DOOR TYP");
		}
			if(kapi2Tip==0){
				lcd_print(2,1,"Prudhome       ");
			}

			if(kapi2Tip==1){
				if(dilSecim==0){
					lcd_print(2,1,"Buton kontrollu");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Button cntrolled");
				}
			}

			if(kapi2Tip==2){
				lcd_print(2,1,"Pizzato        ");
			}

			itoa(kapi2Tip, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				kapi2Tip=kapi2Tip+1;
				if(kapi2Tip>2){
					kapi2Tip=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				kapi2Tip=kapi2Tip-1;
		    	if(kapi2Tip>3){
		    		kapi2Tip=2;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[10]=kapi2Tip;
				hafizaYaz=1;
			}
		}
	if (menuSayac==12){
			if(dilSecim==0){
				lcd_print(1,1,"2.KAPI AC SURESi");
				lcd_print(2,1,"Kac Saniye     ");
			}
			if(dilSecim==1){
				lcd_print(1,1,"2.FLR DR OPN TMR");
				lcd_print(2,1,"Seconds         ");
			}


				itoa(kapi2AcSure, snum, 10);
				lcd_print(2,16,snum);

				if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)&&(kapi2Tip==0)){
					kapi2AcSure=kapi2AcSure+1;
					if(kapi2AcSure>5){
						kapi2AcSure=0;
					}
					bekle();
				}

				if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)&&(kapi2Tip==0)){
					kapi2AcSure=kapi2AcSure-1;
			    	if(kapi2AcSure>6){
			    		kapi2AcSure=5;
			    	}
					bekle();

				}
				if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
					eepromData[11]=kapi2AcSure;
					hafizaYaz=1;
				}
			}

	if (menuSayac==13){
		if(dilSecim==0){
			lcd_print(1,1,"TABLA KAPI TiPi ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"PLTFRM DOOR TYPE");
		}
			if(kapitablaTip==0){
				lcd_print(2,1,"Prudhome       ");
			}

			if(kapitablaTip==1){
				if(dilSecim==0){
					lcd_print(2,1,"Buton kontrollu");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Button cntrolled");
				}
			}

			if(kapitablaTip==2){
				lcd_print(2,1,"Pizzato        ");
			}

			itoa(kapitablaTip, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				kapitablaTip=kapitablaTip+1;
				if(kapitablaTip>2){
					kapitablaTip=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				kapitablaTip=kapitablaTip-1;
		    	if(kapitablaTip>3){
		    		kapitablaTip=2;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[12]=kapitablaTip;
				hafizaYaz=1;
			}
		}

	if (menuSayac==14){
		if(dilSecim==0){
			lcd_print(1,1,"TBL KPI AC KONUM");
		}
		if(dilSecim==1){
			lcd_print(1,1,"PLTFRM DR OP LOC");
		}
			if(kapiTablaAcKonum==0){
				if(dilSecim==0){
					lcd_print(2,1,"1. Katta ac    ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"1. Floor open  ");
				}
			}

			if(kapiTablaAcKonum==1){
				if(dilSecim==0){
					lcd_print(2,1,"2. Katta ac    ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"2. Floor open  ");
				}
			}

			if(kapiTablaAcKonum==2){
				if(dilSecim==0){
					lcd_print(2,1,"1.+2. Katta ac ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"1.+2. Floor open");
				}
			}

			if(kapiTablaAcKonum==3){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}
			}

			itoa(kapiTablaAcKonum, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				kapiTablaAcKonum=kapiTablaAcKonum+1;
				if(kapiTablaAcKonum>2){
					kapiTablaAcKonum=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				kapiTablaAcKonum=kapiTablaAcKonum-1;
		    	if(kapiTablaAcKonum>3){
		    		kapiTablaAcKonum=2;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[34]=kapiTablaAcKonum;
				if(kapiTablaAcKonum==0 || kapiTablaAcKonum==2){
					altLimit=1;
					eepromData[5]=altLimit;
				}

				hafizaYaz=1;
			}
		}

	if (menuSayac==15){
			if(dilSecim==0){
				lcd_print(1,1,"TABLA KP AC SURE");
				lcd_print(2,1,"Kac Saniye     ");
			}
			if(dilSecim==1){
				lcd_print(1,1,"PLTFM DR OPN TMR");
				lcd_print(2,1,"Seconds         ");
			}

				itoa(kapiTablaAcSure, snum, 10);
				lcd_print(2,16,snum);

				if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)&&(kapitablaTip==0)){
					kapiTablaAcSure=kapiTablaAcSure+1;
					if(kapiTablaAcSure>5){
						kapiTablaAcSure=0;
					}
					bekle();
				}

				if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)&&(kapitablaTip==0)){
					kapiTablaAcSure=kapiTablaAcSure-1;
			    	if(kapiTablaAcSure>6){
			    		kapiTablaAcSure=5;
			    	}
					bekle();

				}
				if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
					eepromData[13]=kapiTablaAcSure;
					hafizaYaz=1;
				}
			}

	if (menuSayac==16){
		if(dilSecim==0){
			lcd_print(1,1,"YUKARI YAVAS LMT");
		}
		if(dilSecim==1){
			lcd_print(1,1,"UPPR SLW DWN LMT");
		}
			if(yukariYavasLimit==0){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}
			}

			if(yukariYavasLimit==1){
				if(dilSecim==0){
					lcd_print(2,1,"Aktif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Active         ");
				}
			}

			itoa(yukariYavasLimit, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				yukariYavasLimit=yukariYavasLimit+1;
				if(yukariYavasLimit>1){
					yukariYavasLimit=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				yukariYavasLimit=yukariYavasLimit-1;
		    	if(yukariYavasLimit>0){
		    		yukariYavasLimit=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[14]=yukariYavasLimit;
				hafizaYaz=1;
			}
		}

	if (menuSayac==17){
		if(dilSecim==0){
			lcd_print(1,1,"DEVIRME-YURUYUS ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"TPPNG-MOBIL PLT ");
		}
			if(devirmeYuruyusSecim==2){
				if(dilSecim==0){
					lcd_print(2,1,"Devirme aktif  ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Tipping active ");
				}
			}

			if(devirmeYuruyusSecim==1){
				if(dilSecim==0){
					lcd_print(2,1,"Yuruyus aktif  ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Drive active   ");
				}

			}

			if(devirmeYuruyusSecim==0){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}

			}
			itoa(devirmeYuruyusSecim, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				devirmeYuruyusSecim=devirmeYuruyusSecim+1;
				if(devirmeYuruyusSecim>2){
					devirmeYuruyusSecim=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				devirmeYuruyusSecim=devirmeYuruyusSecim-1;
		    	if(devirmeYuruyusSecim>3){
		    		devirmeYuruyusSecim=2;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[15]=devirmeYuruyusSecim;
				if(devirmeYuruyusSecim==2||devirmeYuruyusSecim==1)
				{
					calismaSekli=0;
					eepromData[1]=calismaSekli;
				}

				if(devirmeYuruyusSecim==1){
					devirmeSilindirTipi=1;
					eepromData[18]=devirmeSilindirTipi;
				}
				hafizaYaz=1;
			}
		}
	if (menuSayac==18){

				if(devirmeYuruyusSecim==2){
					if(dilSecim==0){
						lcd_print(1,1,"DEVRM YUKARI SVC");
					}
					if(dilSecim==1){
						lcd_print(1,1,"TPPNG SWTCH/OPN");
					}
				}

				if(devirmeYuruyusSecim==1){
					if(dilSecim==0){
						lcd_print(1,1,"YURUYUS ILER SVC");
					}
					if(dilSecim==1){
						lcd_print(1,1,"DRVE FRWRD SWTCH");
					}
				}

				if(devirmeYukariIleriLimit==0){
					if(dilSecim==0){
						lcd_print(2,1,"Pasif          ");
					}
					if(dilSecim==1){
						lcd_print(2,1,"Passive        ");
					}
				}

				if(devirmeYukariIleriLimit==1){
					if(dilSecim==0){
						lcd_print(2,1,"Aktif          ");
					}
					if(dilSecim==1){
						lcd_print(2,1,"Active         ");
					}
				}

				itoa(devirmeYukariIleriLimit, snum, 10);
				lcd_print(2,16,snum);

				if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
					devirmeYukariIleriLimit=devirmeYukariIleriLimit+1;
					if(devirmeYukariIleriLimit>1){
						devirmeYukariIleriLimit=0;
					}
					bekle();
				}

				if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
					devirmeYukariIleriLimit=devirmeYukariIleriLimit-1;
			    	if(devirmeYukariIleriLimit>0){
			    		devirmeYukariIleriLimit=1;
			    	}
					bekle();
				}

				if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
					eepromData[16]=devirmeYukariIleriLimit;
					hafizaYaz=1;
				}
			}

	if (menuSayac==19){
			if(devirmeYuruyusSecim==2){
				if(dilSecim==0){
					lcd_print(1,1,"DEVIRM ASAGI SVC");
				}
				if(dilSecim==1){
					lcd_print(1,1,"TPPNG SWTCH/CLSD");
				}
			}

			if(devirmeYuruyusSecim==1){
				if(dilSecim==0){
					lcd_print(1,1,"YURUYUS GERI SVC");
				}
				if(dilSecim==1){
					lcd_print(1,1,"DRIVE BACK SWTCH");
				}
			}

			if(devirmeAsagiGeriLimit==0){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}
			}

			if(devirmeAsagiGeriLimit==1){
				if(dilSecim==0){
					lcd_print(2,1,"Aktif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Active         ");
				}
			}

			itoa(devirmeAsagiGeriLimit, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				devirmeAsagiGeriLimit=devirmeAsagiGeriLimit+1;
				if(devirmeAsagiGeriLimit>1){
					devirmeAsagiGeriLimit=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				devirmeAsagiGeriLimit=devirmeAsagiGeriLimit-1;
		    	if(devirmeAsagiGeriLimit>0){
		    		devirmeAsagiGeriLimit=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[17]=devirmeAsagiGeriLimit;
				hafizaYaz=1;
			}
		}

	if (menuSayac==20){
			if(devirmeYuruyusSecim==1){
				if(dilSecim==0){
					lcd_print(1,1,"YURUYUS SECiLDi ");
				}
				if(dilSecim==1){
					lcd_print(1,1,"DRIVE SELECTED  ");
				}
			}
			if(devirmeYuruyusSecim==2){
				if(dilSecim==0){
					lcd_print(1,1,"DEVIRME SLN TIPI");
				}
				if(dilSecim==1){
					lcd_print(1,1,"CYLNDR TYP/TIPPD");
				}
			}
			if(devirmeSilindirTipi==0){
				if(dilSecim==0){
					lcd_print(2,1,"Tek tesir      ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Single acting  ");
				}
			}

			if(devirmeSilindirTipi==1){
				if(dilSecim==0){
					lcd_print(2,1,"Cift tesir     ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Double acting  ");
				}
			}

			itoa(devirmeSilindirTipi, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)&&(devirmeYuruyusSecim==2)){
				devirmeSilindirTipi=devirmeSilindirTipi+1;
				if(devirmeSilindirTipi>1){
					devirmeSilindirTipi=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)&&(devirmeYuruyusSecim==2)){
				devirmeSilindirTipi=devirmeSilindirTipi-1;
		    	if(devirmeSilindirTipi>0){
		    		devirmeSilindirTipi=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[18]=devirmeSilindirTipi;
				hafizaYaz=1;
			}
		}

	if (menuSayac==21){
		if(dilSecim==0){
			lcd_print(1,1,"PLATFRM SLN TIPI");
		}
		if(dilSecim==1){
			lcd_print(1,1,"CYLNDR TYPE/PLT");
		}
			if(platformSilindirTipi==0){
				if(dilSecim==0){
					lcd_print(2,1,"Tek tesir      ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Single acting  ");
				}
			}

			if(platformSilindirTipi==1){
				if(dilSecim==0){
					lcd_print(2,1,"Cift tesir     ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Double acting  ");
				}
			}

			itoa(platformSilindirTipi, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				platformSilindirTipi=platformSilindirTipi+1;
				if(platformSilindirTipi>1){
					platformSilindirTipi=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				platformSilindirTipi=platformSilindirTipi-1;
		    	if(platformSilindirTipi>0){
		    		platformSilindirTipi=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[19]=platformSilindirTipi;
				if(platformSilindirTipi==1){
					altLimit=1;
					eepromData[5]=altLimit;
				}
				hafizaYaz=1;
			}
		}

	if (menuSayac==22){
		if(dilSecim==0){
			lcd_print(1,1,"YUKARI VALF SURE");
		}
		if(dilSecim==1){
			lcd_print(1,1,"UP VALVE TIMER  ");
		}
			if(yukariValfTmr>=0){
				if(dilSecim==0){
					lcd_print(2,1,"Kac Saniye     ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Second         ");
				}
			}

			itoa(yukariValfTmr, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				yukariValfTmr=yukariValfTmr+1;
				if(yukariValfTmr>5){
					yukariValfTmr=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				yukariValfTmr=yukariValfTmr-1;
		    	if(yukariValfTmr>6){
		    		yukariValfTmr=5;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[20]=yukariValfTmr;
				hafizaYaz=1;
			}
		}

	if (menuSayac==23){
		if(dilSecim==0){
			lcd_print(1,1,"ASAGI VALF SURE ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"DOWN VALVE TIMER");
		}
			if(asagiValfTmr>=0){
				if(dilSecim==0){
					lcd_print(2,1,"Kac Saniye     ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Second         ");
				}
			}

			itoa(asagiValfTmr, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				asagiValfTmr=asagiValfTmr+1;
				if(asagiValfTmr>5){
					asagiValfTmr=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				asagiValfTmr=asagiValfTmr-1;
		    	if(asagiValfTmr>6){
		    		asagiValfTmr=5;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[21]=asagiValfTmr;
				hafizaYaz=1;
			}
		}

	if (menuSayac==24){
			if(devirmeYuruyusSecim==2){
				if(dilSecim==0){
					lcd_print(1,1,"DVRM YKR VLF SN ");
				}
				if(dilSecim==1){
					lcd_print(1,1,"TIPPD UP VLV TMR");
				}
			}

			if(devirmeYuruyusSecim==1){
				if(dilSecim==0){
					lcd_print(1,1,"iLERi VALF SURE ");
				}
				if(dilSecim==1){
					lcd_print(1,1,"FRWD DRV VLV TMR");
				}
			}

			if(devirmeYukariIleriTmr>=0){
				if(dilSecim==0){
					lcd_print(2,1,"Kac Saniye     ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Second         ");
				}
			}

			itoa(devirmeYukariIleriTmr, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				devirmeYukariIleriTmr=devirmeYukariIleriTmr+1;
				if(devirmeYukariIleriTmr>5){
					devirmeYukariIleriTmr=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				devirmeYukariIleriTmr=devirmeYukariIleriTmr-1;
		    	if(devirmeYukariIleriTmr>6){
		    		devirmeYukariIleriTmr=5;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[22]=devirmeYukariIleriTmr;
				hafizaYaz=1;
			}
		}

	if (menuSayac==25){
			if(devirmeYuruyusSecim==2){
				if(dilSecim==0){
					lcd_print(1,1,"DVRM ASG VALF SN");
				}
				if(dilSecim==1){
					lcd_print(1,1,"TPPD DWN VLV TMR");
				}
			}
			if(devirmeYuruyusSecim==1){
				if(dilSecim==0){
					lcd_print(1,1,"GERi VALF SURE  ");
				}
				if(dilSecim==1){
					lcd_print(1,1,"REVERSE VLV TMR ");
				}
			}

			if(devirmeAsagiGeriTmr>=0){
				if(dilSecim==0){
					lcd_print(2,1,"Kac Saniye     ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Second         ");
				}
			}

			itoa(devirmeAsagiGeriTmr, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				devirmeAsagiGeriTmr=devirmeAsagiGeriTmr+1;
				if(devirmeAsagiGeriTmr>5){
					devirmeAsagiGeriTmr=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				devirmeAsagiGeriTmr=devirmeAsagiGeriTmr-1;
		    	if(devirmeAsagiGeriTmr>6){
		    		devirmeAsagiGeriTmr=5;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[23]=devirmeAsagiGeriTmr;
				hafizaYaz=1;
			}
		}

	if (menuSayac==26){
		if(dilSecim==0){
			lcd_print(1,1,"CALiSMA SURESi  ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"WORKING TIME  ");
		}
			if(makineCalismaTmr>99){
				if(dilSecim==0){
					lcd_print(2,1,"Kac Saniye     ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Second         ");
				}
				itoa(makineCalismaTmr, snum, 10);
				lcd_print(2,14,snum);

			}
			if((makineCalismaTmr>=10)&&(makineCalismaTmr<=99)){
				if(dilSecim==0){
					lcd_print(2,1,"Kac Saniye     ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Second         ");
				}

			itoa(makineCalismaTmr, snum, 10);
			lcd_print(2,15,snum);
			}
			if(makineCalismaTmr<=9)
			{
				if(dilSecim==0){
					lcd_print(2,1,"Kac Saniye     ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Second         ");
				}

				itoa(makineCalismaTmr, snum, 10);
				lcd_print(2,16,snum);
			}

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				makineCalismaTmr=makineCalismaTmr+1;
				if(makineCalismaTmr>180){
					makineCalismaTmr=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				makineCalismaTmr=makineCalismaTmr-1;
		    	if(makineCalismaTmr>181){
		    		makineCalismaTmr=180;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[24]=makineCalismaTmr;
				hafizaYaz=1;
			}
		}

	if (menuSayac==27){
			lcd_print(1,1,"BUZZER          ");
			if(buzzer==0){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}
			}

			if(buzzer==1){
				if(dilSecim==0){
					lcd_print(2,1,"Aktif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Active         ");
				}
			}

			itoa(buzzer, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				buzzer=buzzer+1;
				if(buzzer>1){
					buzzer=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				buzzer=buzzer-1;
		    	if(buzzer>0){
		    		buzzer=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[25]=buzzer;
				hafizaYaz=1;
			}
		}

	if (menuSayac==28){
		calismaSayModu=0;
			lcd_print(1,1,"DEMO MODE      ");
			if(demoMode==0){
				if(dilSecim==0){
					lcd_print(2,1,"Pasif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Passive        ");
				}
			}

			if(demoMode==1){
				if(dilSecim==0){
					lcd_print(2,1,"Aktif          ");
				}
				if(dilSecim==1){
					lcd_print(2,1,"Active         ");
				}
			}

			itoa(demoMode, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				demoMode=demoMode+1;
				if(demoMode>1){
					demoMode=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				demoMode=demoMode-1;
		    	if(demoMode>0){
		    		demoMode=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[26]=demoMode;
				hafizaYaz=1;
			}
		}

	if (menuSayac==29){
		if(calismaSayisi1==0 && calismaSayisi10==0 && calismaSayisi100==0 && calismaSayisi1000==0 && calismaSayisi10000==0){
			calismaSayisiYar=0;
		}
		else
			calismaSayisiYar=1;
		if(calismaSayModu==0){

			if(dilSecim==0){
				lcd_print(1,1,"Calisma Sayisi  ");
				}
			if(dilSecim==1)
			{
			lcd_print(1,1,"Working Cycle   ");
			}

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
			lcd_print(2, 1, "           ");

			}

			if(calismaSayModu==1){
				if(dilSecim==0){
					lcd_print(1,1,"Calisma Sayisi  ");
					lcd_print(2,1,"Enter'la Sifirla");
				}
				if(dilSecim==1){
					lcd_print(1,1,"Working Cycle   ");
					lcd_print(2,1,"Del. with Enter ");
				}

			}

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)&&(calismaSayisiYar==1)){
				calismaSayModu=calismaSayModu+1;
				if(calismaSayModu>1){
					calismaSayModu=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)&&(calismaSayisiYar==1)){
				calismaSayModu=calismaSayModu-1;
		    	if(calismaSayModu>0){
		    		calismaSayModu=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[32]=0;
				eepromData[31]=0;
				eepromData[30]=0;
				eepromData[29]=0;
				eepromData[28]=0;
				calismaSayisi10000=0;
				calismaSayisi1000=0;
				calismaSayisi100=0;
				calismaSayisi10=0;
				calismaSayisi1=0;
				calismaSayModu=0;
				hafizaYaz=1;
			}
		}

	if (menuSayac==30){
		calismaSayModu=0;
		if(dilSecim==0){
			lcd_print(1,1,"DIL SECIMI      ");
		}
		if(dilSecim==1){
			lcd_print(1,1,"LANGUAGE SELECT ");
		}
			if(dilSecim==0){
				lcd_print(2,1,"TURKCE         ");
			}

			if(dilSecim==1){
				lcd_print(2,1,"INGILIZCE      ");
			}

			itoa(dilSecim, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(butonKontrol==0)){
				dilSecim=dilSecim+1;
				if(dilSecim>1){
					dilSecim=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(butonKontrol==0)){
				dilSecim=dilSecim-1;
		    	if(dilSecim>0){
		    		dilSecim=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[33]=dilSecim;
				hafizaYaz=1;
			}
		}

	if (menuSayac==31){
		if(dilSecim==0){
			lcd_print(1,1," MENUDEN CIKIS  ");
			lcd_print(2,1,"ENTER'A BASINIZ ");
		}
		if(dilSecim==1){
			lcd_print(1,1," EXIT THE MENU  ");
			lcd_print(2,1,"PUSH ENTER BUTON");
		}

		if (HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1){
			menuGiris=0;
			lcd_clear();
			HAL_Delay(100);
			NVIC_SystemReset();
		}
	}
}

void hataKoduLcdGoster(uint8_t x) {
	if(x==1) {
		if(dilSecim==0){
		lcd_print(1, 1, "   HATA KODU    ");
		}
		if(dilSecim==1){
		lcd_print(1, 1, "   ERROR CODE   ");
		}
		lcd_print(2, 1, "1");
		lcd_print(2, 7, "          ");
	} else if(x==2){
		if(dilSecim==0){
		lcd_print(1, 1, "   HATA KODU    ");
		}
		if(dilSecim==1){
		lcd_print(1, 1, "   ERROR CODE   ");
		}
		lcd_print(2, 2, "2");
		lcd_print(2, 7, "          ");
	} else if(x==3){
		if(dilSecim==0){
		lcd_print(1, 1, "   HATA KODU    ");
		}
		if(dilSecim==1){
		lcd_print(1, 1, "   ERROR CODE   ");
		}
		lcd_print(2, 3, "3");
		lcd_print(2, 7, "          ");
	} else if(x==4){
		if(dilSecim==0){
		lcd_print(1, 1, "   HATA KODU    ");
		}
		if(dilSecim==1){
		lcd_print(1, 1, "   ERROR CODE   ");
		}
		lcd_print(2, 4, "4");
		lcd_print(2, 7, "          ");
	} else if(x==5){
		if(dilSecim==0){
		lcd_print(1, 1, "   HATA KODU    ");
		}
		if(dilSecim==1){
		lcd_print(1, 1, "   ERROR CODE   ");
		}
		lcd_print(2, 5, "5");
		lcd_print(2, 7, "          ");
	} else if(x==6){
		if(dilSecim==0){
		lcd_print(1, 1, "   HATA KODU    ");
		}
		if(dilSecim==1){
		lcd_print(1, 1, "   ERROR CODE   ");
		}
		lcd_print(2, 6, "6");
		lcd_print(2, 7, "          ");
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) //------timer kesmesinde islem yapmak için
{
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
  run_delay();
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

  eepromKontrol();
  loadMenuTexts(dilSecim);

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);
  xTaskCreate(ledTask, "ledTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
  xTaskCreate(wifiTask, "wifiTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	  while (1)
	   {


	   }
  /* USER CODE END 3 */
}

void loadMenuTexts(int dilSecim) {
	strcpy(mainText, mainTextGN);
	strcpy(mainText2, mainText2GN);
	strcpy(ondSafetyText, ondSafetyTextGN);
	strcpy(prudhomeText, prudhomeTextGN);
	strcpy(pizzattoText, pizzattoTextGN);
	strcpy(buzzerText, buzzerTextGN);
	strcpy(demoModText, demoModTextGN);
	/*if(dilSecim == 0) {
		strcpy(menuyeGirildiText, menuyeGirildiTextTR);
		strcpy(ayarlarText, ayarlarTextTR);
		strcpy(hataKayitListText, hataKayitListTextTR);
		strcpy(birHataKoduText, birHataKoduTextTR);
		strcpy(ikiHataKoduText, ikiHataKoduTextTR);
		strcpy(ucHataKoduText, ucHataKoduTextTR);
		strcpy(dortHataKoduText, dortHataKoduTextTR);
		strcpy(besHataKoduText, besHataKoduTextTR);
		strcpy(altiHataKoduText, altiHataKoduTextTR);
		strcpy(yediHataKoduText, yediHataKoduTextTR);
		strcpy(sekizHataKoduText, sekizHataKoduTextTR);
		strcpy(dokuzHataKoduText, dokuzHataKoduTextTR);
		strcpy(onHataKoduText, onHataKoduTextTR);
		strcpy(silmekIcinText, silmekIcinTextTR);
		strcpy(calismaSekliText, calismaSekliTextTR);
		strcpy(devirmeYuruyusText, devirmeYuruyusTextTR);
		strcpy(bastikcaCalisanText, bastikcaCalisanTextTR);
		strcpy(basGonderText, basGonderTextTR);
		strcpy(emniyetCercevesiText, emniyetCercevesiTextTR);
		strcpy(pasifText, pasifTextTR);
		strcpy(aktifText, aktifTextTR);
		strcpy(yavaslamaLimitText, yavaslamaLimitTextTR);
		strcpy(altLimitText, altLimitTextTR);
		strcpy(basincSalteriText, basincSalteriTextTR);
		strcpy(kapiSecimleriText, kapiSecimleriTextTR);
		strcpy(katKapisiAktifText, katKapisiAktifTextTR);
		strcpy(tablaKapiAktifText, tablaKapiAktifTextTR);
		strcpy(katArtiTablaAktifText, katArtiTablaAktifTextTR);
		strcpy(kapiAcmaTipiText, kapiAcmaTipiTextTR);
		strcpy(kapiButonuESPText, kapiButonuESPTextTR);
		strcpy(katButonuEXTText, katButonuEXTTextTR);
		strcpy(birKatKapiTipiText, birKatKapiTipiTextTR);
		strcpy(butonKontrolluText, butonKontrolluTextTR);
		strcpy(birinciKapiAcSuresiText, birinciKapiAcSuresiTextTR);
		strcpy(kacSaniyeText, kacSaniyeTextTR);
		strcpy(ikinciKatKapiTipiText, ikinciKatKapiTipiTextTR);
		strcpy(ikinciKapiAcSuresiText, ikinciKapiAcSuresiTextTR);
		strcpy(tablaKapiTipiText, tablaKapiTipiTextTR);
		strcpy(tablaKapiAcKonumText, tablaKapiAcKonumTextTR);
		strcpy(birinciKattaAcText, birinciKattaAcTextTR);
		strcpy(ikinciKattaAcText, ikinciKattaAcTextTR);
		strcpy(birVeIkinciKattaAcText, birVeIkinciKattaAcTextTR);
		strcpy(tablaKapiAcSureText, tablaKapiAcSureTextTR);
		strcpy(yukariYavaslamaLimitiText, yukariYavaslamaLimitiTextTR);
		strcpy(devirmeYuruyusMenuText, devirmeYuruyusMenuTextTR);
		strcpy(devirmeAktifText, devirmeAktifTextTR);
		strcpy(yuruyusAktifText, yuruyusAktifTextTR);
		strcpy(devirmeYukariText, devirmeYukariTextTR);
		strcpy(yuruyusIleriText, yuruyusIleriTextTR);
		strcpy(devirmeAsagiSivicText, devirmeAsagiSivicTextTR);
		strcpy(yuruyusGeriSivicText, yuruyusGeriSivicTextTR);
		strcpy(yuruyusSecildiText, yuruyusSecildiTextTR);
		strcpy(devirmeSilindirTipiText, devirmeSilindirTipiTextTR);
		strcpy(tekTesirText, tekTesirTextTR);
		strcpy(ciftTesirText, ciftTesirTextTR);
		strcpy(platformSilindirTipiText, platformSilindirTipiTextTR);
		strcpy(asagiValfSureText, asagiValfSureTextTR);
		strcpy(devirmeYukariValfSureText, devirmeYukariValfSureTextTR);
		strcpy(ileriValfSureText, ileriValfSureTextTR);
		strcpy(devirmeAsagiValfSureText, devirmeAsagiValfSureTextTR);
		strcpy(geriValfSureText, geriValfSureTextTR);
		strcpy(calismaSuresiText, calismaSuresiTextTR);
		strcpy(calismaSayisiText, calismaSayisiTextTR);
		strcpy(enterlaSifirlaText, enterlaSifirlaTextTR);
		strcpy(dilSecimText, dilSecimTextTR);
		strcpy(secilenDilText, secilenDilTextTR);
		strcpy(menudenCikisText, menudenCikisTextTR);
		strcpy(enteraBasinizText, enteraBasinizTextTR);
		strcpy(hataKoduText, hataKoduTextTR);
	} else {
		strcpy(menuyeGirildiText, menuyeGirildiTextEN);
		strcpy(ayarlarText, ayarlarTextEN);
		strcpy(hataKayitListText, hataKayitListTextEN);
		strcpy(birHataKoduText, birHataKoduTextEN);
		strcpy(ikiHataKoduText, ikiHataKoduTextEN);
		strcpy(ucHataKoduText, ucHataKoduTextEN);
		strcpy(dortHataKoduText, dortHataKoduTextEN);
		strcpy(besHataKoduText, besHataKoduTextEN);
		strcpy(altiHataKoduText, altiHataKoduTextEN);
		strcpy(yediHataKoduText, yediHataKoduTextEN);
		strcpy(sekizHataKoduText, sekizHataKoduTextEN);
		strcpy(dokuzHataKoduText, dokuzHataKoduTextEN);
		strcpy(onHataKoduText, onHataKoduTextEN);
		strcpy(silmekIcinText, silmekIcinTextEN);
		strcpy(calismaSekliText, calismaSekliTextEN);
		strcpy(devirmeYuruyusText, devirmeYuruyusTextEN);
		strcpy(bastikcaCalisanText, bastikcaCalisanTextEN);
		strcpy(basGonderText, basGonderTextEN);
		strcpy(emniyetCercevesiText, emniyetCercevesiTextEN);
		strcpy(pasifText, pasifTextEN);
		strcpy(aktifText, aktifTextEN);
		strcpy(yavaslamaLimitText, yavaslamaLimitTextEN);
		strcpy(altLimitText, altLimitTextEN);
		strcpy(basincSalteriText, basincSalteriTextEN);
		strcpy(kapiSecimleriText, kapiSecimleriTextEN);
		strcpy(katKapisiAktifText, katKapisiAktifTextEN);
		strcpy(tablaKapiAktifText, tablaKapiAktifTextEN);
		strcpy(katArtiTablaAktifText, katArtiTablaAktifTextEN);
		strcpy(kapiAcmaTipiText, kapiAcmaTipiTextEN);
		strcpy(kapiButonuESPText, kapiButonuESPTextEN);
		strcpy(katButonuEXTText, katButonuEXTTextEN);
		strcpy(birKatKapiTipiText, birKatKapiTipiTextEN);
		strcpy(butonKontrolluText, butonKontrolluTextEN);
		strcpy(birinciKapiAcSuresiText, birinciKapiAcSuresiTextEN);
		strcpy(kacSaniyeText, kacSaniyeTextEN);
		strcpy(ikinciKatKapiTipiText, ikinciKatKapiTipiTextEN);
		strcpy(ikinciKapiAcSuresiText, ikinciKapiAcSuresiTextEN);
		strcpy(tablaKapiTipiText, tablaKapiTipiTextEN);
		strcpy(tablaKapiAcKonumText, tablaKapiAcKonumTextEN);
		strcpy(birinciKattaAcText, birinciKattaAcTextEN);
		strcpy(ikinciKattaAcText, ikinciKattaAcTextEN);
		strcpy(birVeIkinciKattaAcText, birVeIkinciKattaAcTextEN);
		strcpy(tablaKapiAcSureText, tablaKapiAcSureTextEN);
		strcpy(yukariYavaslamaLimitiText, yukariYavaslamaLimitiTextEN);
		strcpy(devirmeYuruyusMenuText, devirmeYuruyusMenuTextEN);
		strcpy(devirmeAktifText, devirmeAktifTextEN);
		strcpy(yuruyusAktifText, yuruyusAktifTextEN);
		strcpy(devirmeYukariText, devirmeYukariTextEN);
		strcpy(yuruyusIleriText, yuruyusIleriTextEN);
		strcpy(devirmeAsagiSivicText, devirmeAsagiSivicTextEN);
		strcpy(yuruyusGeriSivicText, yuruyusGeriSivicTextEN);
		strcpy(yuruyusSecildiText, yuruyusSecildiTextEN);
		strcpy(devirmeSilindirTipiText, devirmeSilindirTipiTextEN);
		strcpy(tekTesirText, tekTesirTextEN);
		strcpy(ciftTesirText, ciftTesirTextEN);
		strcpy(platformSilindirTipiText, platformSilindirTipiTextEN);
		strcpy(asagiValfSureText, asagiValfSureTextEN);
		strcpy(devirmeYukariValfSureText, devirmeYukariValfSureTextEN);
		strcpy(ileriValfSureText, ileriValfSureTextEN);
		strcpy(devirmeAsagiValfSureText, devirmeAsagiValfSureTextEN);
		strcpy(geriValfSureText, geriValfSureTextEN);
		strcpy(calismaSuresiText, calismaSuresiTextEN);
		strcpy(calismaSayisiText, calismaSayisiTextEN);
		strcpy(enterlaSifirlaText, enterlaSifirlaTextEN);
		strcpy(dilSecimText, dilSecimTextEN);
		strcpy(secilenDilText, secilenDilTextEN);
		strcpy(menudenCikisText, menudenCikisTextEN);
		strcpy(enteraBasinizText, enteraBasinizTextEN);
		strcpy(hataKoduText, hataKoduTextEN);
	}*/
}

void hata2EEPROM(uint8_t hataKodu) {
	int checkVal = 0;
	for(int i=0; i<indeksSayisi; i++) {
		if(eepromData[eepromVal[i]] == 0) {
			eepromData[eepromVal[i]] = hataKodu;
			eepromFull[eepromVal[i]] = 2;
			break;
		}
		if(eepromData[indeksSayisi-1] != 0) {
			checkVal = 1;
			break;
		}
	}

	if(checkVal == 1) {
		for(int j = 0; j<indeksSayisi; j++) {
			if(eepromFull[eepromVal[j]] == 2) {
				eepromData[eepromVal[j]] = hataKodu;
				eepromFull[eepromVal[j]] = 0;
			}
			break;
		}
	}

	//char str[16];
	//sprintf(str, "%d", eepromData[37]);
	//uint8_t okunanVeri;
	HAL_I2C_Mem_Write(&hi2c1,0xA0,eepromHataBaslangic,indeksSayisi,&eepromData[eepromHataBaslangic],indeksSayisi,3000);
	HAL_Delay(5);
	//HAL_I2C_Mem_Read(&hi2c1, 0xA0, eepromHataBaslangic, 1, &okunanVeri, 1, 3000);
	//sprintf(str, "%d", okunanVeri);
	//lcd_print(1, 1, "ANA SAYFA       ");
	//lcd_print(2, 1, str);

}

void hataSifirla(void) {
	for(int i=0; i<indeksSayisi; i++) {
		eepromData[eepromVal[i]] = 0;
	}
}

void run_delay(void) {
	HAL_Delay(500);
}

void bekle(void) {
	timer1=millis;
    while((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin)==1)&&(millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol=1;
    }

    while((HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port,butonGeriIn_Pin)==1)&&(millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol=1;
    }

    while((HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1)&&(millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol=1;
    }

    while((HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1)&&(millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol=1;
    }

    while((HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==1)&&(millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol=1;
    }

    while((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port,kapi1AcButonIn_Pin)==0)&&(millis-timer1<1)){
    	butonKontrol=1;
    }

    while((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port,kapi2AcButonIn_Pin)==0)&&(millis-timer1<1)){
    	butonKontrol=1;
    }

    while((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port,kapiTablaAcButonIn_Pin)==0)&&(millis-timer1<1)){
    	butonKontrol=1;
    }

}

void i2cTest(void) {
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

void lcdupdate(uint8_t y) {
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
		lcd_print(1, 1, mainText);
		lcd_print(2, 1, mainText2);
	}
}

void eepromKontrol() {
	HAL_I2C_Mem_Read(&hi2c1,0xA0,0,63,eepromData,63,3000);
	HAL_Delay(1000);

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
	kapiTablaAcKonum = eepromData[34];
	calismaSayModu = eepromData[35];
	kapiAcTipi = eepromData[36];
	hataKayit1 = eepromData[37];
	hataKayit2 = eepromData[38];
	hataKayit3 = eepromData[39];
	hataKayit4 = eepromData[40];
	hataKayit5 = eepromData[41];
	hataKayit6 = eepromData[42];
	hataKayit7 = eepromData[43];
	hataKayit8 = eepromData[44];
	hataKayit9 = eepromData[45];
	hataKayit10 = eepromData[46];

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

	HAL_Delay(1000);
}

void mainTask(void *pvParameters) {
	while(1) {
		if((HAL_GPIO_ReadPin(butonIleriIn_GPIO_Port,butonIleriIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonGeriIn_GPIO_Port,butonGeriIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==0)&&(HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port,butonEnterIn_Pin)==0)&&(HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin)==1)&&(HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin)==1)&&(HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin)==1))
				   {
					   butonKontrol=0;
				   }

				  if(hafizaYaz==1){
					  while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
					  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY){

					  }
					  HAL_I2C_Mem_Write(&hi2c1,0xA0,0,63,eepromData,63,3000);
					  HAL_Delay(5);
					  hafizaYaz=0;
					  if(dilSecim==0){
						  lcd_print(2,1,"Data yazildi    ");
					  }
					  if(dilSecim==1){
						  lcd_print(2,1,"Data Wrote      ");
					  }
					  HAL_Delay(1000);
					  lcd_clear();
				  }

				  if((hafizaOku==0)&&(HAL_I2C_GetState(&hi2c1) == HAL_I2C_STATE_READY)){
					  if(ilkOkuma==0){
						  lcd_print(1,1,"   **EEPROM**   ");
						  if(dilSecim==0){
							  lcd_print(2,1,"Data Okunuyor...");
						  }
						  if(dilSecim==1){
							  lcd_print(2,1,"Data Reading... ");
						  }
						  HAL_Delay(1000);
						  while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
						  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY){
							  HAL_Delay(1000);
						  }
						  if(dilSecim==0){
							  lcd_print(2,1,"Data Okundu.    ");
						  }
						  if(dilSecim==1){
							  lcd_print(2,1,"Data Read.      ");
						  }
						  ilkOkuma=1;
					  }
					  else{
						  if(dilSecim==0){
							  lcd_print(2,1,"Deger Kaydedildi");
						  }
						  if(dilSecim==1){
							  lcd_print(2,1,"Value Saved     ");
						  }
						  lcd_clear();
					  }

					  eepromKontrol();
					  hafizaOku=1;
					  loadMenuTexts(dilSecim);
				  }

				  if((menuGiris==0)&&(mesajYazildi==0)&&(demoMode==0)){
					  lcd_clear();
					  HAL_Delay(10);
					  lcd_print(1, 1, mainText);
					  lcd_print(2, 1, mainText2);
					  mesajYazildi=1;
				  }

				  if ((menuGiris==0) && (HAL_GPIO_ReadPin(butonYukariIn_GPIO_Port,butonYukariIn_Pin)==1) && (HAL_GPIO_ReadPin(butonAsagiIn_GPIO_Port,butonAsagiIn_Pin)==1))
				  {
					  menuGiris=1;
					  lcd_clear();
				  }
				  if(menuGiris==1){
					  menu();
				  }
				  HAL_GPIO_TogglePin(cycleLed_GPIO_Port, cycleLed_Pin);

		/* GİRİLEN PARAMETRELERE GÖRE AYARLARIN YAPILMASI*/

				  if(HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin)==0 && hataVar==0){

					  stopVar=1;
				  }

				  else{
					  stopVar=0;
				  }

		/****************************************  BASINC SALTERI ********************************************/
				  if(basincSalteri==0){
				 		basincVar=1;
				 	}

					  if(basincSalteri==1)
					  {
						  if(HAL_GPIO_ReadPin(basincSalteriIn_GPIO_Port, basincSalteriIn_Pin)==0)
						  {
							  if(millis-timer5>=3){
								  basincVar=1;
							  }
						  }
						  else
						 	{
							  timer5=millis;
						  	  basincVar=0;
						 	}
					  }

				  /******** Bas gönder ***********/

				  if((calismaSekli==1)&&(yukarimotorcalisiyor==1)&&(devirmeYuruyusSecim==0)){

					  basgondercalisyukari=1;
				  }
				  else if(yukarimotorcalisiyor==0)

					  basgondercalisyukari=0;

				  if((calismaSekli==1)&&(asagivalfcalisiyor==1)&&(devirmeYuruyusSecim==0)){

					  basgondercalisasagi=1;
				  }
				  else if(asagivalfcalisiyor==0)
					  basgondercalisasagi=0;

				  /******** Kapı Secimleri ***********/

				  if(kapiSecimleri==0){

					  kapiSivicVar=1;
				  }

				  if(kapiSecimleri==1){

					  if(HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==0)
						  kapiSivicVar=1;
					  else
						  kapiSivicVar=0;
				  }

				  if(kapiSecimleri==2){

					  if(HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==0)
						  kapiSivicVar=1;
					  else
						  kapiSivicVar=0;
				  }

				  if(kapiSecimleri==3){

					  if((HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==0)&&(HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==0))
						  kapiSivicVar=1;
					  else
						  kapiSivicVar=0;
				  }

		/* PARAMETRELERE GÖRE ÇIKISLARIN AYARLANMASI*/
				/*MOTOR CALISIYOR*/
				  if(demoMode==0 && menuGiris==0){
				  if(((yukarimotorcalisiyor)||(devmotoryukaricalisiyor)||((asagivalfcalisiyor)&&(butonKontrol2==0)&&(platformSilindirTipi==1))||((devmotorasagicalisiyor)&&(devirmeSilindirTipi)==1))&&(stopVar)&&(kapiSivicVar))

				  {
					  HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_SET);
					  motorcalisiyor=1;
					  CalismaSayisiYukari=1;
				  }
				  else
				  {
					  HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
					  motorcalisiyor=0;
				  }

				  /*YUKARI ÇALISMA*/


				  if((menuGiris==0) && (stopVar) && (kapiSivicVar)																			/********* motor calısması ***********/
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
									&&(devasagivalfcalisiyor==0))
				  {
					  yukarimotorcalisiyor=1;
				  }
				  else
				  {
					  yukarimotorcalisiyor=0;
				  }

				  if((yukarimotorcalisiyor==1)&&(((HAL_GPIO_ReadPin(yukariYavaslamaLimitIn_GPIO_Port, yukariYavaslamaLimitIn_Pin)==1))&&(yukariYavasLimit))){	/* ikinci hız */

					  HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_SET);
				  }
				  else
					  HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);

				  if(yukarimotorcalisiyor && (devirmeYuruyusSecim==1 || devirmeYuruyusSecim==2 || platformSilindirTipi==1))

				  {
					  HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_SET);
					  yukarivalfcalisiyor=1;

				  }

				  // yukari valf timer calisması

				  if((yukarivalfcalisiyor==1)&&(((HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1)&&(basgondercalisyukari==0))||(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1))&&(stopVar)&&(kapiSivicVar)&&(basincVar)&&(butonKontrol3==0)){

					  timer2=millis;
					  butonKontrol3=1;
				  }

				  if((((millis-timer2 >= yukariValfTmr)&&(butonKontrol3==1))||((stopVar==0)||(kapiSivicVar==0)||(basincVar==0))))
				  {
					  HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
					  yukarivalfcalisiyor=0;
					  butonKontrol3=0;

				  }

				  //Ond safety

				  if(emniyetCercevesi==0){

					  cerceveVar=1;
				  }

				  if((emniyetCercevesi==1)&&(calismaSekli==0)&&(HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin)==0)&&(HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0)){

					  cerceveVar=1;
				  }
				  else if((emniyetCercevesi==1)&&(HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin)==1)&&(calismaSekli==0)){

					  cerceveVar=0;
				  }

				  if (emniyetCercevesi==1 && calismaSekli==1){
					  if(HAL_GPIO_ReadPin(emniyetCercevesiIn_GPIO_Port, emniyetCercevesiIn_Pin)==0){
						  cerceveVar=1;
					  }
					  else{
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
								   && (devasagivalfcalisiyor==0))
				  {
					  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_SET);
					  asagivalfcalisiyor=1;
					  CalismaSayisiAsagi=1;
					  cercevesasagicalisma=1;
				  }

				  // asagi valf timer calisması

				  if((asagivalfcalisiyor==1)&&(((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==1)&&(basgondercalisasagi==0))||((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)&&(altLimit)))&&(stopVar)&&(kapiSivicVar)&&(cerceveVar)&&(butonKontrol2==0)){

					  timer2=millis;
					  butonKontrol2=1;
				  }

				  if((((millis-timer2 >= asagiValfTmr)&&(butonKontrol2==1))||((stopVar==0)||(kapiSivicVar==0)||(cerceveVar==0))))
				  {
					  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
					  asagivalfcalisiyor=0;
					  butonKontrol2=0;

				  }

				  //yavaslama valf

				  if((asagivalfcalisiyor==1)&&(((HAL_GPIO_ReadPin(yavaslamaLimitIn_GPIO_Port, yavaslamaLimitIn_Pin)==0))&&(yavaslamaLimit))){	/* ikinci hız */

					  HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_SET);
				  }
				  else
					  HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);

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
						  &&(devasagivalfcalisiyor==0))

				  {
					  devmotoryukaricalisiyor=1;
				  }

				  else
					  devmotoryukaricalisiyor=0;

				  if(devmotoryukaricalisiyor==1){

					  HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_SET);
					  devyukarivalfcalisiyor=1;

				  }
				  // devirme yukari + yuruyus ileri valf timer calismasi

				  if((devyukarivalfcalisiyor==1)&&((HAL_GPIO_ReadPin(devYukariStartIn_GPIO_Port, devYukariStartIn_Pin)==1)||(HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==1))&&(stopVar)&&(kapiSivicVar)&&(butonKontrol4==0)){

					  timer2=millis;
					  butonKontrol4=1;
				  }

				  if((((millis-timer2 >= devirmeYukariIleriTmr)&&(butonKontrol4==1))||((stopVar==0)||(kapiSivicVar==0))))
				  {
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
						  && (devmotoryukaricalisiyor==0))

				  {
					   devmotorasagicalisiyor=1;
				  }

				  else
				  {
					 devmotorasagicalisiyor=0;
				  }

				  if(devmotorasagicalisiyor==1)
				  {
					   HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_SET);
					   devasagivalfcalisiyor=1;
				  }

				  //devirme asagi + geri valf timer calismasi

				  if((devasagivalfcalisiyor==1)&&((HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==1)||(HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin)==1))&&(stopVar)&&(kapiSivicVar)&&(butonKontrol5==0)){

					  timer2=millis;
					  butonKontrol5=1;
				  }

				  if((((millis-timer2 >= devirmeYukariIleriTmr)&&(butonKontrol5==1))||((stopVar==0)||(kapiSivicVar==0))))
				  {
					  HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
					  devasagivalfcalisiyor=0;
					  butonKontrol5=0;

				  }

				  // makine durum kontrolü

				  if(HAL_GPIO_ReadPin(motorOut_GPIO_Port, motorOut_Pin)==0
						  &&(HAL_GPIO_ReadPin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin)==0)
						  &&(HAL_GPIO_ReadPin(yukariValfOut_GPIO_Port, yukariValfOut_Pin)==0)
						  &&(HAL_GPIO_ReadPin(asagiValfOut_GPIO_Port, asagiValfOut_Pin)==0)
						  &&(HAL_GPIO_ReadPin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin)==0))

					  makineStop=1;
				  else
					  makineStop=0;


				  //kapi 1 kontrol

				  // kapi 1 prudhome

				  if((kapi1Tip==0)&&((kapiSecimleri==1)||(kapiSecimleri==3))
						  &&((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0 && (kapiAcTipi==1)))
						  &&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
						  &&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
						  &&(butonKontrol==0)
						  &&(makineStop==1))
				  {

					  kapi1prudhome=1;
					  timer = millis;
					  bekle();
				  }

				  if((millis-timer >= kapi1AcSure)||((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)||!(altLimit))||(makineStop==0))
				  {
					  kapi1prudhome=0;
				  }

				  // kapi 1 buton kontrol

				  if((kapi1Tip==1)&&((kapiSecimleri==1)||(kapiSecimleri==3))
						  &&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
						  &&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
						  &&((HAL_GPIO_ReadPin(kapi1AcButonIn_GPIO_Port, kapi1AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0 && (kapiAcTipi==1)))
						  &&(makineStop==1))
				  {
					  kapi1butonkontrol=1;
				  }

				  else
				  {
					  kapi1butonkontrol=0;
				  }

				  // kapi 1 pizzato

				  if((kapi1Tip==2)&&((kapiSecimleri==1)||(kapiSecimleri==3))
						  &&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
						  &&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
						  &&(makineStop==1))
				  {
					  kapi1pizzato=1;
				  }

				  else
				  {
					  kapi1pizzato=0;
				  }

				  // kapi 1 çıkış

				  if(kapi1butonkontrol==1 || kapi1pizzato==1 || kapi1prudhome==1)
				  {
					  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
				  }

				  else
					  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);

				  //kapi2 kontrol

				  // kapi 2 prudhome

				  if((kapi2Tip==0)&&((kapiSecimleri==1)||(kapiSecimleri==3))
						  &&((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0 && (kapiAcTipi==1)))
						  &&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
						  &&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
						  &&(makineStop==1)
						  &&(butonKontrol==0))
				  {

					  kapi2prudhome=1;
					  timer = millis;
					  bekle();
				  }

				  if((millis-timer >= kapi2AcSure) || (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)||(makineStop==0))
				  {
					  kapi2prudhome=0;
				  }

				  // kapi 2 buton kontrol

				  if((kapi2Tip==1)&&((kapiSecimleri==1)||(kapiSecimleri==3))
						  &&((HAL_GPIO_ReadPin(kapi2AcButonIn_GPIO_Port, kapi2AcButonIn_Pin)==0 && (kapiAcTipi==0))||(HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0 && (kapiAcTipi==1)))
						  &&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
						  &&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
						  &&(makineStop==1)
				  	  	  	  )
				  {
					  kapi2butonkontrol=1;
				  }
				  else
				  {
					  kapi2butonkontrol=0;
				  }

				  // kapi 2 pizzato

				  if((kapi2Tip==2)&&((kapiSecimleri==1)||(kapiSecimleri==3))
						  &&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
						  &&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
						  &&(makineStop==1)
				  	  	  	  )
				  {
					  kapi2pizzato=1;
				  }
				  else
				  {
					  kapi2pizzato=0;
				  }

				  // kapi 2 çıkış

				  if(kapi2butonkontrol==1 || kapi2pizzato==1 || kapi2prudhome==1)
				  {
					  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
				  }

				  else
					  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);



				  //   kapi tabla kontrol ***


				  if((kapiTablaAcKonum==0 || kapiTablaAcKonum==2)
						  &&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)||!(altLimit))
						  &&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0))

					  kapiTablaAcKonumKat1=1;
				  else
					  kapiTablaAcKonumKat1=0;

				  if((kapiTablaAcKonum==1 || kapiTablaAcKonum==2)
						  && (HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
					  	  &&(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0))
					  kapiTablaAcKonumKat2=1;
				  else
					  kapiTablaAcKonumKat2=0;

				  if(kapiTablaAcKonumKat1==1
						  && kapiAcTipi==1
					  	  && HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0)
				  {
					  kapiactablaesp1=1;
				  }
				  else
					  kapiactablaesp1=0;

				  if(kapiTablaAcKonumKat2==1
						  && kapiAcTipi==1
					  	  && HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==0)
				  {
					  kapiactablaesp2=1;
				  }
				  else
					  kapiactablaesp2=0;

				  // tabla kapısı prudhome

				  if((kapitablaTip==0)&&((kapiSecimleri==2)||(kapiSecimleri==3))
						  &&((kapiTablaAcKonumKat1==1)||(kapiTablaAcKonumKat2==1))
						  &&(((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin)==0)&&(kapiAcTipi==0))
						  ||(kapiactablaesp1)==1 || (kapiactablaesp2)==1)
						  &&(makineStop==1)
						  &&(butonKontrol==0))
				  {

					  kapiTablaprudhome=1;
					  timer = millis;
					  bekle();
				  }

				  if((millis-timer >= kapiTablaAcSure)||((kapiTablaAcKonumKat1==0)&&(kapiTablaAcKonumKat2==0))||(makineStop==0))
				  {
					  kapiTablaprudhome=0;
				  }

				  // tabla kapı buton kontrol

				  if((kapitablaTip==1)&&((kapiSecimleri==2)||(kapiSecimleri==3))
						  &&((kapiTablaAcKonumKat1==1)||(kapiTablaAcKonumKat2==1))
						  &&(((HAL_GPIO_ReadPin(kapiTablaAcButonIn_GPIO_Port, kapiTablaAcButonIn_Pin)==0)&&(kapiAcTipi==0))
						  ||(kapiactablaesp1)==1 || (kapiactablaesp2)==1)
						  &&(makineStop==1))
				  {
					  kapiTablabutonkontrol=1;
				  }

				  else
				  {
					  kapiTablabutonkontrol=0;
				  }

				  // tabla kapı pizzato

				  if((kapitablaTip==2)&&((kapiSecimleri==2)||(kapiSecimleri==3))
						  &&((kapiTablaAcKonumKat1==1)||(kapiTablaAcKonumKat2==1))
						  &&(makineStop==1))
				  {
					  kapiTablapizzato=1;
				  }

				  else //if((kapitablaTip==1)&&((kapiSecimleri==2)||(kapiSecimleri==3)))
				  {
					  kapiTablapizzato=0;
				  }

				  // kapi Tabla çıkış

				  if(kapiTablabutonkontrol==1 || kapiTablaprudhome==1 || kapiTablapizzato==1)
				  {
					  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
				  }

				  else
					  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);

				  /********************************* CALİSMA SAYISI KAYIT YERİ *************************************/

				  if(((CalismaSayisiYukari==1)&&(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)&&(altLimit==0)&&(makineStop==1))
						||((CalismaSayisiAsagi==1)&&((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)&&(altLimit))&&(makineStop==1))){

				  		calismaSayisi1=calismaSayisi1+1;
				  		if(calismaSayisi1>9){
				  		calismaSayisi1=0;
				  		calismaSayisi10=calismaSayisi10+1;
				  		}
				  		if(calismaSayisi10>9){
				  		calismaSayisi10=0;
				  		calismaSayisi100=calismaSayisi100+1;
				  		}
				  		if(calismaSayisi100>9){
				  		calismaSayisi100=0;
				  		calismaSayisi1000=calismaSayisi1000+1;
				  		}
				  		if(calismaSayisi1000>9){
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
				  	    ||HAL_GPIO_ReadPin(devAsagiStartIn_GPIO_Port, devAsagiStartIn_Pin)==0)){

				  		 startBasili=1;
				  }
				  else
				  	     startBasili=0;

				  if(startBasili && HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin)==1)
				  	{
				  		hataVar=1;
				  		hataKoduLcdGoster(1);
				  		acilstophatasi=1;
				  	}

				  else if(acilstophatasi && HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin)==0 && startBasili==0)
				  	 {
				  		acilstophatasi=0;
				  		lcdupdate(1);
				  	}

		/************************************ Emniyet Çerçevesi Hatasi ***************************************************/

				  if(cerceveVar==0 && (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0 || cercevesasagicalisma)&& (emniyetCercevesi==1))
				   {
				  		hataVar=1;
				  		hataKoduLcdGoster(2);
				  		emniyetCercevesihatasi=1;
				  	}
				  	else if(emniyetCercevesihatasi && cerceveVar==1 && asagivalfcalisiyor==0){
				  		emniyetCercevesihatasi=0;
				  		cercevesasagicalisma=0;
				  		lcdupdate(2);
				  	}

		/************************************ BASINC ASIRI YUK HATASI **************************************************/

				  	if(basincVar==0 && basincSalteri==1 && motorcalisiyor==1 && HAL_GPIO_ReadPin(basincSalteriIn_GPIO_Port, basincSalteriIn_Pin)==1)
				  	{
				  		hataVar=1;
				  		hataKoduLcdGoster(3);
				  		basinchatasi=1;
				  	}
				  	else if(basinchatasi && basincVar==1 && HAL_GPIO_ReadPin(yukariStartIn_GPIO_Port, yukariStartIn_Pin)==1){
				  		basinchatasi=0;
				  		lcdupdate(3);

				  	}
		/************************************ KAPI SİVİÇ HATASI **************************************************/
				  if((startBasili || HataMakineCalisiyorkapi) && HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==1 && (kapiSecimleri==1 || kapiSecimleri==3))
				  {
					  hataVar=1;
					  hataKoduLcdGoster(4);
					  katkapisivicihatasi=1;
				  }
				  else if (katkapisivicihatasi && makineStop && startBasili==0 && HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin)==0)
				  {
					  katkapisivicihatasi=0;
				  	  HataMakineCalisiyorkapi=0;
				  	  lcdupdate(4);
				  }

		/************************************ TABLA KAPI SİVİÇ HATASI **************************************************/

				  if((startBasili || HataMakineCalisiyortabla)&& HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==1 && (kapiSecimleri==1 || kapiSecimleri==3))
				  {
					  hataVar=1;
					  hataKoduLcdGoster(5);
					  tablakapisivicihatasi=1;
				  }
				  else if (tablakapisivicihatasi && makineStop && startBasili==0 && HAL_GPIO_ReadPin(tablaKapiSiviciIn_GPIO_Port, tablaKapiSiviciIn_Pin)==0 && makineStop==1)
				  {
					  tablakapisivicihatasi=0;
				  	  HataMakineCalisiyortabla=0;
				  	  lcdupdate(5);
				  }


		/************************************ MAX CALİSMA HATASI BASLANGIC ******************************************/

				   if((motorcalisiyor)||(asagivalfcalisiyor)||(devmotorasagicalisiyor))
				  	 {

			    	if(millis-timer4>=makineCalismaTmr)
				  	  {
				  		hataVar=1;
				  		hataKoduLcdGoster(6);
				  		maksimumcalismahatasi=1;
				  	  }
				    }

				   if(maksimumcalismahatasi && HAL_GPIO_ReadPin(butonEnterIn_GPIO_Port, butonEnterIn_Pin) && startBasili==0){

				  		maksimumcalismahatasi=0;
				  		lcdupdate(6);
				  	}

				  	if((yukarimotorcalisiyor==1)||(asagivalfcalisiyor==1)||(devmotoryukaricalisiyor==1)||(devmotorasagicalisiyor==1)){
				  		makineCalisiyor=0;
				  		HataMakineCalisiyorkapi=1;
				  		HataMakineCalisiyortabla=1;
				  	}
				  	else
				  	{
				  		makineCalisiyor=1;
				  		timer4=millis;
				  	}
		/*********************************** HATA YOKSA HATA VAR SIFIRLA **************************************************/
				  if(hataVar==1 && acilstophatasi==0 && emniyetCercevesihatasi==0 && basinchatasi==0
						  && katkapisivicihatasi==0 && tablakapisivicihatasi==0 && maksimumcalismahatasi==0){
					  hataVar=0;
					  lcdupdate(7);
				  }


		/************************************ HATA LCD GÖSTERME ************************************************************/

		} 		// aktif calisma son parantez.




				  // DEMO MOD BASLIYOR

				  // DEMO YUKARI CALISMA

				  if((demoMode==1)&&(stopVar)&&(menuGiris==0)){

					  if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==0)
						      && (demoAsagiCalis==0)
							  && (demoDevYukari==0)
							  && (demoDevAsagi==0)){
						  HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_SET);
						  demoYukariCalis=1;
					  }
					  else if(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1){
						  HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
						  demoYukariCalis=0;
					  }

					  // DEMO MOTOR CALISMASI

					  if((demoYukariCalis)||(demoDevYukari)||(demoDevAsagi)||(demoAsagiCalis)){

						  HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_SET);

					  }
					  else {

						  HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
					  }
					  if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
							  && (HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==0)
							  && (demoYukariCalis==0)
							  && (demoAsagiCalis==0)){


					  }

					  //DEVİRME YUKARI CALIS
					  if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
							  &&(HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==0)
							  &&(demoYukariCalis==0)
							  &&(demoAsagiCalis==0)
							  && (demoDevAsagi==0)){
						  HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_SET);
						  demoDevYukari=1;
					  }
					  else{
						  HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
						  demoDevYukari=0;
					  }

					  // DEVIRME ASAGI CALIS

					  if((HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
							  &&(HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin)==0)
							  &&(demoYukariCalis==0)
							  &&(demoDevYukari==0)
							  && (demoAsagiCalis==0)){
						  HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_SET);
						  demoDevAsagi=1;
					  }
					  else{
						  HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
						  demoDevAsagi=0;
					  }

					  // DEMO ASAGI CALISMA

					  if((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==0)
						      && (demoYukariCalis==0)
							  && (demoDevAsagi==0)
							  && (demoDevYukari==0)){
						  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_SET);
						  demoAsagiCalis=1;
						  demoCalismaSayisiYar=1;
					  }
					  else if ((HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)){
						  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
						  demoAsagiCalis=0;
					  }

					  if(HAL_GPIO_ReadPin(altLimitIn_GPIO_Port, altLimitIn_Pin)==1)
					  {

						  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
						  timer3 = millis;

					  }

					  if(millis-timer3 >= 5)
					  {
						  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
					  }

					  if(HAL_GPIO_ReadPin(ustLimitIn_GPIO_Port, ustLimitIn_Pin)==1)
					  {

						  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
						  timer3 = millis;

					  }

					  if(millis-timer3 >= 5)
					  {
						  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);

					  }
					  if((demoYukariCalis==1) && (demoCalismaSayisiYar==1)){
						  //mesajYazildi=0;
							calismaSayisi1=calismaSayisi1+1;
							if(calismaSayisi1>9){
								calismaSayisi1=0;
								calismaSayisi10=calismaSayisi10+1;
							}
							if(calismaSayisi10>9){
								calismaSayisi10=0;
								calismaSayisi100=calismaSayisi100+1;
							}
							if(calismaSayisi100>9){
								calismaSayisi100=0;
								calismaSayisi1000=calismaSayisi1000+1;
							}
							if(calismaSayisi1000>9){
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
					  if (menuGiris==0){
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
				  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void ledTask(void *pvParameters) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
}

void wifiTask(void *pvParameters) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_UART_Transmit(&huart1, (uint8_t *)"AT+CWMODE=1\r\n", strlen("AT+CWMODE=1\r\n"), HAL_MAX_DELAY);
    HAL_Delay(500);

    HAL_UART_Transmit(&huart1, (uint8_t *)"AT+CWJAP=\"iPhone SE (2nd generation)\",\"asdasd00991\"\r\n", strlen("AT+CWJAP=\"iPhone SE (2nd generation)\",\"asdasd00991\"\r\n"), HAL_MAX_DELAY);
    //HAL_UART_Transmit(&huart1, (uint8_t *)"AT+CWJAP=\"3Oda1Salon\",\"ucsalonbiroda\"\r\n", strlen("AT+CWJAP=\"3Oda1Salon\",\"ucsalonbiroda\"\r\n"), HAL_MAX_DELAY);
    HAL_Delay(2000);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);

    HAL_UART_Transmit(&huart1, (uint8_t *)"AT+CIPSTART=0,\"TCP\",\"yst.com.tr\",80\r\n", strlen("AT+CIPSTART=0,\"TCP\",\"yst.com.tr\",80\r\n"), HAL_MAX_DELAY);
    HAL_Delay(500);

    char requestBuffer[512];
    sprintf(requestBuffer, "GET /api/updateMachine2.php?MachineID=%s&acilStop1=%s HTTP/1.1\r\nHost: yst.com.tr\r\n\r\n",
            "12345", "12345");

    char requestLength[8];
    sprintf(requestLength, "%d", strlen(requestBuffer));

    HAL_UART_Transmit(&huart1, (uint8_t *)"AT+CIPSEND=0,", strlen("AT+CIPSEND=0,"), HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart1, (uint8_t *)requestLength, strlen(requestLength), HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart1, (uint8_t *)"\r\n", strlen("\r\n"), HAL_MAX_DELAY);
    HAL_Delay(500);

    HAL_UART_Transmit(&huart1, (uint8_t *)requestBuffer, strlen(requestBuffer), HAL_MAX_DELAY);
    HAL_Delay(500);

    char responseBuffer[256];
    memset(responseBuffer, 0, sizeof(responseBuffer));
    uint16_t responseLength = 0;
    while (responseLength < sizeof(responseBuffer) - 1)
    {
        uint16_t bytesRead = HAL_UART_Receive(&huart1, (uint8_t *)(responseBuffer + responseLength), sizeof(responseBuffer) - responseLength - 1, HAL_MAX_DELAY);
        responseLength += bytesRead;

        if (strstr(responseBuffer, "\r\n\r\n") != NULL)
        {
            break;
        }
    }

    if (strstr(responseBuffer, "Kayıt güncellendi.") != NULL)
    {
        // İşlem başarıyla tamamlandı
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
    }
    else if (strstr(responseBuffer, "Kayıt eklendi.") != NULL)
    {
        // İşlem başarıyla tamamlandı
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
    }
    else
    {
        // İşlem başarısız oldu, tekrar denemek için uygun bir if bloğu ekleyebilirsiniz

    }

    HAL_Delay(500);

    HAL_UART_Transmit(&huart1, (uint8_t *)"AT+CIPCLOSE=0\r\n", strlen("AT+CIPCLOSE=0\r\n"), HAL_MAX_DELAY);
    HAL_Delay(500);
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

}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}

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
