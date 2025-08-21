#include "beer_song.h"
#include <sstream>

namespace beer_song {

namespace {

std::string part_of_verse(int ver, bool begSentence)
{
    return (ver == 0 ? std::string(begSentence ? "N" : "n") + "o more" : std::to_string(ver)) +
           (ver == 1 ? " bottle" : " bottles") + " of beer";
}

std::string end_of_verse(int ver)
{
    std::ostringstream endVerse;
    if (ver == 0)
        endVerse << "Go to the store and buy some more, " << part_of_verse(99, false);
    else
        endVerse << "Take " << (ver == 1 ? "it" : "one") << " down and pass it around, "
                 << part_of_verse(ver - 1, false);
    endVerse << " on the wall.\n";

    return endVerse.str();
}

} // namespace

std::string verse(int ver)
{
    std::ostringstream result;
    result << part_of_verse(ver, true) << " on the wall, "
           << part_of_verse(ver, false) << ".\n"
           << end_of_verse(ver);

    return result.str();
}

std::string sing(int verStart, int verEnd)
{
    std::ostringstream song;
    for (int i = verStart; i >= verEnd; --i)
    {
        song << verse(i);
        if (i != verEnd)
            song << "\n";
    }

    return song.str();
}

}  // namespace beer_song
