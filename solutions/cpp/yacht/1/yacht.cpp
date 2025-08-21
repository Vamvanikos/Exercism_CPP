#include "yacht.h"
#include <algorithm>
#include <set>
#include <numeric>

namespace yacht {

// TODO: add your solution here
int score(const std::array<int, 5>& dice, const std::string& category)
{
    int points = 0;
    const auto diceBegin = dice.begin();
    const auto diceEnd = dice.end();
    switch (categoriesToId.at(category))
    {
        case ONES:
            points = ONE_POINT * std::count(diceBegin, diceEnd, ONES);
            break;
        case TWOS:
            points = TWO_POINTS * std::count(diceBegin, diceEnd, TWOS);
            break;
        case THREES:
            points = THREE_POINTS * std::count(diceBegin, diceEnd, THREES);
            break;
        case FOURS:
            points = FOUR_POINTS * std::count(diceBegin, diceEnd, FOURS);
            break;
        case FIVES:
            points = FIVE_POINTS * std::count(diceBegin, diceEnd, FIVES);
            break;
        case SIXES:
            points = SIX_POINTS * std::count(diceBegin, diceEnd, SIXES);
            break;
        case FULL_HOUSE:
            {
                const std::set<int> uniqueInts(diceBegin, diceEnd);
                if (uniqueInts.size() == 2)
                {
                    auto it = uniqueInts.begin();
                    auto firstEl = *it;
                    std::advance(it, 1);
                    auto secondEl = *it;
                    if (((std::count(diceBegin, diceEnd, firstEl) == 3)   &&
                         (std::count(diceBegin, diceEnd, secondEl) == 2)) ||
                        ((std::count(diceBegin, diceEnd, secondEl) == 3)  &&
                         (std::count(diceBegin, diceEnd, firstEl) == 2)))
                        points = std::accumulate(diceBegin, diceEnd, 0);
                }
                break;
            }
        case FOUR_OF_A_KIND:
            {
                const std::set<int> uniqueInts(diceBegin, diceEnd);
                if (uniqueInts.size() <= 2)
                {
                    auto it = uniqueInts.begin();
                    auto firstEl = *it;
                    if (std::count(diceBegin, diceEnd, firstEl) >= 4)
                    {
                        points = FOUR_POINTS * firstEl;
                        break;
                    }
                    std::advance(it, 1);
                    auto secondEl = *it;
                    if (std::count(diceBegin, diceEnd, secondEl) == 4)
                        points = FOUR_POINTS * secondEl;                    
                }
                break;
            }
        case LITTLE_STRAIGHT:
            {
                points = 30;
                for (int i = 1; i <= 5; ++i)
                    {
                        if (std::find(diceBegin, diceEnd, i)  == dice.end())
                        {
                            points = 0;
                            break;
                        }
                    }
                break;
            }
        case BIG_STRAIGHT:
            {
                points = 30;
                for (int i = 2; i <= 6; ++i)
                    {
                        if (std::find(diceBegin, diceEnd, i) == dice.end())
                        {
                            points = 0;
                            break;
                        }
                    }
                break;
            }
        case CHOICE:
            for (const auto& diceTry : dice)
                points += diceTry;
            break;
        case YACHT:
            {
                const std::set uniqueInts(diceBegin, diceEnd);
                if (uniqueInts.size() == 1)
                    points = 50;
                break;
            }
    }

    return points;
}

}  // namespace yacht
