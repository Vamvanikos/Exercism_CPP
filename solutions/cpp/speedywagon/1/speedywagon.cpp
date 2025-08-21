#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(pillar_men_sensor* sensor)
{
    return (sensor);
}

int activity_counter(pillar_men_sensor* sensor, int capacity)
{
    int sum = 0;
    if (sensor)
    {
        for (int i = 0; i < capacity; i++)
        {
            sum += (sensor + i)->activity;
        }
    }

    return sum;
}

bool alarm_control(pillar_men_sensor* sensor)
{
    if (sensor && sensor->activity) { return true; }
    
    return false;
}

bool uv_alarm(pillar_men_sensor* sensor)
{
    if (sensor)
    {
        int result = uv_light_heuristic(&sensor->data);

        return (result > sensor->activity);
    }

    return false;
}

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
