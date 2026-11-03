#pragma once
#include "_Queue.h"

// AI: Helped me understand static constexpr
// in a namespace for compile-time constants
namespace Hardcoded {
	static constexpr double obstacleRow1 = 0.0;
    static constexpr double obstacleRow2 = 0.0;
    static constexpr double obstacleRow3 = 0.0;
}


// AI: Helped me inline for in-header static initialization
struct Navigation {
	inline static Queue xArr;
	inline static Queue yArr;
	inline static Queue angleArr;
	inline static double xPos = -1.0;
	inline static double yPos = -1.0;
	inline static double angle = -1.0; // Normalized to 0 to 2pi

	enum State {
        WAITING,
		TURNING_TO_SITE,
        TO_SITE,
        TO_OBSTACLES,
        COMPLETE_OBSTACLES,
        TO_LOG,
        TO_END,
        END
    };

    enum Direction {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

	static void initializeVision();
	static void initializeVision(int markerId); // For debugging

	static void updatePosData();
	static void printPosData();

	static void turnTo(double targetAngle);
	static void travelTo(double targetX, double targetY);

	static void attemptNavigate();
};
