#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Menu.h"
using namespace std;

Menu :: Menu() : l(), s(l){
	visualizza_menu();
}

void Menu :: visualizza_menu(){
	int x;
	do{
	        system("clear");
        	cout<<"CHI VUOL ESSERE MILIONARIO"<<endl<<endl;
        	cout<<"1) Inizia gioco"<<endl;
        	cout<<"2) Aggiungi domanda"<<endl;
        	cout<<"3) Record"<<endl;
        	cout<<"4) Crediti"<<endl;
        	cout<<"5) Esci"<<endl<<endl;
        	cout<<"Inserisci opzione che vuoi scegliere"<<endl;
		cin>>x;
		switch(x){
			case 1:
				s.visualizza_domanda();
				break;
			case 2:
				l.aggiungi_domanda();
				break;
			case 3:
				visualizza_record();
				break;
			case 4:
				visualizza_crediti();
				break;
			case 5:
				cout<<"Grazie per aver giocato"<<endl;
				return;
			default:
				cout<<"Opzione non valida, riprovare"<<endl;
				break;
		}
	}while(true);
}

void Menu :: visualizza_record(){
	ifstream in;
	in.open("record.txt");
	string s1;
	system("clear");
	while(getline(in,s1)){
		cout<<s1<<endl;
	}
	cout<<endl<<"Premere invio per tornare nel menu..."<<endl;
	cin.clear(); cin.ignore(1);
	getline(cin,s1);
}

void Menu :: visualizza_crediti(){
	system("clear");
	string s1;
	cout<<"CREDITI"<<endl<<endl;
	cout<<"Non ringrazio nessuno"<<endl<<endl;
	cout<<"Premere invio per tornare nel menu..."<<endl;
	cin.clear(); cin.ignore(1);
	getline(cin,s1);
}
