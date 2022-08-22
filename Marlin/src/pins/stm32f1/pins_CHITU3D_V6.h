/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Jbo  24C16 16 k-bit serial i2c eeprom 2 K octets
 * Jbo W25Q16 16 M-bit serial flash spi  2 M octets
 */
#pragma once

#define BOARD_INFO_NAME "Chitu3D V6"

#define Z2_ENABLE_PIN                       PF3
#define Z2_STEP_PIN                         PF5
#define Z2_DIR_PIN                          PF1

#ifndef FIL_RUNOUT2_PIN
  #define FIL_RUNOUT2_PIN                   PF13
#endif

#include "pins_CHITU3D_common.h"

// SPI 2
#define W25QXX_CS_PIN                       PB12
#define W25QXX_MOSI_PIN                     PB15
#define W25QXX_MISO_PIN                     PB14
#define W25QXX_SCK_PIN                      PB13

//
// 24C16 EEPROM
//
  #define IIC_BL24C16_EEPROM
  #define EEPROM_DEVICE_ADDRESS             0xA0
  #define IIC_EEPROM_SCL                    PG0
  #define IIC_EEPROM_SDA                    PG1
  #define IIC_EEPROM_WP                     PF12
  #define IIC_EEPROM_SIZE                  0x800  // 2Kb (24C16) car conflit avec SPI FLASH

//
// WIFI
//
#ifdef BLTOUCH_WIFISLOT
  #define SERVO0_PIN                        PB11 // for BLTOUCH
#else
  #define WFI_RX                            PB10  // USART3 TX
  #define WFI_TX                            PB11  // USART3 RX
  #define WFI_RTS                           PD12  // USART3 RTS
#endif

// not use									 PA2
// not use									 PA3
// not use									 PA4
//											 PA8	MAX6675 CS2
//											 PA9	MAX6675 CS1
// not use									PA10
// not use									PA11
// not use									PA13                  // Z stop +
// not use									PA14                  // Z stop -
// not use									 PB1
// not use									 PB2
//											 PB3	MAX6675 CLK
//											 PB6	TFT-LCD 7846-INT
// not use									 PC0
// not use									 PC1
// not use									 PC2
// not use									 PC3
// not use									 PC4
// not use									 PC5
// not use									 PC8
// not use									 PC9
// not use									PC10
// not use									PC11
// not use									PC12
// not use									PC14
// not use									PC15
//											 PD0	TFT-LCD D2
//											 PD1	TFT-LCD D3
// not use									 PD2
//											 PD4	TFT-LCD nOE
//											 PD5	TFT-LCD nWE
//											 PD8	TFT-LCD D13
//											 PD9	TFT-LCD D14
//											PD10	TFT-LCD D15
//											PD14	TFT-LCD D0
//											PD15	TFT-LCD D1
//											 PE7	TFT-LCD D4
//											 PE8	TFT-LCD D5
//											 PE9	TFT-LCD D6
//											PE10	TFT-LCD D7
//											PE11	TFT-LCD D8
//											PE12	TFT-LCD D9
//											PE13	TFT-LCD D10
//											PE14	TFT-LCD D11
//											PE15	TFT-LCD D12
//											 PF2	FIFO D2
//											 PF4	FIFO D4
//											 PF6	FIFO D6
//											 PF7	FIFO D7
//											 PF8	FIFO RCLK
//											 PF9	FIFO WEN
//											PF10	FIFO WRST
// not use									PF14
// not use									PF15
//											 PG2	POWER KEY
//											 PG3	RESET_INDICATOR
//											 PG4	ERROR_DETECT
//											 PG5	MAX6675_DAT1
//											 PG6	COOL_FAN2
//											 PG6	HOT_END2
//											 PG15	MAX6675 DAT2
