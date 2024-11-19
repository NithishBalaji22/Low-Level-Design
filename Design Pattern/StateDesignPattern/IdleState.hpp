#pragma once
#include <iostream>
#include "States.hpp"
#include "Coin.hpp"
using namespace std;

class VendingMachine;
class IdleState : public State{
private:
    VendingMachine* vendingMachine;
public:
    IdleState(VendingMachine* vendingMachine);
    void clickOnCoinInsertButton();
    void insertCoin(Coin coin);
    void clickOnProductSelectButton();
    void selectProduct(int productId);
    void getChange(int extraAmount);
    vector<Coin> refundFullAmount();
    void dispenseProduct();
};