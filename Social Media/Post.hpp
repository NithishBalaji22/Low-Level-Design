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
