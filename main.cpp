#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "parsingfunctions.h"


using namespace std;

int main() {

<<<<<<< HEAD
    // pull request test
    //OTÁRIO
=======
    //Check if log exists, if not create it
    ofstream create_file("habitlog.txt", ios::app);
    cout << "---------------------------------- habitlog ----------------------------------" << endl;
    create_file.close();

    read_tsplog("habitlog.txt");

    return 0;
>>>>>>> ad62a0d (Basic parsing function for tsp files (text_string_spaced files) and new header)
}
