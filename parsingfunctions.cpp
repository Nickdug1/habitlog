#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "functions.h"

using namespace std;

//read all habits (a habit per line) in habitlog.txt and returns a 2d vector of the file
vector<vector<string>> read_tsplog(string file){ //read text/space log

    vector<vector<string>> log;
    
    //Read log
    ifstream r_file(file);
    string line;

    //loop through each line of r_file and stores it in var line
    while (getline(r_file, line)) {

        istringstream lineStream(line);
        string word;

        vector<string> habit;
        //loop through all the words insine the line
        while (lineStream >> word) {
            //insert the current word in vector habit
            habit.push_back(word);
        }
        //insert all the habits insine log
        log.push_back(habit);
    }

    r_file.close();

    return log;
}

//replaces a char (oldchar) for another (newchar)
string oldchar_newchar(const string& word, char oldchar, char newchar){
    string changedword = word; 
	for (char& c : changedword){
		if (c == oldchar){
			c = newchar;
		}
	}
	return changedword;
} 

void write_tsplog(const vector<vector<string>>& log, const string& filename){
    ofstream w_file(filename);

    for (const vector<string>& habit : log){
    	for (const string& s : habit){
    		w_file << s << " ";
    	}
        w_file << endl;
    }     	

    w_file.close();
}
