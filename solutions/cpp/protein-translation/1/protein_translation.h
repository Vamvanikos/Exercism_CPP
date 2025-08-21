#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H
#include <string>
#include <vector>
#include <unordered_map>

namespace protein_translation {

// TODO: add your solution here
std::vector<std::string> proteins(const std::string& rna);

extern std::unordered_map<std::string, std::string> codonMap;

}  // namespace protein_translation

#endif  // PROTEIN_TRANSLATION_H
