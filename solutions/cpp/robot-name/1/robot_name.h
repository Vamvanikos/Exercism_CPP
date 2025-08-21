#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <string>
#include <unordered_set>
#include <cmath>

namespace robot_name {

inline constexpr int CHAR_LENGTH = 2;
inline constexpr int NUM_LENGTH = 3;
inline constexpr std::string_view CHARSET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
inline constexpr std::string_view NUMSET = "0123456789";
inline constexpr int MAX_NUM_NAMES = std::pow(CHARSET.length(), CHAR_LENGTH) *
                                     std::pow(NUMSET.length(), NUM_LENGTH);

// TODO: add your solution here
class robot {
public:
    robot();
    std::string name() const;
    void reset();

private:
    std::string m_name;
    static std::unordered_set<std::string> m_usedNames;
};

}  // namespace robot_name

#endif  // ROBOT_NAME_H