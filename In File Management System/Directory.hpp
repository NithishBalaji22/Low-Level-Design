#pragma once
#include <bits/stdc++.h>
#include "FileSystem.hpp"
#include "File.hpp"
using namespace std;

class Directory : public FileSystem{
    private:
        string directoryName;
        vector<FileSystem*> fileList;
        stack<FileSystem*> recycleBin;

    public:
        Directory(string directoryName){
            this->directoryName = directoryName;
            fileList = vector<FileSystem*>();
            recycleBin = stack<FileSystem*>();
        }

        void changeName(string newName) override{
            cout<<"Directory Name has changed from "<<directoryName<<" to "<<newName<<endl;
            this->directoryName = newName;
        }

        void add(FileSystem* file){
            fileList.emplace_back(file);
            cout<<"Added under "<<directoryName<<endl;
        }

        void deleteFile(FileSystem* file){
            auto it = find(fileList.begin(), fileList.end(), file);
            if(it != fileList.end()){
                fileList.erase(it);
                recycleBin.push(file);
                cout<<file->getName()<<" has been deleted"<<endl;
            }else{
                cout<<"File has not found in the directory"<<endl;
            }
        }

        void restore(){
            if(!recycleBin.empty()){
                while(!recycleBin.empty()){
                    FileSystem* lastDeletedFile = recycleBin.top();
                    recycleBin.pop();
                    add(lastDeletedFile);
                    cout<<lastDeletedFile->getName()<<" has been restored to "<<directoryName<<endl;
                }
            }else{
                cout<<"No files in the recycle bin"<<endl;
            }
        }

        void ls() override{
            cout<<"----------------------------------"<<endl;
            cout<<"Directory Name: "<<directoryName<<endl;
            cout<<"----------------------------------"<<endl;
            for(auto file : fileList){
                file->ls();
            }
            cout<<"----------------------------------"<<endl;
        }

        string getName() override{
            return directoryName;
        }
};
