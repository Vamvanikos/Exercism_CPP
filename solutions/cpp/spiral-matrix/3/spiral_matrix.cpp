#include "spiral_matrix.h"

namespace spiral_matrix {

bool isOutOfBounds(const int64_t near, const uint32_t length)
{
    return near < 0 || static_cast<uint32_t>(near) == length;
}
    
std::vector<std::vector<uint32_t>> spiral_matrix(const uint32_t length)
{
    int64_t r = 0;
    int64_t c = 0;
    int i = 0;
    std::vector<std::vector<uint32_t>> spiralMatrix(length, std::vector<uint32_t>(length));

    for (uint32_t counter = 1; counter <= length * length; ++counter)
    {
        spiralMatrix[r][c] = counter;

        int64_t nr = r + positions[i].first;
        int64_t nc = c + positions[i].second;
        if (isOutOfBounds(nr, length) || isOutOfBounds(nc, length) ||
            spiralMatrix[nr][nc] != 0)
        {
            i = (i + 1) % 4;
            nr = r + positions[i].first;
            nc = c + positions[i].second;
        }
        r = nr;
        c = nc;
    }

    return spiralMatrix;
}

}  // namespace spiral_matrix
