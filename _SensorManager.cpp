#include <Arduino.h>
// #include <Enes100.h>
#include "_SensorManager.h"
// #include "_FlameSensor.h"
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
		if (sensors[i].type == Sensor::LIMIT_SWITCH) {
			pinMode(sensors[i].pinIn, INPUT_PULLUP); // Set as input with pullup
		} else {
			pinMode(sensors[i].pinIn, INPUT); // Set as input
		}

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
 * Disable all sensors
 */
void SensorManager::disableAll() {
	for (int i = 0; i < NUM_SENSORS; i++) {
		sensors[i].disable();
	}
}

/*
 * Enable a sensor by ID
 */
void SensorManager::enable(Id id) {
	if (id >= 0 && id < NUM_SENSORS) {
		sensors[id].enable();
	}
}

/*
 * Disable a sensor by ID
 */
void SensorManager::disable(Id id) {
	if (id >= 0 && id < NUM_SENSORS) {
		sensors[id].disable();
	}
}

/*
 * Print sensor data for a given ID
 */
void SensorManager::printSensorData(Id id) {
	if (id >= 0 && id < NUM_SENSORS) {
		sensors[id].printData();
	}
}

/*
 * Print data for all sensors
 */
void SensorManager::printAllSensorData() {
	for (int i = 0; i < NUM_SENSORS; i++) {
		sensors[i].printData();
	}
}

/*
 * Sends mission related data to the Enes100 server
 */
void SensorManager::missionOrientation() {
	/*
	 * Enes100.mission(TOPOGRAPHY, TOP_A);
	 * Enes100.mission(TOPOGRAPHY, TOP_B);
	 * Enes100.mission(TOPOGRAPHY, TOP_C);
	 */
	// Enes100.mission(TOPOGRAPHY, Sensor::getOrientation());
}

void SensorManager::missionFlames() {
 	// Enes100.mission(NUM_CANDLES, i); i is an integer (0, 1, 2, 3, 4, 5)
	// Enes100.mission(NUM_CANDLES, FlameSensor::getCandlesLit());
}
