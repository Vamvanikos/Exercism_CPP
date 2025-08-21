#include "grains.h"
#include <cmath>

namespace grains {

// TODO: add your solution here
unsigned long long square(const int& place)
{
    return std::pow(2, place-1);
}

unsigned long long total()
{
    unsigned long long sum = 0;
    for (int i = 1; i <= 64; i++)
    {
        sum += square(i);
    }

    return sum;
}

}  // namespace grains
