#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H
#include <map>
#include <string>

namespace word_count {

// TODO: add your solution here
void clean_word_and_add(std::map<std::string, int>& wordsCount, std::string& word);
std::map<std::string, int> words(const std::string& sentence);
    
}  // namespace word_count

#endif  // WORD_COUNT_H