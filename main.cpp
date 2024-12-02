#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include "functions.h"
// #include <iomanip>  // For std::setw

using namespace std;

int main() {

    //Check if log exists, if not create it
    ofstream create_file("habitlog.txt", ios::app);
    create_file.close();

    //variables to allow us to measure time
    time_t now, last_update;
    now = time(NULL);
    struct tm date_struct = *localtime(&now);

    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "Novermber", "December"};

    vector<vector<string>> habitlog = read_tsplog("habitlog.txt"); // habito = <habitname desc 1001110 rep streak maxstreak day_of_last_update month_of_last_update year_of_last_update>

    //Iterate through habits and verifies if the last required day of the current habit matches the last update, if not, ask the user if the habit was done or not, if wasn't done then reset streak. (give the user the option to leave this iteration every iteration)
    for (int habit_ID = 0; habit_ID < habitlog.size(); habit_ID++) {

        date_struct.tm_mday = stoi(habitlog[habit_ID][6]);
        date_struct.tm_mon = stoi(habitlog[habit_ID][7]) -1;
        date_struct.tm_year = stoi(habitlog[habit_ID][8]);
        last_update = mktime(&date_struct);

        int time_difference = difftime(last_update, now);
        bool answered = false;

        while(!answered) {
            // if(time_difference > 10000000) {
            if(true) {
                cout << "\033[2J\033[1;1H";
                cout << "Note: You can ignore this message.\nThis functionality is being tested!\n\n";
                string last_update_date = months[stoi(habitlog[habit_ID][7]) - 1] + " " +habitlog[habit_ID][6] + ", " + habitlog[habit_ID][8];
                string answer = prompt("Do you confirm " + habitlog[habit_ID][0] + " was not done on [" + last_update_date + "] ? [Y/N]\n\nPress \"e\" to exit this warning!\n");    
                if(answer == "Y" || answer == "y") {
                    reset_streak(habit_ID, habitlog);
                    answered = true;
                } else if(answer == "N" || answer == "n") {
                    answered = true;
                }
                else if(answer == "e") {
                    answered = true;
                    habit_ID =  habitlog.size();
                }    
                
            } else {
                answered = true;
            }
            
        }

    }

    int exit = 0;

    while (exit == 0) {
        display_log(habitlog);

        //ask for functionality [SelectHabit | UpdateDailyLog | CreateNewHabit | ShowRecords]
        vector<string> funcvec = {"SelectHabit", "UpdateDailyLog", "CreateNewHabit", "ShowRecords"};
        char func = choose_func(funcvec, "Exit", 'e');
        switch(func){

            //SelectHabit
            case '0':
                int habit_ID;
                habit_ID = select_habit(habitlog); //Return ID of the selected habit
                if(habit_ID == -1) break;
                edit_habit(habit_ID, habitlog);
                break;

            //Case "1":            
            //update_daily_log() will prompt the user
                //iterate through habits and ask user if it was done today [Y/N]
                    //
                //Did you do 'current_habit' today? [Y/N]
                //Calculate streak and maxstreak
                    //prompt the user if he is sure he lost the streak in case he says no
                    //if Y: prompt the user to log attributes in accord with attribute type ['Urak' for leaving]
                    //else go for next attribute until habit_lenght - 4
                    //display habit stats again
                    //prompt the user to redo or leave [redo | leave]
            //break;

            //createnewhabit
            case '2':
                habitlog.push_back(create_new_habit());
                break;

            //showrecords
            //Case "3":
                //showrecords() prompt the user [Monthly | Annual | All | Leave]
                //display and prompt user again 
                //break;

            case 'e': //leave
                write_tsplog(habitlog, "habitlog.txt");
                exit = 1;
                break;
            
            default:
                cout << "This Functionality was not implemented yet :P [Press anything to leave]";
                string temp;
                getline(cin, temp);
        }
    }
        
    return 0;
}
