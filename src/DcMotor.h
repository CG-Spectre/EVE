#ifndef DCMOTOR_H
#define DCMOTOR_H

class DcMotor {
    public:
        bool isInverted = false;
        int currentDirection = DIRECTIONS.FORWARD;
        DcMotor(int enAp, int in1p, int in2p);
        DcMotor();
        void setPower(int pow);
        int enA;
        int in1;
        int in2;
        void setDirection(int direction);
        void setInverted(){
            setInverted(true);
        }
        void setInverted(bool inv){
            isInverted = inv;
        }
};

struct  {
    int FORWARD = 1;
    int REVERSE = 2;
} DIRECTIONS;

#endif