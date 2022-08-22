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
 */

#include "../../inc/MarlinConfig.h"

#if ALL(HAS_SPI_FLASH, SDSUPPORT, MARLIN_DEV_MODE)

#include "../gcode.h"
#include "../../sd/cardreader.h"
#include "../../libs/W25Qxx.h"    // SPI FLASH
#include "../../libs/BL24CXX.h"   // I2C EEPROM

/**
 * M993: Backup SPI Flash or I2C 24C16 to SD
 */
void GcodeSuite::M993() {
  if (parser.seen('I')) {
    if (MOTHERBOARD == BOARD_CHITU3D_V6) {
      if (!card.isMounted()) card.mount();
      char f_name[] = "24c16.bin";    // I2C EEPROM
      card.openFileWrite(f_name);
      if (!card.isFileOpen()) {
        SERIAL_ECHOLNPGM("Failed to open ", f_name, " to write.");
        return;
      }
      SERIAL_ECHOPGM("Save I2C 24C16");
      BL24CXX::init();
      uint8_t buff[0x100];
      uint16_t adr = 0;
      adr = 0;
      while (adr < 0x0800) {
        hal.watchdog_refresh();
        BL24CXX::read(adr, buff, 0x100);
        adr += 0x100;
        card.write(buff, 0x100);
        SERIAL_CHAR('.');
      }
      SERIAL_ECHOLNPGM("");
      SERIAL_ECHOLNPGM(" done");

      card.closefile();
    }
  } else {
    if (!card.isMounted()) card.mount();
    char fname[] = "spiflash.bin";
    card.openFileWrite(fname);
    if (!card.isFileOpen()) {
      SERIAL_ECHOLNPGM("Failed to open ", fname, " to write.");
      return;
    }

    uint8_t buf[1024];
    uint32_t addr = 0;
    W25QXX.init(SPI_QUARTER_SPEED);
    SERIAL_ECHOPGM("Save SPI Flash");
/*    SERIAL_CHAR('.');
    W25QXX.SPI_FLASH_BufferRead(buf, addr, 1024);
    SERIAL_CHAR('-');
    card.write(buf, 256);
    SERIAL_CHAR('+');*/
    while (addr < SPI_FLASH_SIZE) {
      hal.watchdog_refresh();	 		// jbo
      W25QXX.SPI_FLASH_BufferRead(buf, addr, COUNT(buf));
      addr += COUNT(buf);
      card.write(buf, COUNT(buf));
      if (addr % (COUNT(buf) * 10) == 0) SERIAL_CHAR('.');
    }
    SERIAL_ECHOLNPGM("");			// jbo
    SERIAL_ECHOLNPGM(" done");

    card.closefile();
  }
}

/**
 * M994: Load a backup from SD to SPI Flash
 */
void GcodeSuite::M994() {
  if (parser.seen('I')) {
    if (MOTHERBOARD == BOARD_CHITU3D_V6) {
      if (!card.isMounted()) card.mount();
      char f_name[] = "24c16.bin";
      card.openFileRead(f_name);
      if (!card.isFileOpen()) {
        SERIAL_ECHOLNPGM("Failed to open ", f_name, " to read.");
        return;
      }
      uint8_t buff[0x100];
      uint32_t adr = 0;
      BL24CXX::init();
      SERIAL_ECHOPGM("Load 24C16");
      while (adr < IIC_EEPROM_SIZE) {
        hal.watchdog_refresh();
        card.read(buff, 0x100);
        BL24CXX::write(adr, buff, 0x100);
        adr += 0x100;
        SERIAL_CHAR('.');
      }
      SERIAL_ECHOLNPGM("");
      SERIAL_ECHOLNPGM(" done");

      card.closefile();
	  }
  } else {
    if (!card.isMounted()) card.mount();

    char fname[] = "spiflash.bin";
    card.openFileRead(fname);
    if (!card.isFileOpen()) {
      SERIAL_ECHOLNPGM("Failed to open ", fname, " to read.");
      return;
    }

    uint8_t buf[1024];
    uint32_t addr = 0;
    W25QXX.init(SPI_QUARTER_SPEED);
    W25QXX.SPI_FLASH_BulkErase();
    SERIAL_ECHOPGM("Load SPI Flash");
    while (addr < SPI_FLASH_SIZE) {
      hal.watchdog_refresh();			// jbo
      card.read(buf, COUNT(buf));
      W25QXX.SPI_FLASH_BufferWrite(buf, addr, COUNT(buf));
      addr += COUNT(buf);
      if (addr % (COUNT(buf) * 10) == 0) SERIAL_CHAR('.');
    }
    SERIAL_ECHOLNPGM("");			// jbo
    SERIAL_ECHOLNPGM(" done");

    card.closefile();
  }
}

#endif // HAS_SPI_FLASH && SDSUPPORT && MARLIN_DEV_MODE
