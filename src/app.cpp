#include "app.h"
#include <math.h>
#include <iostream>

    app::app(){
        window.create(sf::VideoMode(750, 500), "Linear Physics", sf::Style::Default);
        
        center = sf::Vector2f(250,150);
        
        targetObject.setFillColor(sf::Color::Red);
        targetObject.setRadius(5.f);

        centerPoint.setFillColor(sf::Color::Green);
        centerPoint.setRadius(2.f);
        centerPoint.setPosition(center);
        

        line.setSize(sf::Vector2f(50,5));
        line.setPosition(center);
    }

    void app::Run(){
        while(window.isOpen()){
            Update();
            Draw();
        }
    }

    void app::Update(){
        
        HandleInputs();
        Rotate();
        Move();
        // Line();
    }

    void app::Draw(){
        window.clear();
        window.draw(targetObject);
        window.draw(centerPoint);
        window.display();
    }




    void app::HandleInputs(){
        sf::Event event;

        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            switch (event.type)
            
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                if (event.key.code == sf::Keyboard::A)
                    radious -= 1;
                if (event.key.code == sf::Keyboard::D)
                    radious += 1;
                if (event.key.code == sf::Keyboard::C)
                    window.clear();
                
            default:
                break;
            }
        }
        // if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            // draw a line between mouse and target

    }


    void app::Rotate(){
        angleTheta += 0.1/radious;
        if (angleTheta >= 360)
            angleTheta = 0;
        
        float x = sin(angleTheta) * radious;
        float y = cos(angleTheta) * radious;
        targetObject.setPosition(x+center.x,y+center.y);

    }

    void app::Move(){
        center = centerPoint.getPosition();
        mouse = sf::Mouse::getPosition(window);

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

    void app::Line(){
        mouse = sf::Mouse::getPosition(window);

        float distX, distY;

        distX = center.x-mouse.x;
        distY = center.y-mouse.y;

        // float ratio = (center.y-mouse.y)/(center.x-mouse.x);
        float angle = atan2(distY,distX) * 180/M_PI;

        std::cout<<angle<<"\n";

        line.setRotation(angle);

    }