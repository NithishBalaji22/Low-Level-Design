#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<algorithm>
using namespace std;

class FileSystem{
    public:
        virtual void ls() = 0;
        virtual string getName() = 0;
};

class File : public FileSystem{
    private:
        string fileName;

    public:
        File(string fileName){
            this->fileName = fileName;
        }

        string getName() override{
            return fileName;
        }

        void ls() override{
            cout<<"File Name: "<<fileName<<'\n';
        }
};

class Directory : public FileSystem{
    private:
        string directoryName;
        vector<FileSystem*> fileSystemList;
        stack<FileSystem*> recycleBin;

    public:
        Directory(string directoryName){
            this->directoryName = directoryName;
            fileSystemList = vector<FileSystem*>();
            recycleBin = stack<FileSystem*>();
            cout<<"Directory: "<<directoryName<<" has been created successfully"<<'\n';
        }

        string getName() override{
            return directoryName;
        }

        void add(FileSystem* fileSystem){
            auto it = find(fileSystemList.begin(), fileSystemList.end(), fileSystem);
            if(it == fileSystemList.end()){
                fileSystemList.emplace_back(fileSystem);
            }else{
                cout<<"The Directory "<<fileSystem->getName()<<" already exist"<<'\n';
            } 
        }

        void Delete(FileSystem* fileSystem){
            auto it = find(fileSystemList.begin(), fileSystemList.end(), fileSystem);
            if(it != fileSystemList.end()){
                cout<<fileSystem->getName()<<" has been deleted successfully!"<<'\n';
                recycleBin.push(fileSystem);
                fileSystemList.erase(it);
            }else{
                cout<<"The Directory "<<fileSystem->getName()<<" does not exist"<<'\n';
            } 
        }

        void restore(){
            if(!recycleBin.empty()){
                FileSystem* lastDeletedItem = recycleBin.top();
                recycleBin.pop();
                fileSystemList.emplace_back(lastDeletedItem);
                cout<<lastDeletedItem->getName()<<" has been restored successfully and added to the directory: "<<this->directoryName<<'\n';
            }
        }

        void ls() override{
            cout<<"Directory Name: "<<directoryName<<'\n';

            for(FileSystem* fileSystem : fileSystemList){
                fileSystem->ls();
            }
        }
};