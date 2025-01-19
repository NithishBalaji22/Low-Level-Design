#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "SubcriberInterface.hpp"
using namespace std;

class Group{
    private:
        vector<ISubcribers*> subcribers;
    public: 
        Group(){
            subcribers = vector<ISubcribers*>();
        }

        void subscribe(ISubcribers* user){
            subcribers.emplace_back(user);
        }

        void unSubscribe(ISubcribers* user){
            auto it = find(subcribers.begin(), subcribers.end(), user);
            if(it != subcribers.end()){
                subcribers.erase(it);
            }else{
                cout<<"Subscribers has not found!!"<<endl;
            }
        }

        void notify(string msg){
            for(auto user : subcribers){
                user->notify(msg);
            }
        }

};