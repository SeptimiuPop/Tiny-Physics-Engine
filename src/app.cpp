#include "app.h"

    app::app(){
        window.create(sf::VideoMode(750, 500), "Linear Physics", sf::Style::Default);
        objects = world.GetObjects();
    }

    void app::Run(){
        while(window.isOpen()){
            Update();
            Draw();
        }
    }

    void app::Update(){
        world.Update(&window);
        HandleInputs();
    }

    void app::Draw(){
        window.clear();
        for (auto obj : objects)
            window.draw(*obj);
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
                    world.ChangeRadious(-1);
                if (event.key.code == sf::Keyboard::D)
                    world.ChangeRadious( 1);
                if (event.key.code == sf::Keyboard::C)
                    window.clear();
                
            default:
                break;
            }
        }
    }
