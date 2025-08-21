#include "eliuds_eggs.h"

namespace chicken_coop {

int positions_to_quantity(int displayDecimal)
{
    int sum = 0;
    while (displayDecimal > 0)
    {
        sum += displayDecimal % 2;
        displayDecimal /= 2;
    }

    return sum;    
}

}  // namespace chicken_coop
