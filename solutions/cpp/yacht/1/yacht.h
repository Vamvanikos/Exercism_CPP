#pragma once
#include <array>
#include <string>
#include <unordered_map>

namespace yacht {

namespace {

inline constexpr int ONES =            1;
inline constexpr int TWOS =            2;
inline constexpr int THREES =          3;
inline constexpr int FOURS =           4;
inline constexpr int FIVES =           5;
inline constexpr int SIXES =           6;
inline constexpr int FULL_HOUSE =      7;
inline constexpr int FOUR_OF_A_KIND =  8;
inline constexpr int LITTLE_STRAIGHT = 9;
inline constexpr int BIG_STRAIGHT =    10;
inline constexpr int CHOICE =          11;
inline constexpr int YACHT =           12;

inline constexpr int ONE_POINT =       1;
inline constexpr int TWO_POINTS =      2;
inline constexpr int THREE_POINTS =    3;
inline constexpr int FOUR_POINTS =     4;
inline constexpr int FIVE_POINTS =     5;
inline constexpr int SIX_POINTS =      6;

static const std::unordered_map<std::string, int> categoriesToId = {
    {"ones",            ONES},
    {"twos",            TWOS},
    {"threes",          THREES},
    {"fours",           FOURS},
    {"fives",           FIVES},
    {"sixes",           SIXES},
    {"full house",      FULL_HOUSE},
    {"four of a kind",  FOUR_OF_A_KIND},
    {"little straight", LITTLE_STRAIGHT},
    {"big straight",    BIG_STRAIGHT},
    {"choice",          CHOICE},
    {"yacht",           YACHT}
};

}

int score(const std::array<int, 5>& dice, const std::string& category);

}  // namespace yacht
