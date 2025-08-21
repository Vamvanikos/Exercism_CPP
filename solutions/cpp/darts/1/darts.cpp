#include "darts.h"
#include <cmath>

namespace darts {

// TODO: add your solution here
    int score(float x, float y)
    {
        float rad = sqrt(pow(x,2) + pow(y,2));

        if (rad > 10)
        {
            return 0;
        }
        else if (rad > 5)
        {
            return 1;
        }
        else if (rad > 1)
        {
            return 5;
        }
        else
        {
            return 10;
        }
    }

}  // namespace darts