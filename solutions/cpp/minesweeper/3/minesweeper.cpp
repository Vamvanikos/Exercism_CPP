#include "minesweeper.h"
namespace minesweeper {

namespace {

constexpr std::pair<int, int> directions[] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1} 
};

constexpr auto in_bounds(int r, int c, int rows, int cols) -> bool
{
    return r >= 0 && c >= 0 && r < rows && c < cols;
}

} // namespace
std::vector<std::string> annotate(const std::vector<std::string>& minesBoard)
{
    if (minesBoard.empty())
        return {};

    auto filledMinesBoard = minesBoard;
    const int rows = static_cast<int>(minesBoard.size());
    const int cols = static_cast<int>(minesBoard[0].size());
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (minesBoard[r][c] != '*')
                continue;

            for (const auto& [dr, dc] : directions)
            {
                const int nr = r + dr;
                const int nc = c + dc;
                if (!in_bounds(nr, nc, rows,cols))
                    continue;

                if (filledMinesBoard[nr][nc] == ' ')
                    filledMinesBoard[nr][nc] = '1';
                else if (filledMinesBoard[nr][nc] >= '1' &&
                         filledMinesBoard[nr][nc] < '8')
                    ++filledMinesBoard[nr][nc];
            }
        }
    }

    return filledMinesBoard;
}

}  // namespace minesweeper