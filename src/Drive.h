#ifndef DRIVE_H
#define DRIVE_H
#include <DcMotor.h>

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

};

#endif