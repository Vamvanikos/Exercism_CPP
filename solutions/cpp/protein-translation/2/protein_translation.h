#pragma once
#include <vector>
#include <unordered_map>
#include <string>

namespace protein_translation {

inline constexpr int CODON_SIZE = 3;

inline const std::unordered_map<std::string_view, std::string_view> codonToAmino = {
    {"AUG", "Methionine"},
    {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"}, {"UUG", "Leucine"},
    {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
    {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
    {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
    {"UGG", "Tryptophan"},
    {"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}
};

std::vector<std::string> proteins(const std::string& sequence);

}  // namespace protein_translation
