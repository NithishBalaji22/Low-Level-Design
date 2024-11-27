#pragma once
#include  <iostream>
#include <stack>
#include "CommandInterface.hpp"
using namespace std;

class MyRemoteControl{
    private:
        ICommand* command;
        stack<ICommand*> commandHistory;
    
    public:
        MyRemoteControl() {
            commandHistory = stack<ICommand*>();
        }

        void setCommand(ICommand* command){
            this->command = command;
            commandHistory.push(command);
        }

        void pressButton(){
            command->execute();
        }

        void undo(){
            if(!commandHistory.empty()){
                ICommand* prevCommand = commandHistory.top();
                commandHistory.pop();
                prevCommand->undo();
            }else{
                cout<<"Ac is never turned On!!"<<endl;
            }
        }
};