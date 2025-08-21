#include "anagram.h"
#include <algorithm>

namespace anagram {

anagram::anagram(const std::string& target) : m_target(to_lower(target)) {}

std::unordered_set<std::string> anagram::matches(const std::unordered_set<std::string>& candidates) const
{
    if (candidates.empty() || m_target.empty())
        return {};

    std::string sortedTarget = sort_word(m_target);
    std::unordered_set<std::string> anagrams;
    for (const std::string& candidate : candidates)
    {
        std::string candidateCheck = to_lower(candidate);
        if (candidateCheck == m_target)
            continue;

        if (sort_word(candidateCheck) == sortedTarget)
            anagrams.emplace(candidate);
    }

    return anagrams;
}

std::string anagram::to_lower(const std::string& word) const
{
    std::string lower = word;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    return lower;
}

std::string anagram::sort_word( const std::string& word) const
{
    std::string sorted = word;
    std::sort(sorted.begin(), sorted.end());

    return sorted;
}

}  // namespace anagram
