#ifndef START_H_
#define START_H_

#include "ListaDomande.h"
#include "Aiuto.h"
#include <fstream>

class Start{
	private:
		ListaDomande l;
		Aiuto a;
	public:
		Start(ListaDomande lista);
		void visualizza_domanda();
		void visualizza_montepremi();
		bool controlla_corretta(Domanda d, int risp);
		void visualizza_aiuto(Domanda d);
		void salva_partita();
};

#endif
