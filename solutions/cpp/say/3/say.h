#pragma once
#include <string>
#include <unordered_map>

namespace say {

namespace {

inline constexpr int CHUNKS_MAX_NUMBER = 4;

inline const std::unordered_map<int, std::string> firstDigits {
    {0, "zero"},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"}
};

inline const std::unordered_map<int, std::string> secondDigits {
    {2, "twenty"},
    {3, "thirty"},
    {4, "forty"},
    {5, "fifty"},
    {6, "sixty"},
    {7, "seventy"},
    {8, "eighty"},
    {9, "ninety"}
};

inline const std::unordered_map<int, std::string> tens {
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"}
};

inline const std::unordered_map<int, std::string> scale {
    {1, "thousand"},
    {2, "million"},
    {3, "billion"}
};
    
}

std::string two_digits_in_english(int num);
std::string in_english(long num);

}  // namespace say
