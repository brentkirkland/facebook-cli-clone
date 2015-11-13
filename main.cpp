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
                    dpn->writeList("users.txt");
                    
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
                run = false;
                break;
            }
            //logged in user
            case 4:
            {
                std::cout<< "\n-------- " + current.getUsername() + "'s profile --------\n\n";
                
                if (dpn->friendgraph->returnListOfPendingFriends(current.getUsername()).getSize() > 1) {
                    std::cout << "You have " << dpn->friendgraph->returnListOfFriends(current.getUsername()).getSize() << " pending friend requestion \n";
                }
                
                if (current.getWall() != ""){
                    std::cout << current.getWallForCommandLine();
                } else {
                    std::cout << "\nOops! You have no wallpost :(\n";
                }
                std::cout << "\nEnter desired command number:\n> 1 - ADD\n> 2 - EDIT\n> 3 - LOGOUT\n> 4 - SEARCH FOR USERS\n> 5 - VIEW/ACCEPT PENDING FRIEND REQUEST"<< endl;
                
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
                                    
                        dpn->writeList("users.txt");
                        break;
                    }
                    //edit user (not there yet)
                    case 2:
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
                                
                                dpn->writeList("users.txt");
                                
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
                                dpn->writeList("users.txt");
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
                                dpn->writeList("users.txt");
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
                                dpn->writeList("users.txt");
                                
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
                                        dpn->writeList("users.txt");
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
                    case 3:
                    {
                        std::cout << "\nYou have been successfully logged out.\n" << endl;
                        goto start;
                        break;
                    }
                    //delete account
                    case 4:
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
                                
                                
                                if (dpn->friendgraph->returnListOfFriends(current.getUsername()).find(selectedusername)) {
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
                                        
                                        cout << "\nEnter desired command number:\n> 1 - ADD POST\n> 2 - DELETE ONE OF YOUR POST\n> 3 - ADD A REPONSE\n> 4 - EDIT A RESPONSE\n> 5 - BACK TO YOUR PROFILE\n> 6 - DELETE FRIEND"<< endl;
                                        
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
                                                
                                                dpn->writeList("users.txt");
                                                goto friendprof;
                                            }
                                            //DELETE ONE OF YOUR POST
                                            case 2:
                                            {
                                                int postdelete;
                                                cin >> postdelete;
                                                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                                                
                                                if(person.getWallPointer()->deletePost(current.getUsername(), postdelete - 1)){
                                                    dpn->writeList("users.txt");
                                                    cout << "\nPost deleted.\n";
                                                } else{
                                                    cout << "\nPost does not belong to you.\n";
                                                }
                                        
                                                goto friendprof;
                                                
                                            }
                                            //Add coment
                                            case 3:
                                                break;
                                            //Delete comment
                                            case 4:
                                                break;
                                            //back to prof
                                            case 5:
                                                break;
                                            //delete friendship
                                            case 6:
                                                break;
                                        }
                                        
                                    }
                                } else {
   
                                    int profile;
                                    switch (profile) {
                                        //Add Friend
                                        case 1:
                                            break;
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
                    case 5:
                    {
                        //view accept friend request
                        
                        LinkedList<string> pending = dpn->friendgraph->returnListOfPendingFriends(current.getUsername());
                        
                        if (pending.getSize() == 1) {
                            std::cout << "No pending request" << endl;
                        }
                        
                        for (int i = 1; i < pending.getSize(); i++) {

                                std::cout << "Accept " << pending.get(i) << " friend request? (YES / NO / IGNORE)" << std::endl;
                                string answer;
                                getline(cin, answer);
                                
                                if (answer == "YES"){
                                    dpn->friendgraph->confirmPending(pending.get(i), current.getUsername());
                                    dpn->writeList("users.txt");
                                } else if (answer == "NO"){
                                    dpn->friendgraph->deletePending(pending.get(i), current.getUsername());
                                    dpn->writeList("users.txt");
                                } else {
                                    profile_input = 1;
                                }

                        }

                    }
                }
                break;
            }

        }
        
        
    }
    
    delete dpn;
    
    return 0;
}
