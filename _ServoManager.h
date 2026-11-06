#pragma once
#include <Servo.h>

/*
 * File AI Disclosure:
 * - AI informed that prewriting 0 degrees to servo prevents calibration
 */

// Servo
struct ServoManager {
    inline static double angle = 0.0;
    inline static Servo servoL, servoR;
    inline static int pinL = -1, pinR = -1;

    static void initializeServos(int pinL, int pinR) {
    	// Prewrite 0 degrees to prevent calibration
     	if (pinL != -1) {
     	    servoL.write(0);
            servoL.attach(pinL);
        }
	    if (pinR != -1) {
     	    servoR.write(0);
            servoR.attach(pinR);
        }
        ServoManager::pinL = pinL;
        ServoManager::pinR = pinR;
    }

    static void setAngle(int degrees){
    	angle = degrees;
    	if (pinL != -1) {
        	servoL.write(degrees);
        }
    	if (pinR != -1) {
        	servoR.write(180 - degrees);
        }
    }
};
