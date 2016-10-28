/*
 * This is a very simple program which demonstrates how to access 
 * command line arguments.  Try the following commands:
 *     g++ echoArgs.cpp
 *     a.out
 *     a.out 123 abcd
 */
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "Echoing command line arguments (one per line):" << endl;
    for (int i = 0; i < argc; i++)
        cout << argv[i] << endl;
    return 0;
}
