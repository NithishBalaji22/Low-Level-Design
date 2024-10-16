//TOPIC: Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It ? | What is Critical Section

//Mutex : Mutual Exclusion

//RACE CONDITION
// 0. Race condition is a condition where two or more threads/process happend to change a common data at the same time
// 1. If there is a race conditio then we have to protect it and the protected setion is called critical section/region

//MUTEX:
// 0. Mutex is used to avoid the race condition 
// 1. We ise lock(), unlock(), on mutex to avoid the race condition

// Remember : The race condition is only possible when two or more thread got the same variable

//Expectations: As the two threads got created the expected out is 2 right but heres where the race condition kicks in and outputs 1 rather 2
// this is because both get executed parallely so both at a time change myAmount as 1

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int myAmount = 0; // Expected 2 but we might get 1 it depends on the os it may or may not be 2 its a good practice to use locks when there is race conditon. Solution ? Use Mutex Locks

// void addMoney(){
//     ++myAmount; // This is where the problem happens so this is the Critical Section
// }

// int main(){
//     thread t1(addMoney);
//     thread t2(addMoney);

//     t1.join();
//     t2.join();
//     cout<< myAmount << endl; 
//     // Surprisingly it outputs 2 but at the end its all depends on the os right at this moment it outputs
//     // 2 as expeted but there is this problem of race condition you should be cautious so always use lock when there is race condition
// }

// Using Mutex Locks
mutex m;

// void addMoney(){
//     m.lock();
//     ++myAmount;
//     m.unlock();
// }

// int main(){
//     thread t1(addMoney);
//     thread t2(addMoney);

//     t1.join();
//     t2.join();
//     cout<< myAmount << endl;
// }
