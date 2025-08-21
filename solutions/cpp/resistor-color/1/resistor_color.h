#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace resistor_color {

namespace {
    static std::unordered_map<std::string, int> colorsToValues =
    {
        {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3}, {"yellow", 4},
        {"green", 5}, {"blue", 6}, {"violet", 7}, {"grey", 8}, {"white", 9}
    };

    static std::vector<std::string> colorCodes = 
    {
        "black", "brown", "red", "orange", "yellow",
        "green", "blue", "violet", "grey", "white"
    };

}
    
int color_code(const std::string& colorCode);
std::vector<std::string> colors();

}  // namespace resistor_color
