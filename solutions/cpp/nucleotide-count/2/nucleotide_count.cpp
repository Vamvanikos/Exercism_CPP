#include "nucleotide_count.h"
#include <unordered_set>
#include <stdexcept>

namespace nucleotide_count {

std::map<char, int> count(const std::string& sequence)
{
    std::map<char, int> nucleotideCount = {
        {'A', 0},
        {'C', 0},
        {'G', 0},
        {'T', 0}
    };
    
    for (char ch : sequence)
    {
        auto it = nucleotideCount.find(ch);
        if (it == nucleotideCount.end())
            throw std::invalid_argument(
                  "Sequence must include only 'A', 'C', 'G', 'T' characters.");

        ++it->second;
    }

    return nucleotideCount;
}

}  // namespace nucleotide_count
