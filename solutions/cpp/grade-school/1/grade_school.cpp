#include "grade_school.h"
#include <algorithm>

namespace grade_school {

// TODO: add your solution here
void school::add(const std::string& name, const int& rank)
{
    if (mapGradesNames.find(rank) == mapGradesNames.end())
    {
        mapGradesNames.insert({rank, {name}});
    }
    else
    {
        mapGradesNames[rank].push_back(name);
        std::sort(mapGradesNames[rank].begin(), mapGradesNames[rank].end());
    }
}
    
const std::map<int, std::vector<std::string>>& school::roster() const
{
    return mapGradesNames;
}

const std::vector<std::string> school::grade(const int& rank) const
{
    std::vector<std::string> ret;
    if(mapGradesNames.find(rank) != mapGradesNames.end())
    {
        ret = mapGradesNames.at(rank);
    }

    return ret;
}

}  // namespace grade_school
