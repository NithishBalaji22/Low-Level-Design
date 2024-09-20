#include "Sales.hpp"

int Sales::saleCounter = 1;

int Sales::getId(){
    return id;
}

int Sales::getAmountPaid(){
    return amountPaid;
}

Customer* Sales::getCustomer(){
    return customer;
}

vector<Item *> Sales::getItemPurchased(){
    return itemsPurchased;
}

void Sales::addToItemPurchased(Item *item){
    itemsPurchased.emplace_back(item);
}