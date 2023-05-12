#include "Guarana.h"
#include "Pole.h"

Guarana::Guarana() {
	this->sila = 0;
	this->wiek = 0;
}

Guarana::Guarana(Swiat* swiat, Polozenie xy) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 0;
	this->wiek = 0;
}

Guarana::Guarana(Swiat* swiat, Polozenie xy, int wiek) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 0;
	this->wiek = wiek;
}

void Guarana::rysowanie() {
	cout << 'g';
}

void Guarana::sprawdzIZasiej(int x1, int y1) {
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
		this->swiat->dodajOrganizm(new Guarana(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Guarana::kolizja(Organizm* org) {
	string komentarz = "";
	komentarz += org->getNazwa();
	komentarz += org->getXY();
	komentarz += " - sila rosnie o 3 po zjedzeniu ";
	komentarz += this->getNazwa();
	komentarz += this->getXY();
	org->addSila(3);
	swiat->dziennik(komentarz);
	for (int i = 0; i < this->swiat->organizmy.size(); i++) {
		if (this->swiat->organizmy[i]->getPolozenie().x == this->xy.x && this->swiat->organizmy[i]->getPolozenie().y == this->xy.y) {
			this->swiat->organizmy.erase(this->swiat->organizmy.begin() + i);
		}
	}
	swiat->plansza[this->xy.x][this->xy.y] = org;
	swiat->plansza[org->getPolozenie().x][org->getPolozenie().y] = new Pole();
	org->setX(this->xy.x);
	org->setY(this->xy.y);
}

string Guarana::getNazwa() {
	return "Guarana";
}

Guarana::~Guarana() {

}