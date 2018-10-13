#include "TabelaSekcija.h"
#include <iostream>

void TabelaSekcija::dodajSekciju(string ime, Sekcija * sek){
	if (mapaTabelaSekcija[ime] != 0) {
		return;
		//vec postoji ta sekcija
	}
	mapaTabelaSekcija[ime] = sek;
}

Sekcija * TabelaSekcija::uzmiSekciju(string ime){
	return mapaTabelaSekcija[ime];
}

ostream & operator<<(ostream & os, const TabelaSekcija & ts){
	os << "Tabela sekcija" << endl;
	os << endl;
	os << "Ime" << "\t" << "Poc.Adresa" << "\t" << "Velicina" << endl;
	for (auto const& x : ts.mapaTabelaSekcija) {
		os << x.second->getIme() << "\t" <<  x.second->getPocetnaAdresa() << "\t\t" << x.second->getVelicina() << endl;
	}
	return os;
}
