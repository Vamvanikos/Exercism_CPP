#include "raindrops.h"

namespace raindrops {

// TODO: add your solution here
std::string convert(int num)
{
    std::string soundStr;

    if ((num%3) == 0)
    {
        soundStr = "Pling";
    }
    if ((num%5) == 0)
    {
        soundStr += "Plang";
    }
    if ((num%7) == 0)
    {
        soundStr += "Plong";
    }
    if (soundStr.empty())
    {
        soundStr = std::to_string(num);
    }

    return soundStr;
}


}  // namespace raindrops
