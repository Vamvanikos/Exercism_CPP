#include "robot_name.h"
#include <utility>
#include <stdexcept>

namespace robot_name {

std::unordered_set<std::string> robot::m_nameList;
    
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
    if (m_nameList.size() == MAX_NUM_NAMES)
        throw std::runtime_error("All available names are already used.");

    auto& gen = generator();
    std::uniform_int_distribution<> distChar(0, CHARSET.size() - 1);
    std::uniform_int_distribution<> distNum(0, NUMSET.size() - 1);
    
    std::pair<std::unordered_set<std::string>::iterator, bool> result;
    do {
        m_name.clear();
        for (int i =0; i < CHAR_LENGTH; ++i)
            m_name += CHARSET[distChar(gen)];
        for (int i = 0; i < NUM_LENGTH; ++i)
            m_name += NUMSET[distNum(gen)];
        result = m_nameList.emplace(m_name);
    } while (!result.second);
}

std::mt19937& robot::generator()
{
    static std::mt19937 gen(std::random_device{}());  // Random number engine
    
    return gen;
}

}  // namespace robot_name
