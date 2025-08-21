#include "etl.h"
#include <cctype>

namespace etl {

std::map<char, int> transform(const std::map<int, std::vector<char>>& oldFormat)
{
    std::map<char, int> newFormat;
    for (const auto& [score, letters] : oldFormat)
        for (char letter : letters)
            newFormat.emplace(std::tolower(static_cast<unsigned char>(letter)), score);

    return newFormat;
}

}  // namespace etl
