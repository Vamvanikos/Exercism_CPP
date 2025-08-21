#include "queen_attack.h"
#include <cmath>

static constexpr int BOARD_MIN = 0;
static constexpr int BOARD_MAX = 7;

namespace queen_attack {

// TODO: add your solution here
chess_board::chess_board(const std::pair<int, int>& wh, const std::pair<int, int>& bl) : whiteQueen(wh), blackQueen(bl)
{
    if (out_of_bounds(whiteQueen))
    {
        throw std::domain_error("White Queen is out of bounds.");
    }
    if (out_of_bounds(blackQueen))
    {
        throw std::domain_error("Black Queen is out of bounds.");
    }
    if (whiteQueen == blackQueen)
    {
        throw std::domain_error("White and Black Queens can't be at the same space.");
    }
}

const std::pair<int, int>& chess_board::white() const
{
    return whiteQueen;
}

const std::pair<int, int>& chess_board::black() const
{
    return blackQueen;
}

bool chess_board::can_attack() const
{
    return ((std::abs(whiteQueen.first - blackQueen.first) == 
             std::abs(whiteQueen.second - blackQueen.second)) ||
            (whiteQueen.first == blackQueen.first)            ||
            (whiteQueen.second == blackQueen.second));
}

bool chess_board::out_of_bounds(const std::pair<int, int>& queen)
{
    return (queen.first < BOARD_MIN || queen.second < BOARD_MIN ||
            queen.first > BOARD_MAX || queen.second > BOARD_MAX);
}
    
}  // namespace queen_attack
