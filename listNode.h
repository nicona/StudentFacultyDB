//
//  listNode.h
//  Assingment5b
//
//  Created by Nicolaus Nagel on 11/3/14.
//  Copyright (c) 2014 Nicolaus Nagel. All rights reserved.
//

#ifndef Assingment5b_listNode_h
#define Assingment5b_listNode_h





template<typename T>
class listNode{
public:
    std::string filepath;
    listNode(T d);
    //virtual ~listNode();
    T data;
    listNode<T>* next;
    listNode<T>* prev;
};

template<typename T>
listNode<T>::listNode(T d){
    next=0;
    prev=0;
    data=d;
}
/*
 template<typename T>
 listNode<T>::~listNode(){
 }
 */
template<typename T>
class DList{
public:
    DList();
    //virtual ~DList();
    bool isEmpty();
    
    inline int getSize(){
        return size;
    }
    
    void addFront(T d);
    void addBack(T d);
    T removeFront();
    T removeBack();
    listNode<T> removeByData(T d);
    
    listNode<T> getFront();
    listNode<T> getBack();
    
    
    listNode<T>* first;
    listNode<T>* last;
    int size = 0;
};

template <typename T>
bool DList<T>::isEmpty(){
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
DList<T>::DList(){
    size=0;
    first=0;
    last=0;
}
/*
 template<typename T>
 DList<T>::~DList(){
 while(first!=0)
 {
 listNode<T>* temp=first;
 first=first->next;
 delete temp;
 }
 
 }*/

template<typename T>
void DList<T>::addFront(T d){
    
    listNode<T>* node = new listNode<T>(d);
    if(isEmpty()){
        last=node;
    }
    else{
        first->prev=node;
    }
    node->next=first;
    first=node;
    ++size;
}
template<typename T>
void DList<T>::addBack(T d){
    
    listNode<T>* node = new listNode<T>(d);
    
    if(isEmpty()){
        first=node;
    }
    else{
        last->next=node;
    }
    node->prev=last;
    last=node;
    ++size;
}

template<typename T>
T DList<T>::removeFront(){
    listNode<T>* temp= first;
    T data=(first->data);
    if(isEmpty()){
        std::cout<<"List is empty cannot remove from empty list."<<std::endl;
    }
    else
    {
        first=first->next;
        if(size!=1)
        {
            first->prev = 0;
            --size;
        }
        else{
            --size;
        }
    }
    return data;
    delete temp;
    
}
template<typename T>
T DList<T>::removeBack(){
    listNode<T>* temp= last;
    T data = (last->data);
    if(isEmpty()){
        std::cout<<"List is empty cannot remove from empty list."<<std::endl;
    }
    else
    {
        last=last->prev;
        if(size!=1){
            last->next=0;
            --size;
        }
        else{
            --size;
        }
    }
    delete temp;
    return data;
}
template<typename T>
listNode<T> DList<T>::getFront(){
    if(isEmpty())
    {
        //  std::cout<<"The list is empty."<<std::endl;
        return NULL;
    }
    else
    {
        return(*first);
    }
}
template<typename T>
listNode<T> DList<T>::getBack(){
    if(isEmpty())
    {
        //std::cout<<"The list is empty."<<std::endl;
        return NULL;
    }
    else{
        return(*last);
    }
}

template<typename T>
listNode<T> DList<T>::removeByData(T d){
    listNode<T>* finder = first;
    while(finder != last){
        if(finder->data == d){
            
            finder->prev->next = finder->next;
            finder->next->prev = finder->prev;
            return(*finder);
        }
        else{
            finder = finder->next;
        }
        
    }
    if(finder->data == last->data){
        last->prev->next = 0;
        return(*last);
    }
    else{
        std::cout<<"sorry that value isnt in the list"<<std::endl;
        return 0;
    }
    
}


#endif
