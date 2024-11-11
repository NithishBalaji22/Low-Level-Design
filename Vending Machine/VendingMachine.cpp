#include "VendingMachine.hpp"
#include "States.hpp"

void VendingMachine::setProductId(int id){
    this->productId = id;
}

State* VendingMachine::getVendingMachineState(){
    return VendingMachineState;
}

State* VendingMachine::getIdleState(){
    return idleState;
}

State* VendingMachine::getHasMoneyState(){
    return hasMoneyState;
}

State* VendingMachine::getSelectProductState(){
    return productSelect;
}

State* VendingMachine::getDispenseProductState(){
    return dispenseproduct;
}

void VendingMachine::setInventory(Inventory *inventory){
    this->inventory = inventory;
}

Inventory* VendingMachine::getInventory(){
    return inventory;
}

vector<Coin> VendingMachine::getCoins(){
    return coins;
}

void VendingMachine::setSelectedProductId(int id){
    productId = id;
}

int VendingMachine::getSelectedProductId(){
    return productId;
}

void VendingMachine::setState(State *VendingMachineState){
    // delete VendingMachineState; // Delete previous state to prevent memory leak
    this->VendingMachineState = VendingMachineState;
}

void VendingMachine::addCoin(Coin coin){
    coins.emplace_back(coin);
}