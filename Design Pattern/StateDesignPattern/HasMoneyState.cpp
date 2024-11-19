#include "HasMoneyState.hpp"
#include "VendingMachine.hpp"

HasMoneyState::HasMoneyState(VendingMachine *vendingMachine){
    this->vendingMachine = vendingMachine;
    cout << "Vending Machine is in Has Money State" << endl;
}

void HasMoneyState::clickOnCoinInsertButton(){
    cout << "Coin insert button already clicked." << endl;
}

void HasMoneyState::insertCoin(Coin coin){
    vendingMachine->addCoin(coin);
}

void HasMoneyState::clickOnProductSelectButton(){
    vendingMachine->setState(vendingMachine->getSelectProductState());
}

void HasMoneyState::selectProduct(int productId){
    cout << "Please click the product select button first!" << endl;
}

void HasMoneyState::getChange(int extraAmount){
    cout << "Cannot get change in Has Money State." << endl;
}

vector<Coin> HasMoneyState::refundFullAmount(){
    vendingMachine->setState(vendingMachine->getIdleState());
    return vendingMachine->getCoins();
}

void HasMoneyState::dispenseProduct(){
    cout << "Cannot dispense product without selection." << endl;
}