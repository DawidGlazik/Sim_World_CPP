#include "Wilk.h"
#include "Pole.h"

Wilk::Wilk() {
	this->sila = 9;
	this->inicjatywa = 5;
	this->wiek = 0;
}

Wilk::Wilk(Swiat* swiat, Polozenie xy) {
	this->sila = 9;
	this->inicjatywa = 5;
	this->wiek = 0;
	this->swiat = swiat;
	this->xy = xy;
}

Wilk::Wilk(Swiat* swiat, Polozenie xy, int sila, int wiek) {
	this->sila = sila;
	this->inicjatywa = 5;
	this->wiek = wiek;
	this->swiat = swiat;
	this->xy = xy;
}

void Wilk::narodziny(int x1, int y1) {
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
		this->swiat->dodajOrganizm(new Wilk(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Wilk::rysowanie() {
	cout << 'W';
}

string Wilk::getNazwa() {
	return "Wilk";
}

Wilk::~Wilk() {

}