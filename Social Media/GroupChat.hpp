#pragma once
#include <iostream>
#include <vector>
#include<unordered_map>
#include "User.hpp"
#include "Message.hpp"
using namespace std;

class GroupChat{
    private:
        static int groupIdGenerator;
        int groupId;
        int capacity;
        string groupName;
        unordered_map<string, User*> members;
        unordered_map<int, Message*> chats;

    public:
        GroupChat(string groupName, int capacity){
            groupId = ++groupIdGenerator;
            this->capacity = capacity;
            this->groupName = groupName;
            members = unordered_map<string, User*>();
            chats = unordered_map<int, Message*>();
        }

        int getGroupId(){
            return groupId;
        }

        void addMember(User* user){
            if(members.size() < capacity){
                members[user->getName()] =  user;
                cout<<user->getName()<<" Added to the group"<<endl;
            }else{
                cout<<"The group has reached its capacity so we cannot add "<<user->getName()<<endl;                
            }            
        }

        void removeMember(string name){
            if(members.find(name) != members.end()){
                members.erase(name);
                cout<<name<<" has removed from the group"<<endl;
            }else{
                cout<<name<<" he is not a part of this group"<<endl;
            }            
        }

        User* getMember(User* user){
            return members[user->getName()];
        }

        void addChat(Message* chat){
            chats[chat->getMessageId()] = chat;
        }

        void editChat(int chatId, string newChat){
            if(chats.find(chatId) != chats.end()){
                chats[chatId]->editMessage(newChat);
                cout<<"Message got Editted!"<<endl;
            }else{
                cout<<"The Message does not exits in the groupchat"<<endl;
            }            
        }

        void deleteChat(int chatId){
            if(chats.find(chatId) != chats.end()){
                chats[chatId]->deleteMessage();
                chats.erase(chatId);
                cout<<"Message got deleted!"<<endl;
            }else{
                cout<<"The Message does not exits in the groupchat"<<endl;
            }
        }
};

int GroupChat::groupIdGenerator = 0;