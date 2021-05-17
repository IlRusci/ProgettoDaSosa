#include "Domanda.h"

Domanda :: Domanda(){}

void Domanda :: setDomanda(string s){
	domanda = s;
}

void Domanda :: setRisposta(string s, int r){
	if (r<0 || r>3) cout<<"Numero risposta non valido"<<endl;
	else risposta[r] = s;
}

void Domanda :: setCorretta(int c){
	if (c<1 || c>4) cout<<"Numero risposta corretta deve essere tra 1 e 4"<<endl;
	else corretta = c;
}

string Domanda :: getDomanda(){
	return domanda;
}

string Domanda :: getRisposta(int r){
	if (r>=0 && r<=3) return risposta[r];
	else return "-1";
}

int Domanda :: getCorretta(){
	return corretta;
}
