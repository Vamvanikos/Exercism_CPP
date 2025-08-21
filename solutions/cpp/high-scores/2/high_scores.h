#pragma once

#include <vector>
#include <optional>

namespace arcade {

class HighScores {
   private:
    std::vector<int> scores;

   public:
    HighScores(std::vector<int> scores) : scores(std::move(scores)){};

    const std::vector<int>& list_scores() const;
    std::optional<int> latest_score() const;
    std::optional<int> personal_best() const;
    std::vector<int> top_three() const;
};

}  // namespace arcade
