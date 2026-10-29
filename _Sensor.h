#pragma once

/*
 * vOut is the pin used for voltage output (digital)
 * data is int or double
 */
struct Sensor {
	friend class SensorManager;

	public:
		enum ReadType { ANALOG, DIGITAL, ULTRASONIC, UNSET };

	private:
		bool enabled;
		int pinIn;
		int vOut;
		ReadType type;
		double data;

	public:
		Sensor() : pinIn(-1), vOut(-1), enabled(false), type(UNSET) {}
		Sensor(int pinIn, ReadType type) : pinIn(pinIn), vOut(-1), enabled(false), type(type) {}
		Sensor(int pinIn, int pinOut, ReadType type) : pinIn(pinIn), vOut(pinOut), enabled(false), type(type) {}

		// Setters
		void enable();
		void disable();
		void update();

		// Getters
		bool isEnabled() { return enabled; }
		double getValue() { return data; }
		void printData();

		bool isObstacle();
		static int getOrientation();
		static int getCandlesLit();
};
