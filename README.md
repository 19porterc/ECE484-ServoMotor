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

### Code Functionality
There are three functions in the Positional Servo library.
* void PS_Setup();
  * This function gets the servo ready for use. It sets pin 5 on the Arduino as an output pin and sets the servo motor to low.
* void PS_Center();
  * This function will center the servo at 90º when called.
* void set_angle(int angle);
  * This function sets the angle of the servo based on the input of the user. The valid range of numbers is any angle from 0 to 180.

### Demo
Below is the link to a YouTube video showcasing this program in action. The positional servo motor will center itself, then move to 0º, pause, move to 60º, pause, move to 120º, pause, move to 180º, pause, then back to 0º.
* [Servo Motor Demo](https://youtu.be/l828bsa6ecI)

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
* [SG90-HV Datasheet](https://akizukidenshi.com/goodsaffix/sg90-hv.pdf)

### Code Functionality
There are two functions in the Continuous Servo library.
* void CS_Setup();
  * This function gets the servo ready for use. It sets pin 9 on the Arduino as an output pin and sets the servo motor to low.
* void set_speed(int speed);
  * This function sets the speed of the servo based on the input of the user. The valid range of input is from -90 to 90.

## Compiling with AVR
To compile the following code with AVR, you will need to have both avr-gcc-11.1.0 installed as well as avrdude. Once those have been installed, the compilation process can begin.
1. **Open Command Prompt**
   - On your windows machine, open command prompt.
2. **Verify AVR**
   - You can verify AVR inside command prompt using
     ```
     avr-gcc -v
     avrdude -v
     ```
   - You may have to install these if missing.
3. **Change Directory to Source Code Directory**
   - cd into the directory to where you downloaded these files.
4. **Compile Each File**
   - We will start with the positional servo code. cd into that directory.
   - Type the following commands to compile the positional servo code.
     ```
     c:\avr-gcc-11.1.0\bin\avr-gcc.exe -Os -DF_CPU=16000000UL -mmcu=atmega328p -c main.c -o main.o
     c:\avr-gcc-11.1.0\bin\avr-gcc.exe -Os -DF_CPU=16000000UL -mmcu=atmega328p -c libPositional/positional.c -o positional.o
     ```
   - You may have to change the filepath depending on where avr-gcc is installed.
5. **Link Files**
   - Type the following command to link the files.
     ```
     c:\avr-gcc-11.1.0\bin\avr-gcc.exe -mmcu=atmega328p -o main.elf main.o positional.o
     ```
   - You may have to change the filepath depending on where avr-gcc is installed.
6. **Check COM Port of Arduino**
   - Open the Arduino IDE to find the COM port of the board.
   - The example here uses com11. Yours may be different.
   - The COM port can be found under Tools -> Port
7. **Upload Code**
   - Type the following command to upload the code to the Arduino.
     ```
     c:\avr-gcc-11.1.0\bin\avrdude.exe -F -V -c arduino -p ATMEGA328P -P com11 -b 115200 -U flash:w:main.elf
     ```
   - You may have to change the filepath depending on where avrdude is installed.
8. **Continuous Files**
   - Once you are finished with the positional servo motor, it is time to move to the continuous servo.
   - Disconnect the Arduino from the computer before switching pins.
   - Use `cd ..` to go back a folder and then cd into the continuous servo folder.
9. **Compile Continuous Files**
   - Type the following commands to compile the continuous servo code.
     ```
     c:\avr-gcc-11.1.0\bin\avr-gcc.exe -Os -DF_CPU=16000000UL -mmcu=atmega328p -c main.c -o main.o
     c:\avr-gcc-11.1.0\bin\avr-gcc.exe -Os -DF_CPU=16000000UL -mmcu=atmega328p -c libContinuous/continuous.c -o continuous.o
     ```
   - You may have to change the filepath depending on where avr-gcc is installed.
10. **Link Files**
    - Type the following command to link the files.
      ```
      c:\avr-gcc-11.1.0\bin\avr-gcc.exe -mmcu=atmega328p -o main.elf main.o continuous.o
      ```
    - You may have to change the filepath depending on where avr-gcc is installed.
11. **Check COM Port of Arduino**
    - Plug the Arduino back in and use the Arduino IDE to find the COM port of the board.
    - The example here uses com11. Yours may be different.
    - The COM port can be found under Tools -> Port
12. **Upload Code**
    - Type the following command to upload the code to the Arduino.
      ```
      c:\avr-gcc-11.1.0\bin\avrdude.exe -F -V -c arduino -p ATMEGA328P -P com11 -b 115200 -U flash:w:main.elf
      ```
    - You may have to change the filepath depending on where avrdude is installed.
