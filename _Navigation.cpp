#include <Enes100.h>
#include "_Navigation.h"
#include "_Queue.h"
#include "_Sensor.h"
#include "_SensorManager.h"

void Navigation::initializeVision() {
	Enes100.begin("Smokey", FIRE, 126, 1116);
}
void Navigation::initializeVision(int markerId) {
	Enes100.begin("Smokey", FIRE, markerId, 1116);
}

void Navigation::updatePosData() {
	if (!Enes100.isVisible()) {
		Serial.print("DEBUG: Not visible");
		return;
	}
	xArr.enque(Enes100.getX());
	yArr.enque(Enes100.getY());
	angleArr.enque((((int) ((Enes100.getTheta() + 2*3.14159)*100000)) % 314159) / 100000.0);

	xPos = xArr.average();
	yPos = yArr.average();
	angle = angleArr.average();
}

void Navigation::printPosData() {
	Serial.print("x: ");
	Serial.print(xPos);
	Serial.print(" y: ");
	Serial.print(yPos);
	Serial.print(" angle: ");
	Serial.println(angle);
}

void Navigation::attemptNavigate() {
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



void someNavigationFunction() {
	
}