#if !defined(SPIRAL_MATRIX_H)
#define SPIRAL_MATRIX_H
#include <cstdint>
#include <vector>
#include <array>

namespace spiral_matrix {

constexpr std::array<std::pair<int, int>, 4> positions = {{
    { 0, 1},
    { 1, 0},
    { 0,-1},
    {-1, 0}
}};

std::vector<std::vector<uint32_t>> spiral_matrix(const uint32_t length);

}  // namespace spiral_matrix

#endif  // SPIRAL_MATRIX_H
