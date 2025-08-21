#include "anagram.h"
#include <algorithm>

namespace anagram {

// TODO: add your solution here
anagram::anagram(const std::string& word)
{
    m_word = to_lower(word);
    m_sorted = sort_word(m_word);
}
    
std::unordered_set<std::string> anagram::matches(const std::unordered_set<std::string>& candidates) const
{
    std::unordered_set<std::string> anagrams;

    for (const auto& candidate : candidates)
    {
        std::string lowered = to_lower(candidate);
        if (lowered == m_word)
            continue;
        if (sort_word(lowered) == m_sorted)
            anagrams.insert(candidate);
    }

    return anagrams;
}

std::string anagram::to_lower(const std::string& word)
{
    std::string lowered = word;
    std::transform(lowered.begin(), lowered.end(), lowered.begin(), [](char ch) {
        return std::tolower(static_cast<unsigned char>(ch));
    });

    return lowered;
}

std::string anagram::sort_word(const std::string& word)
{
    std::string sorted = word;
    std::sort(sorted.begin(), sorted.end());

    return sorted;
}

}  // namespace anagram
