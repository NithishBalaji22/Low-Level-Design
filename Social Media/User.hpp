#pragma once
#include<iostream>
#include <vector>
using namespace std;

class Post;
class User{
    private:
        string userId;
        string name;
        string emailId;
        string password;
        string phoneNumber;
        string bio;
        vector<Post*> posts;
        vector<User*> friends;

    public:
        User(string userId, string name, string emailId, string password, string phoneNumber, string bio){
            this->userId = userId;
            this->name = name;
            this->emailId = emailId;
            this->password = password;
            this->phoneNumber = phoneNumber;
            this->bio = bio;
            posts = vector<Post*>();
            friends = vector<User*>();
        }

        string getUserId(){
            return userId;
        }

        string getEmailId(){
            return emailId;
        }

        string getName(){
            return name;
        }

        string password(){
            return password;
        }

        vector<Post*> getPosts(){
            return posts;
        }

        void addPost(Post* post){
            posts.emplace_back(post);
        }

        void addFriends(User* user){
            friends.emplace_back(user);
        }

        vector<User*> getFriends(){
            return friends;
        }

        bool validateAuthentication(string id, string pass){
            return emailId == id && password == pass;
        }
};