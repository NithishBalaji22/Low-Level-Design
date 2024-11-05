#pragma once
#include <iostream>
#include <vector>
#include "UserCategory.hpp"
using namespace std;

class Pass;
class Car;
class Account;
class User{
    private:
        int userId;
        string userName;
        Account* account;
        UserCategory category;        
        

    public:
        User(int id, string userName, Account* account, UserCategory category){
            this->userId = id;
            this->userName = userName;
            this->account = account;
            this->category = category;
        }

        int getUserId(){
            return userId;
        }

        UserCategory getCategory(){
            return category;
        }

        Account* getAccount(){
            return account;
        }
};