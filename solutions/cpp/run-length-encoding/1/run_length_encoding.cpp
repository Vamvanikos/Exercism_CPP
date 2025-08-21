#include "run_length_encoding.h"
#include <cctype>
#include <stdexcept>

namespace run_length_encoding {

std::string encode(const std::string& inputString)
{    
    if (inputString.empty())
        return "";
    
    for (const char ch : inputString)
    {
        if (!std::isalpha(static_cast<unsigned char>(ch)) && !std::isspace(static_cast<unsigned char>(ch)))
            throw std::invalid_argument("String can contain only characters and whitespaces.");
    }

    std::string encoded;
    encoded.reserve(inputString.size());
    char prevCh = inputString.front();
    int count = 1;
    for (size_t i = 1; i < inputString.size(); ++i)
    {
        if (prevCh != inputString[i])
        {
            encoded += addEncode(prevCh, count);
            prevCh = inputString[i];
            count = 0;
        }
        ++count;
    }
    encoded += addEncode(prevCh, count);

    return encoded;
}

std::string decode(const std::string& inputString)
{
    std::string plain;
    plain.reserve(inputString.size());
    std::string num;

    for (const char ch : inputString)
    {
        if (std::isdigit(static_cast<unsigned char>(ch)))
            num += ch;
        else
        {
            int count = num.empty() ? 1 : std::stoi(num);
            plain.append(count, ch);
            num.clear();
        }
    }

    return plain;
}

}  // namespace run_length_encoding
