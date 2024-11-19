#pragma once
#include "IFactory.hpp"
#include <iostream>
using namespace std;

class GUIFactory{
    public:
        static Ifactory* createFactory(string os){
            if(os == "Windows"){
                return new Windows();
            }else if(os == "Mac"){
                return new Mac();
            }
            return new Windows(); // Default
        }
};