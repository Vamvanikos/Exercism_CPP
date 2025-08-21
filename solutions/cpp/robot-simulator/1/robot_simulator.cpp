#include "robot_simulator.h"

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
    switch (m_bearing)
    {
        case Bearing::NORTH:
            m_bearing = Bearing::EAST;
            break;
        case Bearing::EAST:
            m_bearing = Bearing::SOUTH;
            break;
        case Bearing::SOUTH:
            m_bearing = Bearing::WEST;
            break;
        case Bearing::WEST:
            m_bearing = Bearing::NORTH;
            break;
    }
}

void Robot::turn_left()
{
    switch (m_bearing)
    {
        case Bearing::NORTH:
            m_bearing = Bearing::WEST;
            break;
        case Bearing::EAST:
            m_bearing = Bearing::NORTH;
            break;
        case Bearing::SOUTH:
            m_bearing = Bearing::EAST;
            break;
        case Bearing::WEST:
            m_bearing = Bearing::SOUTH;
            break;
    }
}

void Robot::advance()
{
    switch (m_bearing)
    {
        case Bearing::NORTH:
            ++m_position.second;
            break;
        case Bearing::EAST:
            ++m_position.first;
            break;
        case Bearing::SOUTH:
            --m_position.second;
            break;
        case Bearing::WEST:
            --m_position.first;
            break;
    }
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
        }
    }
}

}  // namespace robot_simulator
