#include "series.h"
#include <stdexcept>

namespace series {

std::vector<std::string> slice(const std::string& digitsString, int len)
{
    size_t stringSize = digitsString.size();
    if (stringSize == 0)
        throw std::domain_error("String of digits can't have size zero.");
    if (len <= 0)
        throw std::domain_error("Length of substrings must be positive.");
    if (len > static_cast<int>(stringSize))
        throw std::domain_error("Length of substrings can't exceed the size of the string.");

    std::vector<std::string> substringsVec;
    size_t numOfSubstrings = stringSize - len + 1;
    substringsVec.reserve(numOfSubstrings);
    for (size_t i = 0; i < numOfSubstrings; ++i)
        substringsVec.emplace_back(digitsString.substr(i, len));

    return substringsVec;        
}

}  // namespace series
