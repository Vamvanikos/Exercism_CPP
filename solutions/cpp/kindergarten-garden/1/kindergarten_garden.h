#include <string>
#include <array>
#include <map>

namespace kindergarten_garden {

// TODO: add your solution here
enum class Plants
{
    clover,
    grass,
    violets,
    radishes
};

extern std::map<char, Plants> plantEncoding;

std::array<Plants, 4> plants(std::string plantEncode, std::string student);

}  // namespace kindergarten_garden
