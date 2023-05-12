#include "Trawa.h"
#include "Pole.h"

Trawa::Trawa() {
	this->sila = 0;
	this->wiek = 0;
}

Trawa::Trawa(Swiat* swiat, Polozenie xy) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 0;
	this->wiek = 0;
}

Trawa::Trawa(Swiat* swiat, Polozenie xy, int wiek) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 0;
	this->wiek = wiek;
}

void Trawa::sprawdzIZasiej(int x1, int y1) {
	string komentarz;
	if (dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x + x1][this->xy.y + y1])) {
		komentarz = "";
		komentarz += "Zasiano ";
		komentarz += this->getNazwa();
		komentarz += "(";
		komentarz += to_string(this->xy.x + x1 + 1);
		komentarz += ",";
		komentarz += to_string(this->xy.y + +y1 + 1);
		komentarz += ")";
		this->swiat->dziennik(komentarz);
		this->swiat->dodajOrganizm(new Trawa(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Trawa::rysowanie() {
	cout << 't';
}

string Trawa::getNazwa() {
	return "Trawa";
}

Trawa::~Trawa() {

}