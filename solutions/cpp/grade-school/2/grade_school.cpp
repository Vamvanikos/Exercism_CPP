#include "grade_school.h"

namespace grade_school {

std::map<int, std::vector<std::string>> school::roster() const
{
    std::map<int, std::vector<std::string>> retRoster;
    for (const auto& [gr, nameSet] : m_roster)
        retRoster[gr] = std::vector<std::string>(nameSet.begin(), nameSet.end());
    
    return retRoster;
}

void school::add(const std::string& name, int grade)
{
    m_roster[grade].insert(name);
}

std::vector<std::string> school::grade(int grade) const
{
    auto it = m_roster.find(grade);

    return (it != m_roster.end()) ? std::vector<std::string>(it->second.begin(), it->second.end()) : std::vector<std::string>{};
}

}  // namespace grade_school
