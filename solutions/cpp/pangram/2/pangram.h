#pragma once
#include <string>
#include <unordered_set>

namespace pangram {

inline constexpr int ALPHA_SIZE = 26;

bool is_pangram(const std::string& sentence);

}  // namespace pangram
