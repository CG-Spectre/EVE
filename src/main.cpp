#include <Arduino.h>
#include "DcMotor.h"
#define enA 5
#define in1 9
#define in2 10

#define enB 10
#define in3 8
#define in4 4

DcMotor motor;
void setup() {
  Serial.begin(9600);
  motor = DcMotor(enA, in1, in2);
}

void loop() {
  motor.setPower(255);
  
}