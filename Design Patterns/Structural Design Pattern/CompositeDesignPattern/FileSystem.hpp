#pragma once
#include <iostream>
using namespace std;

class FileSystem{
    public:
        virtual void ls() = 0;
        virtual void changeName(string newName) = 0;
        virtual string getName() = 0;
};