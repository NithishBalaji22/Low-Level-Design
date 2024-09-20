#include "Customer.hpp"

int Customer::customerCounter = 1;

void Customer::addToTotalPurchaseCost(int amount){
    totalPurchaseCost += amount;
}

void Customer::creditBalance(int amount){
    balance += amount;
}

void Customer::debitBalance(int amount){
    balance -= amount;
}

int Customer::getBalance(){
    return balance;
}

string Customer::getName(){
    return name;
}

int Customer::getId(){
    return id;
}

int Customer::getTotalPurchaseCost(){
    return totalPurchaseCost;
}

vector<Sales *> Customer::getPurchases(){
    return purchases;
}

void Customer::addSales(Sales *sale){
    purchases.emplace_back(sale);
}