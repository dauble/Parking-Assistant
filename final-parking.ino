#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

int trigPin = 12;    //Trig - green Jumper
int echoPin = 11;    //Echo - yellow Jumper
long duration, cm, inches;

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

void setup() {
  //Serial Port begin
  Serial.begin(9600);

  // start LED matrix
  Serial.println("8x8 LED Matrix Test");
  matrix.begin(0x70);  // pass in the address

  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);

  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
//  cm = (duration/2) / 29.1; // uncomment to use cm
  inches = (duration/2) / 74; // uncomment to use in

  // enable light
  matrix.clear();
  matrix.setBrightness(15);

  if(inches <= 24) {
    // to do: keep count, flash for 10s then shut down

    matrix.blinkRate(1); // 0-3
    matrix.writeDisplay();
    matrix.drawLine(0,0, 7,7, LED_RED);
    matrix.drawLine(0,7, 7,0, LED_RED);
    matrix.writeDisplay();

  } else if(inches > 24 && inches <= 29) {

    // display red block
    matrix.blinkRate(0); // 0-3
    matrix.clear();
    matrix.fillRect(0,0, 8,8, LED_RED); // stop
    matrix.writeDisplay();
  } else if(inches > 29 && inches <= 35) {

    // display yellow block
    matrix.blinkRate(0); // 0-3
    matrix.clear();
    matrix.fillRect(0,0, 8,8, LED_YELLOW); // close
    matrix.writeDisplay();
  } else if(inches > 35 && inches <= 48) {

    // display green block
    matrix.blinkRate(0); // 0-3
    matrix.clear();
    matrix.fillRect(0,0, 8,8, LED_GREEN);
    matrix.writeDisplay();
  } else {

    // turn matrix off
    matrix.blinkRate(0); // 0-3
    matrix.clear();
    matrix.writeDisplay();
  }

  delay(250);
}