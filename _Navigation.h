#pragma once

// AI: Helped me understand static constexpr
// in a namespace for compile-time constants
namespace Hardcoded {
	static constexpr double obstacleRow1 = 0.0;
    static constexpr double obstacleRow2 = 0.0;
    static constexpr double obstacleRow3 = 0.0;
}

class Navigation {
	public:
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

	Navigation();
};
