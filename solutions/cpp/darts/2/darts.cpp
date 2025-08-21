#include "darts.h"

namespace darts {

int score(float x, float y)
{
    float distanceSq = x * x + y * y;
    if (distanceSq <= INNER_RADIUS_SQ)   return 10;
    if (distanceSq <= MIDDLE_RADIUS_SQ)  return 5;
    if (distanceSq <= OUTER_RADIUS_SQ)   return 1;
    return 0;
}

}  // namespace darts