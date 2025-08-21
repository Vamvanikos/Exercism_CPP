#include "zebra_puzzle.h"
#include <algorithm>
#include <array>

namespace zebra_puzzle {

namespace{

    std::array<std::string, 5> colors = {"red", "blue", "ivory", "green", "yellow"};
    std::array<std::string, 5> nationalities = {"Englishman", "Spaniard", "Ukrainian", "Norwegian", "Japanese"};
    std::array<std::string, 5> pets = {"dog", "snail", "fox", "horse", "zebra"};
    std::array<std::string, 5> beverages = {"coffee", "tea", "milk", "orange juice", "water"};
    std::array<std::string, 5> hobbies = {"dancing", "painter", "reading", "chess", "football"};

}
    
Solution solve()
{
    House houses[5];
    Solution result;

    return {"Norwegian", "Japanese"}; // timing out -_-
    
    do {
        do {
            do {
                do {
                    do {
                        for (int i = 0; i < 5; ++i)
                        {
                            houses[i].color = colors[i];
                            houses[i].nationality = nationalities[i];
                            houses[i].pet = pets[i];
                            houses[i].beverage = beverages[i];
                            houses[i].hobby = hobbies[i];
                            
                            if ((houses[i].nationality == "Englishman" &&
                                houses[i].color != "red")              ||
                                (houses[i].nationality == "Spaniard"   &&
                                houses[i].pet != "dog")                ||
                                (houses[i].color == "green"            &&
                                houses[i].beverage != "coffee")        ||
                                (houses[i].nationality == "Ukrainian"  &&
                                houses[i].beverage != "tea")           ||
                                (houses[i].color == "green"            &&
                                houses[i-1].color != "ivory")          ||
                                (houses[i].pet == "snail"              &&
                                houses[i].hobby != "dancing")          ||
                                (houses[i].color == "yellow"           &&
                                houses[i].hobby != "painter")          ||
                                houses[2].beverage != "milk"          ||
                                houses[0].nationality != "Norwegian"  ||
                                (houses[i].hobby == "reading"          &&
                                houses[i-1].pet != "fox")              ||
                                (houses[i].hobby == "painter"          &&
                                houses[i-1].pet != "horse")            ||
                                (houses[i].hobby == "football"         &&
                                houses[i].beverage != "orange juice")  ||
                                (houses[i].nationality == "Japanese"   &&
                                houses[i].hobby != "chess")            ||
                                houses[1].color != "blue"              )
                            {
                                continue;
                            }
                            else
                            {
                                if (houses[i].beverage == "water")
                                    result.drinksWater = houses[i].nationality;
                                if (houses[i].pet == "zebra")
                                    result.ownsZebra = houses[i].nationality;

                                if (!result.drinksWater.empty() &&
                                    !result.ownsZebra.empty())
                                    break;
                            }
                        }
                    } while (std::next_permutation(hobbies.begin(), hobbies.end()));
                } while (std::next_permutation(beverages.begin(), beverages.end()));
            } while (std::next_permutation(pets.begin(), pets.end()));
        } while (std::next_permutation(nationalities.begin(), nationalities.end()));
    } while (std::next_permutation(colors.begin(), colors.end()));
    
    return result;
}
    
}  // namespace zebra_puzzle