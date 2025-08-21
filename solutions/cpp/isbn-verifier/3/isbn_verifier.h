#pragma once
#include <string>

namespace isbn_verifier {

inline constexpr int DIGITS_NUM = 10;
inline constexpr int LAST_INDEX = 9;

bool is_valid(const std::string& isbnCode);

}  // namespace isbn_verifier
