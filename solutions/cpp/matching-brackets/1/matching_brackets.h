#if !defined(MATCHING_BRACKETS_H)
#define MATCHING_BRACKETS_H
#include <string>
#include <unordered_map>

namespace matching_brackets {

// TODO: add your solution here
bool check(const std::string& bracketsString);

extern std::unordered_map<char, char> matchingBrackets;

}  // namespace matching_brackets

#endif  // MATCHING_BRACKETS_H