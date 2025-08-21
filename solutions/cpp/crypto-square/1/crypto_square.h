#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H

#include <string>

namespace crypto_square {

// TODO: add your solution here
class cipher {
public:
cipher(const std::string& plainText);
std::string normalized_cipher_text();

private:
std::string m_plainText;
    
};

}  // namespace crypto_square

#endif  // CRYPTO_SQUARE_H