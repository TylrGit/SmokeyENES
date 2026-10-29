#include <Enes100.h>
#include "_Navigation.h"
#include "_Queue.h"
#include "_Sensor.h"
#include "_SensorManager.h"

void Navigation::initializeVision() {
	Enes100.begin("Smokey", FIRE, 126, 1101);
}
void Navigation::initializeVision(int markerId) {
	Enes100.begin("Smokey", FIRE, markerId, 1101);
}

void Navigation::updatePosData() {
	if (!Enes100.isVisible()) return;
	xArr.enque(Enes100.getX());
	yArr.enque(Enes100.getY());
	angleArr.enque(Enes100.getTheta() + 3.14159);

	xPos = xArr.average();
	yPos = yArr.average();
	angle = angleArr.average();
}
