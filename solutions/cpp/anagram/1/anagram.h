#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <string>
#include <unordered_set>

namespace anagram {

// TODO: add your solution here
class anagram {
public:
anagram(const std::string& word);
std::unordered_set<std::string> matches(const std::unordered_set<std::string>& candidates);

private:
std::string to_lower(const std::string& word) const;
    
std::string m_word;
};

}  // namespace anagram

#endif  // ANAGRAM_H