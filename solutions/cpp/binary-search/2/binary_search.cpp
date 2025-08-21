#include "binary_search.h"
#include <stdexcept>
#include <algorithm>

namespace binary_search {

std::size_t find(std::vector<int> data, int searchNum)
{
    std::sort(data.begin(), data.end());
    
    std::size_t left = 0;
    std::size_t right = data.size();
    while (left < right)
    {
        size_t middle = left + (right - left) / 2;
        if (searchNum == data[middle])
            return middle;
        else if (searchNum < data[middle])
            right = middle;
        else
            left = middle + 1;
    }

    throw std::domain_error("Element does not exist in the list.");
}

}  // namespace binary_search
