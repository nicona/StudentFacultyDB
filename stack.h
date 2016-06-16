//
//  stack.h
//  Assingment5b
//
//  Created by Nicolaus Nagel on 11/3/14.
//  Copyright (c) 2014 Nicolaus Nagel. All rights reserved.
//

#ifndef __Assingment5b__stack__
#define __Assingment5b__stack__

#include <iostream>

#include "listNode.h"


template<typename T>
class Stack{
public:
    Stack();
    virtual ~Stack();
    void push(T d);
    T pop();
    T peek();
    bool isEmpty();
private:
    DList<T> *a_list;
};

//constructor
template<typename T>
Stack<T>::Stack(){
    a_list = new DList<T>();
}
//destructor
template<typename T>
Stack<T>::~Stack(){
    delete a_list;
}
//push onto the stack
template<typename T>
void Stack<T>::push(T d){
    a_list->addFront(d);
}
//remove from stack
template<typename T>
T Stack<T>::pop(){
    return a_list->removeFront();
}
//returns front item on the stack
template <typename T>
T Stack<T>::peek(){
    return a_list->getFront().data;
}

//check if stack empty
template <typename T>
bool Stack<T>::isEmpty(){
    return a_list->isEmpty();
}




#endif /* defined(__Assingment5b__stack__) */
