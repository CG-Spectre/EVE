#ifndef DRIVE_H
#define DRIVE_H
#include <DcMotor.h>
#include <Arduino.h>

class Drive {
    public:
        DcMotor frontLeft;
        DcMotor frontRight;
        DcMotor backLeft;
        DcMotor backRight;
        bool ready = false;
        Drive();
        Drive(DcMotor frontLeft, DcMotor frontRight, DcMotor backLeft, DcMotor backRight);
        void forward(int power);
        void backward(int power);
        void left(int power);
        void right(int power);
        void turnLeft(int power);
        void turnRight(int power);
        void sharpLeft(int power);
        void sharpRight(int power);
        void stop();
        int justifyTo255(int val){
            return map(val, 0, 100, 0, 255);
        }
        bool justifyDirection(int power){
            power = justifyTo255(power);
            if(power > 0){
                frontLeft.setDirection(DIRECTIONS.FORWARD);
                frontRight.setDirection(DIRECTIONS.FORWARD);
                backLeft.setDirection(DIRECTIONS.FORWARD);
                backRight.setDirection(DIRECTIONS.FORWARD);
                return true;
            }else if(power < 0){
                frontLeft.setDirection(DIRECTIONS.REVERSE);
                frontRight.setDirection(DIRECTIONS.REVERSE);
                backLeft.setDirection(DIRECTIONS.REVERSE);
                backRight.setDirection(DIRECTIONS.REVERSE);
                return true;
            }else{
                return false;
            }
        }
};

#endif