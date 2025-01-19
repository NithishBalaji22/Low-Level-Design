#include <iostream>
#include <mutex>
using namespace std;

mutex mtx;
class Singleton{
    private:
        // Step1: Create a static var to hold one instance of Singleton class.
        static Singleton* instance; 

        // Step2: Create private singleton constructor
        Singleton(){

        }

    public:
        // Step3: Create a static getInstance() method to instantiate the class and also to return an instance of it.
        // Double Locking SIngleton Logic
        static Singleton* getinstance(){
            if(instance == nullptr){
                mtx.lock();
                if(instance == nullptr){
                    instance = new Singleton();
                }
                mtx.unlock();                
            }
            return instance;
        }

};

Singleton::instance = nullptr;

