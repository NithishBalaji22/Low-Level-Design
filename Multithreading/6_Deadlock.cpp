#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m1;
mutex m2;


Below code should create deadlock but its not creating because our system so fast that it doesnt create a deadlock situation. And to drive deep into
this how the code generating the possibilities of deadlock then?! If you observe closely the two thread is created t1 and t2 and as both execute paralely
first t1 goes to the function thread1 and t2 goes to the thread2 function at the same time and at the same time t1 acquires lock m1 and t2 acquires lock m2
and both reach the next like where t1 tries to lock m2 which is beeing hold by t2 and t2 tries to lock m1 which is hold by t1. Its like two boys holding
the chocolates where both want each others chocolates but refuse to give their own chocolate at the end no one ready to give chocolate and thats leads to the
deadlock situation. And forgot to add a point the reason why in the below code there is no deadlock is we know system is so fast and what do i mean by that ?! Either
one of the thread acquires both the lock when other thread is on its way to their respective function.



void thread1(){
    m1.lock();
    m2.lock();
    cout << "Critical Section of Thread1" << endl;
    m1.unlock();
    m2.unlock();
}

void thread2(){
    m2.lock();
    m1.lock();
    cout << "Critical Section of Thread2" << endl;
    m2.unlock();
    m1.unlock();
}

int main(){
    system("cls");
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();
    return 0;
}

Lets create deadlock by making them sleep for a second after acquision of one of the lock so when both wake up they will lock for the lock which will be hold by 
other threads and in this situation if you try to run them you could see the deadlock behavior

void thread1(){
    m1.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout << "Critical Section of Thread1" << endl;
    m1.unlock();
    m2.unlock();
}

void thread2(){
    m2.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m1.lock();
    cout << "Critical Section of Thread2" << endl;
    m2.unlock();
    m1.unlock();
}

int main(){
    system("cls");
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();
    return 0;
}

