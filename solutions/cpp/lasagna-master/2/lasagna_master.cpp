#include "lasagna_master.h"
#include <stdexcept>

namespace lasagna_master {

int preparationTime(const std::vector<std::string>& layers, int averagePrepTime)
{
    if (averagePrepTime <= 0)
        throw std::invalid_argument("Average preparation time must be positive.");

    return static_cast<int>(layers.size()) * averagePrepTime;
}

amount quantities(const std::vector<std::string>& layers)
{
    amount neededAmount{0, 0.0};
    for (const std::string& layer : layers)
    {
        if (layer == "sauce")
            neededAmount.sauce += 0.2;
        else if (layer == "noodles")
            neededAmount.noodles += 50;
    }

    return neededAmount;
}

void addSecretIngredient(std::vector<std::string>& myIngredients, const std::vector<std::string>& friendsIngredients)
{
    if (myIngredients.empty())
        throw std::invalid_argument("My ingredients list can't be empty.");
    if (friendsIngredients.empty())
        throw std::invalid_argument("Friend's ingredients list can't be empty.");
    
    myIngredients.back() = friendsIngredients.back();
}

void addSecretIngredient(std::vector<std::string>& myIngredients, const std::string& grandmaIngredient)
{
    if (myIngredients.empty())
        throw std::invalid_argument("My ingredients list can't be empty.");
    if (grandmaIngredient.empty())
        throw std::invalid_argument("Grandma's secret ingredient can't be empty.");
    
    myIngredients.back() = grandmaIngredient;
}

std::vector<double> scaleRecipe(const std::vector<double>& amounts, size_t portionsNum)
{
    std::vector<double> scaledAmounts;
    scaledAmounts.reserve(amounts.size());

    for (const double amount : amounts)
    {
        scaledAmounts.emplace_back(amount * static_cast<double>(portionsNum) / 2.0);
    }

    return scaledAmounts;
}

}  // namespace lasagna_master
