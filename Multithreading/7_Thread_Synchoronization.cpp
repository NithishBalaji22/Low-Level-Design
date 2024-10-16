#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

int bankBalance = 0;

// We expect 100 or 200 but the computer is soo fast that it outputs correctly but there synchoronization problem happens in this situation then whats
// the solution then?! Yup!! locks

// void addMoney(int amount){
//     bankBalance += amount;
// }

// int main(){
//     thread t1(addMoney, 100);
//     thread t2(addMoney, 200);

//     t1.join();
//     t2.join();

//     cout<<"Bank Balance: "<<bankBalance<<endl;
//     return 0;
// }

mutex m;

void addMoney(int amount){
    m.lock();
    bankBalance += amount;
    m.unlock();
}

int main(){
    thread t1(addMoney, 100);
    thread t2(addMoney, 200);

    t1.join();
    t2.join();

    cout<<"Bank Balance: "<<bankBalance<<endl;
    return 0;
}