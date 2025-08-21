#include "flower_field.h"

namespace flower_field {

std::vector<std::string> annotate(const std::vector<std::string>& flowerBoard)
{
    if (flowerBoard.empty())
        return {};
    
    const int rowSize = flowerBoard.size();
    const int colSize = flowerBoard[0].size();
    std::vector<std::string> filledFlowerBoard = flowerBoard;

    const auto isValid = [&] (int nr, int nc)
    {
        return nr >= 0 && nr < rowSize &&
               nc >= 0 && nc < colSize;
    };
    
    for (int r = 0; r < rowSize; ++r)
    {
        for (int c = 0; c < colSize; ++c)
        {
            if (flowerBoard[r][c] == FLOWER_TILE)
                continue;

            int flowerCount = 0;
            for (size_t i = 0; i < dr.size(); ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (isValid(nr, nc))
                    if (flowerBoard[nr][nc] == FLOWER_TILE)
                        ++flowerCount;
            }
            if (flowerCount > 0)
                filledFlowerBoard[r][c] = static_cast<char>('0' + flowerCount);
        }
    }

    return filledFlowerBoard;
}

}  // namespace flower_field
