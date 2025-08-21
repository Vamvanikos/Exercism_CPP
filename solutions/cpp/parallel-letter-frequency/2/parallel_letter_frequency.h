#if !defined(PARALLEL_LETTER_FREQUENCY_H)
#define PARALLEL_LETTER_FREQUENCY_H

#include <unordered_map>
#include <vector>
#include <string>

namespace parallel_letter_frequency {

std::unordered_map<char, std::size_t> frequency(std::vector<std::string_view> texts);
    
}

#endif
