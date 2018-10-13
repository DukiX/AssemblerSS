#ifndef INSTRUKCIJA_H
#define INSTRUKCIJA_H

#include <string>
using namespace std;

class Instrukcija {
public:
	string ime;
	string opcode;
	Instrukcija(string i, string o) :ime(i), opcode(o) {}
};

#endif // !INSTRUKCIJA_H
