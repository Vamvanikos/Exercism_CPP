#ifndef TWO_BUCKET_H
#define TWO_BUCKET_H

namespace two_bucket {

enum class bucket_id { one, two };

struct measure_result {
    int num_moves;
    bucket_id goal_bucket;
    int other_bucket_volume;
};

measure_result measure(const int bucket1_capacity, const int bucket2_capacity,
                       const int target_volume, const bucket_id start_bucket);

}  // namespace two_bucket

#endif  // TWO_BUCKET_H
