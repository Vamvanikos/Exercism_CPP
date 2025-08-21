#include "word_count.h"
#include <cctype>

namespace word_count {

void add_word(std::string& word, std::map<std::string, int>& wordsMap)
{
    if (!word.empty())
    {
        if (word.back() == '\'')
            word.pop_back();
        ++wordsMap[word];
        word.clear();
    }
}

std::map<std::string, int> words(const std::string& sentence)
{
    std::map<std::string, int> wordsMap;
    std::string word;
    for (char ch : sentence)
    {
        if (std::isalnum(ch) || (!word.empty() && ch == '\''))
            word += std::tolower(ch);
        else 
            add_word(word, wordsMap);
    }

    add_word(word, wordsMap);   

    return wordsMap;
}

}  // namespace word_count
