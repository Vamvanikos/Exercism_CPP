#pragma once
#include <string>
#include <unordered_set>

namespace anagram {

class anagram {
public:
    anagram(const std::string& target);

    std::unordered_set<std::string> matches(const std::unordered_set<std::string>& candidates) const;
private:
    std::string m_target;
    
};

}  // namespace anagram
