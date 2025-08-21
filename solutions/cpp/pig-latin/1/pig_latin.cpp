#include "pig_latin.h"
#include <sstream>

namespace pig_latin {

namespace{

inline bool goesBack(const std::string& word,const std::size_t idx)
{
    const char ch = word[idx];
    const char nextCh = (idx + 1 < word.size() ? word[idx + 1] : '\0');

    if (vowels.find(ch) != vowels.end())
        return false;
    if (ch == 'y' && idx != 0)
        return false;
    if (ch == 'x' && nextCh == 'r')
        return false;
    if (ch == 'y' && nextCh == 't')
        return false;
    return true;
}

}

std::string translateWord(const std::string& word)
{
    std::size_t i = 0;
    while (i < word.size() && goesBack(word, i))
    {
        if ((i + 1) < word.size() &&
            word[i] == 'q' && word[i+1] == 'u')
        {
            i += 2;
            break;
        }
        ++i;
    }

    return word.substr(i) + word.substr(0, i) + "ay";
}

std::string translate(const std::string& normalWord)
{
    std::istringstream iss(normalWord);
    std::ostringstream oss;
    std::string newWord;
    bool first = true;
    while (iss >> newWord)
    {
        if (!first)
            oss << " ";
        oss << translateWord(newWord);
        first = false;
    }
    
    return oss.str();
}

}  // namespace pig_latin
