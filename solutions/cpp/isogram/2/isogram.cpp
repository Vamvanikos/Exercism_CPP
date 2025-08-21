#include "isogram.h"
#include <unordered_set>
#include <cctype>

namespace isogram {

// TODO: add your solution here
bool is_isogram(const std::string& word)
{
    std::unordered_set<char> wordSet;
    for (char ch : word)
    {
        if (std::isalpha(static_cast<unsigned char>(ch)))
        {
            ch = std::tolower(static_cast<unsigned char>(ch));
            if (wordSet.find(ch) != wordSet.end())
                return false;
            else
                wordSet.insert(ch);
        }
    }

    return true;
}

}  // namespace isogram
