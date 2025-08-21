#include "affine_cipher.h"
#include <numeric>
#include <sstream>

namespace affine_cipher {

inline constexpr int mod_inverse(int a, int m = M) {
    int m0 = m, x0 = 0, x1 = 1;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

std::string encode(const std::string& plaintext, const int keyA, const int keyB)
{
    if (std::gcd(keyA, M) != 1)
        throw std::invalid_argument("Please provide a key A that is not coprime with m.");

    std::ostringstream ciphertext;
    int groupCount = 0;
    for (const char ch : plaintext)
    {
        if (!std::isalnum(static_cast<unsigned char>(ch)))
            continue;
        
        if (groupCount == GROUP_SIZE)
        {
            ciphertext << " ";
            groupCount = 0;
        }

        if (std::isdigit(static_cast<unsigned char>(ch)))
            ciphertext << ch;
        else
        {
            int idx = std::tolower(ch) - 'a';
            int encoded = (keyA * idx + keyB) % M;
            ciphertext << static_cast<char>('a' + encoded);
        }
        ++groupCount;
    }

    return ciphertext.str();
}
    
std::string decode(const std::string& ciphertext, const int keyA, const int keyB)
{
    if (std::gcd(keyA, M) != 1)
        throw std::invalid_argument("Please provide a key A that is not coprime with m.");

    const int invA = mod_inverse(keyA);
    std::ostringstream plaintext;
    for (const char ch : ciphertext)
    {
        if (!std::isalnum(static_cast<unsigned char>(ch)))
            continue;
        if (std::isdigit(static_cast<unsigned char>(ch)))
            plaintext << ch;
        else
        {
            int y = std::tolower(ch) - 'a';
            int decoded = invA * ((y - keyB + 2 * M) % M) % M;
            plaintext << static_cast<char>('a' + decoded);
        }
    }

    return plaintext.str();
}

}  // namespace affine_cipher