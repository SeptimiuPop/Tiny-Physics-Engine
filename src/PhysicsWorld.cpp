#include "PhysicsWorld.h"

   // -------------------------------------------- Constructor/Destructor --------------------------------------------



    PhysicsWorld::PhysicsWorld(){
        gravity = sf::Vector2f(0,-9.81);
        border = sf::FloatRect(sf::Vector2f(25,25), sf::Vector2f(700,450));
    }



    // -------------------------------------------- Public Functions --------------------------------------------



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
        // SHOULD COME LATER IN RENDERER
        // Addigns a position to the shape linked with the object
        sf::Vector2f poz;
        for (int i=0; i<objects.size(); i++){
            poz = objects[i].position;
            poz.y = 500 - poz.y;        // Invert y by window height 
            shapes[i].setPosition(poz);
        }
    }


    void PhysicsWorld::AddObject(float mass_, sf::Vector2f acceleration_, sf::Vector2f velocity_, sf::Vector2f position_){
        Object obj(mass_, acceleration_, velocity_, position_);
        objects.push_back(obj);
        
        sf::CircleShape particle;
        particle.setFillColor(sf::Color::Red);
        particle.setRadius(5.f);
        shapes.push_back(particle);
    }


    /*
    *   Creates a default object and a corresponding shape to be drawn
    */
    void PhysicsWorld::AddObject(){   
        Object obj;
        objects.push_back(obj);
        
        sf::CircleShape particle;
        particle.setFillColor(sf::Color::Red);
        particle.setRadius(5.f);
        shapes.push_back(particle);
    }
    

    void PhysicsWorld::RemoveObject(){  }


    /*
    *   Sends off the objects that need to be rendered
    *   Will evenutually be linked with a renderer
    */
    std::vector<sf::CircleShape>* PhysicsWorld::GetObjects(){
        return &shapes;
    } 



    // -------------------------------------------- Private Functions --------------------------------------------



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


