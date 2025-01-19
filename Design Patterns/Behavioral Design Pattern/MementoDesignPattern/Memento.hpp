#pragma once
#include <iostream>
using namespace std;

class Memento{
    private:
        int height;
        int width;

    public:
        Memento(int height, int width){
            this->height = height;
            this->width = width;
        }

        int getHeight(){
            return height;
        }

        int getWidth(){
            return width;
        }
};