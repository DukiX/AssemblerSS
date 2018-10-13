#include "RelokacioniZapis.h"
#include <iostream>

void RelokacioniZapis::dodajZapis(Zapis * zap){
	vektorRelokacioniZapis.push_back(zap);
}

ostream & operator<<(ostream & os, const RelokacioniZapis & rz){
	os << "Offset" << "\t" << "Tip" << "\t" << "Vrednost" << endl;
	for (int i = 0; i < rz.vektorRelokacioniZapis.size();i++) {
		os << rz.vektorRelokacioniZapis[i]->getOffset() << "\t" << rz.vektorRelokacioniZapis[i]->getTip() << "\t\t" << rz.vektorRelokacioniZapis[i]->getVrednost() << endl;
	}
	return os;
}
