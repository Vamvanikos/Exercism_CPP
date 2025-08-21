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
    filledRows.emplace_back(1, 1);
    for (int i = 1; i < rows; ++i)
    {
        std::vector<int> row(i + 1);
        row[0] = row[i] = 1;
        for (int j = 1; j < i; ++j)
            row[j] = filledRows[i - 1][j - 1] + filledRows[i - 1][j];

        filledRows.emplace_back(std::move(row));
    }

    return filledRows;
}

}  // namespace pascals_triangle
