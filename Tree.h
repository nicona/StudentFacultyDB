//
//  Tree.h
//  Assingment5b
//
//  Created by Nicolaus Nagel on 11/3/14.
//  Copyright (c) 2014 Nicolaus Nagel. All rights reserved.
//

#ifndef Assingment5b_Tree_h
#define Assingment5b_Tree_h

#include <iostream>
#include <fstream>



//using namespace std;

template<typename T>
class TreeNode{
public:
    TreeNode(T d);
    virtual ~TreeNode();
    
    TreeNode<T>* left;
    TreeNode<T>* right;
    T key;
};


template<typename T>
TreeNode<T>::TreeNode(T d){
    left =0;
    right =0;
    key = d;
}


template<typename T>
TreeNode<T>::~TreeNode(){
    //free memory?
}

template<typename T>
class BST{
public:
    BST(){
        root=0;
        size=0;
    };
    
    virtual ~BST(){};
    void add(T d);
    void printSpecificSt(int d);
    void printSpecificFac(int d);
 /*---------------------------------*/
    bool check(int d);
    void setAdviseeIdTree(int d, int newId);
    void setStAdvisorIdTree(int d, int newId);
    int * findAllAdvisees(int d);
    void deleteAdvisee(int d, int adId);
    
    
    int currentFacultyListSize(int d);
    int getStudentAdvisorId(int d);
 /*---------------------------------*/
    bool isEmpty(){
        return (size == 0);
    }
    int getSize(){
        return size;
    }
    
    
    bool deletes(T k);
    
    void printStudents();
    void printFaculty();
    void printToFile();
    
    
private:
    TreeNode<T>* root;
    int size;
    void printHelper(TreeNode<T>* n);
    void printStudentsHelp(TreeNode<T>*n);
    void printFacultyHelp(TreeNode<T>* n);
    void printToFileHelper(TreeNode<T>* n)const;
    
};

template<typename T>
void BST<T>::printToFile(){
    printToFileHelper(root);
}


//I am not sure why it is not working but the method will not write out to a file
template<typename T>
void BST<T>::printToFileHelper(TreeNode<T>* n) const{
    std::ofstream print;
    print.open("/users/niconagel/desktop/Database.txt" ,std::fstream::in | std::fstream::out | std::fstream::app);
    if(n!=0 && print.is_open()){
        printToFileHelper(n->left);
        print<<&n->key<<std::endl;
        printToFileHelper(n->right);
    }
    print.close();
    
}




template<typename T>
void BST<T>::printStudents(){
    printStudentsHelp(root);
}

template<typename T>
void BST<T>::printFaculty(){
    printFacultyHelp(root);
}

template<typename T>
int BST<T>::currentFacultyListSize(int d){
    
    bool found = false;
    
    TreeNode<T>* current = root;
    while(current != 0 && !found){
        if(d == current->key.getId()){
            found = true;
            return current->key.getListSize();
            continue;
        }
        if(d < current->key.getId())
            current = current->left;
        else
            current = current->right;
    }
    return 0;
}




template<typename T>
int BST<T>::getStudentAdvisorId(int d){
    
    bool found = false;
    int advisorId = 0;
    
    TreeNode<T>* current = root;
    while(current != 0 && !found){
        if(d == current->key.getId()){
            found = true;
            advisorId = current->key.getAdvisorId();
            continue;
        }
        if(d < current->key.getId())
            current = current->left;
        else
            current = current->right;
    }
    return advisorId;

    
}
//searches tree for the faculty id and correspondingly gets all advisee ids
template<typename T>
int * BST<T>::findAllAdvisees(int d){
    bool found = false;
    TreeNode<T>* current = root;
    
    while(current != 0 && !found){
        if(d == current->key.getId()){
            found = true;
            //for(int i =0; i < current->key.getListSize(); ++i){
            return current->key.getAllAdvisees();
            //}
            continue;
        }
        if(d < current->key.getId())
            current = current->left;
        else
            current = current->right;
    }
    return 0;
}


//searches tree for the faculty id and correspondingly calls the delete function in the Faculty class
template<typename T>
void BST<T>::deleteAdvisee(int d, int adId){
    bool found = false;
    TreeNode<T>* current = root;
    
    while(current != 0 && !found){
        if(d == current->key.getId()){
            found = true;
            current->key.deleteAdvisee(adId);
            continue;
        }
        if(d < current->key.getId())
            current = current->left;
        else
            current = current->right;
    }
    
}



template <typename T>
void BST<T>::printStudentsHelp(TreeNode<T>* n)
{
	if(n!=NULL)
	{
		printStudentsHelp(n->left);
		std::cout <<"ID: "<< n->key.getId() << std::endl;
		std::cout <<"Name: "<< n->key.getName() << std::endl;
		std::cout <<"Class Level: "<< n->key.getLevel() << std::endl;
		std::cout <<"Major: "<< n->key.getMajor() << std::endl;
		std::cout <<"Gpa: "<< n->key.getGpa() << std::endl;
		std::cout <<"Advisor ID: "<< n->key.getAdvisorId() << std::endl;
        std::cout<<""<<std::endl;
		printStudentsHelp(n->right);
	}
}

template <typename T>
void BST<T>::printFacultyHelp(TreeNode<T>* n)
{
	if(n!=NULL)
	{
		printFacultyHelp(n->left);
		std::cout << "Id: " << n->key.getId() << std::endl;
        std::cout << "Name: " << n->key.getName() << std::endl;
        std::cout << "Level: " << n->key.getLevel() << std::endl;
        std::cout << "Department: " << n->key.getDepart() << std::endl;
        std::cout<<  "Advisees: "<<n->key.printAdvisees()<<std::endl;
        std::cout<<""<<std::endl;
		printFacultyHelp(n->right);
	}
}



template<typename T>
void BST<T>::printSpecificFac(int d) {
	bool found = false;
    
	if (!isEmpty()) {
		TreeNode<T>* current = root;
		while (current != 0) {
			if (d == current->key.getId()) {
				std::cout << "Id: " << current->key.getId() << std::endl;
				std::cout << "Name: " << current->key.getName() << std::endl;
				std::cout << "Level: " << current->key.getLevel() << std::endl;
				std::cout << "Department: " << current->key.getDepart() << std::endl;
                std::cout << "Advisees:" <<current->key.printAdvisees() << std::endl;
                std::cout << " " << std::endl;
				found = true;
				break;
			}
			if (d < current->key.getId()) {
				current = current->left;
			} else {
				current = current->right;
			}
		}
	}
    
	if (!found) {
		std::cout << "There is no Faculty member with that specific id. " << std::endl;
		std::cout << " " << std::endl;
    }
}

template<typename T>
void BST<T>::printSpecificSt(int d) {
	bool found = false;
    
	if (!isEmpty()) {
		TreeNode<T>* current = root;
		while (current != 0) {
			if (d == current->key.getId()) {
				std::cout << "Id: " << current->key.getId() << std::endl;
				std::cout << "Name: " << current->key.getName() << std::endl;
				std::cout << "Level: " << current->key.getLevel() << std::endl;
				std::cout << "Major: " << current->key.getMajor() << std::endl;
				std::cout << "Gpa: " << current->key.getGpa() << std::endl;
				std::cout << "Advisor ID: " << current->key.getAdvisorId() << std::endl;
				std::cout << " " << std::endl;
				found = true;
				break;
			}
			if (d < current->key.getId()) {
				current = current->left;
			} else {
				//cout << "Id : " << current->key.getId() << endl;
				current = current->right;
			}
		}
	}
    
	if (!found) {
		std::cout << "There is no student with that specific id. " << std::endl;
		std::cout << " " << std::endl;
    }
}



template<typename T>
bool BST<T>::check(int d){  //this just checks whether a student/faculty already exits in the tree based off the ID
    
    bool found = false;
    
    TreeNode<T>* current = root;
    while(current != 0 && !found){
        if(d == current->key.getId()){
            found = true;
            continue;
        }
        if(d < current->key.getId())
            current = current->left;
        else
            current = current->right;
    }
    return found;
    
}

template<typename T>
void BST<T>::setAdviseeIdTree(int d, int newId){
    
    bool found = false;
    TreeNode<T>* current = root;

    while(current != 0 && !found){
        if(d == current->key.getId()){
            found = true;
            current->key.setAdviseeId(newId);
            continue;
        }
        if(d < current->key.getId())
            current = current->left;
        else
            current = current->right;
    }
}

template<typename T>
void BST<T>::setStAdvisorIdTree(int d, int newId){
    
    bool found = false;
    TreeNode<T>* current = root;
    
    while(current != 0 && !found){
        if(d == current->key.getId()){
            found = true;
            current->key.setAdId(newId);
            continue;
        }
        if(d < current->key.getId())
            current = current->left;
        else
            current = current->right;
    }
}




template<typename T>
void BST<T>::add(T d){
    
    if(isEmpty()){
        root = new TreeNode<T>(d);
    }
    
    else{
        TreeNode<T>* current = root;
        TreeNode<T>* parent = 0;
        while(current != 0){
            parent = current;
            if(d < current->key)
                current = current->left;
            else
                current = current->right;
        }
        
        TreeNode<T>* newNode = new TreeNode<T>(d);
        if(d > parent->key){
            parent->right = newNode;
        }
        else{
            parent->left = newNode;
        }
    }
    ++size;
}




template<typename T>
bool BST<T>::deletes(T k){   //we prepare for battle
    if (root == NULL)
        return false;  //like weíre ever this lucky
    
    TreeNode<T>* current = root;
    TreeNode<T>* parent = root;
    bool isLeft = true;
    
    while(!(current->key == k)){ //usual code to find the node
        parent = current;
        if(k < current->key){  //need to go left
            
            isLeft = true;
            current = current->left;
        }
        else{ //need to go right
            
            isLeft = false;
            current = current->right;
        }
        if(current == NULL)  //the thing isnít in the tree
            return false;
    }
    
    
    //no children ñ this would be nice
    if(current->left==NULL && current->right==NULL){
        
        if(current == root)             // deleting root
            root = NULL;
        else if(isLeft)
            parent->left = NULL;     // disconnect from parent
        else
            parent->right = NULL;
    }
    
    //one child ñ still not too bad
    // no right child, replace with left subtree
    else if(current->right==NULL){
        if(current == root)  //always have to check for root
            root = current->left;
        else if(isLeft)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    // no left child, replace with right subtree
    else if(current->left==NULL){
        if(current == root)
            root = current->right;
        else if(isLeft)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else{  // two children ñ things are about to get scary
        
        // find successor of node to delete (current)
        TreeNode<T>* successor = getSuccessor(current);
        
        // connect parent of current to successor
        if(current == root)  //usual root check
            root = successor;
        else if(isLeft)
            parent->left = successor;
        else
            parent->right = successor;
        
        // connect successor to current's left child
        successor->left = current->left;
    }
    return true;
}

//At this point we begin to cry and take a 4 hour nap.


template<typename T>
TreeNode<T>* getSuccessor(TreeNode<T>* d){ //d to be deleted
    
    TreeNode<T>* sp = d;  //successorís parent
    TreeNode<T>* successor = d;
    TreeNode<T>* current = d->right;   // go to right first
    while(current != NULL){
        
        sp = successor;
        successor = current;
        current = current->left;      // go to left
    }
    
    if(successor != d->right){  // descendant of right child
        
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

#endif
