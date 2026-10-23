#pragma once
#include "./_Sensor.h"

class SensorManager {
	friend class Navigation;

	private:
		// Note: Dynamically allocated
		static Sensor* sensors;

	public:
		static void initializeSensors();
		static void updateAll();
		static void disableAll();
};
