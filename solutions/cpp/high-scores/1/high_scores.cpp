#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    // TODO: Return all scores for this session.
    return scores;
}

int HighScores::latest_score() {
    // TODO: Return the latest score for this session.
    return scores.back();
}

int HighScores::personal_best() {
    // TODO: Return the highest score for this session.
    int best = scores[0];
    for (auto it = scores.begin(); it != scores.end(); it++)
    {
        if (*it > best) { best = *it; }
    }
    return best;
}

std::vector<int> HighScores::top_three() {
    // TODO: Return the top 3 scores for this session in descending order.
    std::vector<int> sortedScores{scores};
    std::sort(sortedScores.begin(), sortedScores.end(), [](int a, int b) { return a > b;});

    if (sortedScores.size() < 3) { return sortedScores; }
    else { return std::vector<int>(sortedScores.begin(), sortedScores.begin() + static_cast<size_t>(3));}
}

}  // namespace arcade
