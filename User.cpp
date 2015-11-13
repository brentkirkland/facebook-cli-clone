//
//  User.cpp
//  CS130A-1
//
//  Created by Brent Kirkland on 10/7/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#include "User.hpp"

User::User(string text){
    
    string remove_pre_text = "username: ";
    size_t pos = text.find(remove_pre_text);
    text.erase(0, pos + remove_pre_text.length());
    
    string after_username_text = "\npassword: ";
    pos = text.find(after_username_text);
    
    this->username = text.substr(0, pos);
    
    pos = text.find(after_username_text);
    text.erase(0, pos + after_username_text.length());

    string after_password_text = "\ncity: ";
    pos = text.find(after_password_text);

    this->password = text.substr(0, pos);
    
    text.erase(0, pos + after_password_text.length());
    
    string after_city = "\nwall:\n";
    pos = text.find(after_city);
    
    this->city = text.substr(0, pos);
    
    text.erase(0, pos + after_city.length());
    
    string after_wall = "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
    pos = text.find(after_wall);
    
    this->wall = new Wall(this->username);
    this->wall->readWall(text.substr(0, pos));
    
    text.erase(0, pos + after_wall.length());

}

void User::editPassword(string new_password){
    this->password = new_password;
}

void User::editUsername(string new_username){
    this->username = new_username;
    this->wall->modifyUsername(new_username);
}

void User::editCity(string new_city){
    this->city = new_city;
}

string User::getCity() {
    return city;
}

const string User::getPassword() const{
    return password;
}

const string User::getUsername() const{
    return username;
}

string User::getWall(){
    
    if (wall != NULL){
        return wall->entireWall();
    }
    return "";
}

string User::getWallForCommandLine(){
    
    if (wall != NULL){
        return wall->entireWallForCommandLine();
    }
    return "";
}

Wall * User::getWallPointer(){
    return wall;
}

void User::addPost(WallPost post){
    
    this->wall->addPost(post);
}

void User::deletePost(WallPost post){
    this->wall->removePost(post);
}

const string User::userInfo() const{
    
    return "username: " + this->username + "\npassword: " + this->password + "\ncity: " + this->city + "\nwall:\n" + this->wall->entireWall() + "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
    
}

bool operator==(User& left, User& right) {
    return (left.getUsername() == right.getUsername()
            && left.getPassword() == right.getPassword()
            && left.getCity() == right.getCity());
};

void User::addFriend(User u){
    if (friends == NULL) {
        friends = new ArrayList<User>[1];
    }
    friends->insert(0, u);
}

void User::removeFriend(User u){
    if (friends == NULL) {
        return;
    }
    
    //remove friend from both users
    friends->remove(friends->find(u));
    u.getFriends().remove(friends->find(*this));
}

void User::addPendingFriend(User u){
    if (pendingFriends == NULL) {
        pendingFriends = new ArrayList<User>[1];
    }
    pendingFriends->insert(0, u);
}

void User::removePendingFriend(User u){
    if (pendingFriends == NULL) {
        return;
    }
    
    //remove friend from both users
    pendingFriends->remove(friends->find(u));
    //zu.getFriends().remove(friends->find(*this));
}

void User::deletePost(int pos){
    
    wall->deletePost(pos);
    
}

ArrayList<User> User::getFriends(){
    return *friends;
}

ArrayList<User> User::getPendingFriends(){
    return *pendingFriends;
}


