#include "nth_prime.h"
#include <cmath>
#include <stdexcept>

namespace nth_prime {

// TODO: add your solution here
bool is_prime(int num)
{
    int limit = static_cast<int>(std::sqrt(num));
    for (int i = 3; i <= limit; i += 2) 
    {
        if (num % i == 0) return false;
    }
    
    return true;
}

unsigned int nth(unsigned int nth_prime)
{
    if (nth_prime == 0)
    {
        throw std::domain_error("There is no zeroth prime number.");
    }
    if (nth_prime == 1) return 2;
    
    unsigned int count = 1;
    unsigned int number = 1;
    while (count != nth_prime)
    {
        number += 2;
        if (is_prime(number))
        {
            ++count;
        }
    }

    return number;
}
    
}  // namespace nth_prime
