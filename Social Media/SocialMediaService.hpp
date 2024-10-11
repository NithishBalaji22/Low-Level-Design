#pragma once
#include<bits/stdc++.h>
#include"Comment.hpp"
#include "GroupChat.hpp"
#include "Message.hpp"
#include"Post.hpp"
#include"User.hpp"
using namespace std;


class SocialMediaZoho{
    private:
        static SocialMediaZoho* instance;
        unordered_map<string, User*>accounts;
        vector<Post*> feeds;
        unordered_map<string, Post*> posts;
        vector<GroupChat*> totalGroups;
        unordered_map<int, GroupChat*> groupChats;
        SocialMediaZoho(){
            accounts = unordered_map<string, User*> ();
            feeds = vector<Post*>();
            posts = unordered_map<string, Post*>();
            totalGroups = vector<GroupChat*>();
            groupChats = unordered_map<int, GroupChat*>();
        }

    public:
        static SocialMediaZoho* getInstance();
        User* authenticateUser(string emailId, string password);
        void registerUser(User* user);
        void createPost(Post* post);
        void createGroup(GroupChat* group);
        void addUserToGroup(GroupChat* group, vector<User*> users);
        void removeUserFromGroup(GroupChat* group, User* user);
        void getFeed(string userId);
        void addLike(string userId, string postId);
        void commentOnPost(string postId, Comment* comment);
        void sendFriendReq(string user, string Friend);
        
};