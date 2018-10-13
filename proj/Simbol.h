#ifndef SIMBOL_H
#define SIMBOL_H

#include <string>
using namespace std;

class Simbol {
private:
	string ime;
	string sekcija;
	int vrednost;
	char vidljivost;
	int redniBroj;
public:
	Simbol(string i, string s, int vr, char vid, int r) :ime(i), sekcija(s), vrednost(vr), vidljivost(vid), redniBroj(r) {}
	
	string getIme() {
		return ime;
	}
	void setIme(string i) {
		ime = i;
	}
	string getSekcija() {
		return sekcija;
	}

	void setSekcija(string s) {
		sekcija = s;
	}

	int getVrednost() {
		return vrednost;
	}

	void setVrednost(int v) {
		vrednost = v;
	}

	char getVidljivost() {
		return vidljivost;
	}

	void setVidljivost(char v) {
		vidljivost = v;
	}

	int getRedniBroj() {
		return redniBroj;
	}

	void setRedniBroj(int rb) {
		redniBroj = rb;
	}
};

#endif // !SIMBOL_H

