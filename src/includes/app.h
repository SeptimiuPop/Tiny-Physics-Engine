#pragma once
#include "includes.h"
#include "physicsWorld1.h"

class app{
    public:

        app();
        void Run();
        void Update();
        void Draw();
        
        void HandleInputs();
    
    private:

        PhysicsWorld1 world;

        std::vector<sf::CircleShape*> objects;
        sf::RenderWindow window;
};