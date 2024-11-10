#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

string oldchar_newchar(const string& word, char oldchar, char newchar){
    string changedword = word; 
	for (char& c : changedword){
		if (c == oldchar){
			c = newchar;
		}
	}
	return changedword;
} 

string prompt(string promptText){
    string name;

	cout << promptText;    

    getline(cin, name);
    
   	name = oldchar_newchar(name, ' ', '_');
    cout << endl;

    return name;	    
}

int main(){
	string test = prompt("E aí boy? ");
	cout << test;
}
