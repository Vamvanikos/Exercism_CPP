#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

// TODO: add your solution here
unsigned int steps(int number)
{
    if (number < 1)
    {
        throw std::domain_error("Input must be possitive integer.");
    }

    unsigned int count = 0;
    while (number != 1)
    {
        if (number%2)
        {
            number = number * 3 + 1;
        }
        else
        {
            number /= 2;
        }
        ++count;
    }

    return count;
}

}  // namespace collatz_conjecture
