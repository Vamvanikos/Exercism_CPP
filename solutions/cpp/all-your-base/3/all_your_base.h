#pragma once
#include <vector>

inline constexpr int minBase = 2;

namespace all_your_base {

std::vector<unsigned int> convert(unsigned int initBase, const std::vector<unsigned int>& number, unsigned int newBase);

}  // namespace all_your_base
