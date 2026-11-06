#include <Enes100.h>
#include "HardwareSerial.h"
#include "_Navigation.h"
#include "_Queue.h"
#include "_Sensor.h"
#include "_SensorManager.h"

void Navigation::initializeVision() {
	Enes100.begin("Smokey", FIRE, 126, 1116);
}

void Navigation::updatePosData() {
	if (!Enes100.isVisible()) {
		return;
	}
	xArr.enque(Enes100.getX());
	yArr.enque(Enes100.getY());
	angleArr.enque(Enes100.getTheta());

	xPos = xArr.average();
	yPos = yArr.average();
	angle = angleArr.average();
}

void Navigation::printPosData() {
	if (!Enes100.isVisible()) {
		Serial.println("<!> Error: Not visible");
		return;
	}
	Serial.println("--- Timestamp: ");
	Serial.print(time);
	Serial.print("ms -------- ");
	Serial.print("<?> Position: x: ");
	Serial.print(xPos);
	Serial.print(" y: ");
	Serial.print(yPos);
	Serial.print(" angle: ");
	Serial.println(angle);
}

// attemptMovement will:
	// 1. Read navigation step (e.g. FACING_SITE, TO_SITE, BACKING_FROM_SITE, TO_OBSTACLES)
	// 2. Determine if/what sensors to read from
	// 3. Perform a call to motors to move
	// - Motor speed controlled with RPM,
	// - Motor direction controlled by h-bridge?
	// - Motors have a location (FL, FR, BL, BR) associated with them
	// - We can store each via enum class Motor, access via Motor::FRONT_LEFT etc.
void Navigation::attemptNavigate() {
	Serial.println("<?> Navigating...");
//
// 	switch (state) {
// 		case WAITING:
// 			// Logic here
// 			break;
// 		case TURNING_TO_SITE:
// 			turningToSite();
// 			break;
// 		case TO_SITE:
// 			// Logic here
// 			break;
// 		case TO_OBSTACLES:
// 			// Logic here
// 			break;
// 		case COMPLETE_OBSTACLES:
// 			// Logic here
// 			break;
// 		case TO_LOG:
// 			// Logic here
// 			break;
// 		case TO_END:
// 			// Logic here
// 			break;
// 		case END:
// 			// Logic here
// 			break;
// 	}
}

/*
 * Navigation helper functions
 */
