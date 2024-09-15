    #pragma once
    #include<iostream>
    using namespace std;

    class Book{
        private:
            string id;
            string bookName;
            string author;
            int publishYear;
            bool isAvailable;

        public:
            Book(string id, string bookName, string author, int publishYear){
                this->id = id;
                this->bookName = bookName;
                this->author = author;
                this->publishYear = publishYear;
                isAvailable = true;
            }
            
            void setAvailability(bool status){
                isAvailable = status;
            }

            string getId(){
                return id;
            }

            string getAuthor(){
                return author;
            }

            string getBookName(){
                return bookName;
            }

            bool getAvailability(){
                return isAvailable;
            }
    };