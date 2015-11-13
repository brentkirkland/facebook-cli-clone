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

using std::string;

class WallPost {
private:
    string post;
    time_t timeNow;
    string username;
    
public:
    
    WallPost(): post(string()), timeNow(time(&timeNow)), username(string()) {};
    
    WallPost(string p, string u)
        :post(p), timeNow(time(&timeNow)), username(u) {};
    
    WallPost(string p, time_t t, string u)
    :post(p), timeNow(t), username(u) {};
    
    string getPost() const;
    time_t getTime() const;
    string getUsername() const;
    
    void setPost(string post);
    void setTime();
    void setUsername(string username);
    
    const string getEntirePost() const;
    
    void parseString();
    
};

bool operator==(const WallPost& left, const WallPost& right);

#endif /* WallPost_hpp */
