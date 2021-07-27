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

const byte interruptPin = 2;
void mokhito_count();

uint32_t mokhito_timer_count=0;
uint32_t mokhito_timer_count_uart_send=0;
uint32_t mokhito_timer_uart_send_count=0;

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), mokhito_count, RISING);
  
  // Timer 
    cli();
    TCCR1A = 0; 
    TCCR1B = 0;
    OCR1A = 1;  // = (target time / timer resolution) - 1 or 1 / 6.4e-5 - 1 = 15624
    //OCR1A = 15624>>1;  // divide by two >>EDIT added this line<<
    TCCR1B |= (1 << WGM12);// CTC mode on
    TCCR1B |= (1 << CS12);// Set CS10 and CS12 bits for 1024 prescaler:
    TIMSK1 |= (1 << OCIE1A);// timer compare intrupt
    sei();
}

ISR(TIMER1_COMPA_vect){          // timer compare interrupt service routine
  mokhito_timer_count++;   
  //mokhito_timer_uart_send_count++;
  //Serial.println(1,BIN);
}

void loop() {
}


void mokhito_count() {
  mokhito_timer_count_uart_send=mokhito_timer_count;
  mokhito_timer_count=0;
  Serial.println(mokhito_timer_count_uart_send);
  //Serial.println(",");
}
