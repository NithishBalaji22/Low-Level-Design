#pragma once
#include <iostream>
#include "Coin.hpp"
#include "States.hpp"
using namespace std;

class VendingMachine;
class DispenseProductState : public State{
private:
    VendingMachine* vendingMachine;
public:
    DispenseProductState(VendingMachine* vendingMachine);
    void clickOnCoinInsertButton();
    void insertCoin(Coin coin);
    void clickOnProductSelectButton();
    void selectProduct(int productId);
    void getChange(int extraAmount);
    vector<Coin> refundFullAmount();
    void dispenseProduct();
};