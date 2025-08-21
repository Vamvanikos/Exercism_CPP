#include "knapsack.h"
#include <algorithm>
#include <stdexcept>

namespace knapsack {

int maximum_value(int maxWeight, const std::vector<Item>& items)
{
    if (items.empty())
        return 0;
    if (maxWeight <= 0)
        throw std::invalid_argument("Max weight must be possitive.");

    std::vector<int> dp(maxWeight + 1, 0);
    for (const auto& item : items)
    {
        for (int w = maxWeight; w >= item.weight; --w)
        {
            dp[w] = std::max(dp[w], dp[w - item.weight] + item.value);
        }
    }

    return dp[maxWeight];
}

}  // namespace knapsack
