#pragma once
#include <string>
#include <unordered_set>

namespace pig_latin {

inline const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

std::string translateWord(const std::string& newWord);
std::string translate(const std::string& normalWord);

}  // namespace pig_latin
