#include "SocialMediaService.hpp"

SocialMediaZoho* SocialMediaZoho::instance = nullptr;

SocialMediaZoho* SocialMediaZoho::getInstance(){
    if(instance == nullptr){
        instance = new SocialMediaZoho();
    }
    return instance;
}

User* SocialMediaZoho::authenticateUser(string emailId, string password){
    User* user = accounts[emailId];
    if(user != nullptr){
        bool authenticate = user->validateAuthentication(emailId, password);
        if (authenticate) return user;
    }

    return nullptr;
}

void SocialMediaZoho::registerUser(User* user){
    accounts.insert({user->getEmailId(), user});
}

void SocialMediaZoho::createPost(Post* post){
    User* user = accounts[post->getUserId()];
    if(user != nullptr){
        user->addPost(post);
        feeds.emplace_back(post);
        posts.insert({post->getPostId(), post});
    }
}

void SocialMediaZoho::createGroup(GroupChat* group){
    totalGroups.emplace_back(group);
    groupChats.insert({group->getGroupId(), group});
}

void SocialMediaZoho::addUserToGroup(GroupChat* group, vector<User*> users){
    GroupChat* group = groupChats[group->getGroupId()];
    if(group != nullptr){
        for(User* user : users){
            group->addMember(user);
        }
        return;
    }

    cout<<"Such group doesnt exits create one!"<<endl;
}

void SocialMediaZoho::removeUserFromGroup(GroupChat* group, User* user){
    GroupChat* grp = groupChats[group->getGroupId()];
    if(grp != nullptr){
        User* member = grp->getMember(user);
        if(member != nullptr){
            grp->removeMember(member->getName());
            return;
        }else{
            cout<<"Such member doesnt exits in the group"<<endl;
            return;
        }
    }

    cout<<"Such group doesnt exits so we cannot validate the user sorry"<<endl;
}

void SocialMediaZoho::getFeed(string userId){
    User* user = accounts[userId];
    if(user != nullptr){
        vector<User*> friends = user->getFriends();
        for(User* user : friends){
            for(Post* post : user->getPosts()){
                cout<<post->getContent()<<endl;
            }
        }
        return;
    }    

    cout<<"User doesnt exist"<<endl;
}

void SocialMediaZoho::addLike(string userId, string postId){
    Post* post = posts[postId];
    User* user = accounts[userId];

    if(post != nullptr && user != nullptr && !(post->isthepersonLikedBefore(user->getName()))){
        post->addLike(userId);
        return;
    }

    if(post != nullptr){
        cout<<"The post doesnt exist so you cannot like the post sorry"<<endl;
        return;
    }else if(post->isthepersonLikedBefore(user->getName())){
        cout<<"You have already liked the post !"<<endl;
        return;
    }

    cout<<"The userId doesnt exist so you cannot like sorry"<<endl;
}

void SocialMediaZoho::commentOnPost(string postId, Comment* comment){
    Post* post = posts[postId];
    if(post != nullptr){
        post->addComment(comment);
        cout<<"Comment has been added to the post"<<endl;
        return;
    }

    cout<<"The Post is unavailable"<<endl;
}

void SocialMediaZoho::sendFriendReq(string user, string Friend){
    User* userId = accounts[user];
    User* friendId = accounts[Friend];

    if(userId != nullptr && friendId != nullptr){
        userId->addFriends(friendId);
        friendId->addFriends(userId);
        cout<<"Friend Request sent and accepted !"<<endl;
        return;
    }

    cout<<"Something went wrong"<<endl;
}


