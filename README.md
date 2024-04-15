# Servo Motors
This project interfaces a Positional Servo Motor and a Continuous Servo Motor on an Arduino Uno. The main program files have been written in C along with the libraries for each servo motor. There are two main programs. See each folder for the servo you'd like to incorporate.

## Positional Servo Motor
### Introduction
A Positional Servo Motor is a type of motor that allows for positional control. These motors use pulse width modulation (PWM) to control their set angle. The lower end of the PWM signal, usually around 600, will set the servo motor to the 0º position. A higher PWM signal, the usual maximum of 2400, will set the servo to the 180º position. PWM signals and the degree of rotation have a linear relationship. So, any PWM signal set between 600 and 2400 will set the actuator of the servo proportionally between 0º and 180º.

### Materials
* Arduino Uno R3
* Positional Servo Motor
* Jumper Wires

### Schematic
![Positional Servo Schematic. The Servo is plugged into the Arduino with the Signal wire going to pin 5, the Voltage wire going to the 5V pin, and the Ground wire going to the ground pin.](https://github.com/19porterc/ECE484-ServoMotor/blob/main/Positional_Servo/Positional_Servo_Schematic.png)

### Datasheet
Below is the link to the datasheet for the servo used in this tutorial. If you have a different servo motor than the one listed below, be sure to consult that datasheet for your own reference.
* [Miuzei MS18 Datasheet](https://images-na.ssl-images-amazon.com/images/I/61jUf7Q-0uL.pdf)

### Demo
Below is the link to a YouTube video showcasing this program in action. The positional servo motor will center itself, then move to 0º, pause, move to 60º, pause, move to 120º, pause, move to 180º, pause, then back to 0º.
* Placeholder

## Continuous Servo Motor
### Introduction
A Continuous Servo Motor is a type of motor that allows for control over speed and direction of continuous rotation. These motors use pulse width modulation (PWM) to control the speed and direction of the actuator. The lower end of the PWM signal, usually around 1000, will rotate the actuator in the relative reverse direction at full speed. A higher PWM signal, the usual maximum of 2000, will rotate the actuator in the relative forward direction at full speed. The PWM value that is halfway between the minimum and maximum, usually 1500, will stop the actuator. PWM signals and the rotational behavior have a linear relationship. Any PWM signal set between 1000 and 1500 will move the actuator of the servo in the relative reverse direction with proportionate speed. Any PWM signal set between 1500 and 2000 will move the actuator of the servo in the relative forward direction with proportionate speed.

### Materials
* Arduino Uno R3
* Continuous Servo Motor
* Jumper Wires

### Schematic
![Continuous Servo Schematic. The Servo is plugged into the Arduino with the Signal wire going to pin 9, the Voltage wire going to the 5V pin, and the Ground wire going to the ground pin.](https://github.com/19porterc/ECE484-ServoMotor/blob/main/Continuous_Servo/Continuous_Servo_Schematic.png)

### Datasheet
Below is the link to the datasheet for the servo used in this tutorial. If you have a different servo motor than the one listed below, be sure to consult that datasheet for your own reference.
* Placeholder

### Demo
Below is the link to a YouTube video showcasing this program in action. The continuous servo motor will move in the reverse direction for one second, stop for one second, move in the forward direction for one second, stop for one second, and then move in the reverse direction for one second again.
* Placeholder
