#pragma once
#include <iostream>
#include <vector>
#include "Coin.hpp"

class State{
public:
    virtual void clickOnCoinInsertButton() = 0;
    virtual void insertCoin(Coin coin) = 0;
    virtual void clickOnProductSelectButton() = 0;
    virtual void selectProduct(int productId) = 0;
    virtual void getChange(int extraAmount) = 0;
    virtual vector<Coin> refundFullAmount() = 0;
    virtual void dispenseProduct() = 0;
};
