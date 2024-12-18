/*
	Copyright 2022 Benjamin Vedder	benjamin@vedder.se

	This file is part of the VESC firmware.

	The VESC firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The VESC firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#ifndef MAIN_HWCONF_TRAMPA_HW_XP_T_H_
#define MAIN_HWCONF_TRAMPA_HW_XP_T_H_

#include "driver/gpio.h"
#include "esp_mac.h"

extern char* HW_NAME;
#define HW_NO_UART

#define HW_INIT_HOOK()				hw_init()

// CAN
#define CAN_TX_GPIO_NUM				1
#define CAN_RX_GPIO_NUM				0

// NAND-memory
#define NAND_PIN_MOSI				5
#define NAND_PIN_MISO               6
#define NAND_PIN_SCK				4
#define NAND_PIN_CS					3  //7
#define FLASH_FREQ_KHZ              4000

// UART
#define UART_NUM					0
#define UART_BAUDRATE				115200
#define UART_TX						21
#define UART_RX						20

// Functions
void hw_init(void);
char* generate_hw_name();
char* generate_display_name();

#endif /* MAIN_HWCONF_TRAMPA_HW_XP_T_H_ */
