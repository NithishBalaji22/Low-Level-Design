#include "Originator.hpp"
#include "Memento.hpp"

Originator::Originator(int height, int width){
    this->height = height;
    this->width = width;
}

void Originator::showHeightWidth(){
    cout<<"Height: "<<height<<endl;
    cout<<"Width: "<<width<<endl;
}

void Originator::setHeight(int height){
    this->height = height;
}

void Originator::setWidth(int width){
    this->width = width;
}

Memento* Originator::createSnapshot(){
    return new Memento(height, width);
}

void Originator::restoreMemento(Memento* prevState){
    setHeight(prevState->getHeight());
    setWidth(prevState->getWidth());
}