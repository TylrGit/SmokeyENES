#include <Arduino.h>
#include "./_SensorManager.h"
#include "./_Sensor.h"

/*
 * File AI Disclosure:
 * - AI warned that writing pin state to LOW before setting mode
 *   to out is prefferred to prevent startup spikes
 */

/*
 * Sets Arduino pin mode for sensors
 * Each Sensor has the optional vOut disabled by default
 */
void SensorManager::initializeSensors() {
	// Initialize pins for all sensors
	for (int i = 0; i < NUM_SENSORS; i++) {
		pinMode(sensors[i].pinIn, INPUT); // Set as input

		// Sets vOut pins to output if required.
		// Defaults to LOW / off
		if (sensors[i].vOut != -1) {
			digitalWrite(sensors[i].vOut, LOW); // Pre-write LOW
			pinMode(sensors[i].vOut, OUTPUT);
		}
	}
}

/*
 * Calls update() on all sensors
 * Note: Only enabled sensors get updated values
 */
void SensorManager::updateAll() {
	for (int i = 0; i < NUM_SENSORS; i++) {
		sensors[i].update();
	}
}

/*
 * Disables all sensors
 */
void SensorManager::disableAll() {
	for (int i = 0; i < NUM_SENSORS; i++) {
		sensors[i].disable();
	}
}
