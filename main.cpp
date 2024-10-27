#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "parsingfunctions.h"


using namespace std;

int main() {

    //Check if log exists, if not create it
    ofstream create_file("habitlog.txt", ios::app);
    cout << "---------------------------------- habitlog ----------------------------------" << endl;
    create_file.close();

    read_tsplog("habitlog.txt");

    return 0;
}
