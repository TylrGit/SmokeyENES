#pragma once
#include "./_Sensor.h"

class SensorManager {
	friend class Navigation;

	public:
		enum Id {
			LIMIT_SWITCH_1,
			NUM_SENSORS
		};

	public:
		// Note: Dynamically allocated
		static Sensor* sensors;

		static void initializeSensors();
		static void updateAll();
		static void disableAll();
};
