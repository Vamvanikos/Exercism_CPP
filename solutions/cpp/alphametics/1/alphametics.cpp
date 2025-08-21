#include "alphametics.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <optional>
#include <string>
#include <cctype>
#include <set>
#include <algorithm>

namespace alphametics {

namespace {
struct Problem {
    std::vector<std::string> leftSide;
    std::string rightSide;
    std::set<char> letters;
    std::unordered_set<char> firstLetters;
};

Problem parse_problem(const std::string& puzzle)
{
    Problem prob;
    int eqPos = puzzle.find("==");
    std::string leftPart = puzzle.substr(0, eqPos);
    std::string rightPart = puzzle.substr(eqPos + 2);    

    std::string word;
    for (const char ch : leftPart)
    {
        if (std::isalpha(static_cast<unsigned char>(ch)))
            word += ch;
        else if (!word.empty())
        {
            prob.leftSide.push_back(word);
            prob.letters.insert(word.begin(), word.end());
            prob.firstLetters.insert(word[0]);
            word.clear();
        }
    }
    if (!word.empty())
    {
        prob.leftSide.push_back(word);
        prob.letters.insert(word.begin(), word.end());
        prob.firstLetters.insert(word[0]);
    }

    for (const char ch : rightPart)
    {
        if (std::isalpha(static_cast<unsigned char>(ch)))
            prob.rightSide += ch;
    }
    prob.letters.insert(prob.rightSide.begin(), prob.rightSide.end());
    prob.firstLetters.insert(prob.rightSide[0]);

    return prob;
}

bool solve_recursive(const Problem& prob, std::unordered_map<char,int>& assignments, std::unordered_set<int>& used_digits, const int column, const int carry)
{
    if (static_cast<size_t>(column) >= prob.rightSide.size()) {
        return carry == 0;
    }
    
    int column_sum = carry;
    std::vector<char> column_letters;
    for (const auto& word : prob.leftSide)
    {
        int pos = word.size() - 1 - column;
        if (pos >= 0)
        {
            column_letters.push_back(word[pos]);
        }
    }
    char result_letter = prob.rightSide[prob.rightSide.size() - 1 - column];
    
    std::set<char> to_assign;
    for (const char ch : column_letters)
    {
        if (assignments.find(ch) == assignments.end())
        {
            to_assign.insert(ch);
        }
    }
    if (assignments.find(result_letter) == assignments.end())
    {
        to_assign.insert(result_letter);
    }

    if (to_assign.empty())
    {
        for (const char ch : column_letters)
        {
            column_sum += assignments[ch];
        }

        if (column_sum % 10 != assignments[result_letter])
            return false;
        
        return solve_recursive(prob, assignments, used_digits, column + 1, column_sum / 10);
    }

    char ch = *to_assign.begin();
    for (int value = 0; value < 10; ++value)
    {
        if (used_digits.count(value))
            continue;
        if (value == 0 && prob.firstLetters.count(ch))
            continue;

        assignments[ch] = value;
        used_digits.insert(value);

        if (solve_recursive(prob, assignments, used_digits, column, carry))
            return true;

        used_digits.erase(value);
        assignments.erase(ch);
    }

    return false;
}
    
}

std::optional<std::unordered_map<char, int>> solve(const std::string& puzzle)
{
    Problem prob = parse_problem(puzzle);
    std::unordered_map<char, int> assignments;
    std::unordered_set<int> used_digits;
    
    if (solve_recursive(prob, assignments, used_digits, 0, 0))
        return assignments;    
    
    return std::nullopt;
}

}  // namespace alphametics
