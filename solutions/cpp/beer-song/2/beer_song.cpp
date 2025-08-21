#include "beer_song.h"

namespace beer_song {

// TODO: add your solution here

std::string bottlesString(int ver)
{
    if (ver == 0)
        return "no more bottles";
    else if (ver == 1)
        return "1 bottle";
    else
        return (std::to_string(ver) + " bottles");
}

std::string capitalize(const std::string& bottles)
{
    if (bottles.empty())
        return bottles;
    
    std::string ret = bottles;
    ret[0] = std::toupper(ret[0]);

    return ret;
}
    
std::string verse(int ver)
{
    std::string verseString = capitalize(bottlesString(ver)) + " of beer on the wall, " + bottlesString(ver) + " of beer.\n";

    if (ver == 0)
    {
        verseString += "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
    }
    else
    {
        verseString += "Take " + std::string(ver == 1 ? "it" : "one") + " down and pass it around, " + bottlesString(ver - 1) + " of beer on the wall.\n";
    }

    return verseString;
}

std::string sing(int startVerse, int endVerse)
{
    std::string song;
    for (int i = startVerse; i >= endVerse; --i)
    {
        song += verse(i);
        if (i != endVerse) song += "\n";
    }

    return song;
}

}  // namespace beer_song
