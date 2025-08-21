#include "protein_translation.h"

namespace protein_translation {

// TODO: add your solution here
std::vector<std::string> proteins(const std::string& rna)
{
    std::vector<std::string> codons;
    std::vector<std::string> aminos;
    for (size_t i = 0; i < rna.size(); i += 3)
    {
        codons.push_back(rna.substr(i, 3));
    }

    bool fl = false;
    for (const auto& codon : codons)
    {
        for (const auto& codonPair : codonMap )
        {
            if (codon == codonPair.first)
            {
                if (codonPair.second == "STOP") { fl = true; }
                else { aminos.push_back(codonPair.second); }
                break;
            }
        }
        if (fl) {break;}
    }
    
    return aminos;
}

std::unordered_map<std::string, std::string> codonMap =
{
    {"AUG", "Methionine"},
    {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"}, {"UUG", "Leucine"},
    {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
    {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
    {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
    {"UGG", "Tryptophan"},
    {"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}
};

}  // namespace protein_translation
