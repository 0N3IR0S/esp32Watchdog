# esp32Watchdog
This is a simple example for the built-in watchdog.

### Description
A watchdog is used to reboot the cpu if it gets stuck somewhere longer than a certain amount of time.
The program will reset the watchdog five times, then never again. After three seconds the watchdog
comes into play and it will reboot the esp32.

### Environment
  hardware: Espressif ESP32 Dev Module
  IDE:      Platformio
  
### Installation
- clone the repository directly into vscode (recommended)
- download the repo as zip file.

### License
This project is licensed under the terms of the MIT license.
