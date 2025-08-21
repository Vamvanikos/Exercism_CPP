#include "diamond.h"
#include <stdexcept>

namespace diamond {

std::vector<std::string> rows(const char diamondLetter)
{
    if (diamondLetter < 'A' || diamondLetter > 'Z')
        throw std::invalid_argument("Invalid argument. Input should be A-Z.");

    const int boundary = diamondLetter - 'A';
    const int length = boundary * 2 + 1;
    std::vector<std::string> result(length, std::string(length, ' '));
    
    for (int i = 0; i <= boundary; ++i)
    {
        const char ch = 'A' + i;
        result[i][boundary - i] = ch;
        result[i][boundary + i] = ch;
        result[length - 1 - i][boundary - i] = ch;
        result[length - 1 - i][boundary + i] = ch;
    }

    return result;
}

}  // namespace diamond
