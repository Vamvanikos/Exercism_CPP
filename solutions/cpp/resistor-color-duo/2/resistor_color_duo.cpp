#include "resistor_color_duo.h"
#include <unordered_map>

namespace resistor_color_duo {

namespace {

const std::unordered_map<std::string_view, int> colorsMap = {
    {"black", 0}, {"brown", 1}, {"red", 2},    {"orange", 3}, {"yellow", 4},
    {"green", 5}, {"blue", 6},  {"violet", 7}, {"grey", 8},   {"white", 9}
};
    
} // namespace anonymous
    
int value(const std::vector<std::string_view>& colors)
{
    if (colors.empty())
        return 0;
    
    int result = colorsMap.at(colors[0]);
    if (colors.size() > 1)
        result = result * 10 + colorsMap.at(colors[1]);
    
    return result;
}

}  // namespace resistor_color_duo
