#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H
#include <string>

namespace atbash_cipher {

// TODO: add your solution here
std::string encode(std::string plainText);
std::string decode(std::string cypherText);

}  // namespace atbash_cipher

#endif  // ATBASH_CIPHER_H