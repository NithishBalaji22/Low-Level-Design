#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "File.hpp"
#include "FileSystem.hpp"
using namespace std;

class Directory : public FileSystem{
    private:
        string dictionaryName;
        vector<FileSystem*> fileList;
        stack<FileSystem*> recycleBin;

    public:
        Directory(string dictionaryName){
            this->dictionaryName = dictionaryName;
            fileList = vector<FileSystem*>();
            recycleBin = stack<FileSystem*>();
        }

        void changeName(string dictionaryName) override{
            this->dictionaryName = dictionaryName;
            cout<<"Dictionary Name got updated!!!"<<endl;
        }

        void ls() override{
            cout<<"--------------------"<<endl;
            cout<<"Dictionary Name: "<<dictionaryName<<endl;
            cout<<"--------------------"<<endl;

            for(auto file : fileList){
                file->ls();
            }
            cout<<"--------------------"<<endl;
        }

        string getName() override{
            return dictionaryName;
        }

        void add(FileSystem* file){
            fileList.emplace_back(file);
            cout<<"File got added to the dictionary "<<dictionaryName<<endl;
        }

        void deleteFile(FileSystem* file){
            auto it = find(fileList.begin(), fileList.end(), file);
            if(it != fileList.end()){
                fileList.erase(it);
                recycleBin.push(file);
                cout<<"File got deleted from the dictionary!!"<<endl;
            }else{
                cout<<"We couldnt find the file in the dictionary"<<endl;
            }
        }

        void restore(){
            if(!recycleBin.empty()){
                while(!recycleBin.empty()){
                    FileSystem* lastDeletedFile = recycleBin.top();
                    recycleBin.pop();
                    add(lastDeletedFile);
                    cout<<lastDeletedFile->getName()<<" has been restored into the directory "<<dictionaryName<<endl;
                }
            }else{
                cout<<"No files in the recycle bin"<<endl;
            }
        }
};