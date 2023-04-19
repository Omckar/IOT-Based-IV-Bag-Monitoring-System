# IOT-Based-IV-Bag-Monitoring-System
IOT based IV bag monitoring system is project that aims to monitor and level of fluid in an IV bag (Saline bag) using IOT technology. This system can be used in hospitals and health care facilities to alert the staff members about level of fluid available in the bottle. 

Components used:
HX711 Amplifier
LCD 16x2 with I2C Interface
5kg Load Cell
Arduino Uno R3
LED and Buzzer

Connections:
lcd to arduino
gnd (arduino) --> gnd (lcd)
5v (arduino) --> vcc (lcd)
a4 (arduino) --> sda (lcd)
a5 (arduino) --> scl (lcd)

hx711 to arduino
gnd (arduino) --> gnd (amp)
d4 (arduino) --> dt (amp)
d5 (arduino) --> sck (amp)
3.3v (arduino) --> vcc (amp)

load cell to amplifier
red --> e+
black --> e-
white  a-
green --> a+

led 
postive --> 10k ohms resister --> d7 (a)
negative --> gnd (arduino)[merged]

buzzer 
positive --> d8 (a)
negative --> gnd (arduino)[merged]

[merged] means this to wires are short and given to single pin on an arduino.
