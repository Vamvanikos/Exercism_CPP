#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <utility>
#include <stdexcept>

namespace queen_attack {

// TODO: add your solution here
class chess_board {
public:
chess_board(const std::pair<int, int>& wh, const std::pair<int, int>& bl);
const std::pair<int, int>& white() const;
const std::pair<int, int>& black() const;
bool can_attack() const;
    

private:
static bool out_of_bounds(const std::pair<int, int>& queen);
    
std::pair<int, int> whiteQueen;
std::pair<int, int> blackQueen;
    
};

}  // namespace queen_attack

#endif  // QUEEN_ATTACK_H