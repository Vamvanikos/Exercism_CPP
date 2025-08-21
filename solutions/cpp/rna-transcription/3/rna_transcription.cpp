#include "rna_transcription.h"
#include <unordered_map>
#include <stdexcept>

namespace rna_transcription {
    
char to_rna(const char nucleotide)
{
    switch (nucleotide)
    {
        case 'G': return 'C';
        case 'C': return 'G';
        case 'T': return 'A';
        case 'A': return 'U';
        default: throw std::invalid_argument(
                 "Nucleotide must be of type 'G', 'C', 'T', 'A'.");
    }
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
