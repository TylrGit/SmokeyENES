#include <Arduino.h>
#include "./_SensorManager.h"
#include "./_Sensor.h"

// AI Helped fix error linker error for sensors array
Sensor* SensorManager::sensors = nullptr;

/*
 * Initializes sensor array
 * Each Sensor has pin number stored & disabled by default
 *
 * Sensors: Sensor(pinIn, Sensor::type)
 * Sensors: Sensor(pinIn, vOut, Sensor::type)
 *
 * Example: sensors[LIMIT_SWITCH_1] = Sensor(1, Sensor::DIGITAL);
 */
void SensorManager::initializeSensors() {
	sensors = new Sensor[NUM_SENSORS];

	/*
	 * Manually define sensors here
	 */
	sensors[LIMIT_SWITCH_1] = Sensor(12, 13, Sensor::DIGITAL);

	/*
	 * End
	 */

	// Initialize pins for all sensors
	for (int i = 0; i < NUM_SENSORS; i++) {
		pinMode(sensors[i].pinIn, INPUT); // Set as input

		// Sets vOut pins to output if required.
		// Defaults to LOW / off
		if (sensors[i].vOut != -1) {
			pinMode(sensors[i].vOut, OUTPUT);
			digitalWrite(sensors[i].vOut, LOW);
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
