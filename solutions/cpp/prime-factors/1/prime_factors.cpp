#include "prime_factors.h"

namespace prime_factors {

// TODO: add your solution here
const std::vector<long long> of(long num)
{
    std::vector<long long> factors;
    long i = 2;
    
    while (num > 1)
    {
        if (!(num%i))
        {
            factors.push_back(i);
            num /= i;
        }
        else
        {
            i++;
        }
    }

    return factors;
}

}  // namespace prime_factors
