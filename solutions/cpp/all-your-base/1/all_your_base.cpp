#include "all_your_base.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace all_your_base {

// TODO: add your solution here
std::vector<unsigned int> convert(const unsigned int inputBase, const std::vector<unsigned int>& inputNumber, const unsigned int outputBase)
{
    if (inputBase <= 1)
        throw std::invalid_argument("Input base can't be zero or one.");

    if (outputBase <= 1)
        throw std::invalid_argument("Output base can't be zero or one.");

    for (const unsigned int inputElement : inputNumber)
    {
        if (inputElement >= inputBase)
            throw std::invalid_argument("Input number's element can't be same or greater than the input base.");
    }
    
    unsigned int extractedNum = 0;
    const size_t inputSize = inputNumber.size();
    for (size_t i = 0; i < inputSize; ++i)
    {
        extractedNum += inputNumber[i] * std::pow(inputBase, inputSize - i - 1);
    }

    std::vector<unsigned int> outputNumber;
    while (extractedNum != 0)
    {
        outputNumber.push_back(extractedNum % outputBase);
        extractedNum /= outputBase;
    }
    std::reverse(outputNumber.begin(), outputNumber.end());

    return outputNumber;
}

}  // namespace all_your_base
