#include "all_your_base.h"
#include <algorithm>
#include <stdexcept>

namespace all_your_base {

// TODO: add your solution here
std::vector<unsigned int> convert(
    const unsigned int inputBase,
    const std::vector<unsigned int>& inputDigits,
    const unsigned int outputBase)
{
    if (inputBase < 2)
        throw std::invalid_argument("Input base can't be zero or one.");

    if (outputBase < 2)
        throw std::invalid_argument("Output base can't be zero or one.");

    if (inputDigits.empty() || std::all_of(inputDigits.begin(), inputDigits.end(),
        [] (const unsigned int digit) { return digit == 0; }))
    {
        return {};
    }

    for (const unsigned int digit : inputDigits)
    {
        if (digit >= inputBase)
            throw std::invalid_argument("Digit out of range for input base.");
    }
    
    unsigned int decimal = 0;
    for (const unsigned int digit : inputDigits)
        decimal = decimal * inputBase + digit;

    std::vector<unsigned int> outputNumber;
    while (decimal > 0)
    {
        outputNumber.push_back(decimal % outputBase);
        decimal /= outputBase;
    }
    std::reverse(outputNumber.begin(), outputNumber.end());

    return outputNumber;
}

}  // namespace all_your_base
