#include "crypto_square.h"
#include <cctype>
#include <vector>

namespace crypto_square {

// TODO: add your solution here
cipher::cipher(const std::string& plainText) : m_plainText(plainText) {}

std::string cipher::normalized_cipher_text()
{
    std::string cipherText;
    for (char ch : m_plainText)
    {
        if (std::isalnum(ch))
            cipherText.push_back(std::tolower(ch));
    }

    if (cipherText.empty())
        return cipherText;
    
    std::size_t rows = 1, cols = 1;
    do {
        if (rows * cols >= cipherText.length())
            break;
        if (rows == cols)
            ++cols;
        else
            ++rows;
    } while (true);

    std::vector<std::vector<char>> rect(rows, std::vector<char>(cols));
    std::size_t index = 0;
    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < cols; ++j)
        {
            if (index < cipherText.size())
                rect[i][j] = cipherText[index++];
            else
                rect[i][j] = ' ';
        }
    }

    cipherText.clear();
    for (std::size_t j = 0; j < cols; ++j)
    {
        for (std::size_t i = 0; i < rows; ++i)
        {
            cipherText.push_back(rect[i][j]);
        }
        cipherText.push_back(' ');
    }

    if (cipherText.size() > rows * cols)
        cipherText.pop_back();

    return cipherText;
}

}  // namespace crypto_square
