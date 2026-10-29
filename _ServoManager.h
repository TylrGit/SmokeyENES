#pragma once
#include <Servo.h>

// Servo
struct ServoManager {
    static double angle;
    static Servo servoL, servoR;

    static void initializeServos(int pinL, int pinR) {
        servoL.attach(pinL);
        servoR.attach(pinR);
    }

    static void setAngle(int degrees){
    	angle = degrees;
        servoL.write(degrees);
        servoR.write(180 - degrees);
    }
};
