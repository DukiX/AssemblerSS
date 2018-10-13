#ifndef RELOKACIONIZAPIS_H
#define RELOKACIONIZAPIS_H

#include <string>
#include <vector>
#include "Zapis.h"
using namespace std;

class RelokacioniZapis {
private:
	vector<Zapis*> vektorRelokacioniZapis;
public:
	void dodajZapis(Zapis*);

	friend ostream& operator<<(ostream& os, const RelokacioniZapis& rz);
};

#endif // !RELOKACIONIZAPIS_H
