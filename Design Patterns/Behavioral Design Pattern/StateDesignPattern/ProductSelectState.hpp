#pragma once
#include <iostream>
#include "States.hpp"
#include "Coin.hpp"
using namespace std;

class VendingState;
class SelectProductState : public State{
private:
    VendingMachine* vendingMachine;
public:
    SelectProductState(VendingMachine* vendingMachine);
    void clickOnCoinInsertButton();
    void insertCoin(Coin coin);
    void clickOnProductSelectButton();
    void selectProduct(int productId);
    void getChange(int extraAmount);
    vector<Coin> refundFullAmount();
    void dispenseProduct();
};