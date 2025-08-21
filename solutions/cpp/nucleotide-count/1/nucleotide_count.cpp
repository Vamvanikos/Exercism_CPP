#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

// TODO: add your solution here
const std::map<char, int> count(const std::string& dna)
{
    std::map<char, int> nucleotides = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
    for (char ch : dna)
    {
        if (nucleotides.find(ch) == nucleotides.end())
        {
            throw std::invalid_argument("The given nucleotide code does not exist.");
        }
        
        ++nucleotides[ch];
    }

    return nucleotides;
}

}  // namespace nucleotide_count
