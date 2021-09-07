#include "App.h"

    App::App(){
        window.create(sf::VideoMode(750, 500), "Linear Physics", sf::Style::Default);
        objects = testBed.GetObjects();
        world.AddObject();
    }

    void App::Run(){
        while(window.isOpen()){
            Update();
            Draw();
        }
    }

    void App::Update(){
        testBed.Update(&window);
        world.Step(0.005);
        HandleInputs();
    }

    void App::Draw(){
        window.clear();
        for (auto obj : objects)
            window.draw(*obj);
        window.display();
    }




    void App::HandleInputs(){
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
                    testBed.ChangeRadious(-1);
                if (event.key.code == sf::Keyboard::D)
                    testBed.ChangeRadious( 1);
                if (event.key.code == sf::Keyboard::C)
                    window.clear();
                
            default:
                break;
            }
        }
    }
