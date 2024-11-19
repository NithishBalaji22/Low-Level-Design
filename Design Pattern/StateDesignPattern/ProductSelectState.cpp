#include "VendingMachine.hpp"
#include "ProductSelectState.hpp"

SelectProductState::SelectProductState(VendingMachine *vendingMachine){
    this->vendingMachine = vendingMachine;
    cout << "Vending Machine is in Select Product State" << endl;
}

void SelectProductState::clickOnCoinInsertButton(){
    cout << "Coin insert button already clicked." << endl;
}

void SelectProductState::insertCoin(Coin coin){
    cout << "Coin already inserted." << endl;
}

void SelectProductState::clickOnProductSelectButton(){
    cout << "Product select button already clicked." << endl;
}

void SelectProductState::selectProduct(int productId){
    int paidByUser = 0;
    for (auto coin : vendingMachine->getCoins()){
        paidByUser += static_cast<int>(coin);
    }

    vendingMachine->setProductId(productId);
    int productCost = 0;
    Inventory *inventory = vendingMachine->getInventory();
    if (inventory->isProductAvailable(productId)){
        productCost += inventory->getProductCost(productId);
    }

    int extraAmount = paidByUser - productCost;

    if(paidByUser < productCost){
        vendingMachine->setState(vendingMachine->getIdleState());
        refundFullAmount();
        return;
    }else if(paidByUser >= productCost){
        if (paidByUser > productCost){
            getChange(paidByUser - productCost);
            vendingMachine->setState(vendingMachine->getDispenseProductState());
        }
    }
}

void SelectProductState::getChange(int extraAmount){
    cout << "Kindly Collect your cash: " << extraAmount << endl;
}

vector<Coin> SelectProductState::refundFullAmount(){
    vendingMachine->setState(vendingMachine->getIdleState());
    return vendingMachine->getCoins();
}

void SelectProductState::dispenseProduct(){
    cout << "Product cannot be dispensed in the select product state!" << endl;
}