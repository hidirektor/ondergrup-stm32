/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Process.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern CAN_HandleTypeDef hcan;

extern I2C_HandleTypeDef hi2c1;

extern TIM_HandleTypeDef htim1;

extern UART_HandleTypeDef huart1;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
void lcdUpdate(uint8_t);
void eepromKontrol(int);
uint8_t buttonCheck(void);
void bekle(void);
void i2cTest(void);

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define yukariYavaslamaLimitIn_Pin GPIO_PIN_13
#define yukariYavaslamaLimitIn_GPIO_Port GPIOC
#define yavaslamaLimitIn_Pin GPIO_PIN_14
#define yavaslamaLimitIn_GPIO_Port GPIOC
#define basincSalteriIn_Pin GPIO_PIN_15
#define basincSalteriIn_GPIO_Port GPIOC
#define emniyetCercevesiIn_Pin GPIO_PIN_0
#define emniyetCercevesiIn_GPIO_Port GPIOC
#define ustLimitIn_Pin GPIO_PIN_1
#define ustLimitIn_GPIO_Port GPIOC
#define altLimitIn_Pin GPIO_PIN_2
#define altLimitIn_GPIO_Port GPIOC
#define butonGeriIn_Pin GPIO_PIN_3
#define butonGeriIn_GPIO_Port GPIOC
#define butonIleriIn_Pin GPIO_PIN_0
#define butonIleriIn_GPIO_Port GPIOA
#define butonYukariIn_Pin GPIO_PIN_1
#define butonYukariIn_GPIO_Port GPIOA
#define butonAsagiIn_Pin GPIO_PIN_2
#define butonAsagiIn_GPIO_Port GPIOA
#define butonEnterIn_Pin GPIO_PIN_3
#define butonEnterIn_GPIO_Port GPIOA
#define buzzerOut_Pin GPIO_PIN_4
#define buzzerOut_GPIO_Port GPIOA
#define tablaKapiOut_Pin GPIO_PIN_5
#define tablaKapiOut_GPIO_Port GPIOA
#define kapi2Out_Pin GPIO_PIN_6
#define kapi2Out_GPIO_Port GPIOA
#define kapi1Out_Pin GPIO_PIN_7
#define kapi1Out_GPIO_Port GPIOA
#define devirmeAsagiGeriOut_Pin GPIO_PIN_4
#define devirmeAsagiGeriOut_GPIO_Port GPIOC
#define devirmeYukariIleriOut_Pin GPIO_PIN_5
#define devirmeYukariIleriOut_GPIO_Port GPIOC
#define yavaslamaValfOut_Pin GPIO_PIN_0
#define yavaslamaValfOut_GPIO_Port GPIOB
#define asagiValfOut_Pin GPIO_PIN_1
#define asagiValfOut_GPIO_Port GPIOB
#define yukariValfOut_Pin GPIO_PIN_2
#define yukariValfOut_GPIO_Port GPIOB
#define motorIkinciHizOut_Pin GPIO_PIN_10
#define motorIkinciHizOut_GPIO_Port GPIOB
#define motorOut_Pin GPIO_PIN_11
#define motorOut_GPIO_Port GPIOB
#define acilStop1In_Pin GPIO_PIN_12
#define acilStop1In_GPIO_Port GPIOB
#define yukariStartIn_Pin GPIO_PIN_13
#define yukariStartIn_GPIO_Port GPIOB
#define asagiStartIn_Pin GPIO_PIN_14
#define asagiStartIn_GPIO_Port GPIOB
#define devYukariStartIn_Pin GPIO_PIN_15
#define devYukariStartIn_GPIO_Port GPIOB
#define devAsagiStartIn_Pin GPIO_PIN_6
#define devAsagiStartIn_GPIO_Port GPIOC
#define kapi1AcButonIn_Pin GPIO_PIN_7
#define kapi1AcButonIn_GPIO_Port GPIOC
#define kapi2AcButonIn_Pin GPIO_PIN_8
#define kapi2AcButonIn_GPIO_Port GPIOC
#define kapiTablaAcButonIn_Pin GPIO_PIN_9
#define kapiTablaAcButonIn_GPIO_Port GPIOC
#define tablaKapiSiviciIn_Pin GPIO_PIN_8
#define tablaKapiSiviciIn_GPIO_Port GPIOA
#define kapiSiviciIn_Pin GPIO_PIN_15
#define kapiSiviciIn_GPIO_Port GPIOA
#define devirmeYukariLimitIn_Pin GPIO_PIN_10
#define devirmeYukariLimitIn_GPIO_Port GPIOC
#define devirmeAsagiLimitIn_Pin GPIO_PIN_11
#define devirmeAsagiLimitIn_GPIO_Port GPIOC
#define cycleLed_Pin GPIO_PIN_12
#define cycleLed_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
