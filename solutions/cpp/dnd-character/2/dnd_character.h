#pragma once

namespace dnd_character {

inline constexpr int ROLL_NUMS = 4;

struct Character {
    Character();

    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int hitpoints;
};

int ability();
int modifier(const int constit);

}  // namespace dnd_character
