/*
 * WifiConfig.h
 *
 *  Created on: Aug 10, 2024
 *      Author: hidirektor
 */

#ifndef INC_WIFICONFIG_H_
#define INC_WIFICONFIG_H_

#define	_WIFI_RX_SIZE					512
#define	_WIFI_RX_FOR_DATA_SIZE			1024
#define	_WIFI_TX_SIZE					256
#define	_WIFI_TASK_SIZE					512
#define _MAX_SEND_BYTES					2048
#define	_BANK_WIFI_BUTTONS				GPIOB
#define	_BUTTON_RST						GPIO_PIN_11
#define	_BUTTON_ENABLE					GPIO_PIN_6
#define	_WIFI_WAIT_TIME_LOW				1000
#define	_WIFI_WAIT_TIME_MED				5000
#define	_WIFI_WAIT_TIME_HIGH			15000
#define	_WIFI_WAIT_TIME_VERYHIGH		25000

#endif /* INC_WIFICONFIG_H_ */
