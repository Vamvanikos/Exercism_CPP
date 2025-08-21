#include "trinary.h"
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>

namespace trinary {

// TODO: add your solution here
int to_decimal(std::string triString)
{
    int sum = 0;
    if (std::all_of(triString.begin(), triString.end(), ::isdigit))
    {
        int digit, power = triString.length() - 1;
        for (char ch : triString)
        {
            digit = ch - '0';
            sum += digit * pow(3, power--);
        }
    }

    return sum;
}

}  // namespace trinary
