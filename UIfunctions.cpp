#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

#include "functions.h"

using namespace std;

const time_t now = time(NULL);
time_t last_update;
const struct tm date_now = *localtime(&now);
const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "Novermber", "December"};

string prompt(string promptText)
{
	string finput = "\0";

	while (finput == "\0")
	{
		cout << promptText;

		getline(cin, finput);

		finput = oldchar_newchar(finput, ' ', '_');
		cout << endl;
	}
	return finput;
}

vector<string> create_new_habit()
{

	// prompt Nome do habito
	string nome = prompt("New habit: ");
	// descrição
	string descricao = prompt("Description: ");
	// prompt Dia tal contará?
	string codigo_dia = setweekdays();

	// cria o novo habito e coloca no log(vetor)
	vector<string> novo_habito = {nome, descricao, codigo_dia, "0", "0", "0", to_string(date_now.tm_mday), to_string(date_now.tm_mon + 1), to_string(date_now.tm_year + 1900)};
	return novo_habito;
}

int select_habit(const vector<vector<string>> &habitlog)
{
	string name = prompt("Name of habit: ");

	for (int i = 0; i < habitlog.size(); i++)
	{
		if (habitlog[i][0] == name)
		{
			return i;
		}
	}
	return -1;
}

void edit_habit(int habit_ID, vector<vector<string>> &habitlog)
{

	int back = 0;

	// Manipulate habits
	vector<string> funcvec = {"Change_Name", "Change_Description", "Change_Required_Days",
							  "Add_Repetition", "Remove"};

	while (back == 0)
	{

		// the amount of attributes inside a habit
		int habit_size = habitlog[habit_ID].size();

		display_habit(habitlog, habit_ID);

		char func = choose_func(funcvec, "Back", 'b');

		switch (func)
		{
		// Change_Name
		case '0':
		{
			string newname = prompt("New name");
			habitlog[habit_ID][0] = newname;
			break;
		}
		// Change_Description
		case '1':
		{
			string newdesc = prompt("New description: ");
			habitlog[habit_ID][1] = newdesc;
			break;
		}
		// Change_Required_Days
		case '2':
		{
			string newdays = setweekdays();
			habitlog[habit_ID][2] = newdays;
			break;
		}
		// Add_Repetition
		case '3':
		{
			increase_rep(habit_ID, habitlog);
			update_habit_date(habit_ID, habitlog);
			break;
		}
		// Remove
		case '4':
			habitlog.erase(habitlog.begin() + habit_ID);
			back = 1;
			break;
		// leave
		case 'b':
			back = 1;
			break;

		default:
			cout << "This Functionality does not exist :P";
			break;
		}
	}
}

string setweekdays()
{

	string weekdays[7] = {"monday", "tuesday", "wednesday", "thursday", "fryday", "saturday", "sunday"};

	// these numbers represent the required weekdays for this habit respectively -> 0 = not required | 1 = required
	string days_required = "0000000";

	for (int i = 0; i < 7; i++)
	{
		cout << "Will this habit be required on " << weekdays[i] << "? [Y/N]" << endl;

		string answer_y_n;
		cin >> answer_y_n;
		cin.ignore();

		if (answer_y_n == "Y" || answer_y_n == "y")
		{

			days_required[i] = '1';
		}
		else if (answer_y_n == "N" || answer_y_n == "n")
		{

			continue;
		}
		else if ((answer_y_n != "N" || answer_y_n != "n") && (answer_y_n != "Y" || answer_y_n != "y"))
		{

			cout << "Invalid answer" << endl;
			i -= 1;
		}
	}

	return days_required;
}

char choose_func(const vector<string> &funcs, string exit, char exitchar)
{

	char func;
	int i = 0;

	// show all current functionalities
	cout << "\nChoose a functionality [";
	for (const string &funcname : funcs)
	{
		cout << funcname << "(" << i << ") | ";
		i++;
	}
	cout << exit << "(" << exitchar << ")]" << endl;

	cin >> func;
	cin.ignore();

	// returns the funciotionality chosen by user
	return func;
}

void increase_rep(int habit_ID, vector<vector<string>> &habitlog)
{

	int streak = stoi(habitlog[habit_ID][4]) + 1;
	int max_streak = stoi(habitlog[habit_ID][5]);

	// inscrease rep by 1
	habitlog[habit_ID][3] = to_string(stoi(habitlog[habit_ID][3]) + 1);

	// increase streak by 1
	habitlog[habit_ID][4] = to_string(streak);

	// increase max_streak if possible
	if (streak > max_streak)
		habitlog[habit_ID][5] = to_string(streak);

	update_habit_date(habit_ID, habitlog);
}

void reset_streak(int habit_ID, vector<vector<string>> &habitlog)
{
	habitlog[habit_ID][4] = "0";
	update_habit_date(habit_ID, habitlog);
}

void update_habit_date(int habit_ID, vector<vector<string>> &habitlog)
{
	habitlog[habit_ID][6] = to_string(date_now.tm_mday);
	habitlog[habit_ID][7] = to_string(date_now.tm_mon + 1);
	habitlog[habit_ID][8] = to_string(date_now.tm_year + 1900);
}

void update_daily_log(vector<vector<string>> &habitlog)
{

	struct tm date_struct = *localtime(&now);

	// iterate every habit
	for (int habit_ID = 0; habit_ID < habitlog.size(); habit_ID++)
	{

		bool answered = false;

		// stay in loop while user does not answer
		while (!answered)
		{
			// if(time_difference > 10000000) {
			cout << "\033[2J\033[1;1H";
			string answer = prompt("Did you do " + habitlog[habit_ID][0] + " today? [Y/N]\n\nPress \"e\" to leave!\n");
			
			if (answer == "Y" || answer == "y")
			{
				increase_rep(habit_ID, habitlog);
				answered = true;
			}
			else if (answer == "N" || answer == "n")
			{
				answered = true;
			}
			else if (answer == "e")
			{
				answered = true;
				habit_ID = habitlog.size();
			}
		}
	}
}

void verify_required_habits(vector<vector<string>> &habitlog)
{

	struct tm date_struct = *localtime(&now);

	for (int habit_ID = 0; habit_ID < habitlog.size(); habit_ID++)
	{

		date_struct.tm_mday = stoi(habitlog[habit_ID][6]);
		date_struct.tm_mon = stoi(habitlog[habit_ID][7]) - 1;
		date_struct.tm_year = stoi(habitlog[habit_ID][8]);
		last_update = mktime(&date_struct);

		int time_difference = difftime(last_update, now);
		bool answered = false;

		// stay in loop if usar does not answer
		while (!answered)
		{
			// if habit was not done on last required day ask user if he did it or not
			//  if(time_difference > 10000000) {
			if (true)
			{
				cout << "\033[2J\033[1;1H";
				cout << "Note: You can ignore this message.\nThis functionality is being tested!\n\n";
				string last_update_date = months[stoi(habitlog[habit_ID][7]) - 1] + " " + habitlog[habit_ID][6] + ", " + habitlog[habit_ID][8];
				string answer = prompt("Do you confirm " + habitlog[habit_ID][0] + " was not done on [" + last_update_date + "] ? [Y/N]\n\nPress \"e\" to exit this warning!\n");
				if (answer == "Y" || answer == "y")
				{
					reset_streak(habit_ID, habitlog);
					answered = true;
				}
				else if (answer == "N" || answer == "n")
				{
					answered = true;
				}
				else if (answer == "e")
				{
					answered = true;
					// when habit_ID is equals to amount of habits functions ends
					habit_ID = habitlog.size();
				}
			}
			else
			{
				answered = true;
			}
		}
	}
	cout << "ta chegand aqui!";
}