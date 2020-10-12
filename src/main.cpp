#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println(F("Serial Monitor started"));
  // put your setup code here, to run once:
}

void loop() {
  Serial.println("Hello");
  delay(1000);
  // put your main code here, to run repeatedly:
}