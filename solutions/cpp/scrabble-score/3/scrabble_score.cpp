#include "scrabble_score.h"

namespace scrabble_score {

int score(std::string_view word)
{
    int sum = 0;
    for (char letter : word)
    {
        unsigned char uLetter = static_cast<unsigned char>(letter);
        if (std::isalpha(uLetter))
            sum += scoreList[std::toupper(uLetter) - 'A'];
    }

    return sum;
}

}  // namespace scrabble_score
