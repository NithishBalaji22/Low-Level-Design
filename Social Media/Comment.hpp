// #pragma once
// #include<iostream>
// using namespace std;

// class Comment{
//     private:
//         string COMMENT_ID_PREFIX = "CMT";
//         static int commentIdGenerator;
//         string commentId;
//         string postId;
//         string user;
//         string content;

//     public:
//         Comment(string postId, string user, string content){
//             commentId = generateCommentId();
//             this->postId = postId;
//             this->user = user;
//             this->content = content;
//         }

//         string postId(){
//             return postId;
//         }

//         string getuser(){
//             return user;
//         }

//         string generateCommentId(){
//             commentIdGenerator++;
//             return COMMENT_ID_PREFIX + to_string(commentIdGenerator);
//         }
// };

// int Comment::commentIdGenerator = 0;

#pragma once
#include <iostream>
using namespace std;

class Comment {
private:
    static int commentIdGenerator;
    string commentId;
    string postId;
    string user;
    string content;

public:
    Comment(const string& postId, const string& user, const string& content) 
        : commentId("CMT" + to_string(++commentIdGenerator)), postId(postId), user(user), content(content) {}

    string getPostId() {
        return postId;
    }

    string getUser() {
        return user;
    }
};

int Comment::commentIdGenerator = 0;
