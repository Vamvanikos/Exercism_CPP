#include "pascals_triangle.h"
#include <stdexcept>

namespace pascals_triangle {

std::vector<std::vector<int>> generate_rows(int rows)
{
    if (rows < 0)
        throw std::invalid_argument("Number of rows can't be negative.");
    if (rows == 0)
        return {};

    
    std::vector<std::vector<int>> filledRows;
    filledRows.reserve(rows);
    filledRows.emplace_back(std::vector<int>{1});
    for (int i = 1; i < rows; ++i)
    {
        std::vector<int> row;
        row.reserve(i + 1);
        for (int j = 0; j <= i; ++j)
        {
            int value = 0;
            if (j > 0)
                value += filledRows[i - 1][j - 1];
            if (j < i)
                value += filledRows[i-1][j];
            row.emplace_back(value);
        }

        filledRows.emplace_back(std::move(row));
    }

    return filledRows;
}

}  // namespace pascals_triangle
