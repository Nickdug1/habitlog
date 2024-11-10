#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;


char choose_func(vector<string> funcs, string exit, char exitchar){
	char func;
    int i = 0;

    cout << "Choose a functionality [";
	for (string& funcname : funcs){
	cout << funcname << "(" << i << ") | ";
    i++;
    }
    cout << exit << "(" << exitchar << ")]" << endl;

    cin >> func;
    return func;
}

void edit_habit(int habitnumber, vector<vector<string>>& habitlog){
    int back = 0;
    vector<string> funcvec = {"ChangeName", "ChangeDesc", "ChangeDays", 
    	    "ResetStreak", "Remove"};
    while (back == 0){ 
	    char func = choose_func(funcvec, "Back", 'b');
	    
	    switch(func){
	    	case '0':{
	    	    string newname;
				cout << "New name: ";
				cin >> newname;
				
				habitlog[habitnumber][0] = newname;
            }
	    	break;

	    	case '1':{
				string newdesc;
				cout << "New description: ";
				cin >> newdesc;

	 			habitlog[habitnumber][1] = newdesc;
			}	
	    	break;

	    	case '2':{
				string new_days;
			}
	    	break;

	    	case '3':

	    	break;

	    	case '4':

	    	break;
	    	
	    	case 'b':
				back = 1;
	        break;

	        default:
	        cout << "Not implemented yet :P";
	        break;
	    }
	}
}

int main(){
    vector<vector<string>> log = {{"OOOOO", "OAOOKS"}, {"IAA", "LOLO"}, {"habitu", "test"}};
    edit_habit(1, log);
	return 0;
}
