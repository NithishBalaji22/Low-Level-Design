#include <iostream>
#include "SocialMediaService.hpp"
using namespace std;

int main() {
    // Initialize the Social Media Service
    SocialMediaZoho* socialMedia = SocialMediaZoho::getInstance();

    // Registering Users
    User* user1 = new User("1", "Alice", "alice@example.com", "pass123", "555-1234", "Hello, I'm Alice!");
    User* user2 = new User("2", "Bob", "bob@example.com", "bobpass", "555-5678", "Bob here!");
    socialMedia->registerUser(user1);
    socialMedia->registerUser(user2);

    // Authenticating User
    User* loggedInUser = socialMedia->authenticateUser("alice@example.com", "pass123");
    if (loggedInUser) {
        cout << "User authenticated: " << loggedInUser->getName() << endl;
    } else {
        cout << "Authentication failed!" << endl;
    }

    // Creating Posts
    Post* post1 = new Post(loggedInUser->getUserId(), "This is Alice's first post!");
    socialMedia->createPost(post1);

    // Adding a Like
    socialMedia->addLike(user2->getName(), post1->getPostId());

    // Adding a Comment
    Comment* comment1 = new Comment(post1->getPostId(), user2->getName(), "Great post, Alice!");
    socialMedia->commentOnPost(post1->getPostId(), comment1);

    // Sending Friend Request
    socialMedia->sendFriendReq(user1->getName(), user2->getName());

    // Creating a Group Chat
    GroupChat* group1 = new GroupChat("Alice's Group", 5);
    socialMedia->createGroup(group1);
    socialMedia->addUserToGroup(group1, {user1, user2});

    // Sending a Message in Group Chat
    Message* msg1 = new Message(user1->getName(), "Hello everyone in the group!");
    group1->addChat(msg1);

    // Editing a Message in Group Chat
    group1->editChat(msg1->getMessageId(), "Updated message: Hello Group!");

    // Deleting a Message in Group Chat
    group1->deleteChat(msg1->getMessageId());

    // Display User Feed
    socialMedia->getFeed(user1->getUserId());
    
    return 0;
}
