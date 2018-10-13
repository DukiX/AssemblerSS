#ifndef TABELASIMBOLA_H
#define TABELASIMBOLA_H

#include <map>
#include "Simbol.h"
using namespace std;

class TabelaSimbola {
private:
	map<string, Simbol*> mapaTabelaSimbola;
public:
	TabelaSimbola() {}
	bool dodajUTabeluSimbola(string, Simbol*);
	Simbol* uzmiIzTabeleSimbola(string);
	map<string, Simbol*>& getMapaTabelaSimbola() {
		return mapaTabelaSimbola;
	}

	friend ostream& operator<<(ostream& os, const TabelaSimbola& ts);
};

#endif // !TABELASIMBOLA_H

