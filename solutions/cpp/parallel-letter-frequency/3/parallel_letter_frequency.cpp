#include "parallel_letter_frequency.h"
#include <algorithm>
#include <execution>

namespace parallel_letter_frequency {

std::unordered_map<char, std::size_t> frequency(const std::vector<std::string_view>& texts)
{
    std::vector<std::unordered_map<char, std::size_t>> listsOfTexts(texts.size());

    std::for_each(std::execution::par, texts.begin(), texts.end(),
        [&texts, &listsOfTexts] (const std::string_view& view) 
    {
        std::unordered_map<char, std::size_t>& list = listsOfTexts[&view - &texts[0]];

        for (const char ch : view)
        {
            if (std::isalpha(static_cast<unsigned char>(ch)))
                ++list[std::tolower(static_cast<unsigned char>(ch))];
        }
    });

    std::unordered_map<char, std::size_t> results;
    for (const auto& list : listsOfTexts)
        {
            for (const auto& [ch, count] : list)
                results[ch] += count;
        }

    return results;
}

}
