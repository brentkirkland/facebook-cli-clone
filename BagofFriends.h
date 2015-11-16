//
//  BagofFriends.h
//  CS130A_Project_2
//
//  Created by Brent Kirkland on 10/26/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#ifndef BagofFriends_h
#define BagofFriends_h

#include "ArrayList.h"
#include "LinkedList.hpp"
#include <stdio.h>
#include "User.hpp"
#include <stdexcept>

class BagofFriends {
public:
    
    ArrayList<LinkedList<string> > * friendgraph;
    ArrayList<LinkedList<string> > * pendingfriendgraph;
    
    BagofFriends(){
        friendgraph = new ArrayList<LinkedList<string> >();
        pendingfriendgraph = new ArrayList<LinkedList<string> >();
    }
    
    //pending is marked by when
    
    //this is the inner edge
    void addVertice(string username);
    void removeVertice(string username);
    
    void addPending(string requestor, string requestee);
    void confirmPending(string requestor, string requestee);
    void deletePending(string requestor, string requestee);
    void addFriend(string requestor, string requestee);
    void deleteFriend(string requestor, string requestee);
    
    void deletePendingAndAddFriend(string requestor, string requestee);
    
    LinkedList<string> returnListOfFriends(string username);
    LinkedList<string> returnListOfPendingFriends(string username);
    
    int getGraphSize();
    
};

bool operator==(BagofFriends& left, BagofFriends& right);

bool operator==(LinkedList<string>& left, LinkedList<string>& right);


#endif /* BagofFriends_h */
