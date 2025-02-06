#include <iostream>
#include "GiftCardSystem.hpp"
using namespace std;

void display(){
    cout<<endl;
    cout<<"1. Account Summary"<<endl;
    cout<<"2. Create Gift Card"<<endl;
    cout<<"3. Create Customer"<<endl;
    cout<<"4. Gift Card Summary"<<endl;
    cout<<"5. Top-Up Gift Card"<<endl;
    cout<<"6. Close Gift Card"<<endl;
    cout<<"7. Purchase Item"<<endl;
    cout<<"8. Block Gift Card\n"<<endl;
}
int main(){
    GiftCardSystem* system = GiftCardSystem::getInstance();

    while(true){
        display();
        int option;
        cout<<"\nEnter the Option: ";
        cin>>option;

        switch(option){
            case 1:
                system->accountSummary();
                break;
            case 2:
                system->createGiftCard();
                break;
            case 3:
                system->createCustomer();
                break;
            case 4:
                system->giftCardSummary();
                break;
            case 5:
                system->topUpGiftCard();
                break;
            case 6:
                system->closeGiftCard();
                break;
            case 7:
                system->purchaseItem();
                break;
            default:   
                break;
        }
    }
}