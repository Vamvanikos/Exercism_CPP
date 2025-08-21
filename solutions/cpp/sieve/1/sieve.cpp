#include "sieve.h"
#include <algorithm>

namespace sieve {

// TODO: add your solution here
const std::vector<int> primes(const int& num)
{
    std::vector<bool> isPrime(num, true);
    isPrime[0] = isPrime[1] = false;
    std::vector<int> prime;

    for (int i = 2; i <= num; i++)
    {
        if(isPrime[i])
        {
            int j = i*2;
            while(j <= num)
            {
                isPrime[j] = false;
                j += i;
            }
        }
    }

    for (int i = 0; i <= num; i++)
    {
        if (isPrime[i]) { prime.push_back(i); }
    }
        
    return prime;
}

}  // namespace sieve
