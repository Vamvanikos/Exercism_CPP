#if !defined(FOOD_CHAIN_H)
#define FOOD_CHAIN_H
#include <string>
#include <array>

namespace food_chain {

inline constexpr int FIRST_VERSE = 1;
inline constexpr int SECOND_VERSE = 2;
inline constexpr int EIGHTH_VERSE = 8;
inline constexpr int BEINGS_NUM = 8;
inline constexpr int BEINGS_COMMENT = 7;

// TODO: add your solution here
std::string swallow_verse(const std::array<std::string, BEINGS_NUM>& beings, int index);
    
std::string verse(int num);
std::string verses(int start, int end);
std::string sing();
    
}  // namespace food_chain

#endif  // FOOD_CHAIN_H