#include <iostream>
#include <string>
#include <vector>

#include "functions.h"

using namespace std;

string center(string text, int width) {
    if (width <= text.size()) {
            return text;  // Return text as-is if width is too small
        }

    int padding = (width - text.size()) / 2;
    string box = string(padding, ' ') + text + string((padding + (width - text.size()) % 2), ' ');
    return box;
}

// string center(const string& text, int width) {
    // if (width <= text.size()) {
        // return text;
    // }
    // int padding = (width - text.size()) / 2;
    // string centered_text = string(padding, ' ') + text + string(width - text.size() - padding, ' ');
    // return centered_text;
// }

void display_log(const vector<vector<string>>& log) {
    cout << "\033[2J\033[1;1H";
    const int HEADER_PADDING = 69;
    const int COLUMN_WIDTH = 15;
    const int TABLE_PADDING = (HEADER_PADDING*2 + 8 - 4*COLUMN_WIDTH)/2;
    
    
    //This is just the header
    cout << string(HEADER_PADDING, '-') << " HabitLog " << string(HEADER_PADDING, '-') << endl << endl;
    cout << string(TABLE_PADDING, ' ');
        cout << center("Habit", COLUMN_WIDTH) << "|";
        cout << center("Rep", COLUMN_WIDTH) << "|" ;
        cout << center("Streak", COLUMN_WIDTH) << "|";
        cout << center("MaxStreak", COLUMN_WIDTH) << endl;

    for (int i = 0; i < log.size(); i++){
        cout << string(TABLE_PADDING, ' ');
        cout << center(oldchar_newchar(log[i][0], '_', ' '), COLUMN_WIDTH) << "|"; //oldchar_newchar will change the underscores for spaces
        //This is because of the tsp formatting convention for the habit log, 
        //where rep, strk, maxstrk are the last 3 elements of the vector
        for (int j = log[i].size() - 3; j < log[i].size(); j++){
             if (j != log[i].size() - 1) cout << center(log[i][j], COLUMN_WIDTH) << "|"; 
             else cout << center(log[i][j], COLUMN_WIDTH) << endl;	
        }
    }
    cout << endl <<string(HEADER_PADDING*2 + 8 + 2, '-');
}

void display_habit(const vector<vector<string>>& log, int habitnumber){
	cout << "\033[2J\033[1;1H";
    const int HEADER_PADDING = 69;
    const int COLUMN_WIDTH = 15;
    const int TOTAL_WIDTH = HEADER_PADDING*2 + 8;
    const int TABLE_PADDING = (TOTAL_WIDTH - 7*COLUMN_WIDTH)/2;

    int habitsize = log[habitnumber].size();
    cout << string(HEADER_PADDING*2 + 8 + 2, '-');
	cout << oldchar_newchar(log[habitnumber][0], '_', ' ') << endl << endl; //oldchar_newchar will change the underscores for spaces

    cout << string(HEADER_PADDING*2 + 8 + 2, '-');

	cout << "Reps: " << log[habitnumber][habitsize - 3] << endl;
	cout << "Streak: " << log[habitnumber][habitsize - 2] << endl;
	cout << "MaxStreak: " << log[habitnumber][habitsize - 1] << endl;

    cout << string(HEADER_PADDING*2 + 8 + 2, '-') << endl;

    cout << string(TABLE_PADDING, ' ');
    cout << center("Segunda", COLUMN_WIDTH) << "|";
	cout << center("Terça", COLUMN_WIDTH) << "|";
	cout << center("Quarta", COLUMN_WIDTH) << "|";
	cout << center("Quinta", COLUMN_WIDTH) << "|";
	cout << center("Sexta", COLUMN_WIDTH) << "|";
	cout << center("Sábado", COLUMN_WIDTH) << "|";
	cout << center("Domingo", COLUMN_WIDTH) << endl;

    cout << string(TABLE_PADDING, ' ');
	int i = 0;
	for (const char& binary : log[habitnumber][2]) {
	    if (i < 6) {  // For the first 6 items, add `|` after each element
	        if (binary == '1') {
	            cout << center("---Y---", COLUMN_WIDTH) << "|";
	        } else {
	            cout << center("---X---", COLUMN_WIDTH) << "|";
	        }
	    } else {  // For the last item, skip the final `|` and end with a newline
	        if (binary == '1') {
	            cout << center("---Y---", COLUMN_WIDTH);
	        } else {
	            cout << center("---X---", COLUMN_WIDTH);
	        }
	        cout << endl;
	    }
	    i++;
	}
	cout << endl;

    cout << string(HEADER_PADDING*2 + 8 + 2, '-');

    cout << "Descrição: " << endl << "    " << oldchar_newchar(log[habitnumber][1], '_', ' ') << endl;
    cout << string(HEADER_PADDING*2 + 8 + 2, '-') << endl << endl;
}

