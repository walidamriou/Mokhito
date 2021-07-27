/**
 * @file main.cpp
 * @brief main cpp file for techometer atmega328p to generate data to uart usb
 *
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 07/26/2021
 * 
 */

#include <Arduino.h>

uint16_t i=1;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(i);
  i++;
  if(i==1400){
    i=1;
  }
  delay(200);
}