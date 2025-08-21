#include "rotational_cipher.h"
#include <cctype>
#include <stdexcept>

namespace rotational_cipher {

namespace {

constexpr char rotate_char(char ch, int rot)
{
    if (std::isupper(static_cast<unsigned char>(ch)))
        return static_cast<char>('A' + (ch - 'A' + rot) % 26);
    else if (std::islower(static_cast<unsigned char>(ch)))
        return static_cast<char>('a' + (ch - 'a' + rot) % 26);
    return ch;
}
    
} // namespace anonymous

std::string rotate(const std::string& input, int rot)
{
    if (rot < 0 || rot > 26)
        throw std::invalid_argument("Rotation number must be between 0-26.");
    
    std::string output;
    output.reserve(input.size());

    for (char ch : input)
        output.push_back(rotate_char(ch, rot));

    return output;
}

}  // namespace rotational_cipher
