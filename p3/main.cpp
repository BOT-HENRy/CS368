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
 
/**
 * In this program assignment, I added the proper memory management for the 
 * Student and SortedList classes.
 * In both Student and SortedList classes I added destructors, copy constructors,
 * and copy assignment operators. 
 * In the SortedList classes I also added freeList and copyList which are 
 * Auxiliary Functions that help the implementation of destructors, copy constructors,
 * and copy assignment operators. 
 * Before in the remove(int studentID) function in Sortedlist, I remove the listnode
 * by link the one before with the one after. For this assignment, I also detele the 
 * listnode so there will be no memory leak. 
 *
 * In the main.cpp, I create 5 students, update some courses information for 3 of them, 
 * then I create a list and add the students into the list. In the end, I delete 3 of them 
 * from the list and then print out the list.
 *
 * By using the Valgrind tool, it shows there is no memory leak. It says "total heap usage:
 * 5 allocs, 5 frees, 80 bytes allocated" and "All heap blocks were freed -- no leaks 
 * are possible"
 * But if I run main.cpp using the classes in assignment 2, it shows there are memory leaks.
 * It says "total heap usage: 8 allocs, 0 frees, 6,104 bytes allocated"
 * The leak summary says 
 *    definitely lost: 6,072 bytes in 6 blocks
 *    indirectly lost: 32 bytes in 2 blocks
 *
 * The differences between the Student class and the SortedList class is that the Student class 
 * will not cause the program to have a memory leak but SortedList class might. So by updating 
 * the SortedList class we can prevent memory leak.
 *
 * @Yizhe Qu
 */

#include <iostream>
#include <algorithm> 
#include "Student.h"
#include "SortedList.h"
#include "Student.cpp"
#include "SortedList.cpp"

using namespace std;

int main() {
    //add students
    Student stu1 = Student(111222);
    Student stu2 = Student(222333);
    Student stu3 = Student(333444);
    Student stu4 = Student(444555);
    Student stu5 = Student(555666);
    //add courses
    stu1.update(302, 3, 15, Fall, 'A');
    stu2.update(302, 3, 15, Fall, 'B');
    stu2.update(367, 3, 15, Fall, 'A');
    stu3.update(368, 3, 15, Fall, 'A');
    stu3.update(352, 3, 15, Fall, 'A');
    stu3.update(354, 3, 15, Fall, 'B');

    //create list
    SortedList list = SortedList();
    list.insert(&stu1);
    list.insert(&stu2);
    list.insert(&stu3);
    list.insert(&stu4);
    list.insert(&stu5);

    //remove student
    list.remove(222333);  //remove second
    list.remove(555666);  //remove last
    list.remove(111222);  //remove first

    //print list
    list.print();

    return 0;
}
