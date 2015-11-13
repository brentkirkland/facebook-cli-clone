//
//  UserNetwork.cpp
//  CS130A-1
//
//  Created by Brent Kirkland on 10/7/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#include "UserNetwork.hpp"


void UserNetwork:: addUser(User u)
{
//    Node<User> *tmp = this->userList->getHead();
//    
//    if (tmp == NULL){
//        this->userList->addTail(u);
//    }
//    else if (!doesUserExist(u)){
//            this->userList->addTail(u);
//    }
    this->userList->insert(0, u);

}

bool UserNetwork::doesUserExist(User u){
    
//    Node<User> *tmp = this->userList->getHead();
//    
//    while(tmp != NULL){
//        if (tmp->data.getUsername() == u.getUsername()){
//            return 1;
//        }
//        tmp = tmp->next;
//    }
//    return 0;
    
    int pos = userList->find(u);
    
    
    if (pos > -1) {
        return true;
    } else {
        return false;
    }
    
}

bool UserNetwork::checkUser(string username, string password){
//    Node<User> *tmp = this->userList->getHead();
//    
//    while(tmp != NULL){
//        if (tmp->data.getUsername() == username
//            && tmp->data.getPassword() == password){
//            return 1;
//        }
//        tmp = tmp->next;
//    }
//    return 0;
    
    for (int i = 0; i < userList->getSize(); i++) {
        //User * tmp = userList->get(i);
        if (userList->get(i).getUsername() == username && userList->get(i).getPassword() == password)
        {
            return 1;
        }
    }
    return 0;
    
}

const User & UserNetwork::getUser(string username, string password) const{
//    Node<User> *tmp = this->userList->getHead();
//    
//    while(tmp != NULL){
//        if (tmp->data.getUsername() == username
//            && tmp->data.getPassword() == password){
//            return &tmp->data;
//        }
//        tmp = tmp->next;
//    }
//    return &tmp->data;
    
    for (int i = 0; i < userList->getSize(); i++) {
        //User tmp = userList->get(i);
        if (userList->get(i).getUsername() == username && userList->get(i).getPassword() == password)
        {
            
            return userList->get(i);
        }
    }
    throw std::invalid_argument("Invalid arguments");
}

void UserNetwork:: removeUser(User u)
{
    
    //std::cout << "found at: " << this->userList->find(u) << std::endl;
    this->userList->remove(this->userList->find(u));
    //this->userList->remove(u);
}

void UserNetwork:: writeList(string filename)
{
    std::ofstream myfile (filename.c_str());
//    Node<User> *tmp = userList->getHead();
//    while (tmp != NULL)
//    {
//        myfile << tmp->data.userInfo() + "&&&&&&&&&&&&&&&&&&&&&&&&&&& \n" << std::endl;
//        tmp = tmp->next;
//        
//    }
//    myfile.close();
    
    for (int i = 0; i < userList->getSize(); i++) {
        //User tmp = userList->get(i);
    
        
        User z = userList->get(i);
        
        
        //std::cout << "\nUSERINFO" << i;
        //std::cout << userList->get(i).userInfo() << std::endl;
        
        string friends = "friends: \n";
        
        string pending = "pending: \n";
//        
        for (int j = 0; j < friendgraph->returnListOfFriends(z.getUsername()).getSize(); j++) {
            friends = friends + friendgraph->returnListOfFriends(z.getUsername()).get(j) + "\n";
        }
        
        for (int k = 0; k < friendgraph->returnListOfPendingFriends(z.getUsername()).getSize(); k++) {
            pending = pending + friendgraph->returnListOfPendingFriends(z.getUsername()).get(k) + "\n";
        }
        
        myfile << userList->get(i).userInfo()  + "&&&&&&&&&&&&&&&&&&&&&&&&&&& \n" + friends + "((((((((((((())\n" + pending + "*$$$$$$$$$$$$$$$*" << std::endl;
    }
    myfile.close();
    
}

void UserNetwork::readEntireFile(string filename)
{
    std::ifstream infile(filename.c_str());
    std::string str((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    string delimiter = "&&&&&&&&&&&&&&&&&&&&&&&&&&& \nfriends: \n";
    size_t pos = 0;
    string user;
    string friends;
    while((pos = str.find(delimiter)) != string::npos){
        user = str.substr(0,pos);
        
        User * u = new User(user);
        
        this->friendgraph->addVertice(u->getUsername());
        this->userList->insert(0, *u);
        
        str.erase(0, pos + delimiter.length());
        
        delimiter = "((((((((((((())\npending: \n";
        
        pos = str.find(delimiter);
        
        friends = str.substr(0, pos);
        
        string d = "\n";
        string f;
        size_t pos2 = 0;
        while ((pos2 = str.find(d)) != string::npos) {
                
            f = str.substr(0 , pos2);
                
            if (f == "((((((((((((())") {
                    break;
            }
                
            this->friendgraph->addFriend(u->getUsername(), f);
                
            str.erase(0, pos2 + d.length());

            
        }
        
        pos = str.find(delimiter);
    
        str.erase(0, pos + delimiter.length());
        
        delimiter = "*$$$$$$$$$$$$$$$*\n";
        
        pos = str.find(delimiter);
        
        friends = str.substr(0, pos);
        
        d = "\n";
        f = "";
        pos2 = 0;
        while ((pos2 = str.find(d)) != string::npos) {
            
            f = str.substr(0 , pos2);
            
            if (f == "*$$$$$$$$$$$$$$$*") {
                break;
            }
            
            this->friendgraph->addPending(f, u->getUsername());
            
            str.erase(0, pos2 + d.length());
            
        }
        
        pos = str.find(delimiter);
        
        str.erase(0, pos + delimiter.length());
        
        delimiter = "&&&&&&&&&&&&&&&&&&&&&&&&&&& \nfriends: \n";
        
    }
    
    
    
    infile.close();
    
}
