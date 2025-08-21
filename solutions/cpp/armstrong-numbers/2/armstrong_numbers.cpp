#include "armstrong_numbers.h"
#include <string>
#include <cmath>

namespace armstrong_numbers {

bool is_armstrong_number(int num)
{
    if (num < 0)
        return false;
    
    int sum = 0;
    std::string numCh = std::to_string(num);
    
    for (char digitCh : numCh)
        sum += std::pow(digitCh - '0', numCh.size());

    return num == sum;
}

}  // namespace armstrong_numbers
