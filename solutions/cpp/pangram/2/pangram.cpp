#include "pangram.h"

namespace pangram {

bool is_pangram(const std::string& sentence)
{
    if (sentence.size() < ALPHA_SIZE)
        return false;

    std::unordered_set<char> letters;
    letters.reserve(ALPHA_SIZE);
    for (const char let : sentence)
    {
        if (std::isalpha(static_cast<unsigned char>(let)))
        {
            letters.insert(std::tolower(static_cast<unsigned char>(let)));
            if (letters.size() == ALPHA_SIZE)
                return true;
        }
    }

    return false;
}

}  // namespace pangram
