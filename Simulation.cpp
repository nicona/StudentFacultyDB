//
//  Simulation.cpp
//  Assingment5b
//
//  Created by Nicolaus Nagel on 11/3/14.
//  Copyright (c) 2014 Nicolaus Nagel. All rights reserved.
//

#include "Simulation.h"
using namespace std;
void Simulation::deleteStudent(){
    
    Student deleteSt;
    string answer;
    bool loop = true;
    
    int iD;
    
    while(loop)
    {
        loop = false;
        cout<<"What is the student ID?"<<endl;
        cin>>iD;
        deleteSt.setId(iD);
        if(!cin.good()){
            cout<<"Wrong input. Please enter a digit."<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            loop = true;
        }
        
        else if(studentTree.isEmpty() || (!studentTree.check(iD))){
            cout<<"\nStudent does not exist make sure to enter the right ID or press 7 to save a new student.\n"<<endl;
            loop = false;
            break;
        }
        else
        {
            studentTree.deletes(deleteSt);
            cout<<"Student deleted."<<endl;
            cout<<"Would you like to delete another student?"<<endl;
            cin>>answer;
            if(answer =="y" || answer == "yes"){
                loop = true;
            }
            else loop = false;
        }
    }
    
}

void Simulation::findStudent(){
    
    
    string answer; //answer to if user wants to print the student info.
    bool loop = true;
    int iD;
    
    while(loop)
    {
        loop = false;
        Student searchSt;
        cout<<"What is the student ID?"<<endl;
        cin>>iD;
        if(!cin.good()){
            cout<<"Wrong input. Please enter a digit."<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            loop = true;
        }
        
        else if(!(studentTree.check(iD))){
            cout<<"Student not in database."<<endl;
            loop = true;
        }
        studentTree.printSpecificSt(iD);
        
        cout<<"Would you like to search for another student?"<<endl;
        cin>>answer;
        if(answer == "y" || answer =="yes"){
            loop = true;;
        }
        else
            loop = false;
    }
}


void Simulation::printAll(){
    
    if(studentTree.isEmpty()){
        cout<<"There are no students saved.\nPress 7 to enter a new student.\n"<<endl;
    }
    else studentTree.printStudents();
    
}


void Simulation::addStudent()
{
    int iD;
    string name;
    string level;
    string major;
    double gpa;
    int  adId;
    
    string againAns;
    string printAns;
    bool loop = true;
    bool loop2 = true;
    int loop3answer;
    
    while(loop){
       
        Student student;
        loop = false;
        cout<<"What is the student ID?"<<endl;
        cin>>iD;
        if(!cin.good()){
            cout<<"Wrong input. Please enter a digit."<<endl;
            loop = true;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            
        }
        
        else if(studentTree.check(iD)){
            cout<<"Student already exists, please add choose a different ID."<<endl;
            loop = true;
        }
        else
        {
            student.setId(iD);
            cout<<"Name?"<<endl;
            cin>>name;
            student.setName(name);
            
            cout<<"Level?"<<endl;
            cin>>level;
            student.setLevel(level);
            
            cout<<"Major?"<<endl;
            cin>>major;
            student.setMajor(major);
            
            while(loop2){
                cout<<"GPA?"<<endl;
                cin>>gpa;
                if(gpa <= 4 && gpa > 0 ){
                    student.setGpa(gpa);
                    loop2 = false;
                }
                else{
                    cout<<"Student GPA must be within 0 and 4. Enter a new GPA."<<endl;
                    loop2 = true;
                }
            }
            loop2 = true;
            cout<<"Advisor ID?"<<endl;
            cin>>adId;
            student.setAdId(adId);
            
        again:
            if(!(facultyPtr->check(adId))){
                
                cout<<"This faculty does not exist. \nPlease enter a valid Faculty ID or press 1 to get back to the main menu."<<endl;
                cin>>loop3answer;
                if(loop3answer == 1){
                    break;
                }
                else goto again;
                
            }
            else{
                facultyPtr->setAdviseeIdTree(adId, iD);
                
            }
            studentTree.add(student);
            cout<<"Student was added."<<endl;
            cout<<"\nNumber of students in database: "<<studentTree.getSize()<<endl;
        }
        
        cout<<"Would you like to add another student?"<<endl;
        cin>>againAns;
        if(againAns == "n"){
            loop = false;
            break;
        }
        else
            loop = true;
    }
}


void Simulation::findAllAdvisees(){
    
    string answer;
    bool loop = true;
    string name;
    string level;
    string major;
    
    int  facId;
    
    
    while(loop){
        loop = false;
        cout<<"What is the faculty ID?"<<endl;
        cin>>facId;
        if(!cin.good()){
            cout<<"Wrong input. Please enter a digit."<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            loop = true;
        }
        else if(!facultyPtr->check(facId)){
            cout<<"Faculty member not in database, please enter a valid faculty ID."<<endl;
            loop = true;
        }
        
        else{
            int * d = facultyPtr->findAllAdvisees(facId);
            for (int i = 0; i < facultyPtr->currentFacultyListSize(facId);++i){
                studentPtr->printSpecificSt(d[i]);
            }
        }
        
        cout<<"Would you like to search for another student's advisor?"<<endl;
        cin>>answer;
        if(answer == "y" || answer =="yes"){
            loop = true;
        }
        else
            loop = false;
    }
}


void Simulation::saveStudents(){
    
    studentTree.printToFile();
    facultyTree.printToFile();
}


void Simulation::deleteFaculty(){
    
    Faculty deleteFac;
    string answer;
    bool loop = true;
    
    int faculId;
    
    
    while(loop)
    {
        loop = false;
        cout<<"What is the faculty ID?"<<endl;
        cin>>faculId;
        deleteFac.setFaculId(faculId);
        if(!cin.good()){
            cout<<"Wrong input. Please enter a digit."<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            loop = true;
        }
        else if(facultyTree.isEmpty() || (!facultyTree.check(faculId))){
            cout<<"\nFaculty member does not exist make sure to enter the right ID or press 9 to save a new Faculty member.\n"<<endl;
            loop = false;
            break;
        }
        
        else
        {
            facultyTree.deletes(deleteFac);
            cout<<"Faculty deleted."<<endl;
            cout<<"Would you like to delete another faculty member?"<<endl;
            cin>>answer;
            if(answer =="y" || answer == "yes"){
                loop = true;
            }
            else loop = false;
        }
    }
}

void Simulation::findFaculty(){
    
    
    string answer; //answer to if user wants to print the student info.
    bool loop = true;
    
    int faculId;
    
    
    
    while(loop)
    {
        loop = false;
        
        cout<<"What is the faculty ID?"<<endl;
        cin>>faculId;
        if(!cin.good()){
            cout<<"Wrong input. Please enter a digit."<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            loop = true;
        }
        
        else if(!(facultyTree.check(faculId))){
            cout<<"Faculty not in database."<<endl;
            loop = true;
        }
        facultyTree.printSpecificFac(faculId);
        cout<<"Would you like to search for another faculty member?"<<endl;
        cin>>answer;
        if(answer == "y" || answer =="yes"){
            loop = true;
        }
        else
            loop = false;
    }
}

void Simulation::printAllFac(){
    
    if(facultyTree.isEmpty()){
        cout<<"There are no faculty members saved.\nPress 9 to enter a new faculty member.\n"<<endl;
    }
    else facultyTree.printFaculty();
}




void Simulation::addFaculty()
{
    
    string againAns;
    string printAns;
    bool loop = true;
    int numberOfAdvisees;
    
    int faculId;
    string name;
    string level;
    string department;
    int advId;
    
    while(loop){
        
        Faculty faculty;
        
        cout<<"What is the faculty ID?"<<endl;
        cin>>faculId;
        if(!cin.good()){
            cout<<"Wrong input. Please enter a digit."<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            loop = false;
        }
        else if(facultyTree.check(faculId)){
            cout<<"Faculty already exists, please choose a different ID."<<endl;
            loop = false;
        }
        else faculty.setFaculId(faculId);
            
        cout<<"Name?"<<endl;
        cin>>name;
        faculty.setName(name);
        cout<<"Level?"<<endl;
        cin>>level;
        faculty.setLevel(level);
        cout<<"Department?"<<endl;
        cin>>department;
        faculty.setDepart(department);
        
        
        cout<<"How many advisees does this Faculty memeber have?"<<endl;
        cin>>numberOfAdvisees;
    again:
        for(int i =0; i<numberOfAdvisees; ++i){
            cout<<"What are the Advisees ID's?"<<endl;
            cin>>advId;
            if(!cin.good()){
                cout<<"Wrong input. Please enter a digit."<<endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                goto again;
            }
            else
                faculty.setAdviseeId(advId);
        }
        facultyTree.add(faculty);
        cout<<"Faculty was added."<<endl;
        cout<<"Number of Faculty members in database: "<<facultyTree.getSize()<<endl;
        
        cout<<"Would you like to add another faculty member?"<<endl;
        cin>>againAns;
        if(againAns == "n"){
            loop = false;
            break;
        }
    }
}



void Simulation::findFacultyByStId(){
    
    string answer;
    bool loop = true;
    int adviseeId;
    
    while(loop){
    
        cout<<"What is the student ID?"<<endl;
        cin>>adviseeId;
        if(!cin.good()){
            cout<<"Wrong input. Please enter a digit."<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            loop = false;
        }
        facultyPtr->printSpecificFac(studentPtr->getStudentAdvisorId(adviseeId));
        cout<<"Would you like to search for another student's advisor?"<<endl;
        cin>>answer;
        if(answer == "y" || answer =="yes"){
            loop = true;
        }
        else
            loop = false;
    }
}

void Simulation::changeAdvisor(){
    
    string answer;
    bool loop = true;
    int iD;
    int  adId;
    
    while(loop){
        
        loop = false;
        cout<<"What is the student ID?"<<endl;
        cin>>iD;
        if(!cin.good()){
            cout<<"Wrong input. Please enter a digit."<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            loop = true;

        }
        else if(!(studentTree.check(iD))){
            cout<<"Student does not exist."<<endl;
            loop = true;
        }
        else{
        
            cout<<"What is the new advisors ID?"<<endl; //check for correct input
            cin>>adId;
            studentPtr->setStAdvisorIdTree(iD, adId);
            
            cout<<"Advisor has been changed."<<endl;
            
            cout<<"Would you like to change another student's advisor?"<<endl;
            cin>>answer;
            if(answer == "y" || answer =="yes"){
                loop = true;
            }
            else
                loop = false;
        }
        
    }
}


void Simulation::deleteAdvisee(){
    
    bool loop = true;
    
    
    int iD;
    int adId;
    string answer;
    
    while(loop){
        Student change;
        cout<<"What is the faculty member ID?"<<endl;
        cin>>iD;
        if(!(facultyTree.check(iD))){
            cout<<"Faculty does not exist."<<endl;
            loop = true;
        }
        facultyPtr->printSpecificFac(iD);
        cout<<"Which advisee would you like to delete?"<<endl;
        cin>>adId;
        facultyPtr->deleteAdvisee(iD,adId);
        cout<<"Advisee has been deleted, would you like to delete another?"<<endl;
        cin>>answer;
        if(answer == "y" || answer =="yes"){
            loop = true;
        }
        else
            loop = false;

    }
}


void Simulation::menu(){
    
    Simulation sim;
    int option;
    bool loop = true;
    
    while(loop)
    {

        cout<<"Press 1 to print all students."<<endl;
        cout<<"Press 2 to print all faculty members."<<endl;
        cout<<"Press 3 to find a student."<<endl;
        cout<<"Press 4 to find a faculty member."<<endl;
        cout<<"Press 5 to find a student's advisor by ID."<<endl;
        cout<<"Press 6 to print all advisee information of a faculty member."<<endl;
        cout<<"Press 7 to add a new Student."<<endl;
        cout<<"Press 8 to delete a student."<<endl;
        cout<<"Press 9 to add a new faculty member."<<endl;
        cout<<"Press 10 to delete a faculty member."<<endl;
        cout<<"Press 11 to change a students advisor."<<endl;
        cout<<"Press 12 to remove an advisee from a faculty member, given the ID."<<endl;
        cout<<"Press 13 to rollback up to 5 times."<<endl;
        cout<<"Press 14 to exit the program."<<endl;
        cin>>option;
        
        if(option > 14 || option < 1 || !cin.good())
        {
            
            cout<<"\nWrong input, please enter a number between 1 and 14.\n"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n'); //stack overflow
        }
        else
        {
            
            switch (option) {
                case 1:
                    sim.printAll();
                    break;
                case 2:
                    sim.printAllFac();
                    break;
                case 3:
                    sim.findStudent();
                    break;
                case 4:
                    sim.findFaculty();
                    break;
                case 5:
                    sim.findFacultyByStId();
                    break;
                case 6:
                    sim.findAllAdvisees();
                    break;
                case 7:
                    sim.addStudent();
                    break;
                case 8:
                    sim.deleteStudent();
                    break;
                case 9:
                    sim.addFaculty();
                    break;
                case 10:
                    sim.deleteFaculty();
                    break;
                case 11:
                    sim.changeAdvisor();
                    break;
                case 12:
                    sim.deleteAdvisee();//remove advisees from advisor
                    break;
                case 13:
                    //rollback, use stack to store up to 5 rollbacks
                    break;
                case 14:
                    sim.saveStudents();
                    loop = false; // exit
                    break;
                default:
                    break;
            }
        }
    }
}















