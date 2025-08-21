#if !defined(SPIRAL_MATRIX_H)
#define SPIRAL_MATRIX_H
#include <cstdint>
#include <vector>

namespace spiral_matrix {

inline const std::vector<std::pair<int,int>> positions = {
    { 0, 1},
    { 1, 0},
    { 0,-1},
    {-1, 0}
};

// TODO: add your solution here
std::vector<std::vector<uint32_t>> spiral_matrix(const uint32_t length);

}  // namespace spiral_matrix

#endif  // SPIRAL_MATRIX_H
