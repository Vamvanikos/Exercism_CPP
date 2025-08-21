#include "run_length_encoding.h"
#include <algorithm>
#include <stdexcept>
#include <cctype>

namespace run_length_encoding {

namespace {

static std::string add_to_encode(int counter, char ch)
{
    std::string encode_part;
    if (counter > 1)
        encode_part += std::to_string(counter);
    encode_part += ch;

    return encode_part;
}

} // namespace anonymous
    
std::string encode(const std::string& message)
{
    if (std::any_of(message.begin(), message.end(),
                    [] (unsigned char ch) { return !std::isalpha(ch) && !std::isspace(ch); }))
        throw std::invalid_argument("Message must include only characters and whitespaces.");

    if (message.empty())
        return "";

    std::string encodedMessage;
    encodedMessage.reserve(message.size());
    char prevCh = message.front();
    int counter = 1;
    for (char ch : message.substr(1))
    {
        if (ch == prevCh)
            ++counter;
        else
        {
            encodedMessage += add_to_encode(counter, prevCh);
            prevCh = ch;
            counter = 1;
        }
    }
    encodedMessage += add_to_encode(counter, prevCh);

    return encodedMessage;
}

std::string decode(const std::string& message)
{
    if (std::any_of(message.begin(), message.end(),
                    [] (unsigned char ch) { return std::ispunct(ch); }))
        throw std::invalid_argument("Message must not include punctuation.");

    if (message.empty())
        return "";

    std::string decodedMessage;
    decodedMessage.reserve(message.size());
    std::string iterNum;
    for (char ch : message)
        if (std::isdigit(static_cast<unsigned char>(ch)))
            iterNum += ch;
        else
        {
            if (iterNum.empty())
                decodedMessage += ch;
            else
            {
                decodedMessage += std::string(stoi(iterNum), ch);
                iterNum.clear();
            }
        }
    
    return decodedMessage;
}

}  // namespace run_length_encoding
