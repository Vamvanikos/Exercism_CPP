#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H
#include <utility>
#include <string>

namespace robot_simulator {

// TODO: add your solution here
inline constexpr char LEFT =    'L';
inline constexpr char RIGHT =   'R';
inline constexpr char ADVANCE = 'A';
    
enum class Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Robot {
public:
Robot();
Robot(const std::pair<int, int>& initPosition, const Bearing& initBearing);
std::pair<int, int> get_position() const;
Bearing get_bearing() const;
void turn_right();
void turn_left();
void advance();
void execute_sequence(const std::string& sequence);

private:
std::pair<int, int> m_position;
Bearing m_bearing;    
};

}  // namespace robot_simulator

#endif  // ROBOT_SIMULATOR_H