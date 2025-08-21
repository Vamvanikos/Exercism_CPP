#pragma once
#include <vector>
#include <string>
#include <array>

namespace flower_field {

inline constexpr char FLOWER_TILE = '*';
    
inline constexpr std::array<int, 8> dr = {-1,  0,  1, -1, 1, -1, 0, 1};
inline constexpr std::array<int, 8> dc = {-1, -1, -1,  0, 0,  1, 1, 1};

    
std::vector<std::string> annotate(const std::vector<std::string>& flowerBoard);

}  // namespace flower_field
