//
//  Wall.cpp
//  CS130A-1
//
//  Created by Brent Kirkland on 10/6/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#include "Wall.hpp"
#include "WallPost.hpp"

void Wall::addPost(WallPost post){
    
    if (posts == NULL){
        posts = new ArrayList<WallPost>();
    }
    
    //posts->addTail(post);

    posts->insert(0, post);
}

void Wall::removePost(WallPost post){
    posts->remove(posts->find(post));
}

string Wall::readUsername(){
    return username;
}

void Wall::modifyUsername(string username){
    this->username = username;
}

string Wall::entireWall(){

    string x = string();
    
    if (posts != NULL) {
    
        int y = posts->getSize();
        if ( y >= 0) {
    
        for (int i = posts->getSize() - 1; i >= 0; i--){
            x = x + posts->get(i).getEntirePost() + "********************** \n\n";
            }
        }
    }
    return x;
}

string Wall::entireWallForCommandLine(){
    string x = string();
    
    if (posts != NULL) {
        
        int y = posts->getSize();
        if ( y >= 0) {
            
            for (int i = posts->getSize() - 1; i >= 0; i--){
                x = x + ToString(i + 1) + ". " + posts->get(i).getEntirePost() + "********************** \n\n";
            }
        }
    }
    return x;
}

void Wall::deletePost(int pos){
    posts->remove(pos);
}

bool Wall::deletePost(const string username,int pos){
    
    if (posts->get(pos).getUsername() == username) {
        this->deletePost(pos);
        return true;
    }
    return false;
}

ArrayList<WallPost> * Wall::returnPosts(){
    return posts;
}

void Wall::readWall(string text) {
    
    string delimiter = "********************** \n\n";
    size_t pos = 0;
    string token;
    while((pos = text.find(delimiter)) != string::npos) {
        
        token = text.substr(0, pos);
        
        //get username
        string user_delimiter = " wrote: \n";
        size_t pos2 = token.find(user_delimiter);
        string username = text.substr(0, pos2);

        token.erase(0, pos2 + user_delimiter.length());
        
        //get post
        string post_delimiter = "\nat ";
        pos2 = token.find(post_delimiter);
        string post = token.substr(0, pos2);
        token.erase(0, pos2 + post_delimiter.length());
        
        string commentsplitter = "\n----------------------\n";
        pos2 = token.find(commentsplitter);
        
        //convert string to time object
        struct tm tm;
        strptime(token.substr(0, pos2).c_str(), "%H:%M on %m-%d-%Y", &tm);
        time_t t = mktime(&tm);
        
        commentsplitter = "----------------------\n";
        pos2 = token.find(commentsplitter);
        token.erase(0, pos2 + commentsplitter.length());
        
        WallPost * x = new WallPost(post, t, username);
        
        size_t cp = 0;
        string cs;
        while ((cp = token.find(commentsplitter)) != string::npos) {
            
            string ud = " responded: \n";
            size_t p2 = token.find(ud);
            string un = text.substr(0, p2);
            
            token.erase(0, p2 + ud.length());
            
            string pd = "\nat ";
            p2 = token.find(pd);
            string p = token.substr(0, p2);
            token.erase(0, p2 + pd.length());
            
            string ncs = "\n----------------------\n";
            p2 = token.find(ncs);
            
            struct tm tmm;
            strptime(token.substr(0, p2).c_str(), "%H:%M on %m-%d-%Y", &tmm);
            time_t tt = mktime(&tmm);
            
            x->addComment(un, p, tt);
            
            token.erase(0, p2 + ncs.length());
        }
        
        this->addPost(*x);
        
        text.erase(0, pos + delimiter.length());
        
    }
    return;
}