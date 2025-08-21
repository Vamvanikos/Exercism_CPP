#pragma once
#include <utility>

namespace queen_attack {

class chess_board {
public:
chess_board(const std::pair<int, int>& wh, const std::pair<int, int>& bl);
    
std::pair<int, int> white() const;
std::pair<int, int> black() const;
bool can_attack() const;

private:
static constexpr int posMin = 0;
static constexpr int posMax = 7;
    
bool out_of_bounds(const std::pair<int, int>& queen) const;

std::pair<int, int> m_white;
std::pair<int, int> m_black;
};

}  // namespace queen_attack
