#include "isogram.h"
#include <unordered_set>

namespace isogram {

bool is_isogram(const std::string& candidate)
{
    std::unordered_set<char> isoLetters;
    auto lettersEnd = isoLetters.end();
    for (char ch : candidate)
    {
        if (std::isalpha(static_cast<unsigned char>(ch)))
        {
            ch = std::tolower(static_cast<unsigned char>(ch));
            if (isoLetters.find(ch) != lettersEnd)
                return false;
            
            isoLetters.insert(ch);
        }
    }

    return true;
}

}  // namespace isogram
