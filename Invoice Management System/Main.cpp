#include"Store.hpp"
#include"Customer.hpp"
#include"Item.hpp"
#include"Sales.hpp"
#include<iostream>
using namespace std;

int main(){
    Store* store = Store::getInstance();
    
    //Creating Customers
    Customer* cus1 = new Customer("Nithish", 10000);
    Customer* cus2 = new Customer("Sri Ganesh", 5000);

    //Registering Customers
    store->registerCustomer(cus1);
    store->registerCustomer(cus2);

    //Creating Items
    Item* item1 = new Item("Maggie", 14, 7, 5);
    Item* item2 = new Item("Lays", 10, 4, 10);

    //Lets add them to the store
    store->addItem(item1);
    store->addItem(item2);

    store->displayItems();
    store->makePurchase(cus1, "Maggie", 2);

    //After making Purchase lets see certain things
    // Lets see the sales that has been taken place
    store->salesOverview();
}