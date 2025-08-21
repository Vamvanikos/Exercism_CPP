#include <stdexcept>

namespace targets {

inline constexpr int DEFAULT_HEALTH = 3U;
    
class Alien {
public:
    int x_coordinate;
    int y_coordinate;
    int health;    
    
    Alien(const int x, const int y): x_coordinate(x), y_coordinate(y),
                                     health(DEFAULT_HEALTH) {};
    int get_health() const
    {
        return health;
    }
    
    bool hit()
    {
        if (health)
            --health;

        return true;
    }

    bool is_alive() const
    {
        return health;
    }

    bool teleport(const int x_new, const int y_new)
    {
        x_coordinate = x_new;
        y_coordinate = y_new;

        return true;
    }

    bool collision_detection(const Alien& otherAlien) const
    {
        return x_coordinate == otherAlien.x_coordinate &&
                y_coordinate == otherAlien.y_coordinate;
    }
};

}  // namespace targets