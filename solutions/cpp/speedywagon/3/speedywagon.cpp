#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(const std::vector<int>* data_array) {
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

bool connection_check(const pillar_men_sensor* sensor)
{
    return sensor;
}

int activity_counter(const pillar_men_sensor* firstSensor, size_t capacity)
{
    if (!firstSensor || capacity == 0)
        return 0;
    
    int totalActivity = 0;
    for (size_t i = 0; i < capacity; ++i)
        totalActivity += (firstSensor + i)->activity;

    return totalActivity;
}

bool alarm_control(const pillar_men_sensor* sensor)
{
    return sensor && sensor->activity > 0;
}

bool uv_alarm(const pillar_men_sensor* sensor)
{
    if (!sensor || sensor->data.empty())
        return false;
    
    int uvLight = uv_light_heuristic(&sensor->data);
    
    return uvLight > sensor->activity;
}

}  // namespace speedywagon
