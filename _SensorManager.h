#pragma once
#include "./_Sensor.h"

/*
 * File AI Disclosure:
 * - AI helped with initializing sensors in an array
 *   (Inline allows sensors to be defined in the .h file)
 */

struct SensorManager {
	/*
	 * Manually define sensors here
	 *
	 * Using separate VIN: Sensor(pinIn, Sensor::type)
	 * Using vOut pin: Sensor(pinIn, vOut, Sensor::type)
	 *
	 * Example: sensors[LIMIT_SWITCH_1] = Sensor(12, 13, Sensor::DIGITAL);
	 */
	enum Id {
		LIMIT_SWITCH_1,
		NUM_SENSORS
	};
	inline static Sensor sensors[NUM_SENSORS] = {
		Sensor(12, 13, Sensor::DIGITAL), // LIMIT_SWITCH_1
	};

	static void initializeSensors();
	static void updateAll();
	static void disableAll();
};
