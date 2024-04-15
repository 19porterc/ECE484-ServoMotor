#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

#include "positional.h"

// change these values based on your servo
#define MIN  600
#define MAX  2400

//----- Functions -------------//
// Setup Positional Servo.
void PS_Setup() {
  // positional servo pin = output
  PinMode(PSP, Output);

  // positional servo pin = 0
  DigitalWrite(PSP, Low);
}

// Center Positional Servo at 90 degrees.
void PS_Center() {
  DigitalWrite(PSP, High);
  for (int i = 0; i < 45; i++) {
    DigitalWrite(PSP, High);
    _delay_us((MIN + MAX) / 2);
    DigitalWrite(PSP, Low);
    _delay_us(20000 - ((MIN + MAX) / 2));
  }
}

// Set angle of Positional Servo.
void set_angle(int angle) {
  if (angle < 0) {
    angle = 0;
  } else if (angle > 180) {
    angle = 180;
  }

  // conversion from angle to PWM
  uint16_t pulse_width = (((MAX - MIN) / 180) * angle) + MIN;

  for (int i = 0; i < 45; i++) {
    DigitalWrite(PSP, High);
    _delay_us(pulse_width);
    DigitalWrite(PSP, Low);
    _delay_us(20000 - pulse_width);
  }
}
