#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace matching_brackets {

inline const std::unordered_map<char, char> bracketPairs = {
    {')', '('},
    {'}', '{'},
    {']', '['}
};

inline const std::unordered_set<char> openingBrackets = {'(', '{', '['};
    
bool check(const std::string& text);

}  // namespace matching_brackets
