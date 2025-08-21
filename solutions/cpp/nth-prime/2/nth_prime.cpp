#include "nth_prime.h"

namespace nth_prime {

bool is_prime(unsigned int primeCandidate)
{
    for (unsigned int i = 3; i < primeCandidate / 2; i +=2)
    {
        if (primeCandidate % i == 0)
            return false;
    }
    
    return true;
}
    
unsigned int nth(unsigned int num)
{
    if (num == 0)
        throw std::domain_error("Input number must be positive.");

    if (num == 1) return 2;
    
    unsigned int count = 1;
    unsigned int primeCandidate = 3;
    while (true)
    {
        if (is_prime(primeCandidate))
        {
            ++count;
            if (count == num)
                return primeCandidate;
        }
        primeCandidate += 2;
    }        
}

}  // namespace nth_prime
