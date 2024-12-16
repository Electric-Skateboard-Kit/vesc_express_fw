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

#include "hw_lectec.h"
#include "driver/gpio.h"
#include "driver/uart.h"

char HW_NAME[37] = "LECTEC";

void hw_init(void) {

		uart_driver_delete(UART_NUM_0);
		//gpio_reset_pin(LED_RGB_PIN);

	    gpio_config_t io_conf = {};
	    io_conf.intr_type = GPIO_INTR_DISABLE;
	    io_conf.mode = GPIO_MODE_OUTPUT;
	    io_conf.pull_down_en = 0;
	    io_conf.pull_up_en = 0;
	    gpio_config(&io_conf);

}

void generate_uuid(char* uuid_str, size_t len) {
    uint8_t mac[6];
    esp_efuse_mac_get_default(mac);

     snprintf(uuid_str, len, "LECTEC-%X%02X%02X",
             mac[3] & 0x0F, mac[4], mac[5]);
}
