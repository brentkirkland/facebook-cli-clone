//
//  Node.h
//  CS130A-1
//
//  Created by Brent Kirkland and Taylor Getty on 10/6/15.
//

#ifndef Node_h
#define Node_h

#include <cstddef>

template <class T>
struct Node
{
    //constructor
    Node(T data): data(data), next(NULL), previous(NULL) {}
    
    //previous pointer
    Node * previous;
    
    //next pointer
    Node * next;
    
    //some type of data
    T data;
};

#endif /* Node_h */
