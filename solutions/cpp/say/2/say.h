#if !defined(SAY_H)
#define SAY_H
#include <string>

#include <unordered_map>

namespace say {

constexpr int LOW_BOUND = 0;
constexpr long HIGH_BOUND = 999999999999;
constexpr int CHUNKS_OF_THOUSANDS = 1000;
constexpr int CHUNKS_OF_HUNDREDS = 100;
constexpr int CHUNKS_OF_TENS = 10;
constexpr int TEEN_MAX = 19;

inline const std::unordered_map<int, std::string_view> oneDigitNums = {
    {1, "one"},   {2 ,"two"},   {3, "three"},
    {4, "four"},  {5, "five"},  {6, "six"},
    {7, "seven"}, {8, "eight"}, {9, "nine"}
};

inline const std::unordered_map<int, std::string_view> twoDigitNums = {
    {2 ,"twenty"}, {3, "thirty"}, {4, "forty"},
    {5, "fifty"},  {6, "sixty"},  {7, "seventy"},
    {8, "eighty"}, {9, "ninety"}
};
    
inline const std::unordered_map<int, std::string_view> TeenNums = {
    {10, "ten"},      {11, "eleven"},    {12 ,"twelve"},
    {13, "thirteen"}, {14, "fourteen"},  {15, "fifteen"},
    {16, "sixteen"},  {17, "seventeen"}, {18, "eighteen"},
    {19, "nineteen"}
};

inline const std::unordered_map<int, std::string_view> Magnitude = {
    {1, "thousand"}, {2 ,"million"}, {3, "billion"},
};

std::string in_english(long number);

}  // namespace say

#endif  // SAY_H