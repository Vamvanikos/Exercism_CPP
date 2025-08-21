#include "anagram.h"
#include <algorithm>

namespace anagram {

anagram::anagram(const std::string& target)
{
    m_target.resize(target.size()) ;
    std::transform(target.begin(), target.end(), m_target.begin(), ::tolower);
}

std::unordered_set<std::string> anagram::matches(const std::unordered_set<std::string>& candidates) const
{
    if (candidates.empty() || m_target.empty())
        return {};

    std::unordered_set<std::string> anagrams;
    for (const std::string& candidate : candidates)
    {
        std::string candidateCheck(candidate.size(), '\0');
        std::transform(candidate.begin(), candidate.end(), candidateCheck.begin(), ::tolower);
        if (candidateCheck == m_target)
            continue;
        for (char ch : m_target)
        {
            auto pos = candidateCheck.find(ch);
            if (pos != std::string::npos)
                candidateCheck.erase(pos, 1);
            else
                break;
        }
        if (candidateCheck.empty())
            anagrams.emplace(candidate);
    }

    return anagrams;
}

}  // namespace anagram
