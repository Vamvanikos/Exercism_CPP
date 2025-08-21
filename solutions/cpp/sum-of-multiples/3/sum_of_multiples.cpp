#include "sum_of_multiples.h"
#include <numeric>

namespace sum_of_multiples {

// TODO: add your solution here
int to(const std::set<int>& itemsValue, int level)
{
    std::set<int> setOfValues;
    for (int baseValue : itemsValue)
    {
        if (!baseValue) continue;
        for (int multiples = baseValue; multiples < level; multiples += baseValue)
        {
            setOfValues.insert(multiples);
        }
    }

    return std::accumulate(setOfValues.begin(), setOfValues.end(), 0);
}
    
}  // namespace sum_of_multiples
