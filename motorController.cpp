#include "motorController.h"

MotorController::MotorController(short motorPin, float slapForce){
    this->motorPin = motorPin;
    this->force = slapForce;
    wiringPiSetup();
}
