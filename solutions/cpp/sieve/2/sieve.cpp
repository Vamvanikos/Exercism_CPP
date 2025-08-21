#include "sieve.h"
#include <stdexcept>
#include <unordered_map>

namespace sieve {

std::vector<int> primes(int num)
{
    if (num <= 0)
        throw std::invalid_argument("Input number must be positive.");

    std::vector<int> primes;
    primes.reserve(num);
    std::unordered_map<int, bool> primeCandidates;
    primeCandidates.reserve(num);

    for (int i = 2; i <= num; ++i)
        primeCandidates[i] = true;

    for (int i = 2; i <= num; ++i)
    {
        if (primeCandidates[i])
        {
            primes.push_back(i);
            for (int mult = i * 2; mult <= num; mult += i)
                primeCandidates[mult] = false;
        }
    }

    return primes;
}

}  // namespace sieve
