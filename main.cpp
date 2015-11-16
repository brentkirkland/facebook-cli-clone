//
//  main.m
//  CS130A-1
//
//  Created by Brent Kirkland and Taylor Getty on 10/6/15.
//
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <limits>
#include <string>
#include <sstream>

using namespace std;


#include "DoublyLinkedList.h"
#include "LinkedList.hpp"
#include "ArrayList.h"
#include "WallPost.hpp"
#include "Wall.hpp"
#include "User.hpp"
#include "UserNetwork.hpp"


int main(int argc, const char * argv[]) {
    
//    List<int> * test = new LinkedList<int>();
//    List<int> * hi = new ArrayList<int>();
//    
//    const clock_t a2000 = clock();
//    hi->insert(0, 0);
//    hi->insert(1, 1);
//    hi->insert(2, 2);
//    for(int i = 2; i < 2000; i++){
//        int x = i / 2;
//        hi->insert(x, i);
//    }
//    std::cout << "Array List time of 2k: " << float( clock () - a2000 ) /  CLOCKS_PER_SEC << endl;
//    const clock_t l2000 = clock();
//    test->insert(0, 0);
//    test->insert(1, 1);
//    test->insert(2, 2);
//    for(int i = 2; i < 2000; i++){
//        int x = i / 2;
//        test->insert(x, i);
//    }
//    std::cout << "Linked List time of 2k: " << float( clock () - l2000 ) /  CLOCKS_PER_SEC << endl;
//    
//    delete test;
//    test = NULL;
//    delete hi;
//    hi = NULL;
//    
//    List<int> * test1 = new LinkedList<int>();
//    List<int> * hi1 = new ArrayList<int>();
//    
//    const clock_t a4000 = clock();
//    hi1->insert(0, 0);
//    hi1->insert(1, 1);
//    for(int i = 2; i < 4000; i++){
//        hi1->insert(i/2, i);
//    }
//    std::cout << "Array List time of 4k: " << float( clock () - a4000 ) /  CLOCKS_PER_SEC << endl;
//    const clock_t l4000 = clock();
//    test1->insert(0, 0);
//    test1->insert(1, 1);
//    for(int i = 2; i < 4000; i++){
//        test1->insert(i/2, i);
//    }
//    std::cout << "Linked List time of 4k: " << float( clock () - l4000 ) /  CLOCKS_PER_SEC << endl;
//    
//    delete test1;
//    test1 = NULL;
//    delete hi1;
//    hi1 = NULL;
//    
//    List<int> * test2 = new LinkedList<int>();
//    List<int> * hi2 = new ArrayList<int>();
//    
//    const clock_t a8000 = clock();
//    hi2->insert(0, 0);
//    hi2->insert(1, 1);
//    for(int i = 2; i < 8000; i++){
//        hi2->insert(i/2, i);
//    }
//    std::cout << "Array List time of 8k: " << float( clock () - a8000 ) /  CLOCKS_PER_SEC << endl;
//    const clock_t l8000 = clock();
//    test2->insert(0, 0);
//    test2->insert(1, 1);
//    for(int i = 2; i < 8000; i++){
//        test2->insert(i/2, i);
//    }
//    std::cout << "Linked List time of 8k: " << float( clock () - l8000 ) /  CLOCKS_PER_SEC << endl;
//    
//    delete test2;
//    test2 = NULL;
//    delete hi2;
//    hi2 = NULL;
//    
//    List<int> * test3 = new LinkedList<int>();
//    List<int> * hi3 = new ArrayList<int>();
//    
//    const clock_t a10000 = clock();
//    hi3->insert(0, 0);
//    hi3->insert(1, 1);
//    for(int i = 2; i < 10000; i++){
//        hi3->insert(i/2, i);
//    }
//    std::cout << "Array List time of 10k: " << float( clock () - a10000 ) /  CLOCKS_PER_SEC << endl;
//    const clock_t l10000 = clock();
//    
//    test3->insert(0, 0);
//    test3->insert(1, 1);
//    for(int i = 2; i < 10000; i++){
//        test3->insert(i/2, i);
//    }
//    std::cout << "Linked List time of 10k: " << float( clock () - l10000 ) /  CLOCKS_PER_SEC << endl;
//    
//    delete test3;
//    test3 = NULL;
//    delete hi3;
//    hi3 = NULL;
//    
//
    

    
    //
    start:
    //create a list of users
    UserNetwork *dpn = new UserNetwork();
    //read in users
    dpn->readEntireFile("users.txt");
    
    // we don't want 10k users everytime program starts
    if (dpn->friendgraph->getGraphSize() < 100) {
        
        User uuu;
        for (int users = 0; users < 10000; users++) {
        
        
            string username = ToString(users);
            string password = ToString(users);
            string city = ToString(users);
            uuu = *new User(username, password, city);
        
            dpn->friendgraph->addVertice(username);
            
            
            string welcome = "Welcome user: " + ToString(users);
            
            uuu.addPost(*new WallPost(welcome, username));
            dpn->addUser(uuu);
        }
        
        for (int user = 0; user < dpn->friendgraph->getGraphSize(); user++) {
            
            LinkedList<string> us = dpn->friendgraph->friendgraph->get(user);
            string usertoaddto = us.get(0);
            //int randomcount = 0;
            
            while (us.getSize() < 70) {
                int random = rand() % 10000;
                
                us = dpn->friendgraph->friendgraph->get(user);
                
                LinkedList<string> useradding = dpn->friendgraph->friendgraph->get(random);
//                
//                LinkedList<string> tmp = dpn->friendgraph->friendgraph->get(user);
//                
                if (useradding.getSize() < 100 && useradding.get(0) != usertoaddto) {
//                    randomcount++;
                    dpn->friendgraph->addFriend(usertoaddto, useradding.get(0));
                    cout<< "Current adding: " + usertoaddto + " to: " + useradding.get(0) << endl;
                }
                
                
                
            }
            
        }
        
    }
    dpn->writeList("users.txt");
    
    //to hold value of current user
    User current;
    bool run = true;
    string x = "start";
    
    std::cout << "      WELCOME TO THE      \n";
    std::cout << "--------------------------\n";
    std::cout << "╔╦╗┌─┐┬    ╔═╗┬  ┌─┐┬ ┬┌─┐\n ║║├┤ │    ╠═╝│  ├─┤└┬┘├─┤\n═╩╝└─┘┴─┘  ╩  ┴─┘┴ ┴ ┴ ┴ ┴\n";
    std::cout << "--------------------------\n";
    std::cout << "          NETWORK         \n";
    
    std::cout << "\nEnter number to navigate to that page:\n> 1 - CREATE\n> 2 - LOGIN\n> 3 - QUIT" << endl;
    int input;
    cin >> input;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    while(run){
        
        switch (input) {
            //create
            case 1:
            {
                std::cout << "Enter a usename: ";
                string username;
                getline(cin, username);
                std::cout << "Enter a password: ";
                string password;
                getline(cin, password);
                std::cout << "Enter the street you live on in Isla Vista: ";
                string city;
                getline(cin, city);
                
                current = *new User(username, password, city);
                
                if (dpn->doesUserExist(current)){
                    std::cout << "\nUsername exists. Please choose a new username.\n\n";
                } else {
                    dpn->friendgraph->addVertice(current.getUsername());
                    dpn->addUser(current);
                    //dpn->writeList("users.txt");
                    
                    std::cout << "\nSuccessful user creation!\n";
                    goto start;
                }
        
                break;
            }
            case 2:
            {
                std::cout << "Enter a usename: ";
                string username;
                getline(cin, username);
                std::cout << "Enter a password: ";
                string password;
                getline(cin, password);
                
                if (dpn->checkUser(username, password)) {
                    current = dpn->getUser(username, password);
                        std::cout << "\nWelcome " + current.getUsername() + "!\n";
                        input = 4;
                
                    } else {
                        std::cout << "\nInvalid login. Try again.\n";

                }
                
                break;
            }
            case 3:
            {
                cout << "Saving file..." << endl;
                dpn->writeList("users.txt");
                run = false;
                break;
            }
            //logged in user
            case 4:
            {
                std::cout<< "\n-------- " + current.getUsername() + "'s profile --------\n\n";
                
                if (dpn->friendgraph->returnListOfPendingFriends(current.getUsername()).getSize() > 1) {
                    std::cout << "You have " << ToString(dpn->friendgraph->returnListOfPendingFriends(current.getUsername()).getSize() - 1) << " pending friend requestion \n";
                }
                
                if (current.getWall() != ""){
                    std::cout << current.getWallForCommandLine();
                } else {
                    std::cout << "\nOops! You have no wallpost :(\n";
                }
                //std::cout << "\nEnter desired command number:\n> 1 - ADD A POST\n> 2 - EDIT STUFF\n> 3 - LOGOUT\n> 3 - LOGOUT\n> 4 - SEARCH FOR USERS\n> 5 - VIEW/ACCEPT PENDING FRIEND REQUEST"<< endl;
                std::cout << "\nEnter desired command number:\n> 1 - ADD A POST\n> 2 - DELETE A POST\n> 3 - ADD A REPONSE\n> 4 - DELETE A RESPONSE\n> 5 - SEARCH FOR USERS\n> 6 - VIEW/ACCEPT PENDING FRIEND REQUEST\n> 7 - EDIT PROFILE\n> 8 - LOGOUT \n> 9 - FIND THE DEGREE AND PATH TO A SPECIFIC USER\n> 10 - FIND ALL PEOPLE WITH 3 DEGREE OF SEPERATION\n\n(If you don't see the response from a previous command, be sure to scroll up as the menu resets after every command is complete.)\n"<< endl;
                
                
                int profile_input;
                
                cin >> profile_input;
                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                
                switch (profile_input) {
                    //add post
                    case 1:
                    {
                        string post;
                        std::cout << "Type your post and hit enter.\n";
                        getline(cin, post);
                        
                        current.addPost(*new WallPost(post, current.getUsername()));
                                    
                        //dpn->writeList("users.txt");
                        break;
                    }
                    //edit user (not there yet)
                    case 7:
                    {
                        int edit_input;
                        
                        std::cout << "\nEnter the number corresponding with the feild you'd like to edit:\n> 1 - PASSWORD\n> 2 - CITY\n> 3 - DELETE A POST\n> 4 - VIEW/DELETE FRIENDS\n> 5 - DELETE ACCOUNT\n> 6 - CANCEL" << endl;
                        
                        cin >> edit_input;
                        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                        
                        switch (edit_input) {
                            case 10:
                            {
                                //User tmp = current;
                                
                                //dpn->writeList("users.txt");
                                
                                dpn->removeUser(current);
                                
                                string username;
                                std::cout << "Enter a new username (you will lose your friends tho\n";
                                getline(cin, username);
                                current.editUsername(username);
                                
                                
                                dpn->addUser(current);
                                
                                //dpn->writeList("users.txt");
                                
                                break;
                            }
                            case 1:
                            {
                                
                                //dpn->friendgraph->returnListOfFriends(current.getUsername())
                                
                                dpn->removeUser(current);
                                string password;
                                std::cout << "Enter a new password\n";
                                getline(cin, password);
                                current.editPassword(password);
                                dpn->addUser(current);
                                //dpn->writeList("users.txt");
                                break;
                            }
                            case 2:
                            {
                                dpn->removeUser(current);
                                string city;
                                std::cout << "Enter a new city\n";
                                getline(cin, city);
                                current.editCity(city);
                                dpn->addUser(current);
                                //dpn->writeList("users.txt");
                                break;
                            }
                            case 3:
                            {
                                dpn->removeUser(current);
                                int postnumber;
                                std::cout << "Enter a post number\n";
                                cin >> postnumber;
                                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                                current.deletePost(postnumber - 1);
                                dpn->addUser(current);
                                //dpn->writeList("users.txt");
                                
                                break;
                            }
                            case 4:
                            {
                                string x = "";
                    
                                LinkedList<string> friends = dpn->friendgraph->returnListOfFriends(current.getUsername());
                                int z = friends.getSize();
                                for (int i = 1; i < z; i++) {
                                    x = x + ToString(i) + ": " + friends.get(i) + "\n";
                                }
                                
                                if (x == ""){
                                    std:: cout << "\nOops you have no friends! Search and add friends!\n";
                                } else {
                                    std::cout << x;
                                    
                                    std::cout << "Enter 0 to go back or the corresponding friend number to delete the friend:\n";
                                    
                                    int friendnumber;
                                    cin >> friendnumber;
                                    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                                    
                                    if (friendnumber > 0) {
                                        dpn->friendgraph->deleteFriend(current.getUsername(), friends.get(friendnumber));
                                        //dpn->writeList("users.txt");
                                    }
                                    break;
                                    
                                }
                                
                            }
                                
                                break;
                            case 5:
                            {
                                std::cout << "Are you sure?(YES or NO) \n";
                                
                                string answer;
                                
                                getline(cin, answer);
                                
                                if (answer == "YES"){
                                    edit_input = 9;
                                } else {
                                    break;
                                }
                    
                            }
                            case 9:
                            {
                                
                                
                                for (int i = 1; i < dpn->friendgraph->returnListOfFriends(current.getUsername()).getSize(); i++) {
                                    
                                    string user_to_delete = dpn->friendgraph->returnListOfFriends(current.getUsername()).get(i);
                                    
                                    dpn->friendgraph->deleteFriend(current.getUsername(), user_to_delete);
                                    
                                }
                                
                                //current user lives in different user pending list
                                //delete current user from those list
                                
                                for (int i = 0; i < dpn->friendgraph->pendingfriendgraph->getSize(); i++) {
                                    
                                    string user_to_delete = dpn->friendgraph->pendingfriendgraph->get(i).get(0);
                                    
                                    if (user_to_delete != current.getUsername()) {
                                        dpn->friendgraph->deletePending(current.getUsername(), user_to_delete);

                                    }

                                }
                                
                                dpn->removeUser(current);
                                
                                dpn->friendgraph->removeVertice(current.getUsername());
                                dpn->writeList("users.txt");
                                std::cout << "\nAccount deleted. Sorry to see you go." << endl;
                                goto start;
                                break;
                            }
                        }
                        
                        break;
                    }
                    case 8:
                    {
                        std::cout << "\nYou have been successfully logged out.\n" << endl;
                        dpn->writeList("users.txt");
                        goto start;
                        break;
                    }
                    //delete account
                    case 5:
                    {
                        std::cout << "\nSearch for a username: " << endl;
                        string query;
                        getline(cin, query);
                    
                        
                        string x = "";
                        for (int i = 0; i < dpn->friendgraph->friendgraph->getSize(); i++) {
                            if (dpn->friendgraph->friendgraph->get(i).get(0).find(query) != std::string::npos
                                && dpn->friendgraph->friendgraph->get(i).get(0) != current.getUsername()) {
                                
                                  x = x + ToString(i) + ": " + dpn->friendgraph->friendgraph->get(i).get(0) + "\n";
                    
                            
                            }
                        }
                        
                        
                        if (x == ""){
                            std:: cout << "\nOops no users found\n";
                        } else {
                            std::cout << x;
                            
                            std::cout << "Enter -1 to go back or the corresponding friend number to view profile:\n";
                            
                            int personnumber;
                            cin >> personnumber;
                            cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                            
                            if (personnumber >= 0) {
                                //Goto profile
                            
                                //if they are friends
                            
                                string selected = dpn->friendgraph->friendgraph->get(personnumber).get(0);
                                string selectedusername;
                                User person;
                                
                                for (int i = 0; i < dpn->userList->getSize(); i++) {
                                    if (dpn->userList->get(i).getUsername() == selected){
                                        person = dpn->userList->get(i);
                                        selectedusername = person.getUsername();
                                        break;
                                    }
                                }
                                
                                
                                
                                if (dpn->friendgraph->returnListOfFriends(current.getUsername()).find(selectedusername) > 0) {
                                    if (person == current) {
                                        continue;
                                    } else {
                                        friendprof:
                                        std::cout<< "\n-------- " + person.getUsername() + "'s profile --------\n\n";
                                        
                                        if (person.getWall() != ""){
                                            std::cout << person.getWallForCommandLine();
                                        } else {
                                            std::cout << "\nOops! There are no wallpost :(\n";
                                        }
                                        
                                        cout << "\nEnter desired command number:\n> 1 - ADD POST\n> 2 - DELETE ONE OF YOUR POST\n> 3 - ADD A REPONSE\n> 4 - DELETE A RESPONSE\n> 5 - DELETE FRIEND\n> 6 - BACK TO YOUR PROFILE"<< endl;
                                        
                                        int friendprofile;
                                        
                                        cin >> friendprofile;
                                        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                                        
                                        switch (friendprofile) {
                                            //Add WallPost
                                            case 1:
                                            {
                                                string post;
                                                std::cout << "Type your post and hit enter.\n";
                                                getline(cin, post);
                                                
                                                person.addPost(*new WallPost(post, current.getUsername()));
                                                
                                                //dpn->writeList("users.txt");
                                                goto friendprof;
                                            }
                                            //DELETE ONE OF YOUR POST
                                            case 2:
                                            {
                                                int postdelete;
                                                cin >> postdelete;
                                                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                                                
                                                if(person.getWallPointer()->deletePost(current.getUsername(), postdelete - 1)){
                                                    //dpn->writeList("users.txt");
                                                    cout << "\nPost deleted.\n";
                                                } else{
                                                    cout << "\nPost does not belong to you.\n";
                                                }
                                        
                                                goto friendprof;
                                                
                                            }
                                            //Add coment
                                            case 3:
                                            {
                                                int pcn;
                                                std::cout << "Enter the post number you'd like to respond to.\n";
                                                cin >> pcn;
                                                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                                                
                                                WallPost x = person.getWallPointer()->returnPosts()->get(pcn - 1);
                                                
                                                string post;
                                                std::cout << "Type your post and hit enter.\n";
                                                getline(cin, post);
                                                
                                                x.getWallpostResponse()->insert(0, *new WallpostResponse(post, current.getUsername()));
                                                
                                                person.getWallPointer()->returnPosts()->set(pcn - 1, x);
                                                
                                                //dpn->writeList("users.txt");
                                                
                                                goto friendprof;
                                            }
                                            //back to prof
                                            case 4:
                                            {
                                                case4:
                                                int dpn1;
                                                std::cout << "Enter the post number you'd like to remove a comment from or -1 to go back.\n";
                                                cin >> dpn1;
                                                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                                                
                                                WallPost x = person.getWallPointer()->returnPosts()->get(dpn1 - 1);
                                                for (int i = 0; i < x.getWallpostResponse()->getSize(); i++) {
                                                    cout << ToString(i + 1) + ". " + x.getWallpostResponse()->get(i).getEntirePost() << std::endl;
                                                }
                                                
                                                int dpn2;
                                                std::cout << "Enter the comment number you'd like to delete.\n";
                                                cin >> dpn2;
                                                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                                                
                                                
                                                if (x.getWallpostResponse()->get(dpn2 - 1).getUsername() == current.getUsername()) {
                                                    
                                                    x.getWallpostResponse()->remove(dpn2 - 1);
                                                    
                                                    person.getWallPointer()->returnPosts()->set(dpn1 - 1, x);
                                                    
                                                    std::cout << "Comment deleted." << std::endl;
                                                    
                                                    
                                                    //dpn->writeList("users.txt");
                                                    
                                                    
                                                    goto friendprof;
                                                } else {
                                                    std::cout << "Comment does not belong to you." << std::endl;
                                                    goto case4;
                                                }
                                                
                                                
                                            }
                                            //delete friendship
                                            case 5:
                                            {
                                                string answer;
                                                cout << "Are you sure? YES or NO\n";
                                                getline(cin, answer);
                                                
                                                if (answer == "YES") {
                                                    dpn->friendgraph->deleteFriend(current.getUsername(), person.getUsername());
                                                    //dpn->writeList("users.txt");
                                                    
                                                    cout<< "Friend removed./n";
                                                }
                                                
                                                break;
                                            }
                                            case 6:
                                                break;
                                        }
                                        
                                    }
                                } else {
                                    
                                    std::cout<< "\n-------- " + person.getUsername() + "'s profile --------\n\n";
                                    
                                    cout << "\nEnter desired command number:\n> 1 - ADD FRIEND\n> 2 - BACK TO YOUR PROFILE\n" << endl;
                                    
                                    int nonfriendprofile;
                                    
                                    cin >> nonfriendprofile;
                                    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                                    switch (nonfriendprofile) {
                                        //Add Friend
                                        case 1:
                                        {
                                            dpn->friendgraph->addPending(current.getUsername(), person.getUsername());
                                            //dpn->writeList("users.txt");
                                            
                                            cout<< "A friend request was sent./n";
                                            
                                            break;
                                        }
                                        //Go back
                                        case 2:
                                            break;
                                    }
                                }
                                
                            }
                            break;
                        }
                        
                        break;
                        
                    }
                    case 6:
                    {
                        //view accept friend request
                        
                        LinkedList<string> pending = dpn->friendgraph->returnListOfPendingFriends(current.getUsername());
                        
                        
                        LinkedList<string> *q = new LinkedList<string>();
                        LinkedList<string> *q2 = new LinkedList<string>();
                        
                        for (int u = 1; u < pending.getSize(); u++) {
                            q->insert(q->getSize(), pending.get(u));
                        }
                        
                        if (pending.getSize() == 1) {
                            std::cout << "No pending request" << endl;
                        }
                        
                        for (int i = 0; i < q->getSize(); i++) {

                                std::cout << "Accept " << q->get(i) << " friend request? (YES / NO / IGNORE)" << std::endl;
                                string answer;
                                getline(cin, answer);
                            
                                if (answer == "YES"){
                                    
                                    string toremove = q->get(i);
                                    
                                    dpn->friendgraph->deletePending(toremove, current.getUsername());
                                    
                                    q2->insert(q2->getSize(), toremove);
                                
                                    //i--;
                                    //dpn->writeList("users.txt");
                                } else if (answer == "NO"){
                                    dpn->friendgraph->deletePending(pending.get(i), current.getUsername());
                                    dpn->writeList("users.txt");
                                } else {
                                    profile_input = 1;
                                }

                        }
                        
                        for (int v = 0; v < q2->getSize(); v++) {
                            dpn->friendgraph->addFriend(current.getUsername(), q2->get(v));
                        }
                        //dpn->writeList("users.txt");
                        
                        delete q;
                        delete q2;
                        
                        break;
                    }
                    //delete post
                    case 2:
                    {
                        dpn->removeUser(current);
                        int postnumber;
                        std::cout << "Enter a post number\n";
                        cin >> postnumber;
                        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                        current.deletePost(postnumber - 1);
                        dpn->addUser(current);
                        //dpn->writeList("users.txt");
                        
                        break;
                    }
                    //add response
                    case 3:
                    {
                        int pcn;
                        std::cout << "Enter the post number you'd like to respond to.\n";
                        cin >> pcn;
                        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                        
                        WallPost x = current.getWallPointer()->returnPosts()->get(pcn - 1);
                        
                        string post;
                        std::cout << "Type your post and hit enter.\n";
                        getline(cin, post);
                        
                        x.getWallpostResponse()->insert(0, *new WallpostResponse(post, current.getUsername()));
                        
                        current.getWallPointer()->returnPosts()->set(pcn - 1, x);
                        
                        //dpn->writeList("users.txt");
                        break;
                    }
                    //delete a response
                    case 4:
                    {
                        int dpn1;
                        std::cout << "Enter the post number you'd like to remove a comment from or -1 to go back.\n";
                        cin >> dpn1;
                        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                        
                        if (dpn1 >= 0) {
                        WallPost x = current.getWallPointer()->returnPosts()->get(dpn1 - 1);
                        for (int i = 0; i < x.getWallpostResponse()->getSize(); i++) {
                            cout << ToString(i + 1) + ". " + x.getWallpostResponse()->get(i).getEntirePost() << std::endl;
                        }
                        
                        int dpn2;
                        std::cout << "Enter the comment number you'd like to delete.\n";
                        cin >> dpn2;
                        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                        
                        
                        if (x.getWallpostResponse()->get(dpn2 - 1).getUsername() == current.getUsername()) {
                            
                            x.getWallpostResponse()->remove(dpn2 - 1);
                            
                            current.getWallPointer()->returnPosts()->set(dpn1 - 1, x);
                            
                            std::cout << "Comment deleted." << std::endl;
                            
                            //dpn->writeList("users.txt");
                           
                        } else {
                            std::cout << "Comment does not belong to you." << std::endl;
                        }
                        }
                        break;
                    }
                    //degree of seperation
                    case 9:
                    {
                        int graphsize = dpn->friendgraph->friendgraph->getSize();
                        
                        int currentUserPosition = 0;
                        
                        for (int i = 0; i < graphsize; i++) {
                            if (dpn->friendgraph->friendgraph->get(i).get(0) == current.getUsername()) {
                                currentUserPosition = i;
                                continue;
                            }
                        }
                        
                        int *visted = new int[graphsize];
                        
                        for (int i = 0; i < graphsize; i++) {
                            visted[i] = -1;
                        }
                        
                        string person;
                        std::cout << "Type your username you'd like to find the degree of: " << endl;
                        getline(cin, person);
                        
                        ArrayList<string> *q = new ArrayList<string>();
                        //ArrayList<string> *p = new ArrayList<string>();
                        ArrayList<int> *d = new ArrayList<int>();
                        
                        visted[currentUserPosition] = currentUserPosition;
                        q->insert(q->getSize(), current.getUsername());
                        d->insert(d->getSize(), 0);
                        //p->insert(p->getSize(), current.getUsername());
                        string path = current.getUsername();
                        
                        while (q->getSize() > 0) {
                            int currentNodePos = 0;
                            
                            for (int k = 0; k < graphsize; k++) {
                                
                                if (dpn->friendgraph->friendgraph->get(k).get(0) == q->get(0)) {
                                    currentNodePos = k;
                                    continue;
                                }
                            }
                            
                            LinkedList<string> edges = dpn->friendgraph->friendgraph->get(currentNodePos);
                            
                            for (int i = 1; i < edges.getSize(); i++) {
                                
                                int edgepos = 0;
                                
                                for (int l = 0; l < graphsize; l++) {
                                    if (dpn->friendgraph->friendgraph->get(l).get(0) == edges.get(i)) {
                                        edgepos = l;
                                        continue;
                                    }
                                }
                                
                                //cout << ToString(visted[edgepos]) << endl;
                                if (visted[edgepos] == -1) {
                                    
                                    //cout << "Something" << endl;
                                    visted[edgepos] = currentNodePos;
                                    q->insert(q->getSize(), dpn->friendgraph->friendgraph->get(currentNodePos).get(i));
                                    int currentDegree = d->get(0) + 1;
                                    
                                    d->insert(d->getSize(), currentDegree);
                                    
//                                    for (int j = 1; j < q->getSize(); j++) {
//                                        path =  path + " -> " + q->get(j);
//                                     }
//                                    p->insert(p->getSize(), path);
                                    
                                }
                                
                            }
                            
                            if (q->get(0) == person) {
                                
                                int pathpos = 0;
                                
                                for (int b = 0; b < graphsize; b++) {
                                    if (dpn->friendgraph->friendgraph->get(b).get(0) == q->get(0)) {
                                        pathpos = b;
                                        continue;
                                    }
                                }
                                
                                //cout << visted[pathpos] << endl;
                                //cout << person + " is " + ToString(d->get(0)) + " degree(s) from " + current.getUsername() + " via the path: " + p->get(0) << endl;
                                cout << person + " is " + ToString(d->get(0)) + " degree(s) from " + current.getUsername() + " via the path: " << endl;
                                
                                while (dpn->friendgraph->friendgraph->get(pathpos).get(0) != current.getUsername()) {
                                    cout << dpn->friendgraph->friendgraph->get(visted[pathpos]).get(0) << endl;
                                    pathpos = visted[pathpos];
                                }
                                
                                break;
                            }
                            
                            
                            q->remove(0);
                            d->remove(0);
                            //p->remove(0);
                            
                            if (q->getSize() == 0) {
                                cout << "No path found to: " + person << endl;
                                break;
                            }
                        }
                        break;
                        
                    }
                    //3 degree of seperation
                    case 10: {
                        
                        cout << "The following user(s) with 3 degrees of seperation from you: " << endl;
                        bool td = false;
                        int graphsize = dpn->friendgraph->friendgraph->getSize();
                        
                        int currentUserPosition = 0;
                        
                        for (int i = 0; i < graphsize; i++) {
                            if (dpn->friendgraph->friendgraph->get(i).get(0) == current.getUsername()) {
                                currentUserPosition = i;
                                continue;
                            }
                        }
                        
                        bool *visted = new bool[graphsize];
                        
                        for (int i = 0; i < sizeof(visted)/sizeof(bool); i++) {
                            visted[i] = false;
                        }
                        
                        ArrayList<string> *q = new ArrayList<string>();
                        ArrayList<string> *p = new ArrayList<string>();
                        ArrayList<int> *d = new ArrayList<int>();
                        
                        visted[currentUserPosition] = true;
                        q->insert(q->getSize(), current.getUsername());
                        d->insert(d->getSize(), 0);
                        //p->insert(p->getSize(), current.getUsername());
                        string path = current.getUsername();
                        
                        while (q->getSize() > 0) {
                            int currentNodePos = 0;
                            
                            for (int k = 0; k < graphsize; k++) {
                                
                                if (dpn->friendgraph->friendgraph->get(k).get(0) == q->get(0)) {
                                    currentNodePos = k;
                                    continue;
                                }
                            }
                            
                            LinkedList<string> edges = dpn->friendgraph->friendgraph->get(currentNodePos);
                            
                            for (int i = 1; i < edges.getSize(); i++) {
                                
                                int edgepos = 0;
                                
                                for (int l = 0; l < graphsize; l++) {
                                    if (dpn->friendgraph->friendgraph->get(l).get(0) == edges.get(i)) {
                                        edgepos = l;
                                        continue;
                                    }
                                }
                                
                                if (!visted[edgepos]) {
                                    visted[edgepos] = true;
                                    q->insert(q->getSize(), dpn->friendgraph->friendgraph->get(currentNodePos).get(i));
                                    int currentDegree = d->get(0) + 1;
                                    
                                    d->insert(d->getSize(), currentDegree);
                                    
//                                    for (int j = 1; j < q->getSize(); j++) {
//                                        path =  path + " -> " + q->get(j);
//                                    }
//                                    p->insert(p->getSize(), path);
                                    
                                }
                                
                            }
                            
                            if (d->get(0) == 3) {
                                td = true;
                                cout << q->get(0) << endl;

                            }
                            
                            
                            q->remove(0);
                            d->remove(0);
                            p->remove(0);
                            
                        }
                        if (!td) {
                            cout << "Oops... jk no one has 3 degrees" << endl;
                            break;
                        }
                    }
                        break;
                }
                break;
            }

        }
        
        
    }
    
    delete dpn;
    
    return 0;
}
