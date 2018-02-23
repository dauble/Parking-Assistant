# Parking Assistant #

This is a simple Arduino program designed to measure distances and display colors on a 16x16 bi-color LED matrix.

## What is required? ##

* [Arduino Uno R3](https://www.amazon.com/Elegoo-EL-CB-001-ATmega328P-ATMEGA16U2-Arduino/dp/B01EWOE0UU/)
* [Adafruit Bi-Color 16x16 LED Matrix](https://www.amazon.com/Adafruit-Bicolor-Square-Matrix-Backpack/dp/B00OKJFASE/)
* [HC-SR04 Ultrasonic Sensor](https://www.amazon.com/Elegoo-HC-SR04-Ultrasonic-Distance-MEGA2560/dp/B01COSN7O6/)
* [Project Breadboard & Jumper Wires](https://www.amazon.com/microtivity-400-point-Experiment-Breadboard-Jumper/dp/B004RXKWDQ/)

## Required Libraries ##

* [Adafruit LED Backpack](https://github.com/adafruit/Adafruit_LED_Backpack)
* [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)

## Installation ##

### HC-SR04 ###
1. VCC - 5V
2. Trig - 12
3. Echo - 11
4. Grnd - Ground

### LED Matrix ###
1. VCC - 5V
2. D - Analog 4
3. C - Analog 5
4. Grnd - Ground

## Getting Started ##

Getting started is simple. Copy the code from `final-parking.ino` into a new Arduino project, compile and upload. Update the distances to your needs in the IF blocks in the main loop() function.

Enjoy!