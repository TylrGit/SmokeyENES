#include <Arduino.h>
#include "_Sensor.h"

void Sensor::update() {
	if (this->enabled) {
		// this->data = read;
	}
}

void Sensor::enable() {
	this->enabled = true;
	if (this->vOut != -1) {
		digitalWrite(this->vOut, LOW);
	}
}

void Sensor::disable() {
	this->enabled = false;
}
