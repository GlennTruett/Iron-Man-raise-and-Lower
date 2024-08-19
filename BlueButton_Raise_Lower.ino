#include <Arduino.h>

const int MOTORPIN1 = 2;    // runs the motor up
const int MOTORPIN2 = 4;    // runs the motor down
const int ENABLEPIN = 3;    // turns the motor control on or off
const int BUTTONBLUE = 16;  // A2 will be used to manually raise or lower the gauntlet
int buttonPress = 1;        // sets buttonPress variable as a one this keeps track of which buttonPress does what. 

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTORPIN1, OUTPUT);
  pinMode(MOTORPIN2, OUTPUT);
  pinMode(ENABLEPIN, OUTPUT);
  pinMode(BUTTONBLUE, INPUT);

  digitalWrite(BUTTONBLUE, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalRead(BUTTONBLUE);

  if (BUTTONBLUE == HIGH && buttonPress == 1) {
    digitalWrite(ENABLEPIN, HIGH);
    digitalWrite(MOTORPIN1, HIGH);
    digitalWrite(MOTORPIN2, LOW);
    delay(1000);
    digitalWrite(ENABLEPIN, LOW);
    digitalWrite(MOTORPIN1, LOW);
    digitalWrite(MOTORPIN2, LOW);
    buttonPress = buttonPress + 1;
  }

  if (BUTTONBLUE == HIGH && buttonPress == 2) {
    digitalWrite(ENABLEPIN, HIGH);
    digitalWrite(MOTORPIN1, LOW);
    digitalWrite(MOTORPIN2, HIGH);
    delay(1000);
    digitalWrite(ENABLEPIN, LOW);
    digitalWrite(MOTORPIN1, LOW);
    digitalWrite(MOTORPIN2, LOW);
    buttonPress = 1;
  }
}
