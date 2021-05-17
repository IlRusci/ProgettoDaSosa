#ifndef AIUTO_H_
#define AIUTO_H_

#include "ListaDomande.h"

class Aiuto{
	private:
		bool aiuti_utilizzati[3];
	public:
		Aiuto();
		bool usa_aiuto(ListaDomande l, Domanda d, int i);
		int get_aiuti_usati();
		void risetta();
};

#endif
