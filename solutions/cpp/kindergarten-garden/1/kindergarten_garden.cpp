#include "kindergarten_garden.h"

namespace kindergarten_garden {

// TODO: add your solution here

std::map<char, Plants> plantEncoding = 
{
    {'C', Plants::clover},
    {'G', Plants::grass},
    {'V', Plants::violets},
    {'R', Plants::radishes}
};
    
std::array<Plants, 4> plants(std::string plantEncode, std::string student)
{
    std::array<Plants, 4> studentPlants;
    int index = 0;
    int studentIdx = student[0] - 'A';

    for (int i = 0; i < 4; i++)
    {
        if (i == 2) { index = plantEncode.find('\n') + 1; }
        studentPlants[i] = plantEncoding[plantEncode[index + studentIdx * 2 + i%2]];
    }

    return studentPlants;
}

}  // namespace kindergarten_garden
