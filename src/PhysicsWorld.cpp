#include "PhysicsWorld.h"

    PhysicsWorld::PhysicsWorld(){
        gravity = sf::Vector2f(0,-9.81);
        particle.setFillColor(sf::Color::Red);
        particle.setRadius(5.f);

        particle1.setFillColor(sf::Color::Red);
        particle1.setRadius(5.f);

        border = sf::FloatRect(sf::Vector2f(25,25), sf::Vector2f(700,450));
    }


    /*
    *   Advances the simulation by one step
    */
    void PhysicsWorld::Step(float dt){   
        for (auto& obj: objects){

            obj.velocity.x += obj.acceleration.x * obj.mass * dt;
            obj.velocity.y += obj.acceleration.y * obj.mass * dt;
            obj.position.x += obj.velocity.x * dt;
            obj.position.y += obj.velocity.y * dt;

            HandleCollision(obj);

        }
        // BAD SOLUTION PLEASE SOLVE
        // Also the physics world is upside down so we have to swap the y (500 = screen height -- should be done by renderer)
        particle.setPosition(sf::Vector2f(objects[0].position.x, 500 - objects[0].position.y));
        particle1.setPosition(sf::Vector2f(objects[1].position.x, 500 - objects[1].position.y));
    }

    /*
    *   Ensures the particle stays within the border set in the constructor
    *   Swaps the direction of velocity with each subsequent collision detection
    *   
    *   MAY WANT TO SWAP IN THE FUTURE FOR LINEAR PARTICLE COLLISION AND A MORE ROBUST SYSTEM
    */
    void PhysicsWorld::HandleCollision(Object& obj){
        if (obj.position.y < border.top){
            obj.position.y = border.top;
            obj.velocity.y *= -1;
            
            // obj.velocity.y -= 20;   // MIMICKING FRICTION ON CONTACT
            // Try next to add acceleration squared 
        } 
        if (obj.position.y > border.height){
            obj.position.y = border.height;
            obj.velocity.y *= -1;

        }
        if (obj.position.x < border.left){
            obj.position.x = border.left;
            obj.velocity.x *= -1;
        }
        if (obj.position.x > border.width){
            obj.position.x = border.width;
            obj.velocity.x *= -1;
        }
    }

    void PhysicsWorld::AddObject(){   
        Object obj1;
        Object obj2(2.5, sf::Vector2f(30,-250), sf::Vector2f(0,0), sf::Vector2f(350, 350));
        objects.push_back(obj1);
        objects.push_back(obj2);
    }
    
    void PhysicsWorld::RemoveObject(){

    }

    /*
    *   Sends off the objects that need to be rendered
    */
    std::vector<sf::CircleShape*> PhysicsWorld::GetObjects(){
        
        // AGAIN BAD SOLUTION FIND A WAY AND CREATE A RENDERER
        std::vector<sf::CircleShape*> objects;
        objects.push_back(&particle);
        objects.push_back(&particle1);
        return objects;
    } 