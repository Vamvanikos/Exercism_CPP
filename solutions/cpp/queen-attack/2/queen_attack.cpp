#include "queen_attack.h"
#include <stdexcept>
#include <cmath>

namespace queen_attack {

bool chess_board::out_of_bounds(const std::pair<int, int>& queen) const
{
    return queen.first  < posMin || queen.first  > posMax ||
           queen.second < posMin || queen.second > posMax;
}
    
chess_board::chess_board(const std::pair<int, int>& wh, const std::pair<int, int>& bl) : m_white(wh), m_black(bl)
{
    if (out_of_bounds(m_white))
        throw std::domain_error("White queen position must be between 0-7.");
    if (out_of_bounds(m_black))
        throw std::domain_error("Black queen position must be between 0-7.");
    if (m_white == m_black)
        throw std::domain_error("Queens can't be on the same position.");
}

std::pair<int, int> chess_board::white() const
{
    return m_white;
}
std::pair<int, int> chess_board::black() const
{
    return m_black;
}

bool chess_board::can_attack() const
{
    return m_white.first == m_black.first   ||
           m_white.second == m_black.second ||
           std::abs(m_white.first - m_black.first) == 
           std::abs(m_white.second - m_black.second);
}

}  // namespace queen_attack
