#include "atbash_cipher.h"
#include <sstream>
#include <cctype>
#include <stdexcept>

namespace atbash_cipher {

char letterConverter(const unsigned char ch)
{
    if (std::isalpha(static_cast<unsigned char>(ch)))
        return static_cast<char>(SUM_OF_REVERTED_LETTERS - std::tolower(ch));
    else if (std::isdigit(ch))
        return ch;
    
    throw std::invalid_argument("Letter to be converted must be alphanumeric.");
}

std::string encode(const std::string& plaintext)
{
    std::ostringstream ciphertext;
    int count = 0;
    
    for (const char ch : plaintext)
    {
        unsigned char uch = static_cast<unsigned char>(ch);
        if (!std::isalnum(uch))
            continue;
        
        if (count == GROUP_SIZE)
        {
            ciphertext << ' ';
            count = 0;
        }
        
        ciphertext << letterConverter(uch);
        ++count;
    }

    return ciphertext.str();
}

std::string decode(const std::string& ciphertext)
{
    std::ostringstream plaintext;

    for (const char ch : ciphertext)
    {
        unsigned char uch = static_cast<unsigned char>(ch);
        if (std::isalnum(uch))
            plaintext << letterConverter(uch);
    }

    return plaintext.str();
}

}  // namespace atbash_cipher
