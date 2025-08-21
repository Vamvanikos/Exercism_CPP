#include "lasagna_master.h"

namespace lasagna_master {

// TODO: add your solution here
int preparationTime(std::vector<std::string> layers, int minutes)
{
    return (layers.size() * minutes);
}

amount quantities(std::vector<std::string> layers)
{
    int noodleNum = 0, sauceNum = 0;
    for (std::string layer : layers)
    {
        if (layer == "noodles") { noodleNum++; }
        else if (layer == "sauce") { sauceNum++; }
    }
    amount quant{50 * noodleNum, 0.2 * sauceNum};
    
    return quant;       
}

void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendList)
{
    myList.back() = friendList.back();
}

void addSecretIngredient(std::vector<std::string>& myList, const std::string& grandmaIngredient)
{
    myList.back() = grandmaIngredient;
}

std::vector<double> scaleRecipe(const std::vector<double>& amount2portions, int portionsNum)
{
    double mult = static_cast<double>(portionsNum)/2;
    std::vector<double> finalPortions;
    for (double portions : amount2portions)
    {
        finalPortions.push_back(portions * mult);
    }
    
    return finalPortions;
}

}  // namespace lasagna_master
