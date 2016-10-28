/*******************************************************************************
 * Author:        Yizhe Qu	
 * CS Login:      qu
 * 
 * Pair Partner:  (name of your pair programming partner, if applicable)
 * CS Login:      (your partner's CS login name)
 * 
 * Credits:       none
 * 
 * Course:        CS 368, Fall 2015
 * Assignment:    Programming Assignment 3
 ******************************************************************************/
 
#include <iostream>
#include <algorithm> 
#include "SortedList.h"

using namespace std;

SortedList::SortedList(){
    head = NULL;
}

//Auxiliary Functions
void SortedList::freeList (Listnode *L){
    Listnode *curr = L;
    Listnode *tmp = curr;
    //L = L->next; 
    while(tmp!=NULL){      
        tmp = curr->next; 
        delete curr;
        curr = tmp;
    }  
} 

SortedList::Listnode * SortedList::copyList (Listnode *L){
    Listnode *newL = L;
    newL->student = L->student;
    Listnode *newHead = newL;
    Listnode *curr = L;
    while(curr->next != NULL){
        newL->next = curr->next;
        newL->next->student = curr->next->student;
        curr = curr->next;
        newL = newL->next;
    }
    return newHead;
}

//copy constructor
SortedList::SortedList(const SortedList &L){
    head = copyList(L.head); 
}

//destructor
SortedList::~SortedList(){
    freeList(head);
}
//Overload the assignment operator
SortedList & SortedList::operator=(const SortedList &L){
    //check if self-assignment 
    if(this == &L)
        return *this;
    else{
        freeList(head);
        head = copyList(L.head); 
    }
    return *this;
}

bool SortedList::insert(Student *s){
    int check = 0;
    Listnode *curP = head;
    //if list is empty
    if(head == NULL){
       Listnode *curr = new Listnode;
       curr->next = NULL;
       curr->student = s;
       head = curr;
       return true; 
    }
    //searching through the list
    else if(find(s->getID()) == NULL){
        curP = head;
        //when head needs to be replaced
        if(head->student->getID() > s->getID()){
            Listnode *curr = new Listnode;
            curr->next = head;
            curr->student = s;
            head = curr;
            return true;
        }
        //when there's only one and needs to add at next
        else if(curP->next == NULL && curP->student->getID() < s->getID()){
            Listnode *curr = new Listnode;
            curr->next = NULL;
            curr->student = s;
            curP->next = curr;
            return true;
        }
        else{
            //or search to find the position
            while(curP->next != NULL){
                if(curP->next->student->getID() > s->getID()){
                    Listnode *curr = new Listnode;
                    curr->next = curP->next;
                    curr->student = s;
                    curP->next = curr;
                    return true;
                }   
                curP = curP->next;
                //if need to insert at last position
                if(curP->next == NULL){
                    Listnode *curr = new Listnode;
                    curr->next = NULL;
                    curr->student = s;
                    curP->next = curr;
                    return true;
                } 
            }
        }        
    }else{
        check = 0;
        return false;
    }
}

Student * SortedList::find(int studentID){
    Listnode *curP = head;
    while(curP != NULL){        
        if(curP->student->getID() == studentID){
            return curP->student;
        }
        curP = curP->next;
    }
    return NULL;
}

Student * SortedList::remove(int studentID){
    Listnode *curP = head;
    Student *stu;
    //if head is what we want
    if(curP->student->getID() == studentID){
        Listnode *tmp = curP;
        stu = curP->student;
        head = curP->next;
        delete tmp;       
        return stu;
    }
    //if only 2 in the list and need to remove the second one
    if(curP->next->next == NULL && curP->next->student->getID() == studentID){
        Listnode *tmp = curP;
        stu = head->next->student;
        delete tmp->next;
        head->next = NULL;
        return stu;
    }
    //or go through
    while(curP->next->next != NULL){
        if(curP->next->student->getID() == studentID){
            Listnode *tmp = curP->next;
            stu = curP->next->student;
            curP->next = curP->next->next;
            delete tmp;
            return stu;
        }   
        curP = curP->next;
        //if need to remove at last position
        if(curP->next->next == NULL){
            if(curP->next->student->getID() == studentID){
                Listnode *tmp = curP->next;
                stu = curP->next->student;
                delete tmp;
                curP->next = NULL;
                return stu;
            }
        }
    }
    return NULL;
}

int SortedList::getNStudents(int courseNumber, int inYear, Semester inSemester){
    int numStu = 0;
    Listnode *curP = head;
    while(curP != NULL){
        if(curP->student->tookCourse(courseNumber, inYear, inSemester)){
            numStu++;
        }
        curP = curP->next;
    }
    return numStu;
}

Student ** SortedList::getClassRoster(int courseNumber, int inYear, Semester inSemester){
    Student **stuHead = new Student*[getNStudents(courseNumber, inYear, inSemester)];
    Listnode *curP = head;
    int i = 0;
    while(curP != NULL){
        if(curP->student->tookCourse(courseNumber, inYear, inSemester)){
            stuHead[i] = curP->student;
            i++;
        }
        curP = curP->next;
    }
    stuHead[i] = NULL;
    return stuHead;
}



void SortedList::printClassRoster(int courseNumber, int inYear, Semester inSemester){
    Student **stuClass = getClassRoster(courseNumber, inYear, inSemester);
    if(stuClass == NULL){
        cout<< "Course " << courseNumber << " was not offered in " << inSemester << " of " << inYear << "." << endl;
    }else{
        int i = 0;
        while(stuClass[i] != NULL){
            cout<< stuClass[i]->getID() <<endl;
            i++;
        }
    }
}

void SortedList::printClassmates(int * studentGroup, int nStudents){

    int *currL = new int[nStudents];
    int index = 0;
    int check = 0;
    for(int i = 0; i < nStudents; i++){
        if(find(studentGroup[i]) != NULL){
            currL[index] = studentGroup[i];
            index++;
        }
    }
    for(int i = 0; i < index-2; i++){
        Student *stu1 = this->find(studentGroup[i]);
        CourseInfo const **currCourse = stu1->getCourses();
        for(int j = i+1; j < index-1; j++){
            Student *stu2 = this->find(studentGroup[j]);
            int k = 0;
            while(currCourse[k]!=NULL){
cout<<"1 time"<<endl;
                if(stu2->tookCourse(currCourse[k]->courseNumber,currCourse[k]->year,currCourse[k]->cSemester)){
                    cout<< "(" << currL[i] << "," << currL[j] << ")" <<endl;
                    check++;
                }
            }
        }
    }
    if(check == 0){
        cout<< "Cannot find a valid pair.\n";
    }

}


void SortedList::print() const{
    Listnode *curP = head;
    if(curP == NULL){
        cout<< "Empty student list.\n";
    }
    while(curP != NULL){
        cout<< curP->student->getID()<<","<<curP->student->getCredits()<<","<<curP->student->getGPA()<< endl;
        curP = curP->next;
    }
}
