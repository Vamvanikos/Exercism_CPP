#if !defined(ALPHAMETICS_H)
#define ALPHAMETICS_H

#include <string>
#include <unordered_map>
#include <optional>

namespace alphametics {

std::optional<std::unordered_map<char, int>> solve(const std::string& puzzle);

}  // namespace alphametics

#endif  // ALPHAMETICS_H