#pragma once

#include "Includes.h"
#include "PhysicsWorld.h"
#include "PhysicsTestBed.h"

class App{
    public:

        App();
        void Run();
        void Update();
        void Draw();
        
        void HandleInputs();
    
    private:

        PhysicsTestBed testBed;
        PhysicsWorld world;

        std::vector<sf::CircleShape*> objects;
        sf::RenderWindow window;
};