#include "sum_of_multiples.h"
#include <set>

namespace sum_of_multiples {

// TODO: add your solution here
int to(std::vector<int> itemsValue, int level)
{
    if (!itemsValue.size()) return 0;
    
    std::vector<std::vector<int>> setsOfValues(itemsValue.size());
    int j = 0;
    for (int baseValue : itemsValue)
    {
        for (int i = 1; baseValue * i < level; ++i)
        {
            setsOfValues[j].push_back(baseValue * i);
        }
        ++j;
    }

    std::set<int> combined(setsOfValues[0].begin(), setsOfValues[0].end());
    for (std::size_t i = 1; i < setsOfValues.size(); ++i)
    {
        combined.insert(setsOfValues[i].begin(), setsOfValues[i].end());
    }

    int sum = 0;
    for (int num : combined)
    {
        sum += num;
    }

    return sum;
}
    
}  // namespace sum_of_multiples
