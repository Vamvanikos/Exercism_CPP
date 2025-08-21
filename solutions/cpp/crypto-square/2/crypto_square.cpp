#include "crypto_square.h"
#include <cctype>
#include <cmath>
#include <vector>

namespace crypto_square {

// TODO: add your solution here
cipher::cipher(const std::string& plainText)
{
    for (char ch : plainText)
    {
        if (std::isalnum(ch))
            m_plainText.push_back(std::tolower(ch));
    }
}

std::string cipher::normalized_cipher_text()
{
    if (m_plainText.empty())
        return m_plainText;

    std::size_t len = m_plainText.length();
    std::size_t cols = std::ceil(std::sqrt(len));
    std::size_t rows = (cols * (cols - 1) >= len) ? cols - 1 : cols;

    std::vector<std::string> rect(rows, std::string(cols, ' '));
    std::size_t index = 0;
    for (std::size_t r = 0; r < rows && index < len; ++r)
    {
        for (std::size_t c = 0; c < cols && index < len; ++c)
            rect[r][c] = m_plainText[index++];
    }

    std::string cipherText;
    for (std::size_t c = 0; c < cols; ++c)
    {
        for (std::size_t r = 0; r < rows; ++r)
        {
            if (c < rect[r].size())
                cipherText.push_back(rect[r][c]);
        }
        if (c < cols - 1)
            cipherText.push_back(' ');
    }

    return cipherText;
}

}  // namespace crypto_square
