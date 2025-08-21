#include "resistor_color.h"
#include <array>
#include <stdexcept>
#include <algorithm>

namespace resistor_color {

namespace
{

constexpr std::array<std::string_view, 10> colorsArray = 
    {"black", "brown", "red",    "orange", "yellow",
     "green", "blue",  "violet", "grey",   "white"};

} // anonymous namespace
    
int color_code(const std::string_view& color)
{
    auto it = std::find(colorsArray.begin(), colorsArray.end(), color);
    if (it == colorsArray.end())
        throw std::invalid_argument("Given color does not exist.");
    
    return static_cast<int>(std::distance(colorsArray.begin(), it));
}
    
const std::vector<std::string>& colors()
{
    static std::vector<std::string> colorsVector(colorsArray.begin(), colorsArray.end());
    return colorsVector;
}

}  // namespace resistor_color
