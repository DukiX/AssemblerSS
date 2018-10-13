#ifndef ZAPIS_H
#define ZAPIS_H

#include <string>
using namespace std;

class Zapis {
private:
	string offset;
	string tip;
	int vrednost;
public:
	Zapis(string o,string t,int v):offset(o),tip(t),vrednost(v){}

	string getOffset() {
		return offset;
	}
	void setOffset(string o) {
		offset = o;
	}

	string getTip() {
		return tip;
	}
	void setTip(string t) {
		tip = t;
	}

	int getVrednost() {
		return vrednost;
	}
	void setVrednost(int v) {
		vrednost = v;
	}
};

#endif // !ZAPIS_H
