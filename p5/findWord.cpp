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
 * Assignment:    Programming Assignment 5
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 3){
		cout << "Proper usage: findWord <word> <file>" << endl;
		cout << "where" << endl;
		cout << "		<word> is a sequence of non-whitespace characters" << endl;
		cout << "		<file> is the file in which to search for the word" << endl;	
		cout << "example: findWord the test.txt" << endl;
		return 0;
	}else{
		string fileName = argv[2];
		string wordSearch = argv[1];
		ifstream myFile(fileName.c_str());
		int count = 0;
		if (myFile) {       // if the file was successfully opened	
			cout << "Searching for '" << wordSearch <<"' in file '" << fileName <<"'"<<endl;	
			string line;
        while (!getline(myFile, line).eof()) {
        	//cout << line[0] <<endl;
        	int ifPrint = 0;
        	if(line.length()>=wordSearch.length()){
        		for(int i = 0; i <= line.length()-wordSearch.length(); i++){
							int wordCheck = 0;
							for(int j = 0; j < wordSearch.length(); j++){
								if(line[i+j]==wordSearch[j]){
            			wordCheck++;
								}
							}
						
							if(wordCheck==wordSearch.length()){
							 ifPrint ++;
							 count ++;
							}
        		}
        	}
					
        	if(ifPrint>0){
        		 cout << "Line " << count << ": " << line << endl;
        	}
        }
			myFile.close();   // close the file now that we're done with it
			cout << "# occurrences of '" << wordSearch << "' = " << count << endl;
			return 0;

    } else {
        cerr << "File '" << fileName << "' could not be opened" << endl;
        myFile.close();
        return -1;
    }
    return 0;
	}
	


  return 0;
}
