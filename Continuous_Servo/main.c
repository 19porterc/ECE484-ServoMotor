#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "libContinuous/continuous.h"
#include "IO_MACROS.h"

int main(void) {
  CS_Setup();
  _delay_ms(1000);

  while (1) {
    set_speed(90);
    set_speed(0);
    set_speed(-90);
    set_speed(0);
  }
}
