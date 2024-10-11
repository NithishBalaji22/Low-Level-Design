// #pragma once
// #include<iostream>
// using namespace std;

// class Message{
//     private:
//         static int messageId;
//         string userName;
//         string chat;

//     public:
//         Message(string userName, string chat){
//             messageId = messageId++;
//             this->userName = userName;
//             this->chat = chat;
//         }

//         int getMessageId(){
//             return messageId;
//         }

//         void editMessage(string& newChat){
//             chat = newChat;
//         }

//         void deleteMessage(){
//             chat = "[deleted]";
//         }

// };

// int Message::messageId= 1;

#pragma once
#include <iostream>
using namespace std;

class Message {
private:
    static int messageIdGenerator;
    int messageId;
    string userName;
    string chat;

public:
    Message(const string& userName, const string& chat) 
        : messageId(++messageIdGenerator), userName(userName), chat(chat) {}

    int getMessageId() {
        return messageId;
    }

    void editMessage(const string& newChat) {
        chat = newChat;
    }

    void deleteMessage() {
        chat = "[deleted]";
    }
};

int Message::messageIdGenerator = 0;
