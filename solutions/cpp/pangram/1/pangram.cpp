#include "pangram.h"
#include <unordered_set>

namespace pangram {

// TODO: add your solution here
bool is_pangram(std::string candidateString)
{
    bool ret = true;
    std::unordered_set<char> chars;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (candidateString.find(ch) == std::string::npos)
        {
            if (candidateString.find(std::toupper(ch)) == std::string::npos)
            {
                ret = false;
                break;
            }
        }
    }

    return ret;
}

}  // namespace pangram
