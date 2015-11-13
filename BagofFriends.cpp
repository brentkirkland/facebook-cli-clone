//
//  BagofFriends.cpp
//  CS130A_Project_2
//
//  Created by Brent Kirkland and Taylor Getty on 11/1/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#include <stdio.h>
#include "BagofFriends.h"

void BagofFriends::addVertice(string username){
    
    //this needs to be done evertime a user is created
    //the first position is always the user
    
//    if (friendgraph->getSize() < 1) {
//
//    }
    
    for (int i = 0; i < friendgraph->getSize(); i++) {
        if (friendgraph->get(i).get(0) == username) {
            return;
        }
    }
    
    LinkedList<string> inner = *new LinkedList<string>();
    inner.insert(0, username);
    
    friendgraph->insert(0, inner);
    //string x = friendgraph->get(0).get(0);
    
    pendingfriendgraph->insert(0, inner);
    //string y = friendgraph->get(0).get(0);
    
}

void BagofFriends::removeVertice(string username){
    
    //this needs to be done evertime a user is deleted
    
    for (int i = 0; i < friendgraph->getSize(); i++) {
        if (friendgraph->get(i).get(0) == username) {
            friendgraph->remove(i);
        }
        if (pendingfriendgraph->get(i).get(0) == username){
            pendingfriendgraph->remove(i);
        }
    }
    
    
}

void BagofFriends::addPending(string requestor, string requestee){
    
    for (int i = 0; i < pendingfriendgraph->getSize(); i++) {
//        if (pendingfriendgraph->get(i).get(0) == requestor){
//            LinkedList<string> inner = pendingfriendgraph->get(i);
//            
//            if (inner.find(requestee) < 0) {
//            inner.insert(1, requestee);
//            pendingfriendgraph->set(i, inner);
//            }
//        } else
            if (pendingfriendgraph->get(i).get(0) == requestee){
            LinkedList<string> inner = pendingfriendgraph->get(i);
            if (inner.find(requestor) < 0) {
            inner.insert(1, requestor);
            pendingfriendgraph->set(i, inner);
            }
        }
    }
    
}

void BagofFriends::confirmPending(string requestor, string requestee){
    
    //bob sends brent a friend request
    //brent confirms friend request
    //bob is requestor
    //brent is requestee
    
    //remove from pending graph
    this->deletePending(requestor, requestee);

    //add to friend graph
    
    this->addFriend(requestor, requestee);
    this->addFriend(requestee, requestor);
    //so
    
}

void BagofFriends::deletePending(string requestor, string requestee){
    for (int i = 0; i < pendingfriendgraph->getSize(); i++) {
//        if (pendingfriendgraph->get(i).get(0) == requestor){
//            LinkedList<string> inner = pendingfriendgraph->get(i);
//            inner.remove(inner.find(requestee));
//            pendingfriendgraph->set(i, inner);
//        } else
        
            if (pendingfriendgraph->get(i).get(0) == requestee){
            LinkedList<string> inner = pendingfriendgraph->get(i);
            inner.remove(inner.find(requestor));
            pendingfriendgraph->set(i, inner);
        }
    }
    
}

void BagofFriends::addFriend(string requestor, string requestee){
    
    if (requestor != requestee) {
    for (int i = 0; i < friendgraph->getSize(); i++) {
        
        if (friendgraph->get(i).get(0) == requestor){
            LinkedList<string> inner = friendgraph->get(i);
            
            if (inner.find(requestee) < 0) {
                inner.insert(1, requestee);
                friendgraph->set(i, inner);
            }
            
            
        } else if (friendgraph->get(i).get(0) == requestee){
            LinkedList<string> inner = friendgraph->get(i);
            if (inner.find(requestee) < 0) {
                inner.insert(1, requestor);
                friendgraph->set(i, inner);
            }
        }
    }
    }

    
}

void BagofFriends::deleteFriend(string requestor, string requestee){
    
    for (int i = 0; i < friendgraph->getSize(); i++) {
        if (friendgraph->get(i).get(0) == requestor){
            LinkedList<string> inner = friendgraph->get(i);
            inner.remove(inner.find(requestee));
            friendgraph->set(i, inner);
        } else if (friendgraph->get(i).get(0) == requestee){
            LinkedList<string> inner = friendgraph->get(i);
            inner.remove(inner.find(requestor));
            friendgraph->set(i, inner);
        }
    }
    
}

LinkedList<string> BagofFriends::returnListOfFriends(string username){
    
    int s = friendgraph->getSize();
    string hi;
    
    for (int i = 0; i < s; i++) {
        hi = friendgraph->get(i).get(0);
        
        //std::cout << "Hello: " << hi << std::endl;
        if (hi == username){
            LinkedList<string> inner = friendgraph->get(i);
            //std::cout << "return" << std::endl;
            return inner;
        }
    }
    
    throw std::invalid_argument("Invalid argument");
    
}

LinkedList<string> BagofFriends::returnListOfPendingFriends(string username){
    
    int s = pendingfriendgraph->getSize();
    string hi;
    
    for (int i = 0; i < s; i++) {
        hi = pendingfriendgraph->get(i).get(0);
        
        //std::cout << "Hello: " << hi << std::endl;
        if (hi == username){
            LinkedList<string> inner = pendingfriendgraph->get(i);
            //std::cout << "size: !" << inner.getSize()
            //<< username << std::endl;
            return inner;
        }
    }
    
    throw std::invalid_argument("Invalid argument");
    
}

int BagofFriends::getGraphSize(){
    return friendgraph->getSize();
}

bool operator==(BagofFriends& left, BagofFriends& right) {
    
    bool x = true;
    
    if (left.friendgraph->getSize() == right.friendgraph->getSize()) {
        for (int i = 0; i < left.friendgraph->getSize(); i++) {
            
            LinkedList<string> lefty = left.friendgraph->get(i);
            LinkedList<string> righty = right.friendgraph->get(i);
            
            for (int i = 0; i < lefty.getSize(); i++) {
                if (lefty.get(i) != righty.get(i)) {
                    x = false;
                    return x;
                }
            }
            
        }
    } else {
        return false;
    }
    if (left.pendingfriendgraph->getSize() == right.pendingfriendgraph->getSize()) {
        for (int i = 0; i < left.pendingfriendgraph->getSize(); i++) {
            
            LinkedList<string> lefty = left.pendingfriendgraph->get(i);
            LinkedList<string> righty = right.pendingfriendgraph->get(i);
            
            for (int i = 0; i < lefty.getSize(); i++) {
                if (lefty.get(i) != righty.get(i)) {
                    x = false;
                    return x;
                }
            }
            
        }
    } else {
        x = false;
        return x;
    }
    return x;
}

bool operator==(LinkedList<string>& left, LinkedList<string>& right){
    
    if (left.getSize() == right.getSize()) {
        for (int i =0; i < left.getSize(); i++) {
            if (left.get(i) != right.get(i)){
                return false;
            }
        }
    } else {
        return false;
    }
    
    return true;
    
}