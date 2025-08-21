#include "minesweeper.h"

namespace minesweeper {

namespace {

const std::vector<std::pair<int, int>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1} 
};

}

std::vector<std::string> annotate(const std::vector<std::string>& minesBoard)
{
    std::vector<std::string> filledMinesBoard = minesBoard;
    for (int r = 0; r < static_cast<int>(filledMinesBoard.size()); ++r)
    {
        for (int c = 0; c < static_cast<int>(filledMinesBoard[r].size()); ++c)
        {
            if (filledMinesBoard[r][c] == '*')
            {
                for (auto& [dr, dc] : directions)
                {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nc >= 0 &&
                        nr < static_cast<int>(filledMinesBoard.size()) && 
                        nc < static_cast<int>(filledMinesBoard[c].size()))
                    {
                        if (filledMinesBoard[nr][nc] == ' ')
                            filledMinesBoard[nr][nc] = '1';
                        else if (filledMinesBoard[nr][nc] > '0' && filledMinesBoard[nr][nc] < '8')
                            ++filledMinesBoard[nr][nc];
                    }
                }
            }
        }
    }

    return filledMinesBoard;
}

}  // namespace minesweeper
