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

        void changeName(string newFileName) override{
            cout<<"File Name has Changed From "<<fileName<<" "<<newFileName<<endl;
            this->fileName = newFileName;
        }

        void updateContent(string newContent){
            oldContent = content;
            content = newContent;
            cout<<"Content updated in the file "<<fileName<<endl;
        }

        void undoContent(){
            this->content = oldContent;
            cout<<"Content has been restored into the previous state "<<fileName<<endl;
        }

        string getName() override{
            return fileName;
        }
};