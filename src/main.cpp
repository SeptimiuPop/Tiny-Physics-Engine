#include "App.h"
#include "Vector2.h"

int main(){
    
    Vector2 a(3,3);
    Vector2 b(2,2);

    a = b + a*3;
    std::cout<<a<<b;



    // App application;
    // application.Run();


    return 0;

}