#include "IdleState.hpp"
#include "VendingMachine.hpp"

IdleState::IdleState(VendingMachine *vendingMachine){
    this->vendingMachine = vendingMachine;
    cout << "Vending Machine is in Idle State" << endl;
}

void IdleState::clickOnCoinInsertButton(){
    vendingMachine->setState(vendingMachine->getHasMoneyState());
}

void IdleState::insertCoin(Coin coin){
    cout << "Please click the coin insert button first!" << endl;
}

void IdleState::clickOnProductSelectButton(){
    cout << "Please click the coin insert button first!" << endl;
}

void IdleState::selectProduct(int productId){
    cout << "Please click the coin insert button first!" << endl;
}

void IdleState::getChange(int extraAmount){
    cout << "Please click the coin insert button first!" << endl;
}

vector<Coin> IdleState::refundFullAmount(){
    cout << "Please click the coin insert button first!" << endl;
    return {};
}

void IdleState::dispenseProduct(){
    cout << "Please click the coin insert button first!" << endl;
}