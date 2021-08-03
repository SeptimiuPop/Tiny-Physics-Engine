#!/bin/bash

clear
cd bin

rm *.o, main.exe

# read prj
prj="src"

echo "Building the enviroment..."
echo


g++ -c ../$prj/*.cpp -I ../$prj/includes
g++ *.o -o main.exe -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system # to link.

./main.exe 

echo
cd ..
ls $prj