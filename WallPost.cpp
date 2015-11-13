//
//  WallPost.cpp
//  CS130A-1
//
//  Created by Brent Kirkland and Taylor Getty on 10/6/15.
//

#include "WallPost.hpp"

string WallPost::getPost() const{
    return post;
}

time_t WallPost::getTime() const{
    return timeNow;
}

string WallPost::getUsername() const{
    return username;
}

void WallPost::setPost(string post) {
    post = post;
}

void WallPost::setTime(){
    timeNow = time(&timeNow);
}

void WallPost::setUsername(string username) {
    username = username;
}

const string WallPost::getEntirePost() const{
    char buff [20];
    string username = "";
    strftime(buff, 20, "%H:%M on %m-%d-%Y", localtime(&timeNow));
    string x = this->username + " wrote: \n" + post + "\nat " + buff +"\n";
    return x;
}

bool operator==(const WallPost& left, const WallPost& right){
    return (left.getPost() == right.getPost() && left.getTime() == right.getTime() && left.getUsername() == right.getUsername());
}