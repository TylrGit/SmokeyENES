#include <Arduino.h>
#include <Enes100.h>
#include "headers/Constants.h"

/* Mission related commands:
 * Enes100.mission(NUM_CANDLES, i); i is an integer (0, 1, 2, 3, 4, 5)
 * Enes100.mission(TOPOGRAPHY, TOP_A);
 * Enes100.mission(TOPOGRAPHY, TOP_B);
 * Enes100.mission(TOPOGRAPHY, TOP_C);
 */

// Blinks the onboard LED once
void debugLED() {
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH);
	delay(5000);
	digitalWrite(13, LOW);
}

// Arduino default functions
void setup() {
	Serial.begin(9600);
	debugLED();
	// Enes100.begin("Smokey", FIRE, 126, 1101); // Team, type, markerId, room
}

void loop() {
	Serial.println("Hello world!");
	delay(2000);
	// Calls Sensors.updateSensors()
	// Update sensors will read & store sensor
	// values ONLY for toggled on sensors

	// Call Navigation.attemptMovement();
	// attemptMovement will:
	// 1. Read navigation step (e.g. FACING_SITE, TO_SITE, BACKING_FROM_SITE, TO_OBSTACLES)
	// 2. Determine if/what sensors to read from
	// 3. Perform a call to motors to move
	// - Motor speed controlled with RPM,
	// - Motor direction controlled by h-bridge?
	// - Motors have a location (FL, FR, BL, BR) associated with them
	// - We can store each via enum class Motor, access via Motor::FRONT_LEFT etc.
}
