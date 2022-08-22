<p align="center"><img src="buildroot/share/pixmaps/logo/marlin-outrun-nf-500.png" height="250" alt="MarlinFirmware's logo" /></p>

<h1 align="center">Marlin 3D Printer Firmware</h1>

<p align="center">
    <a href="/LICENSE"><img alt="GPL-V3.0 License" src="https://img.shields.io/github/license/marlinfirmware/marlin.svg"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/graphs/contributors"><img alt="Contributors" src="https://img.shields.io/github/contributors/marlinfirmware/marlin.svg"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/releases"><img alt="Last Release Date" src="https://img.shields.io/github/release-date/MarlinFirmware/Marlin"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/actions"><img alt="CI Status" src="https://github.com/MarlinFirmware/Marlin/actions/workflows/test-builds.yml/badge.svg"></a>
    <a href="https://github.com/sponsors/thinkyhead"><img alt="GitHub Sponsors" src="https://img.shields.io/github/sponsors/thinkyhead?color=db61a2"></a>
    <br />
    <a href="https://twitter.com/MarlinFirmware"><img alt="Follow MarlinFirmware on Twitter" src="https://img.shields.io/twitter/follow/MarlinFirmware?style=social&logo=twitter"></a>
</p>

Additional documentation can be found at the [Marlin Home Page](https://marlinfw.org/).
Please test this firmware and let us know if it misbehaves in any way. Volunteers are standing by!

## Marlin 2.1

Marlin 2.1 continues to support both 32-bit ARM and 8-bit AVR boards while adding support for up to 9 coordinated axes and to up to 8 extruders.

Download earlier versions of Marlin on the [Releases page](https://github.com/MarlinFirmware/Marlin/releases).

## Configuration pour Tronxy V5 and V6 cards

le BLTOUCH avec le connecteur WIFI n'est que pour les cartes V6  
  
J'ai modifier les fichiers  
        Marlin/Configuration.h  
        Marlin/Configuration_adv.h  
        Marlin/config.ini  
        Marlin/src/gcode/control/M993_M994.cpp  
        Marlin/src/libs/BL24CXX.cpp  
        Marlin/src/libs/BL24CXX.h  
        Marlin/src/libs/W25Qxx.cpp  
        Marlin/src/pins/stm32f1/pins_CHITU3D_V6.h  
        Marlin/src/pins/stm32f1/pins_CHITU3D_common.h  
        ini/features.ini  
Avec ces modifications, le BLTOUCH, les commandes M993, M993 i, M994 et M994 i fonctionnes  
  
Attention les fichiers dans le répertoire config ne sont pas opérationnels (c'est ceux fournis par Marlin et jamais validés)  

## Pré affichage sur le LDC de image du fichier a imprimer

J'ai modifier le fichier  
Marlin/src/lcd/tft/ui_480x320.cpp  
et tout est OK  

Je vous souhaite de bonnes impressions