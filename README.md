# Arduino Core for FoBE nRF52 Boards

[![Build Status](https://github.com/fobe-projects/fobe-nrf52-arduino/workflows/Build/badge.svg)](https://github.com/fobe-projects/fobe-nrf52-arduino/actions)

This repository contains the Arduino BSP for FoBE nRF52 series:

- [FoBE Quill nRF52840 Mesh](https://wiki.fobestudio.com/product/f1101)

## BSP Installation

There are two methods that you can use to install this BSP. We highly recommend the first option unless you wish to participate in active development of this codebase via Github.

### Recommended: FoBE nRF52 BSP via the Arduino Board Manager

 1. [Download and install the Arduino IDE](https://www.arduino.cc/en/Main/Software) (At least v1.6.12)
 2. Start the Arduino IDE
 3. Go into Preferences
 4. Add https://repo.fobestudio.com/arduino/package_fobe_index.json as an 'Additional Board Manager URL'
 5. Restart the Arduino IDE
 6. Open the Boards Manager from the Tools -> Board menu and install 'FoBE nRF52 Boards by FoBE Studio'
 7. Once the BSP is installed, select 'FoBE Quill nRF52840 Mesh' from the Tools -> Board menu, which will update your system config to use the right compiler and settings for the nRF52.

### Optional (Core Development): FoBE nRF52 BSP via git

 1. Install BSP via Board Manager as above to install compiler & tools.
 2. Delete the core folder `nrf52` installed by Board Manager in Adruino15, depending on your OS. It could be
  * macOS  : `~/Library/Arduino15/packages/fobe/hardware/nrf52`
  * Linux  : `~/.arduino15/packages/fobe/hardware/nrf52`
  * Windows: `%APPDATA%\Local\Arduino15\packages\fobe\hardware\nrf52`
 3. `cd <SKETCHBOOK>`, where `<SKETCHBOOK>` is your Arduino Sketch folder:
  * macOS  : `~/Documents/Arduino`
  * Linux  : `~/Arduino`
  * Windows: `~/Documents/Arduino`
 4. Create a folder named `hardware/fobe`, if it does not exist, and change directories to it
 5. Clone this repo & its submodules:

   ```
   git clone https://github.com/fobe-projects/fobe_nrf52_arduino.git
   cd fobe_nrf52_arduino
   git submodule update --init
   ```
   
 6. Restart the Arduino IDE
 7. Once the BSP is installed, select 'FoBE Quill nRF52840 Mesh' from the Tools -> Board menu, which will update your system config to use the right compiler and settings for the nRF52.

### Adafruit's nrfutil tools

[adafruit-nrfutil](https://github.com/adafruit/Adafruit_nRF52_nrfutil) (derived from Nordic [pc-nrfutil](https://github.com/NordicSemiconductor/pc-nrfutil)) is needed to upload sketch via serial port.

- For Windows and macOS, pre-built executable binaries are included in the BSP at `tools/adafruit-nrfutil/`. It should work out of the box.
- Linux user need to run follow command to install it from PyPi

```
$ pip3 install adafruit-nrfutil --user
```

## Bootloader

Bootloader can be updated via UF2 file or DFU if already existed. Or flash on new blank chip using following guide

### Update Bootloader with UF2 ( nRF52840 only and require 0.4.0+ )

This only works with nRF52840 and require existing bootloader version is at least 0.4.0:

- Quickly doulbe tap reset button to put your board in to bootloader mode. A mass storage device i.e `FoBE Boot` will appear
- Download latest UF2 for your board i.e `update-{BOARD}-{version}_nosd.uf2` from [fobe-nrf52-bootloader release page](https://github.com/fobe-projects/fobe_nrf52_bootloader/releases)
- Drap and drop the UF2 file into `FoBE Boot` drive to perform update then wait until the board reset.x

### Update Bootloader with DFU

To upgrade to the latest Bootloader + Softdevice using the serial port within Arduino IDE.

- Select `Tools > Board > FoBE Quill nRF52840 Mesh`
- Select `Tools > Programmer > Bootloader DFU for nRF52`
- Select `Tools > Burn Bootloader`
- **WAIT** until the process complete ~30 seconds

**Note: close the Serial Monitor before you click "Burn Bootloader". Afterwards, you shouldn't close the Arduino IDE, unplug the Board, launch Serial Monitor etc ... to abort the process. There is a high chance it will brick your device! Do this with care and caution.**

### Burning new Bootloader

To burn the bootloader from within the Arduino IDE, you will need the following tools installed
on your system and available in the system path:

- Segger [JLink Software and Documentation Pack](https://www.segger.com/downloads/jlink)
- Nordic [nRF5x Command Line Tools](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Command-Line-Tools)

Check to make sure you can run `nrfjprog` from your terminal/command prompt

**macOS Note** At present, you will need to create a symlink in `/usr/local/bin` to the
`nrfjprog` tool wherever you have added it. You can run the following command, for example:

```
$ ln -s $HOME/prog/nordic/nrfjprog/nrfjprog /usr/local/bin/nrfjprog
```

Once the tools above have been installed and added to your system path, from the Arduino IDE:

- Select `Tools > Board > FoBE Quill nRF52840 Mesh`
- Select `Tools > Programmer > J-Link for nRF52`
- Select `Tools > Burn Bootloader` with the board and J-Link connected

If you wish to modify bootloader to your own need, check out its repo here [fobe-nrf52-bootloader](https://github.com/fobe-projects/fobe_nrf52_bootloader)

#### Manually Burning the Bootloader via nrfjprog

The bootloader hex file can be found at `bin/bootloader` run the command as follows:

```
$ nrfjprog -e -f nrf52
$ nrfjprog --program quill_nrf52840_bootloader.hex -f nrf52
$ nrfjprog --reset -f nrf52
```

## Credits

This core is based on [Arduino-nRF5](https://github.com/sandeepmistry/arduino-nRF5) by Sandeep Mistry,
which in turn is based on the [Arduino SAMD Core](https://github.com/arduino/ArduinoCore-samd).

The following libraries are used:

- [FreeRTOS](https://www.freertos.org/) as operating system
- [LittleFS](https://github.com/ARMmbed/littlefs) for internal file system
- [nrfx](https://github.com/NordicSemiconductor/nrfx) for peripherals driver
- [TinyUSB](https://github.com/hathach/tinyusb) as usb stack
