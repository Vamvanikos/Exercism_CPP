#include "robot_name.h"
#include <random>
#include <algorithm>
#include <stdexcept>

namespace robot_name {

// TODO: add your solution here
std::unordered_set<std::string> robot::m_usedNames;
    
robot::robot()
{ 
    m_name.reserve(CHAR_LENGTH + NUM_LENGTH);
    reset();
}
    
std::string robot::name() const
{
    return m_name;
}

void robot::reset()
{
    if (m_usedNames.size() == MAX_NUM_NAMES)
    {
        throw std::runtime_error("All possible names are already given.");
    }
    
    std::random_device rd;  // Seed
    std::mt19937 generator(rd());  // Random number engine
    std::uniform_int_distribution<> distChar(0, CHARSET.size() - 1);
    std::uniform_int_distribution<> distNum(0, NUMSET.size() - 1);

    do 
    {
        m_name.clear();
        for(int i = 0; i < CHAR_LENGTH; ++i)
        {
            m_name += CHARSET[distChar(generator)];
        }
        for(int i = 0; i < NUM_LENGTH; ++i)
        {
            m_name += NUMSET[distNum(generator)];
        }
    } while(m_usedNames.find(m_name) != m_usedNames.end());

    m_usedNames.insert(m_name);

}

}  // namespace robot_name
