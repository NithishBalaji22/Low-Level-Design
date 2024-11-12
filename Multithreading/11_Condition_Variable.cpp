#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;


TOPIC: Condition Variable In C++ Threading
NOTES:
1. Condition variables allow us to synchronize threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronize two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition

condition_variable cond;
mutex mtx;
int balance = 0;

void addMoney(int money){
    unique_lock<mutex> lock(mtx);
    balance += money;
    cout<<"Money has been added: "<<balance<<endl;
    lock.unlock();
    cond.notify_one();
}

void withdrawalMoney(int money){
    unique_lock<mutex> lock(mtx);
    cond.wait(lock, [](){
        return (balance != 0) ? true : false;
    });
    if(balance >= money){
        balance -= money;
        cout<<"Amount has been debitted !!"<<endl;
        cout<<"Balance: "<<balance<<endl;
    }else{
        cout<<"Insufficient Funds !!"<<endl;
    }
    lock.unlock();
}

int main(){
    thread t1(withdrawalMoney, 600);
    this_thread::sleep_for(chrono::seconds(2));
    thread t2(addMoney, 500);

    t1.join();
    t2.join();
    return 0;
}
