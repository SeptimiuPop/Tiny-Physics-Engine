#include "PhysicsWorld.h"
#include <iostream>

    PhysicsWorld::PhysicsWorld(){
        gravity = sf::Vector2f(0,-9.81);
    }

    void PhysicsWorld::Step(float dt){   
        for (auto object : objects){
            

            object.force += object.mass * gravity;
 
            object.velocity += object.force / object.mass * dt;
            object.position += object.velocity * dt;
 
            object.force = sf::Vector2f(0,0); // reset net force at the end            
        }
    }
    
    void PhysicsWorld::AddObject(){   
        Object obj;
        obj.force.y = 10;
        obj.mass = 15;
        obj.position = sf::Vector2f(350, 250);
        objects.push_back(obj);
    }
    
    void PhysicsWorld::RemoveObject(){

    }
