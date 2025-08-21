#include "sieve.h"
#include <stdexcept>
#include <cmath>

namespace sieve {

std::vector<int> primes(int num)
{
    if (num < 2)
        return {};

    std::vector<int> primes;
    primes.reserve(num);
    std::vector<bool> primeCandidates(num + 1, true);

    int limit = static_cast<int>(std::sqrt(num));
    for (int i = 2; i <= limit; ++i)
        if (primeCandidates[i])
            for (int mult = i * i; mult <= num; mult += i)
                primeCandidates[mult] = false;

    for (int i = 2; i <= num; ++i)
        if (primeCandidates[i])
            primes.push_back(i);

    return primes;
}

}  // namespace sieve
