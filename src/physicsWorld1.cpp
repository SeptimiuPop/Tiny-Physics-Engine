#include "physicsWorld1.h"
#include <math.h>

    PhysicsWorld1::PhysicsWorld1(){
        center = sf::Vector2f(250,150);
        
        targetObject.setFillColor(sf::Color::Red);
        targetObject.setRadius(5.f);

        centerPoint.setFillColor(sf::Color::Green);
        centerPoint.setRadius(2.f);
        centerPoint.setPosition(center);
        

        line.setSize(sf::Vector2f(50,5));
        line.setPosition(center);


    }
    
    void PhysicsWorld1::Update(sf::RenderWindow* window){
        center = centerPoint.getPosition();
        mouse = sf::Mouse::getPosition(*window);

        Rotate();
        Move();
    }

    std::vector<sf::CircleShape*> PhysicsWorld1::GetObjects(){
        std::vector<sf::CircleShape*> objects;
        objects.push_back(&targetObject);
        objects.push_back(&centerPoint);
        return objects;
    }

    void PhysicsWorld1::ChangeRadious(int number){
        radious += number;    
    }
    
    void PhysicsWorld1::Rotate(){
        angleTheta += 0.1/radious;
        if (angleTheta >= 360)
            angleTheta = 0;
        
        float x = sin(angleTheta) * radious;
        float y = cos(angleTheta) * radious;
        targetObject.setPosition(x+center.x,y+center.y);        
    }

    void PhysicsWorld1::Move(){

        if(abs(mouse.x-center.x) > 0.3 &&
           abs(mouse.y-center.y) > 0.3 ){
            float speed = 0.05;

            float gradient = abs(center.x-mouse.x)/abs(center.y-mouse.y);
            
            float ratio = speed / (1+gradient);

            float distX, distY;

            distY = ratio;
            distX = ratio * gradient;


            if(center.x > mouse.x)
                distX = -distX;
            if(center.y > mouse.y)
                distY = -distY;
            
            centerPoint.move(sf::Vector2f(distX, distY));
        }        
    }

    void PhysicsWorld1::Line(sf::RenderWindow* window){
        mouse = sf::Mouse::getPosition(*window);

        float distX, distY;

        distX = center.x-mouse.x;
        distY = center.y-mouse.y;

        // float ratio = (center.y-mouse.y)/(center.x-mouse.x);
        float angle = atan2(distY,distX) * 180/M_PI;

        std::cout<<angle<<"\n";

        line.setRotation(angle);

    }