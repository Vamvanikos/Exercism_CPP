#include "acronym.h"
#include <cctype>

namespace acronym {

// TODO: add your solution here
std::string acronym(const std::string& phrase)
{
    std::string acron;
    bool flag = true;
    for (char ch : phrase)
    {
        if (flag && std::isalpha(ch))
        {
            acron += std::toupper(ch);
            flag = false;
        }
        if (ch == ' ' || ch == '-')
            flag = true;
    }

    return acron;
}

}  // namespace acronym
