#include <iostream>
#include "Group.hpp"
#include "SubcriberInterface.hpp"
#include "User.hpp"
using namespace std;

int main(){
    Group* group = new Group();

    //Creating User
    ISubcribers* user1 = new User(1);
    ISubcribers* user2 = new User(2);
    ISubcribers* user3 = new User(3);
    ISubcribers* user4 = new User(4);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("Hello you have received a new message !!");

    group->unSubscribe(user4);
    group->notify("Hello !!");
}