#include <string>

namespace star_map {

enum class System {
    BetaHydri,
    Sol,
    EpsilonEridani,
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani
};
    
}

namespace heaven {

class Vessel {
public:    
    Vessel(std::string n, int gen, star_map::System starSystem) : name(std::move(n)), generation(gen), current_system(starSystem) {};
    Vessel(std::string n, int gen) : Vessel(std::move(n), gen, star_map::System::Sol) {};

    Vessel replicate(std::string n) const;
    void make_buster();
    bool shoot_buster();

    std::string name;
    int generation;
    star_map::System current_system;
    int busters = 0;
};

std::string get_older_bob(const Vessel& v1, const Vessel& v2);
bool in_the_same_system(const Vessel& v1, const Vessel& v2);

}