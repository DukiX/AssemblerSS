#ifndef ASEMBLER_H
#define ASEMBLER_H

#include <string>
#include <map>
#include "TabelaSimbola.h"
#include "TabelaSekcija.h"
#include "Instrukcija.h"
#include "RelokacioniZapis.h"
using namespace std;

class Asembler {
private:
	TabelaSimbola* tsim;
	TabelaSekcija* tsek;
	int pocetnaAdresa;
	map<string, Instrukcija*> sveInstrukcije;
	void dodajKod(string, int, Simbol*, string&, string&, string&);
	bool isDigitCEO(string a);
	void dodajKodBezLab(string, int, string, string&, string&, string&);
	void dodajRelZapis(int offset, Simbol*s, RelokacioniZapis* relText, RelokacioniZapis* relData, RelokacioniZapis*relRodata,bool apsolutno,string tekucaSekcija);
	string intToHex(int i);
	string binaryToHex(string binNiz);
	void dodajKodPcRel(Simbol*, string&);
public:
	Asembler(TabelaSimbola* tsimb, TabelaSekcija* tsekc, int pocetnaAdr);
	bool prviProlaz(ifstream& ulaz);
	bool drugiProlaz(ifstream& ulaz,RelokacioniZapis*, RelokacioniZapis*, RelokacioniZapis*,string&,string&,string&);
};

#endif // !ASEMBLER_H
