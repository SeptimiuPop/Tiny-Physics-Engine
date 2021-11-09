#include "Object.h"

    Object::Object(){
        mass = 4;
        acceleration = sf::Vector2f(0,-98.1);
        velocity = sf::Vector2f(0,0);
        position = sf::Vector2f(375,250);
    }

    Object::Object(float mass_, sf::Vector2f acceleration_, sf::Vector2f velocity_, sf::Vector2f position_):
        mass(mass_), acceleration(acceleration_), velocity(velocity_), position(position_){}
