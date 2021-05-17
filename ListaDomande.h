#ifndef LISTADOMANDE_H_
#define LISTADOMANDE_H_

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Domanda.h"
using namespace std;

class ListaDomande{
	private:
		Domanda d[16]; //16 perchè c'è anche il salta risposta
		int domanda_corrente;
		bool salta_domanda;
	public:
		ListaDomande();
		void carica_domande();
		void aggiungi_domanda();
		Domanda getDomanda();
		void aumenta_domanda_corrente();
		int get_domanda_corrente();
		void setSaltaDomanda();
		bool getSaltaDomanda();
		void visualizza_domande(Domanda d1[], int i);
};

#endif
