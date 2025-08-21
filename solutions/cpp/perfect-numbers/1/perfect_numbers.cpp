#include "perfect_numbers.h"
#include <stdexcept>

namespace perfect_numbers {

classification classify(const int number)
{
    if (number < 1)
        throw std::domain_error("Input number must be positive.");
    if (number == 1)
        return classification::deficient;
    
    int sum = 1;
    for (int i = 2; i < number; ++i)
    {
        if (number % i == 0)
            sum += i;
    }

    if (sum == number)
        return classification::perfect;
    else if (sum > number)
        return classification::abundant;
    else
        return classification::deficient;
}
    
}  // namespace perfect_numbers
