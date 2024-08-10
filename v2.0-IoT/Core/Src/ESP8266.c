#include "ESP8266.h"

#include "SystemDefaults.h"
#include "GlobalVariables.h"
#include "Flash.h"

void ESP8266_Init(UART_HandleTypeDef *huart1, const char *wifiSS, const char *wifiPA) {
	sprintf(bufferTX, "AT+RESTORE\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(1000);

	sprintf(bufferTX, "AT+RST\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(1000);

	sprintf(bufferTX, "AT\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);

	sprintf(bufferTX, "AT+CWMODE=1\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);

	char str[100];
	strcpy(str, "AT+CWJAP_DEF=\"");
	strcat(str, wifiSS);
	strcat(str, "\",\"");
	strcat(str, wifiPA);
	strcat(str, "\"\r\n");
	sprintf(bufferTX, "%s", str);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);
}

void ESP8266_Init_AP(UART_HandleTypeDef *huart1) {
	sprintf(bufferTX, "AT+RESTORE\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(1000);

	sprintf(bufferTX, "AT+RST\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(1000);

	sprintf(bufferTX, "AT\r\n");
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);

    // SoftAP + Client
    sprintf(bufferTX, "AT+CWMODE=2\r\n");
    HAL_UART_Transmit_IT(huart1, (uint8_t *)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    //AP Name
    sprintf(bufferTX, "AT+CWSAP=\"%s\",\"%s\",5,3\r\n", apSSID, apPassword);
    HAL_UART_Transmit_IT(huart1, (uint8_t *)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);
}

void connectWifiNetwork(UART_HandleTypeDef *huart1, const char *wifiSS, const char *wifiPA) {
	char str[100];
	strcpy(str, "AT+CWJAP=\"");
	strcat(str, wifiSS);
	strcat(str, "\",\"");
	strcat(str, wifiPA);
	strcat(str, "\"\r\n");
	sprintf(bufferTX, "%s", str);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(2000);
}

void startWebServer(UART_HandleTypeDef *huart1) {
    // Start the TCP on 2805
    sprintf(bufferTX, "AT+CIPMUX=1\r\n");
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(2000);
    sprintf(bufferTX, "AT+CIPSERVER=1,2805\r\n");
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    sprintf(bufferTX, "AT+CIPSEND=0,50");
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    sprintf(bufferTX, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from ESP8266 AP mode!");
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    sprintf(bufferTX, "AT+CIPCLOSE=0");
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(2000);
}

void sendMachineData(UART_HandleTypeDef *huart1, const char *machineID, const char *wifiSSID, const char *wifiPass, const char *machineData) {
	char local_txA[1500];
	char local_txB[50];
	int len;

	char subMachineID[13];
	strncpy(subMachineID, machineID, 12);
	subMachineID[12] = '\0';

	sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
	HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
	HAL_Delay(1000);

	sprintf(local_txA,
	    "GET /api/v2/machine/updateMachineRaw?machineID=%s&wifiSSID=%s&wifiPass=%s&devirmeYuruyusSecim=%d&calismaSekli=%d&emniyetCercevesi=%d&yavaslamaLimit=%d&altLimit=%d&kapiTablaAcKonum=%d&basincSalteri=%d&kapiSecimleri=%d&kapiAcTipi=%d&kapi1Tip=%d&kapi1AcSure=%d&kapi2Tip=%d&kapi2AcSure=%d&kapitablaTip=%d&kapiTablaAcSure=%d&yukariYavasLimit=%d&devirmeYukariIleriLimit=%d&devirmeAsagiGeriLimit=%d&devirmeSilindirTipi=%d&platformSilindirTipi=%d&yukariValfTmr=%d&asagiValfTmr=%d&devirmeYukariIleriTmr=%d&devirmeAsagiGeriTmr=%d&makineCalismaTmr=%d&buzzer=%d&demoMode=%d&calismaSayisi=%d&calismaSayisiDemo=%d&dilSecim=%d&eepromData38=%d&eepromData39=%d&eepromData40=%d&eepromData41=%d&eepromData42=%d&eepromData43=%d&eepromData44=%d&eepromData45=%d&eepromData46=%d&eepromData47=%d&lcdBacklightSure=%d HTTP/1.0\r\nHost: %s\r\n\r\n",
	    subMachineID, wifiSSID, wifiPass, devirmeYuruyusSecim, calismaSekli, emniyetCercevesi,
	    yavaslamaLimit, altLimit, kapiTablaAcKonum, basincSalteri, kapiSecimleri, kapiAcTipi, kapi1Tip, kapi1AcSure,
	    kapi2Tip, kapi2AcSure, kapitablaTip, kapiTablaAcSure, yukariYavasLimit, devirmeYukariIleriLimit, devirmeAsagiGeriLimit,
	    devirmeSilindirTipi, platformSilindirTipi, yukariValfTmr, asagiValfTmr, devirmeYukariIleriTmr, devirmeAsagiGeriTmr,
	    makineCalismaTmr, buzzer, demoMode, calismaSayisi, calismaSayisiDemo, dilSecim, eepromData[38], eepromData[39],
	    eepromData[40], eepromData[41], eepromData[42], eepromData[43], eepromData[44], eepromData[45],
	    eepromData[46], eepromData[47], lcdBacklightSure, mainServerWithPort);

	len = strlen(local_txA);
	sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
	HAL_Delay(2000);

	HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txA, strlen(local_txA));
	HAL_Delay(2000);
}

void sendMachineDataDemo(UART_HandleTypeDef *huart1, const char *machineID, const char *wifiSSID, const char *wifiPass, const char *machineData) {
    char bufferTX[4000];
    char local_txB[50];
    char json_data[2000];
    int len;

    // JSON verisini manuel olarak oluşturma
    snprintf(json_data, sizeof(json_data),
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

    sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(4000);

    snprintf(bufferTX, sizeof(bufferTX),
             "POST /api/v2/machine/updateMachineData HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Content-Type: application/json\r\n"
             "Content-Length: %d\r\n\r\n"
             "%s",
             mainServerWithPort, strlen(json_data), json_data);
    len = strlen(bufferTX);
    sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

    HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
    HAL_Delay(4000);

    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(15000);
}

int checkMachineID(UART_HandleTypeDef *huart1, const char *machineID) {
    char local_txA[1000];
    char local_txB[50];
    int len;

    char bufferRX[1500];

    char subMachineID[13];
    strncpy(subMachineID, machineID, 12);
    subMachineID[12] = '\0';

    sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
    HAL_UART_Transmit_IT(huart1, (uint8_t*) bufferTX, strlen(bufferTX));
    HAL_Delay(1000);

    sprintf(local_txA,
            "GET /api/v2/machine/checkMachineIDRaw?machineID=%s HTTP/1.0\r\nHost: %s\r\n\r\n", subMachineID, mainServerWithPort);

    len = strlen(local_txA);
    sprintf(local_txB, "AT+CIPSEND=%d\r\n", len);

    HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txB, strlen(local_txB));
    HAL_Delay(2000);

    HAL_UART_Transmit_IT(huart1, (uint8_t*) local_txA, strlen(local_txA));
    HAL_Delay(2000);

    HAL_UART_Receive_IT(huart1, bufferRX, sizeof(bufferRX));
    HAL_Delay(5000);

    // HTTP yanıt kodunu kontrol et
    if (strstr(bufferRX, "HTTP/1.1 200 OK")) {
        return 1;  // Başarılı
    } else {
        return 0;  // Başarısız
    }
}

void checkForUpdates(UART_HandleTypeDef *huart, const char *currentVersion) {
    char checkUpdateCommand[150];
    sprintf(checkUpdateCommand, "GET /api/v2/updateChecker/checkUpdatesRaw?currentVersion=%s HTTP/1.0\r\nHost: %s\r\n\r\n", currentVersion, mainServerWithPort);

    // ESP8266 AT komutları ile sunucuya bağlan
    sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"%s\",3000\r\n", mainServer);
    HAL_UART_Transmit_IT(huart, (uint8_t*)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    // Güncelleme kontrol isteğini gönder
    sprintf(bufferTX, "AT+CIPSEND=%d\r\n", strlen(checkUpdateCommand));
    HAL_UART_Transmit_IT(huart, (uint8_t*)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);
    HAL_UART_Transmit_IT(huart, (uint8_t*)checkUpdateCommand, strlen(checkUpdateCommand));
    HAL_Delay(5000);

    // Cevabı al ve işle
    HAL_UART_Receive_IT(huart, bufferRX, sizeof(bufferRX));
    HAL_Delay(5000);

    // Gelen veriyi işleyin ve güncelleme var mı kontrol edin
    if (strstr(bufferRX, "HTTP/1.1 200 OK")) {
        // Yanıt başarılı, güncelleme bilgilerini kontrol et
        if (strstr(bufferRX, "\"updateAvailable\":true")) {
            lcd_print(1, 1, "New Update Available");
            HAL_Delay(2000);
            lcd_clear();
            //downloadNewVersion(huart, "2.0.0");  // Versiyon numarasını dinamik olarak belirleyebilirsiniz
        } else {
            lcd_print(1, 1, "No Update Available");
            HAL_Delay(2000);
            lcd_clear();
        }
    } else {
        // Yanıt başarısız, hata mesajı göster
        lcd_print(1, 1, "Update Check Failed");
        HAL_Delay(2000);
        lcd_clear();
    }
}

void downloadNewVersion(UART_HandleTypeDef *huart, const char *versionCode) {
    char downloadCommand[150];
    sprintf(downloadCommand, "GET /api/v2/updateChecker/downloadNewVersionRaw?versionCode=%s HTTP/1.0\r\nHost: 85.95.231.92:3000\r\n\r\n", versionCode);

    // Sunucuya bağlan
    sprintf(bufferTX, "AT+CIPSTART=\"TCP\",\"85.95.231.92\",3000\r\n");
    HAL_UART_Transmit_IT(huart, (uint8_t*)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);

    // İndirme isteğini gönder
    sprintf(bufferTX, "AT+CIPSEND=%d\r\n", strlen(downloadCommand));
    HAL_UART_Transmit_IT(huart, (uint8_t*)bufferTX, strlen(bufferTX));
    HAL_Delay(2000);
    HAL_UART_Transmit_IT(huart, (uint8_t*)downloadCommand, strlen(downloadCommand));
    HAL_Delay(5000);

    // Cevabı al ve .hex dosyasını indir
    HAL_UART_Receive_IT(huart, bufferRX, sizeof(bufferRX));
    HAL_Delay(5000);

    // Burada .hex dosyasını alıp veriyi bir buffer'a saklamalısınız
    uint32_t receivedData[1024]; // Bu buffer'ı gelen verinin büyüklüğüne göre ayarlamalısınız.
    int dataSize = 0; // Gelen verinin büyüklüğü burada tutulacak

    // bufferRX verisini parse et ve receivedData'ya aktar
    parseHexDataToBuffer(bufferRX, receivedData, &dataSize);

    // İndirilen veriyi flash belleğe yazma işlemi
    lcd_print(1, 1, "Writing to Flash...");
    HAL_Delay(2000);

    writeFlash(receivedData, dataSize);
}


void parseHexDataToBuffer(char *bufferRX, uint32_t *receivedData, int *dataSize) {
    char *line = strtok(bufferRX, "\r\n");  // Gelen veriyi satır satır ayır
    *dataSize = 0;

    while (line != NULL) {
        // Her satır bir Intel HEX formatı satırı ise (genellikle ":" ile başlar)
        if (line[0] == ':') {
            // Veri uzunluğu
            int byteCount = strtol(&line[1], NULL, 16);

            // Veri alanı başlangıç adresi
            int address = strtol(&line[3], NULL, 16);

            // Kayıt türü (00 - Veri, 01 - Dosya sonu vb.)
            int recordType = strtol(&line[7], NULL, 16);

            // Eğer kayıt türü 00 ise (veri satırı)
            if (recordType == 0) {
                for (int i = 0; i < byteCount; i++) {
                    // Her bir byte'ı al ve 32-bit'e dönüştür
                    char byteStr[3];
                    byteStr[0] = line[9 + i * 2];
                    byteStr[1] = line[9 + i * 2 + 1];
                    byteStr[2] = '\0';

                    uint32_t dataByte = strtol(byteStr, NULL, 16);

                    // Veri alanını 4 byte'lık bloklar halinde doldur
                    if (i % 4 == 0) {
                        receivedData[*dataSize] = 0;
                    }

                    receivedData[*dataSize] |= dataByte << ((i % 4) * 8);

                    if (i % 4 == 3) {
                        (*dataSize)++;
                    }
                }
            }
        }

        // Bir sonraki satıra geç
        line = strtok(NULL, "\r\n");
    }
}
