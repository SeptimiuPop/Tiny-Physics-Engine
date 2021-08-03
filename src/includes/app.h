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
        
        void HandleInputs();
        void Rotate();
        void Move();
        void Line();
    
    private:

        sf::RenderWindow window;
        
        sf::CircleShape targetObject;
        sf::CircleShape centerPoint;
        sf::RectangleShape line;
        
        float angleTheta=0;
        float radious=10;
        float velocity=0.05;

        sf::Vector2f center;
        sf::Vector2i mouse;

 
    // 
    // MOVEMENT:
    //      velocity = dist I want to travel on each frame
    //      How do I scale x and y to obey the function?
    // 
    // ANSWER:
    //      for each (y) there are (a) time (x)es
    //      basically a is the scalar
    //  
    //      F(x) = y = ax + b
    //  
    //      daca: v^2 = (x^2) + (y^2)
    //            v^2 = (x)^2 + (ax+b)^2
    //  
    //      solve for x:
    //  
    //      v2 = x2 + a2x2 + 2 * axb + b2
    //  
    //      x2 * (a2 + 1) + 2 * axb + b2 - v2 = 0 
    //  
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    // #  y = v/(a+1)                      # 
    // #  x = y/a                          #
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    //  
    // next: get the following point using velocity
    // 
    // FOR SLINGING SHOT: 
    // velocity = dist(mouse, target) * scaling


    // f(x) = ax + b
    // 
    // 2 points: mouse & target
    // 
    // mouse.y = a mouse.x + b  => b = mouse.y - a mouse.x
    // trget.y = a trget.x + b  => a = (trget.y - b )/trget.x 

    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // #  a = ty-my / tx - mx                   # 
    // #  b = my - a*mx = ty - a*tx             # 
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // #  v2 = x2 + y2 | => x = sqrt(v2/a2+1)   #
    // #  y = ax       |                        #
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

};