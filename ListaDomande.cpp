#include "ListaDomande.h"
#include <string>

ListaDomande :: ListaDomande(){
	carica_domande();
	domanda_corrente = 0;
}

void ListaDomande :: carica_domande(){
	Domanda dom[50];
	ifstream in;
	in.open("domande.txt");
	string s1;
	int c;
	for(int i=0; i<50; i++){ //TODO: far sì che legga tutte le domande
		if(getline(in,s1)){
			dom[i].setDomanda(s1);
			for (int j=0; j<4; j++){
				getline(in,s1);
				dom[i].setRisposta(s1,j);
			}
			in>>c;
			dom[i].setCorretta(c);
			getline(in,s1);
		}
	}
	in.close();
	//domande casuali dalle 50 che ho caricato
	int casuale;
	bool gia_inserito[50];
	for (int i=0; i<50; i++) gia_inserito[i] = false;

	for (int i=0; i<16; i++){
		casuale = rand()%50;
		if (!gia_inserito[casuale]){
			gia_inserito[casuale] = true;
			d[i].setDomanda(dom[casuale].getDomanda());
			for (int j=0; j<4; j++){
				d[i].setRisposta(dom[casuale].getRisposta(j),j);
			}
			d[i].setCorretta(dom[casuale].getCorretta());
		}
		else i--;
	}
}

void ListaDomande :: visualizza_domande(Domanda d1[], int i){
	string s1;
	for (int j=0; j<i; j++){
		cout<<d1[j].getDomanda()<<endl;
	}
	cout<<"-------------------------------------------------"<<endl;
	cin.clear(); cin.ignore();
	getline(cin,s1);
}

void ListaDomande :: aggiungi_domanda(){
	ofstream out;
	out.open("domande.txt", ios::app);
	system("clear");
	string s1;
	int c;
	cout<<"Inserisci testo domanda: ";
	cin.clear(); cin.ignore(1);
	getline(cin,s1);
	out << s1 << endl;
	for (int i=0; i<4; i++){
		cout<<"Inserisci testo risposta "<<i+1<<": ";
		getline(cin,s1);
		s1 = to_string(i+1)+") "+s1;
		out << s1 << endl;
	}
	do{
		cout<<"Inserisci risposta corretta: ";
		cin>>c;
		if (c<1 || c>4) cout<<"La risposta corretta deve essere un intero tra 1 e 4"<<endl;
	}while(c<1 || c>4);
	out << c << endl;
	out.close();
	cout<<"Domanda inserita correttamente"<<endl;
	cout<<"Premi invio per tornare indietro..."<<endl;
	getline(cin,s1);
}

Domanda ListaDomande :: getDomanda(){
	return d[domanda_corrente];
}

void ListaDomande :: aumenta_domanda_corrente(){
	domanda_corrente++;
}

int ListaDomande :: get_domanda_corrente(){
	return domanda_corrente;
}

void ListaDomande :: setSaltaDomanda(){
	salta_domanda = true;
}

bool ListaDomande :: getSaltaDomanda(){
	return salta_domanda;
}
