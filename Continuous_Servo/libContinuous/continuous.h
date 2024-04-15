#ifndef CONTINUOUS_H_INCLUDED
#define CONTINUOUS_H_INCLUDED
/*
||
||  Filename:	 		continuous.h
||  Title: 			    Continuous Servo Driver
||  Author: 			Carl Porter III
||  Compiler:		 	AVR-GCC
||  Description: 
||	This library can control a continuous servo motor.
||  Can be modified to suit any continuous servo motor.
||
*/

//----- Headers ------------//
#include <inttypes.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#include "IO_Macros.h"
#include "continuous_settings.h"
//--------------------------//

//----- Prototypes ------------------------------------------------------------//
/*
||  This function gets the servo ready for use. It sets pin 9 on the Arduino as
||  an output pin and sets the servo motor to low.
*/
void CS_Setup();

/*
||  This function sets the speed of the servo based on the input of the user.
||  The valid range of input is from -90 to 90.
*/
void set_speed(int speed);

//-----------------------------------------------------------------------------//
#endif