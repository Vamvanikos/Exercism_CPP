#include "crypto_square.h"
#include <algorithm>
#include <cmath>

namespace crypto_square {

void cipher::remove_puncts_spaces()
{
    auto newEnd = std::remove_if(m_text.begin(), m_text.end(),
        [](unsigned char ch){ return !std::isalnum(ch); });
    m_text.erase(newEnd, m_text.end());
    std::transform(m_text.begin(), m_text.end(), m_text.begin(),
        [](unsigned char ch) { return std::tolower(ch); });
}

std::vector<std::string> cipher::create_rectangle()
{
    // Find rectangle size
    size_t size = m_text.size();
    m_row = std::sqrt(size);
    m_col = m_row;
    while (m_col * m_row < size)
        (m_col == m_row) ? ++m_col : ++m_row;

    // Create rectangle
    std::vector<std::string> rectangleVector(m_row, std::string(m_col, ' '));
    for (size_t i = 0; i < m_text.size(); ++i)
        rectangleVector[i / m_col][i % m_col] = m_text[i];

    return rectangleVector;
}

std::string cipher::create_encoded(const std::vector<std::string>& rectangleVector) const
{
    std::string output;
    output.reserve(m_text.size());
    for (size_t i = 0; i < m_col; ++i)
    {
        for (size_t j = 0; j < m_row; ++j)
            output += rectangleVector[j][i];
        if (i != m_col - 1)
            output += ' ';
    }

    return output;
}
    
std::string cipher::normalized_cipher_text()
{
    remove_puncts_spaces();
    if (m_text.empty())
        return "";

    std::vector<std::string> rectangleVector = create_rectangle();

    return create_encoded(rectangleVector);
}

}  // namespace crypto_square
