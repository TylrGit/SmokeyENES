#pragma once

// Drive Motors
class DCMotor {
	private:
	    int dirPin;
	    int pwmPin;

	public:
	    DCMotor(int pwm, int dir) : pwmPin(pwm), dirPin(dir) {}

	    void setSpeed(int speed) {
	        // analogWrite(pwmPin, abs(speed));
	        // digitalWrite(dirPin, speed >= 0);
	    }

	    // void setDirection(int dir) {
	    //
	    // }
};
