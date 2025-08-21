#include "anagram.h"
#include <algorithm>

namespace anagram {

// TODO: add your solution here
anagram::anagram(const std::string& word)
{
    m_word = to_lower(word);
}
    
std::unordered_set<std::string> anagram::matches(const std::unordered_set<std::string>& candidates)
{
    std::unordered_set<std::string> anagrams;
    for (const std::string& word : candidates)
    {
        std::string lowcaseWord = to_lower(word);
        if (lowcaseWord == m_word || lowcaseWord.length() != m_word.length())
            continue;
        for (char ch : m_word)
            {
                auto pos = lowcaseWord.find(ch);
                if (pos != std::string::npos)
                    lowcaseWord.erase(pos, 1);
                else
                    continue;
            }
        if (lowcaseWord.empty())
            anagrams.insert(word);
    }

    return anagrams;
}

std::string anagram::to_lower(const std::string& word) const
{
    std::string result(word.size(), '\0');
    std::transform(word.begin(), word.end(), result.begin(), [](char ch) { return std::tolower(static_cast<unsigned char>(ch)); });

    return result;
}

}  // namespace anagram
