TOPIC: Use of join(), detach() and joinable() in Thread In C++ (c++11, 14, 20, 23)

JOIN NOTES
0. Once a thread is started we wait for this thread to finish by calling join() function on thread object
1. Double join will result into program termination
2. If needed we should check thread is joinable before joining ( using joinable() function)

DETACH NOTES
0. This is used to detach newly created thread from the parent thread
1. Always check before detaching a thread that is joinable otherwise we may end up double detaching ans
   double detach() will result into program termination
2. If we have detached thread and main function is returning then the detached thread execution is suspended.

NOTES:
Either join() or detach() should be called on thread object, otheriwise during thread object's destructor it will
terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

//Basic 
void run(int count){
    while(count-- > 0){
        cout<< count << " Zoho" << endl;
    }
}

int main(){
    thread t1(run, 10);
    cout<< "Main" <<endl;
    t1.join();
    cout<< "Main finished"<<endl;
    return 0;
}

So the "Main finished" line will only will get execute after t1 completes its tasks so printing the count with Zoho and sleeping for 5 sec (Assume some work beeing done for the 5sec)
If you run the below program you could see that the Main Finished will get runned after the printing + 5 Second wating period
The purpose of join is that it waits till the thread done with its job then start to execute the line after the t1.join() statement

void run(int count){
    while(count-- > 0){
        cout<< count << " Zoho" << endl;
    }
    this_thread::sleep_for(chrono::seconds(5));
}

int main(){
    thread t1(run, 10);
    cout<< "Main" <<endl;
    t1.join();
    cout<< "Main finished"<<endl;
    return 0;
}

// Possile program termination part by double joins

    The thing is that it wont give you some syntax error it runs smoothly untill!!! the problem starts to occurs 
    Program Flow:
        1) Thread got created and starts to execute 
        2) Printing the required thing
        3) Prints Main
        4) 75th Lines waits for the process to complete and 75th line came executed
        5) 76th line again sees that to join t1 but the program just before join the t1 thread so it will get terminate

        Precaution:
            Using if(t1.joinable)
            You have written tons of code then you actually join before some hundres of codes but in your mind you thought you havent join so you included again 
            so to avoid that whenever you are joining always looks for joinable function alright !!!


void run(int count){
    while(count-- > 0){
        cout<< count << " Zoho" << endl;
    }
}

int main(){
    thread t1(run, 10);
    cout<< "Main" <<endl;
    t1.join();
    //t1.join() // To avoid such termination we use the below function to check where its joinable or not !
    if(t1.joinable())
        t1.join();
    cout<< "Main finished"<<endl;
    return 0;
}


If you execute the below statement you will get something like
    Output: (Could vary accoding to the thread) 
        Main
        Main finished

    Where is the count an the Zoho thing?
            The reason that is not beeing executed is because the firstly the created thread is detached meaning that it got deatch from the parent thread here the parent thread
        of the t1 is the main thread ie, main() so as it got detached from the parent thread the parent thread from now on it wont care about the child thread so the Os will 
        be taking some time to create the thread t1 right within that creation time the parent thread ie, main() thread got executed and return 0; meaning that parent thread got 
        executed before the creation of the t1 thread

            Addon: Parent thread ie, main thread finish soon before the creation of the thread t1 this happens cuz the t1 threads goes to the os and os examine that
        then it get processed then it get it memory allocation to do all these process within this all the chazos the parent thread finished it execution as the t1 thread
        doesnt belongs to the main thread as we have used detach

            The created thread will only be alive untill the main thread is alive if main thread got finished and the other threads running that doesnt belongs to the main thread
        then it will get terminated as the thread isnt belongs to the main thread 


void run(int count){
    while(count-- > 0){
        cout<< count << " Zoho" << endl;
    }
    this_thread::sleep_for(chrono::seconds(5));
}

int main(){
    thread t1(run, 10);
    cout<< "Main" <<endl;
    t1.detach();
    cout<< "Main finished"<<endl;
    return 0;
}

 
    Below Code 
    Output: (Could vary accoding to the thread)
        Main
        9 Zoho
        8 Zoho
        7 Zoho
        6 Zoho
        5 Zoho
        4 Zoho
        3 Zoho
        2 Zoho
        1 Zoho
        0 Zoho
        Main finished

        How is this running now !? 
            Because its the same case as before but we are making the parent thread to sleep for 5 Seconds in the mean time of that 5 seconds the child thread t1 
        gets created and executed how cool is that !!



void run(int count){
    while(count-- > 0){
        cout<< count << " Zoho" << endl;
    }
    cout<< "Thread Finished !"<< endl;
}

int main(){
    thread t1(run, 10);
    cout<< "Main" <<endl;
    t1.detach();
    this_thread::sleep_for(chrono::seconds(5));
    cout<< "Main finished"<<endl; // Waits for 5 Seconds then it execute this statement
    return 0;
}


// Problem : Using detach more than once

void run(int count){
    while(count-- > 0){
        cout<< count << " Zoho" << endl;
    }
    cout<< "Thread Finished !"<< endl;
}

int main(){
    thread t1(run, 10);
    cout<< "Main" <<endl;
    t1.detach();
    // t1.detach() problem
    if(t1.joinable())
        t1.detach(); // Only if the t1 is joinable we can detach right think intuitively
    this_thread::sleep_for(chrono::seconds(5));
    cout<< "Main finished"<< endl; // Waits for 5 Seconds then it execute this statement
    return 0;
}


