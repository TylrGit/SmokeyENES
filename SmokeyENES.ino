#include <Arduino.h>
#include <Enes100.h>
#include "./_SensorManager.h"
#include "./_Navigation.h"
#include "HardwareSerial.h"
// Later probably need ActuatorManager class

/* Mission related commands:
 * Enes100.mission(NUM_CANDLES, i); i is an integer (0, 1, 2, 3, 4, 5)
 * Enes100.mission(TOPOGRAPHY, TOP_A);
 * Enes100.mission(TOPOGRAPHY, TOP_B);
 * Enes100.mission(TOPOGRAPHY, TOP_C);
 */

// Arduino default functions
void setup() {
	Serial.begin(9600);
	// Enes100.begin("Smokey", FIRE, 126, 1101); // Team, type, markerId, room
	SensorManager::initializeSensors();

	// (DEBUG): Manual enable
	// SensorManager::sensors[SensorManager::LIMIT_SWITCH_1].enable();

}

void loop() {
	SensorManager::updateAll(); // Updates sensor data for enabled sensors

	// (DEBUG): Manual debug print
	// SensorManager::sensors[SensorManager::LIMIT_SWITCH_1].printData();


	// SensorManager::printSensorData(SensorManager::LIMIT_SWITCH_1);

	// Call Navigation.attemptMovement();
	// attemptMovement will:
	// 1. Read navigation step (e.g. FACING_SITE, TO_SITE, BACKING_FROM_SITE, TO_OBSTACLES)
	// 2. Determine if/what sensors to read from
	// 3. Perform a call to motors to move
	// - Motor speed controlled with RPM,
	// - Motor direction controlled by h-bridge?
	// - Motors have a location (FL, FR, BL, BR) associated with them
	// - We can store each via enum class Motor, access via Motor::FRONT_LEFT etc.
	//
	//
	delay(100);
}
