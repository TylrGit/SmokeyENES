#include <Arduino.h>
#include <Enes100.h>
#include "HardwareSerial.h"
#include "_Sensor.h"
#include "_SensorManager.h"

// AI Helped with integrating existing update function with ultrasonic sensor
// And debug switch case ULTRASONIC needing braces
void Sensor::update() {
	if (!this->enabled) return;

	switch (this->type) {
    case ANALOG:
        this->data = analogRead(this->pinIn);
        break;

    case DIGITAL:
        this->data = digitalRead(this->pinIn);
        break;

    case ULTRASONIC: {
	    // HC-SR04 code from: https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
        // 10 microsecond pulse to vOut (Trig pin)
        digitalWrite(this->vOut, LOW);
        delayMicroseconds(2);
        digitalWrite(this->vOut, HIGH);
        delayMicroseconds(10);
        digitalWrite(this->vOut, LOW);

        double duration = pulseIn(this->pinIn, HIGH); // Read
        this->data = duration * (0.0343 / 2); // Convert time to distance (cm)
        break;
    }
    case UNSET:
    default:
    	break;
	}
}

void Sensor::enable() {
	this->enabled = true;
	if (this->vOut != -1) {
		digitalWrite(this->vOut, HIGH);
	}
}

void Sensor::disable() {
	this->enabled = false;
	if (this->vOut != -1) {
		digitalWrite(this->vOut, LOW);
	}
}

// Could be stale data if disabled
void Sensor::printData() {
	Serial.println(this->data);
}

bool Sensor::isObstacle() {
	if (this->type != ULTRASONIC) return false;
	return this->data < SensorManager::DISTANCE_THRESHOLD;
}

int Sensor::getOrientation() {
	Sensor sensorL = SensorManager::sensors[SensorManager::LIMIT_SWITCH_1];
	Sensor sensorR = SensorManager::sensors[SensorManager::LIMIT_SWITCH_2];

	if (sensorL.data == 1.0 && sensorR.data == 0.0) return TOP_A;
	if (sensorL.data == 0.0 && sensorR.data == 0.0) return TOP_B;
	if (sensorL.data == 1.0 && sensorR.data == 1.0) return TOP_C;

	return -1;
}
