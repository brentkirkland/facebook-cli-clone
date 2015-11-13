//
//  SingleNode.h
//  CS130A_Project_2
//
//  Created by Brent Kirkland on 10/24/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#ifndef SingleNode_h
#define SingleNode_h

#include <cstddef>

template <class T>
struct SingleNode
{
    //constructor
    SingleNode(T data): data(data), next(NULL){}
    
    //next pointer
    SingleNode * next;
    
    //some type of data
    T data;
};

#endif /* SingleNode_h */
