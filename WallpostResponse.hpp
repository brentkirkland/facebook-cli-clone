//
//  WallpostResponse.hpp
//  CS130A_Project_3
//
//  Created by Brent Kirkland on 11/12/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#ifndef WallpostResponse_hpp
#define WallpostResponse_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>

using std::string;

class WallpostResponse {
private:
    
    string comment;
    time_t timeNow;
    string username;
    
public:
    
    WallpostResponse(): comment(string()), timeNow(time(&timeNow)), username(string()) {};
    WallpostResponse(string c, time_t t, string u): comment(c), timeNow(t), username(u) {};
    WallpostResponse(string c, string u): comment(c), timeNow(time(&timeNow)), username(u) {};
    WallpostResponse(const WallpostResponse& other): comment(other.comment), timeNow(other.timeNow), username(other.username) {};
    
    string getComment() const;
    time_t getTime() const;
    string getUsername() const;
    
    void setComment(string comment);
    void setTime();
    void setUsername(string username);
    
    const string getEntirePost() const;
    
};


#endif /* WallpostResponse_hpp */

