#include "rna_transcription.h"
#include <unordered_map>
#include <stdexcept>

namespace rna_transcription {

namespace {
    
const std::unordered_map<char, char> dnaToRna = {
    {'G', 'C'},
    {'C', 'G'},
    {'T', 'A'},
    {'A', 'U'}
};

}
    
char to_rna(const char nucleotide)
{
    auto it = dnaToRna.find(nucleotide);
    if (it == dnaToRna.end())
        throw std::invalid_argument("Nucleotide must be of type 'G', 'C', 'T', 'A'.");

    return it->second;
}

std::string to_rna(const std::string& sequence)
{
    std::string rna;
    rna.reserve(sequence.size());
    
    for (char ch : sequence)
        rna.push_back(to_rna(ch));

    return rna;
}

}  // namespace rna_transcription
