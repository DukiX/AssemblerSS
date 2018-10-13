#ifndef TABELASEKCIJA_H
#define TABELASEKCIJA_H

#include <string>
#include <map>
#include "Sekcija.h"
using namespace std;

class TabelaSekcija {
private:
	map<string, Sekcija*> mapaTabelaSekcija;
public:
	void dodajSekciju(string, Sekcija*);
	Sekcija* uzmiSekciju(string);

	friend ostream& operator<<(ostream& os, const TabelaSekcija& ts);
};

#endif // !TABELASEKCIJA_H

