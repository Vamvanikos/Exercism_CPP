#include "word_count.h"
#include <algorithm>

namespace word_count {

// TODO: add your solution here

void clean_word_and_add(std::map<std::string, int>& wordsCount, std::string& word)
{
    if (!word.empty())
    {
        if (word.back() == '\'')
            word.pop_back();
        ++wordsCount[word];
        word.clear();
    }
}
    
std::map<std::string, int> words(const std::string& sentence)
{
    std::map<std::string, int> wordsCount;
    std::string word;
    for (char ch : sentence)
    {
        if ((!word.empty() && ch == '\'') ||
            std::isalnum(ch))
        {
            word += std::tolower(ch);
        }
        else
        {
            clean_word_and_add(wordsCount, word);
        }
    }
    clean_word_and_add(wordsCount, word);
        
    return wordsCount;
}

}  // namespace word_count
