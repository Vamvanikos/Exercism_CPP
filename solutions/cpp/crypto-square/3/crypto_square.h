#pragma once
#include <string>
#include <vector>

namespace crypto_square {

class cipher {
public:
    cipher(const std::string& text) : m_text(text) {};

    std::string normalized_cipher_text();
private:
    void remove_puncts_spaces();
    std::vector<std::string> create_rectangle();
    std::string create_encoded(const std::vector<std::string>& rectangleVector) const;
    
    std::string m_text;
    size_t m_row = 0;
    size_t m_col = 0;
};

}  // namespace crypto_square
