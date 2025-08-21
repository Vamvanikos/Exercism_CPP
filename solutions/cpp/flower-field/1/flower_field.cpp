#include "flower_field.h"

namespace flower_field {


void checkNearTiles(int& sum, char r, char c, const std::vector<std::string>& flowerBoard)
{
    if (flowerBoard[r][c] == FLOWER_TILE)
        ++sum;
    if (c > 0 && flowerBoard[r][c - 1] == FLOWER_TILE)
        ++sum;
    if (c < (static_cast<int>(flowerBoard[0].size()) - 1) &&
        flowerBoard[r][c + 1] == FLOWER_TILE)
        ++sum;
}

std::vector<std::string> annotate(const std::vector<std::string>& flowerBoard)
{
    if (flowerBoard.empty())
        return {};
    
    int row = flowerBoard.size();
    int col = flowerBoard[0].size();
    std::vector<std::string> filledFlowerBoard = flowerBoard;
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            if (flowerBoard[r][c] == EMPTY_TILE)
            {
                int sum = 0;
                if (r > 0)
                    checkNearTiles(sum, r - 1, c, flowerBoard);
                checkNearTiles(sum, r, c, flowerBoard);
                if (r < row - 1)
                    checkNearTiles(sum, r + 1, c, flowerBoard);

                if (sum != 0)
                    filledFlowerBoard[r][c] = '0' + sum;
            }          
        }
    }

    return filledFlowerBoard;
}

}  // namespace flower_field
