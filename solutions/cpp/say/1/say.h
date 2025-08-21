#if !defined(SAY_H)
#define SAY_H
#include <string>

#include <unordered_map>

namespace say {

namespace {

inline const int LOW_BOUND = 0;
inline const long HIGH_BOUND = 999999999999;
inline const int HIGH_BOUND_HUNDREDS = 99;
inline const int HIGH_BOUND_THOUSANDS = 999;
inline const int CHUNKS_OF_THOUSANDS = 1000;
inline const int CHUNKS_OF_HUNDREDS = 100;
inline const int CHUNKS_OF_TENS = 10;

inline const std::unordered_map<int, std::string_view> oneDigitNums = {
    {1, "one"},
    {2 ,"two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"}
};

inline const std::unordered_map<int, std::string_view> twoDigitNums = {
    {1, "ten"},
    {2 ,"twenty"},
    {3, "thirty"},
    {4, "forty"},
    {5, "fifty"},
    {6, "sixty"},
    {7, "seventy"},
    {8, "eighty"},
    {9, "ninety"}
};
    
inline const std::unordered_map<int, std::string_view> TenNums = {
    {11, "eleven"},
    {12 ,"twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"}
};

inline const std::unordered_map<int, std::string_view> Magnitude = {
    {1, "thousand"},
    {2 ,"million"},
    {3, "billion"},
};
    
}
    
std::string in_english(long number);

}  // namespace say

#endif  // SAY_H