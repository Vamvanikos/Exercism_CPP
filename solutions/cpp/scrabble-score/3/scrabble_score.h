#pragma once
#include <string>
#include <array>

namespace scrabble_score {

constexpr std::array<int, 26> createScoreList()
{
    std::array<int, 26> score {};
    score['A' - 'A'] = 1;  score['E' - 'A'] = 1; score['I' - 'A'] = 1;
    score['O' - 'A'] = 1;  score['U' - 'A'] = 1; score['L' - 'A'] = 1;
    score['N' - 'A'] = 1;  score['R' - 'A'] = 1; score['S' - 'A'] = 1;
    score['T' - 'A'] = 1;
    score['D' - 'A'] = 2;  score['G' - 'A'] = 2;
    score['B' - 'A'] = 3;  score['C' - 'A'] = 3; score['M' - 'A'] = 3;
    score['P' - 'A'] = 3;
    score['F' - 'A'] = 4;  score['H' - 'A'] = 4; score['V' - 'A'] = 4;
    score['W' - 'A'] = 4;  score['Y' - 'A'] = 4;
    score['K' - 'A'] = 5;
    score['J' - 'A'] = 8;  score['X' - 'A'] = 8;
    score['Q' - 'A'] = 10; score['Z' - 'A'] = 10;

    return score;
}

inline constexpr std::array<int, 26> scoreList = createScoreList();
    
int score(std::string_view word);

}  // namespace scrabble_score
