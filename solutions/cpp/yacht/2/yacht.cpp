#include "yacht.h"
#include <algorithm>
#include <set>
#include <numeric>
#include <stdexcept>

namespace yacht {

bool isFullHouse(const std::unordered_map<int, int>& frequency)
{
    return frequency.size() == 2 &&
           std::any_of(frequency.begin(), frequency.end(),
           [](const auto& freq) { return freq.second == 3; });
}
    
bool isFourOfKind(const std::unordered_map<int, int>& frequency, int& value)
{
    for (const auto& [val, freq] : frequency)
    {
        if (freq >= 4)
        {
            value = val;
            return true;
        }
    }
    return false;
}

int score(const std::array<int, 5>& dice, const std::string& category)
{
    const auto diceBegin = dice.begin();
    const auto diceEnd = dice.end();
    const auto& categ = categoriesToId.at(category);
    std::unordered_map<int, int> frequency;
    for (const auto& d : dice)
        ++frequency[d];

    switch (categ)
    {
        case categories::ONES:   case categories::TWOS:
        case categories::THREES: case categories::FOURS:
        case categories::FIVES:  case categories::SIXES:
            return static_cast<int>(categ) * frequency[static_cast<int>(categ)];
        
        case categories::FULL_HOUSE:
            return isFullHouse(frequency) ? std::reduce(diceBegin, diceEnd) : 0;
        
        case categories::FOUR_OF_A_KIND:
            int value;
            return isFourOfKind(frequency, value) ? 4 * value : 0;
        
        case categories::LITTLE_STRAIGHT:
            {
                std::set<int> isLittleStraight(diceBegin, diceEnd);
                return ((isLittleStraight == std::set<int>{1,2,3,4,5}) ? 30 : 0);
            }
        case categories::BIG_STRAIGHT:
            {
                std::set<int> isBigStraight(diceBegin, diceEnd);
                return ((isBigStraight == std::set<int>{2,3,4,5,6}) ? 30 : 0);
            }
        case categories::CHOICE:
            return std::reduce(diceBegin, diceEnd);
        
        case categories::YACHT:
            return ((frequency.size() == 1) ? 50 : 0);
        
        default:
            throw std::invalid_argument("Category does not exist.");
    }
}

}  // namespace yacht
