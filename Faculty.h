//
//  Faculty.h
//  Assingment5b
//
//  Created by Nicolaus Nagel on 11/3/14.
//  Copyright (c) 2014 Nicolaus Nagel. All rights reserved.
//

#ifndef __Assingment5b__Faculty__
#define __Assingment5b__Faculty__

#include <iostream>
#include "Tree.h"
#include "listNode.h"





//using namespace std;


class Student;

class Faculty{
    
protected:
    
    int facultyId;
    std::string faculName;
    std::string faculLevel;
    std::string faculDepartment;
    DList<int> adviseeIdList;

public:
    
    
    friend class Student;

    Faculty(){}
    //setters and getters
    void setFaculId(int faculId){facultyId = faculId;}
    void setName(std::string name){faculName = name;}
    void setLevel(std::string level){faculLevel = level;}
    void setDepart(std::string department){faculDepartment = department;}
    void setAdviseeId(int studentId){adviseeIdList.addFront(studentId);}

    int getId(){return facultyId;}
    std::string getName(){return faculName;}
    std::string getLevel(){return faculLevel;}
    std::string getDepart(){return faculDepartment;}
    
    bool printAdvisees(){
        int * arr = new int[adviseeIdList.size];
        int i;
        //std::cout<<adviseeIdList.size<<" size of list"<<std::endl;
        listNode<int> *iterator = adviseeIdList.first;
        for(i =0; i< adviseeIdList.size; ++i){
            if(i<1){}
            else {
                iterator= iterator->next;
            }
            if(iterator->data == NULL){
                return false;
            }
            arr[i] = iterator->data;
        }
        for(int j =0; j < adviseeIdList.size;++j){
            std::cout<<arr[j]<<",";
        }
        std::cout<<std::endl;
        return true;
    }
    
    int * getAllAdvisees(){
        int * arr = new int[adviseeIdList.size];
        int i;
        listNode<int> *iterator = adviseeIdList.first;
        for(i =0; i< adviseeIdList.size; ++i){
            if(i<1){
            }
            else{
                iterator= iterator->next;
            }
            arr[i] = iterator->data;
        }
        return arr;
    }
    
    //I am not sure why this is happening, but my removeByData function in the List will not work. I have tried serveral things but keep getting a memory leak. All my other functions work;
    bool deleteAdvisee(int adviseeId){
        /*This code did not work either, got the idea for it from the book
        listNode<int> * temp = adviseeIdList.first;
        listNode<int>* toDelete;
        
        while(temp != NULL){
            
            if(temp->data == adviseeId){
                
                toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
            }
            temp = temp->next;
            
        }
        */
        
        adviseeIdList.removeByData(adviseeId);
        std::cout<<adviseeIdList.size<<" size"<<std::endl;
        return true;
    }
    
    
    int getListSize(){
        return adviseeIdList.size;
    }
    
    
    bool findAdvisee(int iD){
        std::cout<<adviseeIdList.size<<" size"<<std::endl;
        if(adviseeIdList.size == 0){
            return false;
        }
        else{
            listNode<int>* iterator = adviseeIdList.first;
            for(int i =0; i < adviseeIdList.size;++i){
                if(i<1){}
                else
                    iterator = iterator->next;
                if(iterator->data == iD){
                    return true;
                }
            }
            
        }
        return false;
    }
    
    //overloading operators
    bool operator == (int key)
	{
		return (facultyId == key);
	}
    
	bool operator == (const Faculty& fac)
	{
		return (this->facultyId == fac.facultyId) ;
	}
    
	bool operator < (const Faculty& fac)
	{
		return (this->facultyId < fac.facultyId) ;
	}
    
	bool operator > (const Faculty& fac)
	{
		return (this->facultyId > fac.facultyId) ;
	}

};







#endif /* defined(__Assingment5b__Faculty__) */
