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
    int power = justifyTo255(power);
    if(power > 0){
        frontLeft.setDirection(DIRECTIONS.FORWARD);
        frontRight.setDirection(DIRECTIONS.FORWARD);
        backLeft.setDirection(DIRECTIONS.FORWARD);
        backRight.setDirection(DIRECTIONS.FORWARD);
    }else if(power < 0){
        frontLeft.setDirection(DIRECTIONS.REVERSE);
        frontRight.setDirection(DIRECTIONS.REVERSE);
        backLeft.setDirection(DIRECTIONS.REVERSE);
        backRight.setDirection(DIRECTIONS.REVERSE);
    }else{
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
    int power = justifyTo255(power);

    frontLeft.setPower(0);
    frontRight.setPower(power);
    backLeft.setPower(0);
    backRight.setPower(power);
}

void Drive::turnRight(int power){
    int power = justifyTo255(power);

    frontLeft.setPower(power);
    frontRight.setPower(0);
    backLeft.setPower(power);
    backRight.setPower(0);
}

void Drive::sharpRight(int power){
    int power = justifyTo255(power);

    frontLeft.setPower(power);
    frontRight.setPower(-power);
    backLeft.setPower(power);
    backRight.setPower(-power);
}

void Drive::sharpLeft(int power){
    int power = justifyTo255(power);

    frontLeft.setPower(-power);
    frontRight.setPower(power);
    backLeft.setPower(-power);
    backRight.setPower(power);
}

int justifyTo255(int val){
    return map(val, 0, 100, 0, 255);
}