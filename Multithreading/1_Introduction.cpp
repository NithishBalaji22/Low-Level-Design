// TOPIC: Introduction to thread in c++ (c++11)

// QUESTIONS
// 1. What do you understand by thread and give one example in C++ ?

// ANSWER
// 1. In every application there is a default thread which is main(), in side this we create other threads.
// 2. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads. 
//    For example:
//      a. The browser has multiple tabs that can be different threads. 
//      b. MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
//      c. Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

// WAYS TO CREATE THREADS IN C++11
// 1. Function Pointers
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static Member functions

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

ull threadOddSum = 0;
ull threadEvenSum = 0;

void findEven(ull start, ull end){
    for(auto i=start; i<=end; i++){
        if((i&1) == 0){
            evenSum += i;
        }
    }
}

void findOdd(ull start, ull end){
    for(int i=start; i<=end; i++){
        if((i&1) == 1){
            oddSum += i;
        }
    }
}

int main(){
    ull start = 0;
    ull end = 1900000000;

    cout<<"----- Without Multithreading -----"<<endl;

    auto startTime = chrono::high_resolution_clock::now();

    findEven(start, end);
    findOdd(start, end);

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    
    cout<<"OddSum: "<<oddSum<<endl;
    cout<<"EvenSum: "<<evenSum<<endl;
    cout<<"Duration: "<<duration.count()/1000000<<endl;


    cout<<"----- With Multithreading -----"<<endl;

    oddSum = 0;
    evenSum = 0;

    auto StartTime = chrono::high_resolution_clock::now();

    // Run threads
    thread T1(findEven, start, end);
    thread T2(findOdd, start, end);

    // Join threads to ensure they complete
    T1.join();
    T2.join();

    // Capture the end time
    auto EndTime = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto Duration = chrono::duration_cast<chrono::microseconds>(EndTime - StartTime);

    cout << "Odd sum: " << oddSum << endl;
    cout << "Even sum: " << evenSum << endl;
    cout << "Duration: " << Duration.count() / 1000000 << endl;
}