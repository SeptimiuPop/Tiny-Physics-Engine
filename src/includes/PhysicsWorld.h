#pragma once 
#include "Object.h"
#include <vector>

class PhysicsWorld{
private:
    std::vector<Object> objects;
    sf::Vector2f gravity;

public:

    PhysicsWorld();

    void Step(float);
    void AddObject();
    void RemoveObject();
};