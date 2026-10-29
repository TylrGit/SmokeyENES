#pragma once

// Drive Motors
class DCMotor {
	private:
	    int pwmPin;
	    int dirPin;

	public:
	    DCMotor(int pwm, int dir) : pwmPin(pwm), dirPin(dir) {}

	    void setCommand(int speed) {
	        // analogWrite(pwmPin, abs(speed));
	        // digitalWrite(dirPin, speed >= 0);
	    }
};
