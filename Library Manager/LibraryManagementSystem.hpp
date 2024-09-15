#pragma once
#include"Member.hpp"
#include"Books.hpp"
#include<bits/stdc++.h>
using namespace std;

class LibraryManagementSystem{
    private:
        static LibraryManagementSystem* instance;
        unordered_map<string, Book*> bookList;
        unordered_map<string, Member*> memberList;
        int MAX_COUNT_PER_PERSON = 5;
        int MAX_BOOK_KEEP_DAYS = 14;
        LibraryManagementSystem() {
            bookList = unordered_map<string, Book*>();
            memberList = unordered_map<string, Member*>();
        }

    public:
        static LibraryManagementSystem* getInstance();
        void registerMember(Member* member);
        void addBooks(Book* book);
        void removeMember(string memId);
        void removeBook(string bookId);
        void borrowBook(string memId, string bookId);
        void returnBook(string memId, string booKId);
        Member* getMember(string memId);
        vector<Book*> getLibraryBooks();        
};