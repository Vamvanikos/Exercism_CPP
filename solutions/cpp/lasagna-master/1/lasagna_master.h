#pragma once
#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> layers, int minutes = 2);
amount quantities(std::vector<std::string> layers);
void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendList);
void addSecretIngredient(std::vector<std::string>& myList, const std::string& grandmaIngredient);

    
std::vector<double> scaleRecipe(const std::vector<double>& amount2portions, int portionsNum);

}  // namespace lasagna_master
