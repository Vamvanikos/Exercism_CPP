#include "raindrops.h"
#include <array>
#include <utility>

namespace raindrops {

inline constexpr std::array<std::pair<int, std::string_view>, 3> divNSound = {{
    {3, "Pling"},
    {5, "Plang"},
    {7, "Plong"}
}};

std::string convert(int number)
{
    std::string sound;

    auto divisible = [] (int num, int div)
    {
        return num % div == 0;
    };
    
    for (const auto& [div, s] : divNSound)
    {
        if (divisible(number, div))
        {
            sound += s;
        }
    }

    if (sound.empty())
        return std::to_string(number);

    return sound;
}

}  // namespace raindrops
