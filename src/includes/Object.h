#pragma once 
#include <SFML/System.hpp>


class Object{
    public:

        // trajectory
        float mass;
        sf::Vector2f acceleration;
        sf::Vector2f velocity;
        sf::Vector2f position;

        Object();
        Object(float,sf::Vector2f,sf::Vector2f,sf::Vector2f);


    private:


};