#ArduinoJoystick

This is an Arduino Joystick Project that implements a custom joystick interface using Arduino microcontrollers and Linux kernel drivers. Here are the key components and features:

Hardware Components:
Uses Arduino boards
Implements a joystick with 4 directional buttons (UP, DOWN, LEFT, RIGHT)
Uses SPI (Serial Peripheral Interface) communication protocol

Software Components:
Linux Kernel Driver (gpio_driver.c and gpio_driver_new.c):
Implements GPIO (General Purpose Input/Output) control
Handles interrupts for button presses
Manages SPI communication
Provides a character device interface for user-space applications

Arduino Firmware:
Maps button presses to specific byte values:
UP button = 0x01
RIGHT button = 0x02
DOWN button = 0x03
LEFT button = 0x04

Communication Protocol:
Uses SPI with three pins:
SS (Slave Select)
MOSI (Master Out Slave In)
SCK (Serial Clock)
Implements custom bit-banging for data transmission
Uses interrupts for button press detection
