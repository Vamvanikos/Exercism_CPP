#include "say.h"
#include <stdexcept>
#include <sstream>
#include <vector>
#include <algorithm>


namespace say {

std::string two_digits_in_english(int num)
{
    if (num < 0 || num >= 100)
        throw std::invalid_argument("Number must be in the range 0-99.");
    
    int firstDigit = num % 10;
    int secondDigit = num / 10;

    switch (secondDigit)
    {
        case 0:
            return firstDigits.at(firstDigit);
        case 1:
            return tens.at(num);
        default:
            return firstDigit == 0 ? secondDigits.at(secondDigit) :
                   secondDigits.at(secondDigit) + "-" + firstDigits.at(firstDigit);
    }
}

std::string chunk_generator(int chunk)
{
    std::ostringstream chunkInEnglish;
    int remainder = chunk % 100;
    int hundreds = chunk / 100;

    if (hundreds > 0)
    {
        chunkInEnglish << firstDigits.at(hundreds) << " hundred";
        if (remainder != 0)
            chunkInEnglish << " ";
    }
    if (remainder != 0)
        chunkInEnglish << two_digits_in_english(remainder);

    return chunkInEnglish.str();
}

std::string in_english(long num)
{
    if (num < 0 || num > 999'999'999'999)
        throw std::domain_error("Input number must be in the range 0-999.999.999.999");

    if (num == 0)
        return firstDigits.at(0);
    
    std::vector<std::string> chunksVector;
    chunksVector.reserve(CHUNKS_MAX_NUMBER);
    while (num > 0)
    {
        std::ostringstream chunkStr;
        int numOfChunks = chunksVector.size();
        int chunk = num % 1000;
        num /= 1000;

        chunkStr << chunk_generator(chunk);
        if (numOfChunks != 0 && chunk != 0)
        {
            chunkStr << " " << scale.at(numOfChunks);
        }

        chunksVector.push_back(chunkStr.str());
    }

    std::reverse(chunksVector.begin(), chunksVector.end());
    std::ostringstream result;
    for (const auto& chunk : chunksVector)
    {
        if (!chunk.empty())
        {
            if (!result.str().empty())
                result << " ";
            result << chunk;
        }
    }
    
    return result.str();
}

}  // namespace say
