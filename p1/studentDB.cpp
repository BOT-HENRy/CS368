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
 * Assignment:    Programming Assignment 1 
 ******************************************************************************/
 
#include <iostream>

using namespace std;

//struct to store data
struct stuDataBase{
    int studentID;
    int numOfCredits;
    double overallGPA;
}stuDB[7000];

    int numOfStu=0;
    int test;
    int err = 0;

/**
 * methods that check the format of student ID, number of credits
 * and GPA, if incorrect, output error messages
 */
void checkStuID(int studentID){
    if(studentID / 100000 <= 0 || studentID / 100000 > 9){
        err ++;
        cout <<"error - a valid student ID must be a 6-digit positive integer,";
        cout <<"starting with any digit other than zero"<<endl;
    }
}

void checkNumOfCredits(int numOfCredits){
    if(numOfCredits < 0){
        err ++;
        cout <<"error - number of credits must be a non-negative integer value"<<endl;
    }
}

void checkGPA(double GPA){
    if(GPA < 0.0 || GPA > 4.0){
        err ++;
        cout <<"error - GPA must between 0.0 and 4.0 "<<endl;
    }
}

/**
 * methods that add student information (student ID, Credits, GPA)
 * into the data base, will also check errors and existing students
 */
int addStudent(int studentID, int numOfCredits, double overallGPA){
    checkStuID(studentID);
    checkNumOfCredits(numOfCredits);
    checkGPA(overallGPA);
    if(err > 0){
        err = 0;
        return -2;
    }
    //check if student's record already exist
    int i;
    for(i = 0; i < numOfStu; i++){
        if(stuDB[i].studentID == studentID){
            return -1;
        }
    }
    //add info
    stuDB[numOfStu].studentID = studentID;
    stuDB[numOfStu].numOfCredits = numOfCredits;
    stuDB[numOfStu].overallGPA = overallGPA;
    numOfStu++;
    return 1;
}

/**
 * methods that delete the students' information by student ID,
 * will also check errors and existing students
 */
int deleteStudent(int studentID){
    checkStuID(studentID);
    if(err > 0){
        err = 0;
        return -2;
    }

    //check if student's record exist
    int i;
    for(i = 0; i < numOfStu; i++){
        if(stuDB[i].studentID == studentID){
            //remove the record
            for(test = i; test < (numOfStu - 1); test++){
                stuDB[test].studentID = stuDB[test + 1].studentID;
                stuDB[test].numOfCredits = stuDB[test + 1].numOfCredits;
                stuDB[test].overallGPA = stuDB[test + 1].overallGPA;
                if(test == numOfStu -2){
                    stuDB[test + 1].studentID = 0;
                    stuDB[test + 1].numOfCredits = 0;
                    stuDB[test + 1].overallGPA = 0.0;
                }
            }
            numOfStu --;
            return 1;
        }
    }
    return -1;
}

/**
 * methods that updates the students' information by student ID,
 * will also check errors and calculate new GPA
 */
int updateStudent(int studentID, char letterGrade, int courseCredits){
    checkStuID(studentID);
    if(err > 0){
        err = 0;
        return -2;
    }
    if(courseCredits < 0){
        cout <<"error - format of course credits is incorrect"<<endl;
    }
    int i;
    double currGPA;
    //convert letter grades to calculate the new GPA
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
    for(i = 0; i < numOfStu; i++){
        if(stuDB[i].studentID == studentID){
            int currNumC = stuDB[i].numOfCredits;
            stuDB[i].numOfCredits = stuDB[i].numOfCredits + courseCredits;
            double totalGPA = stuDB[i].overallGPA * currNumC + currGPA * courseCredits;
            stuDB[i].overallGPA = totalGPA / stuDB[i].numOfCredits;
            cout <<stuDB[i].studentID <<","<<stuDB[i].numOfCredits<<","<<stuDB[i].overallGPA<< endl;
            return 1;
        }
    }
    return -1;
}

/**
 * methods that print students' information whose GPA is above the given number
 */
int count(double GPA){
    checkGPA(GPA);
    if(err > 0){
        err = 0;
        return -2;
    }
    int i;
    test = 0;
    for(i = 0; i < numOfStu; i++){
        if(stuDB[i].overallGPA >= GPA){
            cout <<stuDB[i].studentID <<","<<stuDB[i].numOfCredits<<","<<stuDB[i].overallGPA<< endl;
            test ++;
        }
    }
    if(test==0){
        cout <<"no students found"<< endl;
    }
    return 1;
}

/**
 * methods that print all students' information in the database
 */
void print(){
    int i;
    for(i = 0; i < numOfStu; i++){   
        cout <<stuDB[i].studentID <<","<<stuDB[i].numOfCredits<<","<<stuDB[i].overallGPA<< endl;
    }
}

int main() {
    bool done = false;
    char choice;

    int studentID;
    int numOfCredits;
    double overallGPA;
    char letterGrade;

    cout << "Enter your commands at the > prompt:" << endl;
    //main body
    while (!done) {
        cout << "> ";
        cin >> choice;

        err = 0;

        switch (choice) {
            //add Student
            case 'a':
                cin >> studentID >> numOfCredits >> overallGPA;

                if(addStudent(studentID, numOfCredits, overallGPA) == -1){
                    cout << "Student already on the list, no information changed." << endl;
                }
                break;

            case 'd':  
                cin >> studentID;  // read in the integer ID
                if(deleteStudent(studentID) == -1){
                    cout << "error - student "<< studentID <<" not found" << endl;
                }
                break;
               
            case 'u':
                cin >> studentID >> letterGrade >> overallGPA;
                if(updateStudent(studentID, letterGrade, overallGPA) == -1){
                    cout << "Student not found" << endl;
                }
                break;

            case 'c':
                cin >> overallGPA;
                count(overallGPA);
                break;

            case 'p':
                print();
                break;

            case 'q':  
                done = true;
                cout << "quit" << endl;
                break;

            // If the command is not one listed in the specification, for the 
            // purposes of this assignment, we will ignore it. 
            // Note that there will be multiple >'s printed out if there is 
            // additional information on the line (in addition to the unknown  
            // command character).  
            default: break;
        } // end switch

    } // end while

    return 0;
}
