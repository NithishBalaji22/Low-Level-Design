#include <iostream>
#include "OnlineFoodDeliverySystem.hpp"
#include "Customer.hpp"
#include "DeliveryAgent.hpp"
#include "MenuItem.hpp"
#include "Restaurant.hpp"

using namespace std;

int main() {
    // Create the Online Food Delivery System instance
    OnlineFoodDeliverySystem* system = OnlineFoodDeliverySystem::getInstance();

    // Create two Restaurants
    Restaurant* restaurant1 = new Restaurant(1, "Pizza Palace", 'A'); 
    Restaurant* restaurant2 = new Restaurant(2, "Burger Bistro", 'C'); 

    // Add food items to Restaurant 1
    restaurant1->addMenuItem(new MenuItem(1, "Pizza", 250));
    restaurant1->addMenuItem(new MenuItem(2, "Burger", 300));
    restaurant1->addMenuItem(new MenuItem(3, "BBQ", 350));
    restaurant1->addMenuItem(new MenuItem(4, "Dosa", 200));
    restaurant1->addMenuItem(new MenuItem(5, "Idly", 280));

    // Add food items to Restaurant 2
    restaurant2->addMenuItem(new MenuItem(6, "Classic Cheeseburger", 150));
    restaurant2->addMenuItem(new MenuItem(7, "Bacon Burger", 180));
    restaurant2->addMenuItem(new MenuItem(8, "Double Patty Burger", 220));
    restaurant2->addMenuItem(new MenuItem(9, "Vegan Burger", 170));
    restaurant2->addMenuItem(new MenuItem(10, "BBQ Burger", 200));

    // Register restaurants with the system
    system->registerRestaurant(restaurant1);
    system->registerRestaurant(restaurant2);

    //Creating Account
    Account* account = new Account(1, 1111, 2812, 10000);

    // Create a Customer
    Customer* customer = new Customer(1, "John Doe", "nithish@gmail.com", "password123", 'A', account); 
    system->registerUser(customer);

    // Create and register a Delivery Agent
    DeliveryAgent* sriGanesh = new DeliveryAgent(1, "Sri Ganesh", 'D'); // Location: 5
    DeliveryAgent* balaji = new DeliveryAgent(2, "Balaji", 'B');

    system->registerDeliveryAgent(balaji);
    system->registerDeliveryAgent(sriGanesh);

    // Simulate customer login and placing an order
    if (system->userLogin(customer)) {
        Order* order = system->placeOrder(customer, restaurant1);
        system->deliveredOrder(order);
        system->orderSummary(order);
    }else{
        return 0;
    }
}
