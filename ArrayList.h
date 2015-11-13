//
//  ArrayList.h
//  CS130A_Project_2
//
//  Created by Brent Kirkland on 10/24/15.
//  Copyright © 2015 Brent Kirkland. All rights reserved.
//

#ifndef ArrayList_h
#define ArrayList_h

#include "List.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

using std::cout;

template <class T>
class ArrayList: public List<T> {
    
private:
    
    T * array;
    int size;
    int arraysize;
    
public:
    ArrayList() {
        array = new T[1];
        size = 0;
        arraysize = 0;
    };
    
    ArrayList(std::string username) {
        array = new T[1];
        size = 0;
        arraysize = 0;
    }
    
    ArrayList(const T & other): size(other.size), arraysize(other.arraysize){
    
//        std::cout << "GIG";
        array = other.array;
    
    };
    
    bool insert(int pos, const T & item);
    void remove(int pos);
    void set(int pos, const T & item);
    T const & get (int pos) const;
    int find(T & item);
    
    int getSize();
    
    ~ArrayList(){
        
        if (this->getSize() > 0) {
            delete[] array;
        }
        array = NULL;
//        size.clear();
//        arraysize = NULL;
    }
};


template <typename T>
bool ArrayList<T>::insert(int pos, const T & item){
    
    if (size == 0 && pos == 0) {
        
        array[0] = item;
        arraysize++;
        size++;
        
        //std::cout << "Insert 0, size: " << size << std::endl;
        
        return 1;
        
    }
    if (arraysize <= size) {
        
        arraysize = arraysize * 2;
        
        T * tmp = new T[arraysize];

        for (int i = 0; i < size; i++){
            tmp[i] = array[i];
        }

        //delete[] array;
        array = tmp;
        tmp = NULL;
        
    }
    if (pos > arraysize) {

        return 0;
        
    } else {
        
        if (pos > size - 1){
            
            array[pos] = item;
            
            //std::cout << "Insert 1, size: " << size << std::endl;
            
            size++;
            return 1;
            
        } else {
            
            if (size + 1 > arraysize){
                insert(pos, item);
            }
            
            //shift
            for (int i = size; i > pos; i--) {
                array[i] = array[i-1];
            }
            
            array[pos] = item;
            size++;

            //std::cout << "Insert 2, size: " << size << std::endl;
            return 1;
            
        }
    }
    
    return 0;
}

template <typename T>
void ArrayList<T>::remove(int pos){
    
    if (pos < 0 || pos >= size){
        //std::cout << "\nzero\n";
        return;
    }
    else if (pos == size - 1){
        //std::cout << "\none\n";

        T * tmp = new T[arraysize];
        
        for (int i = 0; i < size - 1; i++) {
            tmp[i] = array[i];
        }
        
        array = tmp;
        
        size = size - 1;
        
        tmp = NULL;
    }
    else {
        //std::cout << "\ntwo\n";

        T * tmp = new T[arraysize];
        
        for (int i = 0; i < pos; i++) {
            tmp[i] = array[i];
        }
        
        for (int i = pos + 1; i < size; i++){
            tmp[i-1] = array[i];
        }
        
        array = tmp;
        
        size = size - 1;
        
        tmp = NULL;
    }
    
}

template <typename T>
void ArrayList<T>::set(int pos, const T & item){
    if (pos < 0 || pos > size){
        return;
    }
    array[pos] = item;
}

template <typename T>
T const & ArrayList<T>::get(int pos) const {
    
    if (pos < size){
        return array[pos];
    }
    throw std::invalid_argument("Invalid argument");
    
}

template <typename T>
int ArrayList<T>::find(T & item) {
    
    for (int i = 0; i < size; i++) {
        if (array[i] == item){
            return i;
        }
    }
    return -1;
}

template <typename T>
int ArrayList<T>::getSize() {
    
    if (array != NULL){
        return size;
    } else {
        return -1;
    }
}


#endif /* ArrayList_h */
