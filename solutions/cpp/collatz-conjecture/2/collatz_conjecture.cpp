#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

unsigned int steps(int number)
{
    if (number <= 0)
        throw std::domain_error("Input number must be positive integer.");

    unsigned int count = 0;
    while (number != 1)
    {
        if (number % 2 == 0)
            number >>= 1;
        else
            number = number * 3 + 1;
        ++count;
    }

    return count;
}

}  // namespace collatz_conjecture
