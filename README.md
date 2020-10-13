# ESP32 Watchdog
This is a simple example for the built-in watchdog.

### Description
A watchdog is used to reboot the CPU if it gets stuck somewhere longer than a certain amount of time.
The program will reset the watchdog five times, then never again. After three seconds the watchdog
comes into play and it will reboot the ESP32.

Your Serial Monitor should look like this:
```
Serial Monitor started
WDT reset...
WDT reset...
WDT reset...
WDT reset...
WDT reset...
Last WDT reset happend, ESP32 should reboot in 3s!
E (26128) task_wdt: Task watchdog got triggered. The following tasks did not reset the watchdog in time:
E (26128) task_wdt:  - loopTask (CPU 1)
E (26128) task_wdt: Tasks currently running:
E (26128) task_wdt: CPU 0: IDLE0
E (26128) task_wdt: CPU 1: loopTask
E (26128) task_wdt: Aborting.
abort() was called at PC 0x400d3803 on core 0

Backtrace: 0x4008b560:0x3ffbe170 0x4008b78d:0x3ffbe190 0x400d3803:0x3ffbe1b0 0x400845ed:0x3ffbe1d0 0x400e9157:0x3ffbbff0 0x400d3f93:0x3ffbc010 0x40089706:0x3ffbc030 0x40088215:0x3ffbc050

Rebooting...
ets Jun  8 2016 00:22:57

rst:0xc (SW_CPU_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0018,len:4
load:0x3fff001c,len:1044
load:0x40078000,len:8896
load:0x40080400,len:5828
entry 0x400806ac
Serial Monitor started
WDT reset...
```
### Environment
- Hardware: ESP32
- IDE: Platformio

### Installation
- clone the repository directly into vscode (recommended)
- download the repo as zip file.

### License
This project is licensed under the terms of the MIT license.
