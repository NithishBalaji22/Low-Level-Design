#pragma once
#include <iostream>
#include "CommandInterface.hpp"
#include "Receiver.hpp"
using namespace std;

class TurnOnCommand : public ICommand{
    private:
        AcConditioner* ac;

    public:
        TurnOnCommand(AcConditioner* ac){
            this->ac = ac;
        }

        void execute() override{
            ac->acOn();
        }
};