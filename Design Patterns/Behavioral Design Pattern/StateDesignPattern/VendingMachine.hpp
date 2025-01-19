#pragma once
#include <bits/stdc++.h>
#include "States.hpp"
#include "IdleState.hpp"
#include "HasMoneyState.hpp"
#include "ProductSelectState.hpp"
#include "DispenseProductState.hpp"
#include "Inventory.hpp"
#include "Product.hpp"
#include "Coin.hpp"
using namespace std;

class State;
class VendingMachine{
private:
    int productId;
    State *VendingMachineState;
    Inventory *inventory;
    vector<Coin> coins;
    State *idleState;
    State *hasMoneyState;
    State *productSelect;
    State *dispenseproduct;

public:
    VendingMachine(){
        inventory = new Inventory();
        idleState = new IdleState(this);
        hasMoneyState = new HasMoneyState(this);
        productSelect = new SelectProductState(this);
        dispenseproduct = new DispenseProductState(this);
        coins = vector<Coin>();
        VendingMachineState = idleState;
    }
    
    State* getVendingMachineState();
    State* getIdleState();
    State* getHasMoneyState();
    State* getSelectProductState();
    State* getDispenseProductState();
    void setProductId(int id);
    void setInventory(Inventory *inventory);
    Inventory* getInventory();
    vector<Coin> getCoins();
    void setSelectedProductId(int id);
    int getSelectedProductId();
    void setState(State *VendingMachineState);
    void addCoin(Coin coin);
};