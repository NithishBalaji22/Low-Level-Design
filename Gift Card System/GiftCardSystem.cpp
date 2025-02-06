#include "GiftCardSystem.hpp"

GiftCardSystem* GiftCardSystem::instance = nullptr;
GiftCardSystem* GiftCardSystem::getInstance(){
    if(instance == nullptr){
        instance = new GiftCardSystem();
    }
    return instance;
}

void GiftCardSystem::initializeAccountAndCustomer(){
    Account* c1 = new Account(1, 10000);
    Account* c2 = new Account(2, 20000);
    Account* c3 = new Account(3, 30000);

    Customer* cust1 = new Customer(1, c1);
    Customer* cust2 = new Customer(2, c2);
    Customer* cust3 = new Customer(3, c3);

    accountsMap[1] = c1;
    accountsMap[2] = c2;
    accountsMap[3] = c3;

    customerMap[1] = cust1;
    customerMap[2] = cust2;
    customerMap[3] = cust3;
}

void GiftCardSystem::accountSummary(){
    cout<<"CustomerID\tBalance"<<endl;
    for(auto account : accountsMap){
        Account* acc = account.second;
        cout<<acc->getCustomerID()<<"\t\t"<<acc->getBalance()<<endl;
    }
}

void GiftCardSystem::giftCardSummary(){
    cout<<"CardNo\tCust ID\tPIN\tGiftCard Balance\tStatus"<<endl;
    for(auto card : giftCardMap){
        GiftCard* giftCard = card.second;
        bool status = giftCard->getGiftCardCloseStatus();
        string s = (!status) ? "Active" : "Closed";
        cout<<giftCard->getGiftCardNo()<<'\t'<<giftCard->getCustID()<<'\t'<<giftCard->getPin()<<'\t'<<giftCard->getGiftCardBalance()<<"\t\t"<<s<<endl;
    }
}

void GiftCardSystem::purchaseTransactionSummary(){
    cout<<"Txn No\tCard No\tAmount"<<endl;
    for(auto purchase : purchaseTransactionSummaryMap){
        PurchaseTransactionSummary* p = purchase.second;
        cout<<p->getTransactionNo()<<'\t'<<p->getCardNo()<<'\t'<<p->getAmount()<<endl;
    }
}

void GiftCardSystem::createCustomer(){
    int custID = generateCustomerID();
    int balance;
    cout<<"Enter the deposit Amount: ";
    cin>>balance;

    if(balance <= 0){
        cout<<"Deposit Amount cannot be in negative"<<endl;
        return;
    }
    
    Account* account = new Account(custID, balance);
    Customer* customer = new Customer(custID, account);

    accountsMap[account->getCustomerID()] = account;
    customerMap[customer->getCustomerID()] = customer;

    cout<<"Customer Account has been created!!"<<endl;
}

void GiftCardSystem::createGiftCard(){
    int custAccNo;
    cout<<"Enter your Customer Account No: ";
    cin>>custAccNo;

    if(customerMap.find(custAccNo) != customerMap.end()){
        Customer* customer = customerMap.at(custAccNo);
        Account* account = customer->getCustomerAccount();

        if(account->getBalance() < giftCardAmount){
            cout<<"Insufficient Balance!!"<<endl;
            return;
        }

        Transaction* giftCardPurchase = new Debit(account, giftCardAmount);
        giftCardPurchase->execute();
        int pin;
        cout<<"Set Pin for your Gift Card: ";
        cin>>pin;

        if(pin < 0){
            cout<<"Pin cannot be negative !!"<<endl;
            return;
        }

        GiftCard* giftCard = new GiftCard(generateGiftCardNo(), custAccNo, pin, giftCardAmount);
        customer->addGiftCard(giftCard);
        giftCardMap[giftCard->getGiftCardNo()] = giftCard;
        cout<<"Gift Card has been created successfully!!"<<endl;
        giftCardSummary();
    }else{
        cout<<"We couldnt find your account number!!"<<endl;
    }
}

void GiftCardSystem::topUpGiftCard(){
    int custAccNo;
    cout<<"Enter your Customer Account No: ";
    cin>>custAccNo;

    if(customerMap.find(custAccNo) != customerMap.end()){
        Customer* customer = customerMap.at(custAccNo);
        Account* account = customer->getCustomerAccount();
        bool hasGiftCard = customer->doesCustomerHasGiftCard();

        if(hasGiftCard == false){
            cout<<"You dont have giftcard so you cannot proceed!!"<<endl;
            return;
        }

        int cardNo;
        cout<<"Enter the giftCard Number for which you want to topUp: ";
        cin>>cardNo;

        if(cardNo < 0){
            cout<<"Card number cannot be in negative"<<endl;
            return;
        }

        GiftCard* giftCard = customer->getGiftCard(cardNo);

        if(giftCard->getGiftCardCloseStatus()){
            cout<<"Gift Card has been closed you cannot proceed furture!!"<<endl;
            return;
        }
        if(giftCard != nullptr){
            int amount;
            cout<<"Enter the amount for the topUp: ";
            cin>>amount;

            if(amount < 0){
                cout<<"Amount cannot be in negative"<<endl;
                return;
            }

            if(account->getBalance() < amount){
                cout<<"Insufficient Funds!!"<<endl;
                return;
            }

            Transaction* topUp = new Debit(account, amount);
            topUp->execute();

            giftCard->topUp(amount);      
            cout<<"Your gift card has been topupped for amount "<<amount<<endl; 
            giftCardSummary();               
        }else{
            cout<<"We couldnt find the giftCard that belongs to you !!"<<endl;
        }
    }else{
        cout<<"We couldnt find your account number!!"<<endl;
    }
}

void GiftCardSystem::closeGiftCard(){
    int custAccNo;
    cout<<"Enter your Customer Account No: ";
    cin>>custAccNo;

    if(customerMap.find(custAccNo) != customerMap.end()){
        Customer* customer = customerMap.at(custAccNo);
        Account* account = customer->getCustomerAccount();
        bool hasGiftCard = customer->doesCustomerHasGiftCard();

        if(hasGiftCard == false){
            cout<<"You dont have giftcard so you cannot proceed!!"<<endl;
            return;
        }

        int cardNo;
        cout<<"Enter the giftCard Number for which you want to close: ";
        cin>>cardNo;

        if(cardNo < 0){
            cout<<"Card number cannot be in negative"<<endl;
            return;
        }

        GiftCard* giftCard = customer->getGiftCard(cardNo);

        if(giftCard != nullptr){
            int giftcardAmount = giftCard->getGiftCardBalance();
            Transaction* accCredit = new Credit(account, giftcardAmount);
            accCredit->execute();
            giftCard->closeGiftCard();
            cout<<"Gift Card has been closed successfully!!"<<endl;
            giftCardSummary();
        }else{
            cout<<"Either Gift Card has been blocked or closed else there isnt a giftcard no associated with the customer!!"<<endl;
        }
    }else{
        cout<<"We couldnt find the customer!!"<<endl;
    }
}

void GiftCardSystem::purchaseItem(){
    int custAccNo;
    cout<<"Enter your Customer Account No: ";
    cin>>custAccNo;        

    if(customerMap.find(custAccNo) != customerMap.end()){
        Customer* customer = customerMap.at(custAccNo);
        Account* account = customer->getCustomerAccount();
        bool hasGiftCard = customer->doesCustomerHasGiftCard();

        if(hasGiftCard == false){
            cout<<"You dont have giftcard so you cannot proceed!!"<<endl;
            return;
        }

        int cardNo;
        cout<<"Enter the giftCard Number for which you want to close: ";
        cin>>cardNo;

        if(cardNo < 0){
            cout<<"Card number cannot be in negative"<<endl;
            return;
        }

        GiftCard* giftCard = customer->getGiftCard(cardNo);
        if(giftCard != nullptr){
            int amount;
            cout<<"Enter Purchase Amount: ";
            cin>>amount;

            if(amount < 0){
                cout<<"Amount cannot be negative"<<endl;
                return;
            }

            if(giftCard->getGiftCardBalance() < amount){
                cout<<"Gift Card Balance is low you cannot proceed furture!!"<<endl;
                return;
            }

            giftCard->purchase(amount);
            PurchaseTransactionSummary* purchase = new PurchaseTransactionSummary(generateTransactionID(), giftCard->getGiftCardNo(), amount);
            purchaseTransactionSummaryMap[purchase->getTransactionNo()] = purchase;
            cout<<"Purchase has been made successfully!!"<<endl;
            purchaseTransactionSummary();
        }else{
            cout<<"Either Gift Card has been blocked or closed else there isnt a giftcard no associated with the customer!!"<<endl;
        }
    }else{
        cout<<"We couldnt find your account number!!"<<endl;
    }
}

int GiftCardSystem::generateGiftCardNo(){
    return giftCardNo++;
}

int GiftCardSystem::generateCustomerID(){
    return customerID++;
}

int GiftCardSystem::generateTransactionID(){
    return transactionID++;
}