#include "User.hpp"

int User::Counter= 1;

int User::getId(){
    return id;
}

string User::getName(){
    return name;
}

string User::getEmail(){
    return emailId;
}

string User::getLocation(){
    return location;
}

int User::getBalance(){
    return balance;
}

void User::debitAmount(int amount){
    balance -= amount;
}