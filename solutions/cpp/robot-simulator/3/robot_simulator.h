#pragma once
#include <utility>
#include <string>
#include <array>

namespace robot_simulator {

inline constexpr char LEFT = 'L';
inline constexpr char RIGHT = 'R';
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
    Robot(const std::pair<int, int>& pos, Bearing bearing);
    std::pair<int, int> get_position() const;
    Bearing get_bearing() const;
    void turn_left();
    void turn_right();
    void advance();
    void execute_sequence(const std::string& seq);

private:
    static constexpr int NUM_OF_DIRECTIONS = 4;
    static constexpr std::array<std::pair<int, int>, NUM_OF_DIRECTIONS> directions = {{
        { 0,  1},
        { 1,  0},
        { 0, -1},
        {-1,  0}
    }};
    
    std::pair<int, int> m_position;
    int m_bearingInt;
};

}  // namespace robot_simulator
