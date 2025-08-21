#include "rotational_cipher.h"

namespace rotational_cipher {

// TODO: add your solution here
std::string rotate(std::string plainText, int rotKey)
{
    std::string cypherText;

    for (char ch : plainText)
    {
        if (std::isupper(ch))
        {
            cypherText += ('A' + (ch - 'A' + rotKey) % 26);
        }
        else if (std::islower(ch))
        {
            cypherText += ('a' + (ch - 'a' + rotKey) % 26);
        }
        else
        {
            cypherText += ch;
        }
    }

    return cypherText;
}

}  // namespace rotational_cipher
