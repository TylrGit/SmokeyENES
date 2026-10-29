#include <Arduino.h>
#include <Enes100.h>
#include "_SensorManager.h"
#include "_Sensor.h"

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
			digitalWrite(sensors[i].vOut, LOW); // Pre-write
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

/*
 * Sends mission related data to the Enes100 server
 */
void SensorManager::missionAttempt() {
	/*
	 * Enes100.mission(NUM_CANDLES, i); i is an integer (0, 1, 2, 3, 4, 5)
	 * Enes100.mission(TOPOGRAPHY, TOP_A);
	 * Enes100.mission(TOPOGRAPHY, TOP_B);
	 * Enes100.mission(TOPOGRAPHY, TOP_C);
	 */
	Enes100.mission(TOPOGRAPHY, Sensor::getOrientation());
	Enes100.mission(NUM_CANDLES, Sensor::getCandlesLit());
}
