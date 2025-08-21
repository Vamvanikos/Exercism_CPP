#include "trinary.h"
#include <cmath>
#include <stdexcept>

namespace trinary {

int to_decimal(const std::string trinaryNum)
{    
    int numSize = trinaryNum.size();
    if (numSize == 0)
        throw std::invalid_argument("Numeric string can't be empty.");
    
    int result = 0;
    for (char digit : trinaryNum)
    {
        if (digit < '0' || digit > '2')
            return 0;
        result += static_cast<int>(digit - '0') * std::pow(3, --numSize);
        //result = result * 3 + (digit - '0');
    }

    return result;
}

}  // namespace trinary
