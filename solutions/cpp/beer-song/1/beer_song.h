#if !defined(BEER_SONG_H)
#define BEER_SONG_H
#include <string>

namespace beer_song {

// TODO: add your solution here
std::string verse(int ver);
std::string sing(int startVerse, int endVerse = 0);

}  // namespace beer_song

#endif  // BEER_SONG_H