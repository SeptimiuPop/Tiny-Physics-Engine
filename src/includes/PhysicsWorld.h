#pragma once 
#include "Object.h"
#include "Includes.h"
#include <vector>

class PhysicsWorld{

    // -------------------------------------------- Functions --------------------------------------------

    public:

        PhysicsWorld();
        void Step(float);

        void AddObject();
        void AddObject(float,sf::Vector2f,sf::Vector2f,sf::Vector2f);
        void RemoveObject();
        
        std::vector<sf::CircleShape>* GetObjects(); 

    private:
    
        void HandleCollision(Object&);

    // -------------------------------------------- Fields --------------------------------------------

    private:

        std::vector<sf::CircleShape> shapes;
        std::vector<Object> objects;

        sf::Vector2f gravity;
        sf::FloatRect border;
};