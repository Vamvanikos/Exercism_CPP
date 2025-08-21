#pragma once
#include <string>
#include <unordered_set>
#include <cmath>
#include <random>

namespace robot_name {

inline constexpr int CHAR_LENGTH = 2;
inline constexpr int NUM_LENGTH = 3;
inline constexpr std::string_view CHARSET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
inline constexpr std::string_view NUMSET = "0123456789";
inline constexpr int MAX_NUM_NAMES = std::pow(CHARSET.size(), CHAR_LENGTH) *
                                     std::pow(NUMSET.size(), NUM_LENGTH);
    
class robot {
public:
    robot();

    std::string name() const;
    void reset();
private:
    static std::mt19937& generator();
    
    std::string m_name;
    static std::unordered_set<std::string> m_nameList;
};

}  // namespace robot_name
