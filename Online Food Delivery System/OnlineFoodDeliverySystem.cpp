#include "OnlineFoodDeliverySystem.hpp"

// Initialize static members
OnlineFoodDeliverySystem* OnlineFoodDeliverySystem::instance = nullptr;
int OnlineFoodDeliverySystem::orderId;
int OnlineFoodDeliverySystem::transactionId;

OnlineFoodDeliverySystem* OnlineFoodDeliverySystem::getInstance() {
    if (instance == nullptr) {
        instance = new OnlineFoodDeliverySystem();
    }
    return instance;
}

void OnlineFoodDeliverySystem::registerUser(Customer* user) {
    customerMaps.insert({user->getMailId(), user});
}

void OnlineFoodDeliverySystem::registerRestaurant(Restaurant* restaurant) {
    restaurentMaps.insert({restaurant->getRestaurantName(), restaurant});
}

void OnlineFoodDeliverySystem::registerDeliveryAgent(DeliveryAgent* agent) {
    agents.emplace_back(agent);
    agentMaps.insert({agent->getName(), agent});
}

void OnlineFoodDeliverySystem::addOrder(Order* order) {
    ordersMap.insert({order->getOrderId(), order});
}

bool OnlineFoodDeliverySystem::userLogin(Customer* user) {
    string mailId, password;
    cout << "Enter your mailId: ";
    cin >> mailId;
    cout << "Enter your password: ";
    cin >> password;

    if (user->getMailId() == mailId && user->getPassword() == password) {
        return true;
    } 
    cout << "Invalid Credentials!!\n";
    return false;
}

Order* OnlineFoodDeliverySystem::placeOrder(Customer* user, Restaurant* restaurant) {
    vector<MenuItem*> items = restaurant->getMenu();
    cout << "-------- Available Food Items --------" << endl;
    for (auto food : items) {
        cout << food->getName() << endl;
    }

    int noOfFood;
    cout << "\nSelect No of Food Item you wish to order: ";
    cin >> noOfFood;

    int amount = 0;
    vector<OrderItem*> userOrder;

    // Clear the newline character left in the input buffer
    cin.ignore();

    for (int i = 0; i < noOfFood; i++) {
        int quantity;
        string foodName;

        cout << "Enter the Food Name: ";
        getline(cin, foodName);  // Use getline to capture full food name
        cout << "Enter the Quantity: ";
        cin >> quantity;
        cout << endl;

        // Clear the newline character again after reading quantity
        cin.ignore();

        MenuItem* item = restaurant->getMenuItem(foodName);
        OrderItem* orderItem = new OrderItem(item, quantity);
        amount += item->getAmount() * quantity;
        userOrder.emplace_back(orderItem);
    }

    DeliveryAgent* deliveryAgent = nullptr;
    int minDistance = INT_MAX;
    for (auto agent : agents) {
        if (abs(restaurant->getRestaurantLocation() - agent->getLocation()) <= minDistance && agent->getAvailability()) {
            deliveryAgent = agent;
            minDistance = abs(restaurant->getRestaurantLocation() - agent->getLocation());
        }
    }

    if (deliveryAgent != nullptr) {
        int orderId = generateOrderId();
        Order* order = new Order(orderId, user, restaurant, deliveryAgent, userOrder, amount);

        cout<<"------ Logging into your Bank Account ------"<<endl;
        int accNo, pin;
        cout<<"Enter your Account No: ";
        cin>>accNo;
        cout<<"Enter Pin: ";
        cin>>pin;

        Account* account = user->getAccount();
        if(account->getAccNo() == accNo && account->getPin() == pin){
            int userBalance = account->getBalance();

            if (userBalance < amount) {
                cout << "Insufficient Funds!!\n";
                delete order; // Free memory if the order cannot be processed
                return nullptr;
            }

            int transactionId = generateTransactionId();
            Transaction* transaction = new Debit(transactionId, user->getAccount(), amount);
            transaction->execute();
            cout<<"Order has been placed successfully!!!\n";

            ordersMap.insert({orderId, order});
            deliveryAgent->unavailable();
            user->addOrder(order);
            user->addOrderAmount(amount);
            return order;

        }else{
            cout<<"Invalid Credentials!!!\n";
        }
    }else{
        cout << "No available delivery agents at the moment.\n";
    }        
    return nullptr;
}


void OnlineFoodDeliverySystem::deliveredOrder(Order* order) {
    cout<<"\nOrder has been delivered\n";
    DeliveryAgent* agent = order->getAgent();
    agent->available();
    agent->setLocation(order->getUser()->getLocation());
    order->delivered();
}

void OnlineFoodDeliverySystem::orderSummary(Order* order){
    cout<<"\n------ Order Summary ------\n"<<endl;
    cout<<"Restaurant Name: "<<order->getRestaurant()->getRestaurantName()<<endl;
    cout<<"Delivered By: "<<order->getAgent()->getName()<<endl;
    vector<OrderItem*> orderItem = order->getOrderItem();
    for(auto food : orderItem){
        cout<<"Food: "<<food->getItem()->getName()<<" Quantity: "<<food->getQuantity()<<" Cost: "<<(food->getItem()->getAmount() * food->getQuantity())<<endl;
    }
    cout<<"Total Amount: "<<order->getAmount();
}

int OnlineFoodDeliverySystem::generateOrderId() {
    return orderId++;
}

int OnlineFoodDeliverySystem::generateTransactionId() {
    return transactionId++;
}