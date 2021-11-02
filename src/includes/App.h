#pragma once

#include "Includes.h"
#include "PhysicsWorld.h"
#include "PhysicsTestBed.h"

class App{

    // -------------------------------------------- Functions --------------------------------------------

    public:

        App();
        void Run();
    
    private:
    
        void Update();
        void Draw();
        void HandleInputs();

    // -------------------------------------------- Fields --------------------------------------------
    
    private:

        PhysicsTestBed testBed;
        PhysicsWorld world;

        std::vector<sf::CircleShape>* objects;
        sf::RenderWindow window;

        float delta_time;
        sf::Clock clock;
};