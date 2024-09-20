#include "Item.hpp"

int Item::itemCounter = 1;

int Item::getId(){
    return id;
}

string Item::getName(){
    return name;
}

int Item::getSellingPrice(){
    return sp;
}

int Item::getCostPrice(){
    return cp;
}

int Item::getNetProfit(){
    return netProfit;
}

int Item::getQuantity(){
    return itemQuantity;
}

void Item::decrementQuantity(int quantity){
    itemQuantity -= quantity;
}

void Item::incrementQuantity(int quantity){
    itemQuantity += quantity;
}

void Item::setSellingPrice(int price){
    sp = price;
}

void Item::setCostProce(int price){
    cp = price;
}

void Item::incrementProfit(int quantity){
    netProfit += (sp - cp) * quantity;
}