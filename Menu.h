#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <cstdlib>
#include "ListaDomande.h"
#include "Start.h"
using namespace std;

class Menu{
	private:
		ListaDomande l;
		Start s;
	public:
		Menu();
		void visualizza_menu();
		void visualizza_record();
		void visualizza_crediti();
};

#endif
