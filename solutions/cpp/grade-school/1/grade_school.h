#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <map>
#include <vector>
#include <string>

namespace grade_school {

// TODO: add your solution here
class school{
public:
    void add(const std::string& name, const int& rank);
    const std::map<int, std::vector<std::string>>& roster() const;
    const std::vector<std::string> grade(const int& rank) const;

private:
    std::map<int, std::vector<std::string>> mapGradesNames;
};

}  // namespace grade_school

#endif  // GRADE_SCHOOL_H