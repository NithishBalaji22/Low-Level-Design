#pragma once
#include <iostream>
#include "States.hpp"
#include "Coin.hpp"
using namespace std;

class VendingMachine;
class HasMoneyState : public State{
private:
    VendingMachine* vendingMachine;
public:
    HasMoneyState(VendingMachine* vendingMachine);
    void clickOnCoinInsertButton();
    void insertCoin(Coin coin);
    void clickOnProductSelectButton();
    void selectProduct(int productId);
    void getChange(int extraAmount);
    vector<Coin> refundFullAmount();
    void dispenseProduct();
};
