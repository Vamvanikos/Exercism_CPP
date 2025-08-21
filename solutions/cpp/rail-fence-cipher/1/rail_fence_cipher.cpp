#include "rail_fence_cipher.h"
#include <vector>
#include <stdexcept>
#include <sstream>

namespace rail_fence_cipher {

namespace {

inline constexpr bool isSameText(const size_t& textSize, const int numRails)
{
    return static_cast<size_t>(numRails) > textSize ||
           textSize == 0                            ||
           numRails == 1;
}

inline constexpr void getRail(int& rail, int& direction, const int numRails)
{
    rail += direction;
    if (rail == 0 || rail == numRails - 1)
        direction *= -1;
}

}

std::string encode(const std::string& plaintext, const int num_rails)
{
    if (num_rails <= 0)
        throw std::invalid_argument("Number of rails must be positive.");
    
    if (isSameText(plaintext.size(), num_rails))
        return plaintext;
    
    std::vector<std::ostringstream> cipherVector(num_rails);

    int rail = 0;
    int direction = 1;
    for (const char ch : plaintext)
    {
        cipherVector[rail] << ch;
        getRail(rail, direction, num_rails);
    }

    std::ostringstream ciphertext;
    for (const auto& cipherRail : cipherVector)
        ciphertext << cipherRail.str();

    return ciphertext.str();
}

std::string decode(const std::string& ciphertext, const int num_rails)
{
    if (num_rails <= 0)
        throw std::invalid_argument("Number of rails must be positive.");
    
    if (isSameText(ciphertext.size(), num_rails))
        return ciphertext;

    std::vector<std::string> railsVector(num_rails);
    std::vector<size_t> railsLength(num_rails, 0);
    size_t idx = 0;
    
    int rail = 0;
    int direction = 1;
    for (idx = 0; idx < ciphertext.size(); ++idx)
    {
        ++railsLength[rail];
        getRail(rail, direction, num_rails);
    }

    idx = 0;
    for (int i = 0; i < num_rails; ++i)
    {
        railsVector[i] = ciphertext.substr(idx, railsLength[i]);
        idx += railsLength[i];
    }

    std::ostringstream plaintext;
    std::vector<size_t> railsIdx(num_rails, 0);
    rail = 0;
    direction = 1;
    for (idx = 0; idx < ciphertext.size(); ++idx)
    {
        plaintext << railsVector[rail][railsIdx[rail]++];
        getRail(rail, direction, num_rails);
    }

    return plaintext.str();
}

}  // namespace rail_fence_cipher
