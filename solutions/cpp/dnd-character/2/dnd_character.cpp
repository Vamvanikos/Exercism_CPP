#include "dnd_character.h"
#include <random>
#include <array>
#include <numeric>
#include <algorithm>

namespace dnd_character {

Character::Character() : strength(ability()), dexterity(ability()),
                         constitution(ability()), intelligence(ability()),
                         wisdom(ability()), charisma(ability()),
                         hitpoints(10 + modifier(constitution)) {}

int ability()
{
    std::array<int, ROLL_NUMS> rolls;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(1, 6);

    std::generate(rolls.begin(), rolls.end(), [&]() { return dist(gen); });    
    std::nth_element(rolls.begin(), rolls.begin() + 1, rolls.end());

    return std::reduce(rolls.begin() + 1, rolls.end());
}
    
int modifier(const int constit)
{
    return std::floor(static_cast<float>(constit - 10)/2);
}

}  // namespace dnd_character
