// to run the program type "g++ main.cpp parsingfunctions.cpp UIfunctions.cpp displaylog_functions.cpp -o name_of_file" then type "./name_of_file.exe"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

#include "functions.h"

using namespace std;

void run(vector<vector<string>> &habitlog);

// Check if log exists, if not create it
void create_file()
{
    ofstream file("habitlog.txt", ios::app);

    // if file was not created exit program
    if (!file.is_open())
    {
        cout << "habit log file was not found!";
        exit(0);
    }
    file.close();
}

int main()
{

    // create habitlog file
    create_file();

    // habit = <habitname desciption 1001110 rep streak maxstreak day_of_last_update month_of_last_update year_of_last_update>
    vector<vector<string>> habitlog = read_tsplog("habitlog.txt");

    // Verifies if the the last required day in each habit was done or not
    verify_required_habits(habitlog);

    // run the program
    run(habitlog);

    return 0;
}

void run(vector<vector<string>> &habitlog)
{

    int exit = 0;

    while (exit == 0)
    {
        display_log(habitlog);

        // ask for functionality [SelectHabit | UpdateDailyLog | CreateNewHabit | ShowRecords]
        vector<string> funcvec = {"SelectHabit", "UpdateDailyLog", "CreateNewHabit", "ShowRecords"};
        char func = choose_func(funcvec, "Exit", 'e');
        switch (func)
        {

        // SelectHabit
        case '0':
            int habit_ID;
            habit_ID = select_habit(habitlog); // Return ID of the selected habit
            if (habit_ID == -1)
                break;
            edit_habit(habit_ID, habitlog);
            break;

        case '1':
            update_daily_log(habitlog);
            break;
        // update_daily_log() will prompt the user
        // iterate through habits and ask user if it was done today [Y/N]
        // Did you do 'current_habit' today? [Y/N]
        // Calculate streak and maxstreak
        // prompt the user if he is sure he lost the streak in case he says no
        // if Y: prompt the user to log attributes in accord with attribute type ['Urak' for leaving]
        // else go for next attribute until habit_lenght - 4
        // display habit stats again
        // prompt the user to redo or leave [redo | leave]
        // break;

        // createnewhabit
        case '2':
            habitlog.push_back(create_new_habit());
            break;

            // showrecords
            // Case "3":
            // showrecords() prompt the user [Monthly | Annual | All | Leave]
            // display and prompt user again
            // break;

        case 'e': // leave
            write_tsplog(habitlog, "habitlog.txt");
            exit = 1;
            break;

        default:
            cout << "This Functionality was not implemented yet :P [Press anything to leave]";
            string temp;
            getline(cin, temp);
        }
    }
}
