#pragma once
#include<iostream>
using namespace std;

class Player{
    private:
        string name;
        int position;

    public:
        Player(string name){
            this->name = name;
            position = 0;
        }

        string getName(){
            return name;
        }

        int getPosition(){
            return position;
        }

        void setPosition(int pos){
            position = pos;
        }
};