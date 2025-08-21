#include "pascals_triangle.h"

namespace pascals_triangle {

// TODO: add your solution here
std::vector<std::vector<int>> generate_rows(const int rows)
{
    std::vector<std::vector<int>> pascalsTriangle;

    for (int r = 0; r < rows; ++r)
    {
        std::vector<int> row;
        for (int c = 0; c <= r; ++c)
            if(c == 0 || c == r)
                row.push_back(1);
            else
                row.push_back(pascalsTriangle[r-1][c-1] + pascalsTriangle[r-1][c]);
        pascalsTriangle.push_back(row);
    }

    return pascalsTriangle;
}

}  // namespace pascals_triangle
