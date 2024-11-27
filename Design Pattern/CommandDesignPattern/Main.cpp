#include <iostream>
#include "Invoker.hpp"
#include "Receiver.hpp"
#include "CommandInterface.hpp"
#include "CommandTurnOnAc.hpp"
#include "CommandTurnOffAc.hpp"
using namespace std;

int main(){
    AcConditioner* ac = new AcConditioner();
    MyRemoteControl* remote = new MyRemoteControl();

    remote->setCommand(new TurnOnCommand(ac));
    remote->pressButton();    
}