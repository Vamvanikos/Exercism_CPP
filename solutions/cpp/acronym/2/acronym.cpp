#include "acronym.h"
#include <cctype>

namespace acronym {

// TODO: add your solution here
std::string acronym(const std::string& phrase)
{
    std::string result;
    bool newWord = true;
    for (char ch : phrase)
    {
        if (newWord && std::isalpha(ch))
        {
            result += std::toupper(ch);
            newWord = false;
        }
        if (ch == ' ' || ch == '-')
            newWord = true;
    }

    return result;
}

}  // namespace acronym
