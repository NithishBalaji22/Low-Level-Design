#include "DispenseProductState.hpp"
#include "VendingMachine.hpp"
#include "Product.hpp"

DispenseProductState::DispenseProductState(VendingMachine *vendingMachine)
{
    this->vendingMachine = vendingMachine;
    cout << "Vending Machine is in Dispense Product State" << endl;
}

void DispenseProductState::clickOnCoinInsertButton(){
    cout << "Coin already inserted." << endl;
}

void DispenseProductState::insertCoin(Coin coin){
    cout << "Coin already inserted." << endl;
}

void DispenseProductState::clickOnProductSelectButton(){
    cout << "Product already selected." << endl;
}

void DispenseProductState::selectProduct(int productId){
    cout << "Product already selected." << endl;
}

void DispenseProductState::getChange(int extraAmount){
    cout << "Change cannot be returned in the dispense state" << endl;
}

vector<Coin> DispenseProductState::refundFullAmount(){
    cout << "You cannot cancel in the dispense state" << endl;
    return {};
}

void DispenseProductState::dispenseProduct(){
    int productId = vendingMachine->getSelectedProductId();
    Product* product = vendingMachine->getInventory()->getProduct(productId);
    if(product == nullptr) cout<<"Hello"<<endl;
    cout << "Dispensing Product: " << product->getProductName() << endl;
    vendingMachine->getInventory()->decreseProductQuantity(productId, 1);
    vendingMachine->setState(vendingMachine->getIdleState());
}