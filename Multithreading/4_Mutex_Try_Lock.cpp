// TOPIC : mutex::try_lock() On mutex In C++ Threading 

0. try_lock() tries to lock the mutex clearly understand it only tries. On successfull lock acquisition it returns true meaning that lock has been acquired, In case
if the lock is acquired by the other thread then it returns immediately. 

Q) What is the difference between lock() and try_lock?
    The difference is that assume that we got two threads and both trying to acquire lock in critical section, In lock() when t1 acquired the lock then it starts
to execute the critical section but t2 didnt get the lock right then it waits there till t1 completes the task its like you are stuck in the waiting room although
t2 might have another task to perform but as it got stuck in the waiting room it wont be allowed to do other assigned task too. But in the case of try_lock() if t2
didnt get the lock then it might go and do the other assigned task and come back then t1 unlocks it 

1. If try_lock() is ot able to lock the mutex, then it doesnt get blocked thats why its called non-blocking
2. If try_lock() is called again by the same thread which owns the mutex, the behavior is undefined.
    Its a dead lock situation with undefined behavior. (if you want to able to lock the same mutex by the same thread
more than one time then go for recursive_lock)    

 ChatGPT Doubts:
Q) Cosider t1 got the try_lock () alright and t2 wont get the lock right so the for loop keep on iterating even if t2 didn't get lock?
       Yes, exactly! If t2 does not acquire the lock on any given iteration due to t1 holding it, t2 will simply skip the increment for that particular iteration. 
The for loop in t2 will keep on iterating regardless of whether try_lock() succeeds or fails, meaning it won’t stop or wait—it’ll just proceed to the next iteration.

Here’s how it works step-by-step for t2:

Iteration Without Lock:
When t2 reaches a point in its loop where try_lock() returns false (because t1 currently holds the lock), t2 will skip the counter++ operation
and simply move to the next iteration in its loop.

Continuing the Loop:
1) t2 continues its loop until it completes all 100,000 iterations, regardless of whether it successfully locks and increments counter on 
every iteration.
2) Each time t2 attempts try_lock(), it makes an independent decision: either increment counter if the lock is acquired, or skip if it isn’t.

Multiple Attempts:
On each subsequent iteration, t2 will keep trying to acquire the lock. Whenever t1 releases the lock and t2 is successful with try_lock(), it 
will increment counter and then release the lock.
                    
Therefore, even if t2 fails to get the lock in one iteration, it doesn’t stop or wait; it simply proceeds to the next iteration in the loop. The
for loop keeps running until all iterations are completed, irrespective of whether t2 has successfully acquired the lock during each iteration.

BECAUSE OF THIS REASON WE ARE NOT GETTING 200000 AS THE LOCK ACQUIRES IS INSIDE THE FOR LOOP SO IF IT DIDNT GET THE THREAD WILL KEEP ON 
ITERATING UNTILL IT THE LOCK SO THE ITERATION IS GETTING WASTED

// Member Function of Mutex Class is try_lock()
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex mtx;

void increaseTheCounterFor100000Time(){
    for(int i=0; i<100000; i++){
        if(mtx.try_lock()){
            ++counter;
            mtx.unlock();
        }
    }
}

int main(){
    thread t1(increaseTheCounterFor100000Time);
    thread t2(increaseTheCounterFor100000Time);

    t1.join();
    t2.join();

    system("cls");
    cout << "Counter could increase upto : " << counter << endl;
}
