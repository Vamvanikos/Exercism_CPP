#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <unordered_set>
#include <unordered_map>

namespace allergies {

// TODO: add your solution here
class allergy_test
{
public:
    allergy_test(const unsigned int& score);
    bool is_allergic_to(const std::string& item);
    std::unordered_set<std::string> get_allergies();

private:
    unsigned int m_score;

    std::unordered_map<std::string, unsigned int> allergy_items
    {
        {"eggs", 1},
        {"peanuts", 2},
        {"shellfish", 4},
        {"strawberries", 8},
        {"tomatoes", 16},
        {"chocolate", 32},
        {"pollen", 64},
        {"cats", 128}
    };
};
    
}  // namespace allergies

#endif  // ALLERGIES_H