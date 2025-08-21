#include "rna_transcription.h"
#include <stdexcept>

namespace rna_transcription {

// TODO: add your solution here
char to_rna(char nucleotide)
{
    std::map<char, char>::const_iterator it = dnaToRna.find(nucleotide);
    if (it == dnaToRna.end())
    {
        throw std::invalid_argument("Invalid code for nucleotide.");
    }

    return it->second;
}
    
std::string to_rna(const std::string& nucleotide)
{
    std::string rna;
    for (char ch : nucleotide)
    {
        rna += to_rna(ch);
    }

    return rna;
}

}  // namespace rna_transcription
