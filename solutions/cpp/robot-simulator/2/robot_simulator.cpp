#include "robot_simulator.h"
#include <array>
#include <stdexcept>

namespace robot_simulator {

// TODO: add your solution here
Robot::Robot() : Robot({0, 0}, Bearing::NORTH) {}
    
Robot::Robot(const std::pair<int, int>& initPosition, const Bearing& initBearing) :
    m_position(initPosition), m_bearing(initBearing) {}

std::pair<int, int> Robot::get_position() const
{
    return m_position;
}

Bearing Robot::get_bearing() const
{
    return m_bearing;
}

void Robot::turn_right()
{
    m_bearing = static_cast<Bearing>((static_cast<int>(m_bearing) + 1) % 4);
}

void Robot::turn_left()
{
    m_bearing = static_cast<Bearing>((static_cast<int>(m_bearing) + 3) % 4);
}

void Robot::advance()
{
    static constexpr std::array<std::pair<int, int>, 4> advancement = {
        std::pair<int, int>
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

    const auto& delta = advancement[static_cast<int>(m_bearing)];
    m_position.first += delta.first;
    m_position.second += delta.second;
}

void Robot::execute_sequence(const std::string& sequence)
{
    for (const char move : sequence)
    {
        switch (move)
        {
            case LEFT:
                turn_left();
                break;
            case RIGHT:
                turn_right();
                break;
            case ADVANCE:
                advance();
                break;
            default:
                throw std::invalid_argument("Available movements are 'turn left', 'turn right' and 'advance'.");
        }
    }
}

}  // namespace robot_simulator
