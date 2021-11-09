#pragma once 

struct Vector2{
    float x,y;

    Vector2():x(0),y(0){}
    Vector2(float _x, float _y):x(_x),y(_y){}

    
    Vector2 & operator+(const Vector2& other){    
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2 & operator-(const Vector2& other){    
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2 & operator=(const Vector2& other){    
        x = other.x;
        y = other.y;
        return *this;
    }

    Vector2 & operator+=(const Vector2& other){
        return *this + other;
    }
    Vector2 & operator-=(const Vector2& other){
        return *this - other;
    }

    Vector2 & operator*(const float scalar){    
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2 & operator/(const float scalar){    
        x /= scalar;
        y /= scalar;
        return *this;
    }



    void write(std::ostream & o) const {
        o<<"("<<x<<", "<<y<<")";
    }
};
    std::ostream & operator <<(std::ostream & o, const Vector2 & rhs){
        rhs.write(o);
        return o;
    }

    inline bool operator==(const Vector2& lhs, const Vector2& rhs){ return (lhs.x == rhs.x) && (lhs.y == rhs.y);}
    inline bool operator!=(const Vector2& lhs, const Vector2& rhs){ return !(lhs == rhs); }
