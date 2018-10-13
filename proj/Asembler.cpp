#include "Asembler.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <bitset>
#include <regex>
#include <stdlib.h>



Asembler::Asembler(TabelaSimbola * tsimb, TabelaSekcija * tsekc, int pocetnaAdr) {
	tsim = tsimb;
	tsek = tsekc;
	pocetnaAdresa = pocetnaAdr;

	Instrukcija* ins = new Instrukcija("aladd", "110000");
	sveInstrukcije["aladd"] = ins;

	ins = new Instrukcija("alsub", "110001");
	sveInstrukcije["alsub"] = ins;

	ins = new Instrukcija("almul", "110010");
	sveInstrukcije["almul"] = ins;

	ins = new Instrukcija("aldiv", "110011");
	sveInstrukcije["aldiv"] = ins;

	ins = new Instrukcija("alcmp", "110100");
	sveInstrukcije["alcmp"] = ins;

	ins = new Instrukcija("aland", "110101");
	sveInstrukcije["aland"] = ins;

	ins = new Instrukcija("alor", "110110");
	sveInstrukcije["alor"] = ins;

	ins = new Instrukcija("alnot", "110111");
	sveInstrukcije["alnot"] = ins;

	ins = new Instrukcija("altest", "111000");
	sveInstrukcije["altest"] = ins;

	ins = new Instrukcija("alpush", "111001");
	sveInstrukcije["alpush"] = ins;

	ins = new Instrukcija("alpop", "111010");
	sveInstrukcije["alpop"] = ins;

	ins = new Instrukcija("alcall", "111011");
	sveInstrukcije["alcall"] = ins;

	ins = new Instrukcija("aliret", "111100");
	sveInstrukcije["aliret"] = ins;

	ins = new Instrukcija("almov", "111101");
	sveInstrukcije["almov"] = ins;

	ins = new Instrukcija("alshl", "111110");
	sveInstrukcije["alshl"] = ins;

	ins = new Instrukcija("alshr", "111111");
	sveInstrukcije["alshr"] = ins;


	//GT


	ins = new Instrukcija("gtadd", "100000");
	sveInstrukcije["gtadd"] = ins;

	ins = new Instrukcija("gtsub", "100001");
	sveInstrukcije["gtsub"] = ins;

	ins = new Instrukcija("gtmul", "100010");
	sveInstrukcije["gtmul"] = ins;

	ins = new Instrukcija("gtdiv", "100011");
	sveInstrukcije["gtdiv"] = ins;

	ins = new Instrukcija("gtcmp", "100100");
	sveInstrukcije["gtcmp"] = ins;

	ins = new Instrukcija("gtand", "100101");
	sveInstrukcije["gtand"] = ins;

	ins = new Instrukcija("gtor", "100110");
	sveInstrukcije["gtor"] = ins;

	ins = new Instrukcija("gtnot", "100111");
	sveInstrukcije["gtnot"] = ins;

	ins = new Instrukcija("gttest", "101000");
	sveInstrukcije["gttest"] = ins;

	ins = new Instrukcija("gtpush", "101001");
	sveInstrukcije["gtpush"] = ins;

	ins = new Instrukcija("gtpop", "101010");
	sveInstrukcije["gtpop"] = ins;

	ins = new Instrukcija("gtcall", "101011");
	sveInstrukcije["gtcall"] = ins;

	ins = new Instrukcija("gtiret", "101100");
	sveInstrukcije["gtiret"] = ins;

	ins = new Instrukcija("gtmov", "101101");
	sveInstrukcije["gtmov"] = ins;

	ins = new Instrukcija("gtshl", "101110");
	sveInstrukcije["gtshl"] = ins;

	ins = new Instrukcija("gtshr", "101111");
	sveInstrukcije["gtshr"] = ins;


	//NE

	ins = new Instrukcija("neadd", "010000");
	sveInstrukcije["neadd"] = ins;

	ins = new Instrukcija("nesub", "010001");
	sveInstrukcije["nesub"] = ins;

	ins = new Instrukcija("nemul", "010010");
	sveInstrukcije["nemul"] = ins;

	ins = new Instrukcija("nediv", "010011");
	sveInstrukcije["nediv"] = ins;

	ins = new Instrukcija("necmp", "010100");
	sveInstrukcije["necmp"] = ins;

	ins = new Instrukcija("neand", "010101");
	sveInstrukcije["neand"] = ins;

	ins = new Instrukcija("neor", "010110");
	sveInstrukcije["neor"] = ins;

	ins = new Instrukcija("nenot", "010111");
	sveInstrukcije["nenot"] = ins;

	ins = new Instrukcija("netest", "011000");
	sveInstrukcije["netest"] = ins;

	ins = new Instrukcija("nepush", "011001");
	sveInstrukcije["nepush"] = ins;

	ins = new Instrukcija("nepop", "011010");
	sveInstrukcije["nepop"] = ins;

	ins = new Instrukcija("necall", "011011");
	sveInstrukcije["necall"] = ins;

	ins = new Instrukcija("neiret", "011100");
	sveInstrukcije["neiret"] = ins;

	ins = new Instrukcija("nemov", "011101");
	sveInstrukcije["nemov"] = ins;

	ins = new Instrukcija("neshl", "011110");
	sveInstrukcije["neshl"] = ins;

	ins = new Instrukcija("neshr", "011111");
	sveInstrukcije["neshr"] = ins;


	//EQ

	ins = new Instrukcija("eqadd", "000000");
	sveInstrukcije["eqadd"] = ins;

	ins = new Instrukcija("eqsub", "000001");
	sveInstrukcije["eqsub"] = ins;

	ins = new Instrukcija("eqmul", "000010");
	sveInstrukcije["eqmul"] = ins;

	ins = new Instrukcija("eqdiv", "000011");
	sveInstrukcije["eqdiv"] = ins;

	ins = new Instrukcija("eqcmp", "000100");
	sveInstrukcije["eqcmp"] = ins;

	ins = new Instrukcija("eqand", "000101");
	sveInstrukcije["eqand"] = ins;

	ins = new Instrukcija("eqor", "000110");
	sveInstrukcije["eqor"] = ins;

	ins = new Instrukcija("eqnot", "000111");
	sveInstrukcije["eqnot"] = ins;

	ins = new Instrukcija("eqtest", "001000");
	sveInstrukcije["eqtest"] = ins;

	ins = new Instrukcija("eqpush", "001001");
	sveInstrukcije["eqpush"] = ins;

	ins = new Instrukcija("eqpop", "001010");
	sveInstrukcije["eqpop"] = ins;

	ins = new Instrukcija("eqcall", "001011");
	sveInstrukcije["eqcall"] = ins;

	ins = new Instrukcija("eqiret", "001100");
	sveInstrukcije["eqiret"] = ins;

	ins = new Instrukcija("eqmov", "001101");
	sveInstrukcije["eqmov"] = ins;

	ins = new Instrukcija("eqshl", "001110");
	sveInstrukcije["eqshl"] = ins;

	ins = new Instrukcija("eqshr", "001111");
	sveInstrukcije["eqshr"] = ins;

	//PSEUDO INS

	ins = new Instrukcija("alret", "111010");
	sveInstrukcije["alret"] = ins;

	ins = new Instrukcija("aljmp", "111101");
	sveInstrukcije["aljmp"] = ins;

	ins = new Instrukcija("gtret", "101010");
	sveInstrukcije["gtret"] = ins;

	ins = new Instrukcija("gtjmp", "101101");
	sveInstrukcije["gtjmp"] = ins;

	ins = new Instrukcija("neret", "011010");
	sveInstrukcije["neret"] = ins;

	ins = new Instrukcija("nejmp", "011101");
	sveInstrukcije["nejmp"] = ins;

	ins = new Instrukcija("eqret", "001010");
	sveInstrukcije["eqret"] = ins;

	ins = new Instrukcija("eqjmp", "001101");
	sveInstrukcije["eqjmp"] = ins;

}

bool Asembler::prviProlaz(ifstream& ulaz) {
	int locationCounter = 0;
	string tekucaSekcija = "";
	int redniBroj = 0;
	int brojacAdresa = pocetnaAdresa;
	Simbol* und = new Simbol("und", "und", -1, 'l', redniBroj++);
	if (!tsim->dodajUTabeluSimbola("und", und)) {
		redniBroj--; //vracanje rednog broja ako simbol vec postoji
	}

	int pos;
	Instrukcija* instrukcija;

	string val = "";
	bool text = false, bss = false, rodata = false, data = false;

	istringstream iss;
	string linija;
	getline(ulaz, linija);
	iss.str(linija);

	bool pocetak = true;
	while (linija.find(".end") == -1) {

		if (!(iss >> val)) { //prazan red
			getline(ulaz, linija);
			iss.clear();
			val = "";
			iss.str(linija);
			continue;
		}
		if ((pos = linija.find_last_of(":")) != -1) {
			string priv = "";
			for (int i = 0; i < pos; i++) {
				if (linija[i] != ':') {
					if (linija[i] != ' ') {
						priv += linija[i];
					}
				}
				else {
					if (priv == "") {
						cout << "GRESKA!Dva znaka ':' zaredom!" << endl;
						return false;
					}
					else {
						Simbol* sim = new Simbol(priv, tekucaSekcija, locationCounter, 'l', redniBroj++);
						if (!tsim->dodajUTabeluSimbola(priv, sim)) {
							redniBroj--; //vracanje rednog broja ako simbol vec postoji
							if (tsim->uzmiIzTabeleSimbola(priv)->getSekcija() == "und") {
								tsim->uzmiIzTabeleSimbola(priv)->setSekcija(tekucaSekcija);
								tsim->uzmiIzTabeleSimbola(priv)->setVrednost(locationCounter);
							}
							else {
								cout << "GRESKA:Dvaput definisana labela!" << endl;
								return false;
							}
						}
						priv = "";
					}
				}
			}
			if (priv == "") {
				cout << "GRESKA!Dva znaka ':' zaredom!" << endl;
				return 0;
			}
			else {
				Simbol* sim = new Simbol(priv, tekucaSekcija, locationCounter, 'l', redniBroj++);
				if (!tsim->dodajUTabeluSimbola(priv, sim)) {
					redniBroj--; //vracanje rednog broja ako simbol vec postoji
					if (tsim->uzmiIzTabeleSimbola(priv)->getSekcija() == "und") {
						tsim->uzmiIzTabeleSimbola(priv)->setSekcija(tekucaSekcija);
						tsim->uzmiIzTabeleSimbola(priv)->setVrednost(locationCounter);
					}
					else {
						cout << "GRESKA:Dvaput definisana labela!" << endl;
						return false;
					}
				}
				priv = "";
			}

			string linijaPrivremena = "";
			for (int i = pos + 1; i < linija.size(); i++) {
				linijaPrivremena += linija[i];
			}
			linija = linijaPrivremena;
			val = "";
			iss.clear();
			iss.str(linija);
			iss >> val;
			if (val == "") {
				getline(ulaz, linija);
				iss.clear();
				val = "";
				iss.str(linija);
				continue;
			}
		}
		if (val != ".text" && val != ".data" && val != ".bss" && val != ".rodata" && pocetak == true) {
			cout << val;
			cout << "GRESKA!Zapis van sekcije na pocetku!" << endl;
			return false;
		}
		pocetak = false;

		if (val == ".text") {
			if (text == true) {
				cout << "GRESKA:Text sekcija definisana vise puta!";
				return false;
			}
			text = true;
			if (iss >> val) {
				cout << "GRESKA:Dodatan tekst iza oznake sekcije text!";
				return false;
			}
			Simbol* sim = new Simbol(val, val, 0, 'l', redniBroj++);
			tsim->dodajUTabeluSimbola(val, sim);
			if (tekucaSekcija != "") {
				Sekcija* sek = new Sekcija(tekucaSekcija, brojacAdresa - locationCounter, locationCounter);
				tsek->dodajSekciju(tekucaSekcija, sek);
			}
			locationCounter = 0;
			tekucaSekcija = val;
		}
		else if (val == ".data") {
			if (data == true) {
				cout << "GRESKA:Data sekcija definisana vise puta!";
				return false;
			}
			data = true;
			if (iss >> val) {
				cout << "GRESKA:Dodatan tekst iza oznake sekcije data!";
				return false;
			}

			Simbol* sim = new Simbol(val, val, 0, 'l', redniBroj++);
			tsim->dodajUTabeluSimbola(val, sim);
			if (tekucaSekcija != "") {
				Sekcija* sek = new Sekcija(tekucaSekcija, brojacAdresa - locationCounter, locationCounter);
				tsek->dodajSekciju(tekucaSekcija, sek);
			}
			locationCounter = 0;
			tekucaSekcija = val;
		}
		else if (val == ".bss") {
			if (bss == true) {
				cout << "GRESKA:Bss sekcija definisana vise puta!";
				return false;
			}
			bss = true;
			if (iss >> val) {
				cout << "GRESKA:Dodatan tekst iza oznake sekcije bss!";
				return false;
			}

			Simbol* sim = new Simbol(val, val, 0, 'l', redniBroj++);
			tsim->dodajUTabeluSimbola(val, sim);
			if (tekucaSekcija != "") {
				Sekcija* sek = new Sekcija(tekucaSekcija, brojacAdresa - locationCounter, locationCounter);
				tsek->dodajSekciju(tekucaSekcija, sek);
			}
			locationCounter = 0;
			tekucaSekcija = val;
		}
		else if (val == ".rodata") {
			if (rodata == true) {
				cout << "GRESKA:Rodata sekcija definisana vise puta!";
				return false;
			}
			rodata = true;
			if (iss >> val) {
				cout << "GRESKA:Dodatan tekst iza oznake sekcije rodata!";
				return false;
			}

			Simbol* sim = new Simbol(val, val, 0, 'l', redniBroj++);
			tsim->dodajUTabeluSimbola(val, sim);
			if (tekucaSekcija != "") {
				Sekcija* sek = new Sekcija(tekucaSekcija, brojacAdresa - locationCounter, locationCounter);
				tsek->dodajSekciju(tekucaSekcija, sek);
			}
			locationCounter = 0;
			tekucaSekcija = val;
		}
		else if (val == ".global") {
			string bezRazmaka = "";
			while (iss >> val) {
				bezRazmaka += val;
			}
			istringstream stream(bezRazmaka);
			string labela = "";
			while (getline(stream, labela, ',')) {
				Simbol* sim = new Simbol(labela, "und", -1, 'g', redniBroj++);
				if (!tsim->dodajUTabeluSimbola(labela, sim)) {
					redniBroj--; //vracanje rednog broja ako simbol vec postoji
					tsim->uzmiIzTabeleSimbola(labela)->setVidljivost('g');
				}
			}
		}
		else if (val == ".skip") {
			iss >> val;
			bool jeBroj = true;
			for (int i = 0; i < val.size(); i++) {
				if (!isdigit(val[i])) {
					jeBroj = false;
				}
			}
			if (jeBroj) {
				int broj = stoi(val);
				locationCounter += broj;
				brojacAdresa += broj;
			}
			else if(regex_match(val, regex("0x[0-9A-Fa-f]+"))){
				long broj = strtol(val.c_str(), NULL, 16);
				locationCounter += broj;
				brojacAdresa += broj;
			}
			else {
				cout << "GRESKA:Posle .skip mora ici broj";
				return false;
			}
		}
		else if (val == ".char" || val == ".word" || val == ".long") {
			string bezRazmaka = "";
			string pom;
			while (iss >> pom) {
				bezRazmaka += pom;
			}
			istringstream stream(bezRazmaka);
			string la = "";
			int brojanje = 0;
			while (getline(stream, la, ',')) {
				brojanje++;
			}
			if (val == ".char") {
				if (brojanje == 0) {
					brojanje = 1;
				}
				locationCounter += (1 * brojanje);
				brojacAdresa += (1 * brojanje);
			}
			else if (val == ".word") {
				if (brojanje == 0) {
					brojanje = 1;
				}
				locationCounter += (2 * brojanje);
				brojacAdresa += (2 * brojanje);
			}
			else if (val == ".long") {
				if (brojanje == 0) {
					brojanje = 1;
				}
				locationCounter += (4 * brojanje);
				brojacAdresa += (4 * brojanje);
			}
		}

		else if (val == ".align") {
			iss >> val;
			bool jeBroj = true;
			for (int i = 0; i < val.size(); i++) {
				if (!isdigit(val[i])) {
					jeBroj = false;
				}
			}
			if (jeBroj) {
				int broj = stoi(val);
				if (!(broj&(broj - 1)) == 0) {
					cout << "GRESKA:Poravnanje mora biti stepen 2";
					return false;
				}
				if (!(locationCounter % broj == 0)) {
					int priv = broj - (locationCounter % broj);
					locationCounter += priv;
					brojacAdresa += priv;
				}
			}
			else if (regex_match(val, regex("0x[0-9A-Fa-f]+"))) {
				long broj = strtol(val.c_str(), NULL, 16);
				if (!(broj&(broj - 1)) == 0) {
					cout << "GRESKA:Poravnanje mora biti stepen 2";
					return false;
				}
				if (!(locationCounter % broj == 0)) {
					int priv = broj - (locationCounter % broj);
					locationCounter += priv;
					brojacAdresa += priv;
				}
			}
			else {
				cout << "GRESKA:Posle .align mora ici broj";
				return false;
			}
		}
		else if ((instrukcija = sveInstrukcije[val]) != 0) {
			if (tekucaSekcija != ".text") {
				cout << "Greska!Instrukcija van text sekcije!" << endl;
				return false;
			}
			string instr = val;
			string bezRazmaka = "";
			while (iss >> val) {
				bezRazmaka += val;
			}

			if (instr == "alpush" || instr == "eqpush" || instr == "nepush" || instr == "gtpush" || instr == "alpop" || instr == "eqpop" || instr == "nepop" || instr == "gtpop") {
				istringstream stream(bezRazmaka);
				string operand = "";
				int i = 0;
				while (getline(stream, operand, ',')) {
					i++;
					if (i > 1) {
						cout << "GRESKA:Prevelik broj operanada, push, pop!" << endl;
						return false;
					}
				}
				if (i == 0) {
					cout << "GRESKA:Nedostaje operand, push, pop!" << endl;
					return false;
				}
				if (operand[0] == 'r' && isdigit(operand[1]) && operand[2] == '\0') {
					int brojReg = operand[1] - '0';
					if (brojReg < 0 || brojReg >7) {
						cout << "GRESKA:Nedozvoljen broj registra, push, pop" << endl;
						return false;
					}
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					locationCounter += 4;
					brojacAdresa += 4;
				}
			}
			else if (instr == "alcall" || instr == "eqcall" || instr == "necall" || instr == "gtcall") {
				istringstream stream(bezRazmaka);
				string operand = "";
				int i = 0;
				while (getline(stream, operand, ',')) {
					i++;
					if (i > 1) {
						cout << "GRESKA:Prevelik broj operanada, call!" << endl;
						return false;
					}
				}
				if (i == 0) {
					cout << "GRESKA:Nedostaje operand, call!" << endl;
					return false;
				}
				if (isDigitCEO(operand)) {
					cout << "GRESKA:Nedozvoljeno neposredno adresiranje, call" << endl;
					return false;
				}
				if (operand[0] == 'r' && isdigit(operand[1]) && operand[2] == '\0') {
					int brojReg = operand[1] - '0';
					if (brojReg < 0 || brojReg >7) {
						cout << "GRESKA:Nedozvoljen broj registra, call" << endl;
						return false;
					}
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					locationCounter += 4;
					brojacAdresa += 4;
				}
			}
			else if (instr == "aliret" || instr == "eqiret" || instr == "neiret" || instr == "gtiret" || instr == "alret" || instr == "eqret" || instr == "neret" || instr == "gtret") {
				if (bezRazmaka != "") {
					cout << "GRESKA:Prevelik broj operanada, iret,ret!" << endl;
					return false;
				}
				locationCounter += 2;
				brojacAdresa += 2;
			}
			else if (instr == "almov" || instr == "nemov" || instr == "eqmov" || instr == "gtmov") {
				istringstream stream(bezRazmaka);
				string operand = "";
				int i = 0;
				bool boolReg[2];
				boolReg[0] = false;
				boolReg[1] = false;
				while (getline(stream, operand, ',')) {
					i++;
					if (i > 2) {
						cout << "GRESKA:Prevelik broj operanada, mov!" << endl;
						return false;
					}
					if (operand[0] == 'r' && isdigit(operand[1]) && operand[2] == '\0') {
						int brojReg = operand[1] - '0';
						if (brojReg < 0 || brojReg >7) {
							cout << "GRESKA:Nedozvoljen broj registra, mov" << endl;
							return false;
						}
						boolReg[i - 1] = true;
					}
					else if (operand == "pc" && i == 1) {
						boolReg[i - 1] = true;
					}
					else if (operand == "pc" && i == 2) {
						cout << "GRESKA:PC kao drugi argument, mov!" << endl;
						return false;
					}
					else {
						boolReg[i - 1] = false;
					}
				}
				if (i == 0 || i == 1) {
					cout << "GRESKA:Nedostaje operand, mov!" << endl;
					return false;
				}
				if (boolReg[0] == false && boolReg[1] == false) {
					cout << "GRESKA:Oba operanda zahtevaju dodatne bajtove!" << endl;
					return false;
				}
				if (boolReg[0] && boolReg[1]) {
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					locationCounter += 4;
					brojacAdresa += 4;
				}
			}
			else if (instr == "aljmp" || instr == "nejmp" || instr == "eqjmp" || instr == "gtjmp") {
				istringstream stream(bezRazmaka);
				string operand = "";
				int i = 0;
				while (getline(stream, operand, ',')) {
					i++;
					if (i > 1) {
						cout << "GRESKA:Prevelik broj operanada jmp!" << endl;
						return false;
					}
				}
				if (i == 0) {
					cout << "GRESKA:Nedostaje operand jmp!" << endl;
					return false;
				}
				if (operand[0] == 'r' && isdigit(operand[1]) && operand[2] == '\0') {
					int brojReg = operand[1] - '0';
					if (brojReg < 0 || brojReg >7) {
						cout << "GRESKA:Nedozvoljen broj registra jmp" << endl;
						return false;
					}
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					locationCounter += 4;
					brojacAdresa += 4;
				}
			}
			else {
				istringstream stream(bezRazmaka);
				string operand = "";
				int i = 0;
				bool boolReg[2];
				boolReg[0] = false;
				boolReg[1] = false;
				while (getline(stream, operand, ',')) {
					i++;
					if (i > 2) {
						cout << "GRESKA:Prevelik broj operanada!" << endl;
						return false;
					}
					if (operand[0] == 'r' && isdigit(operand[1]) && operand[2] == '\0') {
						int brojReg = operand[1] - '0';
						if (brojReg < 0 || brojReg >7) {
							cout << "GRESKA:Nedozvoljen broj registra!" << endl;
							return false;
						}
						boolReg[i - 1] = true;
					}
				}
				if (i == 0 || i == 1) {
					cout << "GRESKA:Nedostaje operand!" << endl;
					return false;
				}
				if (boolReg[0] == false && boolReg[1] == false) {
					cout << "GRESKA:Oba operanda zahtevaju dodatne bajtove!" << endl;
					return false;
				}
				if (boolReg[0] && boolReg[1]) {
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					locationCounter += 4;
					brojacAdresa += 4;
				}
			}

		}
		else {
			cout << "GRESKA:Nepoznata instrukcija/direktiva! " << val << endl;
			return false;
		}

		getline(ulaz, linija);
		iss.clear();
		val = "";
		iss.str(linija);
	}
	Sekcija* sek = new Sekcija(tekucaSekcija, brojacAdresa - locationCounter, locationCounter);
	tsek->dodajSekciju(tekucaSekcija, sek);
	return true;
}

bool Asembler::drugiProlaz(ifstream& ulaz, RelokacioniZapis* relText, RelokacioniZapis* relData, RelokacioniZapis*relRodata, string& codeText, string& codeData, string& codeRodata) {
	string izlazIme = "izlaz.txt";
	ofstream izlaz;
	izlaz.open(izlazIme);

	izlaz << *tsim;
	izlaz << endl;
	izlaz << endl;
	izlaz << *tsek;

	string bitText = "";
	string bitData = "";
	string bitRodata = "";

	int locationCounter = 0;
	string tekucaSekcija = "";
	int brojacAdresa = pocetnaAdresa;

	Instrukcija* instrukcija;

	string val = "";

	istringstream iss;
	string linija;
	getline(ulaz, linija);
	iss.str(linija);

	int pos;

	while (linija.find(".end") == -1) {
		if (!(iss >> val)) { //prazan red
			getline(ulaz, linija);
			iss.clear();
			val = "";
			iss.str(linija);
			continue;
		}
		if ((pos = linija.find_last_of(":")) != -1) {
			string linijaPrivremena = "";
			for (int i = pos + 1; i < linija.size(); i++) {
				linijaPrivremena += linija[i];
			}
			linija = linijaPrivremena;
			val = "";
			iss.clear();
			iss.str(linija);
			iss >> val;
			if (val == "") {
				getline(ulaz, linija);
				iss.clear();
				val = "";
				iss.str(linija);
				continue;
			}
		}
		if (val == ".text" || val == ".data" || val == ".bss" || val == ".rodata") {
			locationCounter = 0;
			tekucaSekcija = val;
		}
		else if (val == ".global") {
			continue;
		}
		else if (val == ".skip") {
			iss >> val;
			long broj = 0;
			if (regex_match(val, regex("0x[0-9A-Fa-f]+"))) {
				broj = strtol(val.c_str(), NULL, 16);
			}
			else {
				broj = stoi(val);
			}
			locationCounter += broj;
			brojacAdresa += broj;
			if (tekucaSekcija == ".text") {
				for (int i = 0; i < broj; i++) {
					bitText += "00000000";
				}
			}
			else if (tekucaSekcija == ".data") {
				for (int i = 0; i < broj; i++) {
					bitData += "00000000";
				}
			}
			else if (tekucaSekcija == ".rodata") {
				for (int i = 0; i < broj; i++) {
					bitRodata += "00000000";
				}
			}
		}
		else if (val == ".char" || val == ".word" || val == ".long") {
			string bezRazmaka = "";
			string pom;
			while (iss >> pom) {
				bezRazmaka += pom;
			}
			istringstream stream(bezRazmaka);
			string la = "";
			int brojanje = 0;
			while (getline(stream, la, ',')) {
				brojanje++;
				Simbol* s;
				if ((s = tsim->uzmiIzTabeleSimbola(la)) != 0) {
					if (s->getSekcija() == "und" && s->getVidljivost() == 'l') {
						cout << "***GRESKA:Nedefinisana labela:" + s->getIme() + "***" << endl;
						return false;
					}
					if (val == ".char") {
						/*
						dodajKod(tekucaSekcija, 8, s, bitText, bitData, bitRodata);
						int offset = locationCounter;
						dodajRelZapis(offset, s, relText, relData, relRodata, true, tekucaSekcija);
						*/
						cout << "GRESKA:Labela posle .char direktive" << endl;
						return false;
					}
					else if (val == ".word") {
						dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
						int offset = locationCounter;
						dodajRelZapis(offset, s, relText, relData, relRodata, true, tekucaSekcija);
					}
					else if (val == ".long") {
						dodajKod(tekucaSekcija, 32, s, bitText, bitData, bitRodata);
						int offset = locationCounter;
						dodajRelZapis(offset, s, relText, relData, relRodata, true, tekucaSekcija);
					}
				}
				else if (isDigitCEO(la)) {
					if (val == ".char") {
						dodajKodBezLab(tekucaSekcija, 8, la, bitText, bitData, bitRodata);
					}
					else if (val == ".word") {
						dodajKodBezLab(tekucaSekcija, 16, la, bitText, bitData, bitRodata);
					}
					else if (val == ".long") {
						dodajKodBezLab(tekucaSekcija, 32, la, bitText, bitData, bitRodata);
					}
				}
				else if (regex_match(la, regex("\'.\'"))) {
					char zaUpis = la[1];
					int p = (int)zaUpis;
					string pr = to_string(p);
					//cout << "***********"<< zaUpis<<"*"<<p<<"*"<<pr <<"************"<< endl;
					if (val == ".char") {
						dodajKodBezLab(tekucaSekcija, 8, pr, bitText, bitData, bitRodata);
					}
					else if (val == ".word") {
						dodajKodBezLab(tekucaSekcija, 16, pr, bitText, bitData, bitRodata);
					}
					else if (val == ".long") {
						dodajKodBezLab(tekucaSekcija, 32, pr, bitText, bitData, bitRodata);
					}
				}
				else if (regex_match(la, regex("0x[0-9A-Fa-f]+"))) {
					long br = strtol(la.c_str(), NULL, 16);
					string brojHex = to_string(br);
					if (val == ".char") {
						dodajKodBezLab(tekucaSekcija, 8, brojHex, bitText, bitData, bitRodata);
					}
					else if (val == ".word") {
						dodajKodBezLab(tekucaSekcija, 16, brojHex, bitText, bitData, bitRodata);
					}
					else if (val == ".long") {
						dodajKodBezLab(tekucaSekcija, 32, brojHex, bitText, bitData, bitRodata);
					}
				}
				else {
					cout << "***GRESKA:Nepoznata labela!***" << endl;
					return false;
				}
			}
			if (val == ".char") {
				if (brojanje == 0) {
					brojanje = 1;
				}
				locationCounter += (1 * brojanje);
				brojacAdresa += (1 * brojanje);
			}
			else if (val == ".word") {
				if (brojanje == 0) {
					brojanje = 1;
				}
				locationCounter += (2 * brojanje);
				brojacAdresa += (2 * brojanje);
			}
			else if (val == ".long") {
				if (brojanje == 0) {
					brojanje = 1;
				}
				locationCounter += (4 * brojanje);
				brojacAdresa += (4 * brojanje);
			}
		}
		else if (val == ".align") {
			iss >> val;
			long broj = 0;
			if (regex_match(val, regex("0x[0-9A-Fa-f]+"))) {
				broj = strtol(val.c_str(), NULL, 16);
			}
			else {
				broj = stoi(val);
			}
			if (!(locationCounter % broj == 0)) {
				int priv = broj - (locationCounter % broj);
				string resenje = "";
				for (int i = 0; i < priv; i++) {
					resenje += "00000000";
				}
				if (tekucaSekcija == ".text") {
					bitText += resenje;
				}
				else if (tekucaSekcija == ".data") {
					bitData += resenje;
				}
				else if (tekucaSekcija == ".rodata") {
					bitRodata += resenje;
				}
				locationCounter += priv;
				brojacAdresa += priv;
			}
		}
		else if ((instrukcija = sveInstrukcije[val]) != 0) {
			string instr = val;
			string bezRazmaka = "";
			while (iss >> val) {
				bezRazmaka += val;
			}

			if (instr == "alpush" || instr == "eqpush" || instr == "nepush" || instr == "gtpush") {
				istringstream stream(bezRazmaka);
				string operand = "";
				getline(stream, operand, ',');
				if (regex_match(operand, regex("-{0,1}\\d+"))) { //neposredna vrednost
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000000000";
					dodajKodBezLab(tekucaSekcija, 16, operand, bitText, bitData, bitRodata);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("0x[0-9A-Fa-f]+"))) {
					long br = strtol(operand.c_str(), NULL, 16);
					string brojHex = to_string(br);
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000000000";
					dodajKodBezLab(tekucaSekcija, 16, brojHex, bitText, bitData, bitRodata);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("\\*\\d+"))) { //*20 lokacija sa adrese 20
					operand = operand.substr(1, operand.size() - 1); //skidanje *
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000010000";
					dodajKodBezLab(tekucaSekcija, 16, operand, bitText, bitData, bitRodata);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("&.+"))) { //&x vrednost simbola x
					operand = operand.substr(1, operand.size() - 1); //skidanje &
					Simbol* s;
					if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
						cout << "GRESKA:Nedefinisan simbol, push" << endl;
						return false;
					}
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000000000";
					dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
					dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, true, tekucaSekcija);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("\\$.+"))) { //$x pc rel prom x
					operand = operand.substr(1, operand.size() - 1); //skidanje $
					Simbol* s;
					if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
						cout << "GRESKA:Nedefinisan simbol, push" << endl;
						return false;
					}
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000011111";
					//dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
					dodajKodPcRel(s, bitText);
					dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, false, tekucaSekcija);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("r[0-7]\\[.+\\]"))) { //reg ind pom
					operand = operand.substr(1, operand.size() - 1); //skidanje r
					int brojReg = operand[0] - '0';
					string nizBit = bitset<3>(brojReg).to_string();
					operand = operand.substr(2, operand.size() - 2); //skidanje broja i [
					string pomocni = operand;
					operand = "";
					for (int i = 0; pomocni[i] != ']'; i++) {
						operand += pomocni[i];
					}
					if (isDigitCEO(operand)) {
						bitText += sveInstrukcije[instr]->opcode;
						bitText += "0000011";
						bitText += nizBit;
						dodajKodBezLab(tekucaSekcija, 16, operand, bitText, bitData, bitRodata);
					}
					else {
						Simbol* s;
						if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
							cout << "GRESKA:Nedefinisan simbol, push" << endl;
							return false;
						}
						bitText += sveInstrukcije[instr]->opcode;
						bitText += "0000011";
						bitText += nizBit;
						dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
						dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, true, tekucaSekcija);
					}
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("r[0-7]"))) { //reg dir
					operand = operand.substr(1, operand.size() - 1); //skidanje r
					int brojReg = operand[0] - '0';
					string nizBit = bitset<3>(brojReg).to_string();
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000001";
					bitText += nizBit;
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					Simbol* s;
					if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
						cout << "GRESKA:Nedefinisan simbol, push" << endl;
						return false;
					}
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000010000";
					dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
					dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, true, tekucaSekcija);
					locationCounter += 4;
					brojacAdresa += 4;
				}

			}
			else if (instr == "alpop" || instr == "eqpop" || instr == "nepop" || instr == "gtpop") {
				istringstream stream(bezRazmaka);
				string operand = "";
				getline(stream, operand, ',');
				if (regex_match(operand, regex("-{0,1}\\d+"))) { //neposredna vrednost
					cout << "GRESKA!Neposredno adresiranje kod pop ins!" << endl;
					return false;
				}
				else if (regex_match(operand, regex("0x[0-9A-Fa-f]+"))) {
					cout << "GRESKA!Neposredno adresiranje kod pop ins!" << endl;
					return false;
				}
				else if (regex_match(operand, regex("\\*\\d+"))) { //*20 lokacija sa adrese 20
					operand = operand.substr(1, operand.size() - 1); //skidanje *
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "1000000000";
					dodajKodBezLab(tekucaSekcija, 16, operand, bitText, bitData, bitRodata);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("&.+"))) { //&x vrednost simbola x
					cout << "GRESKA!Neposredno adresiranje kod pop ins!" << endl;
					return false;
				}
				else if (regex_match(operand, regex("\\$.+"))) { //$x pc rel prom x
					operand = operand.substr(1, operand.size() - 1); //skidanje $
					Simbol* s;
					if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
						cout << "GRESKA:Nedefinisan simbol, pop" << endl;
						return false;
					}
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "1111100000";
					//dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
					dodajKodPcRel(s, bitText);
					dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, false, tekucaSekcija);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("r[0-7]\\[.+\\]"))) { //reg ind pom
					operand = operand.substr(1, operand.size() - 1); //skidanje r
					int brojReg = operand[0] - '0';
					string nizBit = bitset<3>(brojReg).to_string();
					operand = operand.substr(2, operand.size() - 2); //skidanje broja i [
					string pomocni = operand;
					operand = "";
					for (int i = 0; pomocni[i] != ']'; i++) {
						operand += pomocni[i];
					}
					if (isDigitCEO(operand)) {
						bitText += sveInstrukcije[instr]->opcode;
						bitText += "11";
						bitText += nizBit;
						bitText += "00000";
						dodajKodBezLab(tekucaSekcija, 16, operand, bitText, bitData, bitRodata);
					}
					else {
						Simbol* s;
						if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
							cout << "GRESKA:Nedefinisan simbol,pop" << endl;
							return false;
						}
						bitText += sveInstrukcije[instr]->opcode;
						bitText += "11";
						bitText += nizBit;
						bitText += "00000";
						dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
						dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, true, tekucaSekcija);
					}
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("r[0-7]"))) { //reg dir
					operand = operand.substr(1, operand.size() - 1); //skidanje r
					int brojReg = operand[0] - '0';
					string nizBit = bitset<3>(brojReg).to_string();
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "01";
					bitText += nizBit;
					bitText += "00000";
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					Simbol* s;
					if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
						cout << "GRESKA:Nedefinisan simbol, pop" << endl;
						return false;
					}
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "1000000000";
					dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
					dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, true, tekucaSekcija);
					locationCounter += 4;
					brojacAdresa += 4;
				}
			}
			else if (instr == "alcall" || instr == "eqcall" || instr == "necall" || instr == "gtcall") {
				istringstream stream(bezRazmaka);
				string operand = "";
				getline(stream, operand, ',');
				if (regex_match(operand, regex("-{0,1}\\d+"))) { //neposredna vrednost
					cout << "GRESKA!Neposredno adresiranje kod call ins!" << endl;
					return false;
				}
				else if (regex_match(operand, regex("0x[0-9A-Fa-f]+"))) {
					cout << "GRESKA!Neposredno adresiranje kod call ins!" << endl;
					return false;
				}
				else if (regex_match(operand, regex("\\*\\d+"))) { //*20 lokacija sa adrese 20
					operand = operand.substr(1, operand.size() - 1); //skidanje *
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000010000";
					dodajKodBezLab(tekucaSekcija, 16, operand, bitText, bitData, bitRodata);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("&.+"))) { //&x vrednost simbola x
					cout << "GRESKA!Neposredno adresiranje kod call ins!" << endl;
					return false;
				}
				else if (regex_match(operand, regex("\\$.+"))) { //$x pc rel prom x
					operand = operand.substr(1, operand.size() - 1); //skidanje $
					Simbol* s;
					if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
						cout << "GRESKA:Nedefinisan simbol, call" << endl;
						return false;
					}
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000011111";
					//dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
					dodajKodPcRel(s, bitText);
					dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, false, tekucaSekcija);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("r[0-7]\\[.+\\]"))) { //reg ind pom
					operand = operand.substr(1, operand.size() - 1); //skidanje r
					int brojReg = operand[0] - '0';
					string nizBit = bitset<3>(brojReg).to_string();
					operand = operand.substr(2, operand.size() - 2); //skidanje broja i [
					string pomocni = operand;
					operand = "";
					for (int i = 0; pomocni[i] != ']'; i++) {
						operand += pomocni[i];
					}
					if (isDigitCEO(operand)) {
						bitText += sveInstrukcije[instr]->opcode;
						bitText += "0000011";
						bitText += nizBit;
						dodajKodBezLab(tekucaSekcija, 16, operand, bitText, bitData, bitRodata);
					}
					else {
						Simbol* s;
						if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
							cout << "GRESKA:Nedefinisan simbol, call" << endl;
							return false;
						}
						bitText += sveInstrukcije[instr]->opcode;
						bitText += "0000011";
						bitText += nizBit;
						dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
						dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, true, tekucaSekcija);
					}
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("r[0-7]"))) { //reg dir
					operand = operand.substr(1, operand.size() - 1); //skidanje r
					int brojReg = operand[0] - '0';
					string nizBit = bitset<3>(brojReg).to_string();
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000001";
					bitText += nizBit;
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					Simbol* s;
					if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
						cout << "GRESKA:Nedefinisan simbol, call" << endl;
						return false;
					}
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "0000010000";
					dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
					dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, true, tekucaSekcija);
					locationCounter += 4;
					brojacAdresa += 4;
				}
			}
			else if (instr == "aliret" || instr == "eqiret" || instr == "neiret" || instr == "gtiret") {
				bitText += sveInstrukcije[instr]->opcode;
				bitText += "0000000000";
				locationCounter += 2;
				brojacAdresa += 2;
			}
			else if (instr == "alret" || instr == "eqret" || instr == "neret" || instr == "gtret") {
				bitText += sveInstrukcije[instr]->opcode;
				bitText += "0111100000";
				locationCounter += 2;
				brojacAdresa += 2;
			}
			else if (instr == "almov" || instr == "nemov" || instr == "eqmov" || instr == "gtmov") {
				istringstream stream(bezRazmaka);
				string operand = "";
				int i = 0;
				bitText += sveInstrukcije[instr]->opcode;
				string operandZaPosle = "";
				bool prviProlaz = true;
				bool pcrel = false;
				while (getline(stream, operand, ',')) {
					if (regex_match(operand, regex("-{0,1}\\d+"))) { //neposredna vrednost
						if (prviProlaz) {
							cout << "GRESKA!Neposredno adresiranje dst polja!" << endl;
							return false;
						}
						operandZaPosle = operand;
						bitText += "00000";
					}
					else if (regex_match(operand, regex("0x[0-9A-Fa-f]+"))) {
						long br = strtol(operand.c_str(), NULL, 16);
						string brojHex = to_string(br);
						if (prviProlaz) {
							cout << "GRESKA!Neposredno adresiranje dst polja!" << endl;
							return false;
						}
						operandZaPosle = brojHex;
						bitText += "00000";
					}
					else if (regex_match(operand, regex("\\*\\d+"))) { //*20 lokacija sa adrese 20
						operand = operand.substr(1, operand.size() - 1); //skidanje *
						operandZaPosle = operand;
						bitText += "10000";
					}
					else if (regex_match(operand, regex("&.+"))) { //&x vrednost simbola x
						if (prviProlaz) {
							cout << "GRESKA!Neposredno adresiranje dst polja!" << endl;
							return false;
						}
						operand = operand.substr(1, operand.size() - 1); //skidanje &
						operandZaPosle = operand;
						Simbol* s;
						if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
							cout << "GRESKA:Nedefinisan simbol" << endl;
							return false;
						}
						bitText += "00000";
					}
					else if (regex_match(operand, regex("\\$.+"))) { //$x pc rel prom x
						pcrel = true;
						operand = operand.substr(1, operand.size() - 1); //skidanje $
						operandZaPosle = operand;
						Simbol* s;
						if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
							cout << "GRESKA:Nedefinisan simbol" << endl;
							return false;
						}
						bitText += "11111";
					}
					else if (regex_match(operand, regex("r[0-7]\\[.+\\]"))) { //reg ind pom
						operand = operand.substr(1, operand.size() - 1); //skidanje r
						int brojReg = operand[0] - '0';
						string nizBit = bitset<3>(brojReg).to_string();
						operand = operand.substr(2, operand.size() - 2); //skidanje broja i [
						string pomocni = operand;
						operand = "";
						for (int i = 0; pomocni[i] != ']'; i++) {
							operand += pomocni[i];
						}
						operandZaPosle = operand;
						if (isDigitCEO(operand)) {
							bitText += "11";
							bitText += nizBit;
						}
						else {
							Simbol* s;
							if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
								cout << "GRESKA:Nedefinisan simbol" << endl;
								return false;
							}
							bitText += "11";
							bitText += nizBit;
						}
					}
					else if (regex_match(operand, regex("r[0-7]"))) { //reg dir
						operand = operand.substr(1, operand.size() - 1); //skidanje r
						int brojReg = operand[0] - '0';
						string nizBit = bitset<3>(brojReg).to_string();
						bitText += "01";
						bitText += nizBit;
					}
					else if (operand == "pc") {
						bitText += "01111";
					}
					else {
						Simbol* s;
						if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
							cout << "GRESKA:Nedefinisan simbol" << endl;
							return false;
						}
						operandZaPosle = operand;
						bitText += "10000";
					}
					prviProlaz = false;
				}
				if (operandZaPosle == "") {
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					if (isDigitCEO(operandZaPosle)) {
						dodajKodBezLab(tekucaSekcija, 16, operandZaPosle, bitText, bitData, bitRodata);
					}
					else {
						Simbol* sim;
						if ((sim = tsim->uzmiIzTabeleSimbola(operandZaPosle)) == 0) {
							cout << "GRESKA:Nedefinisan simbol" << endl;
							return false;
						}
						if (pcrel) {
							dodajKodPcRel(sim, bitText);
							dodajRelZapis(locationCounter + 2, sim, relText, relData, relRodata, false, tekucaSekcija);
						}
						else {
							dodajKod(tekucaSekcija, 16, sim, bitText, bitData, bitRodata);
							dodajRelZapis(locationCounter + 2, sim, relText, relData, relRodata, true, tekucaSekcija);
						}
					}
					locationCounter += 4;
					brojacAdresa += 4;
				}
			}
			else if (instr == "aljmp" || instr == "nejmp" || instr == "eqjmp" || instr == "gtjmp") {
				istringstream stream(bezRazmaka);
				string operand = "";
				getline(stream, operand, ',');
				if (regex_match(operand, regex("-{0,1}\\d+"))) { //neposredna vrednost
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "01111";
					bitText += "00000";
					dodajKodBezLab(tekucaSekcija, 16, operand, bitText, bitData, bitRodata);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("0x[0-9A-Fa-f]+"))) {
					long br = strtol(operand.c_str(), NULL, 16);
					string brojHex = to_string(br);
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "01111";
					bitText += "00000";
					dodajKodBezLab(tekucaSekcija, 16, brojHex, bitText, bitData, bitRodata);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("\\*\\d+"))) { //*20 lokacija sa adrese 20
					operand = operand.substr(1, operand.size() - 1); //skidanje *
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "01111";
					bitText += "10000";
					dodajKodBezLab(tekucaSekcija, 16, operand, bitText, bitData, bitRodata);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("&.+"))) { //&x vrednost simbola x
					operand = operand.substr(1, operand.size() - 1); //skidanje &
					Simbol* s;
					if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
						cout << "GRESKA:Nedefinisan simbol, jmp" << endl;
						return false;
					}
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "01111";
					bitText += "00000";
					dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
					dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, true, tekucaSekcija);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("\\$.+"))) { //$x pc rel prom x
					operand = operand.substr(1, operand.size() - 1); //skidanje $
					Simbol* s;
					if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
						cout << "GRESKA:Nedefinisan simbol, jmp" << endl;
						return false;
					}
					if (instr == "aljmp") {
						bitText += sveInstrukcije["aladd"]->opcode;
					}
					else if (instr == "eqjmp") {
						bitText += sveInstrukcije["eqadd"]->opcode;
					}
					else if (instr == "nejmp") {
						bitText += sveInstrukcije["neadd"]->opcode;
					}
					else {
						bitText += sveInstrukcije["gtadd"]->opcode;
					}
					bitText += "0111100000";
					dodajKodPcRel(s, bitText);
					dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, false, tekucaSekcija);
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("r[0-7]\\[.+\\]"))) { //reg ind pom
					operand = operand.substr(1, operand.size() - 1); //skidanje r
					int brojReg = operand[0] - '0';
					string nizBit = bitset<3>(brojReg).to_string();
					operand = operand.substr(2, operand.size() - 2); //skidanje broja i [
					string pomocni = operand;
					operand = "";
					for (int i = 0; pomocni[i] != ']'; i++) {
						operand += pomocni[i];
					}
					if (isDigitCEO(operand)) {
						bitText += sveInstrukcije[instr]->opcode;
						bitText += "01111";
						bitText += "11";
						bitText += nizBit;
						dodajKodBezLab(tekucaSekcija, 16, operand, bitText, bitData, bitRodata);
					}
					else {
						Simbol* s;
						if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
							cout << "GRESKA:Nedefinisan simbol, jmp" << endl;
							return false;
						}
						bitText += sveInstrukcije[instr]->opcode;
						bitText += "01111";
						bitText += "11";
						bitText += nizBit;
						dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
						dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, true, tekucaSekcija);
					}
					locationCounter += 4;
					brojacAdresa += 4;
				}
				else if (regex_match(operand, regex("r[0-7]"))) { //reg dir
					operand = operand.substr(1, operand.size() - 1); //skidanje r
					int brojReg = operand[0] - '0';
					string nizBit = bitset<3>(brojReg).to_string();
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "01111";
					bitText += "01";
					bitText += nizBit;
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					Simbol* s;
					if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
						cout << "GRESKA:Nedefinisan simbol, jmp" << endl;
						return false;
					}
					bitText += sveInstrukcije[instr]->opcode;
					bitText += "01111";
					bitText += "10000";
					dodajKod(tekucaSekcija, 16, s, bitText, bitData, bitRodata);
					dodajRelZapis(locationCounter + 2, s, relText, relData, relRodata, true, tekucaSekcija);
					locationCounter += 4;
					brojacAdresa += 4;
				}
			}
			else {
				istringstream stream(bezRazmaka);
				string operand = "";
				int i = 0;
				bitText += sveInstrukcije[instr]->opcode;
				string operandZaPosle = "";
				bool prviProlaz = true;
				bool pcrel = false;
				while (getline(stream, operand, ',')) {
					if (regex_match(operand, regex("-{0,1}\\d+"))) { //neposredna vrednost
						if (prviProlaz) {
							cout << "GRESKA!Neposredno adresiranje dst polja!" << endl;
							return false;
						}
						operandZaPosle = operand;
						bitText += "00000";
					}
					else if (regex_match(operand, regex("0x[0-9A-Fa-f]+"))) {
						long br = strtol(operand.c_str(), NULL, 16);
						string brojHex = to_string(br);
						if (prviProlaz) {
							cout << "GRESKA!Neposredno adresiranje dst polja!" << endl;
							return false;
						}
						operandZaPosle = brojHex;
						bitText += "00000";
					}
					else if (regex_match(operand, regex("\\*\\d+"))) { //*20 lokacija sa adrese 20
						operand = operand.substr(1, operand.size() - 1); //skidanje *
						operandZaPosle = operand;
						bitText += "10000";
					}
					else if (regex_match(operand, regex("&.+"))) { //&x vrednost simbola x
						if (prviProlaz) {
							cout << "GRESKA!Neposredno adresiranje dst polja!" << endl;
							return false;
						}
						operand = operand.substr(1, operand.size() - 1); //skidanje &
						operandZaPosle = operand;
						Simbol* s;
						if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
							cout << "GRESKA:Nedefinisan simbol" << endl;
							return false;
						}
						bitText += "00000";
					}
					else if (regex_match(operand, regex("\\$.+"))) { //$x pc rel prom x
						pcrel = true;
						operand = operand.substr(1, operand.size() - 1); //skidanje $
						operandZaPosle = operand;
						Simbol* s;
						if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
							cout << "GRESKA:Nedefinisan simbol" << endl;
							return false;
						}
						bitText += "11111";
					}
					else if (regex_match(operand, regex("r[0-7]\\[.+\\]"))) { //reg ind pom
						operand = operand.substr(1, operand.size() - 1); //skidanje r
						int brojReg = operand[0] - '0';
						string nizBit = bitset<3>(brojReg).to_string();
						operand = operand.substr(2, operand.size() - 2); //skidanje broja i [
						string pomocni = operand;
						operand = "";
						for (int i = 0; pomocni[i] != ']'; i++) {
							operand += pomocni[i];
						}
						operandZaPosle = operand;
						if (isDigitCEO(operand)) {
							bitText += "11";
							bitText += nizBit;
						}
						else {
							Simbol* s;
							if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
								cout << "GRESKA:Nedefinisan simbol" << endl;
								return false;
							}
							bitText += "11";
							bitText += nizBit;
						}
					}
					else if (regex_match(operand, regex("r[0-7]"))) { //reg dir
						operand = operand.substr(1, operand.size() - 1); //skidanje r
						int brojReg = operand[0] - '0';
						string nizBit = bitset<3>(brojReg).to_string();
						bitText += "01";
						bitText += nizBit;
					}
					else {
						Simbol* s;
						if (!(s = tsim->uzmiIzTabeleSimbola(operand))) {
							cout << "GRESKA:Nedefinisan simbol" << endl;
							return false;
						}
						operandZaPosle = operand;
						bitText += "10000";
					}
					prviProlaz = false;
				}
				if (operandZaPosle == "") {
					locationCounter += 2;
					brojacAdresa += 2;
				}
				else {
					if (isDigitCEO(operandZaPosle)) {
						dodajKodBezLab(tekucaSekcija, 16, operandZaPosle, bitText, bitData, bitRodata);
					}
					else {
						Simbol* sim;
						if ((sim = tsim->uzmiIzTabeleSimbola(operandZaPosle)) == 0) {
							cout << "GRESKA:Nedefinisan simbol" << endl;
							return false;
						}
						if (pcrel) {
							dodajKodPcRel(sim, bitText);
							dodajRelZapis(locationCounter + 2, sim, relText, relData, relRodata, false, tekucaSekcija);
						}
						else {
							dodajKod(tekucaSekcija, 16, sim, bitText, bitData, bitRodata);
							dodajRelZapis(locationCounter + 2, sim, relText, relData, relRodata, true, tekucaSekcija);
						}
					}
					locationCounter += 4;
					brojacAdresa += 4;
				}
			}

		}

		getline(ulaz, linija);
		iss.clear();
		val = "";
		iss.str(linija);
	}

	/*cout << endl;
	cout << "t: " + bitText << endl;
	cout << endl;
	cout << "d: " + bitData << endl;
	cout << endl;
	cout << "r: " + bitRodata << endl;
	cout << endl;*/

	codeText = binaryToHex(bitText);
	codeData = binaryToHex(bitData);
	codeRodata = binaryToHex(bitRodata);

	izlaz << endl;
	izlaz << "Relokaciona tabela za Text sekciju:" << endl;
	izlaz << *relText;
	izlaz << endl;
	izlaz << endl;
	izlaz << "Relokaciona tabela za Data sekciju:" << endl;
	izlaz << *relData;
	izlaz << endl;
	izlaz << endl;
	izlaz << "Relokaciona tabela za Rodata sekciju:" << endl;
	izlaz << *relRodata;
	izlaz << endl;
	izlaz << endl;

	izlaz << ".text code:" << endl;
	izlaz << codeText;
	izlaz << endl;
	izlaz << endl;
	izlaz << ".data code:" << endl;
	izlaz << codeData;
	izlaz << endl;
	izlaz << endl;
	izlaz << ".rodata code:" << endl;
	izlaz << codeRodata;
	izlaz << endl;
	izlaz << endl;

	izlaz.close();
	return true;
}

bool Asembler::isDigitCEO(string a) {
	bool rez = true;
	int i = 0;
	if (a[0] == '-') {
		i = 1;
	}
	for (; i < a.size(); i++) {
		if (!isdigit(a[i])) {
			rez = false;
		}
	}
	return rez;
}


void Asembler::dodajKod(string sekcija, int bitova, Simbol * s, string& bitText, string& bitData, string& bitRodata) {
	if (s->getVidljivost() == 'g') {
		if (sekcija == ".text") {
			for (int i = 0; i < bitova; i++) {
				bitText += "0";
			}
		}
		else if (sekcija == ".data") {
			for (int i = 0; i < bitova; i++) {
				bitData += "0";
			}
		}
		else if (sekcija == ".rodata") {
			for (int i = 0; i < bitova; i++) {
				bitRodata += "0";
			}
		}
	}
	else {//lokalan
		int vrednost = s->getVrednost();
		if (sekcija == ".text") {
			if (bitova == 8) {
				string nizBit = bitset<8>(vrednost).to_string();
				bitText += nizBit;
			}
			else if (bitova == 16) {
				string nizBit = bitset<16>(vrednost).to_string();
				string prvi, drugi;
				for (int i = 0; i < 8; i++) {
					drugi += nizBit[i];
					prvi += nizBit[i + 8];
				}
				string rez = prvi + drugi;
				bitText += rez;
			}
			else if (bitova == 32) {
				string nizBit = bitset<32>(vrednost).to_string();
				string prvi, drugi, treci, cetvrti;
				for (int i = 0; i < 8; i++) {
					cetvrti += nizBit[i];
					treci += nizBit[i + 8];
					drugi += nizBit[i + 16];
					prvi += nizBit[i + 24];
				}
				string rez = prvi + drugi + treci + cetvrti;
				bitText += rez;
			}
		}
		else if (sekcija == ".data") {
			if (bitova == 8) {
				string nizBit = bitset<8>(vrednost).to_string();
				bitData += nizBit;
			}
			else if (bitova == 16) {
				string nizBit = bitset<16>(vrednost).to_string();
				string prvi, drugi;
				for (int i = 0; i < 8; i++) {
					drugi += nizBit[i];
					prvi += nizBit[i + 8];
				}
				string rez = prvi + drugi;
				bitData += rez;
			}
			else if (bitova == 32) {
				string nizBit = bitset<32>(vrednost).to_string();
				string prvi, drugi, treci, cetvrti;
				for (int i = 0; i < 8; i++) {
					cetvrti += nizBit[i];
					treci += nizBit[i + 8];
					drugi += nizBit[i + 16];
					prvi += nizBit[i + 24];
				}
				string rez = prvi + drugi + treci + cetvrti;
				bitData += rez;
			}
		}
		else if (sekcija == ".rodata") {
			if (bitova == 8) {
				string nizBit = bitset<8>(vrednost).to_string();
				bitRodata += nizBit;
			}
			else if (bitova == 16) {
				string nizBit = bitset<16>(vrednost).to_string();
				string prvi, drugi;
				for (int i = 0; i < 8; i++) {
					drugi += nizBit[i];
					prvi += nizBit[i + 8];
				}
				string rez = prvi + drugi;
				bitRodata += rez;
			}
			else if (bitova == 32) {
				string nizBit = bitset<32>(vrednost).to_string();
				string prvi, drugi, treci, cetvrti;
				for (int i = 0; i < 8; i++) {
					cetvrti += nizBit[i];
					treci += nizBit[i + 8];
					drugi += nizBit[i + 16];
					prvi += nizBit[i + 24];
				}
				string rez = prvi + drugi + treci + cetvrti;
				bitRodata += rez;
			}
		}
	}
}

void Asembler::dodajKodBezLab(string sekcija, int bitova, string broj, string& bitText, string& bitData, string& bitRodata) {
	long vrednost = stoi(broj);
	if (sekcija == ".text") {
		if (bitova == 8) {
			string nizBit = bitset<8>(vrednost).to_string();
			bitText += nizBit;
		}
		else if (bitova == 16) {
			string nizBit = bitset<16>(vrednost).to_string();
			string prvi, drugi;
			for (int i = 0; i < 8; i++) {
				drugi += nizBit[i];
				prvi += nizBit[i + 8];
			}
			string rez = prvi + drugi;
			bitText += rez;
		}
		else if (bitova == 32) {
			string nizBit = bitset<32>(vrednost).to_string();
			string prvi, drugi, treci, cetvrti;
			for (int i = 0; i < 8; i++) {
				cetvrti += nizBit[i];
				treci += nizBit[i + 8];
				drugi += nizBit[i + 16];
				prvi += nizBit[i + 24];
			}
			string rez = prvi + drugi + treci + cetvrti;
			bitText += rez;
		}
	}
	else if (sekcija == ".data") {
		if (bitova == 8) {
			string nizBit = bitset<8>(vrednost).to_string();
			bitData += nizBit;
		}
		else if (bitova == 16) {
			string nizBit = bitset<16>(vrednost).to_string();
			string prvi, drugi;
			for (int i = 0; i < 8; i++) {
				drugi += nizBit[i];
				prvi += nizBit[i + 8];
			}
			string rez = prvi + drugi;
			bitData += rez;
		}
		else if (bitova == 32) {
			string nizBit = bitset<32>(vrednost).to_string();
			string prvi, drugi, treci, cetvrti;
			for (int i = 0; i < 8; i++) {
				cetvrti += nizBit[i];
				treci += nizBit[i + 8];
				drugi += nizBit[i + 16];
				prvi += nizBit[i + 24];
			}
			string rez = prvi + drugi + treci + cetvrti;
			bitData += rez;
		}
	}
	else if (sekcija == ".rodata") {
		if (bitova == 8) {
			string nizBit = bitset<8>(vrednost).to_string();
			bitRodata += nizBit;
		}
		else if (bitova == 16) {
			string nizBit = bitset<16>(vrednost).to_string();
			string prvi, drugi;
			for (int i = 0; i < 8; i++) {
				drugi += nizBit[i];
				prvi += nizBit[i + 8];
			}
			string rez = prvi + drugi;
			bitRodata += rez;
		}
		else if (bitova == 32) {
			string nizBit = bitset<32>(vrednost).to_string();
			string prvi, drugi, treci, cetvrti;
			for (int i = 0; i < 8; i++) {
				cetvrti += nizBit[i];
				treci += nizBit[i + 8];
				drugi += nizBit[i + 16];
				prvi += nizBit[i + 24];
			}
			string rez = prvi + drugi + treci + cetvrti;
			bitRodata += rez;
		}
	}
}
void Asembler::dodajRelZapis(int offset, Simbol*s, RelokacioniZapis* relText, RelokacioniZapis* relData, RelokacioniZapis*relRodata, bool apsolutno, string tekucaSekcija) {
	string hexOff = intToHex(offset);
	string tip = "Apsolutno";
	if (apsolutno == false) {
		tip = "Relativno";
	}
	int vrednost;
	if (s->getVidljivost() == 'l') {
		vrednost = tsim->uzmiIzTabeleSimbola(s->getSekcija())->getRedniBroj();
		Zapis* z = new Zapis(hexOff, tip, vrednost);
		if (tekucaSekcija == ".text") {
			relText->dodajZapis(z);
		}
		else if (tekucaSekcija == ".data") {
			relData->dodajZapis(z);
		}
		else if (tekucaSekcija == ".rodata") {
			relRodata->dodajZapis(z);
		}
	}
	else {
		vrednost = s->getRedniBroj();
		Zapis* z = new Zapis(hexOff, tip, vrednost);
		if (tekucaSekcija == ".text") {
			relText->dodajZapis(z);
		}
		else if (tekucaSekcija == ".data") {
			relData->dodajZapis(z);
		}
		else if (tekucaSekcija == ".rodata") {
			relRodata->dodajZapis(z);
		}
	}
}

string Asembler::intToHex(int i) {
	stringstream str;
	str << hex << i;
	return str.str();
}

string Asembler::binaryToHex(string binNiz) {
	string rest(""), tmp, chr = "0000";
	int len = binNiz.length() / 4;
	chr = chr.substr(0, len);
	//sBinary = chr + sBinary;
	for (unsigned int i = 0; i < binNiz.length(); i += 4)
	{
		tmp = binNiz.substr(i, 4);
		if (!tmp.compare("0000"))
		{
			rest = rest + "0";
		}
		else if (!tmp.compare("0001"))
		{
			rest = rest + "1";
		}
		else if (!tmp.compare("0010"))
		{
			rest = rest + "2";
		}
		else if (!tmp.compare("0011"))
		{
			rest = rest + "3";
		}
		else if (!tmp.compare("0100"))
		{
			rest = rest + "4";
		}
		else if (!tmp.compare("0101"))
		{
			rest = rest + "5";
		}
		else if (!tmp.compare("0110"))
		{
			rest = rest + "6";
		}
		else if (!tmp.compare("0111"))
		{
			rest = rest + "7";
		}
		else if (!tmp.compare("1000"))
		{
			rest = rest + "8";
		}
		else if (!tmp.compare("1001"))
		{
			rest = rest + "9";
		}
		else if (!tmp.compare("1010"))
		{
			rest = rest + "A";
		}
		else if (!tmp.compare("1011"))
		{
			rest = rest + "B";
		}
		else if (!tmp.compare("1100"))
		{
			rest = rest + "C";
		}
		else if (!tmp.compare("1101"))
		{
			rest = rest + "D";
		}
		else if (!tmp.compare("1110"))
		{
			rest = rest + "E";
		}
		else if (!tmp.compare("1111"))
		{
			rest = rest + "F";
		}
		else
		{
			continue;
		}
	}
	return rest;
}

void Asembler::dodajKodPcRel(Simbol* s, string& bitText) {
	if (s->getVidljivost() == 'g') {
		bitText += "1111111011111111";
	}
	else {//lokalan
		int vrednost = s->getVrednost();
		vrednost -= 2;
		if (vrednost == -1) {
			bitText += "1111111111111111";
		}
		else if (vrednost == -2) {
			bitText += "1111111011111111";
		}
		else {
			string nizBit = bitset<16>(vrednost).to_string(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			string prvi, drugi;
			for (int i = 0; i < 8; i++) {
				drugi += nizBit[i];
				prvi += nizBit[i + 8];
			}
			string rez = prvi + drugi;
			bitText += rez;
		}
	}
}