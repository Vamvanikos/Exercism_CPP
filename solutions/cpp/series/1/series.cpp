#include "series.h"
#include <stdexcept>
#include <algorithm>

namespace series {

// TODO: add your solution here
std::vector<std::string> slice(const std::string& numberInString, size_t sliceSize)
{
    std::vector<std::string> slices;
    size_t stringSize = numberInString.size();
    
    if (!stringSize)
        throw std::domain_error("Size of numerical string can't be zero.");
    if (sliceSize <= 0)
        throw std::domain_error("Size of slice can't be smaller than one.");
    if (stringSize < sliceSize)
        throw std::domain_error("Size of string can't be smaller than size of slice.");

    for (size_t i = 0; i < stringSize - sliceSize + 1; i++)
    {
        slices.emplace_back(numberInString.substr(i, sliceSize));
    }

    return slices;    
}

}  // namespace series
