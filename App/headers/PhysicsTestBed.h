#pragma once 
#include "Includes.h"

class PhysicsTestBed{
    
    // -------------------------------------------- Functions --------------------------------------------

    public:

        PhysicsTestBed();
        void Update(sf::RenderWindow*);
        std::vector<sf::CircleShape*> GetObjects(); 
        void ChangeRadious(int);


    private:

        void Rotate();
        void Move();
        void Line(sf::RenderWindow*);
        
        
    // -------------------------------------------- Fields --------------------------------------------
    
    private:
    
        sf::CircleShape targetObject;
        sf::CircleShape centerPoint;
        sf::RectangleShape line;
        
        float angleTheta=0;
        float velocity=0.05;

        sf::Vector2f center;
        sf::Vector2i mouse;
        float radious=10;

};