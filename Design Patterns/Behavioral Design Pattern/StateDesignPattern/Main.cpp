#include<iostream>
#include "Coin.hpp"
#include "Inventory.hpp"
#include"Product.hpp"
#include "VendingMachine.hpp"
#include"States.hpp"
using namespace std;

int main(){
    VendingMachine* vendingMachine = new VendingMachine();
    Inventory* inventory = new Inventory();

    Product* pepsi = new Product(1, "Pepsi", 1, 5);
    Product* coke = new Product(2, "Coke", 1, 10);
    Product* soda = new Product(3, "Soda", 1, 20);

    inventory->addProduct(pepsi);
    inventory->addProduct(coke);
    inventory->addProduct(soda);

    vendingMachine->setInventory(inventory);

    State* vendingState = vendingMachine->getVendingMachineState();
    vendingState->clickOnCoinInsertButton();

    vendingState = vendingMachine->getVendingMachineState();
    vendingState->insertCoin(Coin::FIVE_RUPPEE);
    vendingState->insertCoin(Coin::TWENTY_RUPPEE);
    vendingState->clickOnProductSelectButton();

    vendingState = vendingMachine->getVendingMachineState();
    vendingState->selectProduct(3);
    
    vendingState = vendingMachine->getVendingMachineState();
    vendingState->dispenseProduct();
}