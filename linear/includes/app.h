#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class app{
    public:

        app();
        void Run();
        void Update();
        void Draw();
    
    private:

        sf::RenderWindow window;
        
        sf::CircleShape tgt;
        sf::CircleShape in;
        
        float theta=0;
        float radious=10;
        float velocity=0.05;

        sf::Vector2f center;
        sf::Vector2i mouse;

    // f(x) = ax + b
    // 
    // 2 points: mouse & target
    // 
    // mouse.y = a mouse.x + b  => b = mouse.y - a mouse.x
    // trget.y = a trget.x + b  => a = (trget.y - b )/trget.x 
    // 
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    // #  a = ty-my / tx - mx              #
    // #  b = my - a*mx = ty - a*tx        #
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    // 
    // MOVEMENT:
    //      velocity = dist I want to travel on each frame
    //      How do I scale x and y to obey the function?
    // 
    // ANSWER:
    //      for each (y) there are (a) time (x)es
    //      basically a is the scalar
    //  
    //      daca: v = x+y => v = (a+1)*y
    //  
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    // #  y = v/(a+1)                      # 
    // #  x = y/a                          #
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    //  
    // next: get the following point using velocity
    // 
    // velocity = dist(mouse, target) * scaling
};