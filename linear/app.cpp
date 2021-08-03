#include "app.h"
#include <math.h>

    app::app(){
        window.create(sf::VideoMode(750, 500), "Linear Physics", sf::Style::Default);
        tgt.setFillColor(sf::Color::Red);
        tgt.setRadius(5.f);

        in.setFillColor(sf::Color::Green);
        in.setRadius(2.f);
        in.setPosition(250,150);
        

    }

    void app::Run(){
        while(window.isOpen()){
            Update();
            Draw();
        }
    }

    void app::Update(){
        sf::Event ev;

        while (window.pollEvent(ev)){
            if(ev.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                radious -= 1;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                radious += 1;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                window.clear();
        }
        // if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            // draw a line between mouse and target
        
        theta += 0.1/radious;
        if (theta >= 360)
            theta = 0;
        
        float x = sin(theta) * radious;
        float y = cos(theta) * radious;

        center = in.getPosition();
        mouse = sf::Mouse::getPosition(window);

        if (center.x != mouse.x)
            if(center.x < mouse.x)
                center.x += velocity;
            else
                center.x -= velocity;
        
        if (center.y != mouse.y)
            if(center.y < mouse.y)
                center.y += velocity;
            else
                center.y -= velocity;

        in.setPosition(center);

        tgt.setPosition(x+center.x,y+center.y);

    }

    void app::Draw(){
        // window.clear();
        window.draw(tgt);
        window.draw(in);
        window.display();
    }