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
