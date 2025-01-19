#pragma once
#include <iostream>
using namespace std;

class Memento;
class Originator{
    private:
        int height;
        int width;

    public:
        Originator(int height, int width);
        void showHeightWidth();
        void setHeight(int height);
        void setWidth(int width);
        Memento* createSnapshot();
        void restoreMemento(Memento* prevState);
};