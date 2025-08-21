#include "two_bucket.h"
#include <tuple>
#include <queue>
#include <set>
#include <stdexcept>


namespace two_bucket {

using State = std::tuple<int, int, int>;
    
measure_result measure(const int bucket1_capacity, const int bucket2_capacity,
                       const int target_volume, const bucket_id start_bucket)
{
    if (target_volume > bucket1_capacity && target_volume > bucket2_capacity)
        throw std::invalid_argument("Target volume can't be larger than both the buckets.");
    
    std::queue<State> statesQueue;
    std::set<std::pair<int, int>> visitedCases;

    int bucket1 = 0;
    int bucket2 = 0;

    bucket_id resBucketId;
    int resMoves = 1;

    if (start_bucket == bucket_id::one)
        bucket1 = bucket1_capacity;
    else
        bucket2 = bucket2_capacity;

    statesQueue.push({bucket1, bucket2, resMoves});
    visitedCases.insert({bucket1, bucket2});

    while (!statesQueue.empty())
    {
        std::tie(bucket1, bucket2, resMoves) = statesQueue.front();
        statesQueue.pop();

        if (((start_bucket == bucket_id::one) && (bucket1 == 0) &&
           (bucket2 == bucket2_capacity)) || ((start_bucket == bucket_id::two) &&
           (bucket2 == 0) && (bucket1 == bucket1_capacity)))
               continue;
        
        if (bucket1 == target_volume)
        {
            resBucketId = bucket_id::one;
            return {resMoves, resBucketId, bucket2};
        }
        else if (bucket2 == target_volume)
        {
            resBucketId = bucket_id::two;
            return {resMoves, resBucketId, bucket1};
        }

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
            if (visitedCases.count({action1, action2}) == 0)
            {
                visitedCases.insert({action1, action2});
                statesQueue.push({action1, action2, resMoves + 1});
            }
        }
    }

    throw std::logic_error("Target volume can't be reached with the specified buckets.");
}

}  // namespace two_bucket
