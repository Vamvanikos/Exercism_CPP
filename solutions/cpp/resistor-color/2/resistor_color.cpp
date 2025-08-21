#include "resistor_color.h"
#include <unordered_map>
#include <stdexcept>

namespace resistor_color {

namespace {
    const std::unordered_map<std::string, int> colorsToValues =
    {
        {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3}, {"yellow", 4},
        {"green", 5}, {"blue", 6}, {"violet", 7}, {"grey", 8}, {"white", 9}
    };

    const std::vector<std::string> colorCodes = 
    {
        "black", "brown", "red", "orange", "yellow",
        "green", "blue", "violet", "grey", "white"
    };

}

int color_code(const std::string& colorCode)
{
    return colorsToValues.at(colorCode);
}

const std::vector<std::string>& colors()
{
    return colorCodes;
}

}  // namespace resistor_color
