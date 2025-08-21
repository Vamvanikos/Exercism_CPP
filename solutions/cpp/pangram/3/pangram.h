#pragma once
#include <string>

namespace pangram {

inline constexpr int ALPHA_SIZE = 26;

bool is_pangram(const std::string& sentence);

}  // namespace pangram
