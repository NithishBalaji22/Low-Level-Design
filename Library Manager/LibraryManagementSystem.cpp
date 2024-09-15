#include "LibraryManagementSystem.hpp"

LibraryManagementSystem* LibraryManagementSystem::instance = nullptr;

LibraryManagementSystem* LibraryManagementSystem::getInstance(){
    if(instance == nullptr){
        instance = new LibraryManagementSystem();
    }

    return instance;
}

void LibraryManagementSystem::registerMember(Member* member){
    memberList[member->getMemId()] = member;
}

void LibraryManagementSystem::addBooks(Book* book){
    bookList[book->getId()] = book;
}

void LibraryManagementSystem::removeMember(string memId){
    auto it = memberList.find(memId);
    if(it != memberList.end()){
        memberList.erase(it);
        cout << "Member has been removed successfully" << '\n';
    }else{
        cout << "Member not found" << '\n';
    }
}

void LibraryManagementSystem::removeBook(string bookId){
    auto it = bookList.find(bookId);
    if(it != bookList.end()){
        bookList.erase(it);
        cout << "Book has been removed successfully" << '\n';
    }else{
        cout << "Book not found" << '\n';
    }
}

void LibraryManagementSystem::borrowBook(string memId, string bookId){
    Member* member = memberList[memId];
    Book* book = bookList[bookId];

    if(member != nullptr && book != nullptr){
        if(member->getBookCount() < MAX_COUNT_PER_PERSON && book->getAvailability()){
            member->addBook(book);
            book->setAvailability(false);
            cout<<"Book borrowed: "<<book->getBookName() << " by "<<member->getMemName()<<'\n';
        }else{
            if(member->getBookCount() < MAX_COUNT_PER_PERSON) cout<<"You have reached your limit!"<<'\n';
            else{
                cout<<"Sorry the book you are looking for is not available sorry for the inconvinience caused !"<<'\n';
            }
        }
    }else{
        cout<<"The book you are looking for is not in our library"<<'\n';
    }
}


void LibraryManagementSystem::returnBook(string memId, string bookId){
    Member* member = memberList[memId];
    Book* book = bookList[bookId];

    if(member != nullptr && book != nullptr){
        member->removeBook(book);
        book->setAvailability(true);
        cout<<"Book " <<book->getBookName()<<" has been successfully returned by: "<<member->getMemName()<<'\n';
    }else{
        cout<<"Book or the member is not found"<<'\n';
    }
}

vector<Book*> LibraryManagementSystem::getLibraryBooks(){
    vector<Book*>v;
    for(auto it : bookList){
        v.emplace_back(it.second);
    }
    return v;
}