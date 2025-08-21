#include "hamming.h"
#include <stdexcept>

namespace hamming {

// TODO: add your solution here
int compute(const std::string& dna1, const std::string& dna2)
{
    if (dna1.size() != dna2.size())
    {
        throw std::domain_error("dna sequences have different lengths.");
    }
    
    int distance = 0;
    for (size_t i = 0; i < dna1.size(); i++)
    {
        if (dna1[i] != dna2[i]) { ++distance; }
    }
    
    return distance;
}

}  // namespace hamming
