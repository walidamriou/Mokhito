/*
 ********************************************************************
  ESP8266 PWM Generator Arduino
  Implement PWM generator for Espressif Systems ESP8266 boards by Arduino framework  

  Github: https://github.com/walidamriou/ESP32_PWM_Generator_Arduino
  Copyright © 2020 Walid Amriou
  Last update: October 2020
 ********************************************************************
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>

uint8_t LEDpin = 5; //5

void setup(){
  Serial.begin(115200);
    pinMode(LEDpin, OUTPUT);      // sets the digital pin as output

  //analogWriteFreq(100);
  //analogWriteRange(255);
}

void loop(){
  //analogWrite(LEDpin, 25);  /* set initial 10% duty cycle */
  digitalWrite(LEDpin, HIGH);   // sets the LED on
  delayMicroseconds(10);                  // waits for a second
  digitalWrite(LEDpin, LOW);    // sets the LED off
  delayMicroseconds(5990);   

}


 
