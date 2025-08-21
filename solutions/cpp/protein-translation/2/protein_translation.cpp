#include "protein_translation.h"
#include <stdexcept>

namespace protein_translation {

std::vector<std::string> proteins(const std::string& sequence)
{
    std::vector<std::string> aminosVector;
    size_t idx = 0;
    while (idx < sequence.size())
    {
        std::string codon = sequence.substr(idx, CODON_SIZE);
        if (codon.size() != CODON_SIZE)
            throw std::invalid_argument("Codon name size is different to the expected one (3).");
        
        auto it = codonToAmino.find(codon);
        if (it == codonToAmino.end())
            throw std::invalid_argument("Input contains not recognizable Codons.");
        if (it->second == "STOP")
            break;
        aminosVector.emplace_back(static_cast<std::string>(it->second));
        idx += CODON_SIZE;
    }

    return aminosVector;
}

}  // namespace protein_translation
