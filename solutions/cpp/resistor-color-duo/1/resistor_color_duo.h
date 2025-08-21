#pragma once
#include <vector>
#include <string>

namespace resistor_color_duo {

inline constexpr int MAX_DIGITS = 2;

int value(const std::vector<std::string>& colorCodes);

}  // namespace resistor_color_duo
