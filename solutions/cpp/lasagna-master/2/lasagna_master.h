#pragma once
#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(const std::vector<std::string>& layers, int averagePrepTime = 2);

amount quantities(const std::vector<std::string>& layers);

void addSecretIngredient(std::vector<std::string>& myIngredients, const std::vector<std::string>& friendsIngredients);

void addSecretIngredient(std::vector<std::string>& myIngredients, const std::string& grandmaIngredient);

std::vector<double> scaleRecipe(const std::vector<double>& amounts, size_t portionsNum);

}  // namespace lasagna_master
