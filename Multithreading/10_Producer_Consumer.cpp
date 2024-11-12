#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

vector<int> buffer;
mutex mtx;
condition_variable cond;
const int maxBufferSize = 50;

void producer(int val){
    while(val){
        unique_lock<mutex>locker(mtx);
        cond.wait(locker, [](){
            return buffer.size() < maxBufferSize;
        });
        buffer.emplace_back(val);
        cout<<"Produced: "<<val<<endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }    
}

void consumer(){
    while(true){
        unique_lock<mutex>locker(mtx);
        cond.wait(locker, [](){
            return buffer.size() > 0;
        });
        int val = buffer.back();
        buffer.pop_back();
        cout<<"Consumed: "<<val<<endl;
        locker.unlock();
        cond.notify_one();        
    }
}

int main(){
    thread t1(producer, 50);
    thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}