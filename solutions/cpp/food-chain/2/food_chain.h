#if !defined(FOOD_CHAIN_H)
#define FOOD_CHAIN_H
#include <string>
#include <array>

namespace food_chain {

std::string swallow_verse(int index);
    
std::string verse(int num);
std::string verses(int start, int end);
std::string sing();
    
}  // namespace food_chain

#endif  // FOOD_CHAIN_H