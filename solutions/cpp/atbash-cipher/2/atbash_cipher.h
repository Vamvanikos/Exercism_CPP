#pragma once
#include <string>

namespace atbash_cipher {

inline constexpr int SUM_OF_REVERTED_LETTERS = 219;
inline constexpr int GROUP_SIZE = 5;

char letterConverter(const char ch);

std::string encode(const std::string& plaintext);
std::string decode(const std::string& ciphertext);

}  // namespace atbash_cipher
