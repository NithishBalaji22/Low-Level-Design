#include "TollPaymentProcessing.hpp"

TollPaymentProcessing *TollPaymentProcessing::instance = nullptr;
int TollPaymentProcessing::paymentId;
int TollPaymentProcessing::passId;

TollPaymentProcessing *TollPaymentProcessing::getInstance(){
    if (instance == nullptr){
        instance = new TollPaymentProcessing();
    }
    return instance;
}

void TollPaymentProcessing::registerToll(Toll* toll){
    tollMap.insert({toll->getLocation(), toll});
}

void TollPaymentProcessing::addUser(User* user){
    userMap.insert({user->getUserId(), user});
}

void TollPaymentProcessing::addCar(Car* car){
    carMap.insert({car->getNumberPlate(), car});
}

void TollPaymentProcessing::startJouney(Car* car){
    cout<<"------- Starting this Journey --------"<<endl;
    for(int i= car->getLocation() - 'A'; i <= car->getDestinationLocation() - 'A'; i++){
        this_thread::sleep_for(chrono::seconds(3));
        char tollLocation = static_cast<char> (i + 'A');
        if(tollMap.find(tollLocation) != tollMap.end()){
            reachedTollAndMakePayment(tollLocation, car);
        }else{
            cout<<"Reached Location: "<<tollLocation<<endl;
        }
        car->setLocation(tollLocation);
        if(i == car->getDestinationLocation() - 'A'){
            cout<<"\nCompleted the Journey and heres the summary of your Journey !!!"<<endl;
            this_thread::sleep_for(chrono::seconds(2));
            journeyOverView(car);
            return;
        }
    }
}

void TollPaymentProcessing::reachedTollAndMakePayment(char tollLocation, Car* car){
    cout<<"Reached Toll: "<<tollLocation<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    User* user = car->getUser();
    UserCategory category = user->getCategory();
    Account* account = user->getAccount();
    CarType type = car->getCarType();
    Toll* toll = tollMap[tollLocation];
    int baseCharge = toll->getBaseCharge();
    int amount = baseCharge;

    if(type == CarType::NORMAL_CAR) amount += 1000;
    else if(type == CarType::SPORTS_CAR) amount += 2500;
    else amount += 5000;

    if(category == UserCategory::VIP){
        int discountAmount = amount * 0.20;
        cout<<"\n20 Percent Discount is Applicable"<<endl;
        cout<<"Actual Fair: "<<amount<<endl;
        amount -= discountAmount;
        cout<<"With Discount: "<< amount<<endl;
    }else{
        cout<<"Amount: "<<amount<<endl;
    }

    cout<<"\n-------- Processing Payment --------"<<endl;
    int accNo, pin;

    cout<<"Enter Account No: ";
    cin>>accNo;

    cout<<"Enter Pin: ";
    cin>>pin;

    if(account->getAccountNo() == accNo && account->getPin() == pin){
        if(account->getBalance() < amount){
            cout<<"Insufficient Funds !!!"<<endl;
            exit(0);
        }

        cout<<"This could take you couple of seconds!!"<<endl;
        this_thread::sleep_for(chrono::seconds(5));

        int id = generatePaymentId();
        Payment* payment = new Debit(id, account, amount);
        payment->execute();

        int Id = generatePassId();
        Pass* pass = new Pass(Id, user, car, toll, amount);

        totalPassList.insert({id, pass});
        car->addPass(pass); 
        toll->addAmountCollect(amount);
        cout<<"Processed Payment!!"<<endl; 
        cout<<'\n';

    }else{
        cout<<"Invalid Credentials!!!"<<endl;
        exit(0);
    }      
}

void TollPaymentProcessing::journeyOverView(Car* car){
    vector<Pass*> passList = car->getPass();
    for(auto pass : passList){
        cout<<"Passed by the toll gate: "<<pass->getToll()->getLocation()<<endl;
        cout<<"Amount Paid: "<<pass->getAmount()<<'\n';
    }
    cout<<"Balance Left: "<<car->getUser()->getAccount()->getBalance();
}

int TollPaymentProcessing::generatePaymentId(){
    return paymentId++;
}

int TollPaymentProcessing::generatePassId(){
    return passId++;
}