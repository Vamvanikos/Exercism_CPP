#if !defined(ETL_H)
#define ETL_H
#include <map>
#include <vector>

namespace etl {

// TODO: add your solution here
std::map<char, int> transform(const std::map<int, std::vector<char>>& pointsToLetters);

}  // namespace etl

#endif  // ETL_H