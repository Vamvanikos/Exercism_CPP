#ifndef AFFINE_CIPHER_H
#define AFFINE_CIPHER_H
#include <string>

namespace affine_cipher {

inline constexpr int M = 26;
inline constexpr int GROUP_SIZE = 5;

std::string encode(const std::string& plaintext, const int keyA, const int keyB);
std::string decode(const std::string& ciphertext, const int keyA, const int keyB);

}  // namespace affine_cipher

#endif  // AFFINE_CIPHER_H