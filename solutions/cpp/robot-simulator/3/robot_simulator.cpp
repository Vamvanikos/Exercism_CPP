#include "robot_simulator.h"
#include <stdexcept>

namespace robot_simulator {

Robot::Robot() : Robot({0, 0}, Bearing::NORTH) {};
Robot::Robot(const std::pair<int, int>& pos, Bearing bearing) :
    m_position(pos), m_bearingInt(static_cast<int>(bearing)) {};

std::pair<int, int> Robot::get_position() const
{
    return m_position;
}
    
Bearing Robot::get_bearing() const
{
    return static_cast<Bearing>(m_bearingInt);
}

void Robot::turn_left()
{
    m_bearingInt = (m_bearingInt + NUM_OF_DIRECTIONS - 1) % NUM_OF_DIRECTIONS;
}

void Robot::turn_right()
{
    m_bearingInt = (m_bearingInt + 1) % NUM_OF_DIRECTIONS;
}
    
void Robot::advance()
{
    m_position.first += directions[m_bearingInt].first;
    m_position.second += directions[m_bearingInt].second;
}
    
void Robot::execute_sequence(const std::string& seq)
{
    for (char command : seq)
    {
        switch (command)
        {
        case LEFT:    turn_left();  break;
        case RIGHT:   turn_right(); break;
        case ADVANCE: advance();    break;
        default:
            throw std::domain_error("Command must be one of [L, R, A].");
        }
    }
}

}  // namespace robot_simulator
