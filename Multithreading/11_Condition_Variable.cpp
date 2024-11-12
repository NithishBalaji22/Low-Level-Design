#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

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
