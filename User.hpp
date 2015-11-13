//
//  User.hpp
//  CS130A-1
//
//  Created by Brent Kirkland on 10/7/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>

#include "Wall.hpp"
#include "WallPost.hpp"

class User {
    
private:
    
    string username;
    string password;
    string city;
    Wall *wall;
    
    //make array based on size
    //ArrayList<ArrayList<int>> * friends;
    
    ArrayList<User> * pendingFriends;
    ArrayList<User> * friends;
    
    //int friends[];
    
public:
    
    User(){};
    
    User(string u, string p, string c): username(u), password(p), city(c){
        wall = new Wall();
        wall->modifyUsername(u);
        //friends = new int[][]
        
        //friends = new ArrayList<User>[1];
    };
    
    //read string and create user
    User(string text);
    
    User(const User& other): username(other.username), password(other.password), city(other.city){
        
        
        wall = new Wall(*other.wall);
    };
    
    void editPassword(string new_password);
    void editUsername(string new_username);
    void editCity(string new_city);
    
    const string getUsername() const;
    const string getPassword() const;
    string getCity();
    string getWall();
    
    string getWallForCommandLine();
    
    Wall * getWallPointer();
    
    void addPost(WallPost post);
    void deletePost(WallPost post);
    
    const string userInfo() const;
    
    void addFriend(User u);
    void removeFriend(User u);
    void addPendingFriend(User u);
    void removePendingFriend(User u);
    
    void deletePost(int pos);
    
    ArrayList<User> getFriends();
    ArrayList<User> getPendingFriends();
    
    ~User(){
        
//        if (username != ""){
//            delete wall;
//        }
        username.clear();
        password.clear();
        city.clear();
        wall = NULL;
        
    };
};

bool operator==(User& left, User& right);

#endif /* User_hpp */
