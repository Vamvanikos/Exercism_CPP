#include "all_your_base.h"
#include <stdexcept>
#include <algorithm>

namespace all_your_base {

std::vector<unsigned int> convert(unsigned int initBase, const std::vector<unsigned int>& number, unsigned int newBase)
{
    if (initBase < minBase)
        throw std::invalid_argument("Initial base can't be lower than 2.");
    if (newBase < minBase)
        throw std::invalid_argument("New base can't be lower than 2.");  
    for (unsigned int digit : number)
        if (digit >= initBase)
            throw std::invalid_argument("Digit of initial number can't be same or greater than the initial base.");

    int dec = 0;
    for (unsigned int digit : number)
        dec = dec * initBase + digit;

    std::vector<unsigned int> result;
    while (dec != 0)
    {
        result.emplace_back(dec % newBase);
        dec /= newBase;
    }
    std::reverse(result.begin(), result.end());

    return result;
}

}  // namespace all_your_base
