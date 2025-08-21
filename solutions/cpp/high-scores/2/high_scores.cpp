#include "high_scores.h"
#include <algorithm>

namespace arcade {

const std::vector<int>& HighScores::list_scores() const
{
    return scores;
}

std::optional<int> HighScores::latest_score() const
{
    if (!scores.empty())
        return scores.back();
    return std::nullopt;
}

std::optional<int> HighScores::personal_best() const
{
    if (!scores.empty())
        return *max_element(scores.begin(), scores.end());
    return std::nullopt;
}

std::vector<int> HighScores::top_three() const
{
    std::vector<int> sortedScores = scores;
    sort(sortedScores.begin(), sortedScores.end(), std::greater<int>());
    
    if (sortedScores.size() > 3)
        sortedScores.resize(3);

    return sortedScores;
}

}  // namespace arcade
