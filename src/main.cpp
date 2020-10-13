#include <Arduino.h>
/*
Description:  This is a simple example for the built-in watchdog.
License:      This project is licensed under the terms of the MIT license.
Github:       https://github.com/0N3IR0S/esp32Watchdog

Author:   Benjamin Buerge
Created:  13.10.2020
*/

// LIBRARIES
#include <esp_task_wdt.h>

// GLOBAL
#define WDT_TIMEOUT 3      // time after cpu will reset
int i = 0;                 // number of cycles
int lastMillis = millis(); // timer

// SETUP
void setup()
{
  // Serial Monitor
  Serial.begin(115200);
  Serial.println(F("Serial Monitor started"));

  // Watchdog timer
  esp_task_wdt_init(WDT_TIMEOUT, true); //enable panic so ESP32 restarts
  esp_task_wdt_add(NULL);               //add current thread to WDT watch
}

// MAIN LOOP
void loop()
{
  // reset WDT every 2s for 6 cycles
  if (millis() - lastMillis >= 2000 && i < 5)
  {
    // reset WDT
    esp_task_wdt_reset();
    Serial.println(F("WDT reset..."));

    // increment counter and reset timer
    i++;
    lastMillis = millis();

    // info last reset
    if (i == 5)
    {
      Serial.println(F("Last WDT reset happend, ESP32 should reboot in 3s!"));
    }
  }
}