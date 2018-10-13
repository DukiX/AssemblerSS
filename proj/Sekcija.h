#ifndef SEKCIJA_H
#define SEKCIJA_H

#include <string>
using namespace std;

class Sekcija {
private:
	string ime;
	int pocetnaAdresa;
	int velicina;
public:
	Sekcija(string i, int pa, int v) :ime(i), pocetnaAdresa(pa), velicina(v) {}
	string getIme() {
		return ime;
	}
	void setIme(string i) {
		ime = i;
	}

	int getPocetnaAdresa() {
		return pocetnaAdresa;
	}

	void setPocetnaAdresa(int pa) {
		pocetnaAdresa = pa;
	}

	int getVelicina() {
		return velicina;
	}
	
	void setVelicina(int v) {
		velicina = v;
	}
};

#endif // !SEKCIJA_H

