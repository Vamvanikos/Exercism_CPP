#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

std::map<char, int> count(const std::string& sequence)
{
    int A = 0, C = 0, G = 0, T = 0;

    for (char ch : sequence)
    {
        switch (ch)
        {
            case 'A': ++A; break;
            case 'C': ++C; break;
            case 'G': ++G; break;
            case 'T': ++T; break;
            default: throw std::invalid_argument(
                     "Sequence must include only 'A', 'C', 'G', 'T' characters.");
        }
    }

    return {{'A', A}, {'C', C}, {'G', G}, {'T', T}};
}

}  // namespace nucleotide_count
