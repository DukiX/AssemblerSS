#include "TabelaSimbola.h"
#include <iostream>

bool TabelaSimbola::dodajUTabeluSimbola(string ime, Simbol * simbol){
	if (mapaTabelaSimbola[ime] != 0) {
		return false;//postoji vec simbol
	}
	mapaTabelaSimbola[ime] = simbol;
	return true;
}

Simbol * TabelaSimbola::uzmiIzTabeleSimbola(string ime){
	return mapaTabelaSimbola[ime];
}

ostream & operator<<(ostream & os, const TabelaSimbola & ts){
	os << "Tabela simbola" << endl;
	os << endl;
	os << "Ime" << "\t" << "Sekcija" << "\t" << "Vrednost" << "\t" << "Vidljivost" << "\t" << "Redni broj" << endl;
	for (auto const& x : ts.mapaTabelaSimbola) {
		os << x.second->getIme() << "\t" << x.second->getSekcija() << "\t" << x.second->getVrednost() << "\t\t" << x.second->getVidljivost() << "\t\t" << x.second->getRedniBroj() << endl;
	}
	return os;
}
