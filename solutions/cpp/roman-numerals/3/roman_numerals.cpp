#include "roman_numerals.h"
#include <stdexcept>
#include <array>

namespace roman_numerals {

namespace {

constexpr int ROMAN_NUM_SIZE = 13;
constexpr int SMALLEST_NUM = 1;
constexpr int LARGEST_NUM = 3999;

constexpr std::array<std::pair<int, std::string_view>, ROMAN_NUM_SIZE> int_to_roman = {{
    {1000, "M" },
    {900,  "CM"},
    {500,  "D" },
    {400,  "CD"},
    {100,  "C" },
    {90,   "XC"},
    {50,   "L" },
    {40,   "XL"},
    {10,   "X" },
    {9,    "IX"},
    {5,    "V" },
    {4,    "IV"},
    {1,    "I" }
}};
    
}

std::string convert(int num)
{
    if (num < SMALLEST_NUM || num > LARGEST_NUM)
        throw std::invalid_argument("Input number must be between 1-3999.");

    std::string romanNum;
    for (const auto& [value, roman] : int_to_roman)
    {
        while (num >= value)
        {
            romanNum += roman;
            num -= value;
        }
    }

    return romanNum;
}

}  // namespace roman_numerals
