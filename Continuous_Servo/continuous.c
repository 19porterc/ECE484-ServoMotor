#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "continuous.h"

// change these values based on your servo
#define MIN  1000
#define MAX  2000

//----- Functions -------------//
// Setup continuous servo.
void CS_Setup() {
  // continuous servo pin = output
  PinMode(CSP, Output);

  // continuous servo pin = 0
  DigitalWrite(CSP, Low);
}

// Set speed of Continuous Servo.
void set_speed(int speed) {
  speed = speed + 90;

  if (speed < 0) {
    speed = 0;
  } else if (speed > 180) {
    speed = 180;
  }

  // conversion from speed to PWM
  uint16_t pulse_width = (((MAX - MIN) / 180) * speed) + MIN;

  for (int i = 0; i < 45; i++) {
    DigitalWrite(CSP, High);
    _delay_us(pulse_width);
    DigitalWrite(CSP, Low);
    _delay_us(20000 - pulse_width);
  }
}
