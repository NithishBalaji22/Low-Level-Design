TOPIC: async
NOTES:
1. It runs a function asynchronously (potentially in a new thread) and returns a std::future that
   will hold the result.
2. There are three launch policies for creating task:
     a. launch::async
     b. launch::deffered

HOW IT WORKS:
1. It automatically creates a thread (Or picks from internal thread pool) and a promise object for us.
2. Then passes the promise object to thread function and returns the associated future object.
3. When our passed argument function exits then its value will be set in this promise object, 
   so eventually return value will be available in future object.


#include <iostream>
#include <thread>
#include <future>
using namespace std;

int func(int start, int end){
    cout<<"Thread ID: "<<this_thread::get_id();
    int oddSum = 0;
    for(int i= start; i<=end; i++){
        if(i & 1) oddSum += i;
    }
    return oddSum;
}

int main(){
    int start = 1, end = 100;
    cout<<"Thread ID: "<<this_thread::get_id()<<endl;
    cout<<"Thread created if the launch policy is async"<<endl;
    future<int> oddSum = async(launch::async, func, start, end);

    cout<<"Waiting for the result: "<<endl;
    cout<<"OddSum: "<<oddSum.get()<<endl;
    cout<<"Completed !!"<<endl;
}
