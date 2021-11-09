#include "App.h"

    // -------------------------------------------- Constructor/Destructor --------------------------------------------



    App::App(){
        window.create(sf::VideoMode(750, 500), "Linear Physics", sf::Style::Default);
        objects = world.GetObjects();
        world.AddObject();
        world.AddObject(1, sf::Vector2f(10, -300), sf::Vector2f(0,0), sf::Vector2f(400,400));
    }



    // -------------------------------------------- Public Functions --------------------------------------------



    void App::Run(){
        while(window.isOpen()){
            delta_time = clock.getElapsedTime().asSeconds();
            clock.restart();

            Update();
            Draw();
        }
    }



    // -------------------------------------------- Private Functions --------------------------------------------



    void App::Update(){
        testBed.Update(&window);
        world.Step(delta_time);
        HandleInputs();
    }

    void App::Draw(){
        window.clear();
        for (auto obj : *objects)
            window.draw(obj);
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
