#include "Start.h"

Start :: Start(ListaDomande lista) : a(){
	l = lista;
}

void Start :: visualizza_domanda(){
	Domanda d;
	string s1;
	char c;
	int risp;
	do{
		system("clear");
		d = l.getDomanda();
		cout<<d.getDomanda()<<endl<<endl;
		for (int i=0; i<4; i++)
			cout<<d.getRisposta(i)<<endl;
		do{
		cout<<endl<<"Inserisci risposta. Inserisci 5 se vuoi usare un aiuto."<<endl;
		do{
			cin>>risp;
			if (risp<1 || risp>5) cout<<"La risposta deve essere un valore da 1 a 4, riprova"<<endl;
		}while(risp<1 || risp>5);
		if (risp == 5) visualizza_aiuto(d);
		}while(risp==5);
		if (controlla_corretta(d,risp)){
			cout<<"Risposta corretta!!"<<endl;
			cout<<"Premi invio per andare avanti..."<<endl;
			getline(cin,s1);
			l.aumenta_domanda_corrente();
			visualizza_montepremi();
			if ((l.get_domanda_corrente()==15 && !l.getSaltaDomanda()) || (l.get_domanda_corrente()==16)){
				cout<<"Hai vinto!!!"<<endl;
				salva_partita();
			}
		}
		else{
			cout<<"Risposta non corretta!!"<<endl;
			salva_partita();
		}
	}while(controlla_corretta(d,risp) && (l.get_domanda_corrente()<15 || (l.get_domanda_corrente() == 15 && l.getSaltaDomanda())));
	a.risetta();
}


void Start :: salva_partita(){
	char c;
	string s1;
	cout<<"Vuoi salvare la partita? (y/n)"<<endl;
	do{
		cin>>c;
                if (c!='y' && c!='n') cout<<"Risposta non valida, riprova"<<endl;
        }while(c!='y' && c!='n');

	if (c=='y'){
		cout<<"Inserisci il tuo nome"<<endl;
		cin.clear(); cin.ignore(1);
		getline(cin,s1);
		ofstream out;
		out.open("record.txt", ios::app);
		out<<s1<<" "<<l.get_domanda_corrente()<<" "<<a.get_aiuti_usati()<<endl;
		out.close();
	}
}

void Start :: visualizza_montepremi(){
	system("clear");
	string s1;
	int v[15] = {50,100,200,300,500,1000,2000,4000,8000,16000,32000,64000,125000,500000,1000000};
	for (int i=15; i>0; i--){
		if (i == l.get_domanda_corrente())
			cout<<"- "<<i<<") "<<v[i-1]<<endl;
		else
			cout<<i<<") "<<v[i-1]<<endl;
	}
	cout<<"Premi invio per andare avanti..."<<endl;
	getline(cin,s1);
}

bool Start :: controlla_corretta(Domanda d, int risp){
	if (d.getCorretta() == risp) return true;
	return false;
}

void Start :: visualizza_aiuto(Domanda d){
	int x;
	cout<<"Inserisci l'aiuto (1: chiama a casa, 2: salta domanda, 3: dimezza le risposte)"<<endl;
	do{
		cin>>x;
		if (x<1 || x>3) cout<<"Devi inserire un numero da 1 a 3"<<endl;
	}while(x<1 || x>3);
	a.usa_aiuto(l,d,x);
}
