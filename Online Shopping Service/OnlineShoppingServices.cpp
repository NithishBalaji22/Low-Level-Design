#include "OnlineShoppingService.hpp"

OnlineShoppingService* OnlineShoppingService::instance= nullptr;

OnlineShoppingService* OnlineShoppingService::getInstance(){
    //Singleton Design Pattern
    if(instance == nullptr){
        instance = new OnlineShoppingService();
    }
    return instance;
}

void OnlineShoppingService::registerUser(User* user){
    users.insert({user->getUserId(),user});
}

void OnlineShoppingService::addProduct(Product* product){
    products.insert({product->getProductId(), product});
}

User* OnlineShoppingService::getUser(string userId){
    if(users.find(userId) != users.end()){
        return users[userId];
    }
    cout<<"The user you are looking for is not in our database sorry !"<<'\n';
    return nullptr;   
}

Product* OnlineShoppingService::getProduct(string productId){
    if(products.find(productId) != products.end()){
        return products[productId];
    }
    cout<<"Sorry the product you are looking for is not in our database !"<<'\n';
    return nullptr;    
}

Order* OnlineShoppingService::placeOrder(User* user, ShoppingCart* cart){
    vector<OrderItems*> orderItems;
    for(OrderItems* item : cart->getOrderItems()){
        Product* product = item->getProduct();
        int quantity = item->getQuantity();
        if(product->isAvailable(quantity)){
            product->decreaseQuantity(quantity);
            orderItems.emplace_back(item);
        }
    }

    // Implement if the orderItems.size()==0
    if (orderItems.empty()) {
        cout << "No items available for this order." << endl;
        return nullptr;
    }

    string orderId = generateOrderId(user);
    Order* order = new Order(orderId, user, orderItems);
    orders.insert({orderId, order});
    user->addItem(orderItems);
    cart->cartClear();

    return order;
}

Order* OnlineShoppingService::getOrder(string orderId){
    if(orders.find(orderId) != orders.end()){
        return orders[orderId];
    }

    cout<<"The order you are looking for is not in our database meaning that you havent order any products yet"<<'\n';
    return nullptr;
}

string OnlineShoppingService::generateOrderId(User* user){
    //ORD_NITHISH_5518
    return ORDER_ID_PREFIX + '_' + user->getUserName() + '_' + user->getUserLast4DigitPhoneNumber();
}