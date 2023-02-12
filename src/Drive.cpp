#include "Drive.h"
#include <Arduino.h>
#include "DcMotor.h"

Drive::Drive(){
    ready = false;
}

Drive::Drive(DcMotor fl, DcMotor fr, DcMotor bl, DcMotor br){
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

