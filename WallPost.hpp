//
//  WallPost.hpp
//  CS130A-1
//
//  Created by Brent Kirkland and Taylor Getty on 10/6/15.
//

#ifndef WallPost_hpp
#define WallPost_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>
#include "ArrayList.h"
#include "WallpostResponse.hpp"

using std::string;

class WallPost {
private:
    string post;
    time_t timeNow;
    string username;
    ArrayList<WallpostResponse> *comments;
    
public:
    
    WallPost(): post(string()), timeNow(time(&timeNow)), username(string()), comments(new ArrayList<WallpostResponse>()) {};
    
    WallPost(string p, string u)
        :post(p), timeNow(time(&timeNow)), username(u), comments(new ArrayList<WallpostResponse>()) {};
    
    WallPost(string p, time_t t, string u)
    :post(p), timeNow(t), username(u), comments(new ArrayList<WallpostResponse>()) {};
    
    WallPost(const WallPost& other): post(other.post), timeNow(other.timeNow), username(other.username), comments(new ArrayList<WallpostResponse>(*other.comments)) {};
    
    string getPost() const;
    time_t getTime() const;
    string getUsername() const;
    ArrayList<WallpostResponse> * getWallpostResponse();
    
    void setPost(string post);
    void setTime();
    void setUsername(string username);
    
    void addComment(string username, string comment);
    void addComment(string username, string comment, time_t time);
    
    const string getEntirePost() const;
    
    void parseString();
    
};

bool operator==(const WallPost& left, const WallPost& right);

#endif /* WallPost_hpp */
