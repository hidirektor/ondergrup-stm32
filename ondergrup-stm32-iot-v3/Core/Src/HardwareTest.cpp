/*
 * HardwareTest.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


#include "HardwareTest.h"
#include "main.h"

void HardwareTest::i2cTest() {
    hi2c1.Instance->CR1 &= ~(1 << 0);
    HAL_I2C_DeInit(&hi2c1);

    initGPIO();

    setPinHigh(GPIOB, GPIO_PIN_6);
    setPinHigh(GPIOB, GPIO_PIN_7);

    HAL_Delay(10);
    waitForPinHigh(GPIOB, GPIO_PIN_6);
    waitForPinHigh(GPIOB, GPIO_PIN_7);

    setPinLow(GPIOB, GPIO_PIN_7);
    HAL_Delay(10);
    waitForPinLow(GPIOB, GPIO_PIN_7);

    setPinLow(GPIOB, GPIO_PIN_6);
    HAL_Delay(10);
    waitForPinLow(GPIOB, GPIO_PIN_6);

    setPinHigh(GPIOB, GPIO_PIN_6);
    HAL_Delay(10);
    waitForPinHigh(GPIOB, GPIO_PIN_6);

    setPinHigh(GPIOB, GPIO_PIN_7);
    HAL_Delay(10);
    waitForPinHigh(GPIOB, GPIO_PIN_7);

    deinitGPIO();
    resetI2C();
}

void HardwareTest::initGPIO() {
    GPIO_InitTypeDef strutturaGPIO = {0};
    strutturaGPIO.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    strutturaGPIO.Mode = GPIO_MODE_OUTPUT_OD;
    strutturaGPIO.Pull = GPIO_PULLUP;
    strutturaGPIO.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOB, &strutturaGPIO);
}

void HardwareTest::setPinHigh(GPIO_TypeDef* port, uint16_t pin) {
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

void HardwareTest::setPinLow(GPIO_TypeDef* port, uint16_t pin) {
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

void HardwareTest::waitForPinHigh(GPIO_TypeDef* port, uint16_t pin) {
    while (HAL_GPIO_ReadPin(port, pin) != GPIO_PIN_SET) {}
}

void HardwareTest::waitForPinLow(GPIO_TypeDef* port, uint16_t pin) {
    while (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET) {}
}

void HardwareTest::deinitGPIO() {
    GPIO_InitTypeDef strutturaGPIO = {0};
    strutturaGPIO.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    strutturaGPIO.Mode = GPIO_MODE_AF_OD;
    strutturaGPIO.Pull = GPIO_PULLUP;
    strutturaGPIO.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOB, &strutturaGPIO);
}

void HardwareTest::resetI2C() {
    hi2c1.Instance->CR1 |= 1 << 15;
    hi2c1.Instance->CR1 &= ~(1 << 15);
    hi2c1.Instance->CR1 |= 1 << 0;
    HAL_I2C_Init(&hi2c1);
}
