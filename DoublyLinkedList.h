//
//  DoublyLinkedList.h
//  CS130A-1
//
//  Created by Brent Kirkland and Taylor Getty on 10/6/15.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "Node.h"
#include <cstddef>

template <class T>
class DoublyLinkedList {
    
    private:
    
        //private variables head, tail, and size
        Node<T> * head;
        Node<T> * tail;
        int size;
    
    
    
    public:
    
        //constructor
        DoublyLinkedList() {
            head = NULL;
            tail = NULL;
            size = 0;
        };
    
        DoublyLinkedList(const T& other): head(new Node<T>(*other.head)), tail(new Node<T>(*other.tail)), size(other.size){};
    
        //add element to end of list
        void addTail(T data);
    
        //remove element from the list
        void remove(T data);
    
        //return head to iterate through all element
        Node<T> * getHead();
    
        int getSize();
    
        ~DoublyLinkedList(){
            
            Node<T> *current = NULL;
            
            while(DoublyLinkedList<T>::head != NULL){
                current = head;
                head = head->next;
                delete current;
            }
            head = NULL;
            tail = NULL;
        };
    
};

/*
 * Add data to the end of the linked list
 */
template <typename T>
void DoublyLinkedList<T>::addTail(T data){
    
    Node<T> *a = new Node<T>(data);
    
    if (head == NULL){
        head = a;
        tail = a;
        size = 1;
    } else if (head->next == NULL) {
        head->next = a;
        a->previous = head;
        tail = a;
        size++;
    } else {
        tail->next = a;
        a->previous = tail;
        tail = a;
        size++;
    }
}

/*
 * Removes data from anywhere in the Doubly Linked List
 */
template <typename T>
void DoublyLinkedList<T>::remove(T data){
    
    // Check if a list even exist, if not exit
    if (head == NULL){
        return;
    }
    
    Node<T> *tmp = head;
    
    // Loop through the list to see where the data is
    while (tmp != NULL){
        
        //check the head if it equals our data
        if (head->data == data){
            tmp = head->next;
            delete head;
            head = tmp;
            size = 0;
            break;
        }
        //check the current node if the node data equals data
        else if (tmp->data == data){
        
            //when tmp is the last node
            if (tmp == tail){
                tail = tmp->previous;
                delete tmp;
                size--;
                break;
            }
            //when tmp is not the last or head
            else {
                tmp->previous->next = tmp->next;
                tmp->next->previous = tmp->previous;
                delete tmp;
                size--;
                break;
            }
        }
        
        tmp = tmp->next;
        
    }
}

template <typename T>
Node<T> * DoublyLinkedList<T>::getHead(){
    return head;
}

template <typename T>
int DoublyLinkedList<T>::getSize(){
    return size;
}


#endif /* DoublyLinkedList_h */
