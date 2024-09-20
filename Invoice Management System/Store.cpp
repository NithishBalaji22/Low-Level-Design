#include "Store.hpp"

Store* Store::instance = nullptr;

Store* Store::getInstance(){
    if(instance == nullptr){
        instance = new Store();
    }
    return instance;
}

void Store::registerCustomer(Customer* customer){
    customers[customer->getId()] = customer;
}

void Store::addItem(Item* item){
    items[item->getName()] = item;
}

void Store::addSales(Sales* sale){
    sales[sale->getId()] = sale;
}


void Store::makePurchase(Customer* customer, string itemName, int quantity){
    Item* item = items[itemName];
    if(item != nullptr){
        if(item->getQuantity() < quantity){
            cout<<"Sorry we couldnt process your request for the quantity: "<<quantity<<'\n';
            return;
        }

        int amount = item->getSellingPrice() * quantity;
        bool payment = transaction(customer, amount);
        if(payment){
            Sales* sale = new Sales(customer, {item}, amount);
            sales.insert({sale->getId(), sale});
            item->decrementQuantity(quantity);
            item->incrementProfit(quantity);
            customer->addSales(sale);
            return;
        }

        cout<<"Insufficient Funds in your account"<<'\n';
    }
}

void Store::makeBulkPurchase(Customer* customer, vector<pair<Item*, int>> bulkPurchase) {
    int totalAmount= 0;
    vector<Item*> items;
    for(auto it : bulkPurchase){
        Item* item = it.first;
        int quantity = it.second;
        totalAmount += item->getSellingPrice() * quantity;
        items.emplace_back(item);
    }

    bool payment = transaction(customer, totalAmount);
    if(payment){
        Sales* sale = new Sales(customer, items, totalAmount); // Fixed the constructor call
        sales.insert({sale->getId(), sale});
        for(auto it : bulkPurchase){
            Item* item = it.first;
            int quantity = it.second;
            item->decrementQuantity(quantity);
            item->incrementProfit(quantity); // Fixed profit calculation
        }
        customer->addSales(sale); // Moved outside the loop
    } else {
        cout<<"Insufficient Funds in your account"<<'\n';    
    }
}


void Store::salesOverview(){
    for(auto it : sales){
        cout<<"Sales "<<it.first<<" has been purchased by the customer: "<<it.second->getCustomer()->getName()<<" for the amount of: "<<it.second->getAmountPaid()<<'\n';
        cout<<"List of product customer bought: "<<'\n';
        Sales* sale = it.second;
        for(auto it : sale->getItemPurchased()){
            cout<<"Item name: "<<it->getName()<<'\n';
        }
    }
}

bool Store::transaction(Customer* customer, int amount){
    int balance = customer->getBalance();
    if(balance - amount >= 0){
        customer->debitBalance(amount);
        return true;
    }
    return false;
}

void Store::displayItems(){
    for(auto it : items){
        cout<<it.first<<'\n';
    }
}
