#pragma once
#include <string>
#include <array>
#include <utility>

namespace raindrops {

inline constexpr std::array<std::pair<int, std::string_view>, 3> divNSound = {{
    {3, "Pling"},
    {5, "Plang"},
    {7, "Plong"}
}};

std::string convert(int number);

}  // namespace raindrops
