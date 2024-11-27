#pragma once
#include <iostream>
#include "CommandInterface.hpp"
#include "Receiver.hpp"
using namespace std;

class TurnOffCommand : public ICommand{
    private:
        AcConditioner* ac;

    public:
        TurnOffCommand(AcConditioner* ac){
            this->ac = ac;
        }

        void execute() override{
            ac->acOff();
        }

        void undo() override{
            ac->acOn();
        }
};