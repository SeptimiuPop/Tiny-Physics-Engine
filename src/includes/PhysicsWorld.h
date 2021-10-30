#pragma once 
#include "Object.h"
#include "Includes.h"
#include <vector>

class PhysicsWorld{
private:

    std::vector<Object> objects;
    sf::Vector2f gravity;
    
    sf::FloatRect border;
    sf::CircleShape particle;
    sf::CircleShape particle1;

public:

    PhysicsWorld();
    void Step(float);
    void AddObject();
    void RemoveObject();
    void HandleCollision(Object&);

    std::vector<sf::CircleShape*> GetObjects(); 
};