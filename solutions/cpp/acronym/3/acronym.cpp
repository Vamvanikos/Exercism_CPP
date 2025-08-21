#include "acronym.h"

namespace acronym {

std::string acronym(const std::string& phrase)
{
    if (phrase.empty())
        return "";

    std::string acr;
    bool newWord = true;
    for (char ch : phrase)
    {
        if (newWord && std::isalpha(ch))
        {
            acr += std::toupper(ch);
            newWord = false;
        }
        else if (ch == ' ' || ch == '-')
            newWord = true;
    }

    return acr;    
}

}  // namespace acronym
