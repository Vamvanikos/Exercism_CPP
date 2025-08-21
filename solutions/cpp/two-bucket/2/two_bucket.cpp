#include "two_bucket.h"
#include <tuple>
#include <queue>
#include <set>
#include <stdexcept>

using States = std::tuple<int, int, int>;

namespace two_bucket {
    
measure_result measure(const int bucket1_capacity, const int bucket2_capacity,
                       const int target_volume, const bucket_id start_bucket)
{
    if (target_volume > std::max(bucket1_capacity,bucket2_capacity))
        throw std::invalid_argument("Target volume can't be bigger than both buckets' capacity.");

    // Initialization
    int initBucket1 = (start_bucket == bucket_id::one) ? bucket1_capacity : 0;
    int initBucket2 = (start_bucket == bucket_id::two) ? bucket2_capacity : 0;
    std::queue<States> bucketsStates;
    std::set<std::pair<int, int>> visitedStates;
    bucketsStates.emplace(initBucket1, initBucket2, 1);
    visitedStates.emplace(initBucket1, initBucket2);

    while(!bucketsStates.empty())
    {
        auto [bucket1, bucket2, moves] = bucketsStates.front();
        bucketsStates.pop();

        if ((start_bucket == bucket_id::one && bucket1 == 0 && bucket2 == bucket2_capacity) ||
            (start_bucket == bucket_id::two && bucket2 == 0 && bucket1 == bucket1_capacity))
            continue;

        if (bucket1 == target_volume)
            return {moves, bucket_id::one, bucket2};
        if (bucket2 == target_volume)
            return {moves, bucket_id::two, bucket1};

        std::vector<std::pair<int, int>> actions = {
            {bucket1_capacity, bucket2},
            {bucket1, bucket2_capacity},
            {0, bucket2},
            {bucket1, 0},
            {bucket1 - std::min(bucket1, bucket2_capacity - bucket2),
             bucket2 + std::min(bucket1, bucket2_capacity - bucket2)},
            {bucket1 + std::min(bucket2, bucket1_capacity - bucket1),
             bucket2 - std::min(bucket2, bucket1_capacity - bucket1)}
        };

        for (const auto& [action1, action2] : actions)
        {
            if (visitedStates.emplace(action1, action2).second)
            {
                bucketsStates.emplace(action1, action2, moves + 1);
            }
        }
    }
    
    throw std::logic_error("No way to reach target volume with the given buckets.");
}

}  // namespace two_bucket
