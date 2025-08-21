#pragma once
#include <array>
#include <string>
#include <unordered_map>

namespace yacht {

namespace {

enum class categories {
    ONES = 1,
    TWOS = 2,
    THREES = 3,
    FOURS = 4,
    FIVES = 5,
    SIXES = 6,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    LITTLE_STRAIGHT,
    BIG_STRAIGHT,
    CHOICE,
    YACHT
};

inline const std::unordered_map<std::string, categories> categoriesToId = {
    {"ones",            categories::ONES},
    {"twos",            categories::TWOS},
    {"threes",          categories::THREES},
    {"fours",           categories::FOURS},
    {"fives",           categories::FIVES},
    {"sixes",           categories::SIXES},
    {"full house",      categories::FULL_HOUSE},
    {"four of a kind",  categories::FOUR_OF_A_KIND},
    {"little straight", categories::LITTLE_STRAIGHT},
    {"big straight",    categories::BIG_STRAIGHT},
    {"choice",          categories::CHOICE},
    {"yacht",           categories::YACHT}
};

}

int score(const std::array<int, 5>& dice, const std::string& category);

}  // namespace yacht
