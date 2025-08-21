#include "resistor_color_duo.h"
#include <unordered_map>

namespace resistor_color_duo {

namespace {
    const std::unordered_map<std::string, char> colorsToValues = 
    {
    {"black", '0'}, {"brown", '1'}, {"red", '2'}, {"orange", '3'}, {"yellow", '4'},
    {"green", '5'}, {"blue", '6'}, {"violet", '7'}, {"grey", '8'}, {"white", '9'}
    };
}
    
int value(const std::vector<std::string>& colorCodes)
{
    std::string result;
    result.reserve(MAX_DIGITS);

    for (const auto& codes : colorCodes)
    {
        result += colorsToValues.at(codes);
        if (result.size() == MAX_DIGITS)
            break;
    }

    return std::stoi(result);
}

}  // namespace resistor_color_duo
