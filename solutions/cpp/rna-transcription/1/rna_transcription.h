#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H
#include <string>
#include <map>

namespace rna_transcription {

// TODO: add your solution here
inline const std::map<char, char> dnaToRna = {{'G', 'C'}, {'C', 'G'}, {'T', 'A'}, {'A', 'U'}};
    
char to_rna(char nucleotide);
std::string to_rna(const std::string& nucleotide);

}  // namespace rna_transcription

#endif  // RNA_TRANSCRIPTION_H