#include "sum_of_multiples.h"
#include <numeric>
#include <unordered_set>
#include <stdexcept>

namespace sum_of_multiples {

int to(const std::vector<int>& baseValues, int level)
{
    if (baseValues.empty() || level == 0)
        return 0;
    if (level < 0)
        throw std::invalid_argument("Level can't be negative.");
    
    std::unordered_set<int> multipliers;
    for (int magicalValue : baseValues)
    {
        if (magicalValue == 0)
            continue;
        for (int mult = magicalValue; mult < level; mult += magicalValue)
            multipliers.emplace(mult);
    }

    return std::accumulate(multipliers.begin(), multipliers.end(), 0);
}

}  // namespace sum_of_multiples
