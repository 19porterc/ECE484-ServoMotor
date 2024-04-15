#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "libPositional/positional.h"
#include "IO_MACROS.h"

int main(void) {
  PS_Setup();
  PS_Center();
  _delay_ms(1000);
  
  while (1) {
    set_angle(0);
    _delay_ms(2000);

    set_angle(60);
    _delay_ms(2000);

    set_angle(120);
    _delay_ms(2000);

    set_angle(180);
    _delay_ms(2000);
  }
}
