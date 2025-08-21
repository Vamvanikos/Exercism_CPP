#include "hamming.h"
#include <stdexcept>
#include <unordered_set>

namespace hamming {

static const std::unordered_set<char> dnaLetters = {'C', 'A', 'G', 'T'};
    
void validateLetters (const std::string& dna)
{    
    for (char ch : dna)    
        if (dnaLetters.find(ch) == dnaLetters.end())
            throw std::domain_error("DNA letters must be one of C, A, G, T.");
};
    
int compute(const std::string& dna1, const std::string& dna2)
{
    if (dna1.size() != dna2.size())
        throw std::domain_error("DNAs must have the same size.");

    validateLetters(dna1);
    validateLetters(dna2);
    
    int distance = 0;
    for (size_t i = 0; i < dna1.size(); ++i)    
        if (dna1[i] != dna2[i])
            ++distance;

    return distance;
}

}  // namespace hamming
