#include "eliuds_eggs.h"

namespace chicken_coop {

// TODO: add your solution here

    int positions_to_quantity(int positions)
    {
        int binary[32];
        int idx = 0, count = 0;
        
        while (positions > 0)
        {
            binary[idx]= positions % 2;
            positions /= 2;
            idx++;
        }

        for (int i = 0; i < idx; i++)
        {
            if (binary[i]) { count++; }
        }

        return count;
    }

}  // namespace chicken_coop
