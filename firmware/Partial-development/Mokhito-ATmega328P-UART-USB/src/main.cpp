/**
 * @file main.cpp
 * @brief main cpp file for Mokhito atmega328p to generate data to uart usb
 *
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 07/26/2021
 * 
 */

#include <Arduino.h>

uint32_t i=7142; // 7142 for 1400 RPM and 10000000 for 1 RPM if poles is 6
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(i);
  Serial.print(",");
  i--;
  delay(200);
}