#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

vector<vector<string>> read_tsplog(string file){ //read text/space log

    vector<vector<string>> log;

    //Read log
    ifstream r_file(file);
    string line;

    while (getline(r_file, line)) {
        istringstream lineStream(line);
        string word;

        vector<string> habit;

        while (lineStream >> word) {
            habit.push_back(word);
            // teste1: cout << word << " ";
        }
        log.push_back(habit);
        // teste1: cout << endl;
    }

    r_file.close();

    return log;
}

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
