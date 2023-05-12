#include "WilczeJagody.h"
#include "Pole.h"

WilczeJagody::WilczeJagody() {
	this->sila = 99;
	this->wiek = 0;
}

WilczeJagody::WilczeJagody(Swiat* swiat, Polozenie xy) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 99;
	this->wiek = 0;
}

WilczeJagody::WilczeJagody(Swiat* swiat, Polozenie xy, int wiek) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 99;
	this->wiek = wiek;
}

void WilczeJagody::rysowanie() {
	cout << 'w';
}

void WilczeJagody::sprawdzIZasiej(int x1, int y1) {
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
		this->swiat->dodajOrganizm(new WilczeJagody(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void WilczeJagody::kolizja(Organizm* org) {
	string komentarz = "";
	komentarz += org->getNazwa();
	komentarz += org->getXY();
	komentarz += " zjada ";
	komentarz += this->getNazwa();
	komentarz += this->getXY();
	komentarz += " i umiera";
	swiat->dziennik(komentarz);
	swiat->plansza[this->xy.x][this->xy.y] = new Pole();
	swiat->plansza[org->getPolozenie().x][org->getPolozenie().y] = new Pole();
	for (int i = 0; i < this->swiat->organizmy.size(); i++) {
		if (this->swiat->organizmy[i]->getPolozenie().x == this->xy.x && this->swiat->organizmy[i]->getPolozenie().y == this->xy.y) {
			this->swiat->organizmy.erase(this->swiat->organizmy.begin() + i);
		}
		if (this->swiat->organizmy[i]->getPolozenie().x == org->getPolozenie().x && this->swiat->organizmy[i]->getPolozenie().y == org->getPolozenie().y) {
			this->swiat->organizmy.erase(this->swiat->organizmy.begin() + i);
		}
	}
}

string WilczeJagody::getNazwa() {
	return "Wilcze_jagody";
}

WilczeJagody::~WilczeJagody() {

}