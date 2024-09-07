#include<bits/stdc++.h>
using namespace std;

#include"Order.hpp"
#include "OrderItems.hpp"
#include "Product.hpp"
#include"ShoppingCart.hpp"
#include "User.hpp"
#include"OnlineShoppingService.hpp"

int main(){
    OnlineShoppingService* zohoShoppingService = OnlineShoppingService::getInstance();

    User* user1 = new User("1", "Nithish", "digitalnithish2003@gamil.com", "8754685518", "xxxx");
    User* user2 = new User("2", "Balaji", "nithishbalaji2812@gamil.com", "8754685519", "yyyy");

    zohoShoppingService->registerUser(user1);
    zohoShoppingService->registerUser(user2);

    Product* product1 = new Product("P001", "Smartphone", "High-end smartphone", 999.99, 10);
    Product* product2 = new Product("P002", "Laptop", "Powerful gaming laptop", 1999.99, 5);

    zohoShoppingService->addProduct(product1);
    zohoShoppingService->addProduct(product2);

    ShoppingCart* cart1 = new ShoppingCart();
    cart1->addToCart(product1, 5);
    cart1->addToCart(product2, 2);

    Order* order1 = zohoShoppingService->placeOrder(user1, cart1);
    if(order1 != nullptr){
        cout<<"Order has been placed successively and your OrderId is: "<<order1->getOrderId()<<'\n';
    }else{
        cout<<"Due to some technical glitch we couldnt proceed with your order sorry for your incovinience :)"<<'\n';
    }
}