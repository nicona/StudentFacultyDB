//
//  Student.h
//  Assingment5b
//
//  Created by Nicolaus Nagel on 11/3/14.
//  Copyright (c) 2014 Nicolaus Nagel. All rights reserved.
//

#ifndef __Assingment5b__Student__
#define __Assingment5b__Student__

#include <iostream>
#include "Tree.h"
#include "listNode.h"

class Faculty;

class Student {
protected:
    
    int studentId;
    std::string studentName;
    std::string studentLevel;
    std::string studentMajor;
    double studentGpa;
    int advisorId;
    
    
public:
    
    friend class Faculty;

    Student(){};
    
    
    //setters
    void setId(int iD){studentId = iD;}
    void setName(std::string name){studentName = name;}
    void setLevel(std::string level){studentLevel = level;}
    void setMajor(std::string major){studentMajor = major;}
    void setGpa(double gpa){studentGpa = gpa;}
    void setAdId(int adId){advisorId = adId;}
    
    
    //getters
    int getId(){return studentId;}
    std::string getName(){return studentName;}
    std::string getLevel(){return studentLevel;}
    std::string getMajor(){return studentMajor;}
    double getGpa(){return studentGpa;}
    int getAdvisorId(){return advisorId;}

    
    //overload operators
	bool operator == (int key)
	{
		return (studentId == key);
	}
    
	bool operator == (const Student& stu)
	{
		return (this->studentId == stu.studentId);
	}
    
	bool operator < (const Student& stu)
	{
		return (this->studentId < stu.studentId) ;
	}
    
	bool operator > (const Student& stu)
	{
		return (this->studentId > stu.studentId);
	}
    //overload operator for ostream to file
    friend std::ostream& operator << (std::ostream& os, const Student &stu)
    {
        os << "ID Number: " << stu.studentId << "\nName: " << stu.studentName <<"\nLevel: "<<stu.studentLevel<<"\nMajor: "<<stu.studentMajor<<"\nGPA: "<<stu.studentGpa<<"\nAdvisor ID: "<<stu.advisorId<< std::endl;
		
        return os;
    }
    
};










#endif /* defined(__Assingment5b__Student__) */
