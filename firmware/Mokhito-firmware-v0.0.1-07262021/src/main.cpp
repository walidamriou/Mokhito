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
uint32_t pin = 2;
uint32_t ontime,offtime,duty;
float freq,period;
void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop() {
  ontime = pulseIn(pin,HIGH);
  offtime = pulseIn(pin,LOW);
  period = ontime+offtime; 
  if(period>10000000){
    period=10000000;
  }else if(period<5000)
  {
    period=6250;
  }
  
  Serial.print(period);
  Serial.println(",");
}