#include "pascals_triangle.h"

namespace pascals_triangle {

// TODO: add your solution here
std::vector<std::vector<int>> generate_rows(const int rows)
{
    std::vector<std::vector<int>> pascalsTriangle(rows);

    for (int r = 0; r < rows; ++r)
    {
        pascalsTriangle[r].resize(r + 1);
        pascalsTriangle[r][0] = 1;
        pascalsTriangle[r][r] = 1;
        
        for (int c = 1; c < r; ++c)
            pascalsTriangle[r][c] = pascalsTriangle[r-1][c-1] + pascalsTriangle[r-1][c];
    }

    return pascalsTriangle;
}

}  // namespace pascals_triangle
