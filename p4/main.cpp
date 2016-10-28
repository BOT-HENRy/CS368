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
 * Assignment:    Programming Assignment 4
 ******************************************************************************/

#include <iostream>
#include "ComplexNumber.h"
#include "ComplexNumber.cpp"

using namespace std;

int main() {
  cout << "Enter a complex number C1:" << endl;
  ComplexNumber c1;
  cin >> c1;
  cout << "Enter a complex number C2:" << endl;
  ComplexNumber c2;
  cin >> c2;
  
  cout << "For C1 = " << c1 << " and C2 = " << c2 << " :" << endl;
  cout << "C1 + C2 = " << (c1 + c2) << endl;
  cout << "C1 - C2 = " << (c1 - c2) << endl;
  cout << "C1 * C2 = " << (c1 * c2) << endl;
  if(c1 == c2){
    cout << "C1 == C2 is " << "true" << endl;
    cout << "C1 != C2 is " << "false" << endl;
  }else{
    cout << "C1 == C2 is " << "false" << endl;
    cout << "C1 != C2 is " << "true" << endl;
  }
  ComplexNumber curC1 = c1;  //for resetting C1 to its original value
  cout << "After C1 += C2, C1 = " << (c1 += c2) << endl;
  c1 = curC1;
  cout << "After C1 -= C2, C1 = " << (c1 -= c2) << endl;
  c1 = curC1;
  cout << "After C1 *= C2, C1 = " << (c1 *= c2) << endl;

  return 0;
}
