#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

string prompt(string promptText){
    string finput = "\0";

    while(finput == "\0"){
	cout << promptText;    

    getline(cin, finput);
    
   	finput = oldchar_newchar(finput, ' ', '_');
    cout << endl;
    }
    return finput;	    
}

//Main functions
vector<string> create_new_habit() {
    
	//prompt Nome do habito
    string nome = prompt("Novo hábito: ");
    //descrição
    string descricao = prompt("Descrição: ");
	//prompt Dia tal contará?
	string codigo_dia = setweekdays();

	//cria o novo habito e coloca no log(vetor)
    vector<string> novo_habito = {nome, descricao, codigo_dia, "0", "0", "0"};
    return novo_habito;
}

int select_habit(const vector<vector<string>>& habitlog){
    string name = prompt("Nome do hábito: ");
    
    int habitnumber;
    for (int i = 0; i < habitlog.size(); i++){
        if (habitlog[i][0] == name){
        	habitnumber = i;
        	break;
        } 
    }
    return habitnumber;
}


void edit_habit(int habitnumber, vector<vector<string>>& habitlog){
    int back = 0;
    vector<string> funcvec = {"ChangeName", "ChangeDesc", "ChangeDays", 
    	    "ResetRep", "ResetStreak", "ResetMax", "Remove"};
    
    while (back == 0){ 
		int j = habitlog[habitnumber].size(); //Index of Reps
		display_habit(habitlog, habitnumber);
		
        char func = choose_func(funcvec, "Back", 'b');
	    
	    switch(func){
	    	case '0':{
	    	    string newname = prompt("New name");
				habitlog[habitnumber][0] = newname;
            }
	    	break;

	    	case '1':{
				string newdesc = prompt("New description: ");
	 			habitlog[habitnumber][1] = newdesc;
			}	
	    	break;

	    	case '2':{
				string newdays = setweekdays();
				habitlog[habitnumber][2] = newdays;
			}
	    	break;

	    	case '3':
				habitlog[habitnumber][j - 3] = "0";
	    	break;

	    	case '4':
				habitlog[habitnumber][j - 2] = "0";
	    	break;

	    	case '5':
				habitlog[habitnumber][j - 1] = "0";
	    	break;

			case '6':
				habitlog.erase(habitlog.begin() + habitnumber);
				back = 1;
			break;

	    	case 'b':
				back = 1;
	        break;

	        default:
	        cout << "Funcionalidade não implementada ainda :P";
	        break;
	    }
	}
}

//Inside functions
string setweekdays(){
	vector<string> dias_da_semana = {"segunda", "terça", "quarta", "quinta", "sexta", "sábado", "domingo"};
	string codigo_dia = "0000000";

	for (int i = 0; i < 7; i++){
    cout << "Haverá cobrança quanto ao hábito " << dias_da_semana[i] << "? [Y/N]" << endl;
        
    string resposta_yn; 
    cin >> resposta_yn;
    cin.ignore();
    if (resposta_yn == "Y"){
     	codigo_dia[i] = '1'; //salva o codigo 1011001 em relação as respostas
    }
    else if (resposta_yn != "N"){
        cout << "Resposta inválida";
        i -= 1;  
        } 
	}
	return codigo_dia;
}

char choose_func(const vector<string>& funcs, string exit, char exitchar){
	char func;
    int i = 0;

    cout << "Choose a functionality [";
	for (const string& funcname : funcs){
	cout << funcname << "(" << i << ") | ";
    i++;
    }
    cout << exit << "(" << exitchar << ")]" << endl;

    cin >> func;
    cin.ignore();
    return func;
}

