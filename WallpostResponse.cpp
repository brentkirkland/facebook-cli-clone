//
//  WallpostResponse.cpp
//  CS130A_Project_3
//
//  Created by Brent Kirkland on 11/12/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#include "WallpostResponse.hpp"

string WallpostResponse::getComment() const {
    return comment;
}
time_t WallpostResponse::getTime() const {
    return timeNow;
}
string WallpostResponse::getUsername() const {
    return username;
}
void WallpostResponse::setComment(string comment) {
    comment = comment;
}
void WallpostResponse::setTime(){
    timeNow = time(&timeNow);
}
void WallpostResponse::setUsername(string username) {
    username = username;
}
const string WallpostResponse::getEntirePost() const {
    char buff [20];
    string username = "";
    strftime(buff, 20, "%H:%M on %m-%d-%Y", localtime(&timeNow));
    string x = this->username + " responded: \n" + comment + "\nat " + buff +"\n";
    return x;
}

bool operator==(const WallpostResponse& left, const WallpostResponse& right){
    return (left.getComment() == right.getComment() && left.getTime() == right.getTime() && left.getUsername() == right.getUsername());
}