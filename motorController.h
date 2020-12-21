#pragma once
#include <wiringPi.h>


class MotorController{
    private:
        short motorPin;
        float force;

    public:
        MotorController (short, float);

};
