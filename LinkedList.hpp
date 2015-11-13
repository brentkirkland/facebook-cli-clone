//
//  LinkedList.hpp
//  CS130A_Project_2
//
//  Created by Brent Kirkland on 10/24/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//
#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "List.hpp"
#include "SingleNode.h"
#include <stdexcept>

template <class T>
class LinkedList: public List<T> {
    
private:
    SingleNode<T> * head;
    int size;
    
public:
    
    LinkedList(): head(NULL), size(0) {}

    LinkedList(const T & other): head(new SingleNode<T>(*other.head)), size(other.size){};
    
    bool insert(int pos, const T & item);
    void remove(int pos);
    void set(int pos, const T & item);
    T const & get (int pos) const;
    int find(T & item);
    int getSize();
    
    SingleNode<T> * getHead();
    
    ~LinkedList(){

        SingleNode<T> * current = NULL;
        
        while(LinkedList<T>::head != NULL){
            current = head;
            head = head->next;
        }
        head = NULL;

    }
    
};

template <typename T>
bool LinkedList<T>::insert(int pos, const T & item){
    
    if (pos > size || pos < 0){
        return 0;
    }
    else if (pos == 0 && size == 0){
        head = new SingleNode<T>(item);
        size = 1;
        return 1;
    }
    else {
        
        SingleNode<T> * tmp = head;

        for (int i = 0; i < size + 1; i++){
            
            //insert
            if (pos - 1 == i){
                
                SingleNode<T> * x = new SingleNode<T>(item);
                x->next = tmp->next;
                tmp->next = x;
                size++;
                
                return 1;
            }
            
            tmp = tmp->next;
        }
        
    }
    return 0;
}

template <typename T>
void LinkedList<T>::remove(int pos){
    
    SingleNode<T> * tmp = head;
    
    if (pos > size || pos < 0) {
        return;
    } else if (pos == 0){

        head = head->next;
        size--;
        delete tmp;
        
    } else {
        
        for (int i = 0; i < size - 1; i++){
            
            if (pos - 1 == i){
                
                SingleNode<T> * t = tmp->next;
                tmp->next = tmp->next->next;
                delete t;
                size--;
                return;
            }
            
            tmp = tmp->next;
            
        }
        
    }
    
}

template <typename T>
SingleNode<T> * LinkedList<T>::getHead(){
    return head;
}

template <typename T>
void LinkedList<T>::set(int pos, const T & item){
    
    SingleNode<T> * tmp = head;
    
    if (pos > size || pos < 0) {
        return;
    } else if (pos == 0){
        
        head = new SingleNode<T>(item);
        head->next = tmp->next;
        delete tmp;
        
    } else {
        
        for (int i = 0; i < size - 1; i++){
            
            if (pos - 1 == i){
                
                SingleNode<T> * t = new SingleNode<T>(item);
                t->next = tmp->next->next;
                tmp->next = t;
                return;
            }
            
            tmp = tmp->next;
            
        }
        
    }

    
}

template <typename T>
T const & LinkedList<T>::get(int pos) const {
    
    SingleNode<T> * tmp = head;
    
    if (pos == 0){
        
        return head->data;
        
    } else {
        
        for (int i = 0; i < size - 1; i++){
            
            if (pos - 1 == i){
                
                return tmp->next->data;
            }
            
            tmp = tmp->next;
            
        }
        
    }
    
    throw std::invalid_argument("Invalid argument");
}

template <typename T>
int LinkedList<T>::find(T & item) {
    SingleNode<T> * tmp = head;
    for (int i = 0; i < size; i++) {
        if (tmp->data == item){
            return i;
        }
        tmp = tmp -> next;
    }
    return -1;
}

template <typename T>
int LinkedList<T>::getSize() {
    return size;
}

#endif