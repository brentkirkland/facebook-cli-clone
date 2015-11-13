//
//  UserNetwork.hpp
//  CS130A-1
//
//  Created by Brent Kirkland on 10/7/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#ifndef UserNetwork_hpp
#define UserNetwork_hpp

#include <fstream>
#include <stdio.h>
#include "DoublyLinkedList.h"
#include "BagofFriends.h"
#include "User.hpp"
#include <sstream>

class UserNetwork {
private:
    
public:
    BagofFriends *friendgraph;
    ArrayList<User> *userList;
    UserNetwork(): userList(new ArrayList<User>()), friendgraph(new BagofFriends()) {};
    
    //friend graph
    
    
    ~UserNetwork()
    {
        delete userList;
    };

    void addUser(User u);
    void removeUser(User u);
    
    bool doesUserExist(User u);
    bool checkUser(string username, string password);
    
    const User & getUser(string username, string password) const;
    
    void writeList(string filename);
    void readEntireFile(string filename);
};



#endif /* UserNetwork_hpp */
