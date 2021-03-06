// proj.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <string>
#include "TabelaSimbola.h"
#include "Simbol.h"
#include "TabelaSekcija.h"
#include <sstream>
#include "Asembler.h"
#include "RelokacioniZapis.h"
using namespace std;

int main(int argc, char * argv[]) {
	ifstream ulaz;
	string ulazIme = argv[1];
	ulaz.open(ulazIme);
	if (ulaz.is_open() == 0) {
		cout << "Ulazni fajl ne postoji";
		return 0;
	}
	TabelaSimbola* tsim = new TabelaSimbola();
	TabelaSekcija* tsek = new TabelaSekcija();
	int pocAdr = stoi(argv[2]);
	Asembler a(tsim, tsek,pocAdr);
	bool uspesanPrvi = a.prviProlaz(ulaz);
	ulaz.close();
	if (!uspesanPrvi) {
		return 0;
	}
	ulaz.open(ulazIme);
	RelokacioniZapis* relText = new RelokacioniZapis();
	RelokacioniZapis* relData = new RelokacioniZapis();
	RelokacioniZapis* relRodata = new RelokacioniZapis();
	string codeText, codeData, codeRodata;
	cout << endl;
	cout << *tsim;
	cout << endl;
	cout << endl;
	cout << *tsek;
	cout << endl;
	bool uspesanDrugi=a.drugiProlaz(ulaz,relText,relData,relRodata, codeText, codeData, codeRodata);
	ulaz.close();
	if (!uspesanDrugi) {
		return 0;
	}
	
	cout << "Relokaciona tabela za Text sekciju:" << endl;
	cout << *relText;
	cout << endl;
	cout << endl;
	cout << "Relokaciona tabela za Data sekciju:" << endl;
	cout << *relData;
	cout << endl;
	cout << endl;
	cout << "Relokaciona tabela za Rodata sekciju:" << endl;
	cout << *relRodata;
	cout << endl;
	cout << endl;

	cout << ".text code:" << endl;
	cout << codeText;
	cout << endl;
	cout << endl;
	cout << ".data code:" << endl;
	cout << codeData;
	cout << endl;
	cout << endl;
	cout << ".rodata code:" << endl;
	cout << codeRodata;
	cout << endl;
	cout << endl;

	
	return 0;
}

