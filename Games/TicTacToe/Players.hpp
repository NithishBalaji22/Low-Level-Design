#pragma once
#include<bits/stdc++.h>
using namespace std;

class Players{
    private:
        string name;
        char symbol;

    public:
        Players(string name, char symbol): name(name), symbol(symbol) {}

        string getName(){
            return name;
        }
        char getSymbol(){
            return symbol;
        }
};