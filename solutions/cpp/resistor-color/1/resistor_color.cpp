#include "resistor_color.h"
#include <stdexcept>

namespace resistor_color {

int color_code(const std::string& colorCode)
{
    if (colorsToValues.find(colorCode) == colorsToValues.end())
        throw std::invalid_argument("Given color code does not exist.");
    return colorsToValues[colorCode];
}

std::vector<std::string> colors()
{
    return colorCodes;
}

}  // namespace resistor_color
