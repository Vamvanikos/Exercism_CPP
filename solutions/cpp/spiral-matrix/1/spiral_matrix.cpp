#include "spiral_matrix.h"

namespace spiral_matrix {
    
std::vector<std::vector<uint32_t>> spiral_matrix(const uint32_t length)
{
    uint32_t counter = 0;
    int r = 0;
    int c = 0;
    int i = 0;
    auto [pr, pc] = positions[i];
    std::vector<std::vector<uint32_t>> spiralMatrix(length, std::vector<uint32_t>(length));
    while (counter < length * length)
    {
        while (r >= 0 && r < static_cast<int>(length) &&
               c >= 0 && c < static_cast<int>(length) &&
               spiralMatrix[r][c] == 0)
        {
            spiralMatrix[r][c] = ++counter;
            r += pr;
            c += pc;
        }
        r -= pr;
        c -= pc;
        i = (i + 1) % 4;
        pr = positions[i].first;
        pc = positions[i].second;
        r += pr;
        c += pc;
    }

    return spiralMatrix;
}

}  // namespace spiral_matrix
