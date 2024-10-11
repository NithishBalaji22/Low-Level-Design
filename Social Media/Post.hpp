// #pragma once
// #include<iostream>
// #include <vector>
// using namespace std;

// class Comment;
// class Post{
//     private:
//         string POST_ID_PREFIX = "POST";
//         static int postIdGenerator;
//         string postId;
//         string userId;
//         string content;
//         vector<Comment*> comments;
//         vector<string>likes;

//     public:
//         Post(string userId, string content){
//             postId = posIdGenerator();
//             this->userId = userId;
//             this->content = content;
//             comments = vector<Comment*>();
//             likes = vector<string>();            
//         }

//         string getPostId(){
//             return postId;
//         }

//         void addLike(string userName){
//             likes.emplace_back(userName);
//         }

//         void addComment(Comment* comment){
//             comments.emplace_back(comment);
//         }

//         bool isthepersonLikedBefore(string userName){
//             for(auto s : likes){
//                 if(userName == s) return true;
//             }
//             return false;
//         }

//         string getUserId(){
//             return userId;
//         }

//         string getContent(){
//             return content;
//         }

//         string posIdGenerator(){
//             postIdGenerator++;
//             return POST_ID_PREFIX + to_string(postIdGenerator);
//         }
// };

// int Post::postIdGenerator = 0;

#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Comment;
class Post {
private:
    static int postIdGenerator;
    string postId;
    string userId;
    string content;
    vector<Comment*> comments;
    vector<string> likes;

public:
    Post(string userId, string content) 
        : postId("POST" + to_string(++postIdGenerator)), userId(userId), content(content) {}

    string getPostId() {
        return postId;
    }

    void addLike(const string& userName) {
        likes.push_back(userName);
    }

    void addComment(Comment* comment) {
        comments.push_back(comment);
    }

    bool isthepersonLikedBefore(const string& userName) {
        return find(likes.begin(), likes.end(), userName) != likes.end();
    }

    string getUserId() {
        return userId;
    }

    string getContent() {
        return content;
    }
};

int Post::postIdGenerator = 0;
