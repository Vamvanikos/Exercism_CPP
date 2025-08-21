#include "parallel_letter_frequency.h"
#include <algorithm>

namespace parallel_letter_frequency {

std::unordered_map<char, std::size_t> frequency(std::vector<std::string_view> texts)
{
    std::unordered_map<char, std::size_t> countChars;
    for (const auto& view : texts)
    {
        std::for_each(view.begin(), view.end(), [&countChars] (const char ch)
            {
                if(std::isalpha(ch))
                    ++countChars[std::tolower(static_cast<unsigned char>(ch))];
            });
    }
    
    return countChars;
}
    
}
