#ifndef URAKHABITLOG_H
#define URAKHABITLOG_H

//parsing
std::vector<std::vector<std::string>> read_tsplog(std::string);
void write_tsplog(const std::vector<std::vector<std::string>>& log, const std::string& filename);
std::string oldchar_newchar(const std::string& word, char oldchar, char newchar);

//display
void display_log(const std::vector<std::vector<std::string>>& log);
void display_habit(const std::vector<std::vector<std::string>>& log, int habitnumber);

//UI
int select_habit(const std::vector<std::vector<std::string>>& habitlog);
std::vector<std::string> create_new_habit();
void edit_habit(int habitnumber, std::vector<std::vector<std::string>>& habitlog);

//UI_inside
std::string setweekdays();
char choose_func(const std::vector<std::string>& funcs, std::string exit, char exitchar);
std::string prompt(std::string promp);

#endif
