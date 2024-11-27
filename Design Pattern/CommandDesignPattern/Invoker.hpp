#pragma once
#include  <iostream>
#include "CommandInterface.hpp"
using namespace std;

class MyRemoteControl{
    private:
        ICommand* command;
    
    public:
        MyRemoteControl() {}

        void setCommand(ICommand* command){
            this->command = command;
        }

        void pressButton(){
            command->execute();
        }

        void undo(){
            command->undo();
        }
};