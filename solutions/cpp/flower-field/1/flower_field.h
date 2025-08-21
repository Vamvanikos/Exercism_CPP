#pragma once
#include <vector>
#include <string>

namespace flower_field {

inline constexpr char FLOWER_TILE = '*';
    inline constexpr char EMPTY_TILE = ' ';
    

std::vector<std::string> annotate(const std::vector<std::string>& flowerBoard);

void checkNearTiles(int& sum, char r, char c, const std::vector<std::string>& flowerBoard);
    

}  // namespace flower_field
