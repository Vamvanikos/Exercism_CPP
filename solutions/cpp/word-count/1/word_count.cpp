#include "word_count.h"
#include <algorithm>

namespace word_count {

// TODO: add your solution here
std::map<std::string, int> words(const std::string& sentence)
{
    std::map<std::string, int> wordsCount;
    std::string word;
    for (char ch : sentence)
    {
        if ((!word.empty() && ch == '\'') ||
            std::isalpha(ch)              ||
            std::isdigit(ch))
            
        {
            word += std::tolower(ch);
        }
        else
        {
            if (!word.empty())
            {
                if (word.back() == '\'')
                    word.pop_back();
                ++wordsCount[word];
                word = "";
            }
        }
    }

    if (!word.empty())
    {
        if (word.back() == '\'')
            word.pop_back();
        ++wordsCount[word];
    }
        
    return wordsCount;
}

}  // namespace word_count
