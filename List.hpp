//
//  List.hpp
//  CS130A_Project_2
//
//  Created by Brent Kirkland on 10/24/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#ifndef List_hpp
#define List_hpp


#include <stdio.h>

#include <sstream>
#include <string>

template <typename T>
std::string ToString(T val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}

template <class T>
class List {
public:
    virtual bool insert (int pos, const T & item) = 0;
    /* Inserts the item right before position pos, growing the list by 1.
     pos must be between 0 and the current length of the list.
     (feel free return bool, if you want.) */
    virtual void remove (int pos) = 0;
    /* Removes the element at position pos, shrinking the list by 1.
     pos must be between 0 and the current length of the list minus 1. */
    virtual void set (int pos, const T & item) = 0;
    /* overwrites position pos in the list with item.
     Does not change the length of the list.
     pos must be between 0 and the current length of the list minus 1. */
    virtual T const & get (int pos) const  = 0;
    /* returns the item at position pos, not changing the list.
     pos must be between 0 and the current length of the list minus 1. */
    //virtual ~List() = 0;
    virtual int find(T & item) = 0;
    virtual int getSize() = 0;
    virtual ~List(){
    }
    List(const T&) {};
    List(){};
};

#endif /* List_hpp */
