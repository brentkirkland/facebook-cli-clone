//
//  Wall.hpp
//  CS130A-1
//
//  Created by Brent Kirkland on 10/6/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "ArrayList.h"
#include "List.hpp"
#include "WallPost.hpp"

using std::string;

class Wall {
private:
    ArrayList<WallPost> * posts;
    string username;
public:
    
    Wall(){
        posts = new ArrayList<WallPost>();
    }
    
    Wall(string u){
        username = u;
        posts = new ArrayList<WallPost>();

    };
    
    Wall (const Wall& other ): username(other.username){
        posts = new ArrayList<WallPost>(*other.posts);
        //std::cout << "check one too!";
    };
    
    void addPost(WallPost post);
    void removePost(WallPost post);
    string readUsername();
    void modifyUsername(string username);
    
    string entireWall();
    string entireWallForCommandLine();
    
    void deletePost(int pos);
    bool deletePost(const string username, int pos);
    
    void readWall(string text);
    
    ArrayList<WallPost> * returnPosts();
    
    ~Wall() {
        if (posts != NULL){
            delete posts;
        }
        posts = NULL;
        username.clear();
    };
};

#endif /* Wall_hpp */
