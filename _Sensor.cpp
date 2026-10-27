#include <Arduino.h>
#include "_Sensor.h"

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
        // 10 microsecond pulse to vOut (Trig pin)
        digitalWrite(this->vOut, LOW);
        delayMicroseconds(2);
        digitalWrite(this->vOut, HIGH);
        delayMicroseconds(10);
        digitalWrite(this->vOut, LOW);

        long duration = pulseIn(this->pinIn, HIGH); // Read
        this->data = duration * 0.034 / 2; // Convert time to distance (cm)
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
