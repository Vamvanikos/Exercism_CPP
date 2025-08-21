#include "diamond.h"
#include <stdexcept>
#include <cctype>

#include <iostream>

namespace diamond {

std::vector<std::string> rows(char letter)
{
    if (!std::isalpha(static_cast<unsigned char>(letter)))
        throw std::invalid_argument("Provided input is not valid letter.");
    letter = std::toupper(static_cast<unsigned char>(letter));

    const int boundary = letter - FIRST_LETTER;
    const int length = boundary * 2 + 1;
    std::vector<std::string> result(length, std::string(length, ' '));

    char inputLetter = FIRST_LETTER;
    for (int r = 0; r <= boundary; ++r)
    {
        const int left = boundary - r;
        const int right = boundary + r;
        const int revertedRow = length - r - 1;
        
        result[r][left] = inputLetter;
        result[r][right] = inputLetter;
        result[revertedRow][left] = inputLetter;
        result[revertedRow][right] = inputLetter++;
    }

    return result;
}

}  // namespace diamond
