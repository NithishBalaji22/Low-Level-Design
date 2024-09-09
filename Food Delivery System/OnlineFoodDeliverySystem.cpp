#include "OnlineFoodDeliverySystem.hpp"

OnlineFoodDeliverySystem* OnlineFoodDeliverySystem::instance = nullptr;

OnlineFoodDeliverySystem* OnlineFoodDeliverySystem::getInstance(){
    //Singleton Design Pattern 
    if(instance == nullptr){
        instance = new OnlineFoodDeliverySystem();
    }
    return instance;
}

void OnlineFoodDeliverySystem::registerCustomers(string customerId, Customer* customer){
    customers[customerId] = customer;
}

void OnlineFoodDeliverySystem::registerRestaurants(string restaurantId, Restaurant* restaurant){
    restaurants[restaurantId] = restaurant;
}

void OnlineFoodDeliverySystem::registerDeliveryAgents(string agentId, DeliveryAgent* agent){
    deliveryAgents[agentId] = agent;
}

void OnlineFoodDeliverySystem::addOrders(string orderId, Order* order){
    orders[orderId] = order;
}

vector<Restaurant*> OnlineFoodDeliverySystem::getAvailableRestaurants(){
    vector<Restaurant*>v;
    for(auto it : restaurants){
        v.emplace_back(it.second);
    }
    return v;
}

vector<MenuItem*> OnlineFoodDeliverySystem::getRestaurantMenu(string restaurantId){
    //Error
    // Restaurant* restaurant = restaurants[restaurantId];
    // return restaurant->getMenuItems();
    
    //Follow this type of code
    if(restaurants.find(restaurantId) != restaurants.end()){
        Restaurant* restaurant = restaurants[restaurantId];
        return restaurant->getMenuItems();
    }
    cout << "Restaurant with ID " << restaurantId << " not found." << endl;
    return vector<MenuItem*>();  // Return an empty vector if the restaurant is not found
}


// Order* OnlineFoodDeliverySystem::placeOrder(string customerId, string restaurantId, vector<OrderItems*> items){
//     Restaurant* restaurant = restaurants[restaurantId];
//     Customer* customer = customers[customerId];

//     if(restaurant != nullptr && customer != nullptr){
//         Order* order = new Order(generateOrderId(customer), customer, restaurant);
//         for(OrderItems* item : items){
//             order->addItem(item->getItem()->getItemName(),item);
//         }
//         orders.insert({order->getOrderId(), order});
//         cout<<"Order has been placed! and your orderId is: "<<order->getOrderId()<<" "<<"Thanks for ordering with us!"<<'\n';
//         return order;
//     }
//     return nullptr;
// }

Order* OnlineFoodDeliverySystem::placeOrder(string customerId, string restaurantId, vector<OrderItems*> items){
    if(restaurants.find(restaurantId) != restaurants.end() && customers.find(customerId) != customers.end()){
        Restaurant* restaurant = restaurants[restaurantId];
        Customer* customer = customers[customerId];

        Order* order = new Order(generateOrderId(customer), customer, restaurant);
        for(OrderItems* item : items){
            order->addItem(item->getItem()->getItemName(), item);
        }
        orders.insert({order->getOrderId(), order});
        cout << "Order has been placed! and your orderId is: " << order->getOrderId() << " Thanks for ordering with us!" << '\n';
        return order;
    } else {
        cout << "Invalid customer or restaurant ID." << endl;
        return nullptr;
    }
}


vector<DeliveryAgent*> OnlineFoodDeliverySystem:: getDeliveryAgents(){
    vector<DeliveryAgent*>v;
    for(auto it : deliveryAgents){
        v.emplace_back(it.second);
    }
    return v;
}

void OnlineFoodDeliverySystem::cancelOrder(string orderId){
    Order* order = orders[orderId];
    if(order != nullptr && order->getOrderStatus() == OrderStatus::PENDING){
        order->setOrderStatus(OrderStatus::CANCELLED);
        cout<<"Order has been cancelled and your orderId is: "<<order->getOrderId()<<'\n';
        return;
    }

    cout<<"Such orderId is not in our database sorry!"<<'\n';
}

void OnlineFoodDeliverySystem::assignAgent(Order* order){
    for(DeliveryAgent* agent : getDeliveryAgents()){
        if(agent->getDeliveryAgentAvailability()){
            agent->setDeliveryAgentAvailability(false);
            order->assignDeliveryAgent(agent);
            break;
        }
    }
}

// void OnlineFoodDeliverySystem::updateOrderStatus(string orderId, OrderStatus status){
//     Order* order = orders[orderId];
//     if(order != nullptr){
//         order->setOrderStatus(status);
//         return;
//     }
// }

void OnlineFoodDeliverySystem::updateOrderStatus(string orderId, OrderStatus status){
    if(orders.find(orderId) != orders.end()){
        Order* order = orders[orderId];
        order->setOrderStatus(status);
    } else {
        cout << "Order with ID " << orderId << " not found." << endl;
    }
}

string OnlineFoodDeliverySystem::generateOrderId(Customer* customer){
    return ORDER_ID_PREFIX + customer->getCustomerId() + customer->getlast4letters();
}
