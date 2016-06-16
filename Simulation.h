//
//  Simulation.h
//  Assingment5b
//
//  Created by Nicolaus Nagel on 11/3/14.
//  Copyright (c) 2014 Nicolaus Nagel. All rights reserved.
//

#ifndef __Assingment5b__Simulation__
#define __Assingment5b__Simulation__

#include <iostream>
#include "Faculty.h"
#include "Student.h"
#include "Faculty.h"
#include "Student.h"
#include "Tree.h"


class Simulation{
    
public:
    
    //declaration of both trees + pointers
    BST<Faculty> facultyTree;
    BST<Faculty> *facultyPtr = &facultyTree;
    
    BST<Student> studentTree;
    BST<Student> *studentPtr = &studentTree;
    
    
    void menu();
    void save();
    void rollBack();
    void addStudent();
    void printAll();
    void findStudent();
    void deleteStudent();
    void findAllAdvisees();
    void changeAdvisor();
    void saveStudents();

    void addFaculty(); //add new faculty
    void printAllFac(); //print all
    void findFaculty(); //find faculty by id
    void deleteFaculty(); //delete facutly by id
    void findFacultyByStId();
    void deleteAdvisee();

    
};




#endif /* defined(__Assingment5b__Simulation__) */
