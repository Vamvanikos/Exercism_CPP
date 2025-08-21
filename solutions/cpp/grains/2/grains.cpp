#include "grains.h"
#include <stdexcept>
#include <cmath>

namespace grains {

unsigned long long square(int sq)
{
    if (sq <= 0 || sq > CHESS_SQUARES)
        throw std::invalid_argument("Square number must be positive and <= 64.");

    return 1ULL << (sq - 1);
}

unsigned long long total()
{
    //return (1ULL << (CHESS_SQUARES - 1)) * 2 - 1;
    unsigned long long total = 0;
    for (int i = 1; i <= CHESS_SQUARES; ++i)
        total += square(i);

    return total;
}

}  // namespace grains
