#include<bits/stdc++.h>
using namespace std;

#include"OnlineFoodDeliverySystem.hpp"
#include"Customer.hpp"
#include"DeliveryAgent.hpp"
#include"MenuItem.hpp"
#include"Order.hpp"
#include"OrderItem.hpp"
#include"Restaurant.hpp"

int main(){
    OnlineFoodDeliverySystem* foodDeliverySystem = OnlineFoodDeliverySystem::getInstance();
    Customer* customer1 = new Customer("1", "Nithish", "xxxxxxxx@gamil.com", "6516156");
    Customer* customer2 = new Customer("2", "Balaji", "nithishbal2@gmail.com", "6152895");

    foodDeliverySystem->registerCustomers(customer1->getCustomerId(), customer1);
    foodDeliverySystem->registerCustomers(customer2->getCustomerId(), customer2);

    Restaurant* restaurant1 = new Restaurant("1", "Amman", "Madurai", unordered_map<string, MenuItem*>());
    Restaurant* restaurant2 = new Restaurant("2", "Sabareesh", "TheppaKualam", unordered_map<string, MenuItem*>());

    foodDeliverySystem->registerRestaurants(restaurant1->getRestaurantId(), restaurant1);
    foodDeliverySystem->registerRestaurants(restaurant2->getRestaurantId(), restaurant2);

    DeliveryAgent* agent1 = new DeliveryAgent("1", "Sri Ganesh", "sriganesh@gamil.com", "1234569870", true);
    DeliveryAgent* agent2 = new DeliveryAgent("2", "Mani", "mani.768@gamil.com", "9705612", true);

    foodDeliverySystem->registerDeliveryAgents(agent1->getDeliveryAgentId(), agent1);
    foodDeliverySystem->registerDeliveryAgents(agent2->getDeliveryAgentId(), agent2);

    MenuItem* item1 = new MenuItem("1", "Dosa", "Its a soft dough and rich in carbohydrates", 59.99, true);
    MenuItem* item2 = new MenuItem("2", "Pongal", "Comforting early morning breakfast with rich in protein and carbohydrate", 69.99, true);

    restaurant1->addMenuItem(item1->getMenuItemId(), item1);
    restaurant1->addMenuItem(item2->getMenuItemId(), item2);

    MenuItem* item3 = new MenuItem("3", "Poori", "Its a soft dough and rich in carbohydrates", 49.99, true);
    MenuItem* item4 = new MenuItem("4", "Idly", "Its a soft dough and low in calories", 39.99, true);

    restaurant2->addMenuItem(item3->getMenuItemId(), item3);
    restaurant2->addMenuItem(item4->getMenuItemId(), item4);

    vector<OrderItems*> items;
    //Error
    // items.emplace_back(restaurant1->getMenuItems().at(0), 2);
    // items.emplace_back(restaurant1->getMenuItems().at(1), 1);

    // items.emplace_back(new OrderItems(restaurant1->getMenuItems().at(0), 2));
    // items.emplace_back(new OrderItems(restaurant1->getMenuItems().at(1), 1));

    auto menuItems = restaurant1->getMenuItems();
    items.emplace_back(new OrderItems(menuItems[0], 2)); // Assuming you want the first item in the menu
    items.emplace_back(new OrderItems(menuItems[1], 1)); // Similarly, the second item

    Order* order = foodDeliverySystem->placeOrder(customer1->getCustomerId(), restaurant1->getRestaurantId(), items);
    foodDeliverySystem->updateOrderStatus(order->getOrderId(), OrderStatus::CONFIRMED);
    cout<<"Order status updated: " <<order->getOrderStatus();    
}
