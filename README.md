# Servo Motors
This project interfaces a Positional Servo Motor and a Continuous Servo Motor on an Arduino Uno. The main program files have been written in C along with the libraries for each servo motor. There are two main programs. See each folder for the servo you'd like to incorporate.

## Positional Servo Motor
### Introduction

A Positional Servo Motor is a type of motor that allows for positional control. These motors use pulse width modulation (PWM) to control their set angle. The lower end of the PWM signal, usually around 600, will set the servo motor to the 0º position. A higher PWM signal, the usual maximum of 2400, will set the servo to the 180º position. PWM signals and the degree of rotation have a linear relationship. So, any PWM signal set between 600 and 2400 will set the actuater of the servo proportionatly between 0º and 180º.

### Materials
* Arduino Uno R3
* Positional Servo Motor
* Jumper Wires

### Schematic
![Positional Servo Schematic. The Servo is plugged into the Arduino with the Signal wire going to pin 5, the Voltage wire going to the 5V pin, and the Ground wire going to the ground pin.](https://github.com/19porterc/ECE484-ServoMotor/Positional_Servo/Positional_Servo_Schematic.png?ra)
