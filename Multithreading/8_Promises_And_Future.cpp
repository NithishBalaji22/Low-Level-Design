#include <iostream>
#include <thread>
#include <mutex>
#include <future>
using namespace std;
typedef unsigned long long ull;

The thread got created and its doing something in a finction and it save some result of that function in the that functions local variable
and if i want to access that functions local variable in my main function then i would use the concept of promises and future

void findOdd(promise<ull> &&oddSumPromise, ull start, ull end){
    ull oddSum = 0;
    for(int i=start; i <= end; i++){
        if(i & 1){
            oddSum += i;
        }
    }
    oddSumPromise.set_value(oddSum);
}

int main(){
    ull start= 0, end= 1900000000;
    promise<ull> oddSum;
    future<ull> oddFuture = oddSum.get_future();

    cout << "Thread Created!" << endl;
    thread t(findOdd, move(oddSum), start, end);

    cout << "Waiting for the Result!!" << endl;

    cout << "OddSum: " << oddFuture.get() << endl; // This .get() waits till the thread sets the value in the promise

    cout << "Completed !!" << endl;
    t.join();

    return 0;
}
