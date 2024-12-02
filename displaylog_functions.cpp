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
        //log.size() -> 9 -> name, desc, weekdays, rep, streak, max_streak, day, month, year
        for (int j = log[i].size() - 3; j < log[i].size(); j++){
             if (j != log[i].size() - 1) cout << center(log[i][j-3], COLUMN_WIDTH) << "|"; 
             else cout << center(log[i][j-3], COLUMN_WIDTH) << endl;	
        }
    }
    cout << endl <<string(HEADER_PADDING*2 + 8 + 2, '-');
}

void display_habit(const vector<vector<string>>& log, int habit_ID){
    //clear screen for linux
	cout << "\033[2J\033[1;1H";
    const int HEADER_PADDING = 69;
    const int COLUMN_WIDTH = 15;
    const int TOTAL_WIDTH = HEADER_PADDING*2 + 8;
    const int TABLE_PADDING = (TOTAL_WIDTH - 7*COLUMN_WIDTH)/2;

    int habitsize = log[habit_ID].size();
    // cout << string(HEADER_PADDING*2 + 8 + 2, '-');
	cout << endl << oldchar_newchar(log[habit_ID][0], '_', ' ') << endl; //oldchar_newchar will change the underscores for spaces

    // cout << string(HEADER_PADDING*2 + S8 + 2, '-') << endl;

	cout << "Reps: " << log[habit_ID][3] << endl;
	cout << "Streak: " << log[habit_ID][4] << endl;
	cout << "MaxStreak: " << log[habit_ID][5] << endl;
    cout << "Description: " << oldchar_newchar(log[habit_ID][1], '_', ' ') << endl;

    cout << string(HEADER_PADDING*2 + 8 + 2, '-') << endl;

    cout << string(TABLE_PADDING, ' ');
    cout << center("Monday", COLUMN_WIDTH) << "|";
	cout << center("Tuesday", COLUMN_WIDTH) << "|";
	cout << center("Wednesday", COLUMN_WIDTH) << "|";
	cout << center("Thursday", COLUMN_WIDTH) << "|";
	cout << center("Friday", COLUMN_WIDTH) << "|";
	cout << center("Saturday", COLUMN_WIDTH) << "|";
	cout << center("Sunday", COLUMN_WIDTH) << endl;

    cout << string(TABLE_PADDING, ' ');
	int i = 0;
	for (const char& binary : log[habit_ID][2]) {
	    if (i < 6) {  // For the first 6 items, add `|` after each element
	        if (binary == '1') {
	            cout << center("required", COLUMN_WIDTH) << "|";
	        } else {
	            cout << center("not_required", COLUMN_WIDTH) << "|";
	        }
	    } else {  // For the last item, skip the final `|` and end with a newline
	        if (binary == '1') {
	            cout << center("required", COLUMN_WIDTH);
	        } else {
	            cout << center("not_required", COLUMN_WIDTH);
	        }
	        cout << endl;
	    }
	    i++;
	}
	cout << endl;

    cout << string(HEADER_PADDING*2 + 8 + 2, '-') << endl << endl;
}

