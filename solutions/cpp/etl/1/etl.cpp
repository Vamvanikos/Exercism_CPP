#include "etl.h"
#include <cctype>

namespace etl {

// TODO: add your solution here
std::map<char, int> transform(const std::map<int, std::vector<char>>& pointsToLetters)
{
    std::map<char, int> lettersToPoints;
    for (const auto& [points, letters] : pointsToLetters)
    {
        for (char ch : letters)
                lettersToPoints.emplace(std::tolower(ch), points);
    }

    return lettersToPoints;
}

}  // namespace etl
