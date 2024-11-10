#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
// #include <iomanip>  // For std::setw
#include "functions.h"

using namespace std;

//main_functions

int main() {

    //Check if log exists, if not create it
    ofstream create_file("habitlog.txt", ios::app);
    create_file.close();

    vector<vector<string>> habitlog = read_tsplog("habitlog.txt"); // habito = <habitname desc 1001110 rep streak maxstreak>  

    int exit = 0;
    while (exit == 0){
    display_log(habitlog);

    //ask for functionality [SelectHabit | UpdateDailyLog | CreateNewHabit | ShowRecords]
    vector<string> funcvec = {"SelectHabit", "UpdateDailyLog", "CreateNewHabit", "ShowRecords"};
    char func = choose_func(funcvec, "Exit", 'e');
    switch(func){
    	case '0':
	        int habitnumber;
	        habitnumber = select_habit(habitlog); //select_habit() gives back index
	        //edit_habit() options: [ChangeName | ChangeDesc | ChangeDays | ResetRep | ResetStreak | ResetMaxStreak | Remove]
	        edit_habit(habitnumber, habitlog);
        break;
        //Case "1":            
        //update_daily_log() will prompt the user
            //Did you do 'current_habit' today? [Y/N]
            //Calculate streak and maxstreak
                //prompt the user if he is sure he lost the streak in case he says no
                //if Y: prompt the user to log attributes in accord with attribute type ['Urak' for leaving]
                //else go for next attribute until habit_lenght - 4
                //display habit stats again
                //prompt the user to redo or leave [redo | leave]
        //break;
        case '2':
        	//createnewhabit
        	habitlog.push_back(create_new_habit());
        
        break; 
        //Case "3":
        //showrecords() prompt the user [Monthly | Annual | All | Leave]
             //display and prompt user again 
        //break;
        case 'e':
            write_tsplog(habitlog, "habitlog.txt");
            exit = 1;
        break;
        
        default:
        	cout << "Funcionalidade não implementada ainda :P [Press anything to leave]";
			string temp;
        	getline(cin, temp);
    }
    }
        
    return 0;
}
