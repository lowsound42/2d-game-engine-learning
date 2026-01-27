#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H
#include "../ECS/ECS.h"

class MovementSystem : public System
{
public:
    MovementSystem()
    {
        // What components will this system require?
        // RequireComponent<TransformComponent>();
        // RequireComponent<>();
    }
    void Update()
    {
        // loop all entities that system cares about and do stuff
        // for (auto entity : GetEntities())
        // {
        //     // Update entity position based on velocity
        // }
    }
};

#endif