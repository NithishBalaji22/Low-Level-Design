#pragma once
#include <iostream>
#include "FileSystem.hpp"
using namespace std;

class File : public FileSystem{
    private:
        string fileName;
        string oldContent;
        string content;

    public:
        File(string fileName){
            this->fileName = fileName;
            oldContent = "";
            content = "";
        }

        void ls() override{
            cout<<"File Name: "<<fileName<<endl;
        }

        void changeName(string newName) override{
            cout<<"File name changed from "<<fileName<<" to "<<newName<<endl;
            this->fileName = newName;
        }

        string getName() override{
            return fileName;
        }

        void updateContent(string newContent){
            oldContent = content;
            content = newContent;
            cout<<"Content has been updated!!"<<endl;
        }

        void undoContent(){
            content = oldContent;
            oldContent = "";
            cout<<"Content has been updated to its previous state!!"<<endl;
        }
};