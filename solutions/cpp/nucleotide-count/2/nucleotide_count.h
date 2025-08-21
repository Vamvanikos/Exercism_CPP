#pragma once
#include <string>
#include <map>

namespace nucleotide_count {

std::map<char, int> count(const std::string& sequence);

}  // namespace nucleotide_count
