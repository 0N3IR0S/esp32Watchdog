#include <Arduino.h>
/*
Description:  This is a simple example for the built-in watchdog.
Github:       https://github.com/0N3IR0S/esp32Watchdog

Author:   Benjamin Buerge
Created:  13.10.2020
*/

// LIBRARIES
#include <esp_task_wdt.h>

// GLOBAL
#define WDT_TIMEOUT 3 // time after cpu will reset
int i = 0;            // number of cycles
int last = millis();  // timer

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
  // resetting WDT every 2s, 5 times only
  if (millis() - last >= 2000 && i < 5)
  {
    Serial.println(F("Resetting WDT..."));
    esp_task_wdt_reset();
    last = millis();
    i++;
    if (i == 5)
    {
      Serial.println(F("Stopping WDT reset. CPU should reboot in 3s"));
    }
  }
}