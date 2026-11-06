#include <Arduino.h>
#include <Enes100.h>
#include "HardwareSerial.h"
#include "_FlameSensor.h"
#include "_SensorManager.h"
#include "_Navigation.h"
#include "_ServoManager.h"
#include "_MotorManager.h"


void setup() {
	Serial.begin(9600);
	Navigation::initializeVision();
	SensorManager::initializeSensors();
	SensorManager::enable(SensorManager::LIMIT_SWITCH_1);
	// FlameSensor::initialize();
	// ServoManager::initializeServos(3, -1); // (pinL, pinR) -1 to disable


	// If not connected to Enes system, run a blocking loop
	/*
	if (!Enes100.isConnected()) {
		Serial.println("<!> Error: Vision not connected! Terminating...");
		Serial.flush();
		while (true) {
			delay(100);
		}
	}
	*/

	ServoManager::setAngle(0);
}

void loop() {
	Navigation::time = millis(); // Time since start

	SensorManager::updateAll(); // Updates sensor data for enabled sensors

	Navigation::updatePosData();
	// Navigation::printPosData();
	// Navigation::attemptNavigate();

	// FlameSensor::update();
	// FlameSensor::printArray();

	SensorManager::printSensorData(SensorManager::LIMIT_SWITCH_1); // (DEBUG)

	delay(50);
}
