#pragma once
#include<bits/stdc++.h>
using namespace std;

class Book;
class Member{
    private:
        string memId;
        string name;
        string phoneNumber;
        vector<Book*> list;

    public:
        Member(string memId, string name, string phoneNumber){
            this->memId = memId;
            this->name = name;
            this->phoneNumber = phoneNumber;
            list = vector<Book*>();
        }

        string getMemName(){
            return name;
        }

        string getMemId(){
            return memId;
        }

        void addBook(Book* book){
            list.emplace_back(book);
        }

        void removeBook(Book* book){
            auto it = find(list.begin(), list.end(), book);
            if(it != list.end()){
                list.erase(it);
            }
        }

        int getBookCount(){
            return list.size();
        }

        vector<Book*> getBookList(){
            return list;
        }

};