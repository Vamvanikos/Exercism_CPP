#include <string>

namespace star_map
{

enum class System
{
    BetaHydri,
    Sol,
    EpsilonEridani,
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani
};
    
} //star_map


namespace heaven
{

class Vessel
{
public:
    Vessel(std::string inputName, int gen);
    Vessel(std::string inputName, int gen, star_map::System starStuff);

    Vessel replicate(std::string inputName);
    void make_buster();
    bool shoot_buster();    

    std::string name;
    int generation;
    int busters;
    star_map::System current_system;
};

std::string get_older_bob(Vessel name1, Vessel name2);
bool in_the_same_system(Vessel name1, Vessel name2);
    
} //heaven