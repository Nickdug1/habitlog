//void selevoid select_habit(string habit_name)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string center(string text, int width) {
    int padding = (width - text.size()) / 2;
    string box = string(padding, ' ') + text + string((padding + (width - text.size()) % 2), ' '); 
    return box;
} 

void display_log(vector<vector<string>> log) {
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
        cout << center(log[i][0], COLUMN_WIDTH) << "|";
        //This is because of the tsp formatting convention for the habit log, 
        //where rep, strk, maxstrk are the last 3 elements of the vector
        for (int j = log[i].size() - 3; j < log[i].size(); j++){
             if (j != log[i].size() - 1) cout << center(log[i][j], COLUMN_WIDTH) << "|"; 
             else cout << center(log[i][j], COLUMN_WIDTH) << endl;	
        }
    }
    cout << endl <<string(HEADER_PADDING*2 + 8 + 2, '-');
}



