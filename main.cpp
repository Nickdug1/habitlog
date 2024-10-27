#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
// #include <iomanip>  // For std::setw
#include "main.h"

using namespace std;

//main_functions

int main() {

    //Check if log exists, if not create it
    ofstream create_file("habitlog.txt", ios::app);
    create_file.close();

    vector<vector<string>> habitlog = read_tsplog("habitlog.txt");

    display_log(habitlog);
    
    //ask for functionality [SelectHabit | UpdateDailyLog | CreateNewHabit | ShowRecords]
        //select_habit() will display habit and give options: [Edit | Back]
            //edit_habit() will give options: [ChangeName | ChangeDesc | ChangeAtributtes | ResetStreak | Remove]
                //change_atributtes() will give options: [ChangeName | ChangeAttribute | Reset | Remove], Atributos serão 
                //log[i][2 + 2j], log[i][3 + 2j], log[i][4 + 2j] = attributej_nome, attribute type, attributej
                    //attribute types may be: additive, fixnumber, feeling
                    
        //update_daily_log() will prompt the user
            //Did you do 'current_habit' today? [Y/N]
            //Calculate streak and maxstreak
                //prompt the user if he is sure he lost the streak in case he says no
                //if Y: prompt the user to log attributes in accord with attribute type ['Urak' for leaving]
                //else go for next attribute until habit_lenght - 4
                //display habit stats again
                //prompt the user to redo or leave [redo | leave]

        //createnewhabit()

        //prompt the user [Monthly | Annual | All | Leave]
             //display and prompt user again 

    return 0;
}
