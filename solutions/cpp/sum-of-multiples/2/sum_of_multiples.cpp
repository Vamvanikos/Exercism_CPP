#include "sum_of_multiples.h"

namespace sum_of_multiples {

// TODO: add your solution here
int to(const std::set<int>& itemsValue, int level)
{
    std::set<std::set<int>> setsOfValues;
    for (int baseValue : itemsValue)
    {
        if (!baseValue) continue;
        std::set<int> multiplies;
        for (int i = 1; baseValue * i < level; ++i)
        {
            multiplies.insert(baseValue * i);
        }
        setsOfValues.insert(multiplies);
    }

    std::set<int> combined;
    for (const std::set<int>& values : setsOfValues)
    {
        combined.insert(values.begin(), values.end());
    }

    int sum = 0;
    for (int num : combined)
    {
        sum += num;
    }

    return sum;
}
    
}  // namespace sum_of_multiples
