#ifndef POSITIONAL_H_INCLUDED
#define POSITIONAL_H_INCLUDED
/*
||
||  Filename:	 		positional.h
||  Title: 			    Positional Servo Driver
||  Author: 			Carl Porter III
||  Compiler:		 	AVR-GCC
||  Description: 
||	This library can control a positional servo motor.
||  Can be modified to suit any positional servo motor.
||
*/

//----- Headers ------------//
#include <inttypes.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#include "IO_Macros.h"
#include "positional_settings.h"
//--------------------------//

//----- Prototypes ------------------------------------------------------------//
/*
||  This function gets the servo ready for use. It sets pin 9 on the Arduino as
||  an output pin and sets the servo motor to low.
*/
void PS_Setup();

/*
||  This function will center the servo at 90º when called.
*/
void PS_Center();

/*
||  This function sets the angle of the servo based on the input of the user.
||  The valid range of numbers is any angle from 0 to 180.
*/
void set_angle(int angle);

//-----------------------------------------------------------------------------//
#endif