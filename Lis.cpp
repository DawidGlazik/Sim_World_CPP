#include "Lis.h"
#include "Pole.h"

Lis::Lis() {
	this->sila = 3;
	this->inicjatywa = 7;
	this->wiek = 0;
}

Lis::Lis(Swiat* swiat, Polozenie xy) {
	this->sila = 3;
	this->inicjatywa = 7;
	this->wiek = 0;
	this->swiat = swiat;
	this->xy = xy;
}

Lis::Lis(Swiat* swiat, Polozenie xy, int sila, int wiek) {
	this->sila = sila;
	this->inicjatywa = 7;
	this->wiek = wiek;
	this->swiat = swiat;
	this->xy = xy;
}

void Lis::ruch(int x1, int y1){
	if (dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x + x1][this->xy.y + y1])) {
		this->swiat->plansza[this->xy.x + x1][this->xy.y + y1] = this->swiat->plansza[this->xy.x][this->xy.y];
		this->swiat->plansza[this->xy.x][this->xy.y] = new Pole();
		this->xy.x += x1;
		this->xy.y += y1;
	}
	else {
		if (this->swiat->plansza[this->xy.x + x1][this->xy.y + y1]->getSila() > this->getSila()) return;
		else this->swiat->plansza[this->xy.x + x1][this->xy.y + y1]->kolizja(this);
	}
}

void Lis::narodziny(int x1, int y1) {
	if (dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x + x1][this->xy.y + y1])) {
		string komentarz = "";
		komentarz += "Narodziny organizmu: ";
		komentarz += this->getNazwa();
		komentarz += "(";
		komentarz += to_string(this->xy.x + x1 + 1);
		komentarz += ",";
		komentarz += to_string(this->xy.y + y1 + 1);
		komentarz += ")";
		this->swiat->dziennik(komentarz);
		this->swiat->dodajOrganizm(new Lis(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Lis::rysowanie() {
	cout << 'L';
}

string Lis::getNazwa() {
	return "Lis";
}

Lis::~Lis() {

}