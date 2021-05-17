#ifndef DOMANDA_H_
#define DOMANDA_H_

#include <iostream>
#include <cstdlib>
using namespace std;

class Domanda{
	private:
		string domanda;
		string risposta[4];
		int corretta;
	public:
		Domanda();
		void setDomanda(string s);
		void setRisposta(string s, int r);
		void setCorretta(int c);
		string getDomanda();
		string getRisposta(int r);
		int getCorretta();
};

#endif
