#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "parsingfunctions.h"

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
            cout << word << " ";
        }
        log.push_back(habit);
        cout << endl;
    }

    r_file.close();

    return log;
}