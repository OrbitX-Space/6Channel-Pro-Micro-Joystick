#include <Joystick.h>

const int analogPinX = A0;
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buttonPin5 = 6;
const int buttonPin6 = 7;

// Define the number of analog values (usually 10-bit resolution for Arduino Pro Micro)
const int analogMax = 1023;

// Define joystick X-axis range (-32767 to 32767)
const int xMin = -32767;
const int xMax = 32767;
const int xDeadZone = 50;

Joystick_ Joystick;

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  
  Joystick.setXAxisRange(xMin, xMax);
  Joystick.begin();
}

void loop() {
  int xValue = analogRead(analogPinX);
  int xMapped = map(xValue, 0, analogMax, xMin, xMax);
  
  if (abs(xMapped) < xDeadZone) {
    xMapped = 0;
  }
  
  bool buttonState1 = !digitalRead(buttonPin1);
  bool buttonState2 = !digitalRead(buttonPin2);
  bool buttonState3 = !digitalRead(buttonPin3);
  bool buttonState4 = !digitalRead(buttonPin4);
  bool buttonState5 = !digitalRead(buttonPin5);
  bool buttonState6 = !digitalRead(buttonPin6);
  
  Joystick.setXAxis(xMapped);

  Joystick.setButton(0, buttonState1);
  Joystick.setButton(1, buttonState2);
  Joystick.setButton(2, buttonState3);
  Joystick.setButton(3, buttonState4);
  Joystick.setButton(4, buttonState5);
  Joystick.setButton(5, buttonState6);
  
  Joystick.sendState();
}
