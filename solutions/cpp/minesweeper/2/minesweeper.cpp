#include "minesweeper.h"
namespace minesweeper {
namespace {
const std::vector<std::pair<int, int>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1} 
};
}
std::vector<std::string> annotate(const std::vector<std::string>& minesBoard)
{
    if (minesBoard.empty())
        return minesBoard;
    std::vector<std::string> filledMinesBoard = minesBoard;
    const int rows = static_cast<int>(minesBoard.size());
    const int cols = static_cast<int>(minesBoard[0].size());
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (minesBoard[r][c] == '*')
            {
                for (const auto& [dr, dc] : directions)
                {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nc >= 0 &&
                        nr < rows && nc < cols)
                    {
                        if (filledMinesBoard[nr][nc] == ' ')
                            filledMinesBoard[nr][nc] = '1';
                        else if (filledMinesBoard[nr][nc] >= '1' &&
                                 filledMinesBoard[nr][nc] < '8')
                            ++filledMinesBoard[nr][nc];
                    }
                }
            }
        }
    }
    return filledMinesBoard;
}
}  // namespace minesweeper