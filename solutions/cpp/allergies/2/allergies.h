#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>

namespace allergies {

inline const std::unordered_map<std::string_view, int> allergyItems = {
    {"eggs",         0b00000001},
    {"peanuts",      0b00000010},
    {"shellfish",    0b00000100},
    {"strawberries", 0b00001000},
    {"tomatoes",     0b00010000},
    {"chocolate",    0b00100000},
    {"pollen",       0b01000000},
    {"cats",         0b10000000}
};

class allergy_test {
public:
    allergy_test(int allergyScore) : m_allergyScore(allergyScore) {};

    std::unordered_set<std::string> get_allergies() const;
    bool is_allergic_to(const std::string& allergy) const;
private:
    int m_allergyScore;
};

}  // namespace allergies
