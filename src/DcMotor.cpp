#include <Arduino.h>
#include "DcMotor.h"

DcMotor::DcMotor(int enAp, int in1p, int in2p){
    enA = enAp;
    in1  = in1p;
    in2 = in2p;
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
}
DcMotor::DcMotor(){
    
}
void DcMotor::setPower(int pow){
    analogWrite(enA, pow);
    
}

void DcMotor::setDirection(int direction){
    if(direction == DIRECTIONS.FORWARD){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    }
    if(direction == DIRECTIONS.REVERSE){
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    }
}
