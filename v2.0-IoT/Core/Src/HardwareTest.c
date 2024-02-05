/*
 * HardwareTest.c
 *
 *  Created on: Feb 5, 2024
 *      Author: hidirektor
 */

#include "HardwareTest.h"
#include "main.h"

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
