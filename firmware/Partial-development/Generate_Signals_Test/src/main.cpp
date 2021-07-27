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

#define Signal_Test_pulse_width 10 // us
#define Signal_Test_pulse_space_1RPM 10000000 // us
#define Signal_Test_pulse_space_11RPM 909080 // us
#define Signal_Test_pulse_space_15RPM 666656 // us
#define Signal_Test_pulse_space_599RPM 16684 // us
#define Signal_Test_pulse_space_222RPM 45035 // us
#define Signal_Test_pulse_space_19RPM 526305 // us
#define Signal_Test_pulse_space_1350RPM 7397 // us

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
  delayMicroseconds(Signal_Test_pulse_width);                  // waits for a second
  digitalWrite(LEDpin, LOW);    // sets the LED off
  delayMicroseconds(Signal_Test_pulse_space_222RPM);  
}


 
