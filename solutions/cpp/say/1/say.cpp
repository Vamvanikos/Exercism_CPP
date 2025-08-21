#include "say.h"
#include <stdexcept>
#include <sstream>

namespace say {

std::string ThousandsToString(int number)
{
    if (number < LOW_BOUND || number > HIGH_BOUND_THOUSANDS)
        throw std::domain_error("Input number must be between 0-999");

    std::ostringstream result;

    if (number > HIGH_BOUND_HUNDREDS)
    {
        result << oneDigitNums.at(number / CHUNKS_OF_HUNDREDS) << " hundred";
    }
    
    if (number % CHUNKS_OF_HUNDREDS)
    {
        number %= CHUNKS_OF_HUNDREDS;
        if (!result.str().empty())
            result << " ";

        if (twoDigitNums.find(number / CHUNKS_OF_TENS) != twoDigitNums.end())
        {
            if (TenNums.find(number) != TenNums.end())
            {
                result  << TenNums.at(number);
                return result.str();
            }
            else
            {
                result << twoDigitNums.at(number / CHUNKS_OF_TENS);
                if (oneDigitNums.find(number % CHUNKS_OF_TENS) != oneDigitNums.end())
                    result << "-";
            }
        }
        
        if (oneDigitNums.find(number % CHUNKS_OF_TENS) != oneDigitNums.end())
            result << oneDigitNums.at(number % CHUNKS_OF_TENS);
    }

    return result.str();
}


std::string in_english(long number)
{
    if (number < LOW_BOUND || number > HIGH_BOUND)
        throw std::domain_error("Input number must be between 0-999.999.999.999.");

    if (number == 0)
        return "zero";
    
    std::string result;
    int magnitude = 0;
    while (number > 0)
    {
        if (number % CHUNKS_OF_THOUSANDS)
        {
            if (magnitude)
            {
                if (!result.empty())
                    result.insert(0, " ");
                result.insert(0, " " + std::string(Magnitude.at(magnitude)));
            }
            result.insert(0, ThousandsToString(number % CHUNKS_OF_THOUSANDS));
        }
        number /= CHUNKS_OF_THOUSANDS;
        ++magnitude;
    }

    return result;
}

}  // namespace say
