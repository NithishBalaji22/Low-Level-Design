#include<bits/stdc++.h>
using namespace std;

#include"LibraryManagementSystem.hpp"
#include"Books.hpp"
#include"Member.hpp"

int main(){
    LibraryManagementSystem* librarySystem = LibraryManagementSystem::getInstance();

    //Adding Books
    librarySystem->addBooks(new Book("ISBN1", "Book 1", "Author 1", 2020));
    librarySystem->addBooks(new Book("ISBN2", "Book 2", "Author 2", 2021));
    librarySystem->addBooks(new Book("ISBN3", "Book 3", "Author 3", 2022));

    //Adding Members
    librarySystem->registerMember(new Member("M1", "Nithish", "8754685518"));
    librarySystem->registerMember(new Member("M2", "Balaji", "8754685519"));

    //Borrow Books
    librarySystem->borrowBook("M1", "ISBN1");
    librarySystem->borrowBook("M2", "ISBN1");

    //Return Book
    librarySystem->returnBook("M1", "ISBN1");

    //Search Books
    vector<Book*> books = librarySystem->getLibraryBooks();
    cout<<"Search Results: "<<'\n';
    for(auto it : books){
        cout<<"Book Name: "<<it->getBookName()<<" and the author is: "<<it->getAuthor()<<'\n';
    }
}