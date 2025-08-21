#include "diamond.h"
#include <stdexcept>

namespace diamond {

// TODO: add your solution here
std::vector<std::string> rows(const char diamondLetter)
{
    if (diamondLetter < 'A' || diamondLetter > 'Z')
        throw std::invalid_argument("Invalid argument. Input should be A-Z.");

    const int boundary = diamondLetter - 'A';
    const int length = boundary * 2 + 1;
    std::vector<std::string> result;
    result.reserve(length);
    for (int r = 0; r < boundary + 1; ++r)
    {
        std::string row;
        row.reserve(length);
        for (int c = 0; c < length; ++c)
        {
            if ((c == boundary - r) || (c == boundary + r))
                row.push_back('A' + r);
            else
                row.push_back(' ');
        }
        result.push_back(row);
    }

    for (int r = boundary - 1; r >= 0; --r )
        result.push_back(result[r]);

    return result;
}

}  // namespace diamond
