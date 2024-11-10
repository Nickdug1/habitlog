#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

vector<string> create_new_habit() {
    
	//prompt Nome do habito
    string nome;
	cout << "Escreva o nome do novo hábito: ";
	cin >> nome;
	cin.ignore();

    //descrição
    string descricao;
    cout << "Qual a descrição do hábito?" << endl;
    getline(cin, descricao);
    cout << endl;
    //Parser " " to "_" (criar função em parsingfunctions)
	oldchar_newchar(descricao, ' ', '_');
	//prompt Dia tal contará?
	vector<string> dias_da_semana = {"segunda", "terça", "quarta", "quinta", "sexta", "sábado", "domingo"};
	string codigo_dia = "0000000";

    for (int i = 0; i < 7; i++){
	    cout << "Haverá cobrança quanto ao hábito " << dias_da_semana[i] << "? [Y/N]" << endl;
        
        string resposta_yn; 
        cin >> resposta_yn;
        if (resposta_yn == "Y"){
        	codigo_dia[i] = '1'; //salva o codigo 1011001 em relação as respostas
        }
        //else if (resposta_yn != ("N" && "Y")){
        //    codigo_dia[i] = "0"; 
        //}
        else if (resposta_yn != "N"){
            cout << "Resposta inválida";
            i -= 1;  
        } 
	}

	//cria o novo habito e coloca no log(vetor)
    vector<string> novo_habito = {nome, descricao, codigo_dia, "0", "0", "0"};
    return novo_habito;
}

int select_habit(vector<vector<string>> habitlog){
    string name;
    cout << "Nome do hábito: ";
    cin >> name;
    cout << endl;
    
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
    	    "ResetStreak", "Remove"};
    while (back == 0){ 
	    char func = choose_func(funcvec, "Back", 'b');
	    
	    switch(func){
	    	case '0':{
	    	    string newname;
				cout << "New name: ";
				cin >> newname;
				cout << endl;
				habitlog[habitnumber][0] = newname;
            }
	    	break;

	    	case '1':{
				string newdesc;
				cout << "New description: ";
				cin >> newdesc;
				cout << endl;
	 			habitlog[habitnumber][1] = newdesc;
			}	
	    	break;

	    	case '2':{
				string new_days;
			}
	    	break;

	    	case '3':

	    	break;

	    	case '4':

	    	break;
	    	
	    	case 'b':
				back = 1;
	        break;

	        default:
	        cout << "Not implemented yet :P";
	        break;
	    }
	}
}

char choose_func(vector<string> funcs, string exit, char exitchar){
	char func;
    int i = 0;

    cout << "Choose a functionality [";
	for (string& funcname : funcs){
	cout << funcname << "(" << i << ") | ";
    i++;
    }
    cout << exit << "(" << exitchar << ")]" << endl;

    cin >> func;
    return func;
}

