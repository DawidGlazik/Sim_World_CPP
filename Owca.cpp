#include "Owca.h"
#include "Pole.h"

Owca::Owca() {
	this->sila = 4;
	this->inicjatywa = 4;
	this->wiek = 0;
}

Owca::Owca(Swiat* swiat, Polozenie xy) {
	this->sila = 4;
	this->inicjatywa = 4;
	this->wiek = 0;
	this->swiat = swiat;
	this->xy = xy;
}

Owca::Owca(Swiat* swiat, Polozenie xy, int sila, int wiek) {
	this->sila = sila;
	this->inicjatywa = 4;
	this->wiek = wiek;
	this->swiat = swiat;
	this->xy = xy;
}

void Owca::narodziny(int x1, int y1) {
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
		this->swiat->dodajOrganizm(new Owca(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Owca::rysowanie() {
	cout << 'O';
}

string Owca::getNazwa() {
	return "Owca";
}

Owca::~Owca() {

}