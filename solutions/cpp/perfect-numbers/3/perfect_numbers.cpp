#include "perfect_numbers.h"
#include <stdexcept>
#include <cmath>

namespace perfect_numbers {

classification classify(int num)
{
    if (num < 1)
        throw std::domain_error("Input number must be positive.");

    if (num == 1)
        return classification::deficient;
    
    int sum = 1;
    int limit = static_cast<int>(std::sqrt(num));
    for (int i = 2; i <= limit ; ++i)
    {
        if (num % i == 0)
        {
            int pair = num / i ;
            sum += i;
            if (pair != i)
                sum += pair;
        }
    }

    if (sum == num)
        return classification::perfect;
    else if (sum > num)
        return classification::abundant;
    return classification::deficient;
}
    
}  // namespace perfect_numbers
