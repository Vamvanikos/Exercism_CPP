#include "raindrops.h"

namespace raindrops {

std::string convert(int number)
{
    std::string sound;
    
    for (const auto& [div, s] : divNSound)
    {
        if (number % div == 0)
        {
            sound += s;
        }
    }

    return sound.empty() ? std::to_string(number) : sound;
}

}  // namespace raindrops
