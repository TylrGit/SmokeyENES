#include <Arduino.h>
#include <Enes100.h>
#include "HardwareSerial.h"
#include "_SensorManager.h"
#include "_ServoManager.h"
#include "_Navigation.h"

// Arduino default functions
void setup() {
	Serial.begin(9600);
	SensorManager::initializeSensors();
	// ServoManager::initializeServos(_, _); // (pinL, pinR)
	Navigation::initializeVision(126); // (markerId) optional override

	// (DEBUG): Manual enable
	// SensorManager::sensors[SensorManager::LIMIT_SWITCH_1].enable();
	// SensorManager::sensors[SensorManager::LIMIT_SWITCH_1].enable();
	// SensorManager::sensors[0].enable();
}

void loop() {
	SensorManager::updateAll(); // Updates sensor data for enabled sensors	

	// (DEBUG): Manual debug print
	// SensorManager::sensors[0].printData();
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


	delay(100); // 100ms delay
}
