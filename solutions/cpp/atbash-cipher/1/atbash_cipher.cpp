#include "atbash_cipher.h"
#include <cctype>
#include <algorithm>

namespace atbash_cipher {

// TODO: add your solution here
std::string encode(std::string plainText)
{
    std::string cypherText;
    int counter = 0;
    
    plainText.erase(std::remove(plainText.begin(), plainText.end(), ' '), plainText.end());
    
    for (char ch : plainText)
    {
        if (std::ispunct(ch)) { continue;}
        ch = std::tolower(ch);
        
        if ((ch >= 'a') && (ch <= 'z'))
        {
            ch = 'z' - (ch - 'a');
        }
        cypherText += ch;
        counter++;

        if (counter == 5)
        {
            cypherText += ' ';
            counter = 0;
        }
    }
    
    if (cypherText.back() == ' ')
    {
        cypherText.pop_back();
    }

    return cypherText;
}

std::string decode(std::string cypherText)
{
    std::string plainText;

    cypherText.erase(std::remove(cypherText.begin(), cypherText.end(), ' '), cypherText.end());

    for (char ch : cypherText)
    {
        if ((ch >= 'a') && (ch <= 'z'))
        {
            ch = 'z' - (ch - 'a');
        }
        plainText += ch;
    }

    return plainText;
}

}  // namespace atbash_cipher
