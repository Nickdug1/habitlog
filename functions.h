#ifndef URAKHABITLOG_H
#define URAKHABITLOG_H

//parsing
std::vector<std::vector<std::string>> read_tsplog(std::string);
void write_tsplog(const std::vector<std::vector<std::string>>& log, const std::string& filename);
void oldchar_newchar(std::string& word, char oldchar, char newchar);

//display and UI
void display_log(std::vector<std::vector<std::string>> log);
void select_habit(std::string habit_name);
std::vector<std::string> create_new_habit();
char choose_func(std::vector<std::string> funcs, std::string exit, char exitchar);
void edit_habit(int habitnumber, std::vector<std::string>& habitlog);



#endif
