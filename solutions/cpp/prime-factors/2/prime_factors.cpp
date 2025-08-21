#include "prime_factors.h"
#include <stdexcept>

namespace prime_factors {

std::vector<long long> of(long long number)
{
    if (number <= 0)
        throw std::invalid_argument("Input number must be positive.");
    
    std::vector<long long> primeFactors;
    while (number % 2 == 0)
    {
        primeFactors.push_back(2);
        number /= 2;
    }    

    long long factor = 3;
    while (number != 1)
    {
        if (number % factor == 0)
        {
            primeFactors.push_back(factor);
            number /= factor;
        }
        else
            factor += 2;
    }

    return primeFactors;
}

}  // namespace prime_factors
