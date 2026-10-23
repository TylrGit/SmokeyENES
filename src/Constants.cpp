#include "../headers/Constants.h"

// Includes all our enums & constant values
namespace Constants {
  enum NavState {
    WAITING,
    TO_SITE,
    TO_OBSTACLES,
    OBSTACLES,
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

  // AI: Taught me constexpr vs const keyword.
  struct CoordinateConstants {
    static constexpr double obstacleRow1 = 0;
    static constexpr double obstacleRow2 = 0;
    static constexpr double obstacleRow3 = 0;
  };
}
