#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <string>
#include <unordered_set>

namespace anagram {

// TODO: add your solution here
class anagram {
public:
explicit anagram(const std::string& word);
std::unordered_set<std::string> matches(const std::unordered_set<std::string>& candidates) const;

private:
static std::string to_lower(const std::string& word);
static std::string sort_word(const std::string& word);
    
std::string m_word;
std::string m_sorted;
};

}  // namespace anagram

#endif  // ANAGRAM_H