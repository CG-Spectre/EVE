#include "Drive.h"
#include <Arduino.h>
#include "DcMotor.h"
#include <pt.h>

static struct pt pt1;

Drive::Drive(){
    ready = false;
}

Drive::Drive(DcMotor fl, DcMotor fr, DcMotor bl, DcMotor br){
    PT_INIT(&pt1);
    frontLeft = fl;
    frontRight = fr;
    backLeft = bl;
    backRight = br;
    ready = true;
}

void Drive::forward(int power){
    power = justifyTo255(power);
    if(!justifyDirection(power)){
        stop();
        return;
    }
    power = abs(power);
    frontLeft.setPower(power);
    frontRight.setPower(power);
    backLeft.setPower(power);
    backRight.setPower(power);
}

void Drive::stop(){
    frontLeft.setPower(0);
    frontRight.setPower(0);
    backLeft.setPower(0);
    backRight.setPower(0);
}

void Drive::turnLeft(int power){
    power = justifyTo255(power);
    if(!justifyDirection(power)){
        stop();
        return;
    }
    frontLeft.setPower(0);
    frontRight.setPower(power);
    backLeft.setPower(0);
    backRight.setPower(power);
}

void Drive::turnRight(int power){
    power = justifyTo255(power);
    if(!justifyDirection(power)){
        stop();
        return;
    }
    frontLeft.setPower(power);
    frontRight.setPower(0);
    backLeft.setPower(power);
    backRight.setPower(0);
}

void Drive::sharpRight(int power){
    power = justifyTo255(power);
    if(!justifyDirection(power)){
        stop();
        return;
    }
    frontLeft.setPower(power);
    frontRight.setPower(-power);
    backLeft.setPower(power);
    backRight.setPower(-power);
}

void Drive::sharpLeft(int power){
    power = justifyTo255(power);
    if(!justifyDirection(power)){
        stop();
        return;
    }
    frontLeft.setPower(-power);
    frontRight.setPower(power);
    backLeft.setPower(-power);
    backRight.setPower(power);
}

int Drive::forwardFor(int power, unsigned int milis){
    struct pt *pta;
    pta = &pt1;
    PT_BEGIN(&pt1);
    int recorded = millis();
    while(millis() - recorded < milis){
        forward(power);
    }
    stop();
    PT_END(&pt1);
}

int Drive::backwardFor(int power, unsigned int milis){
    forwardFor(-power, milis);
}

int Drive::rightFor(int power, unsigned int milis){
    struct pt *pta;
    pta = &pt1;
    PT_BEGIN(&pt1);
    int recorded = millis();
    while(millis() - recorded < milis){
        turnRight(power);
    }
    stop();
    PT_END(&pt1);
}
int Drive::leftFor(int power, unsigned int milis){
    struct pt *pta;
    pta = &pt1;
    PT_BEGIN(&pt1);
    int recorded = millis();
    while(millis() - recorded < milis){
        turnLeft(power);
    }
    stop();
    PT_END(&pt1);
}
int Drive::sharpRightFor(int power, unsigned int milis){
    struct pt *pta;
    pta = &pt1;
    PT_BEGIN(&pt1);
    int recorded = millis();
    while(millis() - recorded < milis){
        sharpRight(power);
    }
    stop();
    PT_END(&pt1);
}
int Drive::sharpLeftFor(int power, unsigned int milis){
    struct pt *pta;
    pta = &pt1;
    PT_BEGIN(&pt1);
    int recorded = millis();
    while(millis() - recorded < milis){
        sharpLeft(power);
    }
    stop();
    PT_END(&pt1);
}