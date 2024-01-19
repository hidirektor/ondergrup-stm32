/*
 * Update.c
 *
 *  Created on: Dec 31, 2023
 *      Author: hidirektor
 */

#include "Update.h"

uint32_t calculateCRC32(uint8_t *buffer, size_t length) {
  uint32_t crc = 0xFFFFFFFF;

  for (size_t i = 0; i < length; i++)
  {
    crc ^= buffer[i];

    for (size_t j = 0; j < 8; j++)
    {
      crc = (crc & 1) ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;
    }
  }

  return crc ^ 0xFFFFFFFF;
}

void updateFirmware(UART_HandleTypeDef *huart1) {

    // ESP8266'ya AT komutları göndererek HTTP GET isteği yapın
    char command[100];
    sprintf(command, "AT+CIPSTART=\"TCP\",\"%s\",%d", "127.0.0.1", 3000);
    HAL_UART_Transmit(huart1, (uint8_t *)command, strlen(command), HAL_MAX_DELAY);

    // GET isteği için HTTP başlıkları
    char getRequest[200];
    sprintf(getRequest, "GET /firmware HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", "127.0.0.1");
    sprintf(command, "AT+CIPSEND=%d", strlen(getRequest));
    HAL_UART_Transmit(huart1, (uint8_t *)command, strlen(command), HAL_MAX_DELAY);
    HAL_UART_Transmit(huart1, (uint8_t *)getRequest, strlen(getRequest), HAL_MAX_DELAY);

    // Yanıtı almak için bir süre bekle
    HAL_Delay(5000);

    // Alınan yanıtı işle
    char receivedData[1024];
    memset(receivedData, 0, sizeof(receivedData)); // Null-terminate the buffer
    HAL_UART_Receive(huart1, (uint8_t *)receivedData, sizeof(receivedData) - 1, HAL_MAX_DELAY);

    HAL_Delay(500);

    // Bağlantıyı kapat
    char closeCommand[] = "AT+CIPCLOSE";
    HAL_UART_Transmit(huart1, (uint8_t *)closeCommand, strlen(closeCommand), HAL_MAX_DELAY);

    // Firmware dosyasının CRC32 değerini hesapla
    uint32_t calculatedCRC = calculateCRC32((uint8_t *)receivedData, strlen(receivedData));

    char *headerStart = strstr(receivedData, "x-crc32: ");
    if (headerStart != NULL) {
      uint32_t serverCRC = strtol(headerStart + 9, NULL, 16); // 9: strlen("x-crc32: ")

      // CRC değerlerini karşılaştır
      if (calculatedCRC == serverCRC) {
        HAL_FLASH_Unlock();
        uint32_t address = 0x08000000; // Başlangıç adresi

        // Program belleğe yaz
        for (uint32_t i = 0; i < strlen(receivedData); i += 4) {
          uint32_t data;
          memcpy(&data, &receivedData[i], sizeof(uint32_t));

          // Program belleğe yaz
          HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, data);

          // Bellek adresini güncelle
          address += 4;
        }

        HAL_FLASH_Lock();
        HAL_Delay(200);
        NVIC_SystemReset();
      } else {
        lcd_print(1, 1, "  DOSYA HATASI  ");
      }
    }
}

