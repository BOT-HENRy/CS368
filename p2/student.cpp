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
 * Assignment:    Programming Assignment 2
 ******************************************************************************/
 
#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(){
    studentID = 0;
    nCoursesTaken = 0;
}

Student::Student(int ID){
    studentID = ID;
    nCoursesTaken = 0;
}

Student::Student(int ID, CourseInfo ** courses){
    int i = 0;
    studentID = ID;
    while(courses[i] != NULL){
        coursesTaken[i] = *courses[i];
	i++;
    }
    nCoursesTaken = i - 1;
}

int Student::getID() const{
    return studentID;
}

int Student::getCredits() const{
    int numCredits = 0;
    for(int i = 0; i < nCoursesTaken; i++){
        numCredits = numCredits + coursesTaken[i].credits;
    }
    return numCredits;
}

double Student::getGPA() const{
    int totalCredits = 0;
    int numCredits = 0;
    for(int i = 0; i < nCoursesTaken; i++){
        double currGPA = 0;
        char letterGrade = coursesTaken[i].studentGrade;
        if(letterGrade == 'A' || letterGrade == 'a'){
            currGPA = 4.0;
        }else if(letterGrade == 'B' || letterGrade == 'b'){
            currGPA = 3.0;
        }else if(letterGrade == 'C' || letterGrade == 'c'){
            currGPA = 2.0;
        }else if(letterGrade == 'D' || letterGrade == 'd'){
            currGPA = 1.0;
        }else if(letterGrade == 'F' || letterGrade == 'f'){
            currGPA = 0.0;
        }else{
            cout <<"error - format of letter grade is incorrect"<<endl;
            return -2;
        }
        numCredits = numCredits + coursesTaken[i].credits;
        totalCredits = totalCredits + currGPA * coursesTaken[i].credits;
    }
	if(numCredits == 0) return 0;
    return (double)totalCredits/(double)numCredits;
}

CourseInfo const **Student::getCourses(){
    CourseInfo const **courseInfo = new CourseInfo const *[nCoursesTaken + 1];
    int i = 0;
    for(int i = 0; i < nCoursesTaken; i++){
        courseInfo[i] = &coursesTaken[i];
    }
    courseInfo[i] = NULL;
    return courseInfo;
} 

void Student::update(int courseNumber, int credits, int year, Semester cSemester, char grade){
    int check = 0;

    for(int i = 0; i < nCoursesTaken; i++){
        if(coursesTaken[i].courseNumber == courseNumber){
            coursesTaken[i].credits = credits;
            coursesTaken[i].year = year;
            coursesTaken[i].studentGrade = grade;
            coursesTaken[i].cSemester = cSemester;
            check++;
        }
    }

    if(check == 0){
        coursesTaken[nCoursesTaken].courseNumber = courseNumber;
        coursesTaken[nCoursesTaken].credits = credits;
        coursesTaken[nCoursesTaken].year = year;
        coursesTaken[nCoursesTaken].studentGrade = grade;
        coursesTaken[nCoursesTaken].cSemester = cSemester;
        nCoursesTaken = nCoursesTaken + 1;
    }
    
}

void Student::print() const{
    cout << studentID << "," << getCredits()<< "," << getGPA();
}

bool Student::tookCourse(int courseNumber, int year, Semester cSemester){
    int check = 0;
    for(int i = 0; i < nCoursesTaken; i++){
        if(coursesTaken[i].courseNumber == courseNumber && coursesTaken[i].year == year && coursesTaken[i].cSemester == cSemester){
            check = check + 1;
        }
    }
    if(check != 0){
        return true;
    }else{
        return false;
    }
}




