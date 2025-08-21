#include "say.h"
#include <stdexcept>
#include <sstream>

namespace say {

std::string ThousandsToString(int number)
{
    if (number < LOW_BOUND || number >= CHUNKS_OF_THOUSANDS)
        throw std::domain_error("Input number must be between 0-999");

    std::ostringstream result;
    const int hundreds = number / CHUNKS_OF_HUNDREDS;
    const int remainder = number % CHUNKS_OF_HUNDREDS;

    if (hundreds > 0)
    {
        result << oneDigitNums.at(number / CHUNKS_OF_HUNDREDS) << " hundred";
        if (remainder > 0)
            result << " ";
    }

    if (remainder > CHUNKS_OF_TENS && remainder <= TEEN_MAX)
            result  << TeenNums.at(remainder);
    else
    {
        const int firstDigit = remainder % CHUNKS_OF_TENS;
        const int secondDigit = remainder / CHUNKS_OF_TENS;
        if (twoDigitNums.find(secondDigit) != twoDigitNums.end())
        {
            result << twoDigitNums.at(secondDigit);
            if (firstDigit > 0)
                result << "-" << oneDigitNums.at(firstDigit);
        }
        else if (firstDigit > 0)
            result << oneDigitNums.at(firstDigit);
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
        const int chunk = number % CHUNKS_OF_THOUSANDS;
        if (chunk)
        {
            std::string part = ThousandsToString(chunk);
            if (magnitude)
                part += " " + std::string(Magnitude.at(magnitude));
            if (!result.empty())
                part += " ";
            result = part + result;
        }
        number /= CHUNKS_OF_THOUSANDS;
        ++magnitude;
    }

    return result;
}

}  // namespace say
